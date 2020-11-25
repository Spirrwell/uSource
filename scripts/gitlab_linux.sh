#!/bin/sh
TOP=$(cd $(dirname $0);pwd)
cd "$TOP/../"

./configure -T debug -8 -W --dev
./build
