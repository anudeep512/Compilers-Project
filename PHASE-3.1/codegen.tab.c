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
#line 1 "codegen.y"

  #include <iostream>
  #include <string>
  #include <fstream>
  #include <climits> 
  #include "codegen.hpp"
  #include <string.h>

  extern int yylex();
  extern int yylineno;
  extern FILE * yyout, *fpcpp;
  void yyerror(std::string s);
  char * dt_state ;
  int array_state;
  int atomic_state;

  int makeParallel = -1;
  char * task_name, * num_thr, * runs;

  char * t_state ;
  char * curr_type ;

  std::vector<std::string> func_array;
  std::vector<std::string> task_array;
  std::vector<std::string> method_array;

  std::vector<char *> arg_dat; // used during invokes, will be sent to searching funcs
  std::vector<char *> decl_arg_dat; // used at declarations, will be sent to adding functions
  std::vector<int> decl_arg_is_array ;
//   std::unordered_set<char *> types_set;
//   MethodTable m_tb ;
//   FunctionTable f_tb ;
//   TaskTable t_tb ;
//   VariableTable i_tb ;
//   AttributeTable attr_tb ;
//   TypeTable c_tb ;
  int scopeLevel = 0 ;
  int startCount = 0;
  int io=0;
  int io1 = 0;
  int atm = 0;
  int arr = 0;

#line 115 "codegen.tab.c"

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

