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
	Subproject('public',      dedicated=False),
	Subproject('launcher', singlebin=True),
	Subproject('ref_gl'),
	#Subproject('ref_soft'),
	Subproject('mainui'),
	# Subproject('vgui_support'),
	Subproject('engine', dedicated=False),
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

	grp.add_option('--neon', action='store_true', dest='USE_NEON', default=False,
				   help='Enables the use of NEON vectorization on AArch64 and AArch32 targets.')

	grp.add_option('--memory-debug', action='store_true', dest='MEMORY_DEBUG', default=False,
				   help='Enables the use of memory debugging. This will define various Mem_XXX functions as macros which will include the locations where the allocations tool place')

	grp.add_option('--enable-scripting', action='store_true', dest='ENABLE_SCRIPTING', default=True,
				   help='Enables scripting')

	grp.add_option('--enable-luajit', action='store_true', dest='ENABLE_LUA', default=True,
				   help='Enables lua scripting')

	grp.add_option('--enable-new-renderer', action='store_true', dest='ENABLE_RENDERER2', default=False, help='Enables the use of the new renderer')
	grp.add_option('--enable-vulkan', action='store_true', dest='ENABLE_VULKAN', default=False, help='Enables the use of the vulkan backend')

	opt.load('subproject')

	opt.add_subproject(subdirs())

	opt.load('xcompile compiler_cxx compiler_c sdl2 clang_compilation_database strip_on_install')
	opt.load('cmake msdev eclipse codeblocks doxygen export', tooldir=waftools.location)
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
				conf.check_cc(cflags = [flag] + check_flags)
		except conf.errors.ConfigurationError:
			conf.end_msg('no', color='YELLOW')
		else:
			conf.end_msg('yes')
			supported_flags.append(flag)

	return supported_flags

