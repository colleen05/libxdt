#!/bin/bash

# Make sure CXX environment variable is set.
if [ -z "$CXX" ]
then
    echo "error: CXX environment variable is not set. Please set this to your preferred C++ compiler."
    exit
fi

# Introduction
echo "Building libsphynx [linux]..."

# Setting up directories
echo "Creating directories..."
mkdir -p tmp

# Compiling
echo "Compiling object files..."
${CXX} -c -o tmp/sphynx.o src/sphynx.cpp -Iinclude -std=c++17

echo "Building static library..."
rm bin/libsphynx.a
ar rcs bin/libsphynx.a tmp/sphynx.o

# Cleaning up
echo "Removing temporary directories..."
rm -r tmp