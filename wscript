#! /usr/bin/env python
# encoding: utf-8
# a1batross, mittorn, 2018

from __future__ import print_function
from waflib import Logs
import sys
import os, pathlib
import waftools
from waftools import cmake, msdev, eclipse, codeblocks, export

VERSION = '0.10'
APPNAME = 'uSource'
DESCRIPTION = 'Extended version of Xash3d/Goldsrc'
top = '.'

class Subproject:
	name      = ''
	dedicated = True  # if true will be ignored when building dedicated server
	singlebin = False # if true will be ignored when singlebinary is set
	ignore    = False # if true will be ignored, set by user request

	def __init__(self, name, dedicated=True, singlebin=False):
		self.name = name
		self.dedicated = dedicated
		self.singlebin = singlebin

SUBDIRS = [
	Subproject('modules/public',      dedicated=False),
	Subproject('modules/launcher', singlebin=True),
	Subproject('modules/ref_gl'),
	#Subproject('ref_soft'),
	#Subproject('mainui'),
	# Subproject('vgui_support'),
	Subproject('modules/engine', dedicated=False),
	#Subproject('game/server'),
	#Subproject('game/client', dedicated=False)
]

def subdirs():
	return map(lambda x: x.name, SUBDIRS)

def options(opt):
	grp = opt.add_option_group('Common options')

	grp.add_option('-T', '--build-type', action='store', dest='BUILD_TYPE', default = None,
				   help = 'build type: debug, release or none(custom flags)')

	grp.add_option('-d', '--dedicated', action = 'store_true', dest = 'DEDICATED', default = False,
				   help = 'build Xash Dedicated Server(XashDS)')

	grp.add_option('--single-binary', action = 'store_true', dest = 'SINGLE_BINARY', default = False,
				   help = 'build single "xash" binary instead of xash.dll/libxash.so (forced for dedicated)')

	grp.add_option('-8', '--64bits', action = 'store_true', dest = 'ALLOW64', default = False,
				   help = 'allow targetting 64-bit engine')

	grp.add_option('-W', '--win-style-install', action = 'store_true', dest = 'WIN_INSTALL', default = False,
				   help = 'install like Windows build, ignore prefix, useful for development')

	grp.add_option('--enable-bsp2', action = 'store_true', dest = 'SUPPORT_BSP2_FORMAT', default = False,
				   help = 'build engine and renderers with BSP2 map support(recommended for Quake, breaks compability!)')

	grp.add_option('--sse', action='store_true', dest='USE_SSE', default=False,
				   help='Enables the use of SSE and SSE2 on x86 and x86_64 targets. This is automatically enabled on x64 CPUs')

	grp.add_option('--sse4.1', action='store_true', dest='USE_SSE42', default=False,
				   help='Enables the use of SSE4.2 on x86 and x86_64 targets.')

	grp.add_option('--avx', action='store_true', dest='USE_AVX', default=False,
				   help='Enables the use of AVX on x86_64 targets.')

	grp.add_option('--avx2', action='store_true', dest='USE_AVX2', default=False, help='Enables the use of AVX2')

	grp.add_option('--neon', action='store_true', dest='USE_NEON', default=False,
				   help='Enables the use of NEON vectorization on AArch64 and AArch32 targets.')

	grp.add_option('--no-sse', action='store_true', dest='NO_SSE', default=False, help='Explicitly disables the use of SSE, even on x86_64 targets')

	grp.add_option('--memory-debug', action='store_true', dest='MEMORY_DEBUG', default=False,
				   help='Enables the use of memory debugging. This will define various Mem_XXX functions as macros which will include the locations where the allocations tool place')

	grp.add_option('--enable-scripting', action='store_true', dest='ENABLE_SCRIPTING', help='Enables scripting and builds the scriptsystem DLL')

	grp.add_option('--enable-luajit', action='store_true', dest='ENABLE_LUA', default=False, help='Enables lua scripting')

	grp.add_option('--enable-squirrel', action='store_true', dest='ENABLE_SQUIRREL', help='Enables Squirrel scripting')

	grp.add_option('--enable-new-renderer', action='store_true', dest='ENABLE_RENDERER2', default=False, help='Enables the use of the new renderer')
	grp.add_option('--enable-vulkan', action='store_true', dest='ENABLE_VULKAN', default=False, help='Enables the use of the vulkan backend')

	grp.add_option('--dev', action='store_true', dest='DEV', default=False, help='Force development build macros to be enabled. This is enabled implicitly when building in debug mode')

	grp.add_option('--enable-remote-control', action='store_true', dest='ENABLE_RCSYS', help='Enables the experimental remote control system')

	grp.add_option('--game', type=str, dest='GAME', default='hl', help='The game in which to compile')

	opt.load('subproject')

	for sub in SUBDIRS:
		opt.recurse(sub.name)

	opt.load('xcompile compiler_cxx compiler_c sdl2 clang_compilation_database strip_on_install')
	opt.load('cmake msdev eclipse codeblocks doxygen export cppcheck', tooldir=waftools.location)
	if sys.platform == 'win32':
		opt.load('msvc msdev msvs')
	opt.load('reconfigure')


