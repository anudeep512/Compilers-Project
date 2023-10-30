/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

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

#line 81 "bison.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1828

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  84
/* YYNRULES -- Number of rules.  */
#define YYNRULES  254
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  438

#define YYUNDEFTOK  2
#define YYMAXUTOK   344


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      85,    86,    87,    88,    89
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    56,    57,    57,    57,    57,
      57,    57,    58,    58,    59,    59,    61,    62,    63,    64,
      65,    66,    72,    73,    76,    77,    78,    79,    80,    83,
      84,    85,    86,    87,    90,    91,    94,    95,    96,    97,
      98,    99,   100,   104,   104,   104,   104,   104,   104,   105,
     105,   105,   105,   105,   107,   107,   107,   107,   107,   108,
     108,   108,   108,   108,   113,   116,   116,   116,   116,   117,
     117,   119,   120,   123,   124,   125,   126,   129,   130,   131,
     132,   135,   136,   142,   145,   148,   149,   152,   153,   156,
     157,   161,   161,   164,   164,   167,   167,   172,   175,   175,
     176,   176,   180,   180,   181,   184,   184,   184,   184,   187,
     187,   189,   191,   191,   197,   200,   201,   205,   206,   210,
     211,   215,   218,   222,   223,   224,   227,   231,   232,   238,
     239,   243,   246,   252,   255,   256,   261,   261,   263,   263,
     265,   266,   268,   269,   271,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   281,   281,   282,   283,   284,   287,
     288,   293,   293,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   326,   327,
     331,   332,   333,   337,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   352,   353,   357,   357,   360,
     361,   365,   366,   369,   372,   373,   377,   378,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   398,   399
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WHEN", "REPEAT", "ELSE_WHEN", "DEFAULT",
  "FOR", "BREAK", "CONTINUE", "TASK", "MAKE_PARALLEL", "NULL_ARGS", "TID",
  "ANALYZE", "GET", "SLEEP", "TIME", "START", "RETURN", "TYPE", "ATOMIC",
  "IN", "FUNC", "INVOKE", "IP", "OP", "DIV", "ADD", "SUB", "MUL",
  "EXPONENT", "MODULO", "ARROW", "EQ", "INCR", "DECR", "ASSN_MODULO",
  "ASSN_EXPONENT", "ASSN_DIV", "ASSN_MUL", "AND", "OR", "GT", "LT", "GTEQ",
  "LTEQ", "NOT_EQ", "NEG", "EQUAL_TWO", "INTEGERLITERAL", "STRINGLITERAL",
  "CHARACTERLITERAL", "BOOLEANLITERAL", "FLOATLITERAL", "COMMA",
  "SEMICOLON", "COLON", "IDENTIFIER", "SCOPEOPEN", "SCOPECLOSE",
  "ROUNDOPEN", "ROUNDCLOSE", "SQUAREOPEN", "SQUARECLOSE", "HASH",
  "LEXERROR", "NNUM", "NDEC", "NBOOL", "NLET", "NTEXT", "NVOID", "NARRNUM",
  "NARRDEC", "NARRBOOL", "NARRLET", "NARRTEXT", "ANUM", "ADEC", "ABOOL",
  "ALET", "ATEXT", "AARRNUM", "AARRDEC", "AARRBOOL", "AARRLET", "AARRTEXT",
  "UDATATYPE", "AUDATATYPE", "$accept", "all_datatypes", "expression_op",
  "comparison_op", "arithmetic_op", "logical_op", "nonAtomic_datatypes",
  "begin", "T", "all_ops", "constants", "next", "RHS", "nonAtomicSimple",
  "atomicSimple", "nonAtomicArray", "atomicArray", "declaration",
  "simpleDatatype", "arrayDatatype", "declarationStmt", "simpleList",
  "arrayList", "dimlist", "assignment_statement", "expression_statement",
  "log", "g", "both_assignment", "loop", "for_loop", "$@1", "while_loop",
  "$@2", "conditional", "when_statement", "$@3", "$@4", "when_default",
  "$@5", "analysis_arrays", "analyze_label", "analyze_statement",
  "analyze_syntax", "func_invoke2", "func_invoke", "arguments",
  "task_invoke", "get_invoke", "sleep", "file_name", "input", "nextip",
  "stringvalues", "return_statement", "output", "opstring", "nextop",
  "function", "func_args", "func_decl", "atomic_func_decl", "func_body",
  "func_scope", "func_statements", "task", "$@6", "taskscope", "statement",
  "statements", "access", "id", "start_scope", "start_body", "stt",
  "type_declaration", "$@7", "attributes", "methods", "method",
  "method_invoke", "in_statement", "method_statements", "method_body", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344
};
# endif

