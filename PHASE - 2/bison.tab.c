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
#define YYLAST   1817

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  89
/* YYNRULES -- Number of rules.  */
#define YYNRULES  266
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  463

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
     132,   135,   136,   139,   140,   141,   144,   145,   148,   149,
     152,   153,   154,   155,   158,   162,   165,   168,   169,   172,
     173,   176,   177,   181,   181,   184,   184,   187,   187,   192,
     195,   195,   196,   196,   200,   200,   201,   204,   204,   204,
     204,   207,   207,   209,   211,   211,   217,   220,   221,   225,
     226,   230,   231,   235,   238,   242,   243,   244,   247,   251,
     252,   258,   259,   263,   266,   272,   275,   276,   281,   281,
     283,   283,   285,   286,   288,   289,   291,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   301,   301,   302,   303,
     304,   307,   308,   313,   313,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     346,   347,   351,   352,   353,   357,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   372,   373,   377,
     377,   380,   381,   385,   386,   389,   392,   393,   397,   398,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   418,   419
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
  "arrayList", "dimlist", "LHS", "arr_access", "exprlist", "arith_operand",
  "arith_expr", "assignment_statement", "expression_statement", "log", "g",
  "both_assignment", "loop", "for_loop", "$@1", "while_loop", "$@2",
  "conditional", "when_statement", "$@3", "$@4", "when_default", "$@5",
  "analysis_arrays", "analyze_label", "analyze_statement",
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