#include "codegen.tab.h"
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
  YYSYMBOL_PIPE = 56,                      /* PIPE  */
  YYSYMBOL_IDENTIFIER = 57,                /* IDENTIFIER  */
  YYSYMBOL_COMMA = 58,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 59,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 60,                     /* COLON  */
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
  YYSYMBOL_subroutine_token = 96,          /* subroutine_token  */
  YYSYMBOL_subroutine_id = 97,             /* subroutine_id  */
  YYSYMBOL_subroutine_intVal = 98,         /* subroutine_intVal  */
  YYSYMBOL_subroutine_decVal = 99,         /* subroutine_decVal  */
  YYSYMBOL_subroutine_charVal = 100,       /* subroutine_charVal  */
  YYSYMBOL_subroutine_boolVal = 101,       /* subroutine_boolVal  */
  YYSYMBOL_subroutine_stringVal = 102,     /* subroutine_stringVal  */
  YYSYMBOL_subroutine_io = 103,            /* subroutine_io  */
  YYSYMBOL_subroutine_rs = 104,            /* subroutine_rs  */
  YYSYMBOL_subroutine_fileH = 105,         /* subroutine_fileH  */
  YYSYMBOL_subroutine_fio = 106,           /* subroutine_fio  */
  YYSYMBOL_subroutine_fileC = 107,         /* subroutine_fileC  */
  YYSYMBOL_subroutine_array = 108,         /* subroutine_array  */
  YYSYMBOL_subroutine_narray = 109,        /* subroutine_narray  */
  YYSYMBOL_subr_init = 110,                /* subr_init  */
  YYSYMBOL_return_routine = 111,           /* return_routine  */
  YYSYMBOL_subroutine = 112,               /* subroutine  */
  YYSYMBOL_subroutine_roundopen = 113,     /* subroutine_roundopen  */
  YYSYMBOL_subroutine_roundclose = 114,    /* subroutine_roundclose  */
  YYSYMBOL_subroutine_openscope = 115,     /* subroutine_openscope  */
  YYSYMBOL_subroutine_closescope = 116,    /* subroutine_closescope  */
  YYSYMBOL_subr_this = 117,                /* subr_this  */
  YYSYMBOL_subr_sleep = 118,               /* subr_sleep  */
  YYSYMBOL_all_datatypes = 119,            /* all_datatypes  */
  YYSYMBOL_expression_op = 120,            /* expression_op  */
  YYSYMBOL_comparison_op = 121,            /* comparison_op  */
  YYSYMBOL_arithmetic_op = 122,            /* arithmetic_op  */
  YYSYMBOL_logical_op = 123,               /* logical_op  */
  YYSYMBOL_nonAtomic_datatypes = 124,      /* nonAtomic_datatypes  */
  YYSYMBOL_begin = 125,                    /* begin  */
  YYSYMBOL_E = 126,                        /* E  */
  YYSYMBOL_127_1 = 127,                    /* $@1  */
  YYSYMBOL_T = 128,                        /* T  */
  YYSYMBOL_all_ops = 129,                  /* all_ops  */
  YYSYMBOL_constants = 130,                /* constants  */
  YYSYMBOL_next = 131,                     /* next  */
  YYSYMBOL_RHS = 132,                      /* RHS  */
  YYSYMBOL_133_2 = 133,                    /* $@2  */
  YYSYMBOL_nonAtomicSimple = 134,          /* nonAtomicSimple  */
  YYSYMBOL_atomicSimple = 135,             /* atomicSimple  */
  YYSYMBOL_nonAtomicArray = 136,           /* nonAtomicArray  */
  YYSYMBOL_atomicArray = 137,              /* atomicArray  */
  YYSYMBOL_errorDatatypes = 138,           /* errorDatatypes  */
  YYSYMBOL_declaration = 139,              /* declaration  */
  YYSYMBOL_simpleDatatype = 140,           /* simpleDatatype  */
  YYSYMBOL_arrayDatatype = 141,            /* arrayDatatype  */
  YYSYMBOL_declarationStmt = 142,          /* declarationStmt  */
  YYSYMBOL_143_3 = 143,                    /* $@3  */
  YYSYMBOL_144_4 = 144,                    /* $@4  */
  YYSYMBOL_simpleList = 145,               /* simpleList  */
  YYSYMBOL_arrayList = 146,                /* arrayList  */
  YYSYMBOL_array_inValues = 147,           /* array_inValues  */
  YYSYMBOL_dimlist = 148,                  /* dimlist  */
  YYSYMBOL_149_5 = 149,                    /* $@5  */
  YYSYMBOL_LHS = 150,                      /* LHS  */
  YYSYMBOL_arr_access = 151,               /* arr_access  */
  YYSYMBOL_subroutine_dim = 152,           /* subroutine_dim  */
  YYSYMBOL_exprlist = 153,                 /* exprlist  */
  YYSYMBOL_arith_operand = 154,            /* arith_operand  */
  YYSYMBOL_arith_expr = 155,               /* arith_expr  */
  YYSYMBOL_assignment_statement = 156,     /* assignment_statement  */
  YYSYMBOL_expression_statement = 157,     /* expression_statement  */
  YYSYMBOL_158_6 = 158,                    /* $@6  */
  YYSYMBOL_exprrr = 159,                   /* exprrr  */
  YYSYMBOL_log = 160,                      /* log  */
  YYSYMBOL_g = 161,                        /* g  */
  YYSYMBOL_both_assignment = 162,          /* both_assignment  */
  YYSYMBOL_163_7 = 163,                    /* $@7  */
  YYSYMBOL_loop = 164,                     /* loop  */
  YYSYMBOL_for_loop = 165,                 /* for_loop  */
  YYSYMBOL_166_8 = 166,                    /* $@8  */
  YYSYMBOL_167_9 = 167,                    /* $@9  */
  YYSYMBOL_168_10 = 168,                   /* $@10  */
  YYSYMBOL_169_11 = 169,                   /* $@11  */
  YYSYMBOL_170_12 = 170,                   /* $@12  */
  YYSYMBOL_while_loop = 171,               /* while_loop  */
  YYSYMBOL_172_13 = 172,                   /* $@13  */
  YYSYMBOL_173_14 = 173,                   /* $@14  */
  YYSYMBOL_174_15 = 174,                   /* $@15  */
  YYSYMBOL_175_16 = 175,                   /* $@16  */
  YYSYMBOL_conditional = 176,              /* conditional  */
  YYSYMBOL_when_statement = 177,           /* when_statement  */
  YYSYMBOL_178_17 = 178,                   /* $@17  */
  YYSYMBOL_179_18 = 179,                   /* $@18  */
  YYSYMBOL_180_19 = 180,                   /* $@19  */
  YYSYMBOL_181_20 = 181,                   /* $@20  */
  YYSYMBOL_extend = 182,                   /* extend  */
  YYSYMBOL_183_21 = 183,                   /* $@21  */
  YYSYMBOL_184_22 = 184,                   /* $@22  */
  YYSYMBOL_185_23 = 185,                   /* $@23  */
  YYSYMBOL_186_24 = 186,                   /* $@24  */
  YYSYMBOL_187_25 = 187,                   /* $@25  */
  YYSYMBOL_188_26 = 188,                   /* $@26  */
  YYSYMBOL_189_27 = 189,                   /* $@27  */
  YYSYMBOL_analyze_label = 190,            /* analyze_label  */
  YYSYMBOL_analyze_statement = 191,        /* analyze_statement  */
  YYSYMBOL_192_28 = 192,                   /* $@28  */
  YYSYMBOL_193_29 = 193,                   /* $@29  */
  YYSYMBOL_194_30 = 194,                   /* $@30  */
  YYSYMBOL_195_31 = 195,                   /* $@31  */
  YYSYMBOL_196_32 = 196,                   /* $@32  */
  YYSYMBOL_func_invoke2 = 197,             /* func_invoke2  */
  YYSYMBOL_func_invoke = 198,              /* func_invoke  */
  YYSYMBOL_arguments = 199,                /* arguments  */
  YYSYMBOL_task_invoke_args = 200,         /* task_invoke_args  */
  YYSYMBOL_201_33 = 201,                   /* $@33  */
  YYSYMBOL_task_invoke = 202,              /* task_invoke  */
  YYSYMBOL_203_34 = 203,                   /* $@34  */
  YYSYMBOL_204_35 = 204,                   /* $@35  */
  YYSYMBOL_get_invoke = 205,               /* get_invoke  */
  YYSYMBOL_sleep = 206,                    /* sleep  */
  YYSYMBOL_file_name = 207,                /* file_name  */
  YYSYMBOL_input = 208,                    /* input  */
  YYSYMBOL_209_36 = 209,                   /* $@36  */
  YYSYMBOL_nextip = 210,                   /* nextip  */
  YYSYMBOL_stringvalues = 211,             /* stringvalues  */
  YYSYMBOL_return_statement = 212,         /* return_statement  */
  YYSYMBOL_output = 213,                   /* output  */
  YYSYMBOL_214_37 = 214,                   /* $@37  */
  YYSYMBOL_opstring = 215,                 /* opstring  */
  YYSYMBOL_nextop = 216,                   /* nextop  */
  YYSYMBOL_function = 217,                 /* function  */
  YYSYMBOL_func_args = 218,                /* func_args  */
  YYSYMBOL_219_38 = 219,                   /* $@38  */
  YYSYMBOL_220_39 = 220,                   /* $@39  */
  YYSYMBOL_221_40 = 221,                   /* $@40  */
  YYSYMBOL_222_41 = 222,                   /* $@41  */
  YYSYMBOL_223_42 = 223,                   /* $@42  */
  YYSYMBOL_args = 224,                     /* args  */
  YYSYMBOL_func_return = 225,              /* func_return  */
  YYSYMBOL_func_decl = 226,                /* func_decl  */
  YYSYMBOL_227_43 = 227,                   /* $@43  */
  YYSYMBOL_228_44 = 228,                   /* $@44  */
  YYSYMBOL_229_45 = 229,                   /* $@45  */
  YYSYMBOL_230_46 = 230,                   /* $@46  */
  YYSYMBOL_atomic_func_decl = 231,         /* atomic_func_decl  */
  YYSYMBOL_232_47 = 232,                   /* $@47  */
  YYSYMBOL_233_48 = 233,                   /* $@48  */
  YYSYMBOL_234_49 = 234,                   /* $@49  */
  YYSYMBOL_235_50 = 235,                   /* $@50  */
  YYSYMBOL_func_body = 236,                /* func_body  */
  YYSYMBOL_237_51 = 237,                   /* $@51  */
  YYSYMBOL_238_52 = 238,                   /* $@52  */
  YYSYMBOL_func_scope = 239,               /* func_scope  */
  YYSYMBOL_240_53 = 240,                   /* $@53  */
  YYSYMBOL_241_54 = 241,                   /* $@54  */
  YYSYMBOL_func_statements = 242,          /* func_statements  */
  YYSYMBOL_task = 243,                     /* task  */
  YYSYMBOL_244_55 = 244,                   /* $@55  */
  YYSYMBOL_245_56 = 245,                   /* $@56  */
  YYSYMBOL_246_57 = 246,                   /* $@57  */
  YYSYMBOL_247_58 = 247,                   /* $@58  */
  YYSYMBOL_248_59 = 248,                   /* $@59  */
  YYSYMBOL_taskscope = 249,                /* taskscope  */
  YYSYMBOL_250_60 = 250,                   /* $@60  */
  YYSYMBOL_251_61 = 251,                   /* $@61  */
  YYSYMBOL_statement = 252,                /* statement  */
  YYSYMBOL_253_62 = 253,                   /* $@62  */
  YYSYMBOL_254_63 = 254,                   /* $@63  */
  YYSYMBOL_statements = 255,               /* statements  */
  YYSYMBOL_subroutine_arrow = 256,         /* subroutine_arrow  */
  YYSYMBOL_access = 257,                   /* access  */
  YYSYMBOL_id = 258,                       /* id  */
  YYSYMBOL_startdec = 259,                 /* startdec  */
  YYSYMBOL_260_64 = 260,                   /* $@64  */
  YYSYMBOL_261_65 = 261,                   /* $@65  */
  YYSYMBOL_262_66 = 262,                   /* $@66  */
  YYSYMBOL_start = 263,                    /* start  */
  YYSYMBOL_264_67 = 264,                   /* $@67  */
  YYSYMBOL_265_68 = 265,                   /* $@68  */
  YYSYMBOL_subr_public = 266,              /* subr_public  */
  YYSYMBOL_type_declaration = 267,         /* type_declaration  */
  YYSYMBOL_268_69 = 268,                   /* $@69  */
  YYSYMBOL_269_70 = 269,                   /* $@70  */
  YYSYMBOL_270_71 = 270,                   /* $@71  */
  YYSYMBOL_271_72 = 271,                   /* $@72  */
  YYSYMBOL_272_73 = 272,                   /* $@73  */
  YYSYMBOL_type_scope = 273,               /* type_scope  */
  YYSYMBOL_declaration_t = 274,            /* declaration_t  */
  YYSYMBOL_declarationStmt_t = 275,        /* declarationStmt_t  */
  YYSYMBOL_simpleList_t = 276,             /* simpleList_t  */
  YYSYMBOL_arrayList_t = 277,              /* arrayList_t  */
  YYSYMBOL_methods = 278,                  /* methods  */
  YYSYMBOL_method = 279,                   /* method  */
  YYSYMBOL_280_74 = 280,                   /* $@74  */
  YYSYMBOL_func_decl_m = 281,              /* func_decl_m  */
  YYSYMBOL_282_75 = 282,                   /* $@75  */
  YYSYMBOL_283_76 = 283,                   /* $@76  */
  YYSYMBOL_284_77 = 284,                   /* $@77  */
  YYSYMBOL_285_78 = 285,                   /* $@78  */
  YYSYMBOL_method_invoke2 = 286,           /* method_invoke2  */
  YYSYMBOL_method_args = 287,              /* method_args  */
  YYSYMBOL_method_invoke = 288,            /* method_invoke  */
  YYSYMBOL_in_stmt = 289,                  /* in_stmt  */
  YYSYMBOL_method_statements = 290,        /* method_statements  */
  YYSYMBOL_291_79 = 291,                   /* $@79  */
  YYSYMBOL_292_80 = 292,                   /* $@80  */
  YYSYMBOL_return_statement_m = 293,       /* return_statement_m  */
  YYSYMBOL_method_body = 294               /* method_body  */
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
#define YYLAST   2363

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  200
/* YYNRULES -- Number of rules.  */
#define YYNRULES  401
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  847

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
       0,   112,   112,   113,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   136,   138,
     139,   141,   142,   144,   146,   148,   156,   163,   173,   180,
     187,   194,   201,   208,   215,   222,   229,   236,   243,   250,
     257,   265,   265,   265,   265,   265,   266,   266,   266,   266,
     266,   266,   267,   267,   267,   267,   267,   267,   268,   268,
     269,   269,   272,   277,   278,   279,   280,   281,   287,   288,
     288,   291,   292,   293,   296,   297,   298,   299,   302,   308,
     315,   321,   327,   335,   336,   340,   341,   342,   343,   343,
     343,   344,   345,   346,   346,   350,   357,   364,   371,   378,
     385,   394,   401,   408,   415,   422,   431,   439,   446,   453,
     460,   469,   476,   483,   490,   497,   508,   508,   508,   508,
     510,   511,   515,   521,   528,   536,   545,   552,   560,   568,
     578,   577,   584,   583,   591,   604,   620,   640,   660,   678,
     696,   716,   735,   736,   739,   739,   740,   743,   751,   761,
     769,   772,   774,   775,   778,   782,   787,   790,   793,   794,
     798,   807,   813,   813,   815,   816,   820,   821,   824,   837,
     852,   858,   864,   864,   877,   877,   880,   880,   880,   880,
     881,   880,   896,   896,   896,   897,   896,   914,   917,   917,
     917,   918,   917,   923,   923,   923,   924,   923,   928,   928,
     929,   928,   933,   949,   949,   956,   956,   956,   956,   956,
     956,   975,   978,   986,   996,  1000,  1006,  1006,  1007,  1011,
    1025,  1011,  1036,  1039,  1040,  1043,  1044,  1045,  1048,  1048,
    1052,  1053,  1059,  1060,  1064,  1066,  1070,  1070,  1077,  1080,
    1081,  1087,  1088,  1091,  1091,  1091,  1097,  1097,  1097,  1097,
    1105,  1106,  1109,  1126,  1135,  1138,  1138,  1138,  1138,  1138,
    1160,  1160,  1160,  1160,  1160,  1183,  1184,  1183,  1191,  1192,
    1193,  1194,  1195,  1196,  1197,  1198,  1199,  1199,  1199,  1200,
    1201,  1200,  1206,  1209,  1210,  1214,  1216,  1218,  1223,  1230,
    1214,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1242,
    1247,  1248,  1249,  1253,  1254,  1255,  1255,  1256,  1257,  1258,
    1259,  1260,  1261,  1262,  1261,  1266,  1267,  1268,  1269,  1270,
    1271,  1274,  1275,  1278,  1282,  1289,  1294,  1309,  1319,  1322,
    1309,  1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,
    1334,  1335,  1334,  1340,  1341,  1342,  1346,  1348,  1349,  1359,
    1360,  1365,  1348,  1374,  1374,  1376,  1382,  1388,  1396,  1413,
    1429,  1447,  1467,  1485,  1503,  1521,  1540,  1541,  1545,  1544,
    1551,  1551,  1551,  1551,  1551,  1563,  1565,  1565,  1567,  1573,
    1579,  1586,  1595,  1596,  1597,  1598,  1599,  1600,  1601,  1601,
    1602,  1603,  1604,  1605,  1606,  1607,  1606,  1610,  1613,  1619,
    1626,  1627
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
  "BOOLEANLITERAL", "FLOATLITERAL", "PIPE", "IDENTIFIER", "COMMA",
  "SEMICOLON", "COLON", "SCOPEOPEN", "SCOPECLOSE", "ROUNDOPEN",
  "ROUNDCLOSE", "SQUAREOPEN", "SQUARECLOSE", "HASH", "LEXERROR", "NNUM",
  "NDEC", "NBOOL", "NLET", "NTEXT", "NVOID", "NARRNUM", "NARRDEC",
  "NARRBOOL", "NARRLET", "NARRTEXT", "ANUM", "ADEC", "ABOOL", "ALET",
  "ATEXT", "AARRNUM", "AARRDEC", "AARRBOOL", "AARRLET", "AARRTEXT",
  "TYPENAME", "NUDATATYPE", "AUDATATYPE", "NARRUDATATYPE", "AARRUDATATYPE",
  "$accept", "subroutine_token", "subroutine_id", "subroutine_intVal",
  "subroutine_decVal", "subroutine_charVal", "subroutine_boolVal",
  "subroutine_stringVal", "subroutine_io", "subroutine_rs",
  "subroutine_fileH", "subroutine_fio", "subroutine_fileC",
  "subroutine_array", "subroutine_narray", "subr_init", "return_routine",
  "subroutine", "subroutine_roundopen", "subroutine_roundclose",
  "subroutine_openscope", "subroutine_closescope", "subr_this",
  "subr_sleep", "all_datatypes", "expression_op", "comparison_op",
  "arithmetic_op", "logical_op", "nonAtomic_datatypes", "begin", "E",
  "$@1", "T", "all_ops", "constants", "next", "RHS", "$@2",
  "nonAtomicSimple", "atomicSimple", "nonAtomicArray", "atomicArray",
  "errorDatatypes", "declaration", "simpleDatatype", "arrayDatatype",
  "declarationStmt", "$@3", "$@4", "simpleList", "arrayList",
  "array_inValues", "dimlist", "$@5", "LHS", "arr_access",
  "subroutine_dim", "exprlist", "arith_operand", "arith_expr",
  "assignment_statement", "expression_statement", "$@6", "exprrr", "log",
  "g", "both_assignment", "$@7", "loop", "for_loop", "$@8", "$@9", "$@10",
  "$@11", "$@12", "while_loop", "$@13", "$@14", "$@15", "$@16",
  "conditional", "when_statement", "$@17", "$@18", "$@19", "$@20",
  "extend", "$@21", "$@22", "$@23", "$@24", "$@25", "$@26", "$@27",
  "analyze_label", "analyze_statement", "$@28", "$@29", "$@30", "$@31",
  "$@32", "func_invoke2", "func_invoke", "arguments", "task_invoke_args",
  "$@33", "task_invoke", "$@34", "$@35", "get_invoke", "sleep",
  "file_name", "input", "$@36", "nextip", "stringvalues",
  "return_statement", "output", "$@37", "opstring", "nextop", "function",
  "func_args", "$@38", "$@39", "$@40", "$@41", "$@42", "args",
  "func_return", "func_decl", "$@43", "$@44", "$@45", "$@46",
  "atomic_func_decl", "$@47", "$@48", "$@49", "$@50", "func_body", "$@51",
  "$@52", "func_scope", "$@53", "$@54", "func_statements", "task", "$@55",
  "$@56", "$@57", "$@58", "$@59", "taskscope", "$@60", "$@61", "statement",
  "$@62", "$@63", "statements", "subroutine_arrow", "access", "id",
  "startdec", "$@64", "$@65", "$@66", "start", "$@67", "$@68",
  "subr_public", "type_declaration", "$@69", "$@70", "$@71", "$@72",
  "$@73", "type_scope", "declaration_t", "declarationStmt_t",
  "simpleList_t", "arrayList_t", "methods", "method", "$@74",
  "func_decl_m", "$@75", "$@76", "$@77", "$@78", "method_invoke2",
  "method_args", "method_invoke", "in_stmt", "method_statements", "$@79",
  "$@80", "return_statement_m", "method_body", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-653)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-366)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2239,  -653,  -653,  -653,    42,     5,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
      97,  -653,  -653,  -653,  -653,    43,  2239,  -653,  -653,    51,
    2239,    64,    64,  2239,  2239,  2239,    70,    72,    54,    -8,
    -653,  -653,  -653,  -653,  -653,   103,  -653,  -653,  -653,   106,
     108,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,   115,  -653,  -653,  -653,   116,  -653,
     121,  -653,  -653,   120,  2112,   122,  -653,   124,   146,  -653,
     123,  -653,  2079,  -653,  -653,  -653,  -653,   128,  -653,  -653,
      19,   129,  -653,  -653,   135,  -653,  -653,  2112,   256,   134,
     136,  2112,  2112,  -653,  -653,  2112,  -653,  2112,  2112,   140,
    2112,  2112,  2112,  2112,  -653,  -653,  2112,   150,  -653,   151,
    -653,  -653,   137,  -653,   153,  -653,   200,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  2079,  -653,
    -653,   145,   155,   156,   157,   164,    95,   178,  -653,   206,
     209,   209,    31,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  1409,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
     145,  1409,   210,    26,  -653,  -653,  -653,  -653,  -653,   184,
    -653,   225,   163,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,   748,  -653,   196,  -653,  -653,
    -653,  -653,   208,  -653,  -653,   197,   213,   212,  -653,  -653,
    -653,   214,   215,  -653,  -653,  2112,  1409,  -653,  -653,  -653,
    1409,  -653,  -653,  -653,   235,  -653,    52,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,   211,  -653,   145,   218,  -653,
     244,  -653,  -653,  -653,    16,   216,  2079,   509,  -653,   186,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,   227,  -653,   221,  1409,  1409,
     297,   226,  -653,  -653,  -653,   230,   236,  -653,   232,   101,
    -653,  -653,  -653,   241,    67,  -653,  -653,  -653,  -653,   283,
     268,  -653,   242,  -653,  -653,  -653,  -653,  -653,    38,  1409,
    -653,  2272,   246,  -653,  -653,  -653,  -653,  -653,  -653,   248,
     252,  -653,  -653,  -653,   179,  -653,   247,   249,   220,  -653,
    -653,  -653,   279,  -653,   260,   262,    95,  -653,  -653,   416,
    -653,  -653,  -653,   263,   102,   265,  -653,   287,  -653,  -653,
    -653,  -653,   261,   270,  -653,   174,   264,  -653,  -653,  -653,
     296,  -653,  -653,  -653,  -653,  1588,  -653,     3,   238,  -653,
     272,   275,  -653,  2272,   274,  -653,   987,  1409,    26,   300,
      26,   277,  -653,  -653,  -653,  -653,  2201,  -653,  -653,   280,
     284,  -653,   289,   292,   276,   294,   293,  -653,    85,   299,
    -653,  -653,  -653,  -653,  -653,   298,  -653,  -653,  -653,    67,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,    67,  -653,
     306,  -653,  1409,    67,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  1409,   278,  -653,
     316,  -653,  -653,   317,  -653,  -653,   332,  -653,  -653,   987,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,    36,
    -653,  -653,   307,  -653,  -653,  2201,  2201,  2201,  2201,  2201,
    2201,  2201,  -653,  2201,  -653,  -653,   312,  -653,   325,  1409,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
     110,  -653,  -653,  -653,  -653,  -653,  -653,   327,   107,  -653,
      67,  -653,  -653,  -653,  -653,  -653,  -653,  2112,  -653,   328,
     322,   323,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,   329,  1877,    55,  -653,   326,  -653,  -653,  -653,  -653,
     331,  -653,  -653,  1409,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,   333,  -653,   344,   346,  -653,
     359,  -653,   353,   398,   356,   357,   358,  -653,  1409,  -653,
    1107,  -653,  -653,  -653,  -653,  -653,   102,  -653,  -653,  -653,
     174,  -653,  -653,  -653,  -653,  -653,  -653,  1409,  -653,   361,
    -653,   362,   364,   350,  -653,  -653,   379,  -653,  2201,  -653,
    -653,  -653,  -653,  -653,   365,  -653,  -653,  -653,  1409,  -653,
    -653,  -653,  -653,  -653,   366,   363,   368,  -653,  -653,   298,
    -653,  -653,   370,  -653,  -653,  -653,  1409,   374,    26,  -653,
    -653,  -653,  1989,  -653,  -653,  -653,  -653,  -653,  1409,  -653,
      22,   373,   366,   375,  -653,  -653,  -653,  -653,  -653,  -653,
     367,   401,    65,   377,   380,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
     409,  1989,  -653,  -653,  1409,   383,  1801,  1801,  -653,   411,
    -653,   194,  -653,   382,   390,  -653,  -653,   110,  1314,  -653,
    -653,  -653,  -653,   654,  -653,  -653,  -653,   388,  -653,  -653,
     393,   395,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  1801,  -653,  -653,   421,  -653,
    -653,   280,  -653,  -653,   402,  -653,   400,   104,  1409,    56,
      26,   145,   399,   404,  1989,  1409,  -653,  2201,  -653,  -653,
    -653,  -653,   410,  -653,   412,  1409,   397,  -653,  -653,  -653,
    -653,   405,  -653,    84,   406,  -653,  -653,  -653,   417,  -653,
    -653,  -653,  -653,  1801,  -653,  1409,  -653,  -653,  -653,   414,
    -653,  -653,  -653,  1409,  -653,  -653,  -653,  -653,   415,  -653,
    -653,   171,   419,  -653,  -653,  -653,   423,   433,    58,   987,
    -653,  -653,   418,  -653,  -653,  -653,  -653,  -653,  1801,  -653,
    -653,  -653,  -653,  -653,   430,   435,  -653,  -653,  -653,  1409,
    -653,  -653,  -653,   422,  -653,   438,  1409,  -653,  -653,   432,
    1801,  -653,  -653,  -653,  -653,   437,   439,  -653,  -653,  -653,
    -653,  1801,  -653,   440,  -653,   171,  -653
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
      62,   285,   327,   347,     0,     0,   255,   116,    95,    96,
      97,    98,    99,   100,   106,   107,   108,   109,   110,   101,
     102,   103,   104,   105,   111,   112,   113,   114,   115,   124,
       0,   122,   123,   126,   127,     0,    62,   130,   132,     0,
      62,     0,     0,    62,    62,    62,     0,     0,     0,     0,
     260,   117,   125,   118,   128,     0,     1,     2,    64,     0,
       0,     2,    65,    21,   241,   242,    66,    63,    67,   286,
      21,   348,   119,   129,     0,   256,   121,     3,   131,     3,
     133,   120,   265,     0,    18,     0,   261,     0,   134,     2,
       0,     2,    17,   287,   188,   182,   176,     0,   205,    24,
       0,     0,   228,   236,     3,    21,   345,    18,     0,     0,
       0,    18,    18,   174,   175,    18,   187,    18,    18,     0,
      18,    18,    18,    18,   149,   328,    18,     0,    21,     0,
     257,     2,     0,     2,     0,    21,     0,   284,   268,   269,
     272,   274,   275,   271,   270,   278,   276,   277,    17,   266,
     282,    14,     0,     0,     0,     0,     0,     0,     3,     0,
       9,     9,   147,   340,   331,     2,     2,     2,     2,   162,
       2,     2,     0,     2,     2,   332,   334,   333,   337,   335,
     211,   336,   343,   339,   338,   329,   344,   375,   349,   262,
      14,     0,   135,     0,     3,   279,     2,   273,   283,     0,
     251,     0,     0,    15,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    15,    15,     0,   243,   250,   288,    19,
      19,    19,     0,     8,     3,     0,     2,   325,   323,    11,
      16,     0,     0,   323,     2,    18,     0,    44,    45,    42,
       0,    41,    43,     2,     0,    23,     0,    93,     4,     8,
       6,     7,     5,     3,    19,    86,    85,   161,    72,    88,
      73,    89,    90,   166,   167,     0,   346,    14,     0,   136,
       0,   142,   143,   146,     0,     0,    17,     0,    22,     0,
      27,    31,    30,    29,    33,    32,    38,    35,    34,    36,
      37,    25,    26,    39,    40,     0,   246,     0,     0,     0,
       0,     0,   203,   204,   206,     0,     0,    19,     0,     0,
     227,    10,    10,     0,     0,   341,   160,    20,    87,     0,
       0,    23,     0,    78,    82,    79,    81,    80,    18,     0,
      22,    18,     0,   258,     2,   144,     2,     2,   280,     0,
       0,   267,    28,   244,    14,    21,     0,     0,     0,     3,
       2,   172,     0,   170,     0,     0,     0,     5,     4,     0,
       3,     8,     3,     0,     0,     0,     3,   324,   155,   156,
     154,     2,     0,   150,   159,   152,     0,   163,   222,     2,
       0,    19,    69,    68,    71,     0,   330,     0,     0,   354,
       0,     0,    18,    18,     0,   263,     0,     0,     0,   138,
       0,     0,     2,   234,   245,   247,    18,    20,    20,     0,
       0,   177,     0,     0,     0,     0,     0,   215,     0,   326,
      20,    20,     3,     8,     3,    18,     2,   325,   323,     0,
       2,   151,     2,     2,     2,     2,    57,     2,     0,    22,
       0,     2,     0,     0,     2,     2,     2,     2,     2,     2,
       2,     2,    20,    77,    75,    74,    76,     0,     0,     3,
       0,   356,     3,     0,   357,   367,   350,   353,     2,     0,
     254,   253,   252,    61,    60,   259,   137,   145,     2,     0,
      22,   235,     0,    21,   302,    18,    18,    18,    18,    18,
      18,    18,   289,    18,   189,   183,     0,     3,   173,     0,
     219,   207,    20,    20,    20,     2,    20,    19,    12,    12,
       0,   232,   233,    10,   240,   238,    13,     0,     0,   148,
       0,    55,    52,    53,    54,    56,   158,    18,     3,     0,
       0,     0,    58,    59,    47,    46,    48,    49,    50,    51,
      92,     0,    84,   134,     2,     0,     2,   370,   351,   366,
       0,   355,   264,     0,     2,   281,   248,   297,   291,   292,
     294,   293,   295,   300,   296,     0,   301,     0,     0,     2,
       0,     2,     0,   216,     0,     0,     0,   213,     0,   212,
       0,   225,   226,    10,     2,    13,     0,   237,     3,     2,
     153,   342,   379,     3,    20,    70,    20,     0,     2,     0,
       2,     0,     0,     0,    21,   140,   139,   249,    18,    22,
      21,    21,   171,     2,     0,   178,   218,   220,     0,     3,
       2,     2,   214,   377,   376,     0,     0,   231,   229,    18,
     326,   157,     0,    94,    91,    83,     0,     3,     0,     3,
     371,    22,    18,     2,   298,   290,   190,   184,     0,     3,
       0,     0,   217,     0,   223,   224,    20,     3,   239,    19,
     136,   359,     0,     0,     0,   352,     2,    21,   401,   382,
     383,   386,   388,   390,   385,   384,   393,   391,   392,   397,
       0,    18,   387,   368,     0,     0,    18,    18,   168,     0,
       2,     0,   164,     0,     0,   208,   378,     0,     0,     2,
       2,     2,   372,     0,   394,     2,   400,     0,   141,    22,
       0,     0,    21,   322,   303,   304,   307,   305,   311,   309,
     310,   316,   319,   308,   315,    18,   191,   320,     0,   185,
       2,     0,    20,   221,     0,   230,     0,     0,     0,   138,
       0,    14,     0,     0,     0,     0,    22,    18,     2,     2,
     312,   321,     0,     2,     0,     0,     0,   179,     3,    20,
      20,   137,     2,     0,     0,     2,     2,   395,     0,   369,
     299,   317,   318,    18,    22,     0,    22,   169,     2,     0,
      20,   381,   380,     0,     2,   373,   399,   398,     0,     2,
     313,    18,     0,   186,   165,    21,     0,   140,   139,     0,
      22,   389,     0,   193,   198,   202,   192,     2,    18,     2,
       2,   374,   396,    22,     0,     0,   306,   180,   209,     0,
     314,    19,    21,     0,   210,   141,     0,   199,    22,     0,
      18,   181,    20,   200,   194,     0,     0,    22,    21,   201,
     195,    18,   196,     0,    22,    18,   197
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -653,   177,   950,   143,   147,  -653,  -653,  -232,  -653,  -300,
    -653,    -4,   -79,  -653,  1535,  -653,  -653,   -89,  -206,  -398,
     -68,  -319,   187,  -653,   166,  -653,  -653,  -369,  -653,  -653,
      44,  -653,  -653,  -653,   -35,  -653,   -85,  1268,  -653,  -391,
    -653,  -214,   301,  -653,     0,  -261,  -280,  -653,  -653,  -653,
     125,   130,   131,  -394,  -653,  -293,    77,  -653,  -653,    88,
    -408,  -281,  -612,  -653,  -653,   161,  -653,  -653,  -653,   175,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,   207,  -653,  -653,  -653,  -653,  -653,  -322,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,   172,    49,  -653,  -653,  -653,
    -653,  -653,   425,   943,  -547,  -653,  -653,   295,  -653,  -653,
    -653,   584,   369,   355,  -653,  -166,   -53,   403,   597,  -653,
    -653,   -94,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -186,
    -461,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,   495,  -653,  -653,  -653,  -653,  -653,  -130,  -653,  -653,
    -653,  -653,  -653,  -653,  -459,  -653,  -653,  -653,  -653,  -653,
    -652,  -220,   976,   228,  -653,  -653,  -653,  -653,   -65,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,   152,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,   607,  -653,  1158,  -618,  -200,  -653,  -653,  -653,  -143
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    76,   162,   323,   327,   325,   326,   302,   230,   363,
     309,   581,   587,   215,   281,   310,   136,   106,   298,   377,
      82,   341,   320,   157,   216,   172,   454,   438,   456,   472,
      30,   384,   443,   255,   457,   256,   541,   417,   322,    31,
      32,    33,    34,    35,   107,    37,    38,    39,    59,    60,
      78,    80,   273,   274,   398,   108,   372,   520,   373,   374,
     375,   109,   110,   240,   693,   111,   498,   354,   410,   112,
     113,   154,   499,   650,   779,   823,   114,   153,   568,   687,
     754,   115,   116,   152,   567,   686,   752,   806,   814,   836,
     841,   843,   815,   830,   835,   225,   117,   156,   356,   574,
     734,   824,   118,   119,   418,   617,   618,   120,   573,   651,
     259,   121,   231,   122,   160,   585,   425,   723,   123,   161,
     365,   515,    40,   217,   295,   404,   344,   482,   607,   218,
     475,    41,    55,    87,   190,   396,    42,    74,   129,   267,
     469,    64,    92,   199,   148,   276,   401,   149,    43,    46,
      83,   151,   297,   565,   492,   608,   685,   725,   773,   802,
     726,   308,   124,   159,    44,    47,   185,   265,   125,   235,
     376,   331,    45,    48,    85,   266,   548,   603,   392,   393,
     394,   461,   464,   466,   549,   707,   550,   602,   664,   741,
     799,   126,   625,   127,   262,   681,   744,   788,   682,   683
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,   293,    84,   137,   268,   473,   479,   352,   552,   494,
     495,   386,   364,   313,   299,   300,   455,   324,   198,   353,
     306,   518,   508,   509,   680,   458,   558,   559,   560,   561,
     562,   563,   564,   624,   566,   729,    36,   163,   692,   351,
      36,    49,   164,    36,    36,    36,   175,   176,   329,    72,
     177,   391,   178,   179,   540,   181,   182,   183,   184,   137,
     188,   186,    53,   680,    49,   233,    50,   195,   728,   728,
     390,   652,   233,   751,   335,   321,    51,   271,   473,   349,
      58,   332,   336,   272,    62,   690,    73,    66,    67,    68,
     598,   762,   138,   810,   335,    52,   234,    56,    54,    51,
      57,   359,   554,   382,   575,   576,   577,   728,   579,   158,
      61,    52,   590,   391,  -358,  -362,   352,  -363,   368,   756,
     527,   790,   369,   335,   370,    63,   680,    69,   496,   420,
     371,   700,   390,    70,    52,   432,   433,   434,   435,   436,
     437,   142,   335,   505,    71,   506,   338,   223,   138,   644,
     784,   737,   224,   361,   423,   728,   817,   200,   362,   424,
      75,   555,   505,    77,   760,    79,   201,   202,   583,   584,
     315,   589,    86,   455,    89,   442,   803,   804,   833,    91,
      93,   131,   474,   128,   130,   155,   158,   137,   133,   842,
     728,   511,  -116,   173,   192,   174,   633,   142,   634,   180,
     201,   202,   432,   433,   434,   435,   436,   437,   517,   187,
     194,   189,   728,   586,   203,   204,   205,   206,   207,   196,
     219,   220,   221,   728,   222,   208,   209,   210,   211,   212,
     166,   167,   168,   169,   170,   171,   213,   214,    81,   383,
     228,   226,   389,   229,   662,    -3,   278,   279,   203,   204,
     205,   206,   207,   139,   296,   474,   280,   304,   696,   208,
     209,   210,   211,   212,   -19,   301,   132,   140,   134,   319,
     213,   214,   307,   330,   311,   312,   138,   406,   333,   334,
     342,   337,   345,   626,   343,   357,   355,   358,   770,   360,
     645,   165,   166,   167,   168,   169,   170,   171,   366,   141,
     378,   580,   379,   465,   389,   381,   395,   402,   191,   139,
     193,   403,    52,   407,   165,   408,   411,   484,   348,   412,
     422,   428,   665,   140,   426,   142,   439,   430,   431,   459,
     441,    54,   462,   468,   757,   478,   514,   349,   811,   480,
     502,   497,   236,   237,   238,   239,   763,   241,   242,   500,
     263,   264,   501,   504,   349,   141,   547,   691,   503,   507,
     350,   781,   782,   528,   556,   513,     8,     9,    10,    11,
      12,    13,    73,   277,   544,   546,   569,    19,    20,    21,
      22,    23,   796,   571,   588,   593,   594,   144,    29,   595,
     747,   600,   604,   596,   613,   609,   484,   484,   484,   484,
     484,   484,   484,   305,   484,   610,   485,   611,   473,   615,
     616,   314,   641,   619,   643,   557,   620,   621,   637,   639,
     318,   640,   649,   656,   505,   657,  -360,   769,   416,   243,
     659,   244,  -135,   694,   834,   695,   699,   139,   691,   245,
     702,   246,   701,   144,   705,   709,   730,   146,   732,   733,
     746,   140,   748,   698,   749,   791,   753,   793,   765,   758,
     759,   778,   591,   766,  -361,   247,   785,   248,   249,   250,
     251,   252,   774,   253,   776,   795,   789,   800,   807,   254,
     813,   812,   809,   141,   828,   485,   485,   485,   485,   485,
     485,   485,  -364,   485,   820,   821,   822,  -365,   832,   837,
     838,   415,   844,   146,   414,   582,   628,   597,   380,   831,
     405,   397,   635,   399,   400,   460,   294,   143,   839,   484,
     531,   463,   243,   846,   244,   845,   526,   409,   413,   477,
     232,   735,   245,   629,   246,   658,   642,    65,   706,   197,
     514,   367,   646,   647,   767,   467,     0,     0,   429,     0,
       0,     0,     0,   668,     0,   764,   440,     0,   247,     0,
     248,   249,   250,   251,   252,     0,   253,   486,     0,     0,
       0,   144,   254,   143,     0,     0,     0,     0,     0,   481,
       0,   487,     0,   339,     0,   474,     0,     0,     0,     0,
       0,     0,   668,     0,     0,     0,     0,   713,   713,   704,
       0,     0,     0,   516,     0,     0,     0,   519,   485,   521,
     522,   523,   524,   488,   525,   826,     0,     0,   529,     0,
       0,   532,   533,   534,   535,   536,   537,   538,   539,     0,
       0,   146,     0,     0,     0,     0,   713,     0,     0,     0,
       0,     0,   669,     0,   750,   551,   486,   486,   486,   486,
     486,   486,   486,     0,   486,   553,     0,     0,   484,     0,
     487,   487,   487,   487,   487,   487,   487,   243,   487,   244,
       0,     0,     0,     0,     0,     0,   145,   245,     0,   246,
       0,   669,   578,     0,   713,     0,   714,   714,     0,   147,
       0,   673,   488,   488,   488,   488,   488,   488,   488,   150,
     488,   143,   805,   247,     0,   248,   249,   250,   251,   252,
       0,   253,     0,     0,     0,     0,     0,   254,     0,   713,
       0,   599,     0,   601,     0,   714,     0,   808,   742,     0,
     673,   606,   145,     0,     0,   718,   718,     0,     0,     0,
       0,   713,     0,     0,   669,   147,   612,   485,   614,     0,
       0,     0,   713,     0,   827,   150,   805,     0,     0,     0,
       0,   627,     0,     0,     0,     0,   631,     0,     0,   486,
     840,     0,     0,   714,   718,   636,     0,   638,     0,     0,
       0,     0,     0,   487,     0,     0,     0,     0,     0,     0,
     648,     0,     0,   673,     0,     0,     0,   654,   655,     0,
       0,     0,     0,   670,     0,     0,     0,     0,   714,     0,
       0,     0,     0,     0,     0,   488,     0,   671,     0,     0,
     684,     0,   718,    14,    15,    16,    17,    18,     0,     0,
     714,   489,     0,    24,    25,    26,    27,    28,     0,     0,
       0,   714,   670,   703,     0,     0,     0,   715,   715,   672,
       0,     0,     0,     0,     0,     0,   671,   718,     0,     0,
     145,   716,   716,     0,     0,     0,     0,   731,     0,     0,
       0,     0,     0,   147,     0,     0,   738,   739,   740,   718,
       0,     0,   745,   150,     0,     0,   715,     0,   672,     0,
     718,     0,     0,   717,   717,     0,     0,     0,     0,     0,
     716,     0,     0,     0,     0,   670,     0,   755,   486,     0,
     489,   489,   489,   489,   489,   489,   489,     0,   489,   671,
       0,     0,   487,     0,     0,   771,   772,     0,     0,     0,
     775,     0,   717,     0,   715,     0,     0,   675,     0,   783,
       0,     0,   786,   787,     0,     0,     0,     0,   716,     0,
       0,   672,     0,     0,   488,   794,     0,     0,     0,     0,
       0,   798,     0,     0,     0,     0,   801,     0,     0,   715,
       0,     0,     0,     0,     0,     0,   675,     0,     0,     0,
     717,   720,   720,   716,   816,     0,   818,   819,     0,     0,
     490,   715,     0,     0,     0,     0,     0,   677,     0,     0,
       0,     0,   715,   491,     0,   716,     0,     0,     0,     0,
       0,     0,     0,   493,     0,   717,   716,     0,     0,     0,
     720,     0,     0,     0,     0,     0,     0,    88,     0,    90,
       0,     0,     0,   489,     0,     0,   677,   717,     0,   675,
       0,   722,   722,     0,   470,     0,     0,     0,   717,     0,
       0,     0,     0,     0,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,   674,   720,   490,
     490,   490,   490,   490,   490,   490,     0,   490,   471,     0,
     722,     0,   491,   491,   491,   491,   491,   491,   491,     0,
     491,     0,   493,   493,   493,   493,   493,   493,   493,   677,
     493,     0,     0,   720,     0,     0,   674,     0,   227,     0,
       0,   719,   719,     0,     0,   258,     0,     0,     0,   623,
     243,     0,   244,     0,     0,   720,     0,     0,   722,     0,
     245,     0,   246,     0,   258,     0,   720,     0,     0,     0,
       0,     0,   270,     0,   275,     0,     0,     0,   260,     0,
     719,     0,     0,     0,     0,     0,   247,     0,   248,   249,
     250,   251,   252,   722,   253,     0,     0,   260,     0,   674,
     254,     0,   489,     0,   303,     0,     0,     0,     0,   258,
       0,     0,     0,   258,     0,   722,     0,     0,     0,     0,
       0,     0,   490,     0,     0,     0,   722,     0,   719,     0,
       0,     0,     0,   328,     0,   491,     0,     0,     0,     0,
       0,     0,   260,     0,     0,   493,   260,     0,     0,     0,
     258,     0,     0,     0,     0,     0,   676,     0,     0,     0,
       0,     0,     0,   719,     0,     0,     0,     0,     0,   678,
       0,   258,   258,     0,     0,     0,     0,     0,     0,   679,
       0,     0,     0,   260,     0,   719,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   676,   719,     0,     0,     0,
     721,   721,   258,     0,   260,   260,     0,     0,   678,     0,
       0,     0,     0,   724,   724,     0,     0,     0,   679,     0,
       0,     0,     0,   727,   727,     0,     0,     0,     0,     0,
       0,     0,   258,     0,     0,   260,     0,     0,     0,   721,
     419,     0,   421,     0,     0,     0,   427,     0,     0,     0,
       0,     0,   724,     0,     0,     0,   736,   243,   676,   244,
     261,   490,   727,     0,     0,   260,     0,   245,     0,   246,
     258,   678,     0,     0,   491,     0,     0,     0,     0,   261,
       0,   679,     0,     0,   493,     0,     0,   721,     0,     0,
       0,     0,     0,   247,     0,   248,   249,   250,   251,   252,
     724,   253,   510,   260,   512,     0,     0,   254,     0,     0,
     727,     0,     0,     0,     0,   258,     0,     0,     0,     0,
       0,     0,   721,     0,   261,     0,     0,     0,   261,     0,
     258,     0,     0,     0,     0,   724,     0,     0,     0,   543,
       0,     0,   545,     0,   721,   727,     0,     0,   260,     0,
       0,     0,   243,     0,   244,   721,     0,   724,     0,     0,
       0,     0,   245,   260,   246,   261,     0,   727,   724,     0,
     257,     0,   258,     0,     0,     0,     0,   570,   727,     0,
       0,     0,     0,     0,     0,     0,   261,   261,   247,   269,
     248,   249,   250,   251,   252,     0,   253,     0,     0,     0,
       0,     0,   254,     0,     0,   260,     0,     0,   592,     0,
       0,     0,     0,     0,     0,     0,     0,   261,     0,     0,
       0,     0,     0,     0,     0,     0,   258,     0,     0,     0,
       0,     0,     0,     0,   316,     0,     0,     0,   317,     0,
       0,     0,     0,     0,     0,     0,     0,   261,     0,     0,
       0,   258,     0,   258,     0,     0,     0,     0,     0,   260,
       0,     0,     0,     0,     0,     0,     0,     0,   630,     0,
     258,     0,     0,   632,     0,   340,     0,     0,     0,     0,
       0,     0,     0,     0,   260,   261,   260,     0,     0,     0,
       0,   258,     0,     0,     0,     0,   346,   347,     0,   653,
       0,     0,     0,   260,     0,     0,     0,     0,     0,   258,
       0,     0,     0,     0,     0,     0,     0,   661,     0,   663,
       0,   258,     0,     0,   260,     0,     0,   385,     0,   689,
     261,     0,     0,     0,     0,     0,     0,   697,     0,     0,
       0,     0,   260,     0,     0,   261,   432,   433,   434,   435,
     436,   437,     0,     0,   260,     0,     0,   258,     0,     0,
     444,   445,   446,   447,   448,   449,   450,     0,   451,     0,
       0,   258,     0,     0,     0,     0,   258,     0,     0,     0,
       0,     0,   452,     0,     0,   453,     0,   261,     0,     0,
     260,     0,     0,     0,     0,   476,     0,     0,     0,     0,
       0,     0,     0,     0,   260,     0,     0,     0,     0,   260,
       0,   258,     0,     0,     0,     0,     0,     0,   258,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   258,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   780,     0,
     530,   261,     0,     0,   260,     0,     0,     0,   258,     0,
       0,   260,     0,     0,     0,   542,   258,     0,     0,     0,
       0,   260,     0,     0,     0,     0,   261,     0,   261,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
       0,   260,     0,     0,     0,   261,     0,     0,     0,   260,
       0,     0,   258,     0,     0,     0,     0,   572,     0,   258,
       0,     0,     0,     0,     0,     0,   261,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   261,   260,     0,     0,     0,     0,
       0,     0,   260,     0,    94,    95,   261,     0,    96,   710,
     711,     0,    97,     0,     0,    98,     0,    99,     0,     0,
     196,   605,   100,     5,   245,     0,   246,   102,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   261,     0,     0,     0,   622,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   261,     0,   104,     0,
       0,   261,   712,     0,     0,   542,     0,     0,     0,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,    29,     0,     0,     0,   261,     0,     0,     0,
       0,     0,     0,   261,   660,   432,   433,   434,   435,   436,
     437,     0,     0,   261,     0,     0,   688,     0,     0,   444,
     445,   446,   447,   448,   449,   450,     0,   451,     0,     0,
       0,     0,     0,   261,     0,     0,     0,     0,     0,     0,
       0,   261,     0,     0,   453,     0,     0,     0,     0,     0,
       0,     0,   708,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   743,     0,     0,     0,     0,     0,   261,     0,     0,
       0,     0,     0,     0,   261,     0,     0,     0,     0,     0,
       0,     0,    94,    95,     0,     0,    96,     0,     0,     0,
      97,     0,     0,    98,     0,    99,   761,     0,   666,     0,
     100,     5,   245,   768,   246,   102,   103,     0,     0,     0,
       0,     0,     0,   777,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   792,     0,     0,   104,     0,     0,     0,
     667,   797,     0,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
      29,     0,    94,    95,     0,     0,    96,   825,     0,     0,
      97,     0,     0,    98,   829,    99,     0,     0,     0,     0,
     100,     5,     0,     0,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,    96,
       0,     0,     0,    97,     0,     0,    98,     0,    99,     0,
       0,     0,     0,   100,     5,     0,   104,   101,   102,   103,
     135,   -18,     0,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,   104,
      29,     0,     0,   105,     0,     0,     0,     0,     0,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,    29,    94,    95,     0,     0,    96,     0,
       0,     0,     0,     0,     0,     0,     0,    99,     0,     0,
       0,     0,   100,     5,     0,     0,   101,     0,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     2,   104,     3,
       4,     5,   483,     6,     0,     0,     0,     0,     0,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,    29,   387,   388,     0,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,    29
};

