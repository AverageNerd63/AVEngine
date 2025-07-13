#!/bin/bash
# Build script for Engine
set echo on

echo "Build Everything..."

pushd engine
source build.sh
popd

ERRORLEVEL=$?
if [$ERRORLEVEL -no 0]
then
echo "Error:"$ERRORLEVEL && extension
fi

pushd testbed
source build.sh
popd

ERRORLEVEL=$?
if [$ERRORLEVEL -no 0]
then
echo "Error:"$ERRORLEVEL && extension
fi

echo "All assemblies built successfully"