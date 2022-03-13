#!bin/bash

clang -o myEcho$1.out myEcho.c -D ECHO=\'$1\'
