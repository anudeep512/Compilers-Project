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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    COMMA = 311,                   /* COMMA  */
    SEMICOLON = 312,               /* SEMICOLON  */
    COLON = 313,                   /* COLON  */
    PIPE = 314,                    /* PIPE  */
    IDENTIFIER = 315,              /* IDENTIFIER  */
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
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define WHEN 258
#define REPEAT 259
#define ELSE_WHEN 260
#define DEFAULT 261
#define FOR 262
#define BREAK 263
#define CONTINUE 264
#define TASK 265
#define MAKE_PARALLEL 266
#define NULL_ARGS 267
#define TID 268
#define ANALYZE 269
#define GET 270
#define SLEEP 271
#define TIME 272
#define START 273
#define RETURN 274
#define TYPE 275
#define ATOMIC 276
#define ARRAY 277
#define IN 278
#define FUNC 279
#define INVOKE 280
#define IP 281
#define OP 282
#define DIV 283
#define ADD 284
#define SUB 285
#define MUL 286
#define EXPONENT 287
#define MODULO 288
#define ARROW 289
#define EQ 290
#define INCR 291
#define DECR 292
#define ASSN_MODULO 293
#define ASSN_EXPONENT 294
#define ASSN_DIV 295
#define ASSN_MUL 296
#define AND 297
#define OR 298
#define GT 299
#define LT 300
#define GTEQ 301
#define LTEQ 302
#define NOT_EQ 303
#define NEG 304
#define EQUAL_TWO 305
#define INTEGERLITERAL 306
#define STRINGLITERAL 307
#define CHARACTERLITERAL 308
#define BOOLEANLITERAL 309
#define FLOATLITERAL 310
#define COMMA 311
#define SEMICOLON 312
#define COLON 313
#define PIPE 314
#define IDENTIFIER 315
#define SCOPEOPEN 316
#define SCOPECLOSE 317
#define ROUNDOPEN 318
#define ROUNDCLOSE 319
#define SQUAREOPEN 320
#define SQUARECLOSE 321
#define HASH 322
#define LEXERROR 323
#define NNUM 324
#define NDEC 325
#define NBOOL 326
#define NLET 327
#define NTEXT 328
#define NVOID 329
#define NARRNUM 330
#define NARRDEC 331
#define NARRBOOL 332
#define NARRLET 333
#define NARRTEXT 334
#define ANUM 335
#define ADEC 336
#define ABOOL 337
#define ALET 338
#define ATEXT 339
#define AARRNUM 340
#define AARRDEC 341
#define AARRBOOL 342
#define AARRLET 343
#define AARRTEXT 344
#define TYPENAME 345
#define NUDATATYPE 346
#define AUDATATYPE 347
#define NARRUDATATYPE 348
#define AARRUDATATYPE 349

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "bison.y"

       struct attribute
       {
           char *ID;          // Name of the variable
           char *_type;       // Type of the variable (Function/Task/Type/Normal)
           bool is_atomic;    // Is the variable atomic?
           bool is_array;     // Is the datatype multidimensional?
           char *datatype;    // What is the datatype? (number/decimal/letter/text/bool)

           int intVal; // If encountered a integer constant, will store value here
           float decVal; // If encountered a decimal constant, will store value here
           char charVal; // If encountered a character constant, will store value here
           bool boolVal; // If encountered a boolean constant, will store value here
           bool stringVal; // If encountered a string constant, will store value here
           char *token; // If encountered a token string like for/while, will store value here
       }attr;

#line 273 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
