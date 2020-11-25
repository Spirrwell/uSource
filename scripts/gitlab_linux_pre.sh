#!/bin/sh

apt-get update
apt-get install python3 python3-pip gcc g++ gcc-multilib g++-multilib libsdl2-dev \
libsdl2-gfx-dev libsdl2-image-dev libprotobuf-dev protobuf-compiler protobuf-compiler-grpc

pip3 install waftools
