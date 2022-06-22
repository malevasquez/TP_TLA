#!/bin/bash
bin/Compiler < Programs/$1 5> src/backend/archivoPrueba.c 6> partiture.tex

if [[ $? == 0 ]]; 
    then
        cd src
        make all
        clear
fi
