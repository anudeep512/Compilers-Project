/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "bison.y"

  #include <iostream>
  #include <string>
  #include <fstream>
  #include <climits>
  #include "errors.hpp"
  #include "symbol_table.hpp"
  #include "semantics.hpp"   
  #include <string.h>
  extern int yylex();
  extern int yylineno;
  extern FILE * yyout, *fpcpp;
  void yyerror(std::string s);
  char * dt_state ;
  int array_state;
  int atomic_state;
  char * t_state ;
  char * curr_type ;
  std::vector<char *> arg_dat; // used during invokes, will be sent to searching funcs
  std::vector<char *> decl_arg_dat; // used at declarations, will be sent to adding functions
  std::vector<int> decl_arg_is_array ;
//   std::unordered_set<char *> types_set;
  MethodTable m_tb ;
  FunctionTable f_tb ;
  TaskTable t_tb ;
  VariableTable i_tb ;
  AttributeTable attr_tb ;
  TypeTable c_tb ;
  int scopeLevel = 0 ;
  int startCount = 0;

#line 103 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 362 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_WHEN = 3,                       /* WHEN  */
  YYSYMBOL_REPEAT = 4,                     /* REPEAT  */
  YYSYMBOL_ELSE_WHEN = 5,                  /* ELSE_WHEN  */
  YYSYMBOL_DEFAULT = 6,                    /* DEFAULT  */
  YYSYMBOL_FOR = 7,                        /* FOR  */
  YYSYMBOL_BREAK = 8,                      /* BREAK  */
  YYSYMBOL_CONTINUE = 9,                   /* CONTINUE  */
  YYSYMBOL_TASK = 10,                      /* TASK  */
  YYSYMBOL_MAKE_PARALLEL = 11,             /* MAKE_PARALLEL  */
  YYSYMBOL_NULL_ARGS = 12,                 /* NULL_ARGS  */
  YYSYMBOL_TID = 13,                       /* TID  */
  YYSYMBOL_ANALYZE = 14,                   /* ANALYZE  */
  YYSYMBOL_GET = 15,                       /* GET  */
  YYSYMBOL_SLEEP = 16,                     /* SLEEP  */
  YYSYMBOL_TIME = 17,                      /* TIME  */
  YYSYMBOL_START = 18,                     /* START  */
  YYSYMBOL_RETURN = 19,                    /* RETURN  */
  YYSYMBOL_TYPE = 20,                      /* TYPE  */
  YYSYMBOL_ATOMIC = 21,                    /* ATOMIC  */
  YYSYMBOL_ARRAY = 22,                     /* ARRAY  */
  YYSYMBOL_IN = 23,                        /* IN  */
  YYSYMBOL_FUNC = 24,                      /* FUNC  */
  YYSYMBOL_INVOKE = 25,                    /* INVOKE  */
  YYSYMBOL_IP = 26,                        /* IP  */
  YYSYMBOL_OP = 27,                        /* OP  */
  YYSYMBOL_DIV = 28,                       /* DIV  */
  YYSYMBOL_ADD = 29,                       /* ADD  */
  YYSYMBOL_SUB = 30,                       /* SUB  */
  YYSYMBOL_MUL = 31,                       /* MUL  */
  YYSYMBOL_EXPONENT = 32,                  /* EXPONENT  */
  YYSYMBOL_MODULO = 33,                    /* MODULO  */
  YYSYMBOL_ARROW = 34,                     /* ARROW  */
  YYSYMBOL_EQ = 35,                        /* EQ  */
  YYSYMBOL_INCR = 36,                      /* INCR  */
  YYSYMBOL_DECR = 37,                      /* DECR  */
  YYSYMBOL_ASSN_MODULO = 38,               /* ASSN_MODULO  */
  YYSYMBOL_ASSN_EXPONENT = 39,             /* ASSN_EXPONENT  */
  YYSYMBOL_ASSN_DIV = 40,                  /* ASSN_DIV  */
  YYSYMBOL_ASSN_MUL = 41,                  /* ASSN_MUL  */
  YYSYMBOL_AND = 42,                       /* AND  */
  YYSYMBOL_OR = 43,                        /* OR  */
  YYSYMBOL_GT = 44,                        /* GT  */
  YYSYMBOL_LT = 45,                        /* LT  */
  YYSYMBOL_GTEQ = 46,                      /* GTEQ  */
  YYSYMBOL_LTEQ = 47,                      /* LTEQ  */
  YYSYMBOL_NOT_EQ = 48,                    /* NOT_EQ  */
  YYSYMBOL_NEG = 49,                       /* NEG  */
  YYSYMBOL_EQUAL_TWO = 50,                 /* EQUAL_TWO  */
  YYSYMBOL_INTEGERLITERAL = 51,            /* INTEGERLITERAL  */
  YYSYMBOL_STRINGLITERAL = 52,             /* STRINGLITERAL  */
  YYSYMBOL_CHARACTERLITERAL = 53,          /* CHARACTERLITERAL  */
  YYSYMBOL_BOOLEANLITERAL = 54,            /* BOOLEANLITERAL  */
  YYSYMBOL_FLOATLITERAL = 55,              /* FLOATLITERAL  */
  YYSYMBOL_COMMA = 56,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 57,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 58,                     /* COLON  */
  YYSYMBOL_PIPE = 59,                      /* PIPE  */
  YYSYMBOL_IDENTIFIER = 60,                /* IDENTIFIER  */
  YYSYMBOL_SCOPEOPEN = 61,                 /* SCOPEOPEN  */
  YYSYMBOL_SCOPECLOSE = 62,                /* SCOPECLOSE  */
  YYSYMBOL_ROUNDOPEN = 63,                 /* ROUNDOPEN  */
  YYSYMBOL_ROUNDCLOSE = 64,                /* ROUNDCLOSE  */
  YYSYMBOL_SQUAREOPEN = 65,                /* SQUAREOPEN  */
  YYSYMBOL_SQUARECLOSE = 66,               /* SQUARECLOSE  */
  YYSYMBOL_HASH = 67,                      /* HASH  */
  YYSYMBOL_LEXERROR = 68,                  /* LEXERROR  */
  YYSYMBOL_NNUM = 69,                      /* NNUM  */
  YYSYMBOL_NDEC = 70,                      /* NDEC  */
  YYSYMBOL_NBOOL = 71,                     /* NBOOL  */
  YYSYMBOL_NLET = 72,                      /* NLET  */
  YYSYMBOL_NTEXT = 73,                     /* NTEXT  */
  YYSYMBOL_NVOID = 74,                     /* NVOID  */
  YYSYMBOL_NARRNUM = 75,                   /* NARRNUM  */
  YYSYMBOL_NARRDEC = 76,                   /* NARRDEC  */
  YYSYMBOL_NARRBOOL = 77,                  /* NARRBOOL  */
  YYSYMBOL_NARRLET = 78,                   /* NARRLET  */
  YYSYMBOL_NARRTEXT = 79,                  /* NARRTEXT  */
  YYSYMBOL_ANUM = 80,                      /* ANUM  */
  YYSYMBOL_ADEC = 81,                      /* ADEC  */
  YYSYMBOL_ABOOL = 82,                     /* ABOOL  */
  YYSYMBOL_ALET = 83,                      /* ALET  */
  YYSYMBOL_ATEXT = 84,                     /* ATEXT  */
  YYSYMBOL_AARRNUM = 85,                   /* AARRNUM  */
  YYSYMBOL_AARRDEC = 86,                   /* AARRDEC  */
  YYSYMBOL_AARRBOOL = 87,                  /* AARRBOOL  */
  YYSYMBOL_AARRLET = 88,                   /* AARRLET  */
  YYSYMBOL_AARRTEXT = 89,                  /* AARRTEXT  */
  YYSYMBOL_TYPENAME = 90,                  /* TYPENAME  */
  YYSYMBOL_NUDATATYPE = 91,                /* NUDATATYPE  */
  YYSYMBOL_AUDATATYPE = 92,                /* AUDATATYPE  */
  YYSYMBOL_NARRUDATATYPE = 93,             /* NARRUDATATYPE  */
  YYSYMBOL_AARRUDATATYPE = 94,             /* AARRUDATATYPE  */
  YYSYMBOL_YYACCEPT = 95,                  /* $accept  */
  YYSYMBOL_all_datatypes = 96,             /* all_datatypes  */
  YYSYMBOL_expression_op = 97,             /* expression_op  */
  YYSYMBOL_comparison_op = 98,             /* comparison_op  */
  YYSYMBOL_arithmetic_op = 99,             /* arithmetic_op  */
  YYSYMBOL_logical_op = 100,               /* logical_op  */
  YYSYMBOL_nonAtomic_datatypes = 101,      /* nonAtomic_datatypes  */
  YYSYMBOL_begin = 102,                    /* begin  */
  YYSYMBOL_E = 103,                        /* E  */
  YYSYMBOL_104_1 = 104,                    /* $@1  */
  YYSYMBOL_T = 105,                        /* T  */
  YYSYMBOL_106_2 = 106,                    /* $@2  */
  YYSYMBOL_all_ops = 107,                  /* all_ops  */
  YYSYMBOL_constants = 108,                /* constants  */
  YYSYMBOL_next = 109,                     /* next  */
  YYSYMBOL_RHS = 110,                      /* RHS  */
  YYSYMBOL_111_3 = 111,                    /* $@3  */
  YYSYMBOL_112_4 = 112,                    /* $@4  */
  YYSYMBOL_113_5 = 113,                    /* $@5  */
  YYSYMBOL_114_6 = 114,                    /* $@6  */
  YYSYMBOL_nonAtomicSimple = 115,          /* nonAtomicSimple  */
  YYSYMBOL_atomicSimple = 116,             /* atomicSimple  */
  YYSYMBOL_nonAtomicArray = 117,           /* nonAtomicArray  */
  YYSYMBOL_atomicArray = 118,              /* atomicArray  */
  YYSYMBOL_errorDatatypes = 119,           /* errorDatatypes  */
  YYSYMBOL_declaration = 120,              /* declaration  */
  YYSYMBOL_simpleDatatype = 121,           /* simpleDatatype  */
  YYSYMBOL_arrayDatatype = 122,            /* arrayDatatype  */
  YYSYMBOL_declarationStmt = 123,          /* declarationStmt  */
  YYSYMBOL_124_7 = 124,                    /* $@7  */
  YYSYMBOL_125_8 = 125,                    /* $@8  */
  YYSYMBOL_simpleList = 126,               /* simpleList  */
  YYSYMBOL_127_9 = 127,                    /* $@9  */
  YYSYMBOL_128_10 = 128,                   /* $@10  */
  YYSYMBOL_129_11 = 129,                   /* $@11  */
  YYSYMBOL_130_12 = 130,                   /* $@12  */
  YYSYMBOL_131_13 = 131,                   /* $@13  */
  YYSYMBOL_132_14 = 132,                   /* $@14  */
  YYSYMBOL_arrayList = 133,                /* arrayList  */
  YYSYMBOL_134_15 = 134,                   /* $@15  */
  YYSYMBOL_135_16 = 135,                   /* $@16  */
  YYSYMBOL_136_17 = 136,                   /* $@17  */
  YYSYMBOL_137_18 = 137,                   /* $@18  */
  YYSYMBOL_138_19 = 138,                   /* $@19  */
  YYSYMBOL_139_20 = 139,                   /* $@20  */
  YYSYMBOL_140_21 = 140,                   /* $@21  */
  YYSYMBOL_141_22 = 141,                   /* $@22  */
  YYSYMBOL_142_23 = 142,                   /* $@23  */
  YYSYMBOL_143_24 = 143,                   /* $@24  */
  YYSYMBOL_144_25 = 144,                   /* $@25  */
  YYSYMBOL_145_26 = 145,                   /* $@26  */
  YYSYMBOL_146_27 = 146,                   /* $@27  */
  YYSYMBOL_147_28 = 147,                   /* $@28  */
  YYSYMBOL_array_inValues = 148,           /* array_inValues  */
  YYSYMBOL_dimlist = 149,                  /* dimlist  */
  YYSYMBOL_150_29 = 150,                   /* $@29  */
  YYSYMBOL_LHS = 151,                      /* LHS  */
  YYSYMBOL_152_30 = 152,                   /* $@30  */
  YYSYMBOL_153_31 = 153,                   /* $@31  */
  YYSYMBOL_arr_access = 154,               /* arr_access  */
  YYSYMBOL_exprlist = 155,                 /* exprlist  */
  YYSYMBOL_156_32 = 156,                   /* $@32  */
  YYSYMBOL_arith_operand = 157,            /* arith_operand  */
  YYSYMBOL_158_33 = 158,                   /* $@33  */
  YYSYMBOL_arith_expr = 159,               /* arith_expr  */
  YYSYMBOL_assignment_statement = 160,     /* assignment_statement  */
  YYSYMBOL_161_34 = 161,                   /* $@34  */
  YYSYMBOL_expression_statement = 162,     /* expression_statement  */
  YYSYMBOL_exprrr = 163,                   /* exprrr  */
  YYSYMBOL_164_35 = 164,                   /* $@35  */
  YYSYMBOL_log = 165,                      /* log  */
  YYSYMBOL_g = 166,                        /* g  */
  YYSYMBOL_167_36 = 167,                   /* $@36  */
  YYSYMBOL_168_37 = 168,                   /* $@37  */
  YYSYMBOL_169_38 = 169,                   /* $@38  */
  YYSYMBOL_170_39 = 170,                   /* $@39  */
  YYSYMBOL_171_40 = 171,                   /* $@40  */
  YYSYMBOL_both_assignment = 172,          /* both_assignment  */
  YYSYMBOL_173_41 = 173,                   /* $@41  */
  YYSYMBOL_174_42 = 174,                   /* $@42  */
  YYSYMBOL_loop = 175,                     /* loop  */
  YYSYMBOL_for_loop = 176,                 /* for_loop  */
  YYSYMBOL_177_43 = 177,                   /* $@43  */
  YYSYMBOL_178_44 = 178,                   /* $@44  */
  YYSYMBOL_179_45 = 179,                   /* $@45  */
  YYSYMBOL_180_46 = 180,                   /* $@46  */
  YYSYMBOL_181_47 = 181,                   /* $@47  */
  YYSYMBOL_182_48 = 182,                   /* $@48  */
  YYSYMBOL_183_49 = 183,                   /* $@49  */
  YYSYMBOL_while_loop = 184,               /* while_loop  */
  YYSYMBOL_185_50 = 185,                   /* $@50  */
  YYSYMBOL_186_51 = 186,                   /* $@51  */
  YYSYMBOL_187_52 = 187,                   /* $@52  */
  YYSYMBOL_188_53 = 188,                   /* $@53  */
  YYSYMBOL_189_54 = 189,                   /* $@54  */
  YYSYMBOL_conditional = 190,              /* conditional  */
  YYSYMBOL_when_statement = 191,           /* when_statement  */
  YYSYMBOL_192_55 = 192,                   /* $@55  */
  YYSYMBOL_193_56 = 193,                   /* $@56  */
  YYSYMBOL_194_57 = 194,                   /* $@57  */
  YYSYMBOL_195_58 = 195,                   /* $@58  */
  YYSYMBOL_196_59 = 196,                   /* $@59  */
  YYSYMBOL_197_60 = 197,                   /* $@60  */
  YYSYMBOL_extend = 198,                   /* extend  */
  YYSYMBOL_199_61 = 199,                   /* $@61  */
  YYSYMBOL_200_62 = 200,                   /* $@62  */
  YYSYMBOL_201_63 = 201,                   /* $@63  */
  YYSYMBOL_202_64 = 202,                   /* $@64  */
  YYSYMBOL_203_65 = 203,                   /* $@65  */
  YYSYMBOL_204_66 = 204,                   /* $@66  */
  YYSYMBOL_205_67 = 205,                   /* $@67  */
  YYSYMBOL_206_68 = 206,                   /* $@68  */
  YYSYMBOL_207_69 = 207,                   /* $@69  */
  YYSYMBOL_analysis_arrays = 208,          /* analysis_arrays  */
  YYSYMBOL_analyze_label = 209,            /* analyze_label  */
  YYSYMBOL_analyze_statement = 210,        /* analyze_statement  */
  YYSYMBOL_211_70 = 211,                   /* $@70  */
  YYSYMBOL_analyze_syntax = 212,           /* analyze_syntax  */
  YYSYMBOL_func_invoke2 = 213,             /* func_invoke2  */
  YYSYMBOL_func_invoke = 214,              /* func_invoke  */
  YYSYMBOL_215_71 = 215,                   /* $@71  */
  YYSYMBOL_216_72 = 216,                   /* $@72  */
  YYSYMBOL_217_73 = 217,                   /* $@73  */
  YYSYMBOL_218_74 = 218,                   /* $@74  */
  YYSYMBOL_219_75 = 219,                   /* $@75  */
  YYSYMBOL_220_76 = 220,                   /* $@76  */
  YYSYMBOL_arguments = 221,                /* arguments  */
  YYSYMBOL_222_77 = 222,                   /* $@77  */
  YYSYMBOL_task_invoke = 223,              /* task_invoke  */
  YYSYMBOL_224_78 = 224,                   /* $@78  */
  YYSYMBOL_get_invoke = 225,               /* get_invoke  */
  YYSYMBOL_sleep = 226,                    /* sleep  */
  YYSYMBOL_227_79 = 227,                   /* $@79  */
  YYSYMBOL_228_80 = 228,                   /* $@80  */
  YYSYMBOL_229_81 = 229,                   /* $@81  */
  YYSYMBOL_230_82 = 230,                   /* $@82  */
  YYSYMBOL_231_83 = 231,                   /* $@83  */
  YYSYMBOL_232_84 = 232,                   /* $@84  */
  YYSYMBOL_233_85 = 233,                   /* $@85  */
  YYSYMBOL_234_86 = 234,                   /* $@86  */
  YYSYMBOL_file_name = 235,                /* file_name  */
  YYSYMBOL_236_87 = 236,                   /* $@87  */
  YYSYMBOL_237_88 = 237,                   /* $@88  */
  YYSYMBOL_input = 238,                    /* input  */
  YYSYMBOL_nextip = 239,                   /* nextip  */
  YYSYMBOL_240_89 = 240,                   /* $@89  */
  YYSYMBOL_241_90 = 241,                   /* $@90  */
  YYSYMBOL_stringvalues = 242,             /* stringvalues  */
  YYSYMBOL_return_statement = 243,         /* return_statement  */
  YYSYMBOL_244_91 = 244,                   /* $@91  */
  YYSYMBOL_245_92 = 245,                   /* $@92  */
  YYSYMBOL_output = 246,                   /* output  */
  YYSYMBOL_opstring = 247,                 /* opstring  */
  YYSYMBOL_nextop = 248,                   /* nextop  */
  YYSYMBOL_function = 249,                 /* function  */
  YYSYMBOL_func_args = 250,                /* func_args  */
  YYSYMBOL_251_93 = 251,                   /* $@93  */
  YYSYMBOL_252_94 = 252,                   /* $@94  */
  YYSYMBOL_253_95 = 253,                   /* $@95  */
  YYSYMBOL_args = 254,                     /* args  */
  YYSYMBOL_func_return = 255,              /* func_return  */
  YYSYMBOL_func_decl = 256,                /* func_decl  */
  YYSYMBOL_257_96 = 257,                   /* $@96  */
  YYSYMBOL_258_97 = 258,                   /* $@97  */
  YYSYMBOL_259_98 = 259,                   /* $@98  */
  YYSYMBOL_atomic_func_decl = 260,         /* atomic_func_decl  */
  YYSYMBOL_261_99 = 261,                   /* $@99  */
  YYSYMBOL_262_100 = 262,                  /* $@100  */
  YYSYMBOL_263_101 = 263,                  /* $@101  */
  YYSYMBOL_func_body = 264,                /* func_body  */
  YYSYMBOL_265_102 = 265,                  /* $@102  */
  YYSYMBOL_266_103 = 266,                  /* $@103  */
  YYSYMBOL_func_scope = 267,               /* func_scope  */
  YYSYMBOL_268_104 = 268,                  /* $@104  */
  YYSYMBOL_269_105 = 269,                  /* $@105  */
  YYSYMBOL_func_statements = 270,          /* func_statements  */
  YYSYMBOL_task = 271,                     /* task  */
  YYSYMBOL_272_106 = 272,                  /* $@106  */
  YYSYMBOL_273_107 = 273,                  /* $@107  */
  YYSYMBOL_274_108 = 274,                  /* $@108  */
  YYSYMBOL_275_109 = 275,                  /* $@109  */
  YYSYMBOL_276_110 = 276,                  /* $@110  */
  YYSYMBOL_277_111 = 277,                  /* $@111  */
  YYSYMBOL_taskscope = 278,                /* taskscope  */
  YYSYMBOL_279_112 = 279,                  /* $@112  */
  YYSYMBOL_280_113 = 280,                  /* $@113  */
  YYSYMBOL_281_114 = 281,                  /* $@114  */
  YYSYMBOL_statement = 282,                /* statement  */
  YYSYMBOL_283_115 = 283,                  /* $@115  */
  YYSYMBOL_284_116 = 284,                  /* $@116  */
  YYSYMBOL_statements = 285,               /* statements  */
  YYSYMBOL_access = 286,                   /* access  */
  YYSYMBOL_287_117 = 287,                  /* $@117  */
  YYSYMBOL_288_118 = 288,                  /* $@118  */
  YYSYMBOL_id = 289,                       /* id  */
  YYSYMBOL_290_119 = 290,                  /* $@119  */
  YYSYMBOL_291_120 = 291,                  /* $@120  */
  YYSYMBOL_292_121 = 292,                  /* $@121  */
  YYSYMBOL_startdec = 293,                 /* startdec  */
  YYSYMBOL_294_122 = 294,                  /* $@122  */
  YYSYMBOL_295_123 = 295,                  /* $@123  */
  YYSYMBOL_296_124 = 296,                  /* $@124  */
  YYSYMBOL_start = 297,                    /* start  */
  YYSYMBOL_298_125 = 298,                  /* $@125  */
  YYSYMBOL_299_126 = 299,                  /* $@126  */
  YYSYMBOL_300_127 = 300,                  /* $@127  */
  YYSYMBOL_type_declaration = 301,         /* type_declaration  */
  YYSYMBOL_302_128 = 302,                  /* $@128  */
  YYSYMBOL_303_129 = 303,                  /* $@129  */
  YYSYMBOL_304_130 = 304,                  /* $@130  */
  YYSYMBOL_305_131 = 305,                  /* $@131  */
  YYSYMBOL_type_scope = 306,               /* type_scope  */
  YYSYMBOL_declaration_t = 307,            /* declaration_t  */
  YYSYMBOL_308_132 = 308,                  /* $@132  */
  YYSYMBOL_declarationStmt_t = 309,        /* declarationStmt_t  */
  YYSYMBOL_simpleList_t = 310,             /* simpleList_t  */
  YYSYMBOL_311_133 = 311,                  /* $@133  */
  YYSYMBOL_312_134 = 312,                  /* $@134  */
  YYSYMBOL_313_135 = 313,                  /* $@135  */
  YYSYMBOL_314_136 = 314,                  /* $@136  */
  YYSYMBOL_315_137 = 315,                  /* $@137  */
  YYSYMBOL_316_138 = 316,                  /* $@138  */
  YYSYMBOL_317_139 = 317,                  /* $@139  */
  YYSYMBOL_318_140 = 318,                  /* $@140  */
  YYSYMBOL_arrayList_t = 319,              /* arrayList_t  */
  YYSYMBOL_320_141 = 320,                  /* $@141  */
  YYSYMBOL_321_142 = 321,                  /* $@142  */
  YYSYMBOL_322_143 = 322,                  /* $@143  */
  YYSYMBOL_323_144 = 323,                  /* $@144  */
  YYSYMBOL_324_145 = 324,                  /* $@145  */
  YYSYMBOL_325_146 = 325,                  /* $@146  */
  YYSYMBOL_326_147 = 326,                  /* $@147  */
  YYSYMBOL_327_148 = 327,                  /* $@148  */
  YYSYMBOL_328_149 = 328,                  /* $@149  */
  YYSYMBOL_329_150 = 329,                  /* $@150  */
  YYSYMBOL_330_151 = 330,                  /* $@151  */
  YYSYMBOL_331_152 = 331,                  /* $@152  */
  YYSYMBOL_332_153 = 332,                  /* $@153  */
  YYSYMBOL_333_154 = 333,                  /* $@154  */
  YYSYMBOL_334_155 = 334,                  /* $@155  */
  YYSYMBOL_335_156 = 335,                  /* $@156  */
  YYSYMBOL_methods = 336,                  /* methods  */
  YYSYMBOL_method = 337,                   /* method  */
  YYSYMBOL_338_157 = 338,                  /* $@157  */
  YYSYMBOL_339_158 = 339,                  /* $@158  */
  YYSYMBOL_func_decl_m = 340,              /* func_decl_m  */
  YYSYMBOL_341_159 = 341,                  /* $@159  */
  YYSYMBOL_342_160 = 342,                  /* $@160  */
  YYSYMBOL_343_161 = 343,                  /* $@161  */
  YYSYMBOL_method_invoke2 = 344,           /* method_invoke2  */
  YYSYMBOL_method_args = 345,              /* method_args  */
  YYSYMBOL_method_invoke = 346,            /* method_invoke  */
  YYSYMBOL_347_162 = 347,                  /* $@162  */
  YYSYMBOL_348_163 = 348,                  /* $@163  */
  YYSYMBOL_349_164 = 349,                  /* $@164  */
  YYSYMBOL_350_165 = 350,                  /* $@165  */
  YYSYMBOL_in_stmt = 351,                  /* in_stmt  */
  YYSYMBOL_352_166 = 352,                  /* $@166  */
  YYSYMBOL_353_167 = 353,                  /* $@167  */
  YYSYMBOL_354_168 = 354,                  /* $@168  */
  YYSYMBOL_355_169 = 355,                  /* $@169  */
  YYSYMBOL_356_170 = 356,                  /* $@170  */
  YYSYMBOL_357_171 = 357,                  /* $@171  */
  YYSYMBOL_358_172 = 358,                  /* $@172  */
  YYSYMBOL_359_173 = 359,                  /* $@173  */
  YYSYMBOL_360_174 = 360,                  /* $@174  */
  YYSYMBOL_361_175 = 361,                  /* $@175  */
  YYSYMBOL_362_176 = 362,                  /* $@176  */
  YYSYMBOL_363_177 = 363,                  /* $@177  */
  YYSYMBOL_364_178 = 364,                  /* $@178  */
  YYSYMBOL_method_statements = 365,        /* method_statements  */
  YYSYMBOL_366_179 = 366,                  /* $@179  */
  YYSYMBOL_367_180 = 367,                  /* $@180  */
  YYSYMBOL_return_statement_m = 368,       /* return_statement_m  */
  YYSYMBOL_369_181 = 369,                  /* $@181  */
  YYSYMBOL_370_182 = 370,                  /* $@182  */
  YYSYMBOL_371_183 = 371,                  /* $@183  */
  YYSYMBOL_372_184 = 372,                  /* $@184  */
  YYSYMBOL_method_body = 373               /* method_body  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  56
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1546

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  279
/* YYNRULES -- Number of rules.  */
#define YYNRULES  482
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  757

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   349


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    98,    98,   104,   110,   116,   122,   128,   134,   140,
     146,   152,   158,   164,   170,   176,   182,   188,   196,   196,
     196,   196,   196,   196,   197,   197,   197,   197,   197,   197,
     198,   198,   198,   198,   198,   198,   199,   199,   200,   200,
     203,   208,   209,   210,   211,   212,   218,   219,   219,   222,
     222,   223,   226,   227,   228,   229,   230,   233,   240,   247,
     254,   261,   270,   271,   274,   275,   276,   277,   277,   277,
     278,   278,   279,   279,   280,   280,   280,   284,   290,   296,
     302,   308,   314,   322,   328,   334,   340,   346,   354,   360,
     366,   372,   378,   386,   392,   398,   404,   410,   420,   420,
     420,   420,   422,   423,   430,   436,   442,   449,   457,   463,
     470,   477,   486,   485,   493,   492,   500,   514,   514,   530,
     530,   530,   550,   550,   550,   550,   570,   570,   570,   588,
     588,   588,   588,   608,   608,   608,   608,   608,   628,   628,
     628,   628,   628,   628,   647,   648,   651,   651,   652,   655,
     665,   665,   665,   676,   684,   687,   688,   688,   691,   692,
     693,   694,   694,   697,   698,   702,   702,   712,   720,   721,
     721,   725,   726,   729,   729,   729,   742,   742,   742,   742,
     757,   763,   763,   764,   764,   777,   777,   780,   780,   780,
     780,   780,   780,   781,   780,   797,   797,   797,   797,   798,
     797,   816,   819,   819,   819,   819,   820,   823,   819,   827,
     827,   827,   827,   828,   831,   827,   834,   834,   835,   834,
     839,   853,   853,   853,   853,   861,   861,   868,   868,   875,
     876,   886,   889,   889,   889,   889,   897,   897,   897,   897,
     907,   907,   911,   919,   919,   927,   931,   934,   934,   934,
     934,   934,   935,   935,   935,   935,   935,   938,   938,   939,
     939,   940,   943,   947,   947,   948,   948,   954,   955,   959,
     959,   960,   960,   963,   969,   972,   973,   979,   980,   983,
     983,   989,   989,   989,   997,   998,  1001,  1007,  1013,  1016,
    1016,  1016,  1016,  1032,  1032,  1032,  1032,  1048,  1049,  1048,
    1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1063,
    1063,  1064,  1065,  1064,  1069,  1072,  1073,  1077,  1077,  1077,
    1077,  1077,  1078,  1077,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1094,  1090,  1095,  1096,  1097,  1101,  1102,  1103,
    1104,  1105,  1106,  1107,  1108,  1109,  1110,  1109,  1114,  1115,
    1116,  1117,  1118,  1119,  1122,  1123,  1127,  1127,  1127,  1134,
    1134,  1139,  1139,  1139,  1154,  1163,  1164,  1154,  1170,  1171,
    1172,  1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1183,
    1179,  1184,  1185,  1186,  1191,  1192,  1202,  1203,  1191,  1210,
    1210,  1212,  1212,  1218,  1224,  1232,  1232,  1249,  1249,  1249,
    1265,  1265,  1265,  1283,  1283,  1283,  1283,  1303,  1303,  1303,
    1303,  1320,  1320,  1320,  1320,  1320,  1338,  1338,  1338,  1338,
    1338,  1356,  1356,  1356,  1356,  1356,  1356,  1375,  1376,  1379,
    1380,  1379,  1385,  1385,  1385,  1385,  1396,  1398,  1398,  1400,
    1400,  1400,  1400,  1400,  1422,  1422,  1422,  1422,  1428,  1428,
    1428,  1428,  1428,  1428,  1435,  1435,  1435,  1435,  1435,  1435,
    1444,  1445,  1446,  1447,  1448,  1449,  1450,  1451,  1452,  1453,
    1454,  1455,  1456,  1455,  1460,  1463,  1463,  1463,  1475,  1475,
    1475,  1488,  1489
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "WHEN", "REPEAT",
  "ELSE_WHEN", "DEFAULT", "FOR", "BREAK", "CONTINUE", "TASK",
  "MAKE_PARALLEL", "NULL_ARGS", "TID", "ANALYZE", "GET", "SLEEP", "TIME",
  "START", "RETURN", "TYPE", "ATOMIC", "ARRAY", "IN", "FUNC", "INVOKE",
  "IP", "OP", "DIV", "ADD", "SUB", "MUL", "EXPONENT", "MODULO", "ARROW",
  "EQ", "INCR", "DECR", "ASSN_MODULO", "ASSN_EXPONENT", "ASSN_DIV",
  "ASSN_MUL", "AND", "OR", "GT", "LT", "GTEQ", "LTEQ", "NOT_EQ", "NEG",
  "EQUAL_TWO", "INTEGERLITERAL", "STRINGLITERAL", "CHARACTERLITERAL",
  "BOOLEANLITERAL", "FLOATLITERAL", "COMMA", "SEMICOLON", "COLON", "PIPE",
  "IDENTIFIER", "SCOPEOPEN", "SCOPECLOSE", "ROUNDOPEN", "ROUNDCLOSE",
  "SQUAREOPEN", "SQUARECLOSE", "HASH", "LEXERROR", "NNUM", "NDEC", "NBOOL",
  "NLET", "NTEXT", "NVOID", "NARRNUM", "NARRDEC", "NARRBOOL", "NARRLET",
  "NARRTEXT", "ANUM", "ADEC", "ABOOL", "ALET", "ATEXT", "AARRNUM",
  "AARRDEC", "AARRBOOL", "AARRLET", "AARRTEXT", "TYPENAME", "NUDATATYPE",
  "AUDATATYPE", "NARRUDATATYPE", "AARRUDATATYPE", "$accept",
  "all_datatypes", "expression_op", "comparison_op", "arithmetic_op",
  "logical_op", "nonAtomic_datatypes", "begin", "E", "$@1", "T", "$@2",
  "all_ops", "constants", "next", "RHS", "$@3", "$@4", "$@5", "$@6",
  "nonAtomicSimple", "atomicSimple", "nonAtomicArray", "atomicArray",
  "errorDatatypes", "declaration", "simpleDatatype", "arrayDatatype",
  "declarationStmt", "$@7", "$@8", "simpleList", "$@9", "$@10", "$@11",
  "$@12", "$@13", "$@14", "arrayList", "$@15", "$@16", "$@17", "$@18",
  "$@19", "$@20", "$@21", "$@22", "$@23", "$@24", "$@25", "$@26", "$@27",
  "$@28", "array_inValues", "dimlist", "$@29", "LHS", "$@30", "$@31",
  "arr_access", "exprlist", "$@32", "arith_operand", "$@33", "arith_expr",
  "assignment_statement", "$@34", "expression_statement", "exprrr", "$@35",
  "log", "g", "$@36", "$@37", "$@38", "$@39", "$@40", "both_assignment",
  "$@41", "$@42", "loop", "for_loop", "$@43", "$@44", "$@45", "$@46",
  "$@47", "$@48", "$@49", "while_loop", "$@50", "$@51", "$@52", "$@53",
  "$@54", "conditional", "when_statement", "$@55", "$@56", "$@57", "$@58",
  "$@59", "$@60", "extend", "$@61", "$@62", "$@63", "$@64", "$@65", "$@66",
  "$@67", "$@68", "$@69", "analysis_arrays", "analyze_label",
  "analyze_statement", "$@70", "analyze_syntax", "func_invoke2",
  "func_invoke", "$@71", "$@72", "$@73", "$@74", "$@75", "$@76",
  "arguments", "$@77", "task_invoke", "$@78", "get_invoke", "sleep",
  "$@79", "$@80", "$@81", "$@82", "$@83", "$@84", "$@85", "$@86",
  "file_name", "$@87", "$@88", "input", "nextip", "$@89", "$@90",
  "stringvalues", "return_statement", "$@91", "$@92", "output", "opstring",
  "nextop", "function", "func_args", "$@93", "$@94", "$@95", "args",
  "func_return", "func_decl", "$@96", "$@97", "$@98", "atomic_func_decl",
  "$@99", "$@100", "$@101", "func_body", "$@102", "$@103", "func_scope",
  "$@104", "$@105", "func_statements", "task", "$@106", "$@107", "$@108",
  "$@109", "$@110", "$@111", "taskscope", "$@112", "$@113", "$@114",
  "statement", "$@115", "$@116", "statements", "access", "$@117", "$@118",
  "id", "$@119", "$@120", "$@121", "startdec", "$@122", "$@123", "$@124",
  "start", "$@125", "$@126", "$@127", "type_declaration", "$@128", "$@129",
  "$@130", "$@131", "type_scope", "declaration_t", "$@132",
  "declarationStmt_t", "simpleList_t", "$@133", "$@134", "$@135", "$@136",
  "$@137", "$@138", "$@139", "$@140", "arrayList_t", "$@141", "$@142",
  "$@143", "$@144", "$@145", "$@146", "$@147", "$@148", "$@149", "$@150",
  "$@151", "$@152", "$@153", "$@154", "$@155", "$@156", "methods",
  "method", "$@157", "$@158", "func_decl_m", "$@159", "$@160", "$@161",
  "method_invoke2", "method_args", "method_invoke", "$@162", "$@163",
  "$@164", "$@165", "in_stmt", "$@166", "$@167", "$@168", "$@169", "$@170",
  "$@171", "$@172", "$@173", "$@174", "$@175", "$@176", "$@177", "$@178",
  "method_statements", "$@179", "$@180", "return_statement_m", "$@181",
  "$@182", "$@183", "$@184", "method_body", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-626)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-479)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1455,  -626,  -626,  -626,    15,   -14,   -11,  -626,  -626,  -626,
    -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,
    -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,
      95,  -626,  -626,  -626,  -626,    12,  1455,  -626,  -626,    57,
    1455,    81,    81,  1455,  1455,  1455,   107,   111,    68,   -27,
     115,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,   116,
     118,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,
    -626,  -626,  -626,  -626,  -626,   110,   146,   126,  -626,   128,
    1304,   130,  1425,   125,   131,  -626,   156,  -626,   129,   132,
    -626,  -626,  -626,  -626,   133,    -4,  -626,   121,    33,   136,
     169,   147,     4,  -626,  -626,   377,   150,   151,  -626,  -626,
    -626,  -626,  -626,  -626,  -626,  -626,   152,  -626,  -626,  -626,
    -626,  -626,  1304,  -626,  -626,  -626,   153,  -626,  -626,  1425,
    1425,  1425,  1425,  1425,  1425,  1425,  1425,  1425,  1425,  -626,
    1425,  -626,  -626,   239,  -626,   144,   154,  -626,  -626,   188,
     190,   148,   187,   189,   195,  -626,  -626,   197,   194,   198,
     348,   142,   177,   224,   203,   206,    99,   201,   235,  1304,
    -626,  -626,  -626,  -626,  -626,  -626,  -626,   348,  -626,  -626,
    -626,  -626,   208,  -626,   239,  1425,  -626,  -626,  -626,  -626,
    -626,  -626,  -626,  -626,  -626,  -626,   210,  -626,  1183,   239,
    -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,
    -626,  -626,  -626,  -626,  -626,   213,  -626,  -626,   225,   222,
     348,  -626,  -626,    61,    61,  -626,  -626,  -626,  -626,  -626,
      89,    -4,  -626,  -626,  -626,   248,  -626,    11,  -626,  -626,
    -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,   227,  -626,
    -626,  -626,  -626,   233,   234,   236,  -626,  -626,   243,   247,
     269,  -626,  -626,   232,   169,  -626,  -626,  -626,   348,  -626,
    -626,  -626,  -626,  -626,    10,   241,   276,   277,  -626,  1183,
     281,   283,  -626,  -626,  -626,  -626,   308,  -626,  -626,  -626,
     -15,    -6,   286,   288,   348,   348,   205,  -626,  -626,  -626,
    -626,  -626,    98,   297,   301,   306,   341,   325,  -626,   299,
     303,   348,   348,  -626,  -626,  -626,  -626,   304,   309,  -626,
    -626,    -3,    99,  -626,   313,    89,   312,   315,  -626,   322,
     324,   272,    24,   328,  -626,  -626,   332,  -626,   365,  -626,
    -626,  -626,  -626,  1089,  1035,  -626,  -626,  -626,  -626,  -626,
    -626,   326,   338,   302,     1,  -626,  -626,   356,  -626,   334,
      89,  -626,  -626,  -626,  -626,  -626,  -626,    89,    89,    34,
    -626,  -626,  -626,  -626,   371,   375,  -626,  -626,  -626,   969,
     346,   348,   407,  -626,  -626,   361,  -626,  -626,   232,  -626,
     358,   366,   400,  -626,   391,  -626,  -626,  -626,  -626,   399,
    -626,   370,   373,  -626,   379,   364,  -626,   380,  -626,  1035,
     398,  -626,  -626,  -626,  -626,  -626,  -626,   348,    61,   405,
      61,    61,  -626,  -626,   401,   404,  -626,   192,   316,  -626,
    -626,  -626,  -626,  -626,   408,   403,   406,   411,  -626,  -626,
     348,    89,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,
    -626,  -626,  -626,  -626,  -626,   348,  -626,  -626,   409,   414,
    -626,   415,  -626,  -626,  -626,  -626,  -626,  -626,   158,  1425,
    -626,   416,   418,  -626,  -626,   419,   420,  -626,  -626,  -626,
    -626,  -626,  -626,  -626,  -626,    50,    67,   422,   423,   417,
    -626,   429,   348,  -626,   327,    34,  -626,  -626,  -626,   426,
     430,   425,   427,   428,   969,  -626,  -626,  -626,  -626,    -3,
      89,  -626,   158,   158,   158,   158,   158,   158,   158,  -626,
     158,  -626,   348,  -626,  -626,    61,    61,  -626,  -626,   436,
    1336,  -626,   348,  -626,  -626,  -626,  -626,  -626,   440,  -626,
     437,   447,    59,   448,   438,   450,  -626,  -626,  -626,  -626,
    -626,  -626,   348,   348,  -626,   895,  -626,   400,   158,  -626,
    -626,  -626,  -626,  -626,  -626,  -626,   449,  -626,  -626,  -626,
     475,    80,    91,   456,   457,  -626,   452,  -626,  -626,  -626,
    -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  1336,
    -626,  -626,  -626,   488,  1215,  1215,  -626,   467,  -626,   472,
     474,    34,   485,  -626,  -626,   486,   487,  -626,  -626,  -626,
     409,   489,  -626,  -626,  -626,  -626,  -626,  -626,  -626,   239,
     348,   476,  1336,  -626,   492,  -626,   491,   499,  -626,  -626,
    -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,
    1215,  -626,  -626,  -626,   348,  -626,    37,  -626,  -626,   448,
    -626,  -626,  -626,  -626,   495,   348,  -626,   514,    61,    61,
     501,   503,   505,  -626,  -626,   348,  -626,  -626,  1215,  -626,
     504,   506,  -626,   528,  -626,   463,  -626,   507,  -626,  -626,
    -626,   348,   553,  -626,  -626,  -626,  -626,    94,    97,  -626,
    -626,  -626,   509,  -626,  -626,  -626,  -626,  -626,   401,  -626,
     108,   511,   158,   348,  -626,  -626,  1035,  -626,  -626,  -626,
     510,    72,   348,   512,   513,  -626,  -626,  -626,  -626,  -626,
     532,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,
    -626,  -626,   515,   516,  1215,   348,  -626,  -626,  -626,  -626,
     348,  1215,   520,   518,  -626,  -626,  -626,   523,   525,  -626,
    -626,  1215,  -626,   526,  -626,    72,  -626
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
      40,   317,   364,   384,     0,     0,     0,    98,    77,    78,
      79,    80,    81,    82,    88,    89,    90,    91,    92,    83,
      84,    85,    86,    87,    93,    94,    95,    96,    97,   106,
       0,   104,   105,   108,   109,     0,    40,   112,   114,     0,
      40,     0,     0,    40,    40,    40,     0,     0,     0,     0,
       0,    99,   107,   100,   110,   289,     1,   103,    42,     0,
       0,   102,    43,   297,   277,   278,    44,    41,    45,   318,
     365,   385,   101,   111,   293,     0,   116,   113,   126,   115,
     316,     0,   383,     0,     0,   290,     0,   117,     0,     0,
     129,   202,   195,   187,     0,     0,   247,   269,     0,     0,
     261,     0,   149,   311,   300,     0,     0,     0,   301,   304,
     185,   186,   306,   201,   307,   303,     0,   302,   310,   308,
     305,   309,   316,   298,   153,   314,     0,   319,   377,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   366,
     383,   386,   294,     0,   120,     0,     0,   127,   134,     0,
       0,     0,     0,     0,     0,   225,   226,     0,     0,     0,
       0,     0,   232,     0,   257,     0,     0,     0,     0,   316,
     165,    22,    23,    20,    19,    18,    21,     0,   171,   172,
     231,   315,     0,   436,     0,   383,   368,   369,   371,   370,
     374,   372,   373,   381,   376,   375,     0,   382,   390,     0,
     285,     8,     7,     6,    10,     9,    15,    12,    11,    13,
      14,     2,     3,     4,     5,     0,    16,    17,   284,     0,
       0,   118,   123,     0,     0,   130,   139,   203,   196,   188,
       0,     0,   248,   253,    66,     0,   444,     0,    74,    57,
      61,    58,    60,    59,    49,    70,    65,    64,     0,    51,
      67,    68,    69,     0,     0,     0,   360,   361,     0,     0,
       0,   267,   268,   276,   261,   151,   357,   312,     0,   167,
     299,   320,   378,   367,     0,     0,     0,     0,   428,   390,
       0,     0,   279,   281,   291,   121,     0,   144,   145,   148,
       0,     0,     0,     0,     0,     0,     0,   159,   160,   158,
     161,   164,     0,     0,     0,     0,     0,     0,   448,     0,
      46,     0,     0,   270,   272,   233,   237,     0,     0,   258,
     260,     0,     0,   274,     0,     0,     0,     0,   166,     0,
       0,     0,   116,     0,   393,   126,     0,   394,   387,   389,
     391,   295,   280,     0,     0,   124,   146,   128,   135,   131,
     140,     0,     0,     0,   149,   181,   183,     0,   180,     0,
       0,    33,    30,    31,    32,    35,    34,     0,     0,     0,
     249,   254,   246,   445,     0,     0,    75,    47,    50,     0,
       0,     0,     0,   362,   440,     0,   265,   262,   276,   273,
       0,   154,   155,   359,   358,   313,   321,   379,   396,     0,
     117,     0,     0,   129,     0,     0,   427,     0,   392,     0,
       0,   288,   287,   286,    39,    38,   292,     0,     0,     0,
       0,     0,   204,   197,     0,     0,   189,     0,     0,   163,
     222,   221,   224,   223,     0,     0,     0,     0,   449,   455,
       0,     0,    56,    36,    37,    25,    24,    26,    27,    28,
      29,    55,    53,    52,    54,     0,    73,   242,   234,     0,
     363,     0,   263,   266,   275,   152,   156,   361,   336,   383,
     401,     0,     0,   408,   417,     0,     0,   432,   388,   429,
     296,   282,   125,   147,   136,     0,     0,     0,     0,     0,
     173,   184,     0,   162,     0,     0,   250,   255,   446,     0,
       0,     0,     0,     0,    63,   240,   235,   238,   441,     0,
       0,   330,   336,   336,   336,   336,   336,   336,   336,   322,
     336,   380,     0,   398,   404,     0,     0,   412,   422,     0,
     482,   283,     0,   132,   141,   205,   198,   182,     0,   176,
       0,     0,     0,   230,     0,     0,   447,   450,   456,    76,
      48,    71,     0,     0,   239,     0,   264,   157,   336,   324,
     325,   327,   326,   328,   334,   329,     0,   335,   402,   399,
       0,     0,     0,     0,     0,   433,   475,   471,   460,   461,
     464,   466,   467,   463,   462,   470,   468,   469,   474,   482,
     465,   430,   137,     0,   355,   355,   174,     0,   190,     0,
       0,     0,     0,   251,   256,     0,     0,    62,   241,   438,
     437,     0,   331,   323,   405,   409,   418,   413,   423,     0,
       0,     0,     0,   481,     0,   142,     0,     0,   345,   337,
     338,   340,   339,   344,   342,   343,   349,   352,   341,   348,
     355,   206,   353,   199,     0,   177,     0,   245,   243,   230,
     227,   451,   457,   442,     0,     0,   410,     0,     0,     0,
       0,     0,     0,   472,   431,     0,   350,   351,   355,   354,
       0,     0,   175,     0,   169,     0,   168,     0,   244,   229,
     228,     0,     0,   443,   332,   406,   419,     0,     0,   434,
     476,   479,     0,   143,   346,   207,   200,   178,     0,   191,
       0,     0,   336,     0,   414,   424,     0,   477,   480,   473,
       0,   220,     0,     0,     0,   452,   458,   333,   420,   415,
       0,   435,   347,   209,   216,   208,   179,   170,   192,   453,
     459,   425,     0,     0,   355,     0,   210,   217,   193,   426,
       0,   355,     0,     0,   218,   194,   211,     0,     0,   219,
     212,   355,   213,     0,   214,   220,   215
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -626,   244,  -626,  -626,  -370,  -626,  -626,   257,  -626,  -626,
    -626,  -626,    71,  -626,    38,  -157,  -626,  -626,  -626,  -626,
    -339,  -626,  -142,  -137,  -626,     0,  -183,  -181,  -626,  -626,
    -626,   317,  -626,  -626,  -626,  -626,  -626,  -626,   323,  -626,
    -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,
    -626,  -626,  -626,   174,  -222,  -626,  -292,  -626,  -626,   160,
    -626,  -626,   231,  -626,  -219,  -289,  -626,  -625,  -626,  -626,
     -70,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,
     -61,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,
    -626,  -626,  -626,  -626,  -626,    23,  -626,  -626,  -626,  -626,
    -626,  -626,  -626,  -153,  -626,  -626,  -626,  -626,  -626,  -626,
    -626,  -626,  -626,  -483,   372,     2,  -626,   -45,   137,   498,
    -626,  -626,  -626,  -626,  -626,  -626,  -481,  -626,    21,  -626,
    -626,   191,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,
     342,  -626,  -626,    93,   100,  -626,  -626,   289,   -64,  -626,
    -626,   305,  -626,   220,  -626,  -626,  -626,  -626,  -626,  -170,
    -401,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,   571,
    -626,  -626,  -626,  -626,  -626,  -104,  -626,  -626,  -626,  -626,
    -626,  -626,  -626,  -490,  -626,  -626,  -626,  -626,  -626,  -626,
    -564,  -626,  -626,  -626,   293,  -626,  -626,  -626,  -626,  -626,
    -626,  -626,   -46,  -626,  -626,  -626,  -626,  -626,  -626,  -626,
    -626,   335,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,
    -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,
    -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,
    -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,   340,
    -626,   570,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,
    -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,  -626,
      -2,  -626,  -626,  -626,  -626,  -626,  -626,  -626,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   215,   177,   452,   368,   454,   413,    30,   378,   441,
     246,   310,   455,   247,   503,   457,   311,   312,   309,   440,
      31,    32,    33,    34,    35,   129,    37,    38,    39,    59,
      60,    77,   145,    86,   220,   146,   286,   417,    79,    88,
     223,   149,   292,   420,    89,   224,   419,   532,   150,   293,
     421,   593,   665,   289,   290,   418,   105,   167,   325,   390,
     391,   510,   301,   360,   392,   106,   268,   107,   677,   698,
     130,   491,   538,   644,   597,   673,   712,   359,   424,   425,
     131,   110,   153,   296,   492,   646,   714,   734,   742,   111,
     152,   295,   488,   595,   671,   132,   113,   151,   294,   487,
     594,   670,   711,   725,   732,   740,   748,   751,   753,   755,
     733,   741,   747,   434,   157,   133,   680,   602,   134,   116,
     254,   381,   506,   255,   382,   554,   458,   553,   135,   678,
     250,   136,   158,   304,   435,   544,   159,   305,   436,   545,
     165,   258,   259,   137,   387,   509,   463,   263,   638,   160,
     161,   138,   264,   323,    40,   218,   342,   343,   531,   219,
     416,    41,    75,   143,   344,    42,    84,   199,   409,    64,
      80,   182,   122,   169,   327,   123,    43,    46,    81,   184,
     329,   468,   566,   519,   558,   654,   702,   640,   668,   710,
     641,   124,   168,   326,   163,   256,   317,   460,    44,    47,
      82,   196,   139,   185,   330,   469,    45,    48,    83,   198,
     405,   278,   279,   408,   280,   334,   398,   471,   569,   399,
     522,   472,   570,   655,   337,   401,   525,   656,   475,   573,
     658,   719,   402,   526,   657,   703,   476,   574,   659,   720,
     735,   338,   406,   530,   624,   407,   529,   619,   706,   140,
     611,   126,   318,   461,   555,   683,   252,   307,   437,   546,
     374,   499,   605,   681,   729,   375,   500,   606,   682,   730,
     589,   622,   692,   590,   620,   707,   621,   708,   591
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,   216,   291,   248,   357,   414,   217,   358,   480,   453,
     108,   302,   543,   542,   271,   276,   120,   277,   181,   109,
     269,   676,   559,   560,   561,   562,   563,   564,   565,   281,
     567,   643,   331,    72,   308,  -356,    36,    49,  -356,    50,
      36,   346,   216,    36,    36,    36,    53,   217,   155,    55,
     346,   347,   108,   385,   386,    49,   156,   216,   120,  -119,
     348,   109,   217,   285,   -98,   267,  -150,    73,   612,  -150,
     414,   162,    57,   713,   610,    51,   669,   723,   724,    54,
     104,  -395,   114,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,    51,   197,    56,   276,   354,   277,   108,
     674,   117,    52,   112,   694,   120,   346,    52,   109,   430,
     431,   328,   287,   356,    61,   505,   533,   600,   649,   432,
     433,   288,   104,   346,   114,    52,   361,   362,   363,   364,
     365,   366,   357,   534,   453,   489,   346,   351,   352,   272,
     297,   427,    63,   117,   298,   112,   615,   346,   428,   299,
     346,   261,   300,   346,   379,   380,   367,   616,    71,   262,
     704,    91,    92,   705,   505,    93,   715,    69,    85,   104,
     738,   114,    70,   119,    96,    74,    76,   744,    78,    98,
       5,  -119,    87,    99,    90,   101,   141,   752,   127,   142,
     117,   144,   112,   154,   147,  -271,   162,   148,   485,   486,
     700,   216,   415,   164,   221,   166,   217,   178,   179,   180,
     183,  -359,   717,   227,   222,   119,   253,   115,   102,   511,
     361,   362,   363,   364,   365,   366,   353,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,   225,    29,
     226,   200,   228,   230,   229,   231,   493,   232,   257,   115,
     482,   233,   119,  -259,   260,   354,   265,   415,   355,   266,
     270,   118,   273,   282,     8,     9,    10,    11,    12,    13,
     284,   283,   306,   501,   313,    19,    20,    21,    22,    23,
     314,   557,   315,    58,   316,   319,    29,    62,   504,   322,
      66,    67,    68,   571,   572,   721,   115,   320,   201,   202,
     203,   204,   205,   118,    14,    15,    16,    17,    18,   206,
     207,   208,   209,   210,    24,    25,    26,    27,    28,   321,
     211,   212,   213,   214,    54,   540,   332,   335,   340,   541,
     234,   341,   235,   345,   361,   362,   363,   364,   365,   366,
     236,   349,   237,   350,   675,   369,   370,   371,   372,   373,
     118,   234,   376,   235,   383,   568,    73,   414,   377,   384,
     389,   236,   393,   237,   494,   592,   238,   395,   239,   240,
     241,   242,   243,   396,   400,   121,   397,   244,   403,   404,
     245,   170,   422,   426,    52,   504,   608,   238,   513,   239,
     240,   241,   242,   243,   423,   438,   675,   514,   244,   439,
     456,   245,   170,   171,   172,   173,   174,   175,   176,   459,
     125,   462,   466,   521,   465,   467,   478,   121,   361,   362,
     363,   364,   365,   366,   470,   473,   687,   688,   474,   477,
     484,   479,   513,   513,   513,   513,   513,   513,   513,   660,
     513,   514,   514,   514,   514,   514,   514,   514,   481,   514,
     579,   354,   125,   661,   490,   505,   495,   496,   512,   580,
     497,   498,   507,   508,   121,   596,   523,   216,   524,   527,
     528,   537,   217,   535,   536,   539,   547,   672,   513,   549,
     548,   515,   551,   550,   575,   603,   598,   514,   685,   171,
     172,   173,   174,   175,   176,   599,   601,   604,   693,   125,
     614,   613,   512,   512,   512,   512,   512,   512,   512,   579,
     512,   617,   618,   625,   630,   630,  -478,   645,   580,   647,
     578,   648,   582,   631,   631,   515,   515,   515,   515,   515,
     515,   515,   650,   515,   651,   652,   718,   653,   666,   686,
     662,   584,   579,   581,   664,   726,   667,   684,   512,   689,
     690,   580,   691,   697,   415,   701,   695,   731,   696,   716,
     630,   709,   722,   699,   728,   552,   727,   737,   739,   631,
     736,   515,   745,   743,   746,   749,   750,   410,   754,   578,
     607,   582,   483,   333,   629,   629,   633,   633,   630,   429,
     336,   502,   756,   303,   679,   516,   324,   631,   464,   556,
     584,   388,   581,    65,   339,   635,   635,   632,   632,   394,
     663,   623,   578,   586,   582,     0,     0,     0,     0,     0,
       0,     0,   513,     0,     0,     0,     0,     0,     0,     0,
     629,   514,   633,   584,     0,   581,     0,     0,     0,   516,
     516,   516,   516,   516,   516,   516,     0,   516,   249,   517,
       0,   635,     0,   632,   630,     0,     0,   583,   629,     0,
     633,   630,     0,   631,     0,   249,     0,     0,     0,     0,
     631,   630,   586,     0,     0,     0,     0,   637,   637,   635,
     631,   632,     0,     0,     0,   516,     0,     0,     0,     0,
       0,     0,   512,   517,   517,   517,   517,   517,   517,   517,
       0,   517,     0,     0,     0,   586,     0,     0,   249,     0,
       0,   585,     0,     0,     0,   515,   583,     0,     0,     0,
     251,   634,   634,   637,   629,     0,   633,     0,     0,     0,
       0,   629,     0,   633,     0,     0,     0,   251,     0,   517,
       0,   629,     0,   633,     0,   635,     0,   632,     0,   583,
       0,   637,   635,     0,   632,     0,   249,     0,     0,     0,
       0,     0,   635,   518,   632,     0,     0,   634,     0,     0,
     585,     0,     0,     0,     0,   636,   636,     0,     0,     0,
     251,     0,   249,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   634,     0,     0,   520,   249,
     249,     0,     0,   585,     0,     0,     0,   518,   518,   518,
     518,   518,   518,   518,     0,   518,     0,   637,     0,     0,
       0,   636,     0,     0,   637,   587,     0,     0,   251,   516,
       0,     0,     0,     0,   637,     0,     0,     0,     0,     0,
       0,     0,   520,   520,   520,   520,   520,   520,   520,   636,
     520,     0,     0,   518,   251,   251,     0,     0,     0,     0,
     588,   634,     0,     0,     0,     0,     0,     0,   634,   249,
       0,   251,   251,     0,     0,     0,     0,     0,   634,     0,
       0,     0,     0,   517,   587,     0,     0,     0,   520,   639,
     639,     0,     0,     0,     0,     0,     0,   609,   234,     0,
     235,     0,     0,     0,     0,   249,     0,     0,   236,     0,
     237,     0,     0,     0,     0,   636,     0,   587,     0,   588,
       0,     0,   636,     0,   642,   642,     0,     0,   249,     0,
       0,     0,   636,     0,   238,   639,   239,   240,   241,   242,
     243,   251,     0,   249,     0,   244,     0,     0,   245,     0,
       0,     0,   588,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   639,     0,     0,     0,     0,     0,     0,
     642,     0,     0,     0,     0,     0,     0,   251,     0,     0,
     249,     0,   249,     0,     0,     0,     0,   361,   362,   363,
     364,   365,   366,   442,     0,     0,     0,   518,   642,     0,
     251,   443,   444,   445,   446,   447,   448,   449,     0,   450,
     249,     0,     0,     0,     0,   251,     0,     0,     0,     0,
     249,     0,     0,     0,     0,     0,   451,     0,     0,   639,
       0,     0,   520,     0,     0,     0,   639,     0,     0,     0,
     249,   249,     0,   249,     0,     0,   639,     0,     0,     0,
       0,     0,   251,     0,   251,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   642,     0,     0,     0,     0,     0,
       0,   642,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   642,   251,     0,     0,   411,     0,     0,     0,     0,
       0,     0,   251,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,     0,     0,     0,   249,     0,
       0,     0,   251,   251,     0,   251,   412,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   249,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   249,     0,     0,     0,     0,   201,   202,
     203,   204,   205,   249,    14,    15,    16,    17,    18,   206,
     207,   208,   209,   210,    24,    25,    26,    27,    28,   249,
     211,   212,   213,   214,     0,     0,     0,     0,     0,     0,
     251,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   249,     0,     0,   274,   275,     0,     0,     0,     0,
     249,     0,     0,     0,   251,     0,     0,     0,    91,    92,
       0,     0,    93,   626,   627,   251,    94,     0,     0,    95,
       0,    96,     0,   249,    97,   251,    98,     5,   249,     0,
      99,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,   251,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   251,    29,   102,   628,     0,     0,     0,
       0,     0,   251,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,   251,    29,    91,    92,     0,
     251,    93,     0,     0,     0,    94,     0,     0,    95,     0,
      96,     0,     0,    97,     0,    98,     5,     0,     0,    99,
     100,   101,     0,     0,     0,     0,     0,     0,     0,    91,
      92,     0,     0,    93,     0,     0,     0,    94,     0,     0,
      95,     0,    96,     0,     0,   576,     0,    98,     5,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     0,    29,   102,   577,     0,     0,
       0,     0,     0,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,    29,    91,    92,
       0,     0,    93,     0,     0,     0,    94,     0,     0,    95,
       0,    96,     0,     0,     0,     0,    98,     5,     0,     0,
      99,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     3,     4,     5,     0,     6,
       0,     0,     0,     0,     0,   102,   128,     0,     0,     0,
       0,     0,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     7,    29,     0,     0,     0,
       0,     0,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     0,    29
};

