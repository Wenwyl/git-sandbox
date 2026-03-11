#!/bin/bash

set -e

SRC_DIR="src"
BUILD_DIR="build"
INCLUDE_DIR="include"

mkdir -p "$BUILD_DIR"

cat > "$BUILD_DIR/build.ninja" <<EOF
rule cxx
  command = g++ -std=c++17 -Wall -Wextra -I$INCLUDE_DIR -c \$in -o \$out

rule link
  command = g++ \$in -o \$out

build main.o: cxx ../$SRC_DIR/main.cpp
build app: link main.o

default app
EOF

cd "$BUILD_DIR"
ninja