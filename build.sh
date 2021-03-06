#!/bin/bash

export BOOSTNUMERICBINDINGS_DIR=$(pwd)/boost-numeric-bindings

HOST=$(uname -n | tr " -." "___")
FIBERGEN_DIR=$(cd $(dirname "$0") && pwd)

BUILD_DIR="$FIBERGEN_DIR/build/$HOST"
mkdir -p "$BUILD_DIR" || exit
cd "$BUILD_DIR" || exit
cmake -DCMAKE_VERBOSE_MAKEFILE:BOOL=OFF "$@" ../.. || exit
make || exit

echo ""
echo "Build successful!"
echo "Please update your environmet variables, i.e.:"
echo "export PATH=\$PATH:$FIBERGEN_DIR/bin"
echo "export PYTHONPATH=\$PYTHONPATH:$FIBERGEN_DIR/lib"
