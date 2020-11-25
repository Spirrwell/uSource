#!/bin/sh
TOP=$(cd $(dirname $0);pwd)
cd "$TOP/../"
git submodule init
git submodule update
./waf configure -T debug -8 -W --dev
./waf build
