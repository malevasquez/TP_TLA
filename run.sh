#! /bin/bash
rm -r bin
rm src/frontend/lexical-analysis/flex-scanner.c
rm src/frontend/syntactic-analysis/bison-parser.c
rm src/frontend/syntactic-analysis/bison-parser.h
cmake -S . -B bin
cd bin
make
cd ..