static const yytype_int16 yycheck[] =
{
       0,   215,    70,    92,   190,   396,   400,   300,   469,   407,
     408,   330,   312,   233,   220,   221,   385,   249,   148,   300,
     226,   429,   420,   421,   642,    22,   485,   486,   487,   488,
     489,   490,   491,   580,   493,   687,    36,   105,   650,   300,
      40,    22,   107,    43,    44,    45,   111,   112,   254,    57,
     115,   331,   117,   118,   452,   120,   121,   122,   123,   148,
     128,   126,    57,   681,    22,    34,    24,   135,   686,   687,
     331,   618,    34,   725,    58,    23,    57,    51,   469,    57,
      36,   267,    66,    57,    40,    63,    94,    43,    44,    45,
      35,    35,    92,    35,    58,    92,    65,     0,    93,    57,
      57,   307,    66,    65,   502,   503,   504,   725,   506,    57,
      59,    92,   520,   393,    59,    59,   409,    59,    51,   731,
     439,   773,    55,    58,    57,    61,   744,    57,   409,   361,
      63,    66,   393,    61,    92,    28,    29,    30,    31,    32,
      33,    92,    58,    58,    90,    60,   276,    52,   148,   608,
      66,   698,    57,    52,    52,   773,   808,    12,    57,    57,
      57,   480,    58,    57,    60,    57,    21,    22,    58,    59,
     235,    64,    57,   542,    58,   381,     5,     6,   830,    58,
      60,    35,   396,    61,    60,    57,    57,   276,    65,   841,
     808,   423,    57,    59,    57,    59,   594,   148,   596,    59,
      21,    22,    28,    29,    30,    31,    32,    33,   428,    59,
      57,    60,   830,   513,    69,    70,    71,    72,    73,    19,
      65,    65,    65,   841,    60,    80,    81,    82,    83,    84,
      36,    37,    38,    39,    40,    41,    91,    92,    61,   328,
      34,    63,   331,    34,   638,    35,    62,    22,    69,    70,
      71,    72,    73,    92,    58,   469,    93,    60,   656,    80,
      81,    82,    83,    84,    51,    57,    89,    92,    91,    34,
      91,    92,    60,    62,    60,    60,   276,   345,    60,    35,
      94,    65,    61,   583,    57,    55,    60,    51,   747,    57,
     609,    35,    36,    37,    38,    39,    40,    41,    57,    92,
      17,   507,    34,   392,   393,    63,    60,    59,   131,   148,
     133,    59,    92,    66,    35,    66,    56,   406,    21,    57,
      57,    34,   641,   148,    59,   276,    62,    66,    58,    57,
      34,    93,    57,    59,   732,    35,   425,    57,   799,    62,
      64,    57,   165,   166,   167,   168,   740,   170,   171,    60,
     173,   174,    60,    60,    57,   148,    24,   650,    64,    60,
      63,   759,   760,    57,    57,    67,    69,    70,    71,    72,
      73,    74,    94,   196,    58,    58,    64,    80,    81,    82,
      83,    84,   780,    58,    57,    57,    64,    92,    91,    66,
     709,    65,    61,    64,    35,    62,   485,   486,   487,   488,
     489,   490,   491,   226,   493,    61,   406,    61,   799,    56,
      12,   234,    62,    57,    35,   483,    59,    59,    57,    57,
     243,    57,    57,    60,    58,    57,    59,   746,    12,    13,
      60,    15,    58,    60,   832,    60,    35,   276,   731,    23,
      60,    25,    65,   148,    35,    62,    35,    92,    66,    59,
      62,   276,    59,   659,    59,   774,    35,   776,    59,    57,
      60,    64,   527,    59,    59,    49,    60,    51,    52,    53,
      54,    55,    62,    57,    62,    61,    59,    62,    59,    63,
      62,   800,    59,   276,    62,   485,   486,   487,   488,   489,
     490,   491,    59,   493,   813,    65,    61,    59,    66,    62,
      61,   358,    62,   148,   357,   509,   585,   542,   321,   828,
     344,   334,   597,   336,   337,   390,   215,    92,   837,   608,
     443,   391,    13,   845,    15,   844,   438,   350,   356,   398,
     161,   697,    23,   586,    25,   629,   604,    42,   681,   136,
     629,   313,   610,   611,   744,   393,    -1,    -1,   371,    -1,
      -1,    -1,    -1,   642,    -1,   741,   379,    -1,    49,    -1,
      51,    52,    53,    54,    55,    -1,    57,   406,    -1,    -1,
      -1,   276,    63,   148,    -1,    -1,    -1,    -1,    -1,   402,
      -1,   406,    -1,    74,    -1,   799,    -1,    -1,    -1,    -1,
      -1,    -1,   681,    -1,    -1,    -1,    -1,   686,   687,   667,
      -1,    -1,    -1,   426,    -1,    -1,    -1,   430,   608,   432,
     433,   434,   435,   406,   437,   821,    -1,    -1,   441,    -1,
      -1,   444,   445,   446,   447,   448,   449,   450,   451,    -1,
      -1,   276,    -1,    -1,    -1,    -1,   725,    -1,    -1,    -1,
      -1,    -1,   642,    -1,   712,   468,   485,   486,   487,   488,
     489,   490,   491,    -1,   493,   478,    -1,    -1,   747,    -1,
     485,   486,   487,   488,   489,   490,   491,    13,   493,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    23,    -1,    25,
      -1,   681,   505,    -1,   773,    -1,   686,   687,    -1,    92,
      -1,   642,   485,   486,   487,   488,   489,   490,   491,    92,
     493,   276,   791,    49,    -1,    51,    52,    53,    54,    55,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    63,    -1,   808,
      -1,   544,    -1,   546,    -1,   725,    -1,   795,    74,    -1,
     681,   554,   148,    -1,    -1,   686,   687,    -1,    -1,    -1,
      -1,   830,    -1,    -1,   744,   148,   569,   747,   571,    -1,
      -1,    -1,   841,    -1,   822,   148,   845,    -1,    -1,    -1,
      -1,   584,    -1,    -1,    -1,    -1,   589,    -1,    -1,   608,
     838,    -1,    -1,   773,   725,   598,    -1,   600,    -1,    -1,
      -1,    -1,    -1,   608,    -1,    -1,    -1,    -1,    -1,    -1,
     613,    -1,    -1,   744,    -1,    -1,    -1,   620,   621,    -1,
      -1,    -1,    -1,   642,    -1,    -1,    -1,    -1,   808,    -1,
      -1,    -1,    -1,    -1,    -1,   608,    -1,   642,    -1,    -1,
     643,    -1,   773,    75,    76,    77,    78,    79,    -1,    -1,
     830,   406,    -1,    85,    86,    87,    88,    89,    -1,    -1,
      -1,   841,   681,   666,    -1,    -1,    -1,   686,   687,   642,
      -1,    -1,    -1,    -1,    -1,    -1,   681,   808,    -1,    -1,
     276,   686,   687,    -1,    -1,    -1,    -1,   690,    -1,    -1,
      -1,    -1,    -1,   276,    -1,    -1,   699,   700,   701,   830,
      -1,    -1,   705,   276,    -1,    -1,   725,    -1,   681,    -1,
     841,    -1,    -1,   686,   687,    -1,    -1,    -1,    -1,    -1,
     725,    -1,    -1,    -1,    -1,   744,    -1,   730,   747,    -1,
     485,   486,   487,   488,   489,   490,   491,    -1,   493,   744,
      -1,    -1,   747,    -1,    -1,   748,   749,    -1,    -1,    -1,
     753,    -1,   725,    -1,   773,    -1,    -1,   642,    -1,   762,
      -1,    -1,   765,   766,    -1,    -1,    -1,    -1,   773,    -1,
      -1,   744,    -1,    -1,   747,   778,    -1,    -1,    -1,    -1,
      -1,   784,    -1,    -1,    -1,    -1,   789,    -1,    -1,   808,
      -1,    -1,    -1,    -1,    -1,    -1,   681,    -1,    -1,    -1,
     773,   686,   687,   808,   807,    -1,   809,   810,    -1,    -1,
     406,   830,    -1,    -1,    -1,    -1,    -1,   642,    -1,    -1,
      -1,    -1,   841,   406,    -1,   830,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   406,    -1,   808,   841,    -1,    -1,    -1,
     725,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,
      -1,    -1,    -1,   608,    -1,    -1,   681,   830,    -1,   744,
      -1,   686,   687,    -1,    57,    -1,    -1,    -1,   841,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,   642,   773,   485,
     486,   487,   488,   489,   490,   491,    -1,   493,    91,    -1,
     725,    -1,   485,   486,   487,   488,   489,   490,   491,    -1,
     493,    -1,   485,   486,   487,   488,   489,   490,   491,   744,
     493,    -1,    -1,   808,    -1,    -1,   681,    -1,   158,    -1,
      -1,   686,   687,    -1,    -1,   172,    -1,    -1,    -1,    12,
      13,    -1,    15,    -1,    -1,   830,    -1,    -1,   773,    -1,
      23,    -1,    25,    -1,   191,    -1,   841,    -1,    -1,    -1,
      -1,    -1,   192,    -1,   194,    -1,    -1,    -1,   172,    -1,
     725,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,
      53,    54,    55,   808,    57,    -1,    -1,   191,    -1,   744,
      63,    -1,   747,    -1,   224,    -1,    -1,    -1,    -1,   236,
      -1,    -1,    -1,   240,    -1,   830,    -1,    -1,    -1,    -1,
      -1,    -1,   608,    -1,    -1,    -1,   841,    -1,   773,    -1,
      -1,    -1,    -1,   253,    -1,   608,    -1,    -1,    -1,    -1,
      -1,    -1,   236,    -1,    -1,   608,   240,    -1,    -1,    -1,
     277,    -1,    -1,    -1,    -1,    -1,   642,    -1,    -1,    -1,
      -1,    -1,    -1,   808,    -1,    -1,    -1,    -1,    -1,   642,
      -1,   298,   299,    -1,    -1,    -1,    -1,    -1,    -1,   642,
      -1,    -1,    -1,   277,    -1,   830,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   681,   841,    -1,    -1,    -1,
     686,   687,   329,    -1,   298,   299,    -1,    -1,   681,    -1,
      -1,    -1,    -1,   686,   687,    -1,    -1,    -1,   681,    -1,
      -1,    -1,    -1,   686,   687,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   359,    -1,    -1,   329,    -1,    -1,    -1,   725,
     360,    -1,   362,    -1,    -1,    -1,   366,    -1,    -1,    -1,
      -1,    -1,   725,    -1,    -1,    -1,    12,    13,   744,    15,
     172,   747,   725,    -1,    -1,   359,    -1,    23,    -1,    25,
     397,   744,    -1,    -1,   747,    -1,    -1,    -1,    -1,   191,
      -1,   744,    -1,    -1,   747,    -1,    -1,   773,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    51,    52,    53,    54,    55,
     773,    57,   422,   397,   424,    -1,    -1,    63,    -1,    -1,
     773,    -1,    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,
      -1,    -1,   808,    -1,   236,    -1,    -1,    -1,   240,    -1,
     457,    -1,    -1,    -1,    -1,   808,    -1,    -1,    -1,   459,
      -1,    -1,   462,    -1,   830,   808,    -1,    -1,   442,    -1,
      -1,    -1,    13,    -1,    15,   841,    -1,   830,    -1,    -1,
      -1,    -1,    23,   457,    25,   277,    -1,   830,   841,    -1,
     172,    -1,   499,    -1,    -1,    -1,    -1,   497,   841,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   298,   299,    49,   191,
      51,    52,    53,    54,    55,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    -1,   499,    -1,    -1,   528,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   329,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   553,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,   240,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   359,    -1,    -1,
      -1,   578,    -1,   580,    -1,    -1,    -1,    -1,    -1,   553,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   588,    -1,
     597,    -1,    -1,   593,    -1,   277,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   578,   397,   580,    -1,    -1,    -1,
      -1,   618,    -1,    -1,    -1,    -1,   298,   299,    -1,   619,
      -1,    -1,    -1,   597,    -1,    -1,    -1,    -1,    -1,   636,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   637,    -1,   639,
      -1,   648,    -1,    -1,   618,    -1,    -1,   329,    -1,   649,
     442,    -1,    -1,    -1,    -1,    -1,    -1,   657,    -1,    -1,
      -1,    -1,   636,    -1,    -1,   457,    28,    29,    30,    31,
      32,    33,    -1,    -1,   648,    -1,    -1,   684,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    -1,
      -1,   698,    -1,    -1,    -1,    -1,   703,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    -1,    67,    -1,   499,    -1,    -1,
     684,    -1,    -1,    -1,    -1,   397,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   698,    -1,    -1,    -1,    -1,   703,
      -1,   738,    -1,    -1,    -1,    -1,    -1,    -1,   745,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   755,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   758,    -1,
     442,   553,    -1,    -1,   738,    -1,    -1,    -1,   775,    -1,
      -1,   745,    -1,    -1,    -1,   457,   783,    -1,    -1,    -1,
      -1,   755,    -1,    -1,    -1,    -1,   578,    -1,   580,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
      -1,   775,    -1,    -1,    -1,   597,    -1,    -1,    -1,   783,
      -1,    -1,   819,    -1,    -1,    -1,    -1,   499,    -1,   826,
      -1,    -1,    -1,    -1,    -1,    -1,   618,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   636,   819,    -1,    -1,    -1,    -1,
      -1,    -1,   826,    -1,     3,     4,   648,    -1,     7,     8,
       9,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,    -1,
      19,   553,    21,    22,    23,    -1,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   684,    -1,    -1,    -1,   578,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   698,    -1,    57,    -1,
      -1,   703,    61,    -1,    -1,   597,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    91,    -1,    -1,    -1,   738,    -1,    -1,    -1,
      -1,    -1,    -1,   745,   636,    28,    29,    30,    31,    32,
      33,    -1,    -1,   755,    -1,    -1,   648,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    -1,    -1,
      -1,    -1,    -1,   775,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   783,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   684,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   703,    -1,    -1,    -1,    -1,    -1,   819,    -1,    -1,
      -1,    -1,    -1,    -1,   826,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    -1,     7,    -1,    -1,    -1,
      11,    -1,    -1,    14,    -1,    16,   738,    -1,    19,    -1,
      21,    22,    23,   745,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,   755,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   775,    -1,    -1,    57,    -1,    -1,    -1,
      61,   783,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      91,    -1,     3,     4,    -1,    -1,     7,   819,    -1,    -1,
      11,    -1,    -1,    14,   826,    16,    -1,    -1,    -1,    -1,
      21,    22,    -1,    -1,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,     7,
      -1,    -1,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,
      -1,    -1,    -1,    21,    22,    -1,    57,    25,    26,    27,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    57,
      91,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,     3,     4,    -1,    -1,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    -1,    21,    22,    -1,    -1,    25,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    57,    20,
      21,    22,    61,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    91,    21,    22,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    10,    18,    20,    21,    22,    24,    57,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    91,
     125,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     217,   226,   231,   243,   259,   267,   244,   260,   268,    22,
      24,    57,    92,    57,    93,   227,     0,    57,   125,   143,
     144,    59,   125,    61,   236,   236,   125,   125,   125,    57,
      61,    90,    57,    94,   232,    57,    96,    57,   145,    57,
     146,    96,   115,   245,   115,   269,    57,   228,    97,    58,
      97,    58,   237,    60,     3,     4,     7,    11,    14,    16,
      21,    25,    26,    27,    57,    61,   112,   139,   150,   156,
     157,   160,   164,   165,   171,   176,   177,   191,   197,   198,
     202,   206,   208,   213,   257,   263,   286,   288,    61,   233,
      60,    35,    96,    65,    96,    61,   111,   112,   139,   160,
     164,   176,   191,   197,   202,   206,   208,   213,   239,   242,
     286,   246,   178,   172,   166,    57,   192,   118,    57,   258,
     209,   214,    97,   115,   263,    35,    36,    37,    38,    39,
      40,    41,   120,    59,    59,   263,   263,   263,   263,   263,
      59,   263,   263,   263,   263,   261,   263,    59,   115,    60,
     229,    96,    57,    96,    57,   115,    19,   212,   242,   238,
      12,    21,    22,    69,    70,    71,    72,    73,    80,    81,
      82,    83,    84,    91,    92,   108,   119,   218,   224,    65,
      65,    65,    60,    52,    57,   190,    63,    97,    34,    34,
     103,   207,   207,    34,    65,   264,    96,    96,    96,    96,
     158,    96,    96,    13,    15,    23,    25,    49,    51,    52,
      53,    54,    55,    57,    63,   128,   130,   132,   198,   205,
     257,   288,   289,    96,    96,   262,   270,   234,   224,   132,
      97,    51,    57,   147,   148,    97,   240,    96,    62,    22,
      93,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   136,   137,   219,    58,   247,   113,   113,
     113,    57,   102,    97,    60,    96,   113,    60,   256,   105,
     110,    60,    60,   256,    96,   263,   132,   132,    96,    34,
     117,    23,   133,    98,   102,   100,   101,    99,    97,   113,
      62,   266,   224,    60,    35,    58,    66,    65,   242,    74,
     132,   116,    94,    57,   221,    61,   132,   132,    21,    57,
      63,   140,   150,   156,   162,    60,   193,    55,    51,   113,
      57,    52,    57,   104,   104,   215,    57,   258,    51,    55,
      57,    63,   151,   153,   154,   155,   265,   114,    17,    34,
     117,    63,    65,   112,   126,   132,   116,    21,    22,   112,
     140,   141,   273,   274,   275,    60,   230,    96,   149,    96,
      96,   241,    59,    59,   220,   119,   115,    66,    66,    96,
     163,    56,    57,   190,    99,    98,    12,   132,   199,    97,
     102,    97,    57,    52,    57,   211,    59,    97,    34,    96,
      66,    58,    28,    29,    30,    31,    32,    33,   122,    62,
      96,    34,   113,   127,    42,    43,    44,    45,    46,    47,
      48,    50,    64,    67,   121,   122,   123,   129,    22,    57,
     145,   276,    57,   146,   277,   112,   278,   273,    59,   235,
      57,    91,   124,   134,   136,   225,   132,   147,    35,   148,
      62,    96,   222,    61,   112,   139,   160,   164,   176,   197,
     206,   213,   249,   286,   114,   114,   156,    57,   161,   167,
      60,    60,    64,    64,    60,    58,    60,    60,   114,   114,
      97,   102,    97,    67,   112,   216,    96,   256,   155,    96,
     152,    96,    96,    96,    96,    96,   154,   116,    57,    96,
     132,   151,    96,    96,    96,    96,    96,    96,    96,    96,
     114,   131,   132,    97,    58,    97,    58,    24,   271,   279,
     281,    96,   225,    96,    66,   116,    57,   115,   249,   249,
     249,   249,   249,   249,   249,   248,   249,   179,   173,    64,
      97,    58,   132,   203,   194,   114,   114,   114,    96,   114,
     113,   106,   106,    58,    59,   210,   104,   107,    57,    64,
     155,   263,    97,    57,    64,    66,    64,   129,    35,    96,
      65,    96,   282,   272,    61,   132,    96,   223,   250,    62,
      61,    61,    96,    35,    96,    56,    12,   200,   201,    57,
      59,    59,   132,    12,   199,   287,   104,    96,   107,   211,
      97,    96,    97,   114,   114,   131,    96,    57,    96,    57,
      57,    62,   115,    35,   249,   116,   115,   115,    96,    57,
     168,   204,   199,    97,    96,    96,    60,    57,   216,    60,
     132,    97,   148,    97,   283,   116,    19,    61,   112,   139,
     160,   164,   176,   191,   197,   202,   206,   208,   213,   286,
     289,   290,   293,   294,    96,   251,   180,   174,   132,    97,
      63,   150,   157,   159,    60,    60,   114,    97,   113,    35,
      66,    65,    60,    96,   115,    35,   294,   280,   132,    62,
       8,     9,    61,   112,   139,   160,   164,   176,   191,   197,
     202,   206,   208,   212,   213,   252,   255,   286,   289,   255,
      35,    96,    66,    59,   195,   210,    12,   199,    96,    96,
      96,   284,    74,   132,   291,    96,    62,   116,    59,    59,
     115,   255,   181,    35,   175,    96,   157,   114,    57,    60,
      60,   132,    35,   148,   224,    59,    59,   290,   132,   116,
     249,    96,    96,   253,    62,    96,    62,   132,    64,   169,
      97,   114,   114,    96,    66,    60,    96,    96,   292,    59,
     255,   116,   132,   116,    96,    61,   114,   132,    96,   285,
      62,    96,   254,     5,     6,   112,   182,    59,   115,    59,
      35,   225,   116,    62,   183,   187,    96,   255,    96,    96,
     116,    65,    61,   170,   196,   132,   113,   115,    62,   132,
     188,   116,    66,   255,   114,   189,   184,    62,    61,   116,
     115,   185,   255,   186,    62,   116,   182
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   120,   120,   120,   120,   120,   121,   121,   121,   121,
     121,   121,   122,   122,   122,   122,   122,   122,   123,   123,
     124,   124,   125,   125,   125,   125,   125,   125,   126,   127,
     126,   128,   128,   128,   129,   129,   129,   129,   130,   130,
     130,   130,   130,   131,   131,   132,   132,   132,   132,   132,
     132,   132,   132,   133,   132,   134,   134,   134,   134,   134,
     134,   135,   135,   135,   135,   135,   136,   136,   136,   136,
     136,   137,   137,   137,   137,   137,   138,   138,   138,   138,
     139,   139,   140,   140,   140,   140,   141,   141,   141,   141,
     143,   142,   144,   142,   145,   145,   145,   145,   146,   146,
     146,   146,   147,   147,   149,   148,   148,   150,   150,   150,
     151,   152,   153,   153,   154,   154,   154,   154,   155,   155,
     156,   157,   158,   157,   159,   159,   160,   160,   161,   161,
     162,   162,   163,   162,   164,   164,   166,   167,   168,   169,
     170,   165,   172,   173,   174,   175,   171,   176,   178,   179,
     180,   181,   177,   183,   184,   185,   186,   182,   187,   188,
     189,   182,   182,   190,   190,   192,   193,   194,   195,   196,
     191,   197,   198,   198,   199,   199,   201,   200,   200,   203,
     204,   202,   205,   206,   206,   207,   207,   207,   209,   208,
     210,   210,   211,   211,   212,   212,   214,   213,   215,   216,
     216,   217,   217,   219,   220,   218,   221,   222,   223,   218,
     224,   224,   225,   225,   225,   227,   228,   229,   230,   226,
     232,   233,   234,   235,   231,   237,   238,   236,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   240,
     241,   239,   239,   242,   242,   244,   245,   246,   247,   248,
     243,   249,   249,   249,   249,   249,   249,   250,   251,   249,
     249,   249,   249,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   253,   254,   252,   252,   252,   252,   252,   252,
     252,   255,   255,   256,   257,   258,   258,   260,   261,   262,
     259,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     264,   265,   263,   263,   263,   263,   266,   268,   269,   270,
     271,   272,   267,   273,   273,   274,   275,   275,   276,   276,
     276,   276,   277,   277,   277,   277,   278,   278,   280,   279,
     282,   283,   284,   285,   281,   286,   287,   287,   288,   289,
     289,   289,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   291,   292,   290,   290,   293,   293,
     294,   294
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     2,     2,     3,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     2,     2,
       1,     1,     0,     2,     2,     2,     2,     2,     1,     0,
       4,     3,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     3,     1,     1,     1,     2,     1,     1,
       1,     7,     5,     0,     7,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       3,     3,     1,     1,     1,     2,     1,     1,     2,     3,
       0,     3,     0,     3,     2,     4,     5,     8,     7,    10,
      10,    13,     1,     1,     0,     4,     1,     2,     7,     1,
       1,     0,     1,     4,     1,     1,     1,     5,     3,     1,
       4,     3,     0,     5,     1,     5,     3,     3,     5,     8,
       1,     5,     0,     3,     1,     1,     0,     0,     0,     0,
       0,    20,     0,     0,     0,     0,    15,     1,     0,     0,
       0,     0,    16,     0,     0,     0,     0,    16,     0,     0,
       0,     9,     1,     2,     2,     0,     0,     0,     0,     0,
      18,     2,     8,     8,     4,     1,     0,     2,     1,     0,
       0,    12,     3,    10,    10,     6,     6,     2,     0,     9,
       5,     2,     2,     2,     4,     5,     0,     8,     3,     4,
       1,     2,     2,     0,     0,     4,     0,     0,     0,     7,
       1,     1,     1,     1,     1,     0,     0,     0,     0,    10,
       0,     0,     0,     0,    11,     0,     0,     7,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     0,
       0,     7,     1,     2,     1,     0,     0,     0,     0,     0,
      14,     2,     2,     2,     2,     2,     2,     0,     0,     8,
       2,     2,     1,     1,     1,     1,     6,     1,     1,     1,
       1,     1,     0,     0,     7,     1,     1,     3,     3,     1,
       1,     2,     1,     0,     5,     2,     5,     0,     0,     0,
       9,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       0,     0,     8,     2,     2,     1,     0,     0,     0,     0,
       0,     0,    14,     2,     1,     3,     2,     2,     2,     5,
       5,     8,     7,    10,    10,    13,     2,     1,     0,     7,
       0,     0,     0,     0,    10,     2,     1,     1,    11,     6,
      12,    12,     1,     1,     1,     1,     1,     1,     1,     6,
       1,     1,     1,     1,     0,     0,     7,     1,     5,     5,
       2,     1
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
  case 2: /* subroutine_token: %empty  */
#line 112 "codegen.y"
                         {fprintf(fpcpp, "%s ", yylval.attr.token);}
#line 2324 "codegen.tab.c"
    break;

  case 3: /* subroutine_id: %empty  */
#line 113 "codegen.y"
                      {fprintf(fpcpp, "%s", yylval.attr.converted);}
#line 2330 "codegen.tab.c"
    break;

  case 4: /* subroutine_intVal: %empty  */
#line 118 "codegen.y"
                          {fprintf(fpcpp, "%d", yylval.attr.intVal);}
#line 2336 "codegen.tab.c"
    break;

  case 5: /* subroutine_decVal: %empty  */
#line 119 "codegen.y"
                          {fprintf(fpcpp, "%f", yylval.attr.decVal);}
#line 2342 "codegen.tab.c"
    break;

  case 6: /* subroutine_charVal: %empty  */
#line 120 "codegen.y"
                           {fprintf(fpcpp, "'%c'", yylval.attr.charVal);}
#line 2348 "codegen.tab.c"
    break;

  case 7: /* subroutine_boolVal: %empty  */
#line 121 "codegen.y"
                           {fprintf(fpcpp, "%d", yylval.attr.boolVal);}
#line 2354 "codegen.tab.c"
    break;

  case 8: /* subroutine_stringVal: %empty  */
#line 122 "codegen.y"
                             {fprintf(fpcpp, "%s", yylval.attr.stringVal);}
#line 2360 "codegen.tab.c"
    break;

  case 9: /* subroutine_io: %empty  */
#line 123 "codegen.y"
                      {if(io==1){fprintf(fpcpp,"cin ");} else{fprintf(fpcpp,"cout ");}}
#line 2366 "codegen.tab.c"
    break;

  case 10: /* subroutine_rs: %empty  */
#line 124 "codegen.y"
                      {if(io==1){fprintf(fpcpp," >> ");} else{fprintf(fpcpp,"<< ");}}
#line 2372 "codegen.tab.c"
    break;

  case 11: /* subroutine_fileH: %empty  */
#line 125 "codegen.y"
                         {if(io==1){fprintf(fpcpp,"\n\tifstream fin(");} else{fprintf(fpcpp,"\n\tofstream fop(");}}
#line 2378 "codegen.tab.c"
    break;

  case 12: /* subroutine_fio: %empty  */
#line 126 "codegen.y"
                       {if(io==1){fprintf(fpcpp,"; fin");} else{fprintf(fpcpp,"; fop");}}
#line 2384 "codegen.tab.c"
    break;

  case 13: /* subroutine_fileC: %empty  */
#line 127 "codegen.y"
                         {if(io1 == 0){if(io==1){fprintf(fpcpp," fin.close();\n");} else{fprintf(fpcpp," fop.close();\n");}}}
#line 2390 "codegen.tab.c"
    break;

  case 14: /* subroutine_array: %empty  */
#line 128 "codegen.y"
                         {arr = 1;}
#line 2396 "codegen.tab.c"
    break;

  case 15: /* subroutine_narray: %empty  */
#line 129 "codegen.y"
                          {arr = 0;}
#line 2402 "codegen.tab.c"
    break;

  case 16: /* subr_init: %empty  */
#line 130 "codegen.y"
                  {io1 = 1;}
#line 2408 "codegen.tab.c"
    break;

  case 17: /* return_routine: %empty  */
#line 131 "codegen.y"
                      {if(atm ==1){
              fprintf(fpcpp,"mtx[mut].unlock();\n");
              fprintf(fpcpp,"\tmut++;\n");
              }}
#line 2417 "codegen.tab.c"
    break;

  case 18: /* subroutine: %empty  */
#line 136 "codegen.y"
                   {;}
#line 2423 "codegen.tab.c"
    break;

  case 19: /* subroutine_roundopen: %empty  */
#line 138 "codegen.y"
                             {fprintf(fpcpp, "(");}
#line 2429 "codegen.tab.c"
    break;

  case 20: /* subroutine_roundclose: %empty  */
#line 139 "codegen.y"
                              {fprintf(fpcpp, ")");}
#line 2435 "codegen.tab.c"
    break;

  case 21: /* subroutine_openscope: %empty  */
#line 141 "codegen.y"
                             {fprintf(fpcpp,"{");}
#line 2441 "codegen.tab.c"
    break;

  case 22: /* subroutine_closescope: %empty  */
#line 142 "codegen.y"
                              {fprintf(fpcpp,"}");}
#line 2447 "codegen.tab.c"
    break;

  case 23: /* subr_this: %empty  */
#line 144 "codegen.y"
                  { fprintf(fpcpp, "this"); }
#line 2453 "codegen.tab.c"
    break;

  case 24: /* subr_sleep: %empty  */
#line 146 "codegen.y"
                   { fprintf(fpcpp, "usleep"); }
#line 2459 "codegen.tab.c"
    break;

  case 25: /* all_datatypes: NUDATATYPE subroutine_narray  */
#line 149 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[-1].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[-1].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[-1].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[-1].attr).datatype;
                            // printf("================================%s\n",$$.converted);
                     }
