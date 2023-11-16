#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include "bison.tab.h"
#include "semantics.hpp"
#include "errors.hpp"
#include "symbol_table.hpp"

extern int yyparse();
extern FILE * yyin ;
extern FILE * yyout ;
FILE * fp, *fcode;

int main(int argc, char ** argv) {

  // Test Case Reading
  std::string inputPath = std::string("./testcases/")+argv[1]+".cx";
  yyin = fopen(inputPath.c_str(),"r");

  // Token Writing
  std::string outputTokenPath = std::string("./token_output/")+argv[1]+".tokens";
  fp = fopen(outputTokenPath.c_str(),"w");

  // Parsed Output
  std::string outputParsedPath = std::string("./parsed_output/")+argv[1]+".parsed";
  yyout = fopen(outputParsedPath.c_str(),"w");

  // Code Generation
  std::string outputCodePath = std::string("./code_output/")+argv[1]+".code";
  fcode = fopen(outputCodePath.c_str(),"w");
  
  int i=yyparse();

  return 0 ;

}