#define YYPACT_NINF (-395)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-205)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -395,   707,  -395,   -23,    35,   -41,    -9,    82,  -395,  -395,
    -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,
    -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,
    -395,  -395,  -395,  -395,  -395,    84,    89,     2,  -395,    77,
      77,  -395,  -395,  -395,    94,  1509,  -395,    95,  -395,    97,
     124,   115,   109,   122,  -395,  1595,  -395,  -395,  1190,   116,
     118,   120,   129,   117,   100,   132,   158,   135,  -395,    48,
      -6,  1509,  -395,   274,   141,   144,  -395,  -395,  -395,  -395,
    -395,    19,  -395,  -395,   145,  -395,  -395,  -395,  -395,  -395,
    -395,  1144,   146,   147,   571,   229,   148,   152,   157,    -5,
     229,     6,  1595,  -395,  -395,  -395,  -395,  -395,  -395,  -395,
    -395,  -395,  -395,  -395,  -395,  1230,   312,  -395,  -395,  -395,
    -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,
     160,   161,   229,   229,   664,   162,   168,   171,    41,   172,
      68,  -395,  -395,  -395,  -395,    73,   167,   -28,   198,  1270,
     229,  -395,  -395,  -395,  -395,  -395,  -395,   229,  -395,  -395,
     169,   170,  -395,  -395,  -395,  -395,  1665,   623,   179,   -34,
    -395,   204,   177,  -395,  -395,  -395,  -395,  -395,  -395,   229,
    -395,  -395,  -395,  -395,  -395,   206,  -395,   -15,   176,  -395,
    -395,   186,   190,   189,   216,  1356,  -395,  -395,  -395,  1190,
     193,   191,   202,   199,   233,  -395,   212,   221,   222,   211,
    -395,  -395,   220,  -395,  -395,   209,   158,  -395,  -395,    61,
    -395,  -395,    46,   230,   224,   231,   181,  -395,   235,  -395,
    -395,  -395,   229,   229,   238,  1665,   232,   -12,   520,   520,
     278,   229,  1727,   229,   241,   263,   152,    -5,  -395,   242,
     240,  -395,   243,  1626,  -395,  -395,   268,   250,   229,   249,
     259,  -395,  -395,   262,    79,    68,  -395,   265,  -395,   256,
    -395,    46,  -395,  -395,  -395,  -395,  -395,  -395,    46,  -395,
     255,   260,  -395,   269,   -10,   520,   520,  -395,  -395,  -395,
    -395,  -395,   264,  -395,  -395,  -395,  -395,  -395,  -395,  -395,
    -395,  -395,  -395,  -395,  -395,  -395,  -395,   229,  -395,  -395,
     229,    63,   270,   229,   271,  -395,  1626,  1626,  1626,  1626,
    1626,  1626,  1626,  1626,   272,   275,  -395,   282,   283,   229,
     273,   281,   284,  -395,   229,   286,  -395,  -395,   209,  -395,
    -395,  -395,  -395,  -395,  -395,  -395,  -395,   294,  -395,  -395,
    -395,  -395,   300,  1752,  -395,   329,    48,   262,   229,   305,
    -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  1387,  1387,
    -395,   332,   316,   318,  -395,    79,  -395,   321,   322,  1473,
    -395,   229,   229,   325,   262,  1626,   327,   328,  -395,  -395,
    -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,
     793,   312,  -395,   824,   229,   320,   313,  1137,  -395,  1387,
    1387,   353,  1473,  -395,  -395,  -395,  -395,  -395,  -395,  -395,
    -395,  -395,  -395,  -395,   312,  -395,  -395,  -395,   910,  -395,
    -395,    48,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,
     331,    83,   941,  1027,   335,   337,  -395,  -395,    73,   339,
    -395,  -395,  -395,  -395,    88,  -395,  -395,  1387,  -395,   229,
    1058,   262,  -395
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
      37,     0,     1,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    74,    75,    76,    77,    78,    69,
      70,    71,    72,    73,    79,    80,    81,    82,    83,    87,
      85,    86,    89,    90,    38,     0,     0,     0,    39,     0,
       0,    40,    36,    41,     0,     0,   239,     0,    88,     0,
      93,    91,     0,    92,    84,     0,   168,   169,     0,     0,
       0,     0,     0,     0,     0,     0,   157,     0,   145,     0,
     103,     0,   226,     0,     0,     0,   227,   229,   123,   124,
     228,   136,   232,   230,     0,   231,   236,   234,   233,   105,
     237,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,     0,   177,   178,   181,   183,   184,   180,   179,
     187,   185,   182,   186,   191,     0,   190,   189,     6,     5,
       4,     8,     7,    13,    10,     9,    11,    12,     2,     3,
       0,   193,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   137,   140,   139,     0,     0,     0,   222,     0,
       0,    18,    19,    16,    15,    14,    17,     0,   117,   118,
       0,     0,   129,   146,   225,   238,     0,     0,     0,     0,
      58,     0,     0,    49,    53,    50,    52,    51,    42,     0,
      57,    56,    95,    43,    59,    94,   102,     0,     0,   141,
     142,     0,     0,     0,   222,     0,   176,   192,   170,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,     0,
     155,   156,     0,   161,   162,   167,   157,   144,   223,   111,
     112,   110,     0,   106,     0,   107,     0,   108,     0,   235,
     115,   116,     0,     0,     0,   244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,     0,     0,   163,   223,
       0,   188,     0,     0,   130,   127,     0,   122,     0,     0,
       0,   148,   149,   147,     0,     0,   165,     0,   111,     0,
     104,     0,    29,    26,    27,    28,    31,    30,     0,   224,
       0,     0,   241,     0,     0,     0,     0,   173,    35,    34,
     172,   153,     0,    48,    32,    33,    21,    20,    22,    23,
      24,    25,    61,    47,    45,    44,    46,     0,    96,   101,
       0,     0,     0,     0,   224,   171,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   105,   203,     0,     0,     0,
       0,     0,     0,   154,     0,     0,   160,   158,   167,   164,
     113,   109,   114,   132,   134,   242,   240,     0,   243,   175,
     174,    62,     0,    55,    99,    98,     0,   246,     0,     0,
     195,   196,   198,   197,   199,   202,   200,   194,     0,     0,
     119,     0,     0,     0,   150,     0,   166,     0,     0,     0,
      60,     0,     0,     0,   247,     0,     0,     0,   205,   206,
     208,   207,   212,   210,   211,   214,   217,   209,   213,   220,
       0,   219,   218,     0,     0,     0,     0,     0,   159,     0,
       0,     0,     0,   250,   251,   254,   256,   257,   253,   252,
     260,   258,   255,   259,   264,   263,   262,   265,     0,    54,
     100,     0,   201,   215,   216,   131,   221,   128,   120,   125,
       0,     0,     0,     0,     0,     0,   245,   266,     0,     0,
     152,   151,   133,   135,     0,   261,   143,     0,   248,     0,
       0,   249,   126
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -395,   207,  -395,  -395,   184,  -395,  -197,  -395,  -395,    54,
    -395,    32,   -59,  -201,  -395,  -174,  -395,    -1,   280,  -395,
    -149,  -395,  -395,  -143,  -131,  -395,  -395,   137,  -193,   285,
      44,    22,  -395,  -395,    26,  -395,  -395,  -395,  -395,    78,
    -395,  -395,  -395,  -395,  -395,  -348,   173,   -36,  -144,   105,
     366,  -302,   -43,  -395,   143,   208,   -40,    42,   165,     0,
     205,  -395,    85,  -395,   -85,   149,  -395,   397,  -108,   338,
    -395,  -395,  -155,  -257,  -349,   -39,   342,  -395,   -81,   368,
    -395,  -395,  -395,  -395,  -395,   201,  -395,  -394,  -395
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   130,   157,   304,   305,   306,   287,     1,   180,   307,
     181,   352,   262,    30,    31,    32,    33,   317,    35,    36,
      37,    51,    53,   187,    73,   224,   225,   226,   227,    74,
      75,   318,   257,   206,   319,    78,   449,    79,   328,   320,
      81,   327,   377,   162,   378,   145,   191,   392,    82,   321,
      84,   263,   394,   184,   322,   139,   396,   337,   215,   397,
     323,   216,   266,    38,   131,    39,    40,    56,   114,   115,
      41,   200,   324,   399,   400,   325,   148,    42,    90,    91,
      43,    92,   235,   284,   348,   326,   426,   427,   428
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,   217,    85,   204,   223,    87,    89,   197,   383,   169,
     165,   357,   109,     7,    47,   111,   116,   234,   445,   107,
     403,   199,   219,   239,   160,   161,   220,   146,    85,   269,
     221,    87,    89,   222,   447,    44,   182,   288,   288,   193,
     244,   192,   290,   199,    72,   286,   189,    46,    85,   245,
     346,    87,    89,   190,   103,   112,   384,   147,    54,   109,
     442,   443,   111,   116,   289,   289,   107,    76,   165,   147,
      72,    77,   109,   201,   202,   111,   116,   104,   341,   107,
      48,   105,   237,   448,   288,   288,   283,   197,   349,   350,
      72,   230,   210,    76,    45,    89,   268,    77,   231,   211,
     220,   103,   112,   311,   221,   441,    85,   222,   460,    87,
      89,   289,   289,    76,   103,   112,  -102,    77,   244,   213,
     242,   141,   142,    80,   104,  -102,   214,   355,   105,    68,
      69,   143,   144,   106,   335,   336,    55,   104,   334,   451,
      49,   105,    50,   436,   458,   459,   436,    52,    72,    80,
      83,    58,   109,    93,    94,   111,   116,   461,    95,   107,
     108,   359,   360,   361,   362,   363,   364,   365,   366,    80,
      96,    76,    97,   280,   281,    77,    83,    98,   136,   132,
     106,   133,   292,   134,   308,   436,   436,   135,    86,    48,
     137,   138,   140,   106,   103,   112,    83,   158,   110,   331,
     159,   163,   186,   436,   167,   166,   185,   108,   272,   273,
     274,   275,   276,   277,    86,   188,   199,   104,   198,   207,
     108,   105,   208,   261,   170,   218,   171,    80,   209,   212,
     432,   228,   232,   233,    86,    65,   238,   240,   241,   246,
     243,   405,   170,   247,   171,   110,   248,   249,   353,   250,
      88,   354,   253,    65,    83,   254,   117,   256,   110,   172,
     113,   173,   174,   175,   176,   177,   255,   150,   258,   178,
     370,   259,   179,   106,   265,   374,    88,   172,   264,   173,
     174,   175,   176,   177,   260,   244,   271,   178,   270,   285,
     179,   309,    86,   279,   282,   291,    88,   310,   314,   313,
     108,   315,   329,   117,   456,   330,   332,   113,   150,   151,
     152,   153,   154,   155,   156,   333,   117,   334,   340,   343,
     113,   339,   353,   430,   344,   345,   351,   356,   358,   401,
     401,   371,   367,    89,   373,  -204,   419,   372,   110,   421,
     424,   368,   369,   417,   375,   438,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,   379,    88,   151,   152,   153,   154,   155,
     156,   401,   380,   382,   401,   385,   404,   388,   388,   419,
     401,   401,   421,   424,    70,   407,   417,   439,   413,   422,
     409,   410,   431,   433,   434,   419,   444,   450,   421,   424,
     389,   389,   417,   454,   390,   390,   117,   455,   457,   388,
     113,   414,   388,   401,   401,   415,   252,   381,   388,   388,
     278,   413,   422,   429,   203,   342,   406,   408,   401,   205,
     312,   401,   389,   376,   267,   389,   390,   413,   422,   390,
     338,   389,   389,   347,   414,   390,   390,    57,   415,   149,
     195,   388,   388,   194,     0,     0,   391,   391,     0,     0,
     414,     0,     0,     0,   415,     0,   388,   416,     0,   388,
       0,   183,     0,     0,   389,   389,   183,     0,   390,   390,
       0,     0,     0,   393,   393,     0,     0,     0,   391,   389,
       0,   391,   389,   390,   418,     0,   390,   391,   391,     0,
     416,     0,     0,     0,     0,     0,     0,     0,   183,   183,
       0,     0,     0,     0,     0,   393,   416,     0,   393,     0,
       0,   395,   395,     0,   393,   393,   183,   418,     0,     0,
     391,   391,   420,   183,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   418,     0,   391,     0,     0,   391,     0,
       0,     0,     0,   395,     0,   183,   395,   393,   393,     0,
       0,     0,   395,   395,     0,   420,     0,     0,     0,     0,
       0,     0,   393,     0,     0,   393,     0,     0,     0,   402,
     402,   420,     0,   398,   398,   183,     0,     0,     0,     0,
     425,     0,     0,   168,   423,   395,   395,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,   183,   183,
     395,   402,     0,   395,   402,   398,     0,   183,   398,   183,
     402,   402,     0,   425,   398,   398,     0,   423,     0,     0,
       0,     0,     0,     0,   183,     0,     0,     0,     0,   425,
       0,     0,     0,   423,     0,   236,     0,     0,   118,   119,
     120,   121,   122,   402,   402,     0,     0,   398,   398,   123,
     124,   125,   126,   127,     0,     0,     0,     0,   402,   128,
     129,   402,   398,     0,     0,   398,     0,     0,     0,     0,
       0,     0,     0,   183,     0,     0,   183,     0,     0,   183,
       0,     0,     0,     0,     0,    64,     0,     0,     0,     0,
     118,   119,   120,   121,   122,   183,     0,     0,     0,     0,
     183,   123,   124,   125,   126,   127,     0,     2,     0,     0,
       0,   128,   129,     0,     0,     0,     0,     3,     0,     0,
       0,     0,    70,     0,   183,     4,     0,     5,     6,     0,
       7,     8,     9,    10,    11,    12,    13,     0,     0,     0,
       0,     0,    19,    20,    21,    22,    23,   183,   183,     0,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     183,     0,     0,   183,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    59,    60,     0,     0,
      61,   386,   387,     0,    62,     0,     0,    99,     0,    63,
       0,     0,   100,     0,    64,     0,     0,    65,    66,    67,
       0,     0,     0,     0,     0,   183,     0,    59,    60,     0,
       0,    61,   386,   387,     0,    62,     0,     0,    99,     0,
      63,     0,     0,   100,     0,    64,     0,     0,    65,    66,
      67,   101,     0,   435,     0,     0,     0,     0,     0,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,   101,     0,   437,     0,     0,     0,     0,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    59,    60,     0,     0,    61,     0,     0,
       0,    62,     0,     0,    99,     0,    63,     0,     0,   100,
       0,    64,   411,     0,    65,    66,    67,     0,     0,     0,
       0,     0,     0,     0,    59,    60,     0,     0,    61,   386,
     387,     0,    62,     0,     0,    99,     0,    63,     0,     0,
     100,     0,    64,     0,     0,    65,    66,    67,   101,   412,
     446,     0,     0,     0,     0,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,   101,
       0,   452,     0,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      59,    60,     0,     0,    61,   386,   387,     0,    62,     0,
       0,    99,     0,    63,     0,     0,   100,     0,    64,     0,
       0,    65,    66,    67,     0,     0,     0,     0,     0,     0,
       0,    59,    60,     0,     0,    61,   386,   387,     0,    62,
       0,     0,    99,     0,    63,     0,     0,   100,     0,    64,
       0,     0,    65,    66,    67,   101,     0,   453,     0,     0,
       0,     0,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,   101,     0,   462,     0,
       0,     0,     0,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    59,    60,   440,
     170,    61,   171,     0,     0,    62,     0,     0,     0,     0,
      63,    65,     0,     0,     0,    64,     0,     0,    65,    66,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   172,     0,   173,   174,   175,
     176,   177,     0,     0,     0,   178,     0,     0,   179,     0,
      68,    69,    70,    71,   164,     0,     0,     0,     0,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    59,    60,     0,     0,    61,     0,     0,
       0,    62,     0,     0,    99,     0,    63,     0,     0,   100,
       0,    64,     0,     0,    65,    66,    67,   118,   119,   120,
     121,   122,     0,     0,     0,     0,     0,     0,   123,   124,
     125,   126,   127,    59,    60,     0,     0,    61,   128,   129,
       0,    62,     0,     0,     0,     0,    63,     0,   101,   102,
     196,    64,     0,     0,    65,    66,    67,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     0,
       0,     0,     0,     0,     0,     0,    68,    69,    70,    71,
     229,     0,     0,     0,     0,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    59,
      60,     0,     0,    61,     0,     0,     0,    62,     0,     0,
      99,     0,    63,     0,     0,   100,     0,    64,     0,     0,
      65,    66,    67,     0,     0,     0,     0,     0,     0,     0,
      59,    60,     0,     0,    61,   386,   387,     0,    62,     0,
       0,    99,     0,    63,     0,     0,   100,     0,    64,     0,
       0,    65,    66,    67,   101,   102,   251,     0,     0,     0,
       0,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    59,    60,     0,     0,
      61,     0,     0,     0,    62,     0,     0,    99,     0,    63,
       0,     0,   100,     0,    64,   411,     0,    65,    66,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    59,    60,     0,     0,    61,     0,     0,     0,
      62,     0,     0,     0,     0,    63,     0,     0,     0,     0,
      64,   101,   412,    65,    66,    67,     0,     0,     0,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     0,     0,     0,    68,    69,    70,    71,     0,
       0,     0,     0,     0,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    59,    60,
       0,     0,    61,     0,     0,     0,    62,     0,     0,    99,
       0,    63,     0,     0,   100,     0,    64,     0,     0,    65,
      66,    67,     0,     0,     0,     0,     0,     0,     0,    59,
      60,     0,     0,    61,     0,     0,     0,     0,     0,     0,
       0,     0,    63,     0,     0,     0,     0,    64,     0,     0,
      65,     0,    67,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   101,   316,    64,     0,     0,     0,
       0,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   272,   273,   274,   275,   276,   277,
     293,     0,     0,     0,     0,     0,     0,     0,   294,   295,
     296,   297,   298,   299,   300,     0,   301,     0,     0,   272,
     273,   274,   275,   276,   277,   293,     0,     0,     0,   302,
       0,     0,   303,   294,   295,   296,   297,   298,   299,   300,
       0,   301,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   303
};