def configure(conf):
	# Dirs
	conf.env.ROOT = str(pathlib.Path('.').resolve())
	conf.env.PMSHARED = str(conf.env.ROOT + "/pm_shared")
	conf.env.ENGINE = str(conf.env.ROOT + "/engine")
	conf.env.SHARED = str(conf.env.ROOT + "/game/shared")
	conf.env.SERVER = str(conf.env.ROOT + "/game/server")
	conf.env.CLIENT = str(conf.env.ROOT + "/game/client")
	conf.env.COMMON = str(conf.env.ROOT + "/common")
	conf.env.PUBLIC = str(conf.env.ROOT + "/public")
	conf.env.FAKEVGUI = str(conf.env.ROOT + "/utils/false_vgui/include")
	conf.env.MATHLIB = str(conf.env.ROOT + "/mathlib")

	# Set some opts needed by the server
	conf.env.GAMEDIR = 'hl1'
	conf.env.CLIENT_DIR  = 'bin'
	conf.env.SERVER_DIR  = 'bin'

	conf.options.NO_VGUI = True

	# Add some defines that will let us configure project name, desc, ver, etc.
	conf.env.append_unique('DEFINES', 'PROJECT_NAME=\"{0}\"'.format(APPNAME))
	conf.env.append_unique('DEFINES', 'PROJECT_VERSION=\"{0}\"'.format(VERSION))
	conf.env.append_unique('DEFINES', 'PROJECT_DESCRIPTION=\"{0}\"'.format(DESCRIPTION))

	conf.load('fwgslib reconfigure cmake msdev eclipse codeblocks doxygen export')
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
	conf.env.MSVC_TARGETS = ['x86'] # explicitly request x86 target for MSVC
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

	opts = list()
	if conf.options.USE_SSE:
		opts.append("-msse")
		conf.env.append_unique('DEFINES', 'USE_SSE=1')
	if conf.options.USE_SSE42:
		opts.append("-msse4.2")
		conf.env.append_unique('DEFINES', 'USE_SSE42=1')
	if conf.options.USE_AVX:
		opts.append("-mavx")
		conf.env.append_unique('DEFINES', 'USE_AVX=1')
	if conf.options.USE_NEON:
		opts.append("-mneon")
		conf.env.append_unique('DEFINES', 'USE_NEON=1')

	linker_flags = {
		'common': {
			'msvc':    ['/DEBUG'], # always create PDB, doesn't affect result binaries
			'gcc': ['-Wl,--no-undefined', '-g']
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
			'msvc':    ['/D_USING_V110_SDK71_', '/Zi', '/FS', '/Zc:threadSafeInit-', '/MT', '/DENABLE_XPROF'],
			'clang': ['-g', '-gdwarf-2', '-fvisibility=default', '-Wall', '-Wextra', '-Wno-unused-parameter', '-fpermissive', '-Wno-unused-function', '-DENABLE_XPROF'],
			'gcc': ['-g', '-fvisibility=default', '-Wno-attributes', '-Wno-write-strings', '-Wall', '-Wextra', '-Wno-unused-parameter', '-fpermissive', '-Wno-unused-function', '-Wno-unused-variable', '-Wno-missing-field-initializers', '-Wno-invalid-offsetof', '-Wno-sign-compare', '-Wno-reorder', '-Wno-unknown-pragmas', '-DENABLE_XPROF']
		},
		'fast': {
			'msvc':    ['/O2', '/Oy'], #todo: check /GL /LTCG
			'gcc':     ['-Ofast', '-march=native', '-funsafe-math-optimizations', '-funsafe-loop-optimizations', '-fomit-frame-pointer'],
			'clang':   ['-Ofast', '-march=native'],
			'default': ['-O3']
		},
		'release': {
			'msvc':    ['/O2'],
			'default': ['-O3']
		},
		'debug': {
			'msvc':    ['/O1', '/DDEBUG', '/D_DEBUG'],
			'gcc':     ['-Og', '-DDEBUG=1', '-D_DEBUG=1'],
			'default': ['-O1', '-DDEBUG=1', '-D_DEBUG=1']
		},
		'sanitize': {
			'msvc':    ['/Od', '/RTC1'],
			'gcc':     ['-Og', '-fsanitize=undefined', '-fsanitize=address'],
			'clang':   ['-O0', '-fsanitize=undefined', '-fsanitize=address'],
			'default': ['-O0']
		},
		'nooptimize': {
			'msvc':    ['/Od'],
			'default': ['-O0']
		},
		'trace': {
			'default': [],
			'clang': ['-fxray-instrument']
		}
	}

	compiler_c_cxx_flags['common']['gcc'] += opts
	compiler_c_cxx_flags['common']['clang'] += opts

	compiler_optional_flags = [
		'-fdiagnostics-color=always',
		'-Werror=return-type',
		'-Werror=parentheses',
	]

	cflags = conf.get_flags_by_type(compiler_c_cxx_flags, conf.options.BUILD_TYPE, conf.env.COMPILER_CC)

	conf.env.append_unique('LINKFLAGS', conf.get_flags_by_type(
		linker_flags, conf.options.BUILD_TYPE, conf.env.COMPILER_CC))

	if conf.env.COMPILER_CC == 'msvc':
		conf.env.append_unique('CFLAGS', cflags)
		conf.env.append_unique('CXXFLAGS', cflags)
	else:
		conf.check_cc(cflags=cflags, msg= 'Checking for required C flags')
		conf.check_cxx(cxxflags=cflags, msg= 'Checking for required C++ flags')
		conf.env.append_unique('CFLAGS', cflags + filter_cflags(conf, compiler_optional_flags, cflags, False))
		conf.env.append_unique('CXXFLAGS', cflags + filter_cflags(conf, compiler_optional_flags, cflags, True))


	conf.env.DEDICATED     = conf.options.DEDICATED
	# we don't need game launcher on dedicated
	conf.env.SINGLE_BINARY = conf.options.SINGLE_BINARY or conf.env.DEDICATED
	if conf.env.DEST_OS == 'linux':
		conf.check_cc( lib='dl' )

	if conf.env.DEST_OS != 'win32':
		if not conf.env.LIB_M: # HACK: already added in xcompile!
			conf.check_cc( lib='m' )

		if conf.env.DEST_OS != 'android': # Android has pthread directly in libc
			conf.check_cc( lib='pthread' )
	else:
		# Common Win32 libraries
		# Don't check them more than once, to save time
		# Usually, they are always available
		# but we need them in uselib
		conf.check_cc( lib='user32' )
		conf.check_cc( lib='shell32' )
		conf.check_cc( lib='gdi32' )
		conf.check_cc( lib='advapi32' )
		conf.check_cc( lib='dbghelp' )
		conf.check_cc( lib='psapi' )
		conf.check_cc( lib='ws2_32' )


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
			"x86_64": "win64",
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

	for i in SUBDIRS:
		if conf.env.SINGLE_BINARY and i.singlebin:
			continue

		if conf.env.DEST_OS == 'android' and i.singlebin:
			continue

		if conf.env.DEDICATED and i.dedicated:
			continue

		conf.add_subproject(i.name)
	conf.add_subproject('public')
	conf.add_subproject('mathlib')
	conf.recurse('game/server')
	conf.recurse('game/client')
	conf.recurse('tier1')
	conf.recurse('tier2')
	conf.recurse('networksystem')
	conf.recurse('rendersystem/renderlib')

	conf.env.ENABLE_RENDERER2 = conf.options.ENABLE_RENDERER2

	if conf.options.ENABLE_RENDERER2:
		conf.recurse('rendersystem')

def build(bld):
	for i in SUBDIRS:
		if bld.env.SINGLE_BINARY and i.singlebin:
			continue

		if bld.env.DEST_OS == 'android' and i.singlebin:
			continue

		if bld.env.DEDICATED and i.dedicated:
			continue

		bld.add_subproject(i.name)
	bld.recurse('game/server')
	bld.recurse('game/client')
	bld.recurse('mathlib')
	bld.recurse('public')
	bld.recurse('tier1')
	bld.recurse('tier2')
	bld.recurse('networksystem')
	bld.recurse('rendersystem/renderlib')

	if bld.env.ENABLE_RENDERER2:
		bld.recurse('rendersystem')
