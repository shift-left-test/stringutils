#!/bin/bash

cmake .
make all -j
./test/unittest.bin --gtest_output=xml:result.xml
