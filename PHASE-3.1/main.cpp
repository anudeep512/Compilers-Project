#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

extern int yyparse();
extern FILE * yyin ;
extern FILE * yyout ;
FILE * fp, *fpcpp;

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

  // Code Output
  std::string outputCodePath = std::string("./code_output/")+argv[1]+".cpp";
  fpcpp = fopen(outputCodePath.c_str(),"w");
  fprintf(fpcpp, "#include <bits/stdc++.h>\n#include \"matplotlibcpp.h\"\n\nusing namespace std;\n\n\n");

  int i=yyparse();

  return 0 ;

}






