#!/bin/bash

flex lex.l
bison -dtv bison.y 
g++ -w -c main.cpp
g++ -w -o semantic.o lex.yy.c bison.tab.c semantics.cpp errors.cpp symbol_table.cpp main.o -ll

./semantic.o $1

rm lex.yy.c bison.output bison.tab.c bison.tab.h semantic.o main.o

exit_status=$?


if [ $exit_status -eq 0 ]; then
    echo "Semantics Successful!"
    flex codegen.l
    bison -dtv codegen.y 
    g++ -w -c main.cpp
    g++ -w -o codegen.o lex.yy.c codegen.tab.c codegen.cpp main.o -ll
    ./codegen.o $1
elif [ $exit_status -eq 1 ]; then
    echo "SEMANTICS FAILED!!"

    rm lex.yy.c codegen.output codegen.tab.c codegen.tab.h codegen.o main.o
fi