#line 2471 "codegen.tab.c"
    break;

  case 26: /* all_datatypes: AUDATATYPE subroutine_narray  */
#line 157 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[-1].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[-1].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[-1].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[-1].attr).converted;
                     }
#line 2482 "codegen.tab.c"
    break;

  case 27: /* all_datatypes: ARRAY NARRUDATATYPE  */
#line 164 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[0].attr).datatype;
                            printf("================================%s\n",(yyval.attr).converted);
                            // cout << "Here1\n";
                            arr = 1;
                     }
#line 2496 "codegen.tab.c"
    break;

  case 28: /* all_datatypes: ATOMIC ARRAY AARRUDATATYPE  */
#line 174 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[-2].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[-2].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[-2].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[-2].attr).converted;
                     }
#line 2507 "codegen.tab.c"
    break;

  case 29: /* all_datatypes: NBOOL subroutine_narray  */
#line 181 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[-1].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[-1].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[-1].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[-1].attr).converted;
                     }
#line 2518 "codegen.tab.c"
    break;

  case 30: /* all_datatypes: NDEC subroutine_narray  */
#line 188 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[-1].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[-1].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[-1].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[-1].attr).converted;
                     }
#line 2529 "codegen.tab.c"
    break;

  case 31: /* all_datatypes: NNUM subroutine_narray  */
