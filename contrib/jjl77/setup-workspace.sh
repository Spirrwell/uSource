#!/bin/bash

pushd `dirname $0` > /dev/null
TOP=$(cd ../.. && pwd)
ln -s "$PWD/workspace.code-workspace" "$TOP/workspace.code-workspace"
ln -s "$PWD/.vscode" "$TOP/.vscode"
