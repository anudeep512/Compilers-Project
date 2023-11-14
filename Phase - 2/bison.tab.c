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
  #include<fstream>

  extern int yylex();
  extern int yylineno;
  extern FILE * yyout;
  void yyerror(std::string s);

#line 82 "bison.tab.c"

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

#include "bison.tab.h"
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
  YYSYMBOL_T = 104,                        /* T  */
  YYSYMBOL_all_ops = 105,                  /* all_ops  */
  YYSYMBOL_constants = 106,                /* constants  */
  YYSYMBOL_next = 107,                     /* next  */
  YYSYMBOL_RHS = 108,                      /* RHS  */
  YYSYMBOL_nonAtomicSimple = 109,          /* nonAtomicSimple  */
  YYSYMBOL_atomicSimple = 110,             /* atomicSimple  */
  YYSYMBOL_nonAtomicArray = 111,           /* nonAtomicArray  */
  YYSYMBOL_atomicArray = 112,              /* atomicArray  */
  YYSYMBOL_declaration = 113,              /* declaration  */
  YYSYMBOL_simpleDatatype = 114,           /* simpleDatatype  */
  YYSYMBOL_arrayDatatype = 115,            /* arrayDatatype  */
  YYSYMBOL_declarationStmt = 116,          /* declarationStmt  */
  YYSYMBOL_simpleList = 117,               /* simpleList  */
  YYSYMBOL_arrayList = 118,                /* arrayList  */
  YYSYMBOL_array_inValues = 119,           /* array_inValues  */
  YYSYMBOL_dimlist = 120,                  /* dimlist  */
  YYSYMBOL_LHS = 121,                      /* LHS  */
  YYSYMBOL_arr_access = 122,               /* arr_access  */
  YYSYMBOL_exprlist = 123,                 /* exprlist  */
  YYSYMBOL_arith_operand = 124,            /* arith_operand  */
  YYSYMBOL_arith_expr = 125,               /* arith_expr  */
  YYSYMBOL_assignment_statement = 126,     /* assignment_statement  */
  YYSYMBOL_expression_statement = 127,     /* expression_statement  */
  YYSYMBOL_exprrr = 128,                   /* exprrr  */
  YYSYMBOL_log = 129,                      /* log  */
  YYSYMBOL_g = 130,                        /* g  */
  YYSYMBOL_both_assignment = 131,          /* both_assignment  */
  YYSYMBOL_loop = 132,                     /* loop  */
  YYSYMBOL_for_loop = 133,                 /* for_loop  */
  YYSYMBOL_134_1 = 134,                    /* $@1  */
  YYSYMBOL_while_loop = 135,               /* while_loop  */
  YYSYMBOL_136_2 = 136,                    /* $@2  */
  YYSYMBOL_conditional = 137,              /* conditional  */
  YYSYMBOL_when_statement = 138,           /* when_statement  */
  YYSYMBOL_139_3 = 139,                    /* $@3  */
  YYSYMBOL_140_4 = 140,                    /* $@4  */
  YYSYMBOL_when_default = 141,             /* when_default  */
  YYSYMBOL_142_5 = 142,                    /* $@5  */
  YYSYMBOL_analysis_arrays = 143,          /* analysis_arrays  */
  YYSYMBOL_analyze_label = 144,            /* analyze_label  */
  YYSYMBOL_analyze_statement = 145,        /* analyze_statement  */
  YYSYMBOL_analyze_syntax = 146,           /* analyze_syntax  */
  YYSYMBOL_func_invoke2 = 147,             /* func_invoke2  */
  YYSYMBOL_func_invoke = 148,              /* func_invoke  */
  YYSYMBOL_arguments = 149,                /* arguments  */
  YYSYMBOL_task_invoke = 150,              /* task_invoke  */
  YYSYMBOL_get_invoke = 151,               /* get_invoke  */
  YYSYMBOL_sleep = 152,                    /* sleep  */
  YYSYMBOL_file_name = 153,                /* file_name  */
  YYSYMBOL_input = 154,                    /* input  */
  YYSYMBOL_nextip = 155,                   /* nextip  */
  YYSYMBOL_stringvalues = 156,             /* stringvalues  */
  YYSYMBOL_return_statement = 157,         /* return_statement  */
  YYSYMBOL_output = 158,                   /* output  */
  YYSYMBOL_opstring = 159,                 /* opstring  */
  YYSYMBOL_nextop = 160,                   /* nextop  */
  YYSYMBOL_function = 161,                 /* function  */
  YYSYMBOL_func_args = 162,                /* func_args  */
  YYSYMBOL_args = 163,                     /* args  */
  YYSYMBOL_func_return = 164,              /* func_return  */
  YYSYMBOL_func_decl = 165,                /* func_decl  */
  YYSYMBOL_atomic_func_decl = 166,         /* atomic_func_decl  */
  YYSYMBOL_func_body = 167,                /* func_body  */
  YYSYMBOL_func_scope = 168,               /* func_scope  */
  YYSYMBOL_func_statements = 169,          /* func_statements  */
  YYSYMBOL_task = 170,                     /* task  */
  YYSYMBOL_171_6 = 171,                    /* $@6  */
  YYSYMBOL_taskscope = 172,                /* taskscope  */
  YYSYMBOL_statement = 173,                /* statement  */
  YYSYMBOL_statements = 174,               /* statements  */
  YYSYMBOL_access = 175,                   /* access  */
  YYSYMBOL_id = 176,                       /* id  */
  YYSYMBOL_startdec = 177,                 /* startdec  */
  YYSYMBOL_start = 178,                    /* start  */
  YYSYMBOL_type_declaration = 179,         /* type_declaration  */
  YYSYMBOL_180_7 = 180,                    /* $@7  */
  YYSYMBOL_type_scope = 181,               /* type_scope  */
  YYSYMBOL_methods = 182,                  /* methods  */
  YYSYMBOL_method = 183,                   /* method  */
  YYSYMBOL_method_invoke2 = 184,           /* method_invoke2  */
  YYSYMBOL_method_args = 185,              /* method_args  */
  YYSYMBOL_method_invoke = 186,            /* method_invoke  */
  YYSYMBOL_in_stmt = 187,                  /* in_stmt  */
  YYSYMBOL_method_statements = 188,        /* method_statements  */
  YYSYMBOL_method_body = 189               /* method_body  */
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
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1497

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  95
/* YYNRULES -- Number of rules.  */
#define YYNRULES  285
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  510

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
       0,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      57,    57,    57,    57,    58,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    60,    60,    61,    61,
      63,    64,    65,    66,    67,    68,    74,    75,    78,    79,
      82,    83,    84,    85,    86,    89,    90,    91,    92,    93,
      96,    97,   100,   101,   102,   103,   103,   103,   104,   105,
     106,   110,   110,   110,   110,   110,   110,   111,   111,   111,
     111,   111,   113,   113,   113,   113,   113,   114,   114,   114,
     114,   114,   119,   122,   122,   122,   122,   123,   123,   123,
     123,   125,   126,   129,   130,   131,   132,   135,   136,   137,
     138,   141,   141,   143,   144,   147,   148,   149,   152,   155,
     156,   159,   160,   161,   162,   165,   166,   170,   173,   175,
     175,   178,   179,   182,   183,   186,   186,   187,   191,   191,
     194,   194,   197,   197,   202,   205,   205,   206,   206,   210,
     210,   211,   214,   214,   214,   214,   217,   217,   219,   221,
     221,   227,   230,   231,   235,   236,   241,   242,   246,   249,
     250,   253,   254,   255,   258,   262,   263,   269,   270,   274,
     275,   278,   284,   287,   288,   293,   293,   295,   295,   297,
     297,   299,   300,   303,   305,   308,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   318,   318,   319,   320,   323,
     324,   328,   328,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   360,   361,   365,
     366,   367,   372,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   392,   392,   395,   395,
     399,   400,   403,   406,   408,   408,   410,   411,   414,   415,
     416,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   434,   435
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
  "logical_op", "nonAtomic_datatypes", "begin", "E", "T", "all_ops",
  "constants", "next", "RHS", "nonAtomicSimple", "atomicSimple",
  "nonAtomicArray", "atomicArray", "declaration", "simpleDatatype",
  "arrayDatatype", "declarationStmt", "simpleList", "arrayList",
  "array_inValues", "dimlist", "LHS", "arr_access", "exprlist",
  "arith_operand", "arith_expr", "assignment_statement",
  "expression_statement", "exprrr", "log", "g", "both_assignment", "loop",
  "for_loop", "$@1", "while_loop", "$@2", "conditional", "when_statement",
  "$@3", "$@4", "when_default", "$@5", "analysis_arrays", "analyze_label",
  "analyze_statement", "analyze_syntax", "func_invoke2", "func_invoke",
  "arguments", "task_invoke", "get_invoke", "sleep", "file_name", "input",
  "nextip", "stringvalues", "return_statement", "output", "opstring",
  "nextop", "function", "func_args", "args", "func_return", "func_decl",
  "atomic_func_decl", "func_body", "func_scope", "func_statements", "task",
  "$@6", "taskscope", "statement", "statements", "access", "id",
  "startdec", "start", "type_declaration", "$@7", "type_scope", "methods",
  "method", "method_invoke2", "method_args", "method_invoke", "in_stmt",
  "method_statements", "method_body", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-427)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1357,   -29,    19,    21,     3,    26,    36,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,   123,
    -427,  -427,  -427,  -427,  1357,    69,    72,    85,  1357,    90,
      90,  1357,  1357,  1357,    95,  1222,  -427,    56,    94,  -427,
    -427,    98,  -427,  -427,   124,   102,    96,   104,  -427,  -427,
    1101,  -427,  -427,  -427,  -427,  -427,  1277,   106,   113,   114,
     120,    27,    99,    -6,   125,   149,   137,    -1,  1222,  1222,
     336,   139,   141,  1222,  1222,  -427,  -427,  1222,    31,  1222,
    1222,   144,  1222,  1222,  1222,  1222,  -427,   140,  1222,   152,
     151,  -427,   155,  1277,   121,   150,    34,   160,    52,  1101,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  1101,   162,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,   161,
    -427,  -427,   166,  -427,   121,   121,   134,   175,  -427,  -427,
     176,    47,    32,    39,   177,    48,   179,   -16,   174,  -427,
     121,  -427,  -427,  -427,  -427,  -427,  -427,   121,  -427,  -427,
    -427,  -427,  -427,   172,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  1380,  1277,   182,  -427,
     207,   219,     9,   187,  -427,  -427,  -427,  -427,  -427,   190,
     121,  -427,  -427,  -427,  -427,  -427,  -427,  -427,   221,  -427,
    -427,  -427,    18,   193,   217,   218,   210,  -427,  -427,  -427,
    1403,   223,   211,   230,   205,   222,   225,   246,  -427,   240,
     -16,    27,   244,   248,   253,   492,  -427,   289,  -427,  -427,
     264,  -427,  -427,   259,   149,   294,  -427,  -427,  -427,   -16,
     265,   274,  -427,   159,  1222,  -427,  -427,   121,   271,  1380,
    -427,   275,   192,   318,   278,   306,   121,   -16,  -427,   917,
     121,    34,   307,    34,  -427,  -427,  -427,   283,  1254,  -427,
    -427,   280,   320,   297,   121,   199,   298,   300,   303,   311,
     321,  -427,    58,   323,    92,    48,  -427,   327,   334,   136,
    -427,   -16,  -427,  -427,  -427,  -427,  -427,  -427,   -16,  -427,
     312,  1012,  -427,     6,   192,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,   338,   316,   330,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,   121,
    -427,  -427,   121,    22,  -427,  1254,  1254,  1254,  1254,  1254,
    1254,  1254,  1254,   340,  1254,   342,   343,  -427,   121,   345,
     347,   -16,    42,  -427,  -427,   740,  -427,   121,  -427,   349,
     348,  -427,  -427,   259,  -427,  -427,  -427,   159,  -427,  -427,
     353,   355,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  1012,   354,  -427,  -427,   358,  -427,  -427,
     357,  -427,  -427,   356,   272,  -427,   386,   360,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  1012,  1012,  -427,
     388,    50,   215,  -427,  -427,  -427,  -427,   366,  -427,   369,
     368,  -427,   740,    92,  -427,   370,  -427,  -427,  -427,  -427,
    1133,   805,  -427,   121,   121,  1254,   365,   367,   121,   222,
     351,  -427,   364,   865,    42,  -427,   374,  -427,  1012,  1133,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  1133,   373,   378,    64,  -427,  -427,  -427,  -427,
    -427,  -427,   375,  -427,   379,    89,   380,  -427,   384,   385,
    -427,  -427,  -427,  -427,  -427,   381,   391,   393,    42,   394,
    -427,  -427,  1012,  -427,  -427,   380,  -427,   387,  -427,  -427
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
      40,     0,     0,     0,     0,     0,     0,    71,    72,    73,
      74,    75,    76,    82,    83,    84,    85,    86,    77,    78,
      79,    80,    81,    87,    88,    89,    90,    91,    95,     0,
      93,    94,    97,    98,    40,     0,     0,     0,    40,     0,
       0,    40,    40,    40,     0,   255,   256,     0,     0,    96,
      99,     0,     1,    42,   103,   101,     0,   102,    92,    43,
     210,   185,   186,    44,    41,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   173,     0,   115,   255,   255,
       0,     0,     0,   255,   255,   138,   139,   255,   151,   255,
     255,     0,   255,   255,   255,   255,   117,     0,   255,     0,
       0,   100,     0,     0,     0,     0,     0,     0,     0,   210,
     196,   197,   200,   202,   203,   199,   198,   206,   204,   201,
     205,   210,     0,   208,   190,     8,     7,     6,    10,     9,
      15,    12,    11,    13,    14,     2,     3,     4,     5,     0,
      16,    17,   189,   211,     0,     0,     0,     0,   156,   157,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   243,
       0,    22,    23,    20,    19,    18,    21,     0,   131,   132,
     244,   246,   245,     0,   149,   144,   249,   247,   161,   248,
     253,   251,   250,   242,   254,   263,   259,     0,     0,    64,
       0,     0,     0,     0,    55,    59,    56,    58,    57,    46,
       0,    63,    62,   105,    49,    65,    66,    67,   104,   111,
     112,   114,     0,     0,     0,     0,     0,   209,   195,   187,
       0,     0,     0,     0,     0,     0,     0,     0,   135,     0,
       0,     0,     0,     0,     0,     0,   240,     0,   171,   172,
       0,   177,   178,   184,   173,   239,   122,   123,   121,     0,
       0,   118,   126,   119,   255,   127,   128,     0,     0,   259,
     261,     0,     0,     0,     0,     0,     0,     0,    48,     0,
       0,     0,   107,     0,   180,   179,   207,     0,   222,   145,
     142,     0,     0,   137,     0,     0,     0,     0,     0,     0,
       0,   165,     0,     0,     0,     0,   182,     0,     0,     0,
     116,     0,    33,    30,    31,    32,    35,    34,     0,   252,
       0,   238,   258,     0,     0,   192,   191,    39,    38,   193,
     168,   268,     0,     0,     0,    54,    36,    37,    25,    24,
      26,    27,    28,    29,    69,    53,    51,    50,    52,     0,
     106,   113,     0,     0,   188,   222,   222,   222,   222,   222,
     222,   222,   222,     0,   222,     0,     0,   136,     0,     0,
       0,     0,     0,   170,   169,     0,   163,     0,   162,   241,
       0,   176,   174,   184,   181,   241,   124,   120,   125,   147,
       0,     0,   223,   224,   226,   225,   230,   228,   229,   232,
     235,   227,   231,   238,     0,   236,   257,     0,   260,   194,
       0,    70,    47,     0,    61,   109,   108,     0,   213,   214,
     216,   215,   217,   220,   218,   212,   221,   238,   238,   133,
       0,     0,     0,   153,   152,   155,   154,     0,   265,   264,
       0,   164,     0,     0,   183,     0,   233,   234,   237,   150,
     285,     0,    68,     0,     0,   222,     0,     0,     0,     0,
       0,   129,     0,     0,     0,   266,     0,   175,   238,     0,
     271,   272,   275,   277,   278,   274,   273,   281,   279,   276,
     280,   283,   285,     0,     0,     0,    60,   110,   219,   146,
     143,   134,     0,   140,     0,     0,   160,   267,     0,     0,
     284,   262,   270,   269,   130,     0,     0,     0,     0,     0,
     148,   282,   238,   167,   166,   160,   158,     0,   159,   141
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -427,   233,  -427,  -427,  -261,  -427,  -427,    97,  -427,  -427,
      37,  -427,    11,   616,  -243,  -427,   -63,   -57,     0,   309,
    -427,  -427,  -427,  -427,   186,   197,  -142,   206,  -427,   168,
    -220,  -132,  -376,  -427,   -59,  -427,  -427,    16,  -427,  -427,
    -427,  -427,   117,  -427,  -427,  -427,  -427,  -427,  -426,   229,
     189,   -28,   133,   545,  -230,   200,  -427,   220,   242,   216,
      57,   194,   -58,   276,  -427,   118,  -427,  -427,   -90,   178,
     180,  -427,   454,  -427,   -39,  -427,  -427,  -293,  -427,  -369,
    -427,   339,  -427,   -72,  -427,  -427,   237,  -427,  -427,   392,
      65,   569,  -427,    40,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   139,   167,   336,   308,   338,   316,    29,   268,   201,
     339,   202,   403,   291,    30,    31,    32,    33,    79,    35,
      36,    37,    55,    57,   211,   212,    80,   250,   251,   252,
     253,    81,    82,   452,    83,   283,   229,    84,    85,   495,
      86,   356,    87,    88,   355,   435,   175,   258,   427,   150,
      89,   499,    90,    91,   429,    92,   205,    93,   154,    94,
     372,   243,   391,    95,   244,   296,    38,   142,   143,   319,
      39,    40,    61,   121,   122,    41,   221,   353,   393,   394,
      96,   237,    42,    97,    43,   100,   260,   313,   398,    98,
     430,    99,   207,   472,   473
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,   111,   119,   140,   227,   292,   158,   159,   337,   141,
     285,   170,   171,   188,   228,   172,    47,   176,   177,   317,
     179,   180,   181,   182,   438,    47,   184,    48,   486,   299,
       6,    44,   265,   156,    34,   246,   173,   174,    34,   247,
     140,    34,    34,    34,   248,   451,   141,   249,   446,   447,
     111,   119,   407,   408,   409,   410,   411,   412,   413,   414,
     110,   416,   111,   119,   157,   189,   234,   190,   396,   152,
     216,   317,   505,   482,   271,   191,   112,   192,   271,   148,
      45,   377,   217,   227,   272,   209,    49,   149,   406,   488,
     235,   238,   236,   281,   210,    49,    51,   261,   232,   239,
     241,   193,   233,   194,   195,   196,   197,   198,   242,   110,
      77,    46,   199,   449,   367,   200,   368,   423,   424,    50,
     367,   110,   493,    52,   140,   112,   214,   425,   426,    54,
     141,    53,    56,   507,   189,    59,   190,   112,    63,    64,
      65,   422,    58,   337,   191,   367,   192,   497,   370,   371,
     101,    60,   478,    66,   102,   224,   103,   140,   105,   104,
     107,   106,   151,   141,   302,   303,   304,   305,   306,   307,
     193,   144,   194,   195,   196,   197,   198,   113,   145,   146,
     147,   199,   309,   153,   200,   152,   259,   302,   303,   304,
     305,   306,   307,   115,    77,   155,   168,   225,   169,   318,
     376,   178,   183,     7,     8,     9,    10,    11,    12,   185,
     208,   475,   186,   187,    18,    19,    20,    21,    22,   347,
     213,   219,   220,   485,   218,    28,   113,   302,   303,   304,
     305,   306,   307,   230,   231,   240,   254,   257,   113,   236,
     262,   263,   115,   302,   303,   304,   305,   306,   307,   114,
     266,   318,   383,   264,   115,   267,   270,   361,   273,   259,
     116,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,   276,   453,   274,   275,   118,   279,   346,   450,
     117,   160,    77,   315,   278,   282,   347,   347,   347,   347,
     347,   347,   347,   347,   348,   347,   280,    49,   114,   284,
     302,   303,   304,   305,   306,   307,   325,   450,   287,   116,
     114,   382,   288,   289,   326,   327,   328,   329,   330,   331,
     332,   116,   333,   293,   294,   118,   295,   384,   298,   117,
     301,   300,   311,   314,   383,   320,   120,   118,   321,   335,
     322,   117,   342,   344,   357,   346,   346,   346,   346,   346,
     346,   346,   346,   359,   346,   358,   362,   363,   383,   383,
     364,   348,   348,   348,   348,   348,   348,   348,   348,   365,
     348,   160,   161,   162,   163,   164,   165,   166,   379,   366,
     401,   461,   469,   369,   374,   120,   347,   161,   162,   163,
     164,   165,   166,   382,   375,   349,   402,   120,   400,   383,
     461,   469,   415,   417,   418,   420,   421,   432,   433,   384,
     436,   350,   437,   461,   469,   441,   439,   382,   382,   440,
     442,   444,   445,   448,   454,   367,   455,   479,   385,   480,
     483,   458,   487,   384,   384,   491,   492,   496,   498,   494,
     460,   443,   502,   383,   387,   346,   500,   501,   503,   509,
     504,   506,   123,   277,   476,   226,   462,   341,   382,   460,
     286,   348,   349,   349,   349,   349,   349,   349,   349,   349,
     343,   349,   460,   324,   384,   462,   378,   508,   350,   350,
     350,   350,   350,   350,   350,   350,   297,   350,   462,   373,
     457,   434,   399,   397,    62,   245,   312,   456,   351,   489,
     386,   123,   382,     0,   290,   189,     0,   190,     0,     0,
     385,   388,     0,   123,     0,   191,   490,   192,   384,     0,
       0,     0,     0,     0,     0,     0,   387,   390,     0,     0,
       0,   389,     0,     0,   385,   385,     0,     0,     0,     0,
       0,   193,     0,   194,   195,   196,   197,   198,     0,     0,
     387,   387,   199,     0,   352,   200,     0,   463,     0,     0,
       0,     0,   349,     0,     0,   351,   351,   351,   351,   351,
     351,   351,   351,   465,   351,   385,   463,     0,   350,     0,
       0,     0,   386,     0,     0,     0,     0,   392,     0,   463,
       0,   387,   465,   388,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   465,   386,   386,     0,   390,
       0,     0,     0,   389,     0,     0,     0,   388,   388,   385,
       0,   352,   352,   352,   352,   352,   352,   352,   352,   464,
     352,     0,     0,   390,   390,   387,     0,   389,   389,     0,
     466,     0,     0,     0,     0,     0,     0,   386,   464,   204,
       0,     0,     0,   204,     0,     0,   468,     0,   388,   466,
     467,   464,     0,     0,     0,   351,     0,     0,     0,   392,
     354,     0,   466,   206,   390,   468,     0,   206,   389,   467,
       0,     0,     0,     0,     0,     0,     0,     0,   468,   204,
     204,   386,   467,   392,   392,     0,     0,     0,     0,     0,
       0,     0,   388,   395,     0,   204,     0,     0,     0,     0,
       0,     0,   204,   206,   206,     0,   470,     0,   390,     0,
     203,   352,   389,     0,   215,     0,     0,     0,     0,   206,
       0,     0,     0,     0,   392,   470,   206,   354,   354,   354,
     354,   354,   354,   354,   354,   204,   354,     0,   470,     0,
       0,     0,   428,   189,     0,   190,     0,     0,     0,     0,
     222,   223,     0,   191,     0,   192,     0,     0,     0,   206,
       0,     0,     0,     0,     0,     0,   255,     0,   392,     0,
     204,     0,     0,   256,     0,   395,     0,     0,     0,   193,
       0,   194,   195,   196,   197,   198,     0,     0,     0,     0,
     199,     0,   204,   200,   206,     0,     0,     0,     0,   395,
     395,   204,     0,     0,     0,   204,   269,   474,   189,     0,
     190,     0,     0,     0,     0,     0,   206,     0,   191,   204,
     192,     0,   471,     0,     0,   206,     0,   354,     0,   206,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     395,   471,     0,   206,   193,     0,   194,   195,   196,   197,
     198,     0,     0,     0,   471,   199,     0,     0,   200,     0,
       0,     0,     0,   310,     0,     0,     0,   484,   189,     0,
     190,     0,   323,     0,   204,     0,   340,   204,   191,     0,
     192,     0,     0,     0,   395,     0,     0,     0,     0,     0,
     360,     0,     0,   204,     0,     0,     0,     0,   206,     0,
     204,   206,   204,     0,   193,     0,   194,   195,   196,   197,
     198,     0,     0,     0,     0,   199,     0,   206,   200,     0,
       0,     0,     0,     0,   206,     0,   206,     0,     0,     0,
       0,     0,     0,     0,     0,   302,   303,   304,   305,   306,
     307,   325,     0,     0,     0,   404,     0,     0,   405,   326,
     327,   328,   329,   330,   331,   332,     0,   333,     0,     0,
       0,     0,     0,     0,   419,     0,     0,   204,     0,     0,
       0,   334,     0,   431,   335,     0,   204,     0,   204,   204,
       0,     0,     0,   204,     0,     0,     0,     0,   204,     0,
       0,   206,     0,     0,     0,     0,     0,     0,     0,     0,
     206,     0,   206,   206,     0,    67,    68,   206,     0,    69,
     380,   381,   206,    70,     0,     0,    71,     0,    72,     0,
       0,   108,     0,    73,     5,     0,     0,    74,    75,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   404,
     477,     0,     0,     0,   481,     0,     0,     0,     0,     0,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    67,    68,     0,     0,    69,     0,
       0,     0,    70,     0,     0,    71,     0,    72,     0,     0,
     108,     0,    73,     5,     0,     0,    74,    75,    76,     0,
       0,     0,     0,     0,     0,     0,    67,    68,     0,     0,
      69,     0,     0,     0,    70,     0,     0,    71,     0,    72,
       0,     0,   108,     0,    73,     5,     0,     0,    74,    75,
      76,    77,   109,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    77,   459,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    67,    68,     0,     0,    69,
       0,     0,     0,    70,     0,     0,    71,     0,    72,     0,
       0,     0,     0,    73,     5,     0,     0,    74,    75,    76,
       0,     0,     0,     0,     0,     0,     0,    67,    68,     0,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
      72,     0,     0,     0,     0,    73,     5,     0,     0,    74,
       0,    76,    77,    78,     0,     0,     0,     0,     0,   124,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    77,   345,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,   125,   126,   127,   128,
     129,     0,    13,    14,    15,    16,    17,   130,   131,   132,
     133,   134,    23,    24,    25,    26,    27,     1,   135,   136,
     137,   138,     0,     0,     0,     2,     0,     3,     4,     5,
       0,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,   125,   126,   127,   128,   129,     0,    13,    14,
      15,    16,    17,   130,   131,   132,   133,   134,    23,    24,
      25,    26,    27,     0,   135,   136,   137,   138
};

