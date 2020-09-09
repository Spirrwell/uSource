#!/bin/sh
TOP=`git rev-parse --show-toplevel`
# Runs clang-tidy will all the specified checks
FILES=$(find . -type f -not -path "./thirdparty" \( -iname '*.cpp' \) )
for file in $FILES; do
  clang-tidy -p="$TOP/build" -header-filter=.* --checks=-performance-*,-bugprone-sizeof*,-bugprone-macro-* $file
done