#line 195 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[-1].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[-1].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[-1].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[-1].attr).converted;
                     }
#line 2540 "codegen.tab.c"
    break;

  case 32: /* all_datatypes: NTEXT subroutine_narray  */
#line 202 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[-1].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[-1].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[-1].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[-1].attr).converted;
                     }
#line 2551 "codegen.tab.c"
    break;

  case 33: /* all_datatypes: NLET subroutine_narray  */
#line 209 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[-1].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[-1].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[-1].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[-1].attr).converted;
                     }
#line 2562 "codegen.tab.c"
    break;

  case 34: /* all_datatypes: ABOOL subroutine_narray  */
#line 216 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[-1].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[-1].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[-1].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[-1].attr).converted;
                     }
#line 2573 "codegen.tab.c"
    break;

  case 35: /* all_datatypes: ADEC subroutine_narray  */
#line 223 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[-1].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[-1].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[-1].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[-1].attr).converted;
                     }
#line 2584 "codegen.tab.c"
    break;

  case 36: /* all_datatypes: ALET subroutine_narray  */
#line 230 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[-1].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[-1].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[-1].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[-1].attr).converted;
                     }
#line 2595 "codegen.tab.c"
    break;

  case 37: /* all_datatypes: ATEXT subroutine_narray  */
#line 237 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[-1].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[-1].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[-1].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[-1].attr).converted;
                     }
#line 2606 "codegen.tab.c"
    break;

  case 38: /* all_datatypes: ANUM subroutine_narray  */
#line 244 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[-1].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[-1].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[-1].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[-1].attr).converted;
                     }
#line 2617 "codegen.tab.c"
    break;

  case 39: /* all_datatypes: subroutine_array nonAtomicArray  */
#line 251 "codegen.y"
             {
              /*
              Will be handled down
              */
              (yyval.attr).converted = (yyvsp[0].attr).converted;
             }
#line 2628 "codegen.tab.c"
    break;

  case 40: /* all_datatypes: subroutine_array atomicArray  */
#line 258 "codegen.y"
             {
              /*
              Will be handled down
              */
              }
#line 2638 "codegen.tab.c"
    break;

  case 62: /* begin: %empty  */
#line 272 "codegen.y"
               {
       if(startCount < 1){
              // printError(yylineno,START_ERROR_LESS);
       }
       }
#line 2648 "codegen.tab.c"
    break;

  case 69: /* $@1: %empty  */
#line 288 "codegen.y"
             { fprintf(fpcpp, "%s", (yyvsp[0].attr).token); }
#line 2654 "codegen.tab.c"
    break;

  case 70: /* E: SQUAREOPEN $@1 arr_access SQUARECLOSE  */
#line 288 "codegen.y"
                                                                        { fprintf(fpcpp, "%s", (yyvsp[0].attr).token); }
#line 2660 "codegen.tab.c"
    break;

  case 77: /* all_ops: HASH  */
#line 299 "codegen.y"
             { fprintf(fpcpp, "+"); }
#line 2666 "codegen.tab.c"
    break;

  case 78: /* constants: INTEGERLITERAL subroutine_intVal  */
#line 303 "codegen.y"
       {
              (yyval.attr).datatype = "number"; 
              (yyval.attr).intVal = (yyvsp[-1].attr).intVal;
       }
#line 2675 "codegen.tab.c"
    break;

  case 79: /* constants: CHARACTERLITERAL subroutine_charVal  */
#line 309 "codegen.y"
              {
                     (yyval.attr).datatype = "letter"; 
                     (yyval.attr).charVal = (yyvsp[-1].attr).charVal;
                     printf("%c",(yyvsp[-1].attr).charVal);
              }
#line 2685 "codegen.tab.c"
    break;

  case 80: /* constants: FLOATLITERAL subroutine_decVal  */
#line 316 "codegen.y"
              {
                     (yyval.attr).datatype = "decimal"; 
                     (yyval.attr).decVal = (yyvsp[-1].attr).decVal;
              }
#line 2694 "codegen.tab.c"
    break;

  case 81: /* constants: BOOLEANLITERAL subroutine_boolVal  */
#line 322 "codegen.y"
        {
               (yyval.attr).datatype = "bool"; 
               (yyval.attr).boolVal = (yyvsp[-1].attr).boolVal;
        }
#line 2703 "codegen.tab.c"
    break;

  case 82: /* constants: STRINGLITERAL subroutine_stringVal  */
#line 328 "codegen.y"
       {
              (yyval.attr).datatype = "text"; 
              (yyval.attr).stringVal = (yyvsp[-1].attr).stringVal;
       }
#line 2712 "codegen.tab.c"
    break;

  case 93: /* $@2: %empty  */
#line 346 "codegen.y"
          { fprintf(fpcpp, "!"); }
#line 2718 "codegen.tab.c"
    break;

  case 95: /* nonAtomicSimple: NNUM  */
#line 351 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[0].attr).converted;
                     }
#line 2729 "codegen.tab.c"
    break;

  case 96: /* nonAtomicSimple: NDEC  */
#line 358 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[0].attr).converted;
                     }
#line 2740 "codegen.tab.c"
    break;

  case 97: /* nonAtomicSimple: NBOOL  */
#line 365 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[0].attr).converted;
                     }
#line 2751 "codegen.tab.c"
    break;

  case 98: /* nonAtomicSimple: NLET  */
#line 372 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[0].attr).converted;
                     }
#line 2762 "codegen.tab.c"
    break;

  case 99: /* nonAtomicSimple: NTEXT  */
#line 379 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[0].attr).converted;
                     }
#line 2773 "codegen.tab.c"
    break;

  case 100: /* nonAtomicSimple: NVOID  */
#line 386 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[0].attr).converted;
                     }
#line 2784 "codegen.tab.c"
    break;

  case 101: /* atomicSimple: ANUM  */
#line 395 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[0].attr).converted;
                     }
#line 2795 "codegen.tab.c"
    break;

  case 102: /* atomicSimple: ADEC  */
#line 402 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[0].attr).converted;
                     }
#line 2806 "codegen.tab.c"
    break;

  case 103: /* atomicSimple: ABOOL  */
#line 409 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[0].attr).converted;
                     }
#line 2817 "codegen.tab.c"
    break;

  case 104: /* atomicSimple: ALET  */
#line 416 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[0].attr).converted;
                     }
#line 2828 "codegen.tab.c"
    break;

  case 105: /* atomicSimple: ATEXT  */
#line 423 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[0].attr).converted;
                     }
#line 2839 "codegen.tab.c"
    break;

  case 106: /* nonAtomicArray: NARRNUM  */
#line 432 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[0].attr).converted;
                            //  printf("hiiiiiiiiiiiiiiiiiiiiiiii\n");
                     }
#line 2851 "codegen.tab.c"
    break;

  case 107: /* nonAtomicArray: NARRDEC  */
#line 440 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[0].attr).converted;
                     }
#line 2862 "codegen.tab.c"
    break;

  case 108: /* nonAtomicArray: NARRBOOL  */
#line 447 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[0].attr).converted;
                     }
#line 2873 "codegen.tab.c"
    break;

  case 109: /* nonAtomicArray: NARRLET  */
#line 454 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[0].attr).converted;
                     }
#line 2884 "codegen.tab.c"
    break;

  case 110: /* nonAtomicArray: NARRTEXT  */
#line 461 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted = (yyvsp[0].attr).converted;
                     }
#line 2895 "codegen.tab.c"
    break;

  case 111: /* atomicArray: AARRNUM  */
#line 470 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted = "int";
                     }
#line 2906 "codegen.tab.c"
    break;

  case 112: /* atomicArray: AARRDEC  */
#line 477 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted = "float";
                     }
#line 2917 "codegen.tab.c"
    break;

  case 113: /* atomicArray: AARRBOOL  */
#line 484 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted ="bool";
                     }
#line 2928 "codegen.tab.c"
    break;

  case 114: /* atomicArray: AARRLET  */
#line 491 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted ="char";
                     }
#line 2939 "codegen.tab.c"
    break;

  case 115: /* atomicArray: AARRTEXT  */
#line 498 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            (yyval.attr).converted ="string";
                     }
#line 2950 "codegen.tab.c"
    break;

  case 120: /* declaration: declarationStmt SEMICOLON subroutine_token  */
#line 510 "codegen.y"
                                                         { fprintf(yyout, " : declaration statement"); }
#line 2956 "codegen.tab.c"
    break;

  case 121: /* declaration: errorDatatypes IDENTIFIER subroutine_token  */
#line 511 "codegen.y"
                                                          {printf("TYPE NOT DECLARED, %d\n", yylineno); return 1;}
#line 2962 "codegen.tab.c"
    break;

  case 122: /* simpleDatatype: nonAtomicSimple  */