static const yytype_int16 yycheck[] =
{
       0,    60,    60,    66,   146,   235,    78,    79,   269,    66,
     230,    83,    84,   103,   146,    87,    22,    89,    90,   262,
      92,    93,    94,    95,   393,    22,    98,    24,   454,   249,
      24,    60,    23,    34,    34,    51,     5,     6,    38,    55,
     103,    41,    42,    43,    60,   421,   103,    63,   417,   418,
     109,   109,   345,   346,   347,   348,   349,   350,   351,   352,
      60,   354,   121,   121,    65,    13,    34,    15,    62,    60,
     109,   314,   498,   449,    56,    23,    60,    25,    56,    52,
      61,   301,   121,   225,    66,    51,    92,    60,    66,   458,
      58,    52,    60,   225,    60,    92,    60,   187,    51,    60,
      52,    49,    55,    51,    52,    53,    54,    55,    60,   109,
      60,    90,    60,    63,    56,    63,    58,    75,    76,    93,
      56,   121,    58,     0,   187,   109,    74,    85,    86,    60,
     187,    34,    60,   502,    13,    38,    15,   121,    41,    42,
      43,   361,    57,   404,    23,    56,    25,    58,    56,    57,
      94,    61,   445,    58,    60,    21,    58,   220,    56,    35,
      56,    65,    63,   220,    28,    29,    30,    31,    32,    33,
      49,    65,    51,    52,    53,    54,    55,    60,    65,    65,
      60,    60,   254,    34,    63,    60,   186,    28,    29,    30,
      31,    32,    33,    60,    60,    58,    57,    63,    57,   262,
      64,    57,    62,    69,    70,    71,    72,    73,    74,    57,
      60,   441,    61,    58,    80,    81,    82,    83,    84,   278,
      60,    60,    56,   453,    62,    91,   109,    28,    29,    30,
      31,    32,    33,    58,    58,    58,    62,    65,   121,    60,
      58,    34,   109,    28,    29,    30,    31,    32,    33,    60,
      63,   314,   311,    34,   121,    65,    35,    58,    65,   259,
      60,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    62,    58,    57,    57,    60,    66,   278,   421,
      60,    35,    60,    91,    61,    60,   345,   346,   347,   348,
     349,   350,   351,   352,   278,   354,    66,    92,   109,    59,
      28,    29,    30,    31,    32,    33,    34,   449,    64,   109,
     121,   311,    64,    60,    42,    43,    44,    45,    46,    47,
      48,   121,    50,    34,    60,   109,    67,   311,    34,   109,
      56,    66,    61,    58,   393,    17,    60,   121,    60,    67,
      34,   121,    35,    60,    64,   345,   346,   347,   348,   349,
     350,   351,   352,    56,   354,    35,    58,    57,   417,   418,
      57,   345,   346,   347,   348,   349,   350,   351,   352,    58,
     354,    35,    36,    37,    38,    39,    40,    41,    66,    58,
      64,   440,   440,    60,    57,   109,   445,    36,    37,    38,
      39,    40,    41,   393,    60,   278,    66,   121,    60,   458,
     459,   459,    62,    61,    61,    60,    59,    58,    60,   393,
      57,   278,    57,   472,   472,    58,    62,   417,   418,    61,
      64,    35,    62,    35,    58,    56,    58,    62,   311,    62,
      66,    61,    58,   417,   418,    62,    58,    58,    58,    64,
     440,   404,    61,   502,   311,   445,    62,    62,    57,    62,
      57,    57,    60,   220,   443,   146,   440,   271,   458,   459,
     231,   445,   345,   346,   347,   348,   349,   350,   351,   352,
     273,   354,   472,   267,   458,   459,   308,   505,   345,   346,
     347,   348,   349,   350,   351,   352,   244,   354,   472,   295,
     433,   373,   314,   313,    40,   156,   259,   432,   278,   459,
     311,   109,   502,    -1,    12,    13,    -1,    15,    -1,    -1,
     393,   311,    -1,   121,    -1,    23,   472,    25,   502,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   393,   311,    -1,    -1,
      -1,   311,    -1,    -1,   417,   418,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    51,    52,    53,    54,    55,    -1,    -1,
     417,   418,    60,    -1,   278,    63,    -1,   440,    -1,    -1,
      -1,    -1,   445,    -1,    -1,   345,   346,   347,   348,   349,
     350,   351,   352,   440,   354,   458,   459,    -1,   445,    -1,
      -1,    -1,   393,    -1,    -1,    -1,    -1,   311,    -1,   472,
      -1,   458,   459,   393,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   472,   417,   418,    -1,   393,
      -1,    -1,    -1,   393,    -1,    -1,    -1,   417,   418,   502,
      -1,   345,   346,   347,   348,   349,   350,   351,   352,   440,
     354,    -1,    -1,   417,   418,   502,    -1,   417,   418,    -1,
     440,    -1,    -1,    -1,    -1,    -1,    -1,   458,   459,   104,
      -1,    -1,    -1,   108,    -1,    -1,   440,    -1,   458,   459,
     440,   472,    -1,    -1,    -1,   445,    -1,    -1,    -1,   393,
     278,    -1,   472,   104,   458,   459,    -1,   108,   458,   459,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   472,   144,
     145,   502,   472,   417,   418,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   502,   311,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   144,   145,    -1,   440,    -1,   502,    -1,
     104,   445,   502,    -1,   108,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,   458,   459,   167,   345,   346,   347,
     348,   349,   350,   351,   352,   200,   354,    -1,   472,    -1,
      -1,    -1,    12,    13,    -1,    15,    -1,    -1,    -1,    -1,
     144,   145,    -1,    23,    -1,    25,    -1,    -1,    -1,   200,
      -1,    -1,    -1,    -1,    -1,    -1,   160,    -1,   502,    -1,
     235,    -1,    -1,   167,    -1,   393,    -1,    -1,    -1,    49,
      -1,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      60,    -1,   257,    63,   235,    -1,    -1,    -1,    -1,   417,
     418,   266,    -1,    -1,    -1,   270,   200,    12,    13,    -1,
      15,    -1,    -1,    -1,    -1,    -1,   257,    -1,    23,   284,
      25,    -1,   440,    -1,    -1,   266,    -1,   445,    -1,   270,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     458,   459,    -1,   284,    49,    -1,    51,    52,    53,    54,
      55,    -1,    -1,    -1,   472,    60,    -1,    -1,    63,    -1,
      -1,    -1,    -1,   257,    -1,    -1,    -1,    12,    13,    -1,
      15,    -1,   266,    -1,   339,    -1,   270,   342,    23,    -1,
      25,    -1,    -1,    -1,   502,    -1,    -1,    -1,    -1,    -1,
     284,    -1,    -1,   358,    -1,    -1,    -1,    -1,   339,    -1,
     365,   342,   367,    -1,    49,    -1,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    60,    -1,   358,    63,    -1,
      -1,    -1,    -1,    -1,   365,    -1,   367,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,   339,    -1,    -1,   342,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,   358,    -1,    -1,   432,    -1,    -1,
      -1,    64,    -1,   367,    67,    -1,   441,    -1,   443,   444,
      -1,    -1,    -1,   448,    -1,    -1,    -1,    -1,   453,    -1,
      -1,   432,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     441,    -1,   443,   444,    -1,     3,     4,   448,    -1,     7,
       8,     9,   453,    11,    -1,    -1,    14,    -1,    16,    -1,
      -1,    19,    -1,    21,    22,    -1,    -1,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,
     444,    -1,    -1,    -1,   448,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,     3,     4,    -1,    -1,     7,    -1,
      -1,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,    -1,
      19,    -1,    21,    22,    -1,    -1,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
       7,    -1,    -1,    -1,    11,    -1,    -1,    14,    -1,    16,
      -1,    -1,    19,    -1,    21,    22,    -1,    -1,    25,    26,
      27,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    91,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    91,     3,     4,    -1,    -1,     7,
      -1,    -1,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,
      -1,    -1,    -1,    21,    22,    -1,    -1,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    -1,    21,    22,    -1,    -1,    25,
      -1,    27,    60,    61,    -1,    -1,    -1,    -1,    -1,    12,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    91,    69,    70,    71,    72,
      73,    -1,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    10,    91,    92,
      93,    94,    -1,    -1,    -1,    18,    -1,    20,    21,    22,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    91,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    91,    69,    70,    71,    72,    73,    -1,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    91,    92,    93,    94
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    18,    20,    21,    22,    24,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    91,   102,
     109,   110,   111,   112,   113,   114,   115,   116,   161,   165,
     166,   170,   177,   179,    60,    61,    90,    22,    24,    92,
      93,    60,     0,   102,    60,   117,    60,   118,    57,   102,
      61,   167,   167,   102,   102,   102,    58,     3,     4,     7,
      11,    14,    16,    21,    25,    26,    27,    60,    61,   113,
     121,   126,   127,   129,   132,   133,   135,   137,   138,   145,
     147,   148,   150,   152,   154,   158,   175,   178,   184,   186,
     180,    94,    60,    58,    35,    56,    65,    56,    19,    61,
     113,   129,   132,   137,   145,   147,   150,   152,   154,   157,
     158,   168,   169,   184,    12,    69,    70,    71,    72,    73,
      80,    81,    82,    83,    84,    91,    92,    93,    94,    96,
     111,   112,   162,   163,    65,    65,    65,    60,    52,    60,
     144,    63,    60,    34,   153,    58,    34,    65,   178,   178,
      35,    36,    37,    38,    39,    40,    41,    97,    57,    57,
     178,   178,   178,     5,     6,   141,   178,   178,    57,   178,
     178,   178,   178,    62,   178,    57,    61,    58,   163,    13,
      15,    23,    25,    49,    51,    52,    53,    54,    55,    60,
      63,   104,   106,   108,   148,   151,   186,   187,    60,    51,
      60,   119,   120,    60,    74,   108,   169,   169,    62,    60,
      56,   171,   108,   108,    21,    63,   114,   121,   126,   131,
      58,    58,    51,    55,    34,    58,    60,   176,    52,    60,
      58,    52,    60,   156,   159,   176,    51,    55,    60,    63,
     122,   123,   124,   125,    62,   108,   108,    65,   142,   113,
     181,   163,    58,    34,    34,    23,    63,    65,   103,   108,
      35,    56,    66,    65,    57,    57,    62,    96,    61,    66,
      66,   126,    60,   130,    59,   125,   144,    64,    64,    60,
      12,   108,   149,    34,    60,    67,   160,   153,    34,   125,
      66,    56,    28,    29,    30,    31,    32,    33,    99,   178,
     108,    61,   181,   182,    58,    91,   101,   109,   111,   164,
      17,    60,    34,   108,   122,    34,    42,    43,    44,    45,
      46,    47,    48,    50,    64,    67,    98,    99,   100,   105,
     108,   119,    35,   120,    60,    61,   113,   129,   132,   137,
     147,   152,   158,   172,   184,   139,   136,    64,    35,    56,
     108,    58,    58,    57,    57,    58,    58,    56,    58,    60,
      56,    57,   155,   156,    57,    60,    64,   125,   124,    66,
       8,     9,   113,   129,   132,   137,   145,   147,   150,   152,
     154,   157,   158,   173,   174,   184,    62,   165,   183,   164,
      60,    64,    66,   107,   108,   108,    66,   172,   172,   172,
     172,   172,   172,   172,   172,    62,   172,    61,    61,   108,
      60,    59,   125,    75,    76,    85,    86,   143,    12,   149,
     185,   108,    58,    60,   160,   140,    57,    57,   174,    62,
      61,    58,    64,   105,    35,    62,   174,   174,    35,    63,
     121,   127,   128,    58,    58,    58,   185,   155,    61,    61,
     113,   129,   132,   137,   145,   147,   150,   152,   154,   157,
     158,   184,   188,   189,    12,   149,   107,   108,   172,    62,
      62,   108,   127,    66,    12,   149,   143,    58,   174,   188,
     189,    62,    58,    58,    64,   134,    58,    58,    58,   146,
      62,    62,    61,    57,    57,   143,    57,   174,   146,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    95,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    97,    97,
      97,    97,    97,    97,    98,    98,    98,    98,    98,    98,
      99,    99,    99,    99,    99,    99,   100,   100,   101,   101,
     102,   102,   102,   102,   102,   102,   103,   103,   104,   104,
     105,   105,   105,   105,   105,   106,   106,   106,   106,   106,
     107,   107,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   109,   109,   109,   109,   109,   109,   110,   110,   110,
     110,   110,   111,   111,   111,   111,   111,   112,   112,   112,
     112,   112,   113,   114,   114,   114,   114,   115,   115,   115,
     115,   116,   116,   117,   117,   117,   117,   118,   118,   118,
     118,   119,   119,   120,   120,   121,   121,   121,   122,   123,
     123,   124,   124,   124,   124,   125,   125,   126,   127,   128,
     128,   129,   129,   130,   130,   131,   131,   131,   132,   132,
     134,   133,   136,   135,   137,   139,   138,   140,   138,   142,
     141,   141,   143,   143,   143,   143,   144,   144,   145,   146,
     146,   147,   148,   148,   149,   149,   150,   150,   151,   152,
     152,   153,   153,   153,   154,   155,   155,   156,   156,   157,
     157,   158,   159,   160,   160,   161,   161,   162,   162,   163,
     163,   164,   164,   165,   166,   167,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   169,
     169,   171,   170,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   174,   174,   175,
     176,   176,   177,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   180,   179,   181,   181,
     182,   182,   183,   184,   185,   185,   186,   186,   187,   187,
     187,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   189,   189
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     2,     2,     2,     2,     0,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     5,     3,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     2,     1,     1,     2,
       3,     2,     2,     1,     3,     3,     5,     4,     6,     6,
       8,     1,     1,     3,     1,     1,     4,     1,     1,     1,
       3,     1,     1,     1,     3,     3,     1,     3,     3,     1,
       3,     2,     2,     3,     5,     1,     3,     2,     1,     1,
       0,    12,     0,     8,     2,     0,     8,     0,     9,     0,
       5,     0,     1,     1,     1,     1,     1,     1,    10,     3,
       0,     2,     5,     5,     3,     1,    10,    10,     3,     5,
       5,     2,     2,     0,     5,     3,     1,     1,     1,     3,
       3,     5,     2,     3,     0,     2,     2,     2,     4,     1,
       1,     1,     1,     6,     7,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     2,
       0,     0,     8,     2,     2,     2,     2,     2,     2,     4,
       2,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     2,     0,     3,
       1,     3,     4,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     4,     2,     2,     0,     0,     7,     2,     0,
       2,     0,     4,     2,     1,     1,     7,     8,     3,     7,
       7,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     0
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
  case 92: /* declaration: declarationStmt SEMICOLON  */
#line 119 "bison.y"
                                        { fprintf(yyout, " : declaration statement"); }
#line 1835 "bison.tab.c"
    break;

  case 131: /* log: assignment_statement SEMICOLON  */
#line 178 "bison.y"
                                    { fprintf(yyout, " : assignment statement");  }
#line 1841 "bison.tab.c"
    break;

  case 132: /* log: expression_statement SEMICOLON  */
#line 179 "bison.y"
                                     { fprintf(yyout, " : expression statement");  }
#line 1847 "bison.tab.c"
    break;

  case 140: /* $@1: %empty  */
#line 194 "bison.y"
                                                                           {fprintf(yyout, " : loop statement");}
#line 1853 "bison.tab.c"
    break;

  case 142: /* $@2: %empty  */
#line 197 "bison.y"
                                               {fprintf(yyout, " : loop statement");}
#line 1859 "bison.tab.c"
    break;

  case 145: /* $@3: %empty  */
#line 205 "bison.y"
                                                { fprintf(yyout, " : conditional statement");  }
#line 1865 "bison.tab.c"
    break;

  case 147: /* $@4: %empty  */
#line 206 "bison.y"
                                                                    { fprintf(yyout, " : conditional statement");  }
#line 1871 "bison.tab.c"
    break;

  case 149: /* $@5: %empty  */
#line 210 "bison.y"
                      { fprintf(yyout, " : conditional statement");  }
#line 1877 "bison.tab.c"
    break;

  case 158: /* analyze_statement: ANALYZE analyze_label COLON analyze_label COLON analysis_arrays COLON analysis_arrays analyze_syntax SEMICOLON  */
#line 219 "bison.y"
                                                                                                                                   { fprintf(yyout, " : analyze statement");  }
#line 1883 "bison.tab.c"
    break;

  case 161: /* func_invoke2: func_invoke SEMICOLON  */
#line 227 "bison.y"
                                     { fprintf(yyout, " : call statement");  }
#line 1889 "bison.tab.c"
    break;

  case 166: /* task_invoke: MAKE_PARALLEL IDENTIFIER COLON arith_expr COLON arith_expr COLON arguments COLON SEMICOLON  */
#line 241 "bison.y"
                                                                                                         { fprintf(yyout, " : call statement");  }
#line 1895 "bison.tab.c"
    break;

  case 167: /* task_invoke: MAKE_PARALLEL IDENTIFIER COLON arith_expr COLON arith_expr COLON NULL_ARGS COLON SEMICOLON  */
#line 242 "bison.y"
                                                                                                           { fprintf(yyout, " : call statement");  }
#line 1901 "bison.tab.c"
    break;

  case 169: /* sleep: SLEEP ROUNDOPEN FLOATLITERAL ROUNDCLOSE SEMICOLON  */
#line 249 "bison.y"
                                                          { fprintf(yyout, " : sleep statement");  }
#line 1907 "bison.tab.c"
    break;

  case 170: /* sleep: SLEEP ROUNDOPEN INTEGERLITERAL ROUNDCLOSE SEMICOLON  */
#line 250 "bison.y"
                                                             { fprintf(yyout, " : sleep statement");  }
#line 1913 "bison.tab.c"
    break;

  case 176: /* nextip: SEMICOLON  */
#line 264 "bison.y"
     { 
      fprintf(yyout, " : scan statement");
     }
#line 1921 "bison.tab.c"
    break;

  case 179: /* return_statement: RETURN RHS SEMICOLON  */
#line 274 "bison.y"
                                        { fprintf(yyout, " : return statement"); }
#line 1927 "bison.tab.c"
    break;

  case 180: /* return_statement: RETURN NVOID SEMICOLON  */
#line 275 "bison.y"
                                          { fprintf(yyout, " : return statement"); }
#line 1933 "bison.tab.c"
    break;

  case 181: /* output: OP COLON opstring file_name SEMICOLON  */
#line 279 "bison.y"
       { 
        fprintf(yyout, " : print statement");
       }
#line 1941 "bison.tab.c"
    break;

  case 193: /* func_decl: FUNC IDENTIFIER COLON args COLON func_return  */
#line 303 "bison.y"
                                                               { fprintf(yyout, " : function declaration statement"); }
#line 1947 "bison.tab.c"
    break;

  case 194: /* atomic_func_decl: ATOMIC FUNC IDENTIFIER COLON args COLON func_return  */
#line 305 "bison.y"
                                                                         { fprintf(yyout, " : function declaration statement"); }
#line 1953 "bison.tab.c"
    break;

  case 211: /* $@6: %empty  */
#line 328 "bison.y"
                                 { fprintf(yyout, " : task declaration statement"); }
#line 1959 "bison.tab.c"
    break;

  case 256: /* $@7: %empty  */
#line 392 "bison.y"
                                { fprintf(yyout, " : type declaration statement"); }
#line 1965 "bison.tab.c"
    break;

  case 263: /* method_invoke2: method_invoke SEMICOLON  */
#line 406 "bison.y"
                                          { fprintf(yyout, " : call statement"); }
#line 1971 "bison.tab.c"
    break;


#line 1975 "bison.tab.c"

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

#line 438 "bison.y"


void yyerror(std::string s){
  std::cout << "Syntax Error: " << s << " at line number - " << yylineno << std::endl;
}
