#!/bin/bash
rm build/compile_commands.json
./waf configure clangdb -T debug -8 -W --prefix=~/Desktop/Projects/usource-content --enable-new-renderer -s ~/Desktop/Programs/SDL2
