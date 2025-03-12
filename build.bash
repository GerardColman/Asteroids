#! /usr/bin/env bash

g++ src/main.cpp -o app `pkg-config --libs --cflags sdl3`

ECHO "BUILD COMPLETE"