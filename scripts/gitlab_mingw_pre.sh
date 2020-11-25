#!/bin/sh

apt update
apt -y install mingw-w64 mingw-w64-common mingw-w64-tools python3 python3-pip gcc g++ gcc-multilib g++-multilib libsdl2-dev \
libsdl2-gfx-dev libsdl2-image-dev libprotobuf-dev protobuf-compiler protobuf-compiler-grpc git

pip3 install waftools
# TODO: install sdl2 for mingw
