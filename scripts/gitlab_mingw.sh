#!/bin/sh
TOP=$(cd $(dirname $0);pwd)
cd "$TOP/../"

export CC=x86_64-w64-mingw32-gcc
export CXX=x86_64-w64-mingw32-g++
export RC=x86_64-w64-mingw32-windres

git submodule init
git submodule update
python3 waf configure -T debug -8 -W --dev
python3 waf build
