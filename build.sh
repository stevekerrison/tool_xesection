#!/bin/sh

mkdir -p bin
g++ -O2 -Wall src/XE.cpp src/xesection.cpp -o bin/xesection