#line 516 "codegen.y"
                     {      fprintf(fpcpp, "%s", (yyvsp[0].attr).converted);
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2972 "codegen.tab.c"
    break;

  case 123: /* simpleDatatype: atomicSimple  */
#line 522 "codegen.y"
                     {
                            fprintf(fpcpp, "atomic <%s>", (yyvsp[0].attr).converted);
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                     }
#line 2983 "codegen.tab.c"
    break;

  case 124: /* simpleDatatype: NUDATATYPE  */
#line 529 "codegen.y"
                     {
                            fprintf(fpcpp, "%s", (yyvsp[0].attr).datatype);
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = false; 
                            (yyval.attr).is_atomic = false;
                     }
#line 2994 "codegen.tab.c"
    break;

  case 125: /* simpleDatatype: ATOMIC AUDATATYPE  */
#line 537 "codegen.y"
                     {
                            fprintf(fpcpp, "%s<%s>", (yyvsp[-1].attr).token, (yyvsp[0].attr).datatype);
                            (yyval.attr).datatype = ((yyvsp[-1].attr).datatype);
                            (yyval.attr).is_array = false; 
                            (yyval.attr).is_atomic = true;
                     }
#line 3005 "codegen.tab.c"
    break;

  case 126: /* arrayDatatype: nonAtomicArray  */
#line 546 "codegen.y"
                     {
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            fprintf(fpcpp, "%s", (yyvsp[0].attr).converted);
                     }
#line 3016 "codegen.tab.c"
    break;

  case 127: /* arrayDatatype: atomicArray  */
#line 553 "codegen.y"
                     {
                            
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = (yyvsp[0].attr).is_array;
                            (yyval.attr).is_atomic = (yyvsp[0].attr).is_atomic;
                            fprintf(fpcpp, "atomic <%s>", (yyvsp[0].attr).converted);
                     }
#line 3028 "codegen.tab.c"
    break;

  case 128: /* arrayDatatype: ARRAY NARRUDATATYPE  */
#line 561 "codegen.y"
                     {
                            fprintf(fpcpp, "%s", (yyvsp[0].attr).datatype);
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = true; 
                            (yyval.attr).is_atomic = false;
                     }
#line 3039 "codegen.tab.c"
    break;

  case 129: /* arrayDatatype: ATOMIC ARRAY AARRUDATATYPE  */
#line 569 "codegen.y"
                     {
                            fprintf(fpcpp, "%s<%s>", (yyvsp[-2].attr).token, (yyvsp[0].attr).datatype);
                            (yyval.attr).datatype = ((yyvsp[0].attr).datatype);
                            (yyval.attr).is_array = true; 
                            (yyval.attr).is_atomic = true;
                     }
#line 3050 "codegen.tab.c"
    break;

  case 130: /* $@3: %empty  */
#line 578 "codegen.y"
                     {
                            dt_state = ((yyvsp[0].attr).datatype);
                            array_state = (yyvsp[0].attr).is_array;
                            atomic_state = (yyvsp[0].attr).is_atomic;
                     }
#line 3060 "codegen.tab.c"
    break;

  case 132: /* $@4: %empty  */
#line 584 "codegen.y"
                     {
                            dt_state = ((yyvsp[0].attr).datatype);
                            array_state = (yyvsp[0].attr).is_array;
                            atomic_state = (yyvsp[0].attr).is_atomic;
                     }
#line 3070 "codegen.tab.c"
    break;

  case 134: /* simpleList: IDENTIFIER subroutine_id  */
#line 592 "codegen.y"
              {
                            (yyvsp[-1].attr).datatype = (dt_state);
                            (yyvsp[-1].attr).is_array = array_state;
                            (yyvsp[-1].attr).is_atomic = atomic_state;
                            // if(i_tb.searchDeclaration($1.ID)){
                            //        // printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                            //        return 1;
                            // }
                            // i_tb.addVariable($1.ID, $1.datatype, $1.is_atomic, $1.is_array);
                            // i_tb.print();

              }
#line 3087 "codegen.tab.c"
    break;

  case 135: /* simpleList: simpleList COMMA subroutine_token IDENTIFIER  */
#line 605 "codegen.y"
              {
                            (yyvsp[0].attr).datatype = (dt_state);
                            (yyvsp[0].attr).is_array = array_state;
                            (yyvsp[0].attr).is_atomic = atomic_state;
                            // if(i_tb.searchDeclaration($4.ID)){
                            //        printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                            //        return 1;
                            // }
                            // i_tb.addVariable($4.ID, $4.datatype, $4.is_atomic, $4.is_array);
                            // i_tb.print();

                            
                            fprintf(fpcpp, "%s", (yyvsp[0].attr).ID);
              
              }
#line 3107 "codegen.tab.c"
    break;

  case 136: /* simpleList: IDENTIFIER subroutine_id EQ subroutine_token RHS  */
#line 621 "codegen.y"
              {
                            (yyvsp[-4].attr).datatype = (dt_state);
                            (yyvsp[-4].attr).is_array = array_state;
                            (yyvsp[-4].attr).is_atomic = atomic_state;
                            // if(i_tb.searchDeclaration($1.ID)){
                            //        printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                            //        return 1;
                            // }
                            // if(/* DO LHS RHS check*/ true) ;

                            // i_tb.addVariable($1.ID, $1.datatype, $1.is_atomic, $1.is_array);
                            // i_tb.print();
                            /*
                            Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state,
                            atomic_state, Scope Level + TYPE CHECK FOR COERCIBILITY OF dt_state and
                            RHS.datatype
                            */

              }
#line 3131 "codegen.tab.c"
    break;

  case 137: /* simpleList: simpleList COMMA subroutine_token IDENTIFIER subroutine_id EQ subroutine_token RHS  */
#line 641 "codegen.y"
              {
                            (yyvsp[-4].attr).datatype = (dt_state);
                            (yyvsp[-4].attr).is_array = array_state;
                            (yyvsp[-4].attr).is_atomic = atomic_state;
                            // if(i_tb.searchDeclaration($4.ID)){
                            //        printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                            //        return 1;
                            // }
                            // if(/* DO LHS RHS check*/ true) ;

                            // i_tb.addVariable($4.ID, $4.datatype, $4.is_atomic, $4.is_array);
                            // i_tb.print();
                            /*
                            Insert in Normal IDENTIFIER TABLE $3.ID, dt_state, array_state, atomic_state,
                            Scope Level + TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
                            */
              }
#line 3153 "codegen.tab.c"
    break;

  case 138: /* arrayList: IDENTIFIER subroutine_id SQUAREOPEN subroutine_token dimlist SQUARECLOSE subroutine_token  */
#line 661 "codegen.y"
              {
                            (yyvsp[-6].attr).datatype = (dt_state);
                            (yyvsp[-6].attr).is_array = array_state;
                            (yyvsp[-6].attr).is_atomic = atomic_state;
                            // if(i_tb.searchDeclaration($1.ID)){
                            //        printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                            //        return 1;
                            // }

                            // i_tb.addVariable($1.ID, $1.datatype, $1.is_atomic, $1.is_array);
                            // i_tb.print();
                             /*
                            // Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, atomic_state,
                            Scope Level
                            */
                           
              }
#line 3175 "codegen.tab.c"
    break;

  case 139: /* arrayList: arrayList COMMA subroutine_token IDENTIFIER subroutine_id SQUAREOPEN subroutine_token dimlist SQUARECLOSE subroutine_token  */
#line 679 "codegen.y"
              {
                            (yyvsp[-6].attr).datatype = (dt_state);
                            (yyvsp[-6].attr).is_array = array_state;
                            (yyvsp[-6].attr).is_atomic = atomic_state;
                            // if(i_tb.searchDeclaration($4.ID)){
                            //        printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                            //        return 1;
                            // }

                            // i_tb.addVariable($4.ID, $4.datatype, $4.is_atomic, $4.is_array);
                            // i_tb.print();
                            /*
                            Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, 
                            atomic_state, Scope Level
                            */

              }
#line 3197 "codegen.tab.c"
    break;

  case 140: /* arrayList: IDENTIFIER subroutine_id SQUAREOPEN subroutine_token dimlist SQUARECLOSE subroutine_token EQ subroutine_token RHS  */
#line 697 "codegen.y"
              {
                            (yyvsp[-9].attr).datatype = (dt_state);
                            (yyvsp[-9].attr).is_array = array_state;
                            (yyvsp[-9].attr).is_atomic = atomic_state;

                            // if(i_tb.searchDeclaration($1.ID)){
                            //        printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                            //        return 1;
                            // }

                            // i_tb.addVariable($1.ID, $1.datatype, $1.is_atomic, $1.is_array);

                            /*
                            Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, atomic_state,
                            Scope Level + TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
                            */
              

              }
#line 3221 "codegen.tab.c"
    break;

  case 141: /* arrayList: arrayList COMMA subroutine_token IDENTIFIER subroutine_id SQUAREOPEN subroutine_token dimlist SQUARECLOSE subroutine_token EQ subroutine_token RHS  */
#line 717 "codegen.y"
              {
                            (yyvsp[-9].attr).datatype = (dt_state);
                            (yyvsp[-9].attr).is_array = array_state;
                            (yyvsp[-9].attr).is_atomic = atomic_state;
                            // if(i_tb.searchDeclaration($4.ID)){
                            //        printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                            //        return 1;
                            // }

                            // i_tb.addVariable($4.ID, $4.datatype, $4.is_atomic, $4.is_array);

                            /*
                            Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, atomic_state,
                            Scope Level + TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
                            */
              }
#line 3242 "codegen.tab.c"
    break;

  case 142: /* array_inValues: INTEGERLITERAL  */
#line 735 "codegen.y"
                               {(yyval.attr).intVal = (yyvsp[0].attr).intVal;  fprintf(fpcpp, "%d", (yyvsp[0].attr).intVal); }
#line 3248 "codegen.tab.c"
    break;

  case 143: /* array_inValues: IDENTIFIER  */
#line 736 "codegen.y"
                           {(yyval.attr).intVal = INT_MAX; fprintf(fpcpp, "%s", (yyvsp[0].attr).ID); }
#line 3254 "codegen.tab.c"
    break;

  case 144: /* $@5: %empty  */
#line 739 "codegen.y"
                        { fprintf(fpcpp, "]["); }
#line 3260 "codegen.tab.c"
    break;

  case 147: /* LHS: IDENTIFIER subroutine_id  */
#line 744 "codegen.y"
       {
              // i_tb.searchDeclaration($1.ID);
              /*
              Search for identifier, get it's attributes, 
              store in $1.datatype, $1.is_array, $1.is_atomic
              */
       }
#line 3272 "codegen.tab.c"
    break;

  case 148: /* LHS: IDENTIFIER subroutine_id SQUAREOPEN subroutine_token arr_access SQUARECLOSE subroutine_token  */
#line 752 "codegen.y"
                 {
                     /*
                     Search for identifier, get it's attributes, store
                     in $1.datatype, $1.is_array, $1.is_atomic
                     */
                     /*
                     If is_array of Identifier is false, then semantic error
                     */
                 }
#line 3286 "codegen.tab.c"
    break;

  case 149: /* LHS: access  */
#line 762 "codegen.y"
    {
       /* 
       SHOULD COME BACK, THIS IS ARROW ACCESSING
       */
    }
#line 3296 "codegen.tab.c"
    break;

  case 151: /* subroutine_dim: %empty  */
#line 772 "codegen.y"
                        {fprintf(fpcpp, "][");}
#line 3302 "codegen.tab.c"
    break;

  case 154: /* arith_operand: IDENTIFIER  */
#line 778 "codegen.y"
                          { 
                     makeParallel = 0;
                     (yyval.attr).ID = (yyvsp[0].attr).ID;
                     fprintf(fpcpp, "%s", (yyvsp[0].attr).ID); }
#line 3311 "codegen.tab.c"
    break;

  case 155: /* arith_operand: INTEGERLITERAL  */
#line 782 "codegen.y"
                               {
                     makeParallel = 1;
                     (yyval.attr).intVal = (yyvsp[0].attr).intVal;
                     fprintf(fpcpp, "%d", (yyvsp[0].attr).intVal); 
              }
#line 3321 "codegen.tab.c"
    break;

  case 156: /* arith_operand: FLOATLITERAL  */
#line 787 "codegen.y"
                             { 
                     (yyval.attr).decVal = (yyvsp[0].attr).decVal;       
                     fprintf(fpcpp, "%f", (yyvsp[0].attr).decVal); }
#line 3329 "codegen.tab.c"
    break;

  case 160: /* assignment_statement: LHS EQ subroutine_token RHS  */
#line 799 "codegen.y"
                     {
                            /*
                            Type check for LHS.datatype, RHS.datatype
                            */
                     }
#line 3339 "codegen.tab.c"
    break;

  case 161: /* expression_statement: LHS expression_op RHS  */
#line 808 "codegen.y"
                     {
                            /* 
                            SHOULD COME BACK, THERE SHOULD BE A TYPE CHECK BTW LHS.datatype, RHS.datatype. 
                            IF IT MATCHES, WILL $$.datatype BE BOOLEAN? 
                            */
                     }
#line 3350 "codegen.tab.c"
    break;

  case 162: /* $@6: %empty  */
#line 813 "codegen.y"
                                           { fprintf(fpcpp, " = pow(%s, ", (yyvsp[-1].attr).ID); }
#line 3356 "codegen.tab.c"
    break;

  case 166: /* log: assignment_statement SEMICOLON subroutine_token  */
#line 820 "codegen.y"
                                                     { fprintf(yyout, " : assignment statement");  }
#line 3362 "codegen.tab.c"
    break;

  case 167: /* log: expression_statement SEMICOLON subroutine_token  */
#line 821 "codegen.y"
                                                      { fprintf(yyout, " : expression statement");  }
#line 3368 "codegen.tab.c"
    break;

  case 168: /* g: IDENTIFIER subroutine_id EQ subroutine_token RHS  */
#line 825 "codegen.y"
       {
              // if(i_tb.searchDeclaration($1.ID)){
              //        printError(yylineno,VARIABLE_REDECLARATION_ERROR);
              // }
              // if(/* Do type check with RHS */ true){
              //        i_tb.addVariable($1.ID,dt_state,atomic_state, array_state);
              // }
               /*
              Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, atomic_state, Scope Level + 
              TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
              */
       }
#line 3385 "codegen.tab.c"
    break;

  case 169: /* g: g COMMA subroutine_token IDENTIFIER subroutine_id EQ subroutine_token RHS  */
#line 838 "codegen.y"
       {
              // if(i_tb.searchDeclaration($4.ID)){
              //        printError(yylineno,VARIABLE_REDECLARATION_ERROR);
              // }
              // if(/* Do type check with RHS */ true){
              //        i_tb.addVariable($4.ID,dt_state,atomic_state, array_state);
              // }
              /*
              Insert in Normal IDENTIFIER TABLE $2.ID, dt_state, array_state, atomic_state, Scope Level + 
              TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
              */
       }
#line 3402 "codegen.tab.c"
    break;

  case 170: /* both_assignment: assignment_statement  */
#line 853 "codegen.y"
              {
                     /*
                     NO NEED TO DO ANYTHING, THE ASSIGNMENT STATEMENT RULE TAKES CARE
                     */
              }
#line 3412 "codegen.tab.c"
    break;

  case 171: /* both_assignment: ROUNDOPEN subroutine_token assignment_statement ROUNDCLOSE subroutine_token  */
#line 859 "codegen.y"
                {
                     /*
                     NO NEED TO DO ANYTHING, THE ASSIGNMENT STATEMENT RULE TAKES CARE
                     */
                }
#line 3422 "codegen.tab.c"
    break;

  case 172: /* $@7: %empty  */
#line 864 "codegen.y"
                                 {
                            // printf("%s\n",$1.datatype);
                            dt_state = ((yyvsp[0].attr).datatype);
                            array_state = (yyvsp[0].attr).is_array;
                            atomic_state = (yyvsp[0].attr).is_atomic;
                     }
#line 3433 "codegen.tab.c"
    break;

  case 173: /* both_assignment: simpleDatatype $@7 g  */
#line 871 "codegen.y"
                {
                     dt_state = NULL ;
                }
#line 3441 "codegen.tab.c"
    break;

  case 176: /* $@8: %empty  */
#line 880 "codegen.y"
              {scopeLevel++; fprintf(fpcpp, "%s", (yyvsp[0].attr).token); }
#line 3447 "codegen.tab.c"
    break;

  case 177: /* $@9: %empty  */
#line 880 "codegen.y"
                                                                                                                     { fprintf(fpcpp, ";"); }
#line 3453 "codegen.tab.c"
    break;

  case 178: /* $@10: %empty  */
#line 880 "codegen.y"
                                                                                                                                                        { fprintf(fpcpp, ";"); }
#line 3459 "codegen.tab.c"
    break;

  case 179: /* $@11: %empty  */
#line 880 "codegen.y"
                                                                                                                                                                                                                           { fprintf(yyout, " : loop statement");}
#line 3465 "codegen.tab.c"
    break;

  case 180: /* $@12: %empty  */
#line 881 "codegen.y"
       {
              // i_tb.deleteVariables();
              scopeLevel--;
       }
#line 3474 "codegen.tab.c"
    break;

  case 181: /* for_loop: FOR $@8 SQUAREOPEN subroutine_roundopen both_assignment PIPE $@9 RHS PIPE $@10 exprrr SQUARECLOSE subroutine_roundclose $@11 SCOPEOPEN subroutine_openscope statements $@12 SCOPECLOSE subroutine_closescope  */
#line 885 "codegen.y"
       {
              /*
              RHS.datatype is coercible with boolean?
              */
              /*
              NO NEED TO DO ANYTHING EXCEPT SCOPES, THE 
              PREDICATES ARE TAKEN CARE BY ABOVE RULES
              */
       }
#line 3488 "codegen.tab.c"
    break;

  case 182: /* $@13: %empty  */
#line 896 "codegen.y"
                   { fprintf(fpcpp, "while"); }
#line 3494 "codegen.tab.c"
    break;

  case 183: /* $@14: %empty  */
#line 896 "codegen.y"
                                                                                                                         { fprintf(yyout, " : loop statement");}
#line 3500 "codegen.tab.c"
    break;

  case 184: /* $@15: %empty  */
#line 896 "codegen.y"
                                                                                                                                                                                                {scopeLevel++;}
#line 3506 "codegen.tab.c"
    break;

  case 185: /* $@16: %empty  */
#line 897 "codegen.y"
       {
              // i_tb.deleteVariables();
              scopeLevel--;
       }
#line 3515 "codegen.tab.c"
    break;

  case 186: /* while_loop: REPEAT $@13 SQUAREOPEN subroutine_roundopen RHS SQUARECLOSE subroutine_roundclose $@14 SCOPEOPEN subroutine_openscope $@15 statements $@16 SCOPECLOSE subroutine_closescope  */
#line 901 "codegen.y"
       {
              /*
              RHS.datatype is coercible with boolean?
              */
              /*
              NO NEED TO DO ANYTHING EXCEPT SCOPES, THE PREDICATES ARE
              TAKEN CARE BY ABOVE RULES
              */
       }
#line 3529 "codegen.tab.c"
    break;

  case 188: /* $@17: %empty  */
#line 917 "codegen.y"
                     { fprintf(fpcpp, "if"); }
#line 3535 "codegen.tab.c"
    break;

  case 189: /* $@18: %empty  */
#line 917 "codegen.y"
                                                                                                                     { fprintf(yyout, " : conditional statement");  }
#line 3541 "codegen.tab.c"
    break;

  case 190: /* $@19: %empty  */
#line 917 "codegen.y"
                                                                                                                                                                                                     { scopeLevel++;}
#line 3547 "codegen.tab.c"
    break;

  case 191: /* $@20: %empty  */
#line 918 "codegen.y"
       {
              // i_tb.deleteVariables();
              scopeLevel--;
       }
#line 3556 "codegen.tab.c"
    break;

  case 193: /* $@21: %empty  */
#line 923 "codegen.y"
                   { fprintf(fpcpp, "else if"); }
#line 3562 "codegen.tab.c"
    break;

  case 194: /* $@22: %empty  */
#line 923 "codegen.y"
                                                                                                                        { fprintf(yyout, " : conditional statement");  }
#line 3568 "codegen.tab.c"
    break;

  case 195: /* $@23: %empty  */
#line 923 "codegen.y"
                                                                                                                                                                                                        { scopeLevel++;}
#line 3574 "codegen.tab.c"
    break;

  case 196: /* $@24: %empty  */
#line 924 "codegen.y"
       {
              // i_tb.deleteVariables();
              scopeLevel--;
       }
#line 3583 "codegen.tab.c"
    break;

  case 198: /* $@25: %empty  */
#line 928 "codegen.y"
                 {  fprintf(fpcpp, "else");  fprintf(yyout, " : conditional statement");  }
#line 3589 "codegen.tab.c"
    break;

  case 199: /* $@26: %empty  */
#line 928 "codegen.y"
                                                                                                                           { scopeLevel++; }
#line 3595 "codegen.tab.c"
    break;

  case 200: /* $@27: %empty  */
#line 929 "codegen.y"
       {
              // i_tb.deleteVariables();
              scopeLevel--;
       }
#line 3604 "codegen.tab.c"
    break;

  case 204: /* analyze_label: IDENTIFIER subroutine_id  */
#line 950 "codegen.y"
              {
                     /*
                     SHOULD COME BACK, WHAT ARE THESE?
                     */
              }
#line 3614 "codegen.tab.c"
    break;

  case 205: /* $@28: %empty  */
#line 956 "codegen.y"
                            {fprintf(fpcpp,"drawGraph(");}
#line 3620 "codegen.tab.c"
    break;

  case 206: /* $@29: %empty  */
#line 956 "codegen.y"
                                                                               {fprintf(fpcpp,",");}
#line 3626 "codegen.tab.c"
    break;

  case 207: /* $@30: %empty  */
#line 956 "codegen.y"
                                                                                                                         {fprintf(fpcpp,",");}
#line 3632 "codegen.tab.c"
    break;

  case 208: /* $@31: %empty  */
#line 956 "codegen.y"
                                                                                                                                                                              {fprintf(fpcpp,",");}
#line 3638 "codegen.tab.c"
    break;

  case 209: /* $@32: %empty  */
#line 956 "codegen.y"
                                                                                                                                                                                                                                                                             { fprintf(yyout, " : analyze statement");  }
#line 3644 "codegen.tab.c"
    break;

  case 210: /* analyze_statement: ANALYZE $@28 analyze_label COLON $@29 analyze_label COLON $@30 IDENTIFIER subroutine_id COLON $@31 IDENTIFIER subroutine_id subroutine_roundclose SEMICOLON subroutine_token $@32  */
#line 958 "codegen.y"
       {
       /* 
       SHOULD COME BACK, WHAT ARE THESE? 
       */
       }
#line 3654 "codegen.tab.c"
    break;

  case 211: /* func_invoke2: func_invoke SEMICOLON  */
#line 975 "codegen.y"
                                     {  fprintf(fpcpp, ";");  fprintf(yyout, " : call statement");  }
#line 3660 "codegen.tab.c"
    break;

  case 212: /* func_invoke: INVOKE IDENTIFIER subroutine_id COLON subroutine_roundopen arguments COLON subroutine_roundclose  */
#line 979 "codegen.y"
       {
              /*
              BY here list of arg_dat (list of arguement's datatypes) will be ready. 
              For all functions with name as $2.ID, type check arguements
              */
              arg_dat.clear();
       }
#line 3672 "codegen.tab.c"
    break;

  case 213: /* func_invoke: INVOKE IDENTIFIER subroutine_id COLON subroutine_roundopen NULL_ARGS COLON subroutine_roundclose  */
#line 987 "codegen.y"
           {
              /*
              For all functions with name as $2.ID, type check if arguements are null
              */ 
             arg_dat.clear();
           }
#line 3683 "codegen.tab.c"
    break;

  case 214: /* arguments: arguments COMMA subroutine_token RHS  */
#line 997 "codegen.y"
          {
              arg_dat.push_back(((yyvsp[0].attr).datatype));
          }
#line 3691 "codegen.tab.c"
    break;

  case 215: /* arguments: RHS  */
#line 1001 "codegen.y"
          {
              arg_dat.push_back(((yyvsp[0].attr).datatype));
          }
#line 3699 "codegen.tab.c"
    break;

  case 216: /* $@33: %empty  */
#line 1006 "codegen.y"
                  {fprintf(fpcpp, ",");}
#line 3705 "codegen.tab.c"
    break;

  case 218: /* task_invoke_args: NULL_ARGS  */
#line 1007 "codegen.y"
                            {arg_dat.clear();}
#line 3711 "codegen.tab.c"
    break;

  case 219: /* $@34: %empty  */
#line 1011 "codegen.y"
                                                                               { 
                     
                     fprintf(yyout, " : call statement");                       /*
                     
                     By here list of arg_dat (list of arguement's datatypes) will be ready. For all functions with name
                     as $1.ID, type check arguements
                     */

                     fprintf(fpcpp, "\n\tfor(int i = 0; i < %s; i++) {\n", (yyvsp[-1].attr).ID);
                     fprintf(fpcpp, "\t\tgett.begin();\n");
                     fprintf(fpcpp, "\t\tthread threads[%s];\n", (yyvsp[-3].attr).ID);
                     fprintf(fpcpp, "\n\tfor(int i = 0; i < %s; i++) {\n", (yyvsp[-3].attr).ID);
                     fprintf(fpcpp, "\t\tthreads[i] = thread(%s, i+1", (yyvsp[-5].attr).ID);
                     
              }
#line 3731 "codegen.tab.c"
    break;

  case 220: /* $@35: %empty  */
#line 1025 "codegen.y"
                                 {

                     fprintf(fpcpp, ");\n\t}");

                     fprintf(fpcpp, "\n\tfor(int i = 0; i < %s; i++) {\n\t\tthreads[i].join();\n\t}\n", (yyvsp[-5].attr).ID);
                     fprintf(fpcpp, "\t\tgett.stop();\n\t}\n\tgett.t = gett.t/%s;\n", (yyvsp[-3].attr).ID);

                     arg_dat.clear();
              }
#line 3745 "codegen.tab.c"
    break;

  case 223: /* sleep: SLEEP subr_sleep ROUNDOPEN subroutine_token FLOATLITERAL subroutine_decVal ROUNDCLOSE subroutine_roundclose SEMICOLON subroutine_token  */
#line 1039 "codegen.y"
                                                                                                                                               { fprintf(yyout, " : sleep statement");  }
#line 3751 "codegen.tab.c"
    break;

  case 224: /* sleep: SLEEP subr_sleep ROUNDOPEN subroutine_roundopen INTEGERLITERAL subroutine_intVal ROUNDCLOSE subroutine_roundclose SEMICOLON subroutine_token  */
#line 1040 "codegen.y"
                                                                                                                                                      { fprintf(yyout, " : sleep statement");  }
#line 3757 "codegen.tab.c"
    break;

  case 225: /* file_name: ARROW subroutine_fileH STRINGLITERAL subroutine_stringVal subroutine_roundclose subroutine_fio  */
#line 1043 "codegen.y"
                                                                                                            {io1 = 0;}
#line 3763 "codegen.tab.c"
    break;

  case 228: /* $@36: %empty  */
#line 1048 "codegen.y"
           {io = 1;}
#line 3769 "codegen.tab.c"
    break;

  case 231: /* nextip: SEMICOLON subroutine_token  */
#line 1054 "codegen.y"
     { 
      fprintf(yyout, " : scan statement");
     }
#line 3777 "codegen.tab.c"
    break;

  case 234: /* return_statement: RETURN subroutine_token RHS SEMICOLON  */
#line 1064 "codegen.y"
                                                         {
       fprintf(fpcpp,"%s",(yyvsp[0].attr).token); (yyval.attr).datatype = (yyvsp[-1].attr).datatype; (yyval.attr).is_array = (yyvsp[-1].attr).is_array; /*Atomics not needed here ig*/ /*TYPE CHECK WITH LAST FUNCTION'S RETURN DATATYPE AND THIS DATATYPE*/fprintf(yyout, " : return statement"); }
#line 3784 "codegen.tab.c"
    break;

  case 235: /* return_statement: RETURN subroutine_token NVOID SEMICOLON subroutine_token  */
#line 1066 "codegen.y"
                                                                            {(yyval.attr).datatype = (yyvsp[-2].attr).datatype; (yyval.attr).is_array = (yyvsp[-2].attr).is_array; /*Atomics not needed here ig*/ /*TYPE CHECK WITH LAST FUNCTION'S RETURN DATATYPE AND THIS DATATYPE*/ fprintf(yyout, " : return statement"); }
#line 3790 "codegen.tab.c"
    break;

  case 236: /* $@37: %empty  */
#line 1070 "codegen.y"
            {io = 0;}
#line 3796 "codegen.tab.c"
    break;

  case 237: /* output: OP $@37 file_name COLON opstring SEMICOLON subroutine_token subroutine_fileC  */
#line 1071 "codegen.y"
       { 
        fprintf(yyout, " : print statement");
       //  printf("================================================");
       }
#line 3805 "codegen.tab.c"
    break;

  case 243: /* $@38: %empty  */
#line 1091 "codegen.y"
                         { task_array.push_back(","); func_array.push_back(std::string((yyvsp[0].attr).converted)); task_array.push_back(std::string((yyvsp[0].attr).converted)); method_array.push_back(std::string((yyvsp[0].attr).converted)); printf("================================%s\n",(yyvsp[0].attr).converted);}
#line 3811 "codegen.tab.c"
    break;

  case 244: /* $@39: %empty  */
#line 1091 "codegen.y"
                                                                                                                                                                                                                                                                                    {if(arr==0){func_array.push_back(std::string((yyvsp[0].attr).ID)); method_array.push_back(std::string((yyvsp[0].attr).ID)); task_array.push_back(std::string((yyvsp[0].attr).ID));} else{func_array.push_back(std::string((yyvsp[0].attr).ID)+"[]"); task_array.push_back(std::string((yyvsp[0].attr).ID)+"[]"); method_array.push_back(std::string((yyvsp[0].attr).ID)+"[]");}}
#line 3817 "codegen.tab.c"
    break;

  case 245: /* func_args: all_datatypes $@38 IDENTIFIER $@39  */
#line 1092 "codegen.y"
       {
              decl_arg_dat.push_back(((yyvsp[-3].attr).ID));
              decl_arg_is_array.push_back((yyvsp[-3].attr).is_array);
              // i_tb.addVariable($3.ID, $1.datatype, $1.is_atomic, $1.is_array);
       }
#line 3827 "codegen.tab.c"
    break;

  case 246: /* $@40: %empty  */
#line 1097 "codegen.y"
                         {func_array.push_back(std::string((yyvsp[0].attr).token)); task_array.push_back(std::string((yyvsp[0].attr).token)); method_array.push_back(std::string((yyvsp[0].attr).token)); }
#line 3833 "codegen.tab.c"
    break;

  case 247: /* $@41: %empty  */
#line 1097 "codegen.y"
                                                                                                                                                                                   {func_array.push_back(std::string((yyvsp[0].attr).converted));task_array.push_back(std::string((yyvsp[0].attr).converted)); method_array.push_back(std::string((yyvsp[0].attr).converted)); }
#line 3839 "codegen.tab.c"
    break;

  case 248: /* $@42: %empty  */
#line 1097 "codegen.y"
                                                                                                                                                                                                                                                                                                                                                     {if(arr==0){func_array.push_back(std::string((yyvsp[0].attr).ID));   task_array.push_back(std::string((yyvsp[0].attr).ID));  method_array.push_back(std::string((yyvsp[0].attr).ID)); } else{func_array.push_back(std::string((yyvsp[0].attr).ID)+"[]");  task_array.push_back(std::string((yyvsp[0].attr).ID)+"[]");  method_array.push_back(std::string((yyvsp[0].attr).ID)+"[]"); }}
#line 3845 "codegen.tab.c"
    break;

  case 249: /* func_args: func_args COMMA $@40 all_datatypes $@41 IDENTIFIER $@42  */
#line 1098 "codegen.y"
       {              
              // i_tb.addVariable($4.ID, $4.datatype, $4.is_atomic, $4.is_array);
              decl_arg_is_array.push_back((yyvsp[-3].attr).is_array);
              decl_arg_dat.push_back(((yyvsp[-1].attr).ID));
       }
#line 3855 "codegen.tab.c"
    break;

  case 252: /* func_return: nonAtomic_datatypes  */
#line 1110 "codegen.y"
              {
                     if((yyvsp[0].attr).is_array==0){
                     func_array.push_back(std::string((yyvsp[0].attr).converted));
                     method_array.push_back(std::string((yyvsp[0].attr).converted));
                     }
                     else{
                            func_array.push_back(std::string((yyvsp[0].attr).converted)+" *");
                            method_array.push_back(std::string((yyvsp[0].attr).converted)+" *");
                     }
                     // printf("%d\n",$1.is_array);

                     (yyval.attr).datatype = ((yyvsp[0].attr).datatype); 
                     (yyval.attr).is_array = (yyvsp[0].attr).is_array; 

                     /*Atomic is not needed*/
              }
#line 3876 "codegen.tab.c"
    break;

  case 253: /* func_return: NUDATATYPE  */
#line 1127 "codegen.y"
            {
              func_array.push_back(std::string((yyvsp[0].attr).datatype));
              method_array.push_back(std::string((yyvsp[0].attr).datatype));

              (yyval.attr).datatype = ((yyvsp[0].attr).datatype); 
              (yyval.attr).is_array = (yyvsp[0].attr).is_array; 
              /*Atomic is not needed*/
            }
#line 3889 "codegen.tab.c"
    break;

  case 254: /* func_return: IDENTIFIER  */
#line 1135 "codegen.y"
                         {printf("TYPE NOT DECLARED, %d\n", yylineno); return 1;}
#line 3895 "codegen.tab.c"
    break;

  case 255: /* $@43: %empty  */
#line 1138 "codegen.y"
                  { func_array.clear(); func_array.push_back(std::string((yyvsp[0].attr).token)); }
#line 3901 "codegen.tab.c"
    break;

  case 256: /* $@44: %empty  */
#line 1138 "codegen.y"
                                                                                                  {func_array.push_back(std::string((yyvsp[0].attr).ID));}
#line 3907 "codegen.tab.c"
    break;

  case 257: /* $@45: %empty  */
#line 1138 "codegen.y"
                                                                                                                                                    { func_array.push_back(std::string((yyvsp[0].attr).token)); }
#line 3913 "codegen.tab.c"
    break;

  case 258: /* $@46: %empty  */
#line 1138 "codegen.y"
                                                                                                                                                                                                                { func_array.push_back(std::string((yyvsp[0].attr).token)); }
#line 3919 "codegen.tab.c"
    break;

  case 259: /* func_decl: FUNC $@43 IDENTIFIER $@44 COLON $@45 args COLON $@46 func_return  */
#line 1139 "codegen.y"
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
                     atm = 0;
                     // cout<< FuncDeclGen(func_array);

                     fprintf(fpcpp,"\n%s", FuncDeclGen(func_array).c_str());

                     func_array.clear();
                     
              }
