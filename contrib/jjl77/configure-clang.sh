#!/bin/bash
export CC=clang
export CXX=clang++
./waf configure clangdb -T debug -8 -W --prefix=~/Games/uSource --enable-new-renderer 
