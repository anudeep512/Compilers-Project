%{
  #include <iostream>
  #include <string>
  extern int yylex();
  extern int yylineno;
  void yyerror(string s);
%}

%token SPECIALSYMBOL
%token INTEGERLITERAL
%token STRINGLITERAL
%token CHARLITERAL
%token BOOLLITERAL

%start begin
%%
begin : ;
%%

void yyerror(string s){
  cout << s << endl;
}






