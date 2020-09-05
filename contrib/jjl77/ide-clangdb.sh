#!/bin/sh
TOP=`git rev-parse --show-toplevel`


# Mingw debug/release
export CC="/usr/bin/i686-w64-mingw32-gcc"
export CXX="/usr/bin/i686-w64-mingw32-g++"
export WINRC=i686-w64-mingw32-windres
rm "$TOP/build/compile_commands.json"
"$TOP/waf" configure clangdb -T debug -8 -W --prefix=~/Games/uSource --enable-new-renderer
cp -v "$TOP/build/compile_commands.json" "$TOP/compile_commands_mingw_debug.json"
rm "$TOP/build/compile_commands.json"
"$TOP/waf" configure clangdb -T release -8 -W --prefix=~/Games/uSource --enable-new-renderer
cp -v "$TOP/build/compile_commands.json" "$TOP/compile_commands_mingw_release.json"

# GCC
export CC=gcc
export CXX=g++
rm "$TOP/build/compile_commands.json"
"$TOP/waf" configure clangdb -T release -8 -W --prefix=~/Games/uSource --enable-new-renderer
cp -v "$TOP/build/compile_commands.json" "$TOP/compile_commands_gcc_debug.json"
rm "$TOP/build/compile_commands.json"
"$TOP/waf" configure clangdb -T debug -8 -W --prefix=~/Games/uSource --enable-new-renderer
cp -v "$TOP/build/compile_commands.json" "$TOP/compile_commands_gcc_release.json"
