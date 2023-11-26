#!/bin/bash

flex lex.l
bison -dtv bison.y 
g++ -std=c++20 -w -c main.cpp
g++ -std=c++20 -w -o semantic.o lex.yy.c bison.tab.c semantics.cpp errors.cpp symbol_table.cpp main.o -ll

./semantic.o $1
exit_status=$?

if [ $exit_status -eq 0 ]; then
    echo "SEMANTICS SUCCESSFUL"
    flex codegen.l 
    bison -dtv codegen.y 
    g++ -std=c++20 -w -c main.cpp
    g++ -std=c++20 -w -o codegen.o lex.yy.c codegen.tab.c codegen.cpp main.o -ll
    ./codegen.o $1
    rm lex.yy.c codegen.output codegen.tab.c codegen.tab.h codegen.o main.o
    rm bison.output bison.tab.c bison.tab.h semantic.o
    echo "CODE GENERATION COMPLETED" 
elif [ $exit_status -eq 1 ]; then
    echo "SEMANTICS FAILURE"
    rm bison.output bison.tab.c bison.tab.h semantic.o main.o lex.yy.c
fi