#line 3944 "codegen.tab.c"
    break;

  case 260: /* $@47: %empty  */
#line 1160 "codegen.y"
                                 {func_array.clear(); func_array.push_back(std::string((yyvsp[0].attr).token)); }
#line 3950 "codegen.tab.c"
    break;

  case 261: /* $@48: %empty  */
#line 1160 "codegen.y"
                                                                                                                {func_array.push_back(std::string((yyvsp[0].attr).ID));}
#line 3956 "codegen.tab.c"
    break;

  case 262: /* $@49: %empty  */
#line 1160 "codegen.y"
                                                                                                                                                                  { func_array.push_back(std::string((yyvsp[0].attr).token)); }
#line 3962 "codegen.tab.c"
    break;

  case 263: /* $@50: %empty  */
#line 1160 "codegen.y"
                                                                                                                                                                                                                              { func_array.push_back(std::string((yyvsp[0].attr).token)); }
#line 3968 "codegen.tab.c"
    break;

  case 264: /* atomic_func_decl: ATOMIC FUNC $@47 IDENTIFIER $@48 COLON $@49 args COLON $@50 func_return  */
#line 1161 "codegen.y"
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
                            // cout<<"====================================="<<endl;
                            // fprintf
                            atm = 1;
                            fprintf(fpcpp, "\n%s", FuncDeclGen(func_array).c_str());

                            func_array.clear();
                     }
#line 3993 "codegen.tab.c"
    break;

  case 265: /* $@51: %empty  */
#line 1183 "codegen.y"
                                           {if(atm ==1){ fprintf(fpcpp,"\n\tmtx[mut].lock();\n"); scopeLevel++;}}
#line 3999 "codegen.tab.c"
    break;

  case 266: /* $@52: %empty  */
#line 1184 "codegen.y"
       {
              // i_tb.deleteVariables();
              scopeLevel--;
       }
#line 4008 "codegen.tab.c"
    break;

  case 279: /* $@53: %empty  */
#line 1200 "codegen.y"
                                           {scopeLevel++;}
#line 4014 "codegen.tab.c"
    break;

  case 280: /* $@54: %empty  */
#line 1201 "codegen.y"
          {
              // i_tb.deleteVariables();
              scopeLevel--;

          }
#line 4024 "codegen.tab.c"
    break;

  case 285: /* $@55: %empty  */
#line 1214 "codegen.y"
           { 
              task_array.clear(); task_array.push_back("void"); 
       }
#line 4032 "codegen.tab.c"
    break;

  case 286: /* $@56: %empty  */
#line 1216 "codegen.y"
                    {        
              task_array.push_back(std::string((yyvsp[0].attr).ID)); 
       }
#line 4040 "codegen.tab.c"
    break;

  case 287: /* $@57: %empty  */
#line 1218 "codegen.y"
               { 
                     task_array.push_back(std::string((yyvsp[0].attr).token)); 
                     task_array.push_back("int"); 
                     task_array.push_back("tid"); 
                     scopeLevel++;
              }
#line 4051 "codegen.tab.c"
    break;

  case 288: /* $@58: %empty  */
#line 1223 "codegen.y"
                      { 
              task_array.push_back(")"); 
              fprintf(yyout, " : task declaration statement"); 

              fprintf(fpcpp,"\n%s", FuncDeclGen(task_array).c_str());      

       }
#line 4063 "codegen.tab.c"
    break;

  case 289: /* $@59: %empty  */
#line 1230 "codegen.y"
       {
              // i_tb.deleteVariables();
              scopeLevel--;
       }
