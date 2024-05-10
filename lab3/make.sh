#!/bin/bash
flex lexical.l
bison -d syntax.y
flex lexical.l
gcc main.c syntax.tab.c -lfl -o parser