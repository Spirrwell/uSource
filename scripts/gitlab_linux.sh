#!/bin/sh
TOP=$(cd $(dirname $0);pwd)
cd "$TOP/../"
git submodule init
git submodule update
python3 waf configure -T debug -8 -W --dev
python3 waf build