static const yytype_int16 yycheck[] =
{
       1,   145,    45,   134,   147,    45,    45,   115,   356,    94,
      91,   313,    55,    23,    23,    55,    55,   166,   412,    55,
     369,    55,    50,    57,     5,     6,    54,    33,    71,   222,
      58,    71,    71,    61,   428,    58,    95,   238,   239,    33,
      55,   100,   239,    55,    45,    57,    51,    88,    91,    64,
      60,    91,    91,    58,    55,    55,   358,    63,    56,   102,
     409,   410,   102,   102,   238,   239,   102,    45,   149,    63,
      71,    45,   115,   132,   133,   115,   115,    55,   271,   115,
      89,    55,   167,   431,   285,   286,   235,   195,   285,   286,
      91,   150,    51,    71,    59,   134,    50,    71,   157,    58,
      54,   102,   102,   246,    58,   407,   149,    61,   457,   149,
     149,   285,   286,    91,   115,   115,    55,    91,    55,    51,
     179,    73,    74,    45,   102,    64,    58,    64,   102,    56,
      57,    83,    84,    55,    55,    56,    59,   115,    55,    56,
      58,   115,    58,   400,    56,    57,   403,    58,   149,    71,
      45,    57,   195,    58,    57,   195,   195,   459,    34,   195,
      55,   316,   317,   318,   319,   320,   321,   322,   323,    91,
      55,   149,    63,   232,   233,   149,    71,    55,    61,    63,
     102,    63,   241,    63,   243,   442,   443,    58,    45,    89,
      58,    33,    57,   115,   195,   195,    91,    56,    55,   258,
      56,    56,    50,   460,    57,    59,    58,   102,    27,    28,
      29,    30,    31,    32,    71,    58,    55,   195,    58,    57,
     115,   195,    54,    12,    13,    58,    15,   149,    57,    57,
     385,    33,    63,    63,    91,    24,    57,    33,    61,    63,
      34,   372,    13,    57,    15,   102,    56,    58,   307,    33,
      45,   310,    59,    24,   149,    64,    55,    58,   115,    48,
      55,    50,    51,    52,    53,    54,    64,    34,    56,    58,
     329,    50,    61,   195,    65,   334,    71,    48,    58,    50,
      51,    52,    53,    54,    62,    55,    55,    58,    64,    57,
      61,    50,   149,    58,    56,    17,    91,    34,    58,    57,
     195,    58,    34,   102,   448,    55,    57,   102,    34,    35,
      36,    37,    38,    39,    40,    56,   115,    55,    62,    64,
     115,    56,   381,   382,    64,    56,    62,    57,    57,   368,
     369,    58,    60,   372,    50,    60,   379,    56,   195,   379,
     379,    59,    59,   379,    58,   404,    34,    35,    36,    37,
      38,    39,    40,    59,   149,    35,    36,    37,    38,    39,
      40,   400,    62,    34,   403,    60,    34,   368,   369,   412,
     409,   410,   412,   412,    58,    57,   412,    64,   379,   379,
      59,    59,    57,    56,    56,   428,    33,    56,   428,   428,
     368,   369,   428,    58,   368,   369,   195,    60,    59,   400,
     195,   379,   403,   442,   443,   379,   199,   353,   409,   410,
     226,   412,   412,   381,   134,   278,   372,   375,   457,   134,
     247,   460,   400,   338,   216,   403,   400,   428,   428,   403,
     265,   409,   410,   284,   412,   409,   410,    40,   412,    71,
     102,   442,   443,   101,    -1,    -1,   368,   369,    -1,    -1,
     428,    -1,    -1,    -1,   428,    -1,   457,   379,    -1,   460,
      -1,    95,    -1,    -1,   442,   443,   100,    -1,   442,   443,
      -1,    -1,    -1,   368,   369,    -1,    -1,    -1,   400,   457,
      -1,   403,   460,   457,   379,    -1,   460,   409,   410,    -1,
     412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,
      -1,    -1,    -1,    -1,    -1,   400,   428,    -1,   403,    -1,
      -1,   368,   369,    -1,   409,   410,   150,   412,    -1,    -1,
     442,   443,   379,   157,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,    -1,   457,    -1,    -1,   460,    -1,
      -1,    -1,    -1,   400,    -1,   179,   403,   442,   443,    -1,
      -1,    -1,   409,   410,    -1,   412,    -1,    -1,    -1,    -1,
      -1,    -1,   457,    -1,    -1,   460,    -1,    -1,    -1,   368,
     369,   428,    -1,   368,   369,   209,    -1,    -1,    -1,    -1,
     379,    -1,    -1,    12,   379,   442,   443,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,   232,   233,
     457,   400,    -1,   460,   403,   400,    -1,   241,   403,   243,
     409,   410,    -1,   412,   409,   410,    -1,   412,    -1,    -1,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,   428,
      -1,    -1,    -1,   428,    -1,    12,    -1,    -1,    67,    68,
      69,    70,    71,   442,   443,    -1,    -1,   442,   443,    78,
      79,    80,    81,    82,    -1,    -1,    -1,    -1,   457,    88,
      89,   460,   457,    -1,    -1,   460,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   307,    -1,    -1,   310,    -1,    -1,   313,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,   329,    -1,    -1,    -1,    -1,
     334,    78,    79,    80,    81,    82,    -1,     0,    -1,    -1,
      -1,    88,    89,    -1,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    58,    -1,   358,    18,    -1,    20,    21,    -1,
      23,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,   381,   382,    -1,
      -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     404,    -1,    -1,   407,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     3,     4,    -1,    -1,
       7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,
      -1,    -1,    19,    -1,    21,    -1,    -1,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,   459,    -1,     3,     4,    -1,
      -1,     7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,
      16,    -1,    -1,    19,    -1,    21,    -1,    -1,    24,    25,
      26,    58,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    58,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     3,     4,    -1,    -1,     7,    -1,    -1,
      -1,    11,    -1,    -1,    14,    -1,    16,    -1,    -1,    19,
      -1,    21,    22,    -1,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,     7,     8,
       9,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,    -1,
      19,    -1,    21,    -1,    -1,    24,    25,    26,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    58,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       3,     4,    -1,    -1,     7,     8,     9,    -1,    11,    -1,
      -1,    14,    -1,    16,    -1,    -1,    19,    -1,    21,    -1,
      -1,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,     7,     8,     9,    -1,    11,
      -1,    -1,    14,    -1,    16,    -1,    -1,    19,    -1,    21,
      -1,    -1,    24,    25,    26,    58,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    58,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     3,     4,    12,
      13,     7,    15,    -1,    -1,    11,    -1,    -1,    -1,    -1,
      16,    24,    -1,    -1,    -1,    21,    -1,    -1,    24,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    58,    -1,    -1,    61,    -1,
      56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     3,     4,    -1,    -1,     7,    -1,    -1,
      -1,    11,    -1,    -1,    14,    -1,    16,    -1,    -1,    19,
      -1,    21,    -1,    -1,    24,    25,    26,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,     3,     4,    -1,    -1,     7,    88,    89,
      -1,    11,    -1,    -1,    -1,    -1,    16,    -1,    58,    59,
      60,    21,    -1,    -1,    24,    25,    26,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     3,
       4,    -1,    -1,     7,    -1,    -1,    -1,    11,    -1,    -1,
      14,    -1,    16,    -1,    -1,    19,    -1,    21,    -1,    -1,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    -1,     7,     8,     9,    -1,    11,    -1,
      -1,    14,    -1,    16,    -1,    -1,    19,    -1,    21,    -1,
      -1,    24,    25,    26,    58,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     3,     4,    -1,    -1,
       7,    -1,    -1,    -1,    11,    -1,    -1,    14,    -1,    16,
      -1,    -1,    19,    -1,    21,    22,    -1,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    -1,     7,    -1,    -1,    -1,
      11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,
      21,    58,    59,    24,    25,    26,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     3,     4,
      -1,    -1,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,
      -1,    16,    -1,    -1,    19,    -1,    21,    -1,    -1,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      24,    -1,    26,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    58,    59,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    62,
      -1,    -1,    65,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    97,     0,    10,    18,    20,    21,    23,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
     103,   104,   105,   106,   107,   108,   109,   110,   153,   155,
     156,   160,   167,   170,    58,    59,    88,    23,    89,    58,
      58,   111,    58,   112,    56,    59,   157,   157,    57,     3,
       4,     7,    11,    16,    21,    24,    25,    26,    56,    57,
      58,    59,   107,   114,   119,   120,   121,   124,   125,   127,
     129,   130,   138,   139,   140,   142,   144,   146,   150,   165,
     168,   169,   171,    58,    57,    34,    55,    63,    55,    14,
      19,    58,    59,   107,   121,   124,   129,   137,   139,   142,
     144,   146,   149,   150,   158,   159,   165,   175,    67,    68,
      69,    70,    71,    78,    79,    80,    81,    82,    88,    89,
      91,   154,    63,    63,    63,    58,    61,    58,    33,   145,
      57,    73,    74,    83,    84,   135,    33,    63,   166,   169,
      34,    35,    36,    37,    38,    39,    40,    92,    56,    56,
       5,     6,   133,    56,    60,   168,    59,    57,    12,   154,
      13,    15,    48,    50,    51,    52,    53,    54,    58,    61,
      98,   100,   102,   140,   143,    58,    50,   113,    58,    51,
      58,   136,   102,    33,   166,   159,    60,   158,    58,    55,
     161,   102,   102,   108,   114,   119,   123,    57,    54,    57,
      51,    58,    57,    51,    58,   148,   151,   138,    58,    50,
      54,    58,    61,   113,   115,   116,   117,   118,    33,    60,
     102,   102,    63,    63,   110,   172,    12,   154,    57,    57,
      33,    61,   102,    34,    55,    64,    63,    57,    56,    58,
      33,    60,    91,    59,    64,    64,    58,   122,    56,    50,
      62,    12,   102,   141,    58,    65,   152,   145,    50,   118,
      64,    55,    27,    28,    29,    30,    31,    32,    94,    58,
     102,   102,    56,   110,   173,    57,    57,    96,   103,   105,
      96,    17,   102,    33,    41,    42,    43,    44,    45,    46,
      47,    49,    62,    65,    93,    94,    95,    99,   102,    50,
      34,   113,   136,    57,    58,    58,    59,   107,   121,   124,
     129,   139,   144,   150,   162,   165,   175,   131,   128,    34,
      55,   102,    57,    56,    55,    55,    56,   147,   148,    56,
      62,   118,   117,    64,    64,    56,    60,   155,   174,    96,
      96,    62,   101,   102,   102,    64,    57,   141,    57,   162,
     162,   162,   162,   162,   162,   162,   162,    60,    59,    59,
     102,    58,    56,    50,   102,    58,   152,   132,   134,    59,
      62,    99,    34,   135,   141,    60,     8,     9,   107,   121,
     124,   129,   137,   139,   142,   144,   146,   149,   150,   163,
     164,   165,   175,   164,    34,   114,   120,    57,   147,    59,
      59,    22,    59,   107,   121,   124,   129,   137,   139,   142,
     144,   146,   149,   150,   165,   175,   176,   177,   178,   101,
     102,    57,   162,    56,    56,    60,   163,    60,   102,    64,
      12,   141,   164,   164,    33,   177,    60,   177,   135,   126,
      56,    56,    60,    60,    58,    60,   138,    59,    56,    57,
     164,   141,    60
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
     112,   113,   113,   114,   114,   114,   115,   115,   116,   116,
     117,   117,   117,   117,   118,   119,   120,   121,   121,   122,
     122,   123,   123,   124,   124,   126,   125,   128,   127,   129,
     131,   130,   132,   130,   134,   133,   133,   135,   135,   135,
     135,   136,   136,   137,   138,   138,   139,   140,   140,   141,
     141,   142,   142,   143,   144,   145,   145,   145,   146,   147,
     147,   148,   148,   149,   150,   151,   152,   152,   153,   153,
     154,   154,   155,   155,   156,   156,   157,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   159,   159,   161,   160,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     164,   164,   165,   166,   166,   167,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   169,   169,   171,
     170,   172,   172,   173,   173,   174,   175,   175,   176,   176,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   178,   178
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
       8,     3,     1,     1,     4,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     3,     3,     3,     2,     2,     3,
       5,     1,     2,     1,     1,     0,    12,     0,     8,     2,
       0,     8,     0,     9,     0,     8,     0,     1,     1,     1,
       1,     1,     1,     9,     3,     1,     2,     4,     4,     1,
       3,     9,     9,     3,     5,     2,     2,     0,     5,     3,
       1,     1,     1,     3,     5,     2,     3,     0,     2,     2,
       2,     4,     6,     6,     7,     7,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     2,     0,     8,     2,     2,     2,     2,     2,
       2,     4,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     2,     2,     2,     3,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     2,     0,
       7,     2,     3,     2,     0,     4,     5,     6,     4,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     2
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
#line 2020 "bison.tab.c"
    break;

  case 117:
#line 168 "bison.y"
                                    { fprintf(yyout, " : assignment statement");  }
#line 2026 "bison.tab.c"
    break;

  case 118:
#line 169 "bison.y"
                                     { fprintf(yyout, " : expression statement");  }
#line 2032 "bison.tab.c"
    break;

  case 125:
#line 184 "bison.y"
                                                                                                   {fprintf(yyout, " : loop statement");}
#line 2038 "bison.tab.c"
    break;

  case 127:
#line 187 "bison.y"
                                               {fprintf(yyout, " : loop statement");}
#line 2044 "bison.tab.c"
    break;

  case 130:
#line 195 "bison.y"
                                                { fprintf(yyout, " : conditional statement");  }
#line 2050 "bison.tab.c"
    break;

  case 132:
#line 196 "bison.y"
                                                                    { fprintf(yyout, " : conditional statement");  }
#line 2056 "bison.tab.c"
    break;

  case 134:
#line 200 "bison.y"
                                                 { fprintf(yyout, " : conditional statement");  }
#line 2062 "bison.tab.c"
    break;

  case 145:
#line 211 "bison.y"
                                                                    { fprintf(yyout, " : analyze statement");  }
#line 2068 "bison.tab.c"
    break;

  case 146:
#line 217 "bison.y"
                                     { fprintf(yyout, " : call statement");  }
#line 2074 "bison.tab.c"
    break;

  case 151:
#line 230 "bison.y"
                                                                                                           { fprintf(yyout, " : call statement");  }
#line 2080 "bison.tab.c"
    break;

  case 152:
#line 231 "bison.y"
                                                                                                             { fprintf(yyout, " : call statement");  }
#line 2086 "bison.tab.c"
    break;

  case 154:
#line 238 "bison.y"
                                                          { fprintf(yyout, " : sleep statement");  }
#line 2092 "bison.tab.c"
    break;

  case 160:
#line 253 "bison.y"
     { 
      fprintf(yyout, " : scan statement");
     }
#line 2100 "bison.tab.c"
    break;

  case 163:
#line 263 "bison.y"
                                        { fprintf(yyout, " : return statement"); }
#line 2106 "bison.tab.c"
    break;

  case 164:
#line 267 "bison.y"
       { 
        fprintf(yyout, " : print statement");
       }
#line 2114 "bison.tab.c"
    break;

  case 172:
#line 285 "bison.y"
                                                                            { fprintf(yyout, " : function declaration statement"); }
#line 2120 "bison.tab.c"
    break;

  case 173:
#line 286 "bison.y"
                                                                             { fprintf(yyout, " : function declaration statement"); }
#line 2126 "bison.tab.c"
    break;

  case 174:
#line 288 "bison.y"
                                                                                      { fprintf(yyout, " : function declaration statement"); }
#line 2132 "bison.tab.c"
    break;

  case 175:
#line 289 "bison.y"
                                                                                        { fprintf(yyout, " : function declaration statement"); }
#line 2138 "bison.tab.c"
    break;

  case 193:
#line 313 "bison.y"
                                      { fprintf(yyout, " : task declaration statement"); }
#line 2144 "bison.tab.c"
    break;

  case 239:
#line 377 "bison.y"
                                 { fprintf(yyout, " : type declaration statement"); }
#line 2150 "bison.tab.c"
    break;


#line 2154 "bison.tab.c"

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
#line 422 "bison.y"


void yyerror(std::string s){
  std::cout << "Syntax Error: " << s << " at line number - " << yylineno << std::endl;
}
