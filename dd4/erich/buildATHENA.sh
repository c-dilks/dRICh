#!/bin/bash
# convenience build script, to try to avoid copying too much to this working subdirectory;
# just calls ../buildATHENA.sh; outputs geo file to ../out/
pushd ..
./buildATHENA.sh $*
popd