#define YYPACT_NINF (-368)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -368,   601,  -368,   -19,    10,   -67,   -17,    27,  -368,  -368,
    -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,  -368,  -368,    48,    55,    62,  -368,    52,
      52,  -368,  -368,  -368,    60,  1455,  -368,    67,  -368,    70,
      99,    80,    74,    89,  -368,  1541,  -368,  -368,  1136,    92,
      96,   104,   112,   110,    73,   115,   141,   118,  -368,    18,
     148,  1455,  -368,   124,   135,  -368,  -368,  -368,  -368,  -368,
       9,  -368,  -368,   137,  -368,  -368,  -368,  -368,  -368,  1090,
     139,   142,    61,  1703,   144,   150,   147,     6,  1703,   259,
    1541,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,  1176,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,   149,   153,
    1703,  1703,  1642,   152,   157,   159,    35,   161,    36,  -368,
    -368,  -368,  -368,    41,  1703,  -368,  -368,  -368,  -368,  -368,
    -368,  1703,  1216,  -368,  -368,   173,   183,  -368,  -368,  -368,
    -368,  1611,   696,   162,   -20,  -368,   180,   186,  -368,  -368,
    -368,  -368,  -368,  -368,  1703,  -368,  -368,  -368,  -368,  -368,
     214,  -368,   -23,   187,  -368,  -368,   163,   195,   196,   224,
    1302,  -368,  -368,  -368,  1136,   199,   197,   198,   226,   205,
    -368,   209,   216,   206,   191,  -368,  -368,   211,  -368,  -368,
     207,   141,  -368,  -368,  -368,  -368,  1703,  1703,   215,  1611,
     213,    -2,   156,   156,   257,  1703,  1738,  1703,   227,   242,
     150,     6,  -368,   221,   232,  -368,   243,  1572,  -368,  -368,
     245,   248,  1703,   225,   244,  -368,  -368,   252,    49,    36,
    -368,   254,   240,   250,  -368,   262,   -13,   156,   156,  -368,
    -368,  -368,  -368,  -368,   251,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,  -368,  -368,  1703,  -368,  -368,  1703,   -15,
     258,  1703,   265,  -368,  1572,  1572,  1572,  1572,  1572,  1572,
    1572,  1572,   263,  -368,  -368,   266,   267,  1703,   269,   268,
     279,  -368,  1703,   272,  -368,  -368,   207,  -368,  -368,  -368,
    -368,  -368,   273,  -368,  -368,  -368,  -368,   274,  1763,  -368,
     300,    18,   252,  1703,   278,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,  1333,  1333,  -368,   305,   286,   291,  -368,
      49,  -368,   293,   296,  1419,  -368,  1703,  1703,   299,   252,
    1572,   302,   303,  -368,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,  -368,  -368,   732,  -368,  -368,   818,  1703,
     249,   298,  1691,  -368,  1333,  1333,   327,  1419,  -368,  -368,
    -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,   849,  -368,  -368,    18,  -368,  -368,  -368,
    -368,  -368,  -368,  -368,  -368,   307,    53,   935,   966,   306,
     308,  -368,  -368,    41,   310,  -368,  -368,  -368,  -368,    66,
    -368,  -368,  1333,  -368,  1703,  1052,   252,  -368
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      37,     0,     1,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    74,    75,    76,    77,    78,    69,
      70,    71,    72,    73,    79,    80,    81,    82,    83,    87,
      85,    86,    89,    90,    38,     0,     0,     0,    39,     0,
       0,    40,    36,    41,     0,     0,   227,     0,    88,     0,
      93,    91,     0,    92,    84,     0,   156,   157,     0,     0,
       0,     0,     0,     0,     0,     0,   145,     0,   133,     0,
       0,     0,   214,     0,     0,   215,   217,   111,   112,   216,
     124,   220,   218,     0,   219,   224,   222,   221,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,   166,   169,   171,   172,   168,   167,   175,   173,
     170,   174,   179,     0,   178,   177,     6,     5,     4,     8,
       7,    13,    10,     9,    11,    12,     2,     3,     0,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
     125,   128,   127,     0,     0,    18,    19,    16,    15,    14,
      17,     0,     0,   105,   106,     0,     0,   117,   134,   213,
     226,     0,     0,     0,     0,    58,     0,     0,    49,    53,
      50,    52,    51,    42,     0,    57,    56,    95,    43,    59,
      94,   102,     0,     0,   129,   130,     0,     0,     0,   210,
       0,   164,   180,   158,     0,     0,     0,     0,     0,     0,
     109,     0,     0,     0,     0,   143,   144,     0,   149,   150,
     155,   145,   132,   103,   104,   223,     0,     0,     0,   232,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
       0,     0,   151,   211,     0,   176,     0,     0,   118,   115,
       0,   110,     0,     0,     0,   136,   137,   135,     0,     0,
     153,     0,     0,     0,   229,     0,     0,     0,     0,   161,
      35,    34,   160,   141,     0,    29,    26,    27,    28,    31,
      30,    48,    32,    33,    21,    20,    22,    23,    24,    25,
      61,    47,    45,    44,    46,     0,    96,   101,     0,     0,
       0,     0,   212,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   192,   191,     0,     0,     0,     0,     0,
       0,   142,     0,     0,   148,   146,   155,   152,   120,   122,
     230,   228,     0,   231,   163,   162,    62,     0,    55,    99,
      98,     0,   234,     0,     0,   183,   184,   186,   185,   187,
     190,   188,   182,     0,     0,   107,     0,     0,     0,   138,
       0,   154,     0,     0,     0,    60,     0,     0,     0,   235,
       0,     0,     0,   193,   194,   196,   195,   200,   198,   199,
     202,   205,   197,   201,   208,     0,   207,   206,     0,     0,
       0,     0,     0,   147,     0,     0,     0,     0,   238,   239,
     242,   244,   245,   241,   240,   248,   246,   243,   247,   252,
     251,   250,   253,     0,    54,   100,     0,   189,   203,   204,
     119,   209,   116,   108,   113,     0,     0,     0,     0,     0,
       0,   233,   254,     0,     0,   140,   139,   121,   123,     0,
     249,   131,     0,   236,     0,     0,   237,   114
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -368,   177,  -368,  -368,  -368,  -368,  -192,  -368,  -368,    39,
    -368,    16,   -48,  -180,  -368,   -62,  -368,    -1,   241,  -368,
    -145,  -368,  -368,   145,   246,    29,   -38,  -368,  -368,    45,
    -368,  -368,  -368,  -368,    65,  -368,  -368,  -368,  -368,  -368,
    -322,   151,   -52,  -142,   101,   416,  -287,   -37,  -368,   121,
     170,   -33,    37,   136,   -42,   167,  -368,    75,  -368,   -81,
     134,  -368,   352,  -111,   295,  -368,  -368,  -271,  -254,  -325,
     220,  -368,  -368,   -84,   322,  -368,  -368,  -368,  -368,  -368,
     228,  -368,  -367,  -368
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   128,   151,   282,   283,   284,   259,     1,   175,   285,
     176,   327,   246,    30,    31,    32,    33,   295,    35,    36,
      37,    51,    53,   182,    73,    74,   296,   241,   201,   297,
      77,   424,    78,   306,   298,    80,   305,   352,   157,   353,
     143,   186,   367,    81,   299,    83,   247,   369,   179,   300,
     137,   371,   315,   210,   372,   301,   211,   250,    38,   129,
      39,    40,    56,   112,   113,    41,   195,   302,   374,   375,
     303,   189,    42,    88,    89,    43,    90,   219,   256,   323,
     304,   401,   402,   403
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,   212,   192,   105,   332,   160,    47,    75,    84,   358,
       7,   164,    86,   110,   155,   156,   218,   102,   107,   378,
     420,    46,   109,   334,   335,   336,   337,   338,   339,   340,
     341,   262,   228,    75,    84,   194,   422,   223,    86,    44,
     228,   229,   260,   260,    72,   177,   359,   321,   105,   330,
     187,    75,    84,   194,   101,   258,    86,   184,   110,   417,
     418,   105,   102,   107,   185,   324,   325,   109,   160,    45,
      72,   110,    48,   163,   255,   102,   107,   260,   260,   192,
     109,   221,   196,   197,   423,    49,   205,   208,    72,   407,
      76,   139,   140,   206,   209,   416,   213,    68,    69,   101,
     103,   141,   142,   214,   313,   314,    50,   435,   312,   426,
      79,    55,   101,    52,    75,    84,    76,    58,    54,    86,
     104,   411,   433,   434,   411,    91,   226,    92,   116,   117,
     118,   119,   120,    93,    76,    94,    79,    95,   105,   121,
     122,   123,   124,   125,    96,   103,    82,   436,   110,   126,
     127,    72,   102,   107,    79,   130,   106,   109,   103,   131,
     261,   261,    48,   411,   411,   104,    85,   132,   252,   253,
     133,   134,    82,   135,   136,   138,   108,   264,   104,   286,
     153,   411,   144,   145,   146,   147,   148,   149,   150,   101,
      82,   154,    85,   158,   309,   261,   261,    76,   161,   162,
     181,   106,   180,   245,   165,   183,   166,   193,   194,   202,
      85,   203,    87,   224,   106,    65,   204,    79,   207,   222,
     231,   108,   111,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,   108,   103,   216,   328,    87,   167,
     329,   168,   169,   170,   171,   172,   217,   225,   227,   173,
     230,   232,   174,    82,   233,   104,    87,   234,   237,   345,
     144,   238,   239,   240,   349,   242,   243,   111,   244,   248,
     257,   254,   249,    85,   263,   114,   288,   287,   291,   307,
     111,   431,   310,   115,   145,   146,   147,   148,   149,   150,
     292,   106,   188,   144,   145,   146,   147,   148,   149,   150,
     311,   293,   392,   308,   318,   364,   364,   312,   328,   405,
     317,   108,   397,   326,   319,   331,   389,   394,   320,    87,
     114,   396,   333,   342,   347,   343,   344,   346,   115,   348,
     350,   413,   354,   114,   357,   392,   355,   364,   360,   379,
     364,   115,   363,   363,   380,   397,   364,   364,   382,   389,
     394,   392,   384,   388,   396,   385,   406,   111,   408,   409,
     419,   397,   414,   425,   429,   389,   394,   356,   430,   432,
     396,   236,   404,   199,   363,   289,   381,   363,   200,   364,
     364,   251,   290,   363,   363,   316,   388,   383,   365,   365,
     322,   351,    57,   152,   364,   190,     0,   364,     0,   390,
       0,     0,   388,     0,     0,     0,     0,     0,   366,   366,
     114,     0,     0,     0,     0,     0,   363,   363,   115,   391,
     365,     0,     0,   365,     0,     0,     0,     0,     0,   365,
     365,   363,   390,     0,   363,     0,     0,     0,     0,     0,
     366,     0,     0,   366,   368,   368,     0,     0,   390,   366,
     366,     0,   391,     0,     0,   393,     0,     0,     0,     0,
       0,     0,   365,   365,   370,   370,     0,     0,   391,     0,
       0,     0,     0,     0,     0,   395,   368,   365,     0,   368,
     365,     0,   366,   366,     0,   368,   368,     0,   393,     0,
       0,     0,     0,     0,     0,     0,   370,   366,     0,   370,
     366,     0,     0,     0,   393,   370,   370,     0,   395,   178,
     373,   373,     0,     0,   178,     0,     0,     0,   368,   368,
       0,   398,     0,     0,   395,     0,     0,     0,     0,     0,
       0,     0,     0,   368,     0,     0,   368,     0,   370,   370,
       0,     0,   373,     0,     0,   373,   178,   178,     0,     0,
       0,   373,   373,   370,   398,     0,   370,     0,     0,     0,
     178,     0,     0,   376,   376,     0,     0,   178,     0,     0,
     398,   377,   377,     0,   399,     0,     0,     0,     0,     0,
       0,     0,   400,     0,   373,   373,     0,     0,     0,     0,
     178,     0,     0,     0,     0,   376,     0,     0,   376,   373,
       0,     2,   373,   377,   376,   376,   377,   399,     0,     0,
       0,     3,   377,   377,     0,   400,     0,     0,     0,     4,
     178,     5,     6,   399,     7,     0,     0,     0,     0,     0,
       0,   400,   178,   178,     0,     0,     0,   376,   376,     0,
       0,   178,     0,   178,     0,   377,   377,     0,     0,     0,
       0,     0,   376,     0,     0,   376,     0,     0,   178,     0,
     377,     0,     0,   377,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   178,     0,     0,   178,     0,     0,   178,   220,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   178,     0,     0,     0,     0,   178,     0,
       0,     0,     0,     0,     0,    59,    60,     0,     0,    61,
     361,   362,     0,    62,     0,     0,    97,     0,    63,   178,
       0,    98,     0,    64,     0,     0,    65,    66,    67,     0,
       0,     0,     0,   116,   117,   118,   119,   120,     0,     0,
       0,     0,   178,   178,   121,   122,   123,   124,   125,     0,
       0,     0,     0,     0,   126,   127,     0,     0,     0,     0,
      99,     0,   410,     0,     0,   178,     0,     0,   178,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    59,    60,     0,     0,    61,   361,   362,     0,    62,
       0,     0,    97,     0,    63,     0,     0,    98,     0,    64,
       0,     0,    65,    66,    67,     0,     0,     0,     0,     0,
     178,     0,    59,    60,     0,     0,    61,     0,     0,     0,
      62,     0,     0,    97,     0,    63,     0,     0,    98,     0,
      64,   386,     0,    65,    66,    67,    99,     0,   412,     0,
       0,     0,     0,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    99,   387,   421,
       0,     0,     0,     0,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    59,    60,
       0,     0,    61,   361,   362,     0,    62,     0,     0,    97,
       0,    63,     0,     0,    98,     0,    64,     0,     0,    65,
      66,    67,     0,     0,     0,     0,     0,     0,     0,    59,
      60,     0,     0,    61,   361,   362,     0,    62,     0,     0,
      97,     0,    63,     0,     0,    98,     0,    64,     0,     0,
      65,    66,    67,    99,     0,   427,     0,     0,     0,     0,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    99,     0,   428,     0,     0,     0,
       0,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    59,    60,     0,     0,    61,
     361,   362,     0,    62,     0,     0,    97,     0,    63,     0,
       0,    98,     0,    64,     0,     0,    65,    66,    67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    59,    60,     0,     0,    61,     0,     0,
       0,    62,     0,     0,     0,     0,    63,     0,     0,     0,
      99,    64,   437,     0,    65,    66,    67,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     0,     0,     0,     0,     0,    68,    69,    70,    71,
     159,     0,     0,     0,     0,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    59,
      60,     0,     0,    61,     0,     0,     0,    62,     0,     0,
      97,     0,    63,     0,     0,    98,     0,    64,     0,     0,
      65,    66,    67,   116,   117,   118,   119,   120,     0,     0,
       0,     0,     0,     0,   121,   122,   123,   124,   125,    59,
      60,     0,     0,    61,   126,   127,     0,    62,     0,     0,
       0,     0,    63,     0,    99,   100,   191,    64,     0,     0,
      65,    66,    67,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,     0,     0,     0,     0,
       0,     0,    68,    69,    70,    71,   215,     0,     0,     0,
       0,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    59,    60,     0,     0,    61,
       0,     0,     0,    62,     0,     0,    97,     0,    63,     0,
       0,    98,     0,    64,     0,     0,    65,    66,    67,     0,
       0,     0,     0,     0,     0,     0,    59,    60,     0,     0,
      61,   361,   362,     0,    62,     0,     0,    97,     0,    63,
       0,     0,    98,     0,    64,     0,     0,    65,    66,    67,
      99,   100,   235,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    59,    60,     0,     0,    61,     0,     0,     0,
      62,     0,     0,    97,     0,    63,     0,     0,    98,     0,
      64,   386,     0,    65,    66,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    59,    60,
       0,     0,    61,     0,     0,     0,    62,     0,     0,     0,
       0,    63,     0,     0,     0,     0,    64,    99,   387,    65,
      66,    67,     0,     0,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     0,     0,
       0,    68,    69,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    59,    60,     0,     0,    61,     0,
       0,     0,    62,     0,     0,    97,     0,    63,     0,     0,
      98,     0,    64,     0,     0,    65,    66,    67,     0,     0,
       0,     0,     0,     0,     0,    59,    60,     0,     0,    61,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     0,    64,     0,     0,    65,     0,    67,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      99,   294,    64,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     0,     0,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
     198,     0,     0,   415,   165,     0,   166,     0,     0,     8,
       9,    10,    11,    12,    13,    65,   165,     0,   166,     0,
      19,    20,    21,    22,    23,     0,     0,    65,     0,     0,
      29,     0,     0,     0,     0,     0,     0,     0,     0,   167,
       0,   168,   169,   170,   171,   172,     0,     0,     0,   173,
       0,   167,   174,   168,   169,   170,   171,   172,     0,     0,
       0,   173,     0,     0,   174,   265,   266,   267,   268,   269,
     270,   271,     0,     0,     0,     0,     0,     0,     0,   272,
     273,   274,   275,   276,   277,   278,     0,   279,     0,     0,
     265,   266,   267,   268,   269,   270,   271,     0,     0,     0,
     280,     0,     0,   281,   272,   273,   274,   275,   276,   277,
     278,     0,   279,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   281
};

