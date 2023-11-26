#!/bin/bash

flex lex.l
bison -dtv bison.y 
g++ -w -c main.cpp
g++ -w -o semantic.o lex.yy.c bison.tab.c semantics.cpp errors.cpp symbol_table.cpp main.o -ll

./semantic.o $1
rm lex.yy.c bison.output bison.tab.c bison.tab.h semantic.o main.o


    flex codegen.l 
    bison -dtv codegen.y 
    g++ -w -c main.cpp
    g++ -w -o codegen.o lex.yy.c codegen.tab.c codegen.cpp main.o -ll
    ./codegen.o $1

    rm lex.yy.c codegen.output codegen.tab.c codegen.tab.h codegen.o main.o



