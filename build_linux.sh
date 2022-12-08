#!/bin/bash

# Make sure CXX environment variable is set.
if [ -z "$CXX" ]
then
    echo "error: CXX environment variable is not set. Please set this to your preferred C++ compiler."
    exit
fi

# Introduction
echo "Building libxdt [linux]..."

# Setting up directories
echo "Creating directories..."
mkdir -p tmp

# Compiling
echo "Compiling object files..."
${CXX} -c -o tmp/libxdt.o src/libxdt.cpp -Iinclude -std=c++17

echo "Building static library..."
rm bin/libxdt.a
ar rcs bin/libxdt.a tmp/libxdt.o

# Cleaning up
echo "Removing temporary directories..."
rm -r tmp