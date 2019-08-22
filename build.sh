#!/bin/bash

cmake . || exit 1
make all -j || exit 1
make check || exit 1
./test/unittest.bin --gtest_output=xml:result.xml
