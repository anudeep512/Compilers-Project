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
%token BOOLEANLITERAL
%token FLOATLITERAL
%token SCOPEOPEN
%token SCOPECLOSE
%token ROUNDOPEN
%token ROUNDCLOSE
%token SQUAREOPEN
%token SQUARECLOSE
%token HASH
%token LEXERROR

%token NNUM
%token NDEC
%token NBOOL
%token NLET
%token NTEXT
%token NVOID

%token ANUM
%token ADEC
%token ABOOL
%token ALET
%token ATEXT

%start begin
%%
begin : ;
%%

void yyerror(string s){
  cout << s << endl;
}






