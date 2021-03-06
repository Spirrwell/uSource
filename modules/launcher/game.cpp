/*
game.cpp -- executable to run Xash Engine
Copyright (C) 2011 Uncle Mike

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/

#include "port.h"
#include "cmdline.h"
#include "debug.h"
#include "common.h"
#include "public/keyvalues.h"
#include "crtlib.h"
#include "appframework.h"
#include "crtlib.h"
#include "platformspec.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#ifdef _WIN32
#include <direct.h>
#define chdir _chdir
#endif

#if defined(__APPLE__) || defined(__unix__)
	#define XASHLIB    "libengine." OS_LIB_EXT
#elif _WIN32
	#if !__MINGW32__ && _MSC_VER >= 1200
		#define USE_WINMAIN
	#endif
	#define XASHLIB "engine.dll"
	#define dlerror() GetStringLastError()
	#include <shellapi.h> // CommandLineToArgvW
#endif

#ifdef WIN32
extern "C"
{
// Enable NVIDIA High Performance Graphics while using Integrated Graphics.
__declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;

// Enable AMD High Performance Graphics while using Integrated Graphics.
__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}
#endif

#define GAME_PATH	"hl1"	// default dir to start from

typedef void (*pfnChangeGame)( const char *progname );
typedef int  (*pfnInit)( int argc, char **argv, const char *progname, int bChangeGame, pfnChangeGame func );
typedef void (*pfnShutdown)( void );

static pfnInit     Xash_Main;
static pfnShutdown Xash_Shutdown = NULL;
static char        szGameDir[128]; // safe place to keep gamedir
static int         szArgc;
static char        **szArgv;
static HINSTANCE	hEngine;

static void Xash_Error( const char *szFmt, ... )
{
	static char	buffer[16384];	// must support > 1k messages
	va_list		args;

	va_start( args, szFmt );
	vsnprintf( buffer, sizeof(buffer), szFmt, args );
	va_end( args );

#if defined( _WIN32 )
	MessageBoxA( NULL, buffer, "Xash Error", MB_OK );
#else
	fprintf( stderr, "Xash Error: %s\n", buffer );
#endif
	exit( 1 );
}

#ifdef _WIN32
static const char *GetStringLastError()
{
	static char buf[1024];

	FormatMessageA( FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, GetLastError(), MAKELANGID( LANG_ENGLISH, SUBLANG_DEFAULT ),
		buf, sizeof( buf ), NULL );

	return buf;
}
#endif

static void Sys_LoadEngine( void )
{
	if(( hEngine = LoadLibrary( XASHLIB )) == NULL )
	{
		Xash_Error("Unable to load the " XASHLIB ": %s", dlerror() );
	}

	if(( Xash_Main = (pfnInit)GetProcAddress( hEngine, "Host_Main" )) == NULL )
	{
		Xash_Error( XASHLIB " missed 'Host_Main' export: %s", dlerror() );
	}

	// this is non-fatal for us but change game will not working
	Xash_Shutdown = (pfnShutdown)GetProcAddress( hEngine, "Host_Shutdown" );
}

static void Sys_UnloadEngine( void )
{
	if( Xash_Shutdown ) Xash_Shutdown( );
	if( hEngine ) FreeLibrary( hEngine );

	Xash_Main = NULL;
	Xash_Shutdown = NULL;
}

/* Loads the interfaces specified in the GameInfo */
static void Sys_LoadInterfaces()
{
	const char* game = GlobalCommandLine().FindString("-game");
	if(!game) game = GAME_PATH;
	static char filePath[256];
	Q_snprintf(filePath, sizeof(filePath), "%s%sgameinfo.txt", game, PATH_SEPARATOR);

	KeyValues kv;
	kv.ParseFile(filePath);
	if(!kv.IsGood())
	{
		printf("Failed to parse GameInfo.txt!");
		exit(1);
	}

	/* Try to find the interfaces subkey */
	KeyValues* pInterfaces = kv.GetChild("interfaces");
	if(!pInterfaces)
	{
		printf("No interfaces key in the gameinfo.txt. Your gameinfo might be malformed.\n");
		return;
	}
	printf("Loading interfaces...\n");
	/* Loop through all keys and add the interfaces */
	for(auto k : pInterfaces->Keys())
	{
		/* Check if this is an absolute/relative path. If so, we will need to extract the filename and path components
		 * before making a platform-specific library name */
		char finalFile[512];
		if(Q_countchar(k.Value(), '/') != 0 || Q_countchar(k.Value(), '\\') != 0)
		{
			char fileName[128];
			Q_FileName(k.Value(), fileName, sizeof(fileName));
			Q_BaseDirectory(k.Value(), filePath, sizeof(filePath));
			/* I know the %s%s%s%s%s format seems kinda funny, but hey. It works. */
			Q_snprintf(finalFile, sizeof(finalFile), "%s%s%s%s.%s", filePath, PATH_SEPARATOR, OS_LIB_PREFIX, fileName, OS_LIB_EXT);
		}
		else
		{
			/* If there is no existing file path, formatting is simple */
			Q_snprintf(finalFile, sizeof(finalFile), "%s%s.%s", OS_LIB_PREFIX, k.Value(), OS_LIB_EXT);
		}
		printf("Loading interface %s from %s\n", k.Name(), finalFile);
		if(!AppFramework::AddInterface(finalFile, k.Name()))
		{
			printf("Failed to add interface %s from %s\nExiting.\n", k.Name(), finalFile);
			exit(1);
		}
	}
	if(!AppFramework::LoadInterfaces())
	{
		printf("Failed to load some interfaces. This is a fatal error.\n");
		exit(1);
	}
	printf("...Finished loading interfaces\n");
}

