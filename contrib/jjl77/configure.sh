#!/bin/bash
rm build/compile_commands.json
./waf configure clangdb cmake -T debug -8 -W --prefix=~/Games/uSource --enable-new-renderer --enable-remote-control
