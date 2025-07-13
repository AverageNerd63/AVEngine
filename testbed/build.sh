#!/bin/bash
# Build script for Engine
set echo on

mkdir -p ../bin

# Get list of all the .c files
cFilenames=$(find . -type f -name "*.c")

# echo "Files:" $cFilenames
assembly="testbed"
compilerFlags="-g -fdeclspec -fPIC"
# -fms-extension
# -Wall -Werror
inlcudeFlags="-Isrc -I../engine/src/"
linkerFlags="-L../bin/ -lengine -Wl,-rpath,."
defines="-D_DEBUG -DAIMPORT"

echo "Building $assembly..."
clang $cFilenames $compilerFlags -o ../bin/lib$assembly.so $defines $inlcudeFlags $compilerFlags