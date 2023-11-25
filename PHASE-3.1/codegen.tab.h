/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_CODEGEN_TAB_H_INCLUDED
# define YY_YY_CODEGEN_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    WHEN = 258,                    /* WHEN  */
    REPEAT = 259,                  /* REPEAT  */
    ELSE_WHEN = 260,               /* ELSE_WHEN  */
    DEFAULT = 261,                 /* DEFAULT  */
    FOR = 262,                     /* FOR  */
    BREAK = 263,                   /* BREAK  */
    CONTINUE = 264,                /* CONTINUE  */
    TASK = 265,                    /* TASK  */
    MAKE_PARALLEL = 266,           /* MAKE_PARALLEL  */
    NULL_ARGS = 267,               /* NULL_ARGS  */
    TID = 268,                     /* TID  */
    ANALYZE = 269,                 /* ANALYZE  */
    GET = 270,                     /* GET  */
    SLEEP = 271,                   /* SLEEP  */
    TIME = 272,                    /* TIME  */
    START = 273,                   /* START  */
    RETURN = 274,                  /* RETURN  */
    TYPE = 275,                    /* TYPE  */
    ATOMIC = 276,                  /* ATOMIC  */
    ARRAY = 277,                   /* ARRAY  */
    IN = 278,                      /* IN  */
    FUNC = 279,                    /* FUNC  */
    INVOKE = 280,                  /* INVOKE  */
    IP = 281,                      /* IP  */
    OP = 282,                      /* OP  */
    DIV = 283,                     /* DIV  */
    ADD = 284,                     /* ADD  */
    SUB = 285,                     /* SUB  */
    MUL = 286,                     /* MUL  */
    EXPONENT = 287,                /* EXPONENT  */
    MODULO = 288,                  /* MODULO  */
    ARROW = 289,                   /* ARROW  */
    EQ = 290,                      /* EQ  */
    INCR = 291,                    /* INCR  */
    DECR = 292,                    /* DECR  */
    ASSN_MODULO = 293,             /* ASSN_MODULO  */
    ASSN_EXPONENT = 294,           /* ASSN_EXPONENT  */
    ASSN_DIV = 295,                /* ASSN_DIV  */
    ASSN_MUL = 296,                /* ASSN_MUL  */
    AND = 297,                     /* AND  */
    OR = 298,                      /* OR  */
    GT = 299,                      /* GT  */
    LT = 300,                      /* LT  */
    GTEQ = 301,                    /* GTEQ  */
    LTEQ = 302,                    /* LTEQ  */
    NOT_EQ = 303,                  /* NOT_EQ  */
    NEG = 304,                     /* NEG  */
    EQUAL_TWO = 305,               /* EQUAL_TWO  */
    INTEGERLITERAL = 306,          /* INTEGERLITERAL  */
    STRINGLITERAL = 307,           /* STRINGLITERAL  */
    CHARACTERLITERAL = 308,        /* CHARACTERLITERAL  */
    BOOLEANLITERAL = 309,          /* BOOLEANLITERAL  */
    FLOATLITERAL = 310,            /* FLOATLITERAL  */
    PIPE = 311,                    /* PIPE  */
    IDENTIFIER = 312,              /* IDENTIFIER  */
    COMMA = 313,                   /* COMMA  */
    SEMICOLON = 314,               /* SEMICOLON  */
    COLON = 315,                   /* COLON  */
    SCOPEOPEN = 316,               /* SCOPEOPEN  */
    SCOPECLOSE = 317,              /* SCOPECLOSE  */
    ROUNDOPEN = 318,               /* ROUNDOPEN  */
    ROUNDCLOSE = 319,              /* ROUNDCLOSE  */
    SQUAREOPEN = 320,              /* SQUAREOPEN  */
    SQUARECLOSE = 321,             /* SQUARECLOSE  */
    HASH = 322,                    /* HASH  */
    LEXERROR = 323,                /* LEXERROR  */
    NNUM = 324,                    /* NNUM  */
    NDEC = 325,                    /* NDEC  */
    NBOOL = 326,                   /* NBOOL  */
    NLET = 327,                    /* NLET  */
    NTEXT = 328,                   /* NTEXT  */
    NVOID = 329,                   /* NVOID  */
    NARRNUM = 330,                 /* NARRNUM  */
    NARRDEC = 331,                 /* NARRDEC  */
    NARRBOOL = 332,                /* NARRBOOL  */
    NARRLET = 333,                 /* NARRLET  */
    NARRTEXT = 334,                /* NARRTEXT  */
    ANUM = 335,                    /* ANUM  */
    ADEC = 336,                    /* ADEC  */
    ABOOL = 337,                   /* ABOOL  */
    ALET = 338,                    /* ALET  */
    ATEXT = 339,                   /* ATEXT  */
    AARRNUM = 340,                 /* AARRNUM  */
    AARRDEC = 341,                 /* AARRDEC  */
    AARRBOOL = 342,                /* AARRBOOL  */
    AARRLET = 343,                 /* AARRLET  */
    AARRTEXT = 344,                /* AARRTEXT  */
    TYPENAME = 345,                /* TYPENAME  */
    NUDATATYPE = 346,              /* NUDATATYPE  */
    AUDATATYPE = 347,              /* AUDATATYPE  */
    NARRUDATATYPE = 348,           /* NARRUDATATYPE  */
    AARRUDATATYPE = 349            /* AARRUDATATYPE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 45 "codegen.y"

       struct attribute
       {
           char *ID;          // Name of the variable
           bool is_atomic;    // Is the variable atomic?
           bool is_array;     // Is the datatype multidimensional?
           char *datatype;    // What is the datatype? (number/decimal/letter/text/bool)

           int intVal; // If encountered a integer constant, will store value here
           float decVal; // If encountered a decimal constant, will store value here
           char charVal; // If encountered a character constant, will store value here
           bool boolVal; // If encountered a boolean constant, will store value here
           char *stringVal; // If encountered a strin  g constant, will store value here
           char *token; // If encountered a token string like for/while, will store value here
           char *converted; // If the given code has C++ reserved keywords, the changed variable name will be stored here.
       }attr;

#line 176 "codegen.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CODEGEN_TAB_H_INCLUDED  */