static const yytype_int16 yycheck[] =
{
       1,   143,   113,    55,   291,    89,    23,    45,    45,   331,
      23,    92,    45,    55,     5,     6,   161,    55,    55,   344,
     387,    88,    55,   294,   295,   296,   297,   298,   299,   300,
     301,   223,    55,    71,    71,    55,   403,    57,    71,    58,
      55,    64,   222,   223,    45,    93,   333,    60,   100,    64,
      98,    89,    89,    55,    55,    57,    89,    51,   100,   384,
     385,   113,   100,   100,    58,   257,   258,   100,   152,    59,
      71,   113,    89,    12,   219,   113,   113,   257,   258,   190,
     113,   162,   130,   131,   406,    58,    51,    51,    89,   360,
      45,    73,    74,    58,    58,   382,   144,    56,    57,   100,
      55,    83,    84,   151,    55,    56,    58,   432,    55,    56,
      45,    59,   113,    58,   152,   152,    71,    57,    56,   152,
      55,   375,    56,    57,   378,    58,   174,    57,    67,    68,
      69,    70,    71,    34,    89,    55,    71,    63,   190,    78,
      79,    80,    81,    82,    55,   100,    45,   434,   190,    88,
      89,   152,   190,   190,    89,    63,    55,   190,   113,    63,
     222,   223,    89,   417,   418,   100,    45,    63,   216,   217,
      58,    61,    71,    58,    33,    57,    55,   225,   113,   227,
      56,   435,    34,    35,    36,    37,    38,    39,    40,   190,
      89,    56,    71,    56,   242,   257,   258,   152,    59,    57,
      50,   100,    58,    12,    13,    58,    15,    58,    55,    57,
      89,    54,    45,    33,   113,    24,    57,   152,    57,    57,
      57,   100,    55,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,   113,   190,    63,   285,    71,    48,
     288,    50,    51,    52,    53,    54,    63,    61,    34,    58,
      63,    56,    61,   152,    58,   190,    89,    33,    59,   307,
      34,    64,    64,    58,   312,    56,    50,   100,    62,    58,
      57,    56,    65,   152,    17,    55,    34,    50,    57,    34,
     113,   423,    57,    55,    35,    36,    37,    38,    39,    40,
      58,   190,    33,    34,    35,    36,    37,    38,    39,    40,
      56,    58,   354,    55,    64,   343,   344,    55,   356,   357,
      56,   190,   354,    62,    64,    57,   354,   354,    56,   152,
     100,   354,    57,    60,    56,    59,    59,    58,   100,    50,
      58,   379,    59,   113,    34,   387,    62,   375,    60,    34,
     378,   113,   343,   344,    58,   387,   384,   385,    57,   387,
     387,   403,    59,   354,   387,    59,    57,   190,    56,    56,
      33,   403,    64,    56,    58,   403,   403,   328,    60,    59,
     403,   194,   356,   132,   375,   230,   347,   378,   132,   417,
     418,   211,   231,   384,   385,   249,   387,   350,   343,   344,
     256,   316,    40,    71,   432,   100,    -1,   435,    -1,   354,
      -1,    -1,   403,    -1,    -1,    -1,    -1,    -1,   343,   344,
     190,    -1,    -1,    -1,    -1,    -1,   417,   418,   190,   354,
     375,    -1,    -1,   378,    -1,    -1,    -1,    -1,    -1,   384,
     385,   432,   387,    -1,   435,    -1,    -1,    -1,    -1,    -1,
     375,    -1,    -1,   378,   343,   344,    -1,    -1,   403,   384,
     385,    -1,   387,    -1,    -1,   354,    -1,    -1,    -1,    -1,
      -1,    -1,   417,   418,   343,   344,    -1,    -1,   403,    -1,
      -1,    -1,    -1,    -1,    -1,   354,   375,   432,    -1,   378,
     435,    -1,   417,   418,    -1,   384,   385,    -1,   387,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   375,   432,    -1,   378,
     435,    -1,    -1,    -1,   403,   384,   385,    -1,   387,    93,
     343,   344,    -1,    -1,    98,    -1,    -1,    -1,   417,   418,
      -1,   354,    -1,    -1,   403,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   432,    -1,    -1,   435,    -1,   417,   418,
      -1,    -1,   375,    -1,    -1,   378,   130,   131,    -1,    -1,
      -1,   384,   385,   432,   387,    -1,   435,    -1,    -1,    -1,
     144,    -1,    -1,   343,   344,    -1,    -1,   151,    -1,    -1,
     403,   343,   344,    -1,   354,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   354,    -1,   417,   418,    -1,    -1,    -1,    -1,
     174,    -1,    -1,    -1,    -1,   375,    -1,    -1,   378,   432,
      -1,     0,   435,   375,   384,   385,   378,   387,    -1,    -1,
      -1,    10,   384,   385,    -1,   387,    -1,    -1,    -1,    18,
     204,    20,    21,   403,    23,    -1,    -1,    -1,    -1,    -1,
      -1,   403,   216,   217,    -1,    -1,    -1,   417,   418,    -1,
      -1,   225,    -1,   227,    -1,   417,   418,    -1,    -1,    -1,
      -1,    -1,   432,    -1,    -1,   435,    -1,    -1,   242,    -1,
     432,    -1,    -1,   435,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   285,    -1,    -1,   288,    -1,    -1,   291,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   307,    -1,    -1,    -1,    -1,   312,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,     7,
       8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,   333,
      -1,    19,    -1,    21,    -1,    -1,    24,    25,    26,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,   356,   357,    78,    79,    80,    81,    82,    -1,
      -1,    -1,    -1,    -1,    88,    89,    -1,    -1,    -1,    -1,
      58,    -1,    60,    -1,    -1,   379,    -1,    -1,   382,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     3,     4,    -1,    -1,     7,     8,     9,    -1,    11,
      -1,    -1,    14,    -1,    16,    -1,    -1,    19,    -1,    21,
      -1,    -1,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
     434,    -1,     3,     4,    -1,    -1,     7,    -1,    -1,    -1,
      11,    -1,    -1,    14,    -1,    16,    -1,    -1,    19,    -1,
      21,    22,    -1,    24,    25,    26,    58,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    58,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     3,     4,
      -1,    -1,     7,     8,     9,    -1,    11,    -1,    -1,    14,
      -1,    16,    -1,    -1,    19,    -1,    21,    -1,    -1,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    -1,     7,     8,     9,    -1,    11,    -1,    -1,
      14,    -1,    16,    -1,    -1,    19,    -1,    21,    -1,    -1,
      24,    25,    26,    58,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    58,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     3,     4,    -1,    -1,     7,
       8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,
      -1,    19,    -1,    21,    -1,    -1,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,     7,    -1,    -1,
      -1,    11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      58,    21,    60,    -1,    24,    25,    26,    -1,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     3,
       4,    -1,    -1,     7,    -1,    -1,    -1,    11,    -1,    -1,
      14,    -1,    16,    -1,    -1,    19,    -1,    21,    -1,    -1,
      24,    25,    26,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,     3,
       4,    -1,    -1,     7,    88,    89,    -1,    11,    -1,    -1,
      -1,    -1,    16,    -1,    58,    59,    60,    21,    -1,    -1,
      24,    25,    26,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     3,     4,    -1,    -1,     7,
      -1,    -1,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,
      -1,    19,    -1,    21,    -1,    -1,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
       7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,
      -1,    -1,    19,    -1,    21,    -1,    -1,    24,    25,    26,
      58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     3,     4,    -1,    -1,     7,    -1,    -1,    -1,
      11,    -1,    -1,    14,    -1,    16,    -1,    -1,    19,    -1,
      21,    22,    -1,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,     7,    -1,    -1,    -1,    11,    -1,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    21,    58,    59,    24,
      25,    26,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     3,     4,    -1,    -1,     7,    -1,
      -1,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,    -1,
      19,    -1,    21,    -1,    -1,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    24,    -1,    26,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      58,    59,    21,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      58,    -1,    -1,    12,    13,    -1,    15,    -1,    -1,    67,
      68,    69,    70,    71,    72,    24,    13,    -1,    15,    -1,
      78,    79,    80,    81,    82,    -1,    -1,    24,    -1,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    -1,    -1,    -1,    58,
      -1,    48,    61,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    58,    -1,    -1,    61,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      62,    -1,    -1,    65,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    97,     0,    10,    18,    20,    21,    23,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
     103,   104,   105,   106,   107,   108,   109,   110,   148,   150,
     151,   155,   162,   165,    58,    59,    88,    23,    89,    58,
      58,   111,    58,   112,    56,    59,   152,   152,    57,     3,
       4,     7,    11,    16,    21,    24,    25,    26,    56,    57,
      58,    59,   107,   114,   115,   116,   119,   120,   122,   124,
     125,   133,   134,   135,   137,   139,   141,   145,   163,   164,
     166,    58,    57,    34,    55,    63,    55,    14,    19,    58,
      59,   107,   116,   119,   124,   132,   134,   137,   139,   141,
     144,   145,   153,   154,   160,   170,    67,    68,    69,    70,
      71,    78,    79,    80,    81,    82,    88,    89,    91,   149,
      63,    63,    63,    58,    61,    58,    33,   140,    57,    73,
      74,    83,    84,   130,    34,    35,    36,    37,    38,    39,
      40,    92,   164,    56,    56,     5,     6,   128,    56,    60,
     163,    59,    57,    12,   149,    13,    15,    48,    50,    51,
      52,    53,    54,    58,    61,    98,   100,   102,   135,   138,
      58,    50,   113,    58,    51,    58,   131,   102,    33,   161,
     154,    60,   153,    58,    55,   156,   102,   102,    58,   108,
     114,   118,    57,    54,    57,    51,    58,    57,    51,    58,
     143,   146,   133,   102,   102,    60,    63,    63,   110,   167,
      12,   149,    57,    57,    33,    61,   102,    34,    55,    64,
      63,    57,    56,    58,    33,    60,    91,    59,    64,    64,
      58,   117,    56,    50,    62,    12,   102,   136,    58,    65,
     147,   140,   102,   102,    56,   110,   168,    57,    57,    96,
     103,   105,    96,    17,   102,    27,    28,    29,    30,    31,
      32,    33,    41,    42,    43,    44,    45,    46,    47,    49,
      62,    65,    93,    94,    95,    99,   102,    50,    34,   113,
     131,    57,    58,    58,    59,   107,   116,   119,   124,   134,
     139,   145,   157,   160,   170,   126,   123,    34,    55,   102,
      57,    56,    55,    55,    56,   142,   143,    56,    64,    64,
      56,    60,   150,   169,    96,    96,    62,   101,   102,   102,
      64,    57,   136,    57,   157,   157,   157,   157,   157,   157,
     157,   157,    60,    59,    59,   102,    58,    56,    50,   102,
      58,   147,   127,   129,    59,    62,    99,    34,   130,   136,
      60,     8,     9,   107,   116,   119,   124,   132,   134,   137,
     139,   141,   144,   145,   158,   159,   160,   170,   159,    34,
      58,   115,    57,   142,    59,    59,    22,    59,   107,   116,
     119,   124,   132,   134,   137,   139,   141,   144,   145,   160,
     170,   171,   172,   173,   101,   102,    57,   157,    56,    56,
      60,   158,    60,   102,    64,    12,   136,   159,   159,    33,
     172,    60,   172,   130,   121,    56,    56,    60,    60,    58,
      60,   133,    59,    56,    57,   159,   136,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    92,    92,    92,    92,    92,    92,
      93,    93,    93,    93,    93,    93,    94,    94,    94,    94,
      94,    94,    95,    95,    96,    96,    97,    97,    97,    97,
      97,    97,    98,    98,    99,    99,    99,    99,    99,   100,
     100,   100,   100,   100,   101,   101,   102,   102,   102,   102,
     102,   102,   102,   103,   103,   103,   103,   103,   103,   104,
     104,   104,   104,   104,   105,   105,   105,   105,   105,   106,
     106,   106,   106,   106,   107,   108,   108,   108,   108,   109,
     109,   110,   110,   111,   111,   111,   111,   112,   112,   112,
     112,   113,   113,   114,   115,   116,   116,   117,   117,   118,
     118,   119,   119,   121,   120,   123,   122,   124,   126,   125,
     127,   125,   129,   128,   128,   130,   130,   130,   130,   131,
     131,   132,   133,   133,   134,   135,   135,   136,   136,   137,
     137,   138,   139,   140,   140,   140,   141,   142,   142,   143,
     143,   144,   145,   146,   147,   147,   148,   148,   149,   149,
     150,   150,   151,   151,   152,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   154,
     154,   156,   155,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   159,   159,
     160,   161,   161,   162,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   164,   164,   166,   165,   167,
     167,   168,   168,   169,   170,   170,   171,   171,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   173,   173
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       5,     3,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     2,     1,
       1,     2,     2,     1,     3,     3,     5,     4,     6,     6,
       8,     3,     1,     3,     3,     2,     2,     3,     5,     1,
       2,     1,     1,     0,    12,     0,     8,     2,     0,     8,
       0,     9,     0,     8,     0,     1,     1,     1,     1,     1,
       1,     9,     3,     1,     2,     4,     4,     1,     3,     9,
       9,     3,     5,     2,     2,     0,     5,     3,     1,     1,
       1,     3,     5,     2,     3,     0,     2,     2,     2,     4,
       6,     6,     7,     7,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       2,     0,     8,     2,     2,     2,     2,     2,     2,     4,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     2,
       2,     2,     3,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     2,     0,     7,     2,
       3,     2,     0,     4,     5,     6,     4,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 84:
#line 113 "bison.y"
                                        { fprintf(yyout, " : declaration statement"); }
#line 2009 "bison.tab.c"
    break;

  case 105:
#line 148 "bison.y"
                                    { fprintf(yyout, " : assignment statement");  }
#line 2015 "bison.tab.c"
    break;

  case 106:
#line 149 "bison.y"
                                     { fprintf(yyout, " : expression statement");  }
#line 2021 "bison.tab.c"
    break;

  case 113:
#line 164 "bison.y"
                                                                                                   {fprintf(yyout, " : loop statement");}
#line 2027 "bison.tab.c"
    break;

  case 115:
#line 167 "bison.y"
                                               {fprintf(yyout, " : loop statement");}
#line 2033 "bison.tab.c"
    break;

  case 118:
#line 175 "bison.y"
                                                { fprintf(yyout, " : conditional statement");  }
#line 2039 "bison.tab.c"
    break;

  case 120:
#line 176 "bison.y"
                                                                    { fprintf(yyout, " : conditional statement");  }
#line 2045 "bison.tab.c"
    break;

  case 122:
#line 180 "bison.y"
                                                 { fprintf(yyout, " : conditional statement");  }
#line 2051 "bison.tab.c"
    break;

  case 133:
#line 191 "bison.y"
                                                                    { fprintf(yyout, " : analyze statement");  }
#line 2057 "bison.tab.c"
    break;

  case 134:
#line 197 "bison.y"
                                     { fprintf(yyout, " : call statement");  }
#line 2063 "bison.tab.c"
    break;

  case 139:
#line 210 "bison.y"
                                                                                                           { fprintf(yyout, " : call statement");  }
#line 2069 "bison.tab.c"
    break;

  case 140:
#line 211 "bison.y"
                                                                                                             { fprintf(yyout, " : call statement");  }
#line 2075 "bison.tab.c"
    break;

  case 142:
#line 218 "bison.y"
                                                          { fprintf(yyout, " : sleep statement");  }
#line 2081 "bison.tab.c"
    break;

  case 148:
#line 233 "bison.y"
     { 
      fprintf(yyout, " : scan statement");
     }
#line 2089 "bison.tab.c"
    break;

  case 151:
#line 243 "bison.y"
                                        { fprintf(yyout, " : return statement"); }
#line 2095 "bison.tab.c"
    break;

  case 152:
#line 247 "bison.y"
       { 
        fprintf(yyout, " : print statement");
       }
#line 2103 "bison.tab.c"
    break;

  case 160:
#line 265 "bison.y"
                                                                            { fprintf(yyout, " : function declaration statement"); }
#line 2109 "bison.tab.c"
    break;

  case 161:
#line 266 "bison.y"
                                                                             { fprintf(yyout, " : function declaration statement"); }
#line 2115 "bison.tab.c"
    break;

  case 162:
#line 268 "bison.y"
                                                                                      { fprintf(yyout, " : function declaration statement"); }
#line 2121 "bison.tab.c"
    break;

  case 163:
#line 269 "bison.y"
                                                                                        { fprintf(yyout, " : function declaration statement"); }
#line 2127 "bison.tab.c"
    break;

  case 181:
#line 293 "bison.y"
                                      { fprintf(yyout, " : task declaration statement"); }
#line 2133 "bison.tab.c"
    break;

  case 227:
#line 357 "bison.y"
                                 { fprintf(yyout, " : type declaration statement"); }
#line 2139 "bison.tab.c"
    break;


#line 2143 "bison.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 402 "bison.y"


void yyerror(std::string s){
  std::cout << "Syntax Error: " << s << " at line number - " << yylineno << std::endl;
}
