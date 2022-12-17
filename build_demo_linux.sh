#!/bin/bash

./build_linux.sh

${CXX} -o bin/demo src/Demo.cpp -Iinclude -Lbin/ -lxdt -std=c++17