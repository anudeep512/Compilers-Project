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
%token CHARACTERLITERAL
%token BOOLLITERAL
%token SCOPEOPEN
%token SCOPECLOSE
%token ROUNDOPEN
%token ROUNDCLOSE
%token SQUAREOPEN
%token SQUARECLOSE
%token HASH
%token LEXERROR

%start begin
%%
begin : ;
%%

void yyerror(string s){
  cout << s << endl;
}






