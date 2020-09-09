#!/bin/sh
TOP=`git rev-parse --show-toplevel`
# Runs clang-tidy will all the specified checks
echo $(find ./public -iname "*.cpp")
clang-tidy -p="$TOP/build" --checks=-performance-*,-bugprone-sizeof*,-bugprone-macro-* $(find . -iname "*.cpp")