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
  fprintf(fpcpp, "#include <iostream>\n#include <thread>\n#include <mutex>\n#include <atomic>\n#include <fstream>\n#include <sstream>\n#include <chrono>\n#include \"codegen.hpp\"\n#include <random>\n#include <time.h>\n#include <unistd.h>\n#include <cstdlib>\n#include <ctime>\n#include <cmath>\n#include <vector>\n#include <thread>\n#include <map>\n//#include \"matplotlibcpp.h\"\n\nusing namespace std;\nusing namespace chrono;\n\nTimer gett; \nmutex mtx[100000];\nint mut = 0;\n\n");

  int i=yyparse();

  return 0 ;

}