static const yytype_int16 yycheck[] =
{
       0,   143,   224,   160,   296,   344,   143,   296,   409,   379,
      80,   230,   495,   494,   184,   198,    80,   198,   122,    80,
     177,   646,   512,   513,   514,   515,   516,   517,   518,   199,
     520,   595,    22,    60,    23,    34,    36,    22,    34,    24,
      40,    56,   184,    43,    44,    45,    60,   184,    52,    60,
      56,    66,   122,    56,    57,    22,    60,   199,   122,    35,
      66,   122,   199,   220,    60,   169,    65,    94,   558,    65,
     409,    60,    60,   698,   555,    60,   640,     5,     6,    93,
      80,    57,    80,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,    60,   140,     0,   279,    60,   279,   169,
      63,    80,    92,    80,   668,   169,    56,    92,   169,    75,
      76,   268,    51,   296,    57,    56,    66,    58,   601,    85,
      86,    60,   122,    56,   122,    92,    28,    29,    30,    31,
      32,    33,   424,    66,   504,   424,    56,   294,   295,   185,
      51,   360,    61,   122,    55,   122,    66,    56,   367,    60,
      56,    52,    63,    56,   311,   312,    58,    66,    90,    60,
      66,     3,     4,    66,    56,     7,    58,    60,    58,   169,
     734,   169,    61,    80,    16,    60,    60,   741,    60,    21,
      22,    35,    56,    25,    56,    27,    61,   751,    58,    58,
     169,    35,   169,    60,    65,    74,    60,    65,   420,   421,
     681,   343,   344,    34,    60,    58,   343,    57,    57,    57,
      57,    34,   702,    65,    60,   122,    74,    80,    60,    61,
      28,    29,    30,    31,    32,    33,    21,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    60,    91,
      60,    12,    65,    58,    65,    58,    64,    63,    34,   122,
     417,    63,   169,    60,    58,    60,    65,   409,    63,    34,
      62,    80,    62,    60,    69,    70,    71,    72,    73,    74,
      58,    56,    34,   440,    57,    80,    81,    82,    83,    84,
      57,   510,    58,    36,    58,    52,    91,    40,   455,    67,
      43,    44,    45,   525,   526,   706,   169,    60,    69,    70,
      71,    72,    73,   122,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    60,
      91,    92,    93,    94,    93,   492,    60,    60,    57,    12,
      13,    58,    15,    35,    28,    29,    30,    31,    32,    33,
      23,    65,    25,    65,   646,    58,    55,    51,    17,    34,
     169,    13,    63,    15,    60,   522,    94,   706,    65,    60,
      57,    23,    60,    25,    58,   532,    49,    62,    51,    52,
      53,    54,    55,    61,    56,    80,    62,    60,    56,    24,
      63,    35,    66,    59,    92,   552,   553,    49,   468,    51,
      52,    53,    54,    55,    66,    34,   698,   468,    60,    34,
      64,    63,    35,    36,    37,    38,    39,    40,    41,    12,
      80,    60,    56,   469,    66,    34,    62,   122,    28,    29,
      30,    31,    32,    33,    35,    65,   658,   659,    65,    60,
      35,    61,   512,   513,   514,   515,   516,   517,   518,   619,
     520,   512,   513,   514,   515,   516,   517,   518,    60,   520,
     530,    60,   122,   620,    60,    56,    58,    64,   468,   530,
      64,    60,    58,    58,   169,    35,    60,   619,    60,    60,
      60,    64,   619,    61,    61,    56,    60,   644,   558,    64,
      60,   468,    64,    66,    58,    57,    59,   558,   655,    36,
      37,    38,    39,    40,    41,    58,    58,    57,   665,   169,
      35,    62,   512,   513,   514,   515,   516,   517,   518,   589,
     520,    65,    65,    35,   594,   595,    74,    60,   589,    57,
     530,    57,   530,   594,   595,   512,   513,   514,   515,   516,
     517,   518,    57,   520,    58,    58,   703,    58,    57,    35,
      74,   530,   622,   530,    62,   712,    57,    62,   558,    58,
      57,   622,    57,    35,   706,    12,    62,    35,    62,    58,
     640,    62,    62,    66,    61,   504,    64,    61,   735,   640,
      65,   558,    62,   740,    66,    62,    61,   343,    62,   589,
     552,   589,   418,   276,   594,   595,   594,   595,   668,   368,
     277,   441,   755,   231,   649,   468,   264,   668,   388,   509,
     589,   322,   589,    42,   279,   594,   595,   594,   595,   326,
     622,   589,   622,   530,   622,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   702,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     640,   702,   640,   622,    -1,   622,    -1,    -1,    -1,   512,
     513,   514,   515,   516,   517,   518,    -1,   520,   160,   468,
      -1,   640,    -1,   640,   734,    -1,    -1,   530,   668,    -1,
     668,   741,    -1,   734,    -1,   177,    -1,    -1,    -1,    -1,
     741,   751,   589,    -1,    -1,    -1,    -1,   594,   595,   668,
     751,   668,    -1,    -1,    -1,   558,    -1,    -1,    -1,    -1,
      -1,    -1,   702,   512,   513,   514,   515,   516,   517,   518,
      -1,   520,    -1,    -1,    -1,   622,    -1,    -1,   220,    -1,
      -1,   530,    -1,    -1,    -1,   702,   589,    -1,    -1,    -1,
     160,   594,   595,   640,   734,    -1,   734,    -1,    -1,    -1,
      -1,   741,    -1,   741,    -1,    -1,    -1,   177,    -1,   558,
      -1,   751,    -1,   751,    -1,   734,    -1,   734,    -1,   622,
      -1,   668,   741,    -1,   741,    -1,   268,    -1,    -1,    -1,
      -1,    -1,   751,   468,   751,    -1,    -1,   640,    -1,    -1,
     589,    -1,    -1,    -1,    -1,   594,   595,    -1,    -1,    -1,
     220,    -1,   294,   295,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   668,    -1,    -1,   468,   311,
     312,    -1,    -1,   622,    -1,    -1,    -1,   512,   513,   514,
     515,   516,   517,   518,    -1,   520,    -1,   734,    -1,    -1,
      -1,   640,    -1,    -1,   741,   530,    -1,    -1,   268,   702,
      -1,    -1,    -1,    -1,   751,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   512,   513,   514,   515,   516,   517,   518,   668,
     520,    -1,    -1,   558,   294,   295,    -1,    -1,    -1,    -1,
     530,   734,    -1,    -1,    -1,    -1,    -1,    -1,   741,   381,
      -1,   311,   312,    -1,    -1,    -1,    -1,    -1,   751,    -1,
      -1,    -1,    -1,   702,   589,    -1,    -1,    -1,   558,   594,
     595,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,
      15,    -1,    -1,    -1,    -1,   417,    -1,    -1,    23,    -1,
      25,    -1,    -1,    -1,    -1,   734,    -1,   622,    -1,   589,
      -1,    -1,   741,    -1,   594,   595,    -1,    -1,   440,    -1,
      -1,    -1,   751,    -1,    49,   640,    51,    52,    53,    54,
      55,   381,    -1,   455,    -1,    60,    -1,    -1,    63,    -1,
      -1,    -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   668,    -1,    -1,    -1,    -1,    -1,    -1,
     640,    -1,    -1,    -1,    -1,    -1,    -1,   417,    -1,    -1,
     492,    -1,   494,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,   702,   668,    -1,
     440,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
     522,    -1,    -1,    -1,    -1,   455,    -1,    -1,    -1,    -1,
     532,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,   734,
      -1,    -1,   702,    -1,    -1,    -1,   741,    -1,    -1,    -1,
     552,   553,    -1,   555,    -1,    -1,   751,    -1,    -1,    -1,
      -1,    -1,   492,    -1,   494,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   734,    -1,    -1,    -1,    -1,    -1,
      -1,   741,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   751,   522,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,   532,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    -1,    -1,   620,    -1,
      -1,    -1,   552,   553,    -1,   555,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   644,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   655,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,   665,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   681,
      91,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
     620,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   703,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,
     712,    -1,    -1,    -1,   644,    -1,    -1,    -1,     3,     4,
      -1,    -1,     7,     8,     9,   655,    11,    -1,    -1,    14,
      -1,    16,    -1,   735,    19,   665,    21,    22,   740,    -1,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   681,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,   703,    91,    60,    61,    -1,    -1,    -1,
      -1,    -1,   712,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,   735,    91,     3,     4,    -1,
     740,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,    -1,
      16,    -1,    -1,    19,    -1,    21,    22,    -1,    -1,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    -1,     7,    -1,    -1,    -1,    11,    -1,    -1,
      14,    -1,    16,    -1,    -1,    19,    -1,    21,    22,    -1,
      -1,    25,    26,    27,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    91,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    91,     3,     4,
      -1,    -1,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,
      -1,    16,    -1,    -1,    -1,    -1,    21,    22,    -1,    -1,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    20,    21,    22,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    60,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    91
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    10,    18,    20,    21,    22,    24,    60,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    91,
     102,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     249,   256,   260,   271,   293,   301,   272,   294,   302,    22,
      24,    60,    92,    60,    93,    60,     0,    60,   102,   124,
     125,    57,   102,    61,   264,   264,   102,   102,   102,    60,
      61,    90,    60,    94,    60,   257,    60,   126,    60,   133,
     265,   273,   295,   303,   261,    58,   128,    56,   134,   139,
      56,     3,     4,     7,    11,    14,    16,    19,    21,    25,
      26,    27,    60,    61,   120,   151,   160,   162,   165,   175,
     176,   184,   190,   191,   210,   213,   214,   223,   226,   238,
     243,   246,   267,   270,   286,   344,   346,    58,    61,   120,
     165,   175,   190,   210,   213,   223,   226,   238,   246,   297,
     344,    61,    58,   258,    35,   127,   130,    65,    65,   136,
     143,   192,   185,   177,    60,    52,    60,   209,   227,   231,
     244,   245,    60,   289,    34,   235,    58,   152,   287,   268,
      35,    36,    37,    38,    39,    40,    41,    97,    57,    57,
      57,   270,   266,    57,   274,   298,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   296,   297,   304,   262,
      12,    69,    70,    71,    72,    73,    80,    81,    82,    83,
      84,    91,    92,    93,    94,    96,   117,   118,   250,   254,
     129,    60,    60,   135,   140,    60,    60,    65,    65,    65,
      58,    58,    63,    63,    13,    15,    23,    25,    49,    51,
      52,    53,    54,    55,    60,    63,   105,   108,   110,   214,
     225,   346,   351,    74,   215,   218,   290,    34,   236,   237,
      58,    52,    60,   242,   247,    65,    34,   270,   161,   110,
      62,   254,   297,    62,    21,    22,   121,   122,   306,   307,
     309,   254,    60,    56,    58,   110,   131,    51,    60,   148,
     149,   149,   137,   144,   193,   186,   178,    51,    55,    60,
      63,   157,   159,   209,   228,   232,    34,   352,    23,   113,
     106,   111,   112,    57,    57,    58,    58,   291,   347,    52,
      60,    60,    67,   248,   235,   153,   288,   269,   110,   275,
     299,    22,    60,   126,   310,    60,   133,   319,   336,   306,
      57,    58,   251,   252,   259,    35,    56,    66,    66,    65,
      65,   110,   110,    21,    60,    63,   121,   151,   160,   172,
     158,    28,    29,    30,    31,    32,    33,    58,    99,    58,
      55,    51,    17,    34,   355,   360,    63,    65,   103,   110,
     110,   216,   219,    60,    60,    56,    57,   239,   242,    57,
     154,   155,   159,    60,   289,    62,    61,    62,   311,   314,
      56,   320,   327,    56,    24,   305,   337,   340,   308,   263,
      96,    60,    91,   101,   115,   117,   255,   132,   150,   141,
     138,   145,    66,    66,   173,   174,    59,   159,   159,   157,
      75,    76,    85,    86,   208,   229,   233,   353,    34,    34,
     114,   104,    34,    42,    43,    44,    45,    46,    47,    48,
      50,    67,    98,    99,   100,   107,    64,   110,   221,    12,
     292,   348,    60,   241,   248,    66,    56,    34,   276,   300,
      35,   312,   316,    65,    65,   323,   331,    60,    62,    61,
     255,    60,   110,   148,    35,   149,   149,   194,   187,   160,
      60,   166,   179,    64,    58,    58,    64,    64,    60,   356,
     361,   110,   154,   109,   110,    56,   217,    58,    58,   240,
     156,    61,   120,   165,   175,   190,   213,   226,   246,   278,
     344,   297,   315,    60,    60,   321,   328,    60,    60,   341,
     338,   253,   142,    66,    66,    61,    61,    64,   167,    56,
     110,    12,   221,   208,   230,   234,   354,    60,    60,    64,
      66,    64,   107,   222,   220,   349,   239,   159,   279,   278,
     278,   278,   278,   278,   278,   278,   277,   278,   110,   313,
     317,   149,   149,   324,   332,    58,    19,    61,   120,   165,
     175,   190,   210,   213,   223,   226,   238,   246,   344,   365,
     368,   373,   110,   146,   195,   188,    35,   169,    59,    58,
      58,    58,   212,    57,    57,   357,   362,   109,   110,    12,
     221,   345,   278,    62,    35,    66,    66,    65,    65,   342,
     369,   371,   366,   373,   339,    35,     8,     9,    61,   120,
     165,   175,   190,   210,   213,   223,   226,   238,   243,   246,
     282,   285,   344,   285,   168,    60,   180,    57,    57,   208,
      57,    58,    58,    58,   280,   318,   322,   329,   325,   333,
     254,   110,    74,   365,    62,   147,    57,    57,   283,   285,
     196,   189,   110,   170,    63,   151,   162,   163,   224,   212,
     211,   358,   363,   350,    62,   110,    35,   149,   149,    58,
      57,    57,   367,   110,   285,    62,    62,    35,   164,    66,
     221,    12,   281,   330,    66,    66,   343,   370,   372,    62,
     284,   197,   171,   162,   181,    58,    58,   278,   110,   326,
     334,   255,    62,     5,     6,   198,   110,    64,    61,   359,
     364,    35,   199,   205,   182,   335,    65,    61,   285,   110,
     200,   206,   183,   110,   285,    62,    66,   207,   201,    62,
      61,   202,   285,   203,    62,   204,   198
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,    95,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    97,    97,
      97,    97,    97,    97,    98,    98,    98,    98,    98,    98,
      99,    99,    99,    99,    99,    99,   100,   100,   101,   101,
     102,   102,   102,   102,   102,   102,   103,   104,   103,   106,
     105,   105,   107,   107,   107,   107,   107,   108,   108,   108,
     108,   108,   109,   109,   110,   110,   110,   110,   110,   110,
     111,   110,   112,   110,   113,   114,   110,   115,   115,   115,
     115,   115,   115,   116,   116,   116,   116,   116,   117,   117,
     117,   117,   117,   118,   118,   118,   118,   118,   119,   119,
     119,   119,   120,   120,   121,   121,   121,   121,   122,   122,
     122,   122,   124,   123,   125,   123,   126,   127,   126,   128,
     129,   126,   130,   131,   132,   126,   134,   135,   133,   136,
     137,   138,   133,   139,   140,   141,   142,   133,   143,   144,
     145,   146,   147,   133,   148,   148,   150,   149,   149,   151,
     152,   153,   151,   151,   154,   155,   156,   155,   157,   157,
     157,   158,   157,   159,   159,   161,   160,   162,   163,   164,
     163,   165,   165,   167,   168,   166,   169,   170,   171,   166,
     172,   173,   172,   174,   172,   175,   175,   177,   178,   179,
     180,   181,   182,   183,   176,   185,   186,   187,   188,   189,
     184,   190,   192,   193,   194,   195,   196,   197,   191,   199,
     200,   201,   202,   203,   204,   198,   205,   206,   207,   198,
     198,   208,   208,   208,   208,   209,   209,   211,   210,   212,
     212,   213,   215,   216,   217,   214,   218,   219,   220,   214,
     222,   221,   221,   224,   223,   223,   225,   227,   228,   229,
     230,   226,   231,   232,   233,   234,   226,   236,   235,   237,
     235,   235,   238,   240,   239,   241,   239,   242,   242,   244,
     243,   245,   243,   246,   247,   248,   248,   249,   249,   251,
     250,   252,   253,   250,   254,   254,   255,   255,   255,   257,
     258,   259,   256,   261,   262,   263,   260,   265,   266,   264,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   268,   269,   267,   267,   270,   270,   272,   273,   274,
     275,   276,   277,   271,   278,   278,   278,   278,   278,   278,
     279,   280,   281,   278,   278,   278,   278,   282,   282,   282,
     282,   282,   282,   282,   282,   283,   284,   282,   282,   282,
     282,   282,   282,   282,   285,   285,   287,   288,   286,   290,
     289,   291,   292,   289,   294,   295,   296,   293,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   298,   299,   300,
     297,   297,   297,   297,   302,   303,   304,   305,   301,   306,
     306,   308,   307,   309,   309,   311,   310,   312,   313,   310,
     314,   315,   310,   316,   317,   318,   310,   320,   321,   322,
     319,   323,   324,   325,   326,   319,   327,   328,   329,   330,
     319,   331,   332,   333,   334,   335,   319,   336,   336,   338,
     339,   337,   341,   342,   343,   340,   344,   345,   345,   347,
     348,   349,   350,   346,   352,   353,   354,   351,   355,   356,
     357,   358,   359,   351,   360,   361,   362,   363,   364,   351,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   366,   367,   365,   365,   369,   370,   368,   371,   372,
     368,   373,   373
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     2,     2,     2,     2,     0,     0,     4,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     0,     4,     0,     0,     6,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     2,     2,     1,     1,     1,     2,     1,     1,
       2,     3,     0,     3,     0,     3,     1,     0,     4,     0,
       0,     5,     0,     0,     0,     8,     0,     0,     6,     0,
       0,     0,     9,     0,     0,     0,     0,    10,     0,     0,
       0,     0,     0,    13,     1,     1,     0,     4,     1,     1,
       0,     0,     6,     1,     1,     1,     0,     4,     1,     1,
       1,     0,     4,     3,     1,     0,     4,     3,     1,     0,
       4,     2,     2,     0,     0,     5,     0,     0,     0,     8,
       1,     0,     4,     0,     3,     1,     1,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
      12,     1,     0,     0,     0,     0,     0,     0,    14,     0,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     7,
       0,     1,     1,     1,     1,     1,     1,     0,    11,     3,
       0,     2,     0,     0,     0,     7,     0,     0,     0,     8,
       0,     4,     1,     0,    11,    10,     3,     0,     0,     0,
       0,     9,     0,     0,     0,     0,     9,     0,     3,     0,
       3,     0,     5,     0,     4,     0,     2,     1,     1,     0,
       4,     0,     4,     5,     2,     3,     0,     2,     2,     0,
       3,     0,     0,     6,     1,     1,     1,     1,     1,     0,
       0,     0,     9,     0,     0,     0,    10,     0,     0,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     0,     5,     1,     2,     0,     0,     0,     0,
       0,     0,     0,    13,     2,     2,     2,     2,     2,     2,
       0,     0,     0,     7,     2,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     0,     5,     1,     1,
       2,     2,     1,     1,     2,     0,     0,     0,     5,     0,
       2,     0,     0,     5,     0,     0,     0,     7,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     0,     0,     0,
       7,     2,     2,     0,     0,     0,     0,     0,    10,     2,
       0,     0,     3,     2,     2,     0,     2,     0,     0,     5,
       0,     0,     5,     0,     0,     0,     8,     0,     0,     0,
       7,     0,     0,     0,     0,    10,     0,     0,     0,     0,
      10,     0,     0,     0,     0,     0,    13,     2,     0,     0,
       0,     6,     0,     0,     0,     9,     2,     1,     1,     0,
       0,     0,     0,    11,     0,     0,     0,     6,     0,     0,
       0,     0,     0,    12,     0,     0,     0,     0,     0,    12,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     0,     5,     1,     0,     0,     5,     0,     0,
       5,     2,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* all_datatypes: NUDATATYPE  */
#line 99 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2499 "y.tab.c"
    break;

  case 3: /* all_datatypes: AUDATATYPE  */
#line 105 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2509 "y.tab.c"
    break;

  case 4: /* all_datatypes: NARRUDATATYPE  */
#line 111 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2519 "y.tab.c"
    break;

  case 5: /* all_datatypes: AARRUDATATYPE  */
#line 117 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2529 "y.tab.c"
    break;

  case 6: /* all_datatypes: NBOOL  */
#line 123 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2539 "y.tab.c"
    break;

  case 7: /* all_datatypes: NDEC  */
#line 129 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2549 "y.tab.c"
    break;

  case 8: /* all_datatypes: NNUM  */
#line 135 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2559 "y.tab.c"
    break;

  case 9: /* all_datatypes: NTEXT  */
#line 141 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2569 "y.tab.c"
    break;

  case 10: /* all_datatypes: NLET  */
#line 147 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2579 "y.tab.c"
    break;

  case 11: /* all_datatypes: ABOOL  */
#line 153 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2589 "y.tab.c"
    break;

  case 12: /* all_datatypes: ADEC  */
#line 159 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2599 "y.tab.c"
    break;

  case 13: /* all_datatypes: ALET  */
#line 165 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2609 "y.tab.c"
    break;

  case 14: /* all_datatypes: ATEXT  */
#line 171 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2619 "y.tab.c"
    break;

  case 15: /* all_datatypes: ANUM  */
#line 177 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2629 "y.tab.c"
    break;

  case 16: /* all_datatypes: nonAtomicArray  */
#line 183 "bison.y"
             {
              /*
              Will be handled down
              */
             }
#line 2639 "y.tab.c"
    break;

  case 17: /* all_datatypes: atomicArray  */
#line 189 "bison.y"
             {
              /*
              Will be handled down
              */
              }
#line 2649 "y.tab.c"
    break;

  case 18: /* expression_op: ASSN_DIV  */
#line 196 "bison.y"
                        { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2655 "y.tab.c"
    break;

  case 20: /* expression_op: ASSN_MODULO  */
#line 196 "bison.y"
                                                                                    { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2661 "y.tab.c"
    break;

  case 21: /* expression_op: ASSN_MUL  */
#line 196 "bison.y"
                                                                                                                             { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2667 "y.tab.c"
    break;

  case 22: /* expression_op: INCR  */
#line 196 "bison.y"
                                                                                                                                                                  { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2673 "y.tab.c"
    break;

  case 23: /* expression_op: DECR  */
#line 196 "bison.y"
                                                                                                                                                                                                       { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2679 "y.tab.c"
    break;

  case 24: /* comparison_op: LT  */
#line 197 "bison.y"
                  { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2685 "y.tab.c"
    break;

  case 25: /* comparison_op: GT  */
#line 197 "bison.y"
                                                     { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2691 "y.tab.c"
    break;

  case 26: /* comparison_op: GTEQ  */
#line 197 "bison.y"
                                                                                          { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2697 "y.tab.c"
    break;

  case 27: /* comparison_op: LTEQ  */
#line 197 "bison.y"
                                                                                                                               { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2703 "y.tab.c"
    break;

  case 28: /* comparison_op: NOT_EQ  */
#line 197 "bison.y"
                                                                                                                                                                      { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2709 "y.tab.c"
    break;

  case 29: /* comparison_op: EQUAL_TWO  */
#line 197 "bison.y"
                                                                                                                                                                                                                { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2715 "y.tab.c"
    break;

  case 30: /* arithmetic_op: ADD  */
#line 198 "bison.y"
                   { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2721 "y.tab.c"
    break;

  case 31: /* arithmetic_op: SUB  */
#line 198 "bison.y"
                                                       { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2727 "y.tab.c"
    break;

  case 32: /* arithmetic_op: MUL  */
#line 198 "bison.y"
                                                                                           { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2733 "y.tab.c"
    break;

  case 33: /* arithmetic_op: DIV  */
#line 198 "bison.y"
                                                                                                                               { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2739 "y.tab.c"
    break;

  case 34: /* arithmetic_op: MODULO  */
#line 198 "bison.y"
                                                                                                                                                                      { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2745 "y.tab.c"
    break;

  case 36: /* logical_op: AND  */
#line 199 "bison.y"
                { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2751 "y.tab.c"
    break;

  case 37: /* logical_op: OR  */
#line 199 "bison.y"
                                                   { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2757 "y.tab.c"
    break;

  case 40: /* begin: %empty  */
#line 203 "bison.y"
        {
       if(startCount < 1){
              printError(yylineno,START_ERROR_LESS);
       }
       }
#line 2767 "y.tab.c"
    break;

  case 46: /* E: %empty  */
#line 218 "bison.y"
    {;}
#line 2773 "y.tab.c"
    break;

  case 47: /* $@1: %empty  */
#line 219 "bison.y"
             { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2779 "y.tab.c"
    break;

  case 48: /* E: SQUAREOPEN $@1 arr_access SQUARECLOSE  */
#line 219 "bison.y"
                                                                  { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2785 "y.tab.c"
    break;

  case 49: /* $@2: %empty  */
#line 222 "bison.y"
               { fprintf(fpcpp, "%s", (yyvsp[0].attr).ID); }
#line 2791 "y.tab.c"
    break;

  case 55: /* all_ops: HASH  */
#line 229 "bison.y"
             { fprintf(fpcpp, "<<"); }
#line 2797 "y.tab.c"
    break;

  case 56: /* all_ops: ARROW  */
#line 230 "bison.y"
              { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2803 "y.tab.c"
    break;

  case 57: /* constants: INTEGERLITERAL  */
#line 234 "bison.y"
       {
              (yyval.attr).datatype = "number"; 
              (yyval.attr).intVal = (yyvsp[0].attr).intVal;
              fprintf(fpcpp,"%d", (yyvsp[0].attr).intVal);
       }
#line 2813 "y.tab.c"
    break;

  case 58: /* constants: CHARACTERLITERAL  */
#line 241 "bison.y"
              {
                     (yyval.attr).datatype = "letter"; 
                     (yyval.attr).charVal = (yyvsp[0].attr).charVal;
                     fprintf(fpcpp, "%c", (yyvsp[0].attr).charVal);
              }
#line 2823 "y.tab.c"
    break;

  case 59: /* constants: FLOATLITERAL  */
#line 248 "bison.y"
              {
                     (yyval.attr).datatype = "decimal"; 
                     (yyval.attr).decVal = (yyvsp[0].attr).decVal;
                     fprintf(fpcpp, "%f", (yyvsp[0].attr).decVal);
              }
#line 2833 "y.tab.c"
    break;

  case 60: /* constants: BOOLEANLITERAL  */
#line 255 "bison.y"
        {
               (yyval.attr).datatype = "bool"; 
               (yyval.attr).boolVal = (yyvsp[0].attr).boolVal;
               fprintf(fpcpp, "%d", (yyvsp[0].attr).boolVal);
        }
#line 2843 "y.tab.c"
    break;

  case 61: /* constants: STRINGLITERAL  */
#line 262 "bison.y"
       {
              (yyval.attr).datatype = "text"; 
              (yyval.attr).stringVal = (yyvsp[0].attr).stringVal;
              fprintf(fpcpp, "%s", (yyvsp[0].attr).stringVal);
       }
#line 2853 "y.tab.c"
    break;

  case 66: /* RHS: TID  */
#line 276 "bison.y"
          { fprintf(fpcpp, "%s", (yyvsp[0].attr).token);}
#line 2859 "y.tab.c"
    break;

  case 70: /* $@3: %empty  */
#line 278 "bison.y"
                { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2865 "y.tab.c"
    break;

  case 71: /* RHS: ROUNDOPEN $@3 RHS all_ops next ROUNDCLOSE  */
#line 278 "bison.y"
                                                                          { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2871 "y.tab.c"
    break;

  case 72: /* $@4: %empty  */
#line 279 "bison.y"
                { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2877 "y.tab.c"
    break;

  case 73: /* RHS: ROUNDOPEN $@4 RHS ROUNDCLOSE  */
#line 279 "bison.y"
                                                             { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2883 "y.tab.c"
    break;

  case 74: /* $@5: %empty  */
#line 280 "bison.y"
          { fprintf(fpcpp, "!"); }
#line 2889 "y.tab.c"
    break;

  case 75: /* $@6: %empty  */
#line 280 "bison.y"
                                             { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2895 "y.tab.c"
    break;

  case 76: /* RHS: NEG $@5 ROUNDOPEN $@6 RHS ROUNDCLOSE  */
#line 280 "bison.y"
                                                                                          { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 2901 "y.tab.c"
    break;

  case 77: /* nonAtomicSimple: NNUM  */
#line 285 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2911 "y.tab.c"
    break;

  case 78: /* nonAtomicSimple: NDEC  */
#line 291 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2921 "y.tab.c"
    break;

  case 79: /* nonAtomicSimple: NBOOL  */
#line 297 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2931 "y.tab.c"
    break;

  case 80: /* nonAtomicSimple: NLET  */
#line 303 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2941 "y.tab.c"
    break;

  case 81: /* nonAtomicSimple: NTEXT  */
#line 309 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2951 "y.tab.c"
    break;

  case 82: /* nonAtomicSimple: NVOID  */
#line 315 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2961 "y.tab.c"
    break;

  case 83: /* atomicSimple: ANUM  */
#line 323 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2971 "y.tab.c"
    break;

  case 84: /* atomicSimple: ADEC  */
#line 329 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2981 "y.tab.c"
    break;

  case 85: /* atomicSimple: ABOOL  */
#line 335 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2991 "y.tab.c"
    break;

  case 86: /* atomicSimple: ALET  */
#line 341 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 3001 "y.tab.c"
    break;

  case 87: /* atomicSimple: ATEXT  */
#line 347 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 3011 "y.tab.c"
    break;

  case 88: /* nonAtomicArray: NARRNUM  */
#line 355 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 3021 "y.tab.c"
    break;

  case 89: /* nonAtomicArray: NARRDEC  */
#line 361 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 3031 "y.tab.c"
    break;

  case 90: /* nonAtomicArray: NARRBOOL  */
#line 367 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 3041 "y.tab.c"
    break;

  case 91: /* nonAtomicArray: NARRLET  */
#line 373 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 3051 "y.tab.c"
    break;

  case 92: /* nonAtomicArray: NARRTEXT  */
#line 379 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 3061 "y.tab.c"
    break;

  case 93: /* atomicArray: AARRNUM  */
#line 387 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 3071 "y.tab.c"
    break;

  case 94: /* atomicArray: AARRDEC  */
#line 393 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 3081 "y.tab.c"
    break;

  case 95: /* atomicArray: AARRBOOL  */
#line 399 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 3091 "y.tab.c"
    break;

  case 96: /* atomicArray: AARRLET  */
#line 405 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 3101 "y.tab.c"
    break;

  case 97: /* atomicArray: AARRTEXT  */
#line 411 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 3111 "y.tab.c"
    break;

  case 102: /* declaration: declarationStmt SEMICOLON  */
#line 422 "bison.y"
                                        { fprintf(yyout, " : declaration statement"); fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 3117 "y.tab.c"
    break;

  case 103: /* declaration: errorDatatypes IDENTIFIER  */
#line 423 "bison.y"
                                         {printf("TYPE NOT DECLARED, %d\n", yylineno); fprintf(fpcpp, "%s", (yyvsp[0].attr)); return 1;}
#line 3123 "y.tab.c"
    break;

  case 104: /* simpleDatatype: nonAtomicSimple  */
#line 431 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 3133 "y.tab.c"
    break;

  case 105: /* simpleDatatype: atomicSimple  */
#line 437 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 3143 "y.tab.c"
    break;

  case 106: /* simpleDatatype: NUDATATYPE  */
#line 443 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = false; 
                            (yyval.attr).is_atomic = false;
                     }
#line 3153 "y.tab.c"
    break;

  case 107: /* simpleDatatype: ATOMIC AUDATATYPE  */
#line 450 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[-1].attr).datatype);
                            (yyval.attr).is_array = false; 
                            (yyval.attr).is_atomic = true;
                     }
#line 3163 "y.tab.c"
    break;

  case 108: /* arrayDatatype: nonAtomicArray  */
#line 458 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 3173 "y.tab.c"
    break;

  case 109: /* arrayDatatype: atomicArray  */
#line 464 "bison.y"
                     {
                            
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 3184 "y.tab.c"
    break;

  case 110: /* arrayDatatype: ARRAY NARRUDATATYPE  */
#line 471 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[-1].attr).datatype);
                            (yyval.attr).is_array = true; 
                            (yyval.attr).is_atomic = false;
                     }
#line 3194 "y.tab.c"
    break;

  case 111: /* arrayDatatype: ATOMIC ARRAY AARRUDATATYPE  */
#line 478 "bison.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[-2].attr).datatype);
                            (yyval.attr).is_array = true; 
                            (yyval.attr).is_atomic = true;
                     }
#line 3204 "y.tab.c"
    break;

  case 112: /* $@7: %empty  */
#line 486 "bison.y"
                     {
                            // printf("%s\n",$1.datatype);
                            dt_state = ((yyvsp[0].attr).datatype);
                            array_state = (yyvsp[0].attr).is_array;
                            atomic_state = (yyvsp[0].attr).is_atomic;
                     }
#line 3215 "y.tab.c"
    break;

  case 114: /* $@8: %empty  */
#line 493 "bison.y"
                     {
                            dt_state = ((yyvsp[0].attr).datatype);
                            array_state = (yyvsp[0].attr).is_array;
                            atomic_state = (yyvsp[0].attr).is_atomic;
                     }
#line 3225 "y.tab.c"
    break;

  case 116: /* simpleList: IDENTIFIER  */
#line 501 "bison.y"
              {
                            (yyvsp[0].attr).datatype = (dt_state);
                            (yyvsp[0].attr).is_array = array_state;
                            (yyvsp[0].attr).is_atomic = atomic_state;
                            if(i_tb.searchDeclaration((yyvsp[0].attr).ID)){
                                   printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                                   return 1;
                            }
                            i_tb.addVariable((yyvsp[0].attr).ID, (yyvsp[0].attr).datatype, (yyvsp[0].attr).is_atomic, (yyvsp[0].attr).is_array);
                            i_tb.print();

                            fprintf(fpcpp, "%s", (yyvsp[0].attr).ID);
              }
#line 3243 "y.tab.c"
    break;

  case 117: /* $@9: %empty  */
#line 514 "bison.y"
                             {fprintf(fpcpp, "%s", (yyvsp[0].attr));}
#line 3249 "y.tab.c"
    break;

  case 118: /* simpleList: simpleList COMMA $@9 IDENTIFIER  */
#line 515 "bison.y"
              {
                            (yyvsp[0].attr).datatype = (dt_state);
                            (yyvsp[0].attr).is_array = array_state;
                            (yyvsp[0].attr).is_atomic = atomic_state;
                            if(i_tb.searchDeclaration((yyvsp[0].attr).ID)){
                                   printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                                   return 1;
                            }
                            i_tb.addVariable((yyvsp[0].attr).ID, (yyvsp[0].attr).datatype, (yyvsp[0].attr).is_atomic, (yyvsp[0].attr).is_array);
                            i_tb.print();

                            
                            fprintf(fpcpp, "%s", (yyvsp[0].attr).ID);
              
              }
#line 3269 "y.tab.c"
    break;

  case 119: /* $@10: %empty  */
#line 530 "bison.y"
                       { fprintf(fpcpp, "%s", (yyvsp[0].attr).ID); }
#line 3275 "y.tab.c"
    break;

  case 120: /* $@11: %empty  */
#line 530 "bison.y"
                                                           { fprintf(fpcpp, "="); }
#line 3281 "y.tab.c"
    break;

  case 121: /* simpleList: IDENTIFIER $@10 EQ $@11 RHS  */
#line 531 "bison.y"
              {
                            (yyvsp[-4].attr).datatype = (dt_state);
                            (yyvsp[-4].attr).is_array = array_state;
                            (yyvsp[-4].attr).is_atomic = atomic_state;
                            if(i_tb.searchDeclaration((yyvsp[-4].attr).ID)){
                                   printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                                   return 1;
                            }
                            if(/* DO LHS RHS check*/ true) ;

                            i_tb.addVariable((yyvsp[-4].attr).ID, (yyvsp[-4].attr).datatype, (yyvsp[-4].attr).is_atomic, (yyvsp[-4].attr).is_array);
                            i_tb.print();
                            /*
                            Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state,
                            atomic_state, Scope Level + TYPE CHECK FOR COERCIBILITY OF dt_state and
                            RHS.datatype
                            */

              }
#line 3305 "y.tab.c"
    break;

  case 122: /* $@12: %empty  */
#line 550 "bison.y"
                             {fprintf(fpcpp, ","); }
#line 3311 "y.tab.c"
    break;

  case 123: /* $@13: %empty  */
#line 550 "bison.y"
                                                                { fprintf(fpcpp, "%s", 4.ID); }
#line 3317 "y.tab.c"
    break;

  case 124: /* $@14: %empty  */
#line 550 "bison.y"
                                                                                                   { fprintf(fpcpp, "="); }
#line 3323 "y.tab.c"
    break;

  case 125: /* simpleList: simpleList COMMA $@12 IDENTIFIER $@13 EQ $@14 RHS  */
#line 551 "bison.y"
              {
                            (yyvsp[-4].attr).datatype = (dt_state);
                            (yyvsp[-4].attr).is_array = array_state;
                            (yyvsp[-4].attr).is_atomic = atomic_state;
                            if(i_tb.searchDeclaration((yyvsp[-4].attr).ID)){
                                   printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                                   return 1;
                            }
                            if(/* DO LHS RHS check*/ true) ;

                            i_tb.addVariable((yyvsp[-4].attr).ID, (yyvsp[-4].attr).datatype, (yyvsp[-4].attr).is_atomic, (yyvsp[-4].attr).is_array);
                            i_tb.print();
                            /*
                            Insert in Normal IDENTIFIER TABLE $3.ID, dt_state, array_state, atomic_state,
                            Scope Level + TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
                            */
              }
#line 3345 "y.tab.c"
    break;

  case 126: /* $@15: %empty  */
#line 570 "bison.y"
                       {fprintf(fpcpp, "%s", (yyvsp[0].attr).ID);}
#line 3351 "y.tab.c"
    break;

  case 127: /* $@16: %empty  */
#line 570 "bison.y"
                                                                 { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 3357 "y.tab.c"
    break;

  case 128: /* arrayList: IDENTIFIER $@15 SQUAREOPEN $@16 dimlist SQUARECLOSE  */
#line 571 "bison.y"
              {
                            (yyvsp[-5].attr).datatype = (dt_state);
                            (yyvsp[-5].attr).is_array = array_state;
                            (yyvsp[-5].attr).is_atomic = atomic_state;
                            if(i_tb.searchDeclaration((yyvsp[-5].attr).ID)){
                                   printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                                   return 1;
                            }

                            i_tb.addVariable((yyvsp[-5].attr).ID, (yyvsp[-5].attr).datatype, (yyvsp[-5].attr).is_atomic, (yyvsp[-5].attr).is_array);
                            i_tb.print();
                            /*
                            Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, atomic_state,
                            Scope Level
                            */
                            fprintf(fpcpp, "%s", (yyvsp[0].attr));
              }
#line 3379 "y.tab.c"
    break;

  case 129: /* $@17: %empty  */
#line 588 "bison.y"
                            {fprintf(fpcpp, "%s", (yyvsp[0].attr));}
#line 3385 "y.tab.c"
    break;

  case 130: /* $@18: %empty  */
#line 588 "bison.y"
                                                                   {fprintf(fpcpp, "%s", (yyvsp[0].attr).ID);}
#line 3391 "y.tab.c"
    break;

  case 131: /* $@19: %empty  */
#line 588 "bison.y"
                                                                                                             {fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 3397 "y.tab.c"
    break;

  case 132: /* arrayList: arrayList COMMA $@17 IDENTIFIER $@18 SQUAREOPEN $@19 dimlist SQUARECLOSE  */
#line 589 "bison.y"
              {
                            (yyvsp[-5].attr).datatype = (dt_state);
                            (yyvsp[-5].attr).is_array = array_state;
                            (yyvsp[-5].attr).is_atomic = atomic_state;
                            if(i_tb.searchDeclaration((yyvsp[-5].attr).ID)){
                                   printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                                   return 1;
                            }

                            i_tb.addVariable((yyvsp[-5].attr).ID, (yyvsp[-5].attr).datatype, (yyvsp[-5].attr).is_atomic, (yyvsp[-5].attr).is_array);
                            i_tb.print();
                            /*
                            Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, 
                            atomic_state, Scope Level
                            */
                            
                            fprintf(fpcpp, "%s", (yyvsp[0].attr));

              }
#line 3421 "y.tab.c"
    break;

  case 133: /* $@20: %empty  */
#line 608 "bison.y"
                       {fprintf(fpcpp, "%s", (yyvsp[0].attr).ID);}
#line 3427 "y.tab.c"
    break;

  case 134: /* $@21: %empty  */
#line 608 "bison.y"
                                                                 { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 3433 "y.tab.c"
    break;

  case 135: /* $@22: %empty  */
#line 608 "bison.y"
                                                                                                                   {fprintf(fpcpp, "%s", (yyvsp[0].attr));}
#line 3439 "y.tab.c"
    break;

  case 136: /* $@23: %empty  */
#line 608 "bison.y"
                                                                                                                                                  { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 3445 "y.tab.c"
    break;

  case 137: /* arrayList: IDENTIFIER $@20 SQUAREOPEN $@21 dimlist SQUARECLOSE $@22 EQ $@23 RHS  */
#line 609 "bison.y"
              {
                            (yyvsp[-9].attr).datatype = (dt_state);
                            (yyvsp[-9].attr).is_array = array_state;
                            (yyvsp[-9].attr).is_atomic = atomic_state;

                            if(i_tb.searchDeclaration((yyvsp[-9].attr).ID)){
                                   printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                                   return 1;
                            }

                            i_tb.addVariable((yyvsp[-9].attr).ID, (yyvsp[-9].attr).datatype, (yyvsp[-9].attr).is_atomic, (yyvsp[-9].attr).is_array);

                            /*
                            Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, atomic_state,
                            Scope Level + TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
                            */
              

              }
#line 3469 "y.tab.c"
    break;

  case 138: /* $@24: %empty  */
#line 628 "bison.y"
                            {fprintf(fpcpp, "%s", (yyvsp[0].attr));}
#line 3475 "y.tab.c"
    break;

  case 139: /* $@25: %empty  */
#line 628 "bison.y"
                                                                   {fprintf(fpcpp, "%s", (yyvsp[0].attr).ID);}
#line 3481 "y.tab.c"
    break;

  case 140: /* $@26: %empty  */
#line 628 "bison.y"
                                                                                                             { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 3487 "y.tab.c"
    break;

  case 141: /* $@27: %empty  */
#line 628 "bison.y"
                                                                                                                                                               {fprintf(fpcpp, "%s", (yyvsp[0].attr));}
#line 3493 "y.tab.c"
    break;

  case 142: /* $@28: %empty  */
#line 628 "bison.y"
                                                                                                                                                                                              { fprintf(fpcpp, "%s",(yyvsp[0].attr)); }
#line 3499 "y.tab.c"
    break;

  case 143: /* arrayList: arrayList COMMA $@24 IDENTIFIER $@25 SQUAREOPEN $@26 dimlist SQUARECLOSE $@27 EQ $@28 RHS  */
#line 629 "bison.y"
              {
                            (yyvsp[-9].attr).datatype = (dt_state);
                            (yyvsp[-9].attr).is_array = array_state;
                            (yyvsp[-9].attr).is_atomic = atomic_state;
                            if(i_tb.searchDeclaration((yyvsp[-9].attr).ID)){
                                   printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                                   return 1;
                            }

                            i_tb.addVariable((yyvsp[-9].attr).ID, (yyvsp[-9].attr).datatype, (yyvsp[-9].attr).is_atomic, (yyvsp[-9].attr).is_array);

                            /*
                            Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, atomic_state,
                            Scope Level + TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
                            */
              }
#line 3520 "y.tab.c"
    break;

  case 144: /* array_inValues: INTEGERLITERAL  */
#line 647 "bison.y"
                               {(yyval.attr).intVal = (yyvsp[0].attr).intVal;  fprintf(fpcpp, "%d", (yyvsp[0].attr).intVal); }
#line 3526 "y.tab.c"
    break;

  case 145: /* array_inValues: IDENTIFIER  */
#line 648 "bison.y"
                           {(yyval.attr).intVal = INT_MAX; fprintf(fpcpp, "%s", (yyvsp[0].attr).ID); }
#line 3532 "y.tab.c"
    break;

  case 146: /* $@29: %empty  */
#line 651 "bison.y"
                        { fprintf(fpcpp, "]["); }
#line 3538 "y.tab.c"
    break;

  case 149: /* LHS: IDENTIFIER  */
#line 656 "bison.y"
       {
              i_tb.searchDeclaration((yyvsp[0].attr).ID);
              /*
              Search for identifier, get it's attributes, 
              store in $1.datatype, $1.is_array, $1.is_atomic
              */

              fprintf(fpcpp, "%s", (yyvsp[0].attr).ID);
       }
#line 3552 "y.tab.c"
    break;

  case 150: /* $@30: %empty  */
#line 665 "bison.y"
                 {fprintf(fpcpp, "%s", (yyvsp[0].attr).ID);}
#line 3558 "y.tab.c"
    break;

  case 151: /* $@31: %empty  */
#line 665 "bison.y"
                                                           { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 3564 "y.tab.c"
    break;

  case 152: /* LHS: IDENTIFIER $@30 SQUAREOPEN $@31 arr_access SQUARECLOSE  */
#line 666 "bison.y"
                 {
                     /*
                     Search for identifier, get it's attributes, store
                     in $1.datatype, $1.is_array, $1.is_atomic
                     */
                     /*
                     If is_array of Identifier is false, then semantic error
                     */
                     fprintf(fpcpp, "%s", (yyvsp[0].attr));
                 }
#line 3579 "y.tab.c"
    break;

  case 153: /* LHS: access  */
#line 677 "bison.y"
    {
       /* 
       SHOULD COME BACK, THIS IS ARROW ACCESSING
       */
    }
#line 3589 "y.tab.c"
    break;

  case 156: /* $@32: %empty  */
#line 688 "bison.y"
                          { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 3595 "y.tab.c"
    break;

  case 158: /* arith_operand: IDENTIFIER  */
#line 691 "bison.y"
                          { fprintf(fpcpp, "%s", (yyvsp[0].attr).ID); }
#line 3601 "y.tab.c"
    break;

  case 159: /* arith_operand: INTEGERLITERAL  */
#line 692 "bison.y"
                               { fprintf(fpcpp, "%d", (yyvsp[0].attr).intVal); }
#line 3607 "y.tab.c"
    break;

  case 160: /* arith_operand: FLOATLITERAL  */
#line 693 "bison.y"
                             { fprintf(fpcpp, "%f", (yyvsp[0].attr).decVal); }
#line 3613 "y.tab.c"
    break;

  case 161: /* $@33: %empty  */
#line 694 "bison.y"
                          { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 3619 "y.tab.c"
    break;

  case 162: /* arith_operand: ROUNDOPEN $@33 arith_expr ROUNDCLOSE  */
#line 694 "bison.y"
                                                                               { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 3625 "y.tab.c"
    break;

  case 165: /* $@34: %empty  */
#line 702 "bison.y"
                             { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 3631 "y.tab.c"
    break;

  case 166: /* assignment_statement: LHS EQ $@34 RHS  */
#line 703 "bison.y"
                     {

                            /*
                            Type check for LHS.datatype, RHS.datatype
                            */
                     }
#line 3642 "y.tab.c"
    break;

  case 167: /* expression_statement: LHS expression_op RHS  */
#line 713 "bison.y"
                     {
                            /* 
                            SHOULD COME BACK, THERE SHOULD BE A TYPE CHECK BTW LHS.datatype, RHS.datatype. 
                            IF IT MATCHES, WILL $$.datatype BE BOOLEAN? 
                            */
                     }
#line 3653 "y.tab.c"
    break;

  case 169: /* $@35: %empty  */
#line 721 "bison.y"
                  { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 3659 "y.tab.c"
    break;

  case 170: /* exprrr: ROUNDOPEN $@35 expression_statement ROUNDCLOSE  */
#line 721 "bison.y"
                                                                                 { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 3665 "y.tab.c"
    break;

  case 171: /* log: assignment_statement SEMICOLON  */
#line 725 "bison.y"
                                    { fprintf(fpcpp, "%s", (yyvsp[0].attr)); fprintf(yyout, " : assignment statement");  }
#line 3671 "y.tab.c"
    break;

  case 172: /* log: expression_statement SEMICOLON  */
#line 726 "bison.y"
                                     { fprintf(fpcpp, "%s", (yyvsp[0].attr));  fprintf(yyout, " : expression statement");  }
#line 3677 "y.tab.c"
    break;

  case 173: /* $@36: %empty  */
#line 729 "bison.y"
              {fprintf(fpcpp, "%s", (yyvsp[0].attr).ID);}
#line 3683 "y.tab.c"
    break;

  case 174: /* $@37: %empty  */
#line 729 "bison.y"
                                                { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 3689 "y.tab.c"
    break;

  case 175: /* g: IDENTIFIER $@36 EQ $@37 RHS  */
#line 730 "bison.y"
       {
              if(i_tb.searchDeclaration((yyvsp[-4].attr).ID)){
                     printError(yylineno,VARIABLE_REDECLARATION_ERROR);
              }
              if(/* Do type check with RHS */ true){
                     i_tb.addVariable((yyvsp[-4].attr).ID,dt_state,atomic_state, array_state);
              }
              /*
              Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, atomic_state, Scope Level + 
              TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
              */
       }
#line 3706 "y.tab.c"
    break;

  case 176: /* $@38: %empty  */
#line 742 "bison.y"
           {fprintf(fpcpp, "%s", (yyvsp[0].attr));}
#line 3712 "y.tab.c"
    break;

  case 177: /* $@39: %empty  */
#line 742 "bison.y"
                                                  {fprintf(fpcpp, "%s", (yyvsp[0].attr).ID);}
#line 3718 "y.tab.c"
    break;

  case 178: /* $@40: %empty  */
#line 742 "bison.y"
                                                                                    { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 3724 "y.tab.c"
    break;

  case 179: /* g: g COMMA $@38 IDENTIFIER $@39 EQ $@40 RHS  */
#line 743 "bison.y"
       {
              if(i_tb.searchDeclaration((yyvsp[-4].attr).ID)){
                     printError(yylineno,VARIABLE_REDECLARATION_ERROR);
              }
              if(/* Do type check with RHS */ true){
                     i_tb.addVariable((yyvsp[-4].attr).ID,dt_state,atomic_state, array_state);
              }
              /*
              Insert in Normal IDENTIFIER TABLE $2.ID, dt_state, array_state, atomic_state, Scope Level + 
              TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
              */
       }
#line 3741 "y.tab.c"
    break;

  case 180: /* both_assignment: assignment_statement  */
#line 758 "bison.y"
              {
                     /*
                     NO NEED TO DO ANYTHING, THE ASSIGNMENT STATEMENT RULE TAKES CARE
                     */
              }
#line 3751 "y.tab.c"
    break;

  case 181: /* $@41: %empty  */
#line 763 "bison.y"
                            { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 3757 "y.tab.c"
    break;

  case 182: /* both_assignment: ROUNDOPEN $@41 assignment_statement ROUNDCLOSE  */
#line 763 "bison.y"
                                                                                           { fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 3763 "y.tab.c"
    break;

  case 183: /* $@42: %empty  */
#line 764 "bison.y"
                                 {
                            // printf("%s\n",$1.datatype);
                            dt_state = ((yyvsp[0].attr).datatype);
                            array_state = (yyvsp[0].attr).is_array;
                            atomic_state = (yyvsp[0].attr).is_atomic;
                     }
#line 3774 "y.tab.c"
    break;

  case 184: /* both_assignment: simpleDatatype $@42 g  */
#line 771 "bison.y"
                {
                     dt_state = NULL ;
                }
#line 3782 "y.tab.c"
    break;

  case 187: /* $@43: %empty  */
#line 780 "bison.y"
              {scopeLevel++; fprintf(fpcpp, "%s", (yyvsp[0].attr)); }
#line 3788 "y.tab.c"
    break;

  case 188: /* $@44: %empty  */
#line 780 "bison.y"
                                                                    { fprintf(fpcpp, "("); }
#line 3794 "y.tab.c"
    break;

  case 189: /* $@45: %empty  */
#line 780 "bison.y"
                                                                                                                   { fprintf(fpcpp, ";"); }
#line 3800 "y.tab.c"
    break;

  case 190: /* $@46: %empty  */
#line 780 "bison.y"
                                                                                                                                                      { fprintf(fpcpp, ";"); }
#line 3806 "y.tab.c"
    break;

  case 191: /* $@47: %empty  */
#line 780 "bison.y"
                                                                                                                                                                                                    { fprintf(fpcpp, ")"); fprintf(yyout, " : loop statement");}
#line 3812 "y.tab.c"
    break;

  case 192: /* $@48: %empty  */
#line 780 "bison.y"
                                                                                                                                                                                                                                                                           { fprintf(fpcpp, "{"); }
#line 3818 "y.tab.c"
    break;

  case 193: /* $@49: %empty  */
#line 781 "bison.y"
       {
              i_tb.deleteVariables();
              scopeLevel--;
       }
#line 3827 "y.tab.c"
    break;

  case 194: /* for_loop: FOR $@43 SQUAREOPEN $@44 both_assignment PIPE $@45 RHS PIPE $@46 exprrr SQUARECLOSE $@47 SCOPEOPEN $@48 statements $@49 SCOPECLOSE  */
#line 785 "bison.y"
       {
              fprintf(fpcpp, "}");
              /*
              RHS.datatype is coercible with boolean?
              */
              /*
              NO NEED TO DO ANYTHING EXCEPT SCOPES, THE 
              PREDICATES ARE TAKEN CARE BY ABOVE RULES
              */
       }
#line 3842 "y.tab.c"
    break;

  case 195: /* $@50: %empty  */
#line 797 "bison.y"
                   { fprintf(fpcpp, "while"); }
#line 3848 "y.tab.c"
    break;

  case 196: /* $@51: %empty  */
#line 797 "bison.y"
                                                            { fprintf(fpcpp, "("); }
#line 3854 "y.tab.c"
    break;

  case 197: /* $@52: %empty  */
#line 797 "bison.y"
                                                                                                       { fprintf(fpcpp, "}");  fprintf(yyout, " : loop statement");}
#line 3860 "y.tab.c"
    break;

  case 198: /* $@53: %empty  */
#line 797 "bison.y"
                                                                                                                                                                               { fprintf(fpcpp, "{");  scopeLevel++;}
#line 3866 "y.tab.c"
    break;

  case 199: /* $@54: %empty  */
#line 798 "bison.y"
       {
              i_tb.deleteVariables();
              scopeLevel--;
       }
#line 3875 "y.tab.c"
    break;

  case 200: /* while_loop: REPEAT $@50 SQUAREOPEN $@51 RHS SQUARECLOSE $@52 SCOPEOPEN $@53 statements $@54 SCOPECLOSE  */
#line 802 "bison.y"
       {
              /*
              RHS.datatype is coercible with boolean?
              */
              /*
              NO NEED TO DO ANYTHING EXCEPT SCOPES, THE PREDICATES ARE
              TAKEN CARE BY ABOVE RULES
              */
              { fprintf(fpcpp, "}"); } 
       }
#line 3890 "y.tab.c"
    break;

  case 202: /* $@55: %empty  */
#line 819 "bison.y"
                     { fprintf(fpcpp, "if"); }
#line 3896 "y.tab.c"
    break;

  case 203: /* $@56: %empty  */
#line 819 "bison.y"
                                                          {  fprintf(fpcpp, "(");  }
#line 3902 "y.tab.c"
    break;

  case 204: /* $@57: %empty  */
#line 819 "bison.y"
                                                                                                     {  fprintf(fpcpp, ")");  fprintf(yyout, " : conditional statement");  }
#line 3908 "y.tab.c"
    break;

  case 205: /* $@58: %empty  */
#line 819 "bison.y"
                                                                                                                                                                                       {  fprintf(fpcpp, "{");  scopeLevel++;}
#line 3914 "y.tab.c"
    break;

  case 206: /* $@59: %empty  */
#line 820 "bison.y"
       {
              i_tb.deleteVariables();
              scopeLevel--;
       }
#line 3923 "y.tab.c"
    break;

  case 207: /* $@60: %empty  */
#line 823 "bison.y"
                    {
               fprintf(fpcpp, "}"); 
       }
#line 3931 "y.tab.c"
    break;

  case 209: /* $@61: %empty  */
#line 827 "bison.y"
                   { fprintf(fpcpp, "else if"); }
#line 3937 "y.tab.c"
    break;

  case 210: /* $@62: %empty  */
#line 827 "bison.y"
                                                             { fprintf(fpcpp, "("); }
#line 3943 "y.tab.c"
    break;

  case 211: /* $@63: %empty  */
#line 827 "bison.y"
                                                                                                      {  fprintf(fpcpp, ")");  fprintf(yyout, " : conditional statement");  }
#line 3949 "y.tab.c"
    break;

  case 212: /* $@64: %empty  */
#line 827 "bison.y"
                                                                                                                                                                                        {  fprintf(fpcpp, "{");  scopeLevel++;}
#line 3955 "y.tab.c"
    break;

  case 213: /* $@65: %empty  */
#line 828 "bison.y"
       {
              i_tb.deleteVariables();
              scopeLevel--;
       }
#line 3964 "y.tab.c"
    break;

  case 214: /* $@66: %empty  */
#line 831 "bison.y"
                    {
               fprintf(fpcpp, "}"); 
       }
#line 3972 "y.tab.c"
    break;

  case 216: /* $@67: %empty  */
#line 834 "bison.y"
                 {  fprintf(fpcpp, "else");  fprintf(yyout, " : conditional statement");  }
#line 3978 "y.tab.c"
    break;

  case 217: /* $@68: %empty  */
#line 834 "bison.y"
                                                                                                      {  fprintf(fpcpp, "{");  scopeLevel++; }
#line 3984 "y.tab.c"
    break;

  case 218: /* $@69: %empty  */
#line 835 "bison.y"
       {
              i_tb.deleteVariables();
              scopeLevel--;
       }
#line 3993 "y.tab.c"
    break;

  case 219: /* extend: DEFAULT $@67 SCOPEOPEN $@68 statements $@69 SCOPECLOSE  */
#line 838 "bison.y"
                    { fprintf(fpcpp, "}"); }
#line 3999 "y.tab.c"
    break;

  case 220: /* extend: %empty  */
#line 839 "bison.y"
         {;}
#line 4005 "y.tab.c"
    break;

  case 224: /* analysis_arrays: AARRNUM  */
#line 854 "bison.y"
              {
                     /* 
                     SHOULD COME BACK, WHAT ARE THESE? 
                     */
              }
#line 4015 "y.tab.c"
    break;

  case 226: /* analyze_label: IDENTIFIER  */
#line 862 "bison.y"
              {
                     /*
                     SHOULD COME BACK, WHAT ARE THESE?
                     */
              }
#line 4025 "y.tab.c"
    break;

  case 227: /* $@70: %empty  */
#line 868 "bison.y"
                                                                                                                                   { fprintf(yyout, " : analyze statement");  }
#line 4031 "y.tab.c"
    break;

  case 228: /* analyze_statement: ANALYZE analyze_label COLON analyze_label COLON analysis_arrays COLON analysis_arrays analyze_syntax SEMICOLON $@70  */
#line 869 "bison.y"
       {
       /* 
       SHOULD COME BACK, WHAT ARE THESE? 
       */
       }
#line 4041 "y.tab.c"
    break;

  case 230: /* analyze_syntax: %empty  */
#line 876 "bison.y"
       {
              /* 
              SHOULD COME BACK, WHAT ARE THESE? 
              */
       }
#line 4051 "y.tab.c"
    break;

  case 231: /* func_invoke2: func_invoke SEMICOLON  */
#line 886 "bison.y"
                                     {  fprintf(fpcpp, ";");  fprintf(yyout, " : call statement");  }
#line 4057 "y.tab.c"
    break;

  case 232: /* $@71: %empty  */
#line 889 "bison.y"
                               { fprintf(fpcpp, "%s", (yyvsp[0].attr).ID); }
#line 4063 "y.tab.c"
    break;

  case 233: /* $@72: %empty  */
#line 889 "bison.y"
                                                                      { fprintf(fpcpp, "("); }
#line 4069 "y.tab.c"
    break;

  case 234: /* $@73: %empty  */
#line 889 "bison.y"
                                                                                                         { fprintf(fpcpp, ")"); }
#line 4075 "y.tab.c"
    break;

  case 235: /* func_invoke: INVOKE IDENTIFIER $@71 COLON $@72 arguments $@73  */
#line 890 "bison.y"
       {
              /*
              BY here list of arg_dat (list of arguement's datatypes) will be ready. 
              For all functions with name as $2.ID, type check arguements
              */
              arg_dat.clear();
       }
#line 4087 "y.tab.c"
    break;

  case 236: /* $@74: %empty  */
#line 897 "bison.y"
                               { fprintf(fpcpp, "%s", (yyvsp[0].attr).ID); }
#line 4093 "y.tab.c"
    break;

  case 237: /* $@75: %empty  */
#line 897 "bison.y"
                                                                      { fprintf(fpcpp, "("); }
#line 4099 "y.tab.c"
    break;

  case 238: /* $@76: %empty  */
#line 897 "bison.y"
                                                                                                               { fprintf(fpcpp, ")"); }
#line 4105 "y.tab.c"
    break;

  case 239: /* func_invoke: INVOKE IDENTIFIER $@74 COLON $@75 NULL_ARGS COLON $@76  */
#line 898 "bison.y"
           {
              /*
              For all functions with name as $2.ID, type check if arguements are null
              */ 
             arg_dat.clear();
           }
#line 4116 "y.tab.c"
    break;

  case 240: /* $@77: %empty  */
#line 907 "bison.y"
                            { fprintf(fpcpp, ","); }
#line 4122 "y.tab.c"
    break;

  case 241: /* arguments: arguments COMMA $@77 RHS  */
#line 908 "bison.y"
          {
              arg_dat.push_back(((yyvsp[0].attr).datatype));
          }
#line 4130 "y.tab.c"
    break;

  case 242: /* arguments: RHS  */
#line 912 "bison.y"
          {
              arg_dat.push_back(((yyvsp[0].attr).datatype));
          }
#line 4138 "y.tab.c"
    break;

  case 243: /* $@78: %empty  */
#line 919 "bison.y"
                                                                                                         { fprintf(yyout, " : call statement");  }
#line 4144 "y.tab.c"
    break;

  case 244: /* task_invoke: MAKE_PARALLEL IDENTIFIER COLON arith_expr COLON arith_expr COLON arguments COLON SEMICOLON $@78  */
#line 920 "bison.y"
              {
                     /*
                     By here list of arg_dat (list of arguement's datatypes) will be ready. For all functions with name
                     as $1.ID, type check arguements
                     */
                     arg_dat.clear();
              }
#line 4156 "y.tab.c"
    break;

  case 245: /* task_invoke: MAKE_PARALLEL IDENTIFIER COLON arith_expr COLON arith_expr COLON NULL_ARGS COLON SEMICOLON  */
#line 927 "bison.y"
                                                                                                           { fprintf(yyout, " : call statement");  }
#line 4162 "y.tab.c"
    break;

  case 247: /* $@79: %empty  */
#line 934 "bison.y"
              {fprintf(fpcpp,"usleep");}
#line 4168 "y.tab.c"
    break;

  case 248: /* $@80: %empty  */
#line 934 "bison.y"
                                                   {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4174 "y.tab.c"
    break;

  case 249: /* $@81: %empty  */
#line 934 "bison.y"
                                                                                                {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4180 "y.tab.c"
    break;

  case 250: /* $@82: %empty  */
#line 934 "bison.y"
                                                                                                                                           {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4186 "y.tab.c"
    break;

  case 251: /* sleep: SLEEP $@79 ROUNDOPEN $@80 FLOATLITERAL $@81 ROUNDCLOSE $@82 SEMICOLON  */
#line 934 "bison.y"
                                                                                                                                                                                     {fprintf(fpcpp,"%s",(yyvsp[0].attr).token); fprintf(yyout, " : sleep statement");  }
#line 4192 "y.tab.c"
    break;

  case 252: /* $@83: %empty  */
#line 935 "bison.y"
               {fprintf(fpcpp,"usleep");}
#line 4198 "y.tab.c"
    break;

  case 253: /* $@84: %empty  */
#line 935 "bison.y"
                                                    {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4204 "y.tab.c"
    break;

  case 254: /* $@85: %empty  */
#line 935 "bison.y"
                                                                                                   {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4210 "y.tab.c"
    break;

  case 255: /* $@86: %empty  */
#line 935 "bison.y"
                                                                                                                                              {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4216 "y.tab.c"
    break;

  case 256: /* sleep: SLEEP $@83 ROUNDOPEN $@84 INTEGERLITERAL $@85 ROUNDCLOSE $@86 SEMICOLON  */
#line 935 "bison.y"
                                                                                                                                                                                        {fprintf(fpcpp,"%s",(yyvsp[0].attr).token); fprintf(yyout, " : sleep statement");  }
#line 4222 "y.tab.c"
    break;

  case 257: /* $@87: %empty  */
#line 938 "bison.y"
                  {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4228 "y.tab.c"
    break;

  case 258: /* file_name: ARROW $@87 STRINGLITERAL  */
#line 938 "bison.y"
                                                                {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4234 "y.tab.c"
    break;

  case 259: /* $@88: %empty  */
#line 939 "bison.y"
                  {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4240 "y.tab.c"
    break;

  case 260: /* file_name: ARROW $@88 IDENTIFIER  */
#line 939 "bison.y"
                                                             {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4246 "y.tab.c"
    break;

  case 261: /* file_name: %empty  */
#line 940 "bison.y"
            {;}
#line 4252 "y.tab.c"
    break;

  case 263: /* $@89: %empty  */
#line 947 "bison.y"
                          {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4258 "y.tab.c"
    break;

  case 265: /* $@90: %empty  */
#line 948 "bison.y"
                 {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4264 "y.tab.c"
    break;

  case 266: /* nextip: SEMICOLON $@90  */
#line 949 "bison.y"
     { 
      fprintf(yyout, " : scan statement");
     }
#line 4272 "y.tab.c"
    break;

  case 267: /* stringvalues: STRINGLITERAL  */
#line 954 "bison.y"
                             {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4278 "y.tab.c"
    break;

  case 268: /* stringvalues: IDENTIFIER  */
#line 955 "bison.y"
                          {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4284 "y.tab.c"
    break;

  case 269: /* $@91: %empty  */
#line 959 "bison.y"
                          {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4290 "y.tab.c"
    break;

  case 270: /* return_statement: RETURN $@91 RHS SEMICOLON  */
#line 959 "bison.y"
                                                                        {fprintf(fpcpp,"%s",(yyvsp[0].attr).token); (yyval.attr).datatype = (yyvsp[-1].attr).datatype; (yyval.attr).is_array = (yyvsp[-1].attr).is_array; /*Atomics not needed here ig*/ /*TYPE CHECK WITH LAST FUNCTION'S RETURN DATATYPE AND THIS DATATYPE*/fprintf(yyout, " : return statement"); }
#line 4296 "y.tab.c"
    break;

  case 271: /* $@92: %empty  */
#line 960 "bison.y"
                          {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4302 "y.tab.c"
    break;

  case 272: /* return_statement: RETURN $@92 NVOID SEMICOLON  */
#line 960 "bison.y"
                                                                          {fprintf(fpcpp,"%s",(yyvsp[0].attr).token); (yyval.attr).datatype = (yyvsp[-1].attr).datatype; (yyval.attr).is_array = (yyvsp[-1].attr).is_array; /*Atomics not needed here ig*/ /*TYPE CHECK WITH LAST FUNCTION'S RETURN DATATYPE AND THIS DATATYPE*/ fprintf(yyout, " : return statement"); }
#line 4308 "y.tab.c"
    break;

  case 273: /* output: OP COLON opstring file_name SEMICOLON  */
#line 964 "bison.y"
       { 
        fprintf(yyout, " : print statement");
       }
#line 4316 "y.tab.c"
    break;

  case 276: /* nextop: %empty  */
#line 973 "bison.y"
         {;}
#line 4322 "y.tab.c"
    break;

  case 279: /* $@93: %empty  */
#line 983 "bison.y"
                                    {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4328 "y.tab.c"
    break;

  case 280: /* func_args: all_datatypes IDENTIFIER $@93  */
#line 984 "bison.y"
       {
              decl_arg_dat.push_back(((yyvsp[-2].attr).ID));
              decl_arg_is_array.push_back((yyvsp[-2].attr).is_array);
              i_tb.addVariable((yyvsp[-1].attr).ID, (yyvsp[-2].attr).datatype, (yyvsp[-2].attr).is_atomic, (yyvsp[-2].attr).is_array);
       }
#line 4338 "y.tab.c"
    break;

  case 281: /* $@94: %empty  */
#line 989 "bison.y"
                         {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4344 "y.tab.c"
    break;

  case 282: /* $@95: %empty  */
#line 989 "bison.y"
                                                                                  {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4350 "y.tab.c"
    break;

  case 283: /* func_args: func_args COMMA $@94 all_datatypes IDENTIFIER $@95  */
#line 990 "bison.y"
       {
              i_tb.addVariable((yyvsp[-1].attr).ID, (yyvsp[-2].attr).datatype, (yyvsp[-2].attr).is_atomic, (yyvsp[-2].attr).is_array);
              decl_arg_is_array.push_back((yyvsp[-2].attr).is_array);
              decl_arg_dat.push_back(((yyvsp[-2].attr).ID));
       }
#line 4360 "y.tab.c"
    break;

  case 286: /* func_return: nonAtomic_datatypes  */
#line 1002 "bison.y"
              {
                     (yyval.attr).datatype = ((yyvsp[0].attr).datatype); 
                     (yyval.attr).is_array = (yyvsp[0].attr).is_array; 
                     /*Atomic is not needed*/
              }
#line 4370 "y.tab.c"
    break;

  case 287: /* func_return: NUDATATYPE  */
#line 1008 "bison.y"
            {
              (yyval.attr).datatype = ((yyvsp[0].attr).datatype); 
              (yyval.attr).is_array = (yyvsp[0].attr).is_array; 
              /*Atomic is not needed*/
            }
#line 4380 "y.tab.c"
    break;

  case 288: /* func_return: IDENTIFIER  */
#line 1013 "bison.y"
                         {{printf("TYPE NOT DECLARED, %d\n", yylineno); return 1;};}
#line 4386 "y.tab.c"
    break;

  case 289: /* $@96: %empty  */
#line 1016 "bison.y"
                                  { fprintf(fpcpp,"%s",(yyvsp[0].attr).datatype); fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4392 "y.tab.c"
    break;

  case 290: /* $@97: %empty  */
#line 1016 "bison.y"
                                                                                                          {fprintf(fpcpp,"{");}
#line 4398 "y.tab.c"
    break;

  case 291: /* $@98: %empty  */
#line 1016 "bison.y"
                                                                                                                                           {fprintf(fpcpp,"}");}
#line 4404 "y.tab.c"
    break;

  case 292: /* func_decl: FUNC IDENTIFIER $@96 COLON $@97 args COLON $@98 func_return  */
#line 1017 "bison.y"
              { 
                     /*
                     Add args as they are encountered in the id_table, IN FUNCTIONS TABLE, name of the function
                     is $2.ID decl_arg_dats will be ready, return_type is $6.datatype, $6.is_array 
                     */ 
              //       if(f_tb.searchFunction($2.ID, decl_arg_dat,decl_arg_is_array) == ""){
              //        f_tb.addFunction($2.ID, decl_arg_dat, decl_arg_is_array,$6.datatype, $6.is_array, 0);
              //        decl_arg_dat.clear(); fprintf(yyout, " : function declaration statement");
              //       }else {
              //        printError(yylineno, FUNCTION_REDECLARATION_ERROR);
              //        decl_arg_dat.clear(); fprintf(yyout, " : function declaration statement");
              //       }
                     
              }
#line 4423 "y.tab.c"
    break;

  case 293: /* $@99: %empty  */
#line 1032 "bison.y"
                                            { fprintf(fpcpp,"%s",(yyvsp[0].attr).datatype); fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4429 "y.tab.c"
    break;

  case 294: /* $@100: %empty  */
#line 1032 "bison.y"
                                                                                                                    {fprintf(fpcpp,"(");}
#line 4435 "y.tab.c"
    break;

  case 295: /* $@101: %empty  */
#line 1032 "bison.y"
                                                                                                                                                     {fprintf(fpcpp,")");}
#line 4441 "y.tab.c"
    break;

  case 296: /* atomic_func_decl: ATOMIC FUNC IDENTIFIER $@99 COLON $@100 args COLON $@101 func_return  */
#line 1033 "bison.y"
                     { 
                            /*
                            Add args as they are encountered in the id_table, decl_arg_dats will be ready, return_type
                            is $6.datatype, $6.is_array 
                            */ 
                            // if(f_tb.searchFunction($2.ID, decl_arg_dat,decl_arg_is_array) == ""){
                            //        f_tb.addFunction($2.ID, decl_arg_dat, decl_arg_is_array , $6.datatype, $6.is_array, 1);
                            //        decl_arg_dat.clear(); fprintf(yyout, " : function declaration statement");
                            // }else {                        
                            //        printError(yylineno, FUNCTION_REDECLARATION_ERROR);
                            //        decl_arg_dat.clear(); fprintf(yyout, " : function declaration statement");
                            // }
                     }
#line 4459 "y.tab.c"
    break;

  case 297: /* $@102: %empty  */
#line 1048 "bison.y"
                      { fprintf(fpcpp,"{"); scopeLevel++;}
#line 4465 "y.tab.c"
    break;

  case 298: /* $@103: %empty  */
#line 1049 "bison.y"
       {
              i_tb.deleteVariables();
              scopeLevel--;
       }
#line 4474 "y.tab.c"
    break;

  case 299: /* func_body: SCOPEOPEN $@102 func_statements $@103 SCOPECLOSE  */
#line 1052 "bison.y"
                    {fprintf(fpcpp,"}");}
#line 4480 "y.tab.c"
    break;

  case 311: /* $@104: %empty  */
#line 1064 "bison.y"
                      {fprintf(fpcpp,"{");scopeLevel++;}
#line 4486 "y.tab.c"
    break;

  case 312: /* $@105: %empty  */
#line 1065 "bison.y"
          {
              i_tb.deleteVariables();
              scopeLevel--;
          }
#line 4495 "y.tab.c"
    break;

  case 313: /* func_scope: SCOPEOPEN $@104 func_statements $@105 SCOPECLOSE  */
#line 1068 "bison.y"
                       {fprintf(fpcpp,"}");}
#line 4501 "y.tab.c"
    break;

  case 316: /* func_statements: %empty  */
#line 1073 "bison.y"
                 {;}
#line 4507 "y.tab.c"
    break;

  case 317: /* $@106: %empty  */
#line 1077 "bison.y"
           {fprintf(fpcpp,"void ");}
#line 4513 "y.tab.c"
    break;

  case 318: /* $@107: %empty  */
#line 1077 "bison.y"
                                                {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4519 "y.tab.c"
    break;

  case 319: /* $@108: %empty  */
#line 1077 "bison.y"
                                                                                      {fprintf(fpcpp,"( int tid, ");scopeLevel++;}
#line 4525 "y.tab.c"
    break;

  case 320: /* $@109: %empty  */
#line 1077 "bison.y"
                                                                                                                                        { fprintf(fpcpp,"}");fprintf(yyout, " : task declaration statement"); }
#line 4531 "y.tab.c"
    break;

  case 321: /* $@110: %empty  */
#line 1077 "bison.y"
                                                                                                                                                                                                                          {fprintf(fpcpp,"{");}
#line 4537 "y.tab.c"
    break;

  case 322: /* $@111: %empty  */
#line 1078 "bison.y"
       {
              i_tb.deleteVariables();
              scopeLevel--;
       }
#line 4546 "y.tab.c"
    break;

  case 323: /* task: TASK $@106 IDENTIFIER $@107 COLON $@108 args $@109 SCOPEOPEN $@110 taskscope $@111 SCOPECLOSE  */
#line 1081 "bison.y"
                   {fprintf(fpcpp,"}");}
#line 4552 "y.tab.c"
    break;

  case 330: /* $@112: %empty  */
#line 1090 "bison.y"
                    {fprintf(fpcpp,"{");scopeLevel++;}
#line 4558 "y.tab.c"
    break;

  case 331: /* $@113: %empty  */
#line 1091 "bison.y"
        {
              i_tb.deleteVariables();
              scopeLevel--;
        }
#line 4567 "y.tab.c"
    break;

  case 332: /* $@114: %empty  */
#line 1094 "bison.y"
                     {fprintf(fpcpp,"}");}
#line 4573 "y.tab.c"
    break;

  case 336: /* taskscope: %empty  */
#line 1097 "bison.y"
          {;}
#line 4579 "y.tab.c"
    break;

  case 345: /* $@115: %empty  */
#line 1109 "bison.y"
                      {fprintf(fpcpp,"{"); scopeLevel++;}
#line 4585 "y.tab.c"
    break;

  case 346: /* $@116: %empty  */
#line 1110 "bison.y"
          {
              i_tb.deleteVariables();
              scopeLevel--;
          }
#line 4594 "y.tab.c"
    break;

  case 347: /* statement: SCOPEOPEN $@115 statements $@116 SCOPECLOSE  */
#line 1113 "bison.y"
                       {fprintf(fpcpp,"}");}
#line 4600 "y.tab.c"
    break;

  case 350: /* statement: BREAK SEMICOLON  */
#line 1116 "bison.y"
                            {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4606 "y.tab.c"
    break;

  case 351: /* statement: CONTINUE SEMICOLON  */
#line 1117 "bison.y"
                               {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4612 "y.tab.c"
    break;

  case 355: /* statements: %empty  */
#line 1123 "bison.y"
            {;}
#line 4618 "y.tab.c"
    break;

  case 356: /* $@117: %empty  */
#line 1127 "bison.y"
                    {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4624 "y.tab.c"
    break;

  case 357: /* $@118: %empty  */
#line 1127 "bison.y"
                                                          {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4630 "y.tab.c"
    break;

  case 358: /* access: IDENTIFIER $@117 ARROW $@118 id  */
#line 1128 "bison.y"
       {
              /*$1.datatype should be from an existing class*/ 
              t_state = ((yyvsp[-4].attr).datatype);
       }
#line 4639 "y.tab.c"
    break;

  case 359: /* $@119: %empty  */
#line 1134 "bison.y"
                    {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4645 "y.tab.c"
    break;

  case 360: /* id: IDENTIFIER $@119  */
#line 1135 "bison.y"
        {
              t_state = ((yyvsp[-1].attr).datatype); 
              (yyval.attr).datatype = ((yyvsp[-1].attr).datatype);
       }
#line 4654 "y.tab.c"
    break;

  case 361: /* $@120: %empty  */
#line 1139 "bison.y"
                  {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4660 "y.tab.c"
    break;

  case 362: /* $@121: %empty  */
#line 1139 "bison.y"
                                                             {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4666 "y.tab.c"
    break;

  case 363: /* id: id ARROW $@120 IDENTIFIER $@121  */
#line 1140 "bison.y"
       {
              t_state = ((yyvsp[-4].attr).datatype); 
              /*
                     Type check that t_state is existing in the types_set, and it has an attribute named $3.ID
              */ 
              /*
                     After the check is done, we are supposed to update the t_state to the last identifier type
              */ 
              t_state = (yyvsp[-1].attr).datatype;
       }
#line 4681 "y.tab.c"
    break;

  case 364: /* $@122: %empty  */
#line 1154 "bison.y"
                { //////////////////////////////// COMPLETED ///////////////////////////////
       fprintf(yyout, " : start declaration statement");
       fprintf(fpcpp,"%s",(yyvsp[0].attr).token);
       scopeLevel++;
       startCount++;
              if(startCount > 1){
                     printError(yylineno, START_ERROR_MORE);
                     return 1;    
              }
       }
#line 4696 "y.tab.c"
    break;

  case 365: /* $@123: %empty  */
#line 1163 "bison.y"
                   {fprintf(fpcpp,"{");}
#line 4702 "y.tab.c"
    break;

  case 366: /* $@124: %empty  */
#line 1164 "bison.y"
       {
              i_tb.deleteVariables();
              scopeLevel--;
       }
#line 4711 "y.tab.c"
    break;

  case 367: /* startdec: START $@122 SCOPEOPEN $@123 start $@124 SCOPECLOSE  */
#line 1167 "bison.y"
                    {fprintf(fpcpp,"}");}
#line 4717 "y.tab.c"
    break;

  case 377: /* $@125: %empty  */
#line 1179 "bison.y"
                 {fprintf(fpcpp,"{"); scopeLevel++;}
#line 4723 "y.tab.c"
    break;

  case 378: /* $@126: %empty  */
#line 1180 "bison.y"
     {
       i_tb.deleteVariables();
       scopeLevel--;
     }
#line 4732 "y.tab.c"
    break;

  case 379: /* $@127: %empty  */
#line 1183 "bison.y"
                  {fprintf(fpcpp,"}");}
#line 4738 "y.tab.c"
    break;

  case 383: /* start: %empty  */
#line 1186 "bison.y"
       {;}
#line 4744 "y.tab.c"
    break;

  case 384: /* $@128: %empty  */
#line 1191 "bison.y"
                       {fprintf(fpcpp,"class");}
#line 4750 "y.tab.c"
    break;

  case 385: /* $@129: %empty  */
#line 1192 "bison.y"
              { 
                     // types_set.insert($2.token); 
                     fprintf(fpcpp,"%s",(yyvsp[0].attr).token);
                     if(c_tb.searchType((yyvsp[0].attr).ID)){
                            printError(yylineno,TYPE_REDECLARATION);
                            return 1;
                     }
                     curr_type = ((yyvsp[0].attr).ID);
                     fprintf(yyout, " : type declaration statement"); 

              }
#line 4766 "y.tab.c"
    break;

  case 386: /* $@130: %empty  */
#line 1202 "bison.y"
                          {fprintf(fpcpp,"{"); scopeLevel++;}
#line 4772 "y.tab.c"
    break;

  case 387: /* $@131: %empty  */
#line 1203 "bison.y"
              {
                     i_tb.deleteVariables();
                     scopeLevel--;
                     curr_type = NULL ;
              }
#line 4782 "y.tab.c"
    break;

  case 388: /* type_declaration: TYPE $@128 TYPENAME $@129 SCOPEOPEN $@130 type_scope methods $@131 SCOPECLOSE  */
#line 1207 "bison.y"
                           {fprintf(fpcpp,"}");}
#line 4788 "y.tab.c"
    break;

  case 390: /* type_scope: %empty  */
#line 1210 "bison.y"
                                       {;}
#line 4794 "y.tab.c"
    break;

  case 391: /* $@132: %empty  */
#line 1212 "bison.y"
                                            {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4800 "y.tab.c"
    break;

  case 392: /* declaration_t: declarationStmt_t SEMICOLON $@132  */
#line 1213 "bison.y"
              { 
                     fprintf(yyout, " : declaration statement"); 
              }
#line 4808 "y.tab.c"
    break;

  case 393: /* declarationStmt_t: simpleDatatype simpleList_t  */
#line 1219 "bison.y"
                     {
                            dt_state = ((yyvsp[-1].attr).datatype);
                            array_state = (yyvsp[-1].attr).is_array;
                            atomic_state = (yyvsp[-1].attr).is_atomic;
                     }
#line 4818 "y.tab.c"
    break;

  case 394: /* declarationStmt_t: arrayDatatype arrayList_t  */
#line 1225 "bison.y"
                     {
                            dt_state = ((yyvsp[-1].attr).datatype);
                            array_state = (yyvsp[-1].attr).is_array;
                            atomic_state = (yyvsp[-1].attr).is_atomic;
                     }
#line 4828 "y.tab.c"
    break;

  case 395: /* $@133: %empty  */
#line 1232 "bison.y"
                         {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4834 "y.tab.c"
    break;

  case 396: /* simpleList_t: IDENTIFIER $@133  */
#line 1233 "bison.y"
                     {
                            (yyvsp[-1].attr).datatype = (dt_state);
                            (yyvsp[-1].attr).is_array = array_state;
                            (yyvsp[-1].attr).is_atomic = atomic_state;

                            if(attr_tb.searchAttribute((yyvsp[-1].attr).ID, curr_type) == ""){
                                   attr_tb.addVariable((yyvsp[-1].attr).ID, curr_type, (yyvsp[-1].attr).datatype, (yyvsp[-1].attr).is_atomic, (yyvsp[-1].attr).is_array);
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }
                            /*
                            Insert in ATTRIBBUTES TABLE $1.ID, dt_state, array_state, atomic_state, class_name will
                            be the last one from the types_Set
                            */
                     }
#line 4855 "y.tab.c"
    break;

  case 397: /* $@134: %empty  */
#line 1249 "bison.y"
                                 {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4861 "y.tab.c"
    break;

  case 398: /* $@135: %empty  */
#line 1249 "bison.y"
                                                                            {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4867 "y.tab.c"
    break;

  case 399: /* simpleList_t: simpleList COMMA $@134 IDENTIFIER $@135  */
#line 1250 "bison.y"
                     {
                            (yyvsp[-1].attr).datatype = (dt_state);
                            (yyvsp[-1].attr).is_array = array_state;
                            (yyvsp[-1].attr).is_atomic = atomic_state;
                            if(attr_tb.searchAttribute((yyvsp[-1].attr).ID, curr_type) == ""){
                                   attr_tb.addVariable((yyvsp[-1].attr).ID, curr_type, (yyvsp[-1].attr).datatype, (yyvsp[-1].attr).is_atomic, (yyvsp[-1].attr).is_array);
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }
                            /*
                            Insert in ATTRIBUTES TABLE $3.ID, dt_state, array_state, atomic_state, class_name will
                            be the last one from the types_Set
                            */
                     }
#line 4887 "y.tab.c"
    break;

  case 400: /* $@136: %empty  */
#line 1265 "bison.y"
                           {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4893 "y.tab.c"
    break;

  case 401: /* $@137: %empty  */
#line 1265 "bison.y"
                                                              {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4899 "y.tab.c"
    break;

  case 402: /* simpleList_t: IDENTIFIER $@136 EQ $@137 RHS  */
#line 1266 "bison.y"
                     {
                            (yyvsp[-4].attr).datatype = (dt_state);
                            (yyvsp[-4].attr).is_array = array_state;
                            (yyvsp[-4].attr).is_atomic = atomic_state;

                            if(attr_tb.searchAttribute((yyvsp[-4].attr).ID, curr_type) == ""){
                                   attr_tb.addVariable((yyvsp[-4].attr).ID, curr_type, (yyvsp[-4].attr).datatype, (yyvsp[-4].attr).is_atomic, (yyvsp[-4].attr).is_array);
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }
                            /*
                            Insert in ATTRIBUTES TABLE $1.ID, dt_state, array_state, atomic_state, class_name will
                            be the last one from the types_Set + TYPE CHECK FOR COERCIBILITY OF
                            dt_state and RHS.datatype
                            */
                     }
#line 4921 "y.tab.c"
    break;

  case 403: /* $@138: %empty  */
#line 1283 "bison.y"
                                 {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4927 "y.tab.c"
    break;

  case 404: /* $@139: %empty  */
#line 1283 "bison.y"
                                                                            {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4933 "y.tab.c"
    break;

  case 405: /* $@140: %empty  */
#line 1283 "bison.y"
                                                                                                               {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4939 "y.tab.c"
    break;

  case 406: /* simpleList_t: simpleList COMMA $@138 IDENTIFIER $@139 EQ $@140 RHS  */
#line 1284 "bison.y"
                     {
                            (yyvsp[-4].attr).datatype = (dt_state);
                            (yyvsp[-4].attr).is_array = array_state;
                            (yyvsp[-4].attr).is_atomic = atomic_state;

                            if(attr_tb.searchAttribute((yyvsp[-4].attr).ID, curr_type) == ""){
                                   attr_tb.addVariable((yyvsp[-4].attr).ID, curr_type, (yyvsp[-4].attr).datatype, (yyvsp[-4].attr).is_atomic, (yyvsp[-4].attr).is_array);
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }
                            /*
                            Insert in ATTRIBUTES TABLE $3.ID, dt_state, array_state, atomic_state, class_name
                            will be the last one from the types_Set+ TYPE CHECK FOR COERCIBILITY OF
                            dt_state and RHS.datatype
                            */
                     }
#line 4961 "y.tab.c"
    break;

  case 407: /* $@141: %empty  */
#line 1303 "bison.y"
                         {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4967 "y.tab.c"
    break;

  case 408: /* $@142: %empty  */
#line 1303 "bison.y"
                                                                    {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4973 "y.tab.c"
    break;

  case 409: /* $@143: %empty  */
#line 1303 "bison.y"
                                                                                                                        {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4979 "y.tab.c"
    break;

  case 410: /* arrayList_t: IDENTIFIER $@141 SQUAREOPEN $@142 dimlist SQUARECLOSE $@143  */
#line 1304 "bison.y"
                     {
                            (yyvsp[-6].attr).datatype = (dt_state);
                            (yyvsp[-6].attr).is_array = array_state;
                            (yyvsp[-6].attr).is_atomic = atomic_state;

                            if(attr_tb.searchAttribute((yyvsp[-6].attr).ID, curr_type) == ""){
                                   attr_tb.addVariable((yyvsp[-6].attr).ID, curr_type, (yyvsp[-6].attr).datatype, (yyvsp[-6].attr).is_atomic, (yyvsp[-6].attr).is_array);
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }
                            /*
                            Insert in ATTRIBUTES $1.ID, dt_state, array_state, class_name will be the
                            last one from the types_Set atomic_state
                            */
                     }
#line 5000 "y.tab.c"
    break;

  case 411: /* $@144: %empty  */
#line 1320 "bison.y"
                                {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5006 "y.tab.c"
    break;

  case 412: /* $@145: %empty  */
#line 1320 "bison.y"
                                                                           {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5012 "y.tab.c"
    break;

  case 413: /* $@146: %empty  */
#line 1320 "bison.y"
                                                                                                                      {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5018 "y.tab.c"
    break;

  case 414: /* $@147: %empty  */
#line 1320 "bison.y"
                                                                                                                                                                          {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5024 "y.tab.c"
    break;

  case 415: /* arrayList_t: arrayList COMMA $@144 IDENTIFIER $@145 SQUAREOPEN $@146 dimlist SQUARECLOSE $@147  */
#line 1321 "bison.y"
                     {
                            (yyvsp[-6].attr).datatype = (dt_state);
                            (yyvsp[-6].attr).is_array = array_state;
                            (yyvsp[-6].attr).is_atomic = atomic_state;

                            if(attr_tb.searchAttribute((yyvsp[-6].attr).ID, curr_type) == ""){
                                   attr_tb.addVariable((yyvsp[-6].attr).ID, curr_type, (yyvsp[-6].attr).datatype, (yyvsp[-6].attr).is_atomic, (yyvsp[-6].attr).is_array);
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }

                            /*
                            Insert in ATTRIBUTES TABLE $1.ID, dt_state, array_state, atomic_state, class_name 
                            will be the last one from the types_Set
                            */
                     }
#line 5046 "y.tab.c"
    break;

  case 416: /* $@148: %empty  */
#line 1338 "bison.y"
                          {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5052 "y.tab.c"
    break;

  case 417: /* $@149: %empty  */
#line 1338 "bison.y"
                                                                      {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5058 "y.tab.c"
    break;

  case 418: /* $@150: %empty  */
#line 1338 "bison.y"
                                                                                                                          {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5064 "y.tab.c"
    break;

  case 419: /* $@151: %empty  */
#line 1338 "bison.y"
                                                                                                                                                             {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5070 "y.tab.c"
    break;

  case 420: /* arrayList_t: IDENTIFIER $@148 SQUAREOPEN $@149 dimlist SQUARECLOSE $@150 EQ $@151 RHS  */
#line 1339 "bison.y"
                     {
                            (yyvsp[-9].attr).datatype = (dt_state);
                            (yyvsp[-9].attr).is_array = array_state;
                            (yyvsp[-9].attr).is_atomic = atomic_state;

                            if(attr_tb.searchAttribute((yyvsp[-9].attr).ID, curr_type) == ""){
                                   attr_tb.addVariable((yyvsp[-9].attr).ID, curr_type, (yyvsp[-9].attr).datatype, (yyvsp[-9].attr).is_atomic, (yyvsp[-9].attr).is_array);
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }

                            /*
                            Insert in ATTRIBUTES TABLE $1.ID, dt_state, array_state, atomic_state, class_name will be
                            the last one from the types_Set + TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
                            */
                     }
#line 5092 "y.tab.c"
    break;

  case 421: /* $@152: %empty  */
#line 1356 "bison.y"
                                {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5098 "y.tab.c"
    break;

  case 422: /* $@153: %empty  */
#line 1356 "bison.y"
                                                                           {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5104 "y.tab.c"
    break;

  case 423: /* $@154: %empty  */
#line 1356 "bison.y"
                                                                                                                      {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5110 "y.tab.c"
    break;

  case 424: /* $@155: %empty  */
#line 1356 "bison.y"
                                                                                                                                                                          {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5116 "y.tab.c"
    break;

  case 425: /* $@156: %empty  */
#line 1356 "bison.y"
                                                                                                                                                                                                            {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5122 "y.tab.c"
    break;

  case 426: /* arrayList_t: arrayList COMMA $@152 IDENTIFIER $@153 SQUAREOPEN $@154 dimlist SQUARECLOSE $@155 EQ $@156 RHS  */
#line 1357 "bison.y"
                     {
                            (yyvsp[-9].attr).datatype = (dt_state);
                            (yyvsp[-9].attr).is_array = array_state;
                            (yyvsp[-9].attr).is_atomic = atomic_state;

                            if(attr_tb.searchAttribute((yyvsp[-9].attr).ID, curr_type) == ""){
                                   attr_tb.addVariable((yyvsp[-9].attr).ID, curr_type, (yyvsp[-9].attr).datatype, (yyvsp[-9].attr).is_atomic, (yyvsp[-9].attr).is_array);
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }
                            /*
                            Insert in ATTRIBUTES TABLE $1.ID, dt_state, array_state, atomic_state, class_name will be the
                            last one from the types_Set + TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
                            */
                     }
#line 5143 "y.tab.c"
    break;

  case 428: /* methods: %empty  */
#line 1376 "bison.y"
         {;}
#line 5149 "y.tab.c"
    break;

  case 429: /* $@157: %empty  */
#line 1379 "bison.y"
                              {fprintf(fpcpp,"{");}
#line 5155 "y.tab.c"
    break;

  case 430: /* $@158: %empty  */
#line 1380 "bison.y"
       {
              i_tb.deleteVariables();
              scopeLevel--;
       }
#line 5164 "y.tab.c"
    break;

  case 431: /* method: func_decl_m SCOPEOPEN $@157 method_body $@158 SCOPECLOSE  */
#line 1383 "bison.y"
                    {fprintf(fpcpp,"}");}
#line 5170 "y.tab.c"
    break;

  case 432: /* $@159: %empty  */
#line 1385 "bison.y"
                              { fprintf(fpcpp,"%s",(yyvsp[0].attr).datatype); fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5176 "y.tab.c"
    break;

  case 433: /* $@160: %empty  */
#line 1385 "bison.y"
                                                                                                       {fprintf(fpcpp,"(");scopeLevel++;}
#line 5182 "y.tab.c"
    break;

  case 434: /* $@161: %empty  */
#line 1385 "bison.y"
                                                                                                                                                     {fprintf(fpcpp,")");}
#line 5188 "y.tab.c"
    break;

  case 435: /* func_decl_m: FUNC IDENTIFIER $@159 COLON $@160 args COLON $@161 func_return  */
#line 1386 "bison.y"
              { 
              /*
              Add args as they are encountered in the IDENTIFIER TABLE, 
              IN METHODS TABLE: $2.ID is method name, decl_arg_dats will be ready, 
              return_type is $6.datatype, $6.is_array class name will be the last element in the types_set
              */ 
                     decl_arg_dat.clear(); fprintf(yyout, " : function declaration statement"); 
              }
#line 5201 "y.tab.c"
    break;

  case 436: /* method_invoke2: method_invoke SEMICOLON  */
#line 1396 "bison.y"
                                          { fprintf(yyout, " : call statement");  fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5207 "y.tab.c"
    break;

  case 439: /* $@162: %empty  */
#line 1400 "bison.y"
                                {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5213 "y.tab.c"
    break;

  case 440: /* $@163: %empty  */
#line 1400 "bison.y"
                                                                           {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5219 "y.tab.c"
    break;

  case 441: /* $@164: %empty  */
#line 1400 "bison.y"
                                                                                                                 {fprintf(fpcpp,"(");}
#line 5225 "y.tab.c"
    break;

  case 442: /* $@165: %empty  */
#line 1400 "bison.y"
                                                                                                                                                         {fprintf(fpcpp,")");}
#line 5231 "y.tab.c"
    break;

  case 443: /* method_invoke: INVOKE id ARROW $@162 IDENTIFIER $@163 COLON $@164 method_args COLON $@165  */
#line 1401 "bison.y"
              {
                     /* 
                     Type check: $2.datatype should be a class, and $4.ID should be a function 
                     in that class
                     */ 
                     /*
                     BY here list of arg_dat (list of arguement's datatypes) will be ready. 
                     For all mthods with name as $2.ID, type check arguements
                     */
              arg_dat.clear();
              }
#line 5247 "y.tab.c"
    break;

  case 444: /* $@166: %empty  */
#line 1422 "bison.y"
             {fprintf(fpcpp,"this");}
#line 5253 "y.tab.c"
    break;

  case 445: /* $@167: %empty  */
#line 1422 "bison.y"
                                            {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5259 "y.tab.c"
    break;

  case 446: /* $@168: %empty  */
#line 1422 "bison.y"
                                                                                       {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5265 "y.tab.c"
    break;

  case 447: /* in_stmt: IN $@166 ARROW $@167 IDENTIFIER $@168  */
#line 1423 "bison.y"
       {
              /*
              In this check if $3.datatype = last element in the type set
              */
       }
#line 5275 "y.tab.c"
    break;

  case 448: /* $@169: %empty  */
#line 1428 "bison.y"
                   {fprintf(fpcpp,"this");}
#line 5281 "y.tab.c"
    break;

  case 449: /* $@170: %empty  */
#line 1428 "bison.y"
                                                  {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5287 "y.tab.c"
    break;

  case 450: /* $@171: %empty  */
#line 1428 "bison.y"
                                                                                             {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5293 "y.tab.c"
    break;

  case 451: /* $@172: %empty  */
#line 1428 "bison.y"
                                                                                                                                   {fprintf(fpcpp,"(");}
#line 5299 "y.tab.c"
    break;

  case 452: /* $@173: %empty  */
#line 1428 "bison.y"
                                                                                                                                                                         {fprintf(fpcpp,")");}
#line 5305 "y.tab.c"
    break;

  case 453: /* in_stmt: INVOKE IN $@169 ARROW $@170 IDENTIFIER $@171 COLON $@172 arguments COLON $@173  */
#line 1429 "bison.y"
       {
              /*
              In this check if $4.ID exists in the methods table whose class is last element in the types_set
               + TYPE CHECK FOR PARARMETERS AND RETURN TYPES, SAME AS FUNCTION
              */
       }
#line 5316 "y.tab.c"
    break;

  case 454: /* $@174: %empty  */
#line 1435 "bison.y"
                   {fprintf(fpcpp,"this");}
#line 5322 "y.tab.c"
    break;

  case 455: /* $@175: %empty  */
#line 1435 "bison.y"
                                                  {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5328 "y.tab.c"
    break;

  case 456: /* $@176: %empty  */
#line 1435 "bison.y"
                                                                                             {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5334 "y.tab.c"
    break;

  case 457: /* $@177: %empty  */
#line 1435 "bison.y"
                                                                                                                                   {fprintf(fpcpp,"(");}
#line 5340 "y.tab.c"
    break;

  case 458: /* $@178: %empty  */
#line 1435 "bison.y"
                                                                                                                                                                         {fprintf(fpcpp,")");}
#line 5346 "y.tab.c"
    break;

  case 459: /* in_stmt: INVOKE IN $@174 ARROW $@175 IDENTIFIER $@176 COLON $@177 NULL_ARGS COLON $@178  */
#line 1436 "bison.y"
       {
              /*
              In this check if $4.ID exists in the methods table whose class is last element in the types_set + 
              TYPE CHECK FOR PARARMETERS AND RETURN TYPES, SAME AS FUNCTION
                     */
       }
#line 5357 "y.tab.c"
    break;

  case 471: /* $@179: %empty  */
#line 1455 "bison.y"
                             {fprintf(fpcpp,"{"); scopeLevel++;}
#line 5363 "y.tab.c"
    break;

  case 472: /* $@180: %empty  */
#line 1456 "bison.y"
                 {
                     i_tb.deleteVariables();
                     scopeLevel--;
                 }
#line 5372 "y.tab.c"
    break;

  case 473: /* method_statements: SCOPEOPEN $@179 method_statements $@180 SCOPECLOSE  */
#line 1459 "bison.y"
                              {fprintf(fpcpp,"}");}
#line 5378 "y.tab.c"
    break;

  case 475: /* $@181: %empty  */
#line 1463 "bison.y"
                            {fprintf(fpcpp,"%s ",(yyvsp[0].attr).token);}
#line 5384 "y.tab.c"
    break;

  case 476: /* $@182: %empty  */
#line 1463 "bison.y"
                                                                            {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5390 "y.tab.c"
    break;

  case 477: /* return_statement_m: RETURN $@181 RHS SEMICOLON $@182  */
#line 1464 "bison.y"
              { 
                     (yyval.attr).datatype = (yyvsp[-2].attr).datatype; 
                     (yyval.attr).is_array = (yyvsp[-2].attr).is_array; 
                     /*
                       Atomics not needed here ig
                     */ 
                     /*
                     TYPE CHECK WITH LAST METHOD'S RETURN DATATYPE AND THIS DATATYPE
                     */
                     fprintf(yyout, " : return statement"); 
              }
#line 5406 "y.tab.c"
    break;

  case 478: /* $@183: %empty  */
#line 1475 "bison.y"
                       {fprintf(fpcpp,"%s ",(yyvsp[0].attr).token);}
#line 5412 "y.tab.c"
    break;

  case 479: /* $@184: %empty  */
#line 1475 "bison.y"
                                                                        {fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 5418 "y.tab.c"
    break;

  case 480: /* return_statement_m: RETURN $@183 NVOID SEMICOLON $@184  */
#line 1476 "bison.y"
              { 
                     (yyval.attr).datatype = (yyvsp[-2].attr).datatype; 
                     (yyval.attr).is_array = (yyvsp[-2].attr).is_array; 
                     /*
                     Atomics not needed here ig
                     */ 
                     /*
                     TYPE CHECK WITH LAST METHOD'S RETURN DATATYPE AND THIS DATATYPE
                     */ 
                     fprintf(yyout, " : return statement"); 
              }
#line 5434 "y.tab.c"
    break;

  case 482: /* method_body: %empty  */
#line 1489 "bison.y"
             {;}
#line 5440 "y.tab.c"
    break;


#line 5444 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1492 "bison.y"


void yyerror(std::string s){
  std::cout << "Syntax Error: " << s << " at line number - " << yylineno << std::endl;
}

