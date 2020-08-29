/*
crtlib.h - internal stdlib
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
#pragma once

#include <stdarg.h>
#include "build.h"
#include "containers/string.h"

#ifdef __GNUC__
#define _format(x) __attribute__((format(printf, x, x+1)))
#else
#define _format(x)
#endif

#undef PATH_SEPARATOR

#ifdef _WIN32
#define PATH_SEPARATOR "\\"
#else
#define PATH_SEPARATOR "/"
#endif

// timestamp modes
enum
{
	TIME_FULL = 0,
	TIME_DATE_ONLY,
	TIME_TIME_ONLY,
	TIME_NO_SECONDS,
	TIME_YEAR_ONLY,
	TIME_FILENAME,
};

//
// crtlib.c
//

int Q_strcasecmp(const char* a, const char* b);
#define Q_strupr(in, out) Q_strnupr( in, out, 99999 )
void Q_strnupr(const char *in, char *out, size_t size_out);
#define Q_strlwr(in, out) Q_strnlwr( in, out, 99999 )
void Q_strnlwr(const char *in, char *out, size_t size_out);
int Q_strlen(const char *string);
int Q_colorstr(const char *string);
char Q_toupper(const char in);
char Q_tolower(const char in);
#define Q_strcat(dst, src) Q_strncat( dst, src, 99999 )
size_t Q_strncat(char *dst, const char *src, size_t siz);
#define Q_strcpy(dst, src) Q_strncpy( dst, src, 99999 )
size_t Q_strncpy(char *dst, const char *src, size_t siz);
uint Q_hashkey(const char *string, uint hashSize, qboolean caseinsensitive);
qboolean Q_isdigit(const char *str);
int Q_atoi(const char *str);
float Q_atof(const char *str);
void Q_atov(float *vec, const char *str, size_t siz);
char *Q_strchr(const char *s, char c);
char *Q_strrchr(const char *s, char c);
#define Q_stricmp(s1, s2) Q_strnicmp( s1, s2, 99999 )
int Q_strnicmp(const char *s1, const char *s2, int n);
#define Q_strcmp(s1, s2) Q_strncmp( s1, s2, 99999 )
int Q_strncmp(const char *s1, const char *s2, int n);
qboolean Q_stricmpext(const char *s1, const char *s2);
const char *Q_timestamp(int format);
char *Q_stristr(const char *string, const char *string2);
char *Q_strstr(const char *string, const char *string2);
#define Q_vsprintf(buffer, format, args) Q_vsnprintf( buffer, 99999, format, args )
int Q_vsnprintf(char *buffer, size_t buffersize, const char *format, va_list args);
int Q_snprintf(char *buffer, size_t buffersize, const char *format, ...) _format(3);
int Q_sprintf(char *buffer, const char *format, ...) _format(2);
#define Q_memprint(val) Q_pretifymem( val, 2 )
char *Q_pretifymem(float value, int digitsafterdecimal);
char *va(const char *format, ...) _format(1);
void COM_FileBase(const char *in, char *out);
const char *COM_FileExtension(const char *in);
void COM_DefaultExtension(char *path, const char *extension);
void COM_ReplaceExtension(char *path, const char *extension);
void COM_ExtractFilePath(const char *path, char *dest);
const char *COM_FileWithoutPath(const char *in);
void COM_StripExtension(char *path);
#define COM_CheckString(string) ( ( !string || !*string ) ? 0 : 1 )
int matchpattern(const char *in, const char *pattern, qboolean caseinsensitive);
int matchpattern_with_separator(const char *in, const char *pattern, qboolean caseinsensitive, const char *separators,
                                qboolean wildcard_least_one);

char* Q_strdup(const char* s);
void* Q_malloc(size_t sz);
void Q_free(void* blk);
void* Q_alloca(size_t sz);

/* Format a color string using terminal escape codes */
/* color_table is a table containing 10 entries of char[3] that specifies a color in RGB. if set to nullptr, a default is used */
/* modifier_talbe is a table containing 10 entries of char that specifies a format modifier for that color index, a default is used if set to nullptr */
/* This function is a bit unsafe, so be careful with it */
#define FMT_NONE 0
#define FMT_BOLD 1
#define FMT_UNDERLINE 2
#define FMT_BLINK 3
char* Q_fmtcolorstr(const char* s, char* out, size_t n);
char* Q_fmtcolorstr(const char* s, char* out, size_t n, const unsigned char color_table[10][3]);
char* Q_fmtcolorstr(const char* s, char* out, size_t n, const unsigned char color_table[10][3], const unsigned char modifier_table[10]);

/* Safe string conversions */
bool Q_strint(const char* str, int& out, int base = 10);
bool Q_strfloat(const char* str, float& out);
bool Q_strdouble(const char* str, double& out);
bool Q_strlong(const char* str, long long& out, int base = 10);
bool Q_strbool(const char* str, bool& out);

/* Path operations */
char* Q_FileExtension(const char* s, char* out, size_t len);
char* Q_FileName(const char* s, char* out, size_t len);
char* Q_BaseDirectory(const char* s, char* out, size_t len);
char* Q_StripExtension(const char* s, char* out, size_t len);
char* Q_StripDirectory(const char* s, char* out, size_t len);
char* Q_FixSlashes(const char* s, char* out, size_t len);
char* Q_FixSlashesInPlace(char* s);
String& Q_FixSlashesInPlace(String& s);
char* Q_MakeAbsolute(const char* s, char* out, size_t len);

bool Q_startswith(const char* string, const char* startingString);
bool Q_endswith(const char* str, const char* subst);

/* Other C std functions which might not be portable */
char* Q_getcwd(char* buf, size_t sz);
int Q_getpid();
int Q_mkstemp(char* tmpl);
int Q_unlink(const char* path);
int Q_mkdir(const char* path);
int Q_fileno(FILE* f);