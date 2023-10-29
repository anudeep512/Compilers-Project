/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_BISON_TAB_H_INCLUDED
# define YY_YY_BISON_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    WHEN = 258,
    REPEAT = 259,
    ELSE_WHEN = 260,
    DEFAULT = 261,
    FOR = 262,
    BREAK = 263,
    CONTINUE = 264,
    TASK = 265,
    MAKE_PARALLEL = 266,
    NULL_ARGS = 267,
    TID = 268,
    ANALYZE = 269,
    GET = 270,
    SLEEP = 271,
    TIME = 272,
    START = 273,
    RETURN = 274,
    TYPE = 275,
    ATOMIC = 276,
    IN = 277,
    FUNC = 278,
    INVOKE = 279,
    IP = 280,
    OP = 281,
    DIV = 282,
    ADD = 283,
    SUB = 284,
    MUL = 285,
    EXPONENT = 286,
    MODULO = 287,
    ARROW = 288,
    EQ = 289,
    INCR = 290,
    DECR = 291,
    ASSN_MODULO = 292,
    ASSN_EXPONENT = 293,
    ASSN_DIV = 294,
    ASSN_MUL = 295,
    AND = 296,
    OR = 297,
    GT = 298,
    LT = 299,
    GTEQ = 300,
    LTEQ = 301,
    NOT_EQ = 302,
    NEG = 303,
    EQUAL_TWO = 304,
    INTEGERLITERAL = 305,
    STRINGLITERAL = 306,
    CHARACTERLITERAL = 307,
    BOOLEANLITERAL = 308,
    FLOATLITERAL = 309,
    COMMA = 310,
    SEMICOLON = 311,
    COLON = 312,
    IDENTIFIER = 313,
    SCOPEOPEN = 314,
    SCOPECLOSE = 315,
    ROUNDOPEN = 316,
    ROUNDCLOSE = 317,
    SQUAREOPEN = 318,
    SQUARECLOSE = 319,
    HASH = 320,
    LEXERROR = 321,
    NNUM = 322,
    NDEC = 323,
    NBOOL = 324,
    NLET = 325,
    NTEXT = 326,
    NVOID = 327,
    NARRNUM = 328,
    NARRDEC = 329,
    NARRBOOL = 330,
    NARRLET = 331,
    NARRTEXT = 332,
    ANUM = 333,
    ADEC = 334,
    ABOOL = 335,
    ALET = 336,
    ATEXT = 337,
    AARRNUM = 338,
    AARRDEC = 339,
    AARRBOOL = 340,
    AARRLET = 341,
    AARRTEXT = 342,
    UDATATYPE = 343,
    AUDATATYPE = 344
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */
