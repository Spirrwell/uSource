#!/bin/bash
export CC="/usr/bin/i686-w64-mingw32-gcc"
export CXX="/usr/bin/i686-w64-mingw32-g++"
export LD="/usr/bin/i686-w64-mingw32-g++"
export WINRC=i686-w64-mingw32-windres
./waf configure clangdb -T debug -8 -W --prefix=~/Games/uSource --enable-new-renderer 