static void Sys_ChangeGame( const char *progname )
{
	if( !progname || !progname[0] )
		Xash_Error( "Sys_ChangeGame: NULL gamedir" );

	if( Xash_Shutdown == NULL )
		Xash_Error( "Sys_ChangeGame: missed 'Host_Shutdown' export\n" );

	strncpy( szGameDir, progname, sizeof( szGameDir ) - 1 );

	Sys_UnloadEngine ();
	Sys_LoadEngine ();

	Xash_Main( szArgc, szArgv, szGameDir, 1, Sys_ChangeGame );
}

_inline int Sys_Start( void )
{
	int ret;

	/* Initialization for libpublic */
	GlobalCommandLine().Set(szArgc, szArgv);
	dbg::Init();

	/* Launching with the editor? */
	if(GlobalCommandLine().Find("-editor"))
	{
		printf("Starting DarkRadiant..\n");
		const char* dir = GlobalCommandLine().FindString("-basedir");
		if(dir) chdir(dir);
		char fsGame[64];
		const char* game = GlobalCommandLine().FindString("-game");
		Q_snprintf(fsGame, sizeof(fsGame), "fs_game=%s", game ? game : GAME_PATH);
		const char* const args[] = {
			"fs_game=hl1",
			NULL,
		};

		char darkRadiantPath[512];
		const char* dot = "";
		if(Q_strcmp(OS_EXE_EXT, "") != 0) dot = ".";
		Q_snprintf(darkRadiantPath, sizeof(darkRadiantPath), "darkradiant/bin/darkradiant%s%s", dot, OS_EXE_EXT);
		platform::ExecProgram(darkRadiantPath, const_cast<char *const *>(args));
		return 0;
	}

	/* Load interfaces immediately! */
	Sys_LoadInterfaces();
	Sys_LoadEngine();
	ret = Xash_Main( szArgc, szArgv, GAME_PATH, 0, Xash_Shutdown ? Sys_ChangeGame : NULL );
	Sys_UnloadEngine();

	return ret;
}

#ifndef USE_WINMAIN
int main( int argc, char **argv )
{
	szArgc = argc;
	szArgv = argv;

	return Sys_Start();
}
#else
//#pragma comment(lib, "shell32.lib")
int __stdcall WinMain( HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR cmdLine, int nShow )
{
	LPWSTR* lpArgv;
	int ret, i;

	lpArgv = CommandLineToArgvW( GetCommandLineW(), &szArgc );
	szArgv = ( char** )malloc( szArgc * sizeof( char* ));

	for( i = 0; i < szArgc; ++i )
	{
		int size = wcslen(lpArgv[i]) + 1;
		szArgv[i] = ( char* )malloc( size );
		wcstombs( szArgv[i], lpArgv[i], size );
	}

	LocalFree( lpArgv );

	ret = Sys_Start();

	for( ; i < szArgc; ++i )
		free( szArgv[i] );
	free( szArgv );

	return ret;
}
#endif