def filter_cflags(conf, flags, required_flags, cxx):
	supported_flags = []
	check_flags = required_flags + ['-Werror']
	conf.msg('Detecting supported flags for %s' % ('C++' if cxx else 'C'),'...')

	for flag in flags:
		conf.start_msg('Checking for %s' % flag)
		try:
			if cxx:
				conf.check_cxx(cxxflags = [flag] + check_flags)
			else:
				conf.check_cxx(cflags = [flag] + check_flags)
		except conf.errors.ConfigurationError:
			conf.end_msg('no', color='YELLOW')
		else:
			conf.end_msg('yes')
			supported_flags.append(flag)

	return supported_flags

def configure(conf):
	# Dirs
	conf.env.ROOT = str(pathlib.Path('.').resolve())
	conf.env.PMSHARED = str(conf.env.ROOT + "/modules/pm_shared")
	conf.env.ENGINE = str(conf.env.ROOT + "/modules/engine")
	conf.env.SHARED = str(conf.env.ROOT + "games/" + conf.options.GAME + "/game/shared")
	conf.env.SERVER = str(conf.env.ROOT + "games/" + conf.options.GAME + "/game/server")
	conf.env.CLIENT = str(conf.env.ROOT + "games/" + conf.options.GAME + "/game/client")
	conf.env.COMMON = str(conf.env.ROOT + "/modules/common")
	conf.env.PUBLIC = str(conf.env.ROOT + "/modules/public")
	conf.env.FAKEVGUI = str(conf.env.ROOT + "/utils/false_vgui/include")
	conf.env.MATHLIB = str(conf.env.ROOT + "/modules/mathlib")

	conf.env.ENABLE_RCSYS = conf.options.ENABLE_RCSYS

	# Set some opts needed by the server
	conf.env.GAMEDIR = conf.options.GAME
	conf.env.CLIENT_DIR  = 'bin'
	conf.env.SERVER_DIR  = 'bin'

	conf.options.NO_VGUI = True

	# Add some defines that will let us configure project name, desc, ver, etc.
	conf.env.append_unique('DEFINES', 'PROJECT_NAME=\"{0}\"'.format(APPNAME))
	conf.env.append_unique('DEFINES', 'PROJECT_VERSION=\"{0}\"'.format(VERSION))
	conf.env.append_unique('DEFINES', 'PROJECT_DESCRIPTION=\"{0}\"'.format(DESCRIPTION))

	conf.load('fwgslib reconfigure cmake msdev eclipse codeblocks doxygen export cppcheck')
	conf.start_msg('Build type')
	if conf.options.BUILD_TYPE == None:
		conf.end_msg('not set', color='RED')
		conf.fatal('Please set a build type, for example "-T release"')
	elif not conf.options.BUILD_TYPE in ['fast', 'release', 'debug', 'nooptimize', 'sanitize', 'trace', 'none']:
		conf.end_msg(conf.options.BUILD_TYPE, color='RED')
		conf.fatal('Invalid build type. Valid are "debug", "release" or "none"')
	conf.end_msg(conf.options.BUILD_TYPE)

	# -march=native should not be used
	if conf.options.BUILD_TYPE == 'fast':
		Logs.warn('WARNING: \'fast\' build type should not be used in release builds')

	conf.load('subproject')

	# Force XP compability, all build targets should add
	# subsystem=bld.env.MSVC_SUBSYSTEM
	# TODO: wrapper around bld.stlib, bld.shlib and so on?
	conf.env.MSVC_SUBSYSTEM = 'WINDOWS,5.01'
	if not conf.options.ALLOW64:
		conf.env.MSVC_TARGETS = ['x86'] # explicitly request x86 target for MSVC
	else:
		conf.env.MSVC_TARGETS = ['x64']
	if sys.platform == 'win32':
		conf.load('msvc msvcfix msdev msvs')
	conf.load('xcompile compiler_c compiler_cxx gitversion clang_compilation_database strip_on_install')

	# Every static library must have fPIC
	if conf.env.DEST_OS != 'win32' and '-fPIC' in conf.env.CFLAGS_cshlib:
		conf.env.append_unique('CFLAGS_cstlib', '-fPIC')
		conf.env.append_unique('CXXFLAGS_cxxstlib', '-fPIC')

	# modify options dictionary early
	# GLES enabled for android, raspi, devices, etc.
	if conf.env.DEST_OS == 'android' or conf.env.DEST_CPU in ['aarch32', 'aarch64']:
		conf.options.ALLOW64 = True # skip pointer length check
		conf.options.NO_VGUI = True # skip vgui
		conf.options.NANOGL = True
		conf.options.GLWES  = True
		conf.options.GL     = False

	# Force _WIN32 definition for windows (generally good for IDE integration)
	if conf.env.DEST_OS == 'win32':
		conf.env.append_unique('DEFINES', '_WIN32')
		conf.env.append_value('INCLUDES', ['common'])

	conf.env.append_value('INCLUDES', 'thirdparty/nuklear')
	conf.env.append_value('INCLUDES', 'modules')

	# Hardcoded include path for Mingw on Linux, also for IDE integration
	if conf.env.DEST_OS == 'win32' and sys.platform == 'linux':
		conf.env.append_unique('CXXFLAGS', '-I/usr/x86_64-w64-mingw32/include/')

	# We restrict 64-bit builds ONLY for Win/Linux/OSX running on Intel architecture
	# Because compatibility with original GoldSrc
	if conf.env.DEST_OS in ['win32', 'linux', 'darwin'] and conf.env.DEST_CPU in ['x86_64']:
		conf.env.BIT32_ALLOW64 = conf.options.ALLOW64
		if not conf.env.BIT32_ALLOW64:
			Logs.info('WARNING: will build engine for 32-bit target')
	else:
		conf.env.BIT32_ALLOW64 = True
	conf.env.BIT32_MANDATORY = not conf.env.BIT32_ALLOW64
	conf.load('force_32bit')
	if conf.env.DEST_OS != 'android' and not conf.options.DEDICATED:
		conf.load('sdl2')

	# Defines for posix-compliance
	if conf.env.DEST_OS in ['linux', 'darwin', 'freebsd']:
		conf.env.append_unique('DEFINES', '_POSIX=1')

	# Vectorization & code generation
	if conf.env.DEST_CPU == "x86_64":
		conf.env.append_unique('DEFINES', '_x64_=1')
		conf.env.append_unique('DEFINES', '_X64_=1')
	if conf.env.DEST_CPU == "x86":
		conf.env.append_unique('DEFINES', '_x86_=1')
		conf.env.append_unique('DEFINES', '_X86_=1')
	if conf.env.DEST_CPU == "aarch64":
		conf.env.append_unique('DEFINES', '_AARCH64_=1')
	if conf.env.DEST_CPU == "aarch32":
		conf.env.append_unique('DEFINES', '_AARCH32_=1')

	conf.options.USE_SSE    = conf.options.USE_SSE if conf.env.DEST_CPU in ['x86', 'x86_64'] else False
	conf.options.USE_SSE42  = conf.options.USE_SSE42 if conf.env.DEST_CPU in ['x86', 'x86_64'] else False
	conf.options.USE_AVX    = conf.options.USE_AVX if conf.env.DEST_CPU in ['x86_64'] else False
	conf.options.USE_NEON   = conf.options.USE_NEON if conf.env.DEST_CPU in ['aarch32', 'aarch64'] else False

	linker_flags = {
		'common': {
			'msvc':    ['/DEBUG'], # always create PDB, doesn't affect result binaries
			'gcc': ['-Wl,--no-undefined', '-g', '-lstdc++']
		},
		'sanitize': {
			'clang':   ['-fsanitize=undefined', '-fsanitize=address'],
			'gcc':     ['-fsanitize=undefined', '-fsanitize=address'],
		},
		'trace': {
			'clang': ['-fxray-instrument']
		}
	}

	compiler_c_cxx_flags = {
		'common': {
			# disable thread-safe local static initialization for C++11 code, as it cause crashes on Windows XP
			'msvc':    ['/D_USING_V110_SDK71_', '/std:c++17', '/Zi', '/FS', '/Zc:threadSafeInit-', '/DENABLE_XPROF'],
			'clang': ['-g', '-std=c++17', '-gdwarf-2', '-fvisibility=default', '-Wall', '-Wextra', '-Wno-unused-parameter', '-fpermissive', '-Wno-unused-function', '-DENABLE_XPROF'],
			'gcc': ['-g', '-std=c++17', '-Wno-expansion-to-defined', '-fvisibility=default', '-Wno-attributes', '-Wno-write-strings', '-Wall', '-Wextra', '-Wno-unused-parameter', '-fpermissive', '-Wno-unused-function', '-Wno-unused-variable', '-Wno-missing-field-initializers', '-Wno-invalid-offsetof', '-Wno-sign-compare', '-Wno-reorder', '-Wno-unknown-pragmas', '-DENABLE_XPROF']
		},
		'fast': {
			'msvc':    ['/O2', '/Oy', '/MT'], #todo: check /GL /LTCG
			'gcc':     ['-Ofast', '-march=native', '-funsafe-math-optimizations', '-funsafe-loop-optimizations', '-fomit-frame-pointer'],
			'clang':   ['-Ofast', '-march=native'],
			'default': ['-O3']
		},
		'release': {
			'msvc':    ['/O2', '/MT'],
			'default': ['-O3']
		},
		'debug': {
			'msvc':    ['/O1', '/DDEBUG', '/D_DEBUG', '/D_DEV', '/MTd'],
			'gcc':     ['-Og', '-DDEBUG=1', '-D_DEBUG=1', '-D_DEV=1'],
			'default': ['-O1', '-DDEBUG=1', '-D_DEBUG=1', '-D_DEV=1']
		},
		'sanitize': {
			'msvc':    ['/Od', '/RTC1', '/MT'],
			'gcc':     ['-Og', '-fsanitize=undefined', '-fsanitize=address'],
			'clang':   ['-O0', '-fsanitize=undefined', '-fsanitize=address'],
			'default': ['-O0']
		},
		'nooptimize': {
			'msvc':    ['/Od', '/MT'],
			'default': ['-O0']
		},
		'trace': {
			'default': [],
			'msvc': ['/MT'],
			'clang': ['-fxray-instrument']
		}
	}

	compiler_optional_flags = [
		'-fdiagnostics-color=always',
		'-Werror=return-type',
		'-Werror=parentheses',
	]

	# SIMD Extension support
	if conf.options.USE_SSE and not conf.options.NO_SSE:
		compiler_c_cxx_flags['common']['gcc'].append("-msse")
		compiler_c_cxx_flags['common']['clang'].append("-msse")
		if not conf.options.ALLOW64:
			compiler_c_cxx_flags['common']['msvc'] += ['/arch:SSE', '/arch:SSE2']
		conf.env.append_unique('DEFINES', 'USE_SSE=1')
	if conf.options.USE_SSE42:
		compiler_c_cxx_flags['common']['gcc'].append("-msse4.2")
		compiler_c_cxx_flags['common']['clang'].append("-msse4.2")
		# MSVC does not allow you to control this behaviour -_-
		conf.env.append_unique('DEFINES', 'USE_SSE42=1')
	if conf.options.USE_AVX:
		compiler_c_cxx_flags['common']['gcc'].append("-mavx")
		compiler_c_cxx_flags['common']['clang'].append("-mavx")
		compiler_c_cxx_flags['common']['msvc'].append('/arch:AVX')
		conf.env.append_unique('DEFINES', 'USE_AVX=1')
	if conf.options.USE_AVX2:
		compiler_c_cxx_flags['common']['gcc'].append("-mavx")
		compiler_c_cxx_flags['common']['clang'].append("-mavx")
		compiler_c_cxx_flags['common']['msvc'].append('/arch:AVX2')
		conf.env.append_unique('DEFINES', 'USE_AVX2=1')
	if conf.options.USE_NEON:
		compiler_c_cxx_flags['common']['gcc'].append("-mneon")
		compiler_c_cxx_flags['common']['clang'].append("-mneon")
		# MSVC does not support arm -_-
		conf.env.append_unique('DEFINES', 'USE_NEON=1')

	# Are we forcibly running a development build?
	if conf.options.DEV:
		conf.env.append_unique('DEFINES', '_DEV=1')

	cflags = conf.get_flags_by_type(compiler_c_cxx_flags, conf.options.BUILD_TYPE, conf.env.COMPILER_CC)

	conf.env.append_unique('LINKFLAGS', conf.get_flags_by_type(
		linker_flags, conf.options.BUILD_TYPE, conf.env.COMPILER_CC))

	if conf.env.COMPILER_CC == 'msvc':
		conf.env.append_unique('CFLAGS', cflags)
		conf.env.append_unique('CXXFLAGS', cflags)
	else:
		#conf.check_cc(cflags=cflags, msg= 'Checking for required C flags')
		conf.check_cxx(cxxflags=cflags, msg= 'Checking for required C++ flags')
		conf.env.append_unique('CFLAGS', cflags + filter_cflags(conf, compiler_optional_flags, cflags, False))
		conf.env.append_unique('CXXFLAGS', cflags + filter_cflags(conf, compiler_optional_flags, cflags, True))


	conf.env.DEDICATED     = conf.options.DEDICATED
	# we don't need game launcher on dedicated
	conf.env.SINGLE_BINARY = conf.options.SINGLE_BINARY or conf.env.DEDICATED
	if conf.env.DEST_OS == 'linux':
		conf.check_cxx( lib='dl' )

	if conf.env.DEST_OS != 'win32':
		if not conf.env.LIB_M: # HACK: already added in xcompile!
			conf.check_cxx( lib='m' )

		if conf.env.DEST_OS != 'android': # Android has pthread directly in libc
			conf.check_cxx( lib='pthread' )
	else:
		# Common Win32 libraries
		# Don't check them more than once, to save time
		# Usually, they are always available
		# but we need them in uselib
		conf.check_cxx( lib='user32' )
		conf.check_cxx( lib='shell32' )
		conf.check_cxx( lib='gdi32' )
		conf.check_cxx( lib='advapi32' )
		conf.check_cxx( lib='dbghelp' )
		conf.check_cxx( lib='psapi' )
		conf.check_cxx( lib='ws2_32' )


	# indicate if we are packaging for Linux/BSD
	if(not conf.options.WIN_INSTALL and
			conf.env.DEST_OS not in ['win32', 'darwin', 'android']):
		conf.env.LIBDIR = conf.env.BINDIR = '${PREFIX}/lib/xash3d'
	else:
		conf.env.LIBDIR = conf.env.BINDIR = conf.env.PREFIX

	# Figure out platform subdirectory
	platform_matrix = {
		"win32": {
			"x86": "win32",
			"amd64": "win64",
			"aarch32": "winarm32",
			"aarch64": "winarm64"
		},
		"linux": {
			"x86": "linux32",
			"x86_64": "linux64",
			"aarch32": "linuxarm32",
			"aarch64": "linuxarm64"
		},
		"freebsd": {
			"x86": "freebsd32",
			"x86_64": "freebsd64",
			"aarch32": "freebsdarm32",
			"aarch64": "freebsdarm64",
		},
		"darwin": {
			"x86": "osx32",
			"x86_64": "osx64",
			"aarch32": "osxarm32",
			"aarch64": "osxarm64"
		}
	}
	platform_subdir = platform_matrix[conf.env.DEST_OS][conf.env.DEST_CPU]

	# Configure the library directories
	conf.env.LIBDIR = conf.env.BINDIR = conf.env.PREFIX + '/bin/' + platform_subdir

	# Set the platform subdir
	conf.env.append_unique('DEFINES', 'PLATFORM_SUBDIR={0}'.format(platform_subdir))


	conf.env.append_unique('DEFINES', 'XASH_BUILD_COMMIT="{0}"'.format(conf.env.GIT_VERSION if conf.env.GIT_VERSION else 'notset'))

	# Set platform props
	if conf.options.ALLOW64:
		conf.env.PLATFORM_64BIT = True
		conf.env.PLATFORM_32BIT = False
	else:
		conf.env.PLATFORM_64BIT = False
		conf.env.PLATFORM_32BIT = True

	for i in SUBDIRS:
		if conf.env.SINGLE_BINARY and i.singlebin:
			continue

		if conf.env.DEST_OS == 'android' and i.singlebin:
			continue

		if conf.env.DEDICATED and i.dedicated:
			continue

		conf.recurse(i.name)
	conf.recurse('modules/public')
	conf.recurse('modules/mathlib')
	conf.recurse('games/' + conf.env.GAMEDIR + '/server')
	conf.recurse('games/' + conf.env.GAMEDIR + '/client')
	conf.recurse('modules/tier1')
	conf.recurse('modules/tier2')
	conf.recurse('modules/networksystem')
	conf.recurse('modules/rendersystem/renderlib')
	conf.recurse('utils/hlbsp')
	conf.recurse('utils/hlvis')
	conf.recurse('utils/hlcsg')
	conf.recurse('utils/hlrad')
	conf.recurse('modules/mainui2')

	conf.env.ENABLE_RENDERER2 = conf.options.ENABLE_RENDERER2
	conf.env.SCRIPTING = conf.options.ENABLE_SCRIPTING

	if conf.options.ENABLE_SCRIPTING:
		conf.recurse('modules/scriptsystem')
	if conf.options.ENABLE_RENDERER2:
		conf.recurse('modules/rendersystem')

def build(bld):
	for i in SUBDIRS:
		if bld.env.SINGLE_BINARY and i.singlebin:
			continue

		if bld.env.DEST_OS == 'android' and i.singlebin:
			continue

		if bld.env.DEDICATED and i.dedicated:
			continue

		bld.recurse(i.name)
	bld.recurse('games/' + bld.env.GAMEDIR + '/server')
	bld.recurse('games/' + bld.env.GAMEDIR + '/client')
	bld.recurse('modules/mathlib')
	bld.recurse('modules/public')
	bld.recurse('modules/tier1')
	bld.recurse('modules/tier2')
	bld.recurse('modules/networksystem')
	bld.recurse('modules/rendersystem/renderlib')
	bld.recurse('utils/hlbsp')
	bld.recurse('utils/hlvis')
	bld.recurse('utils/hlcsg')
	bld.recurse('utils/hlrad')
	bld.recurse('modules/mainui2')

	if bld.env.SCRIPTING:
		bld.recurse('modules/scriptsystem')
	if bld.env.ENABLE_RENDERER2:
		bld.recurse('modules/rendersystem')