#line 4072 "codegen.tab.c"
    break;

  case 297: /* $@60: %empty  */
#line 1242 "codegen.y"
                                         {scopeLevel++;}
#line 4078 "codegen.tab.c"
    break;

  case 298: /* $@61: %empty  */
#line 1243 "codegen.y"
        {
              // i_tb.deleteVariables();
              scopeLevel--;
        }
#line 4087 "codegen.tab.c"
    break;

  case 312: /* $@62: %empty  */
#line 1261 "codegen.y"
                                           { scopeLevel++;}
#line 4093 "codegen.tab.c"
    break;

  case 313: /* $@63: %empty  */
#line 1262 "codegen.y"
          {
              // i_tb.deleteVariables();
              scopeLevel--;
          }
#line 4102 "codegen.tab.c"
    break;

  case 323: /* subroutine_arrow: %empty  */
#line 1278 "codegen.y"
                         {
       fprintf(fpcpp, ".");
}
#line 4110 "codegen.tab.c"
    break;

  case 324: /* access: IDENTIFIER subroutine_id ARROW subroutine_arrow id  */
#line 1283 "codegen.y"
       {
              /*$1.datatype should be from an existing class*/ 
              t_state = ((yyvsp[-4].attr).datatype);
       }
#line 4119 "codegen.tab.c"
    break;

  case 325: /* id: IDENTIFIER subroutine_id  */
#line 1290 "codegen.y"
        {
              t_state = ((yyvsp[-1].attr).datatype); 
              (yyval.attr).datatype = ((yyvsp[-1].attr).datatype);
       }
#line 4128 "codegen.tab.c"
    break;

  case 326: /* id: id ARROW subroutine_arrow IDENTIFIER subroutine_id  */
#line 1295 "codegen.y"
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
#line 4143 "codegen.tab.c"
    break;

  case 327: /* $@64: %empty  */
#line 1309 "codegen.y"
                { //////////////////////////////// COMPLETED ///////////////////////////////
       fprintf(yyout, " : start declaration statement");
       fprintf(fpcpp,"int main() ");
       scopeLevel++;
       startCount++;
              if(startCount > 1){
                     // printError(yylineno, START_ERROR_MORE);
                     return 1;    
              }
       }
#line 4158 "codegen.tab.c"
    break;

  case 328: /* $@65: %empty  */
#line 1319 "codegen.y"
       {
              // i_tb.deleteVariables();
              scopeLevel--;
       }
#line 4167 "codegen.tab.c"
    break;

  case 329: /* $@66: %empty  */
#line 1322 "codegen.y"
         {fprintf(fpcpp, "\treturn 0;\n\n");}
#line 4173 "codegen.tab.c"
    break;

  case 340: /* $@67: %empty  */
#line 1334 "codegen.y"
                                      {scopeLevel++;}
#line 4179 "codegen.tab.c"
    break;

  case 341: /* $@68: %empty  */
#line 1335 "codegen.y"
     {
       // i_tb.deleteVariables();
       scopeLevel--;

     }
#line 4189 "codegen.tab.c"
    break;

  case 346: /* subr_public: %empty  */
#line 1346 "codegen.y"
                    { fprintf(fpcpp, "\npublic:"); }
#line 4195 "codegen.tab.c"
    break;

  case 347: /* $@69: %empty  */
#line 1348 "codegen.y"
                       {fprintf(fpcpp,"class");}
#line 4201 "codegen.tab.c"
    break;

  case 348: /* $@70: %empty  */
#line 1349 "codegen.y"
              { 
                     // types_set.insert($2.token); 
                     fprintf(fpcpp,"%s",(yyvsp[0].attr).token);
                     // if(c_tb.searchType($3.ID)){
                     //        printError(yylineno,TYPE_REDECLARATION);
                     //        return 1;
                     // }
                     curr_type = ((yyvsp[0].attr).ID);
                     fprintf(yyout, " : type declaration statement"); 

              }
#line 4217 "codegen.tab.c"
    break;

  case 349: /* $@71: %empty  */
#line 1359 "codegen.y"
                                               { scopeLevel++;}
#line 4223 "codegen.tab.c"
    break;

  case 350: /* $@72: %empty  */
#line 1360 "codegen.y"
              {
                     // i_tb.deleteVariables();
                     scopeLevel--;
                     curr_type = NULL ;

              }
#line 4234 "codegen.tab.c"
    break;

  case 351: /* $@73: %empty  */
#line 1365 "codegen.y"
                {
                     fprintf(fpcpp, "\t%s() = default;\n", (yyvsp[-8].attr).token);
                     fprintf(fpcpp, "\t%s(const %s&) = default;\n", (yyvsp[-8].attr).token, (yyvsp[-8].attr).token);
                     fprintf(fpcpp, "\t%s& operator = (const %s&) = default;\n", (yyvsp[-8].attr).token, (yyvsp[-8].attr).token);
                     fprintf(fpcpp, "\t~%s() = default;\n", (yyvsp[-8].attr).token);

              }
#line 4246 "codegen.tab.c"
    break;

  case 352: /* type_declaration: TYPE $@69 TYPENAME $@70 SCOPEOPEN subroutine_openscope $@71 subr_public type_scope methods $@72 $@73 SCOPECLOSE subroutine_closescope  */
#line 1371 "codegen.y"
                                                 {fprintf(fpcpp, ";");}
#line 4252 "codegen.tab.c"
    break;

  case 355: /* declaration_t: declarationStmt_t SEMICOLON subroutine_token  */
#line 1377 "codegen.y"
              { 
                     fprintf(yyout, " : declaration statement"); 
              }
#line 4260 "codegen.tab.c"
    break;

  case 356: /* declarationStmt_t: simpleDatatype simpleList_t  */
#line 1383 "codegen.y"
                     {
                            dt_state = ((yyvsp[-1].attr).datatype);
                            array_state = (yyvsp[-1].attr).is_array;
                            atomic_state = (yyvsp[-1].attr).is_atomic;
                     }
#line 4270 "codegen.tab.c"
    break;

  case 357: /* declarationStmt_t: arrayDatatype arrayList_t  */
#line 1389 "codegen.y"
                     {
                            dt_state = ((yyvsp[-1].attr).datatype);
                            array_state = (yyvsp[-1].attr).is_array;
                            atomic_state = (yyvsp[-1].attr).is_atomic;
                     }
#line 4280 "codegen.tab.c"
    break;

  case 358: /* simpleList_t: IDENTIFIER subroutine_id  */
#line 1397 "codegen.y"
                     {
                            (yyvsp[-1].attr).datatype = (dt_state);
                            (yyvsp[-1].attr).is_array = array_state;
                            (yyvsp[-1].attr).is_atomic = atomic_state;

                            // if(attr_tb.searchAttribute($1.ID, curr_type) == ""){
                            //        attr_tb.addVariable($1.ID, curr_type, $1.datatype, $1.is_atomic, $1.is_array);
                            // }else {
                            //        printError(yylineno,TYPE_ATTR_REDECLARATION);
                            //        return 1;
                            // }
                            /*
                            Insert in ATTRIBBUTES TABLE $1.ID, dt_state, array_state, atomic_state, class_name will
                            be the last one from the types_Set
                            */
                     }
#line 4301 "codegen.tab.c"
    break;

  case 359: /* simpleList_t: simpleList COMMA subroutine_token IDENTIFIER subroutine_id  */
#line 1414 "codegen.y"
                     {
                            (yyvsp[-1].attr).datatype = (dt_state);
                            (yyvsp[-1].attr).is_array = array_state;
                            (yyvsp[-1].attr).is_atomic = atomic_state;
                            // if(attr_tb.searchAttribute($4.ID, curr_type) == ""){
                            //        attr_tb.addVariable($4.ID, curr_type, $4.datatype, $4.is_atomic, $4.is_array);
                            // }else {
                            //        printError(yylineno,TYPE_ATTR_REDECLARATION);
                            //        return 1;
                            // }
                            /*
                            Insert in ATTRIBUTES TABLE $3.ID, dt_state, array_state, atomic_state, class_name will
                            be the last one from the types_Set
                            */
                     }
#line 4321 "codegen.tab.c"
    break;

  case 360: /* simpleList_t: IDENTIFIER subroutine_id EQ subroutine_token RHS  */
#line 1430 "codegen.y"
                     {
                            (yyvsp[-4].attr).datatype = (dt_state);
                            (yyvsp[-4].attr).is_array = array_state;
                            (yyvsp[-4].attr).is_atomic = atomic_state;

                            // if(attr_tb.searchAttribute($1.ID, curr_type) == ""){
                            //        attr_tb.addVariable($1.ID, curr_type, $1.datatype, $1.is_atomic, $1.is_array);
                            // }else {
                            //        printError(yylineno,TYPE_ATTR_REDECLARATION);
                            //        return 1;
                            // }
                            /*
                            Insert in ATTRIBUTES TABLE $1.ID, dt_state, array_state, atomic_state, class_name will
                            be the last one from the types_Set + TYPE CHECK FOR COERCIBILITY OF
                            dt_state and RHS.datatype
                            */
                     }
#line 4343 "codegen.tab.c"
    break;

  case 361: /* simpleList_t: simpleList COMMA subroutine_token IDENTIFIER subroutine_id EQ subroutine_token RHS  */
#line 1448 "codegen.y"
                     {
                            (yyvsp[-4].attr).datatype = (dt_state);
                            (yyvsp[-4].attr).is_array = array_state;
                            (yyvsp[-4].attr).is_atomic = atomic_state;

                            // if(attr_tb.searchAttribute($4.ID, curr_type) == ""){
                            //        attr_tb.addVariable($4.ID, curr_type, $4.datatype, $4.is_atomic, $4.is_array);
                            // }else {
                            //        printError(yylineno,TYPE_ATTR_REDECLARATION);
                            //        return 1;
                            // }
                            /*
                            Insert in ATTRIBUTES TABLE $3.ID, dt_state, array_state, atomic_state, class_name
                            will be the last one from the types_Set+ TYPE CHECK FOR COERCIBILITY OF
                            dt_state and RHS.datatype
                            */
                     }
#line 4365 "codegen.tab.c"
    break;

  case 362: /* arrayList_t: IDENTIFIER subroutine_id SQUAREOPEN subroutine_token dimlist SQUARECLOSE subroutine_token  */
#line 1468 "codegen.y"
                     {
                            (yyvsp[-6].attr).datatype = (dt_state);
                            (yyvsp[-6].attr).is_array = array_state;
                            (yyvsp[-6].attr).is_atomic = atomic_state;
                            

                            // if(attr_tb.searchAttribute($1.ID, curr_type) == ""){
                            //        attr_tb.addVariable($1.ID, curr_type, $1.datatype, $1.is_atomic, $1.is_array);
                            // }else {
                            //        printError(yylineno,TYPE_ATTR_REDECLARATION);
                            //        return 1;
                            // }
                            /*
                            Insert in ATTRIBUTES $1.ID, dt_state, array_state, class_name will be the
                            last one from the types_Set atomic_state
                            */
                     }
#line 4387 "codegen.tab.c"
    break;

  case 363: /* arrayList_t: arrayList COMMA subroutine_token IDENTIFIER subroutine_id SQUAREOPEN subroutine_token dimlist SQUARECLOSE subroutine_token  */
#line 1486 "codegen.y"
                     {
                            (yyvsp[-6].attr).datatype = (dt_state);
                            (yyvsp[-6].attr).is_array = array_state;
                            (yyvsp[-6].attr).is_atomic = atomic_state;

                            // if(attr_tb.searchAttribute($4.ID, curr_type) == ""){
                            //        attr_tb.addVariable($4.ID, curr_type, $4.datatype, $4.is_atomic, $4.is_array);
                            // }else {
                            //        printError(yylineno,TYPE_ATTR_REDECLARATION);
                            //        return 1;
                            // }

                            /*
                            Insert in ATTRIBUTES TABLE $1.ID, dt_state, array_state, atomic_state, class_name 
                            will be the last one from the types_Set
                            */
                     }
#line 4409 "codegen.tab.c"
    break;

  case 364: /* arrayList_t: IDENTIFIER subroutine_id SQUAREOPEN subroutine_token dimlist SQUARECLOSE subroutine_token EQ subroutine_token RHS  */
#line 1504 "codegen.y"
                     {
                            (yyvsp[-9].attr).datatype = (dt_state);
                            (yyvsp[-9].attr).is_array = array_state;
                            (yyvsp[-9].attr).is_atomic = atomic_state;

                            // if(attr_tb.searchAttribute($1.ID, curr_type) == ""){
                            //        attr_tb.addVariable($1.ID, curr_type, $1.datatype, $1.is_atomic, $1.is_array);
                            // }else {
                            //        printError(yylineno,TYPE_ATTR_REDECLARATION);
                            //        return 1;
                            // }

                            /*
                            Insert in ATTRIBUTES TABLE $1.ID, dt_state, array_state, atomic_state, class_name will be
                            the last one from the types_Set + TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
                            */
                     }
#line 4431 "codegen.tab.c"
    break;

  case 365: /* arrayList_t: arrayList COMMA subroutine_token IDENTIFIER subroutine_id SQUAREOPEN subroutine_token dimlist SQUARECLOSE subroutine_token EQ subroutine_token RHS  */
#line 1522 "codegen.y"
                     {
                            (yyvsp[-9].attr).datatype = (dt_state);
                            (yyvsp[-9].attr).is_array = array_state;
                            (yyvsp[-9].attr).is_atomic = atomic_state;

                            // if(attr_tb.searchAttribute($4.ID, curr_type) == ""){
                            //        attr_tb.addVariable($4.ID, curr_type, $4.datatype, $4.is_atomic, $4.is_array);
                            // }else {
                            //        printError(yylineno,TYPE_ATTR_REDECLARATION);
                            //        return 1;
                            // }
                            /*
                            Insert in ATTRIBUTES TABLE $1.ID, dt_state, array_state, atomic_state, class_name will be the
                            last one from the types_Set + TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
                            */
                     }
#line 4452 "codegen.tab.c"
    break;

  case 368: /* $@74: %empty  */
#line 1545 "codegen.y"
       {
              // i_tb.deleteVariables();
              scopeLevel--;

       }
#line 4462 "codegen.tab.c"
    break;

  case 370: /* $@75: %empty  */
#line 1551 "codegen.y"
                   { method_array.clear(); method_array.push_back(std::string((yyvsp[0].attr).token)); }
#line 4468 "codegen.tab.c"
    break;

  case 371: /* $@76: %empty  */
#line 1551 "codegen.y"
                                                                                                       { method_array.push_back(std::string((yyvsp[0].attr).ID)); }
#line 4474 "codegen.tab.c"
    break;

  case 372: /* $@77: %empty  */
#line 1551 "codegen.y"
                                                                                                                                                              {method_array.push_back(std::string((yyvsp[0].attr).token));  scopeLevel++;}
#line 4480 "codegen.tab.c"
    break;

  case 373: /* $@78: %empty  */
#line 1551 "codegen.y"
                                                                                                                                                                                                                                         {method_array.push_back(std::string((yyvsp[0].attr).token)); }
#line 4486 "codegen.tab.c"
    break;

  case 374: /* func_decl_m: FUNC $@75 IDENTIFIER $@76 COLON $@77 args COLON $@78 func_return  */
#line 1552 "codegen.y"
              { 
              /*
              Add args as they are encountered in the IDENTIFIER TABLE, 
              IN METHODS TABLE: $2.ID is method name, decl_arg_dats will be ready, 
              return_type is $6.datatype, $6.is_array class name will be the last element in the types_set
              */ 
                     decl_arg_dat.clear(); fprintf(yyout, " : function declaration statement"); 
                     fprintf(fpcpp,"\n\t%s", FuncDeclGen(method_array).c_str());
              }
#line 4500 "codegen.tab.c"
    break;

  case 375: /* method_invoke2: method_invoke SEMICOLON  */
#line 1563 "codegen.y"
                                          { fprintf(yyout, " : call statement");  fprintf(fpcpp,"%s",(yyvsp[0].attr).token);}
#line 4506 "codegen.tab.c"
    break;

  case 378: /* method_invoke: INVOKE id ARROW subroutine_arrow IDENTIFIER subroutine_id COLON subroutine_roundopen method_args COLON subroutine_roundclose  */
#line 1568 "codegen.y"
              {
                     arg_dat.clear();
              }
#line 4514 "codegen.tab.c"
    break;

  case 379: /* in_stmt: IN subr_this ARROW subroutine_token IDENTIFIER subroutine_id  */
#line 1574 "codegen.y"
       {
              /*
              In this check if $3.datatype = last element in the type set
              */
       }
#line 4524 "codegen.tab.c"
    break;

  case 380: /* in_stmt: INVOKE IN subr_this ARROW subroutine_token IDENTIFIER subroutine_id COLON subroutine_roundopen arguments COLON subroutine_roundclose  */
#line 1580 "codegen.y"
       {
              /*
              In this check if $4.ID exists in the methods table whose class is last element in the types_set
               + TYPE CHECK FOR PARARMETERS AND RETURN TYPES, SAME AS FUNCTION
              */
       }
#line 4535 "codegen.tab.c"
    break;

  case 381: /* in_stmt: INVOKE IN subr_this ARROW subroutine_token IDENTIFIER subroutine_id COLON subroutine_roundopen NULL_ARGS COLON subroutine_roundclose  */
#line 1587 "codegen.y"
       {
              /*
              In this check if $4.ID exists in the methods table whose class is last element in the types_set + 
              TYPE CHECK FOR PARARMETERS AND RETURN TYPES, SAME AS FUNCTION
                     */
       }
#line 4546 "codegen.tab.c"
    break;

  case 394: /* $@79: %empty  */
#line 1606 "codegen.y"
                                                  {scopeLevel++;}
#line 4552 "codegen.tab.c"
    break;

  case 395: /* $@80: %empty  */
#line 1607 "codegen.y"
                 {
                     scopeLevel--;
                 }
#line 4560 "codegen.tab.c"
    break;

  case 398: /* return_statement_m: RETURN subroutine_token RHS SEMICOLON subroutine_token  */
#line 1614 "codegen.y"
              { 
                     (yyval.attr).datatype = (yyvsp[-2].attr).datatype; 
                     (yyval.attr).is_array = (yyvsp[-2].attr).is_array; 
                     fprintf(yyout, " : return statement"); 
              }
#line 4570 "codegen.tab.c"
    break;

  case 399: /* return_statement_m: RETURN subroutine_token NVOID SEMICOLON subroutine_token  */
#line 1620 "codegen.y"
              { 
                     (yyval.attr).datatype = (yyvsp[-2].attr).datatype; 
                     (yyval.attr).is_array = (yyvsp[-2].attr).is_array; 
                     fprintf(yyout, " : return statement"); 
              }
#line 4580 "codegen.tab.c"
    break;


#line 4584 "codegen.tab.c"

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

#line 1630 "codegen.y"

// io1 = 0;
void yyerror(std::string s){
  std::cout << "Syntax Error: " << s << " at line number - " << yylineno << std::endl;
}



