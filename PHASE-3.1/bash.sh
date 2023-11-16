#!/bin/bash

flex lex.l
bison -dtv bison.y 
g++ -w -c main.cpp
g++ -w -o ex.o lex.yy.c bison.tab.c semantics.cpp symbol_table.cpp main.o -ll

