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

  extern int yylex();
  extern int yylineno;
  void yyerror(std::string s);

#line 79 "bison.tab.c"

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
#define YYLAST   1605

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  231
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  433

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
       0,    53,    53,    53,    53,    53,    53,    53,    54,    54,
      54,    54,    54,    54,    55,    55,    55,    55,    55,    55,
      56,    56,    57,    57,    59,    60,    61,    62,    63,    69,
      70,    73,    74,    75,    76,    79,    80,    81,    82,    83,
      86,    87,    90,    91,    92,    93,    94,    95,    99,    99,
      99,    99,    99,    99,   100,   100,   100,   100,   100,   102,
     102,   102,   102,   102,   103,   103,   103,   103,   103,   108,
     109,   112,   112,   112,   112,   113,   113,   115,   116,   119,
     120,   121,   122,   125,   126,   127,   128,   131,   132,   138,
     141,   144,   145,   149,   150,   153,   153,   156,   156,   159,
     159,   164,   167,   167,   168,   168,   172,   172,   173,   176,
     176,   176,   176,   179,   179,   181,   183,   183,   188,   189,
     190,   191,   194,   197,   198,   199,   204,   207,   209,   210,
     215,   219,   220,   221,   224,   228,   229,   235,   236,   240,
     243,   249,   252,   253,   258,   258,   260,   260,   261,   262,
     264,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     274,   275,   276,   277,   278,   279,   280,   285,   285,   288,
     289,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   323,   324,   328,
     329,   330,   334,   337,   338,   341,   342,   345,   346,   349,
     352,   353,   357,   358,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     379,   380
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
  "UDATATYPE", "AUDATATYPE", "$accept", "expression_op", "comparison_op",
  "arithmetic_op", "logical_op", "nonAtomic_datatypes", "begin", "T",
  "all_ops", "constants", "next", "RHS", "nonAtomicSimple", "atomicSimple",
  "nonAtomicArray", "atomicArray", "declaration", "simpleDatatype",
  "arrayDatatype", "declarationStmt", "simpleList", "arrayList", "dimlist",
  "assignment_statement", "expression_statement", "log", "both_assignment",
  "loop", "for_loop", "$@1", "while_loop", "$@2", "conditional",
  "when_statement", "$@3", "$@4", "when_default", "$@5", "analysis_arrays",
  "analyze_label", "analyze_syntax", "analyze_statement", "is",
  "func_invoke", "arguments", "task_invoke", "get_invoke", "get_statement",
  "sleep", "file_name", "input", "nextip", "stringvalues",
  "return_statement", "output", "opstring", "nextop", "function",
  "func_args", "func_decl", "atomic_func_decl", "func_body",
  "func_statements", "task", "$@6", "tid_expr", "taskscope", "statement",
  "statements", "access", "id", "type_declaration", "attributes",
  "attribute", "methods", "method", "method_invoke", "in_statement",
  "method_statements", "method_body", YY_NULLPTR
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

#define YYPACT_NINF (-357)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -357,   767,  -357,   -21,   -42,   -18,   -10,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  1517,     3,    20,    32,  -357,    57,    57,
    -357,  -357,    38,    60,    65,  -357,    73,    51,    76,   112,
      94,    92,   101,  -357,  1378,  -357,  -357,    99,  1517,   103,
      99,  -357,   461,   104,   113,   110,   107,   119,   128,   134,
      -8,   105,   461,   136,   138,   139,   141,  1378,   137,   142,
    1378,   143,   146,  1378,  1378,  -357,  -357,  1378,   108,  1378,
    1378,  1378,  1378,  1378,  1378,  1378,  1378,   147,  1378,  1378,
    -357,   153,   152,   154,  1448,   155,    99,   -32,   164,   156,
    -357,  -357,  -357,  -357,  -357,  -357,   461,  -357,  -357,  -357,
    -357,  -357,   180,  -357,    28,   158,   461,   461,  1479,   161,
    -357,  -357,   166,   170,   159,   171,     9,   172,    26,    -3,
     461,  -357,  -357,  -357,  -357,  -357,  -357,   461,   205,   181,
     208,   209,   188,  -357,  -357,  -357,  -357,  -357,  -357,   183,
     184,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,   192,   193,  -357,   191,   196,   195,   -16,
    -357,  -357,   -17,   631,   240,   461,   856,   461,   206,   224,
     113,   197,   199,   225,  -357,  -357,   204,   215,    -8,   210,
    -357,   100,  -357,  -357,   212,  -357,  -357,   203,   138,  -357,
    -357,  -357,  -357,    -2,  1378,   252,   252,  -357,   461,   461,
    -357,  1409,   113,   941,  -357,  -357,  -357,   631,  -357,  -357,
    -357,  -357,   211,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,   461,  -357,  -357,   461,    34,  -357,  -357,   461,
     214,   217,   220,  -357,  -357,  -357,  -357,  -357,  -357,    66,
      72,    26,  -357,   221,  -357,  -357,  -357,   222,   226,   227,
     228,  1409,   223,   235,  1409,  1409,  1409,  1409,  1409,  1409,
    1409,  1409,   234,  -357,  -357,    36,   262,  -357,    52,   941,
    1517,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,   855,  -357,  -357,   238,
     942,  -357,   267,   243,   244,   248,   255,    52,  -357,   530,
    -357,   249,  -357,  -357,   203,  -357,  -357,  -357,  -357,  -357,
     246,   274,   279,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,    11,  -357,  -357,  -357,  -357,    81,   254,
    -357,  -357,  -357,   461,   461,  1292,  1292,   258,   263,   265,
    -357,    72,  -357,   260,   264,  1409,   313,   322,   269,  -357,
    -357,  -357,  -357,  -357,   280,   281,  1517,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  1027,  -357,
    -357,  1058,   150,   275,   100,    52,  -357,  1292,  1292,  -357,
     282,   284,  -357,  -357,  -357,  -357,  -357,  -357,  -357,    87,
      81,  1144,  1175,  -357,  -357,   289,  -357,  -357,  -357,  -357,
    1292,  1261,  -357
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      24,     0,     1,     0,     0,     0,     0,    48,    49,    50,
      51,    52,    53,    59,    60,    61,    62,    63,    54,    55,
      56,    57,    58,    64,    65,    66,    67,    68,    73,    71,
      72,    75,    76,    25,     0,     0,     0,    26,     0,     0,
      27,    28,     0,     0,     0,    74,     0,     0,     0,    79,
      77,     0,    78,    69,   166,   144,   145,     0,     0,     0,
       0,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   133,     0,     0,   166,     0,     0,
     166,     0,     0,   166,   166,    95,    96,   166,   108,   166,
     166,   166,   166,   166,   166,   166,   166,     0,   166,   166,
     146,   167,     0,     0,     0,     0,     0,     0,     0,     0,
      35,    39,    36,    38,    37,    29,     0,    43,    42,    81,
      30,    47,    80,    88,     0,     0,     0,     0,     0,     0,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     6,     7,     4,     3,     2,     5,     0,   199,     0,
       0,     0,     0,   151,    91,    92,   152,   155,   157,     0,
       0,   101,   158,   154,   153,   163,   161,   159,   156,   160,
     150,   165,   164,     0,     0,   205,     0,     0,     0,     0,
     207,   203,     0,     0,     0,     0,     0,     0,     0,    83,
       0,     0,     0,     0,    94,    93,     0,     0,     0,     0,
     139,     0,   131,   132,     0,   137,   138,   143,   133,   200,
     210,    89,    90,     0,   166,     0,     0,    69,     0,     0,
     147,     0,     0,     0,   204,   202,   208,     0,   148,    23,
      22,   127,     0,    17,    14,    15,    16,    19,    18,    20,
      21,     9,     8,    10,    11,    12,    13,    45,    34,    32,
      31,    33,     0,    82,    87,     0,     0,   102,    99,     0,
       0,     0,     0,   125,    29,    42,   121,   123,    30,     0,
       0,     0,   141,     0,   201,   211,   162,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,   180,     0,     0,   117,     0,     0,
     214,   215,   218,   220,   221,   217,   216,   226,   224,   222,
     219,   223,   229,   228,   227,   230,     0,   149,    46,     0,
      41,    85,    84,     0,     0,     0,     0,     0,   130,     0,
     122,     0,   136,   134,   143,   140,   128,   129,   104,   106,
       0,     0,     0,   171,   172,   174,   173,   175,   179,   176,
     177,   168,   206,     0,   110,   109,   112,   111,     0,     0,
     209,   231,    44,     0,     0,     0,     0,     0,     0,     0,
     124,     0,   142,     0,     0,     0,     0,     0,     0,   213,
     116,   225,    40,    86,     0,     0,   182,   183,   185,   184,
     189,   187,   188,   191,   194,   186,   190,   197,     0,   196,
     195,     0,     0,     0,     0,     0,   135,     0,     0,   178,
       0,     0,   212,   192,   193,   103,   198,   100,    97,     0,
       0,     0,     0,   169,   170,     0,   126,   115,   105,   107,
       0,     0,    98
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -357,  -357,  -357,  -357,  -357,   114,  -357,  -357,    23,  -200,
     -14,   -46,  -169,  -357,  -163,  -357,    -1,   -47,   -45,   -31,
    -357,  -357,  -175,   229,   -15,  -182,  -357,    43,  -357,  -357,
    -357,  -357,   168,  -357,  -357,  -357,  -357,  -357,  -323,   160,
    -356,  -352,    22,   -54,   -48,   -20,   -71,  -220,   202,   162,
      74,   -11,    90,   312,   239,  -357,    29,  -357,   -43,   361,
    -357,   327,   661,  -357,  -357,  -357,  -257,  -311,  -354,   364,
    -357,  -357,  -357,   268,  -357,   190,   398,  -357,  -280,  -357
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   147,   249,   250,   251,   228,     1,   117,   252,   118,
     319,   266,    29,    30,    31,    32,    80,    34,    35,    36,
      50,    52,   124,    81,    82,    83,   196,    84,    85,   425,
      86,   324,    87,    88,   323,   373,   161,   374,   358,   132,
      89,   304,   267,    90,   269,    91,   121,    92,    93,   137,
      94,   333,   207,    95,    96,   208,   272,    37,   101,   177,
      39,    55,    97,    40,   174,   291,   292,   397,   398,    98,
     148,    41,   104,   105,   179,   180,    99,   314,   315,   316
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,   265,    48,   307,   369,    44,   380,     6,   120,   390,
     390,   102,   401,   103,   229,   256,   119,   107,   120,   359,
     230,    73,    73,   173,   340,   183,   134,   343,   344,   345,
     346,   347,   348,   349,   350,    73,   361,    42,   173,   285,
     227,   301,   390,   130,   225,   390,    43,   295,    46,   152,
     131,   390,   390,   421,   422,   209,   274,   102,   229,   103,
     202,    49,   120,   182,   230,   390,   390,   203,   427,   378,
     186,    45,   120,   120,   390,   390,   431,   205,    51,   307,
     191,   192,   420,   188,   206,   210,   120,   416,    53,   188,
     416,   188,   189,   120,   211,    57,   307,   194,   322,   285,
     352,   212,   285,   285,   285,   285,   285,   285,   285,   285,
     416,   416,   263,   159,   160,   108,    54,   301,   409,    58,
     416,   329,   330,    59,    73,   354,   355,   331,   332,   265,
      60,   120,    61,   120,   301,   356,   357,   297,   298,   232,
      45,   253,   329,   426,   277,   278,    62,   268,   109,    63,
     110,   111,   112,   113,   114,    64,    65,   100,   264,   275,
     106,   116,   122,   123,   120,   120,   133,   288,   125,   305,
     126,   136,   279,   280,   139,   140,   141,   142,   143,   144,
     145,   146,   127,   387,   387,   141,   142,   143,   144,   145,
     146,   128,   129,   285,   135,   150,   138,   184,   120,   154,
     151,   120,   155,   306,   265,   120,   320,   170,   173,   321,
     175,   181,   176,   325,   187,   200,   387,   185,   197,   387,
     284,   190,   300,   198,   199,   387,   387,   288,   201,   204,
     288,   288,   288,   288,   288,   288,   288,   288,   213,   387,
     387,   214,   215,   216,   217,   305,   218,   219,   387,   387,
     220,   224,   221,   152,   222,   223,   254,   231,   255,   140,
     259,   257,   305,   258,   286,   260,   302,   108,   271,    48,
     270,   326,   262,   318,   327,   268,   328,   335,   336,   306,
     284,   341,   337,   284,   284,   284,   284,   284,   284,   284,
     284,   338,   339,   342,   351,   353,   306,   309,   300,   379,
     362,   364,   365,   366,   367,   368,   375,   371,   376,   120,
     120,   391,   391,   377,   381,   300,   402,   320,   383,   407,
     404,   288,   405,   408,   286,   412,   410,   286,   286,   286,
     286,   286,   286,   286,   286,   411,   413,   414,   423,   418,
     424,   317,   302,   363,   391,   392,   392,   391,   430,   382,
     268,   370,   403,   391,   391,    48,   419,   195,   261,   302,
     406,   334,    38,   372,   386,   386,    56,   391,   391,   226,
     273,     0,   178,   309,   284,     0,   391,   391,   392,     0,
       0,   392,     0,     0,     0,     0,     0,   392,   392,   287,
     309,   303,     0,     0,     0,     0,     0,   386,     0,     0,
     386,   392,   392,     0,     0,     0,   386,   386,   388,   388,
     392,   392,     0,     0,     0,     0,     0,     0,   286,     0,
     386,   386,     0,   289,     0,   308,     0,     0,     0,   386,
     386,     0,     0,     0,     0,     0,     0,     0,     0,   394,
     394,   388,     0,     0,   388,     0,     0,     0,     0,   287,
     388,   388,   287,   287,   287,   287,   287,   287,   287,   287,
     290,     0,   311,     0,   388,   388,     0,   303,     0,     0,
       0,     0,   394,   388,   388,   394,   108,     0,     0,     0,
       0,   394,   394,   289,   303,    73,   289,   289,   289,   289,
     289,   289,   289,   289,     0,   394,   394,     0,     0,     0,
       0,   308,     0,     0,   394,   394,     0,     0,     0,   109,
       0,   110,   111,   112,   113,   114,     0,     0,   308,   115,
     290,     0,   116,   290,   290,   290,   290,   290,   290,   290,
     290,     0,     0,   389,   389,   310,     0,     0,   311,     0,
       0,     0,     0,   287,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,    73,   311,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   389,   393,   393,   389,
       0,     0,     0,     0,     0,   389,   389,   289,   109,     0,
     110,   111,   112,   113,   114,   293,     0,   312,   264,   389,
     389,   116,     0,     0,     0,     0,     0,     0,   389,   389,
     393,     0,     0,   393,   396,   396,     0,     0,     0,   393,
     393,   310,     0,     0,   290,     0,     0,     0,     0,   294,
       0,   313,     0,   393,   393,     0,     0,     0,   310,     0,
       0,     0,   393,   393,     0,     0,     0,   396,     0,     0,
     396,     0,     0,     0,     0,   293,   396,   396,   293,   293,
     293,   293,   293,   293,   293,   293,     0,     0,     0,     0,
     396,   396,     0,   312,     0,     0,     0,     0,     0,   396,
     396,     0,     0,     0,     0,     0,     0,   395,   395,   294,
     312,     0,   294,   294,   294,   294,   294,   294,   294,   294,
       0,     0,     0,     0,     0,     0,     0,   313,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     0,
     395,     0,     0,   395,   313,     0,     0,     0,     0,   395,
     395,     0,     0,     0,     0,     0,     0,     0,     0,   399,
     399,     0,     0,   395,   395,     0,     0,     0,   149,   293,
       0,   153,   395,   395,   156,   157,     0,     0,   158,     0,
     162,   163,   164,   165,   166,   167,   168,   169,     0,   171,
     172,     0,   399,   400,   400,   399,     0,     2,     0,     0,
       0,   399,   399,   294,     0,     0,     0,     3,     0,     0,
       0,     0,     0,     0,     0,   399,   399,     4,     5,     0,
       6,     0,     0,     0,   399,   399,   400,     0,     0,   400,
       0,     0,     0,     0,     0,   400,   400,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   400,
     400,     0,     0,     0,     0,     0,     0,     0,   400,   400,
       0,     0,     0,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,    66,    67,
       0,     0,    68,     0,     0,     0,    69,     0,     0,     0,
       0,    71,     0,     0,    72,   276,    47,   296,     0,    73,
      74,    75,     0,   233,   234,   235,   236,   237,   238,     0,
       0,     0,     0,     0,     0,     0,     0,   239,   240,   241,
     242,   243,   244,   245,     0,   246,     0,     0,     0,     0,
       0,   297,   298,    76,   299,   360,     0,     0,   247,     0,
       0,   248,     7,    78,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    79,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    66,    67,     0,     0,    68,     0,
       0,     0,    69,     0,     0,     0,     0,    71,     0,     0,
      72,     0,    47,   296,     0,    73,    74,    75,     0,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
       0,     0,     0,   239,   240,   241,   242,   243,   244,   245,
       0,   246,     0,     0,     0,     0,     0,   297,   298,    76,
     299,     0,     0,     0,     0,     0,     0,   248,     7,    78,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      79,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      66,    67,     0,     0,    68,   384,   385,     0,    69,     0,
       0,    70,     0,    71,     0,     0,    72,     0,    47,     0,
       0,    73,    74,    75,     0,     0,     0,     0,     0,     0,
       0,    66,    67,     0,     0,    68,   384,   385,     0,    69,
       0,     0,    70,     0,    71,     0,     0,    72,     0,    47,
       0,     0,    73,    74,    75,    76,     0,   415,     0,     0,
       0,     0,     0,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    76,     0,   417,     0,
       0,     0,     0,     0,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    66,    67,     0,
       0,    68,   384,   385,     0,    69,     0,     0,    70,     0,
      71,     0,     0,    72,     0,    47,     0,     0,    73,    74,
      75,     0,     0,     0,     0,     0,     0,     0,    66,    67,
       0,     0,    68,   384,   385,     0,    69,     0,     0,    70,
       0,    71,     0,     0,    72,     0,    47,     0,     0,    73,
      74,    75,    76,     0,   428,     0,     0,     0,     0,     0,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    76,     0,   429,     0,     0,     0,     0,
       0,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    66,    67,     0,     0,    68,   384,
     385,     0,    69,     0,     0,    70,     0,    71,     0,     0,
      72,     0,    47,     0,     0,    73,    74,    75,     0,     0,
       0,     0,     0,     0,     0,    66,    67,     0,     0,    68,
     384,   385,     0,    69,     0,     0,    70,     0,    71,     0,
       0,    72,     0,    47,     0,     0,    73,    74,    75,    76,
       0,   432,     0,     0,     0,     0,     0,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    66,    67,     0,     0,    68,     0,     0,     0,    69,
       0,     0,    70,     0,    71,     0,     0,    72,     0,    47,
       0,     0,    73,    74,    75,     0,     0,     0,     0,     0,
       0,     0,    66,    67,     0,     0,    68,     0,     0,     0,
       0,     0,     0,     0,     0,    71,     0,     0,     0,     0,
      47,     0,     0,    73,     0,    75,    76,    77,     0,     0,
       0,     0,     0,     0,     0,     7,    78,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    79,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    76,   281,    47,
       0,     6,     0,     0,     0,     0,   282,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,   283,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,     0,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,   193,    47,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28
};

static const yytype_int16 yycheck[] =
{
       1,   201,    33,   223,   327,    23,   358,    23,    62,   365,
     366,    58,   366,    58,   183,   190,    62,    60,    72,   299,
     183,    24,    24,    55,   281,    57,    72,   284,   285,   286,
     287,   288,   289,   290,   291,    24,   316,    58,    55,   221,
      57,   223,   398,    51,    60,   401,    88,   222,    58,    80,
      58,   407,   408,   407,   408,    58,    58,   104,   227,   104,
      51,    58,   116,   106,   227,   421,   422,    58,   420,    58,
     116,    89,   126,   127,   430,   431,   430,    51,    58,   299,
     126,   127,   405,    55,    58,   139,   140,   398,    56,    55,
     401,    55,    64,   147,   140,    57,   316,   128,    64,   281,
      64,   147,   284,   285,   286,   287,   288,   289,   290,   291,
     421,   422,    12,     5,     6,    15,    59,   299,   375,    59,
     431,    55,    56,    58,    24,    73,    74,    55,    56,   329,
      57,   185,    56,   187,   316,    83,    84,    56,    57,   185,
      89,   187,    55,    56,   215,   216,    34,   201,    48,    55,
      50,    51,    52,    53,    54,    63,    55,    58,    58,   213,
      57,    61,    58,    50,   218,   219,    61,   221,    58,   223,
      63,    33,   218,   219,    33,    34,    35,    36,    37,    38,
      39,    40,    63,   365,   366,    35,    36,    37,    38,    39,
      40,    63,    58,   375,    58,    58,    57,    33,   252,    56,
      58,   255,    56,   223,   404,   259,   252,    60,    55,   255,
      58,    56,    58,   259,    34,    56,   398,    61,    57,   401,
     221,    63,   223,    57,    54,   407,   408,   281,    57,    57,
     284,   285,   286,   287,   288,   289,   290,   291,    33,   421,
     422,    60,    34,    34,    56,   299,    63,    63,   430,   431,
      58,    56,    59,   284,    63,    59,    50,    17,    34,    34,
      56,    64,   316,    64,   221,    50,   223,    15,    65,   300,
      58,    57,    62,    62,    57,   329,    56,    56,    56,   299,
     281,    58,    56,   284,   285,   286,   287,   288,   289,   290,
     291,    64,    64,    58,    60,    33,   316,   223,   299,   353,
      62,    34,    59,    59,    56,    50,    60,    58,    34,   363,
     364,   365,   366,    34,    60,   316,    58,   363,   364,    59,
      57,   375,    57,    59,   281,    56,    13,   284,   285,   286,
     287,   288,   289,   290,   291,    13,    56,    56,    56,    64,
      56,   227,   299,   320,   398,   365,   366,   401,    59,   363,
     404,   329,   367,   407,   408,   386,   404,   128,   198,   316,
     371,   271,     1,   334,   365,   366,    39,   421,   422,   179,
     208,    -1,   104,   299,   375,    -1,   430,   431,   398,    -1,
      -1,   401,    -1,    -1,    -1,    -1,    -1,   407,   408,   221,
     316,   223,    -1,    -1,    -1,    -1,    -1,   398,    -1,    -1,
     401,   421,   422,    -1,    -1,    -1,   407,   408,   365,   366,
     430,   431,    -1,    -1,    -1,    -1,    -1,    -1,   375,    -1,
     421,   422,    -1,   221,    -1,   223,    -1,    -1,    -1,   430,
     431,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   365,
     366,   398,    -1,    -1,   401,    -1,    -1,    -1,    -1,   281,
     407,   408,   284,   285,   286,   287,   288,   289,   290,   291,
     221,    -1,   223,    -1,   421,   422,    -1,   299,    -1,    -1,
      -1,    -1,   398,   430,   431,   401,    15,    -1,    -1,    -1,
      -1,   407,   408,   281,   316,    24,   284,   285,   286,   287,
     288,   289,   290,   291,    -1,   421,   422,    -1,    -1,    -1,
      -1,   299,    -1,    -1,   430,   431,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    -1,    -1,   316,    58,
     281,    -1,    61,   284,   285,   286,   287,   288,   289,   290,
     291,    -1,    -1,   365,   366,   223,    -1,    -1,   299,    -1,
      -1,    -1,    -1,   375,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,   316,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   398,   365,   366,   401,
      -1,    -1,    -1,    -1,    -1,   407,   408,   375,    48,    -1,
      50,    51,    52,    53,    54,   221,    -1,   223,    58,   421,
     422,    61,    -1,    -1,    -1,    -1,    -1,    -1,   430,   431,
     398,    -1,    -1,   401,   365,   366,    -1,    -1,    -1,   407,
     408,   299,    -1,    -1,   375,    -1,    -1,    -1,    -1,   221,
      -1,   223,    -1,   421,   422,    -1,    -1,    -1,   316,    -1,
      -1,    -1,   430,   431,    -1,    -1,    -1,   398,    -1,    -1,
     401,    -1,    -1,    -1,    -1,   281,   407,   408,   284,   285,
     286,   287,   288,   289,   290,   291,    -1,    -1,    -1,    -1,
     421,   422,    -1,   299,    -1,    -1,    -1,    -1,    -1,   430,
     431,    -1,    -1,    -1,    -1,    -1,    -1,   365,   366,   281,
     316,    -1,   284,   285,   286,   287,   288,   289,   290,   291,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   299,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     398,    -1,    -1,   401,   316,    -1,    -1,    -1,    -1,   407,
     408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   365,
     366,    -1,    -1,   421,   422,    -1,    -1,    -1,    77,   375,
      -1,    80,   430,   431,    83,    84,    -1,    -1,    87,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    98,
      99,    -1,   398,   365,   366,   401,    -1,     0,    -1,    -1,
      -1,   407,   408,   375,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   421,   422,    20,    21,    -1,
      23,    -1,    -1,    -1,   430,   431,   398,    -1,    -1,   401,
      -1,    -1,    -1,    -1,    -1,   407,   408,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,
     422,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   430,   431,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    -1,     3,     4,
      -1,    -1,     7,    -1,    -1,    -1,    11,    -1,    -1,    -1,
      -1,    16,    -1,    -1,    19,   214,    21,    22,    -1,    24,
      25,    26,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    60,    -1,    -1,    62,    -1,
      -1,    65,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     3,     4,    -1,    -1,     7,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    -1,    16,    -1,    -1,
      19,    -1,    21,    22,    -1,    24,    25,    26,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    65,    67,    68,
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
      82,    83,    84,    85,    86,    87,    88,     3,     4,    -1,
      -1,     7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,
      16,    -1,    -1,    19,    -1,    21,    -1,    -1,    24,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,     7,     8,     9,    -1,    11,    -1,    -1,    14,
      -1,    16,    -1,    -1,    19,    -1,    21,    -1,    -1,    24,
      25,    26,    58,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    58,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     3,     4,    -1,    -1,     7,     8,
       9,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,    -1,
      19,    -1,    21,    -1,    -1,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,     7,
       8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,
      -1,    19,    -1,    21,    -1,    -1,    24,    25,    26,    58,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     3,     4,    -1,    -1,     7,    -1,    -1,    -1,    11,
      -1,    -1,    14,    -1,    16,    -1,    -1,    19,    -1,    21,
      -1,    -1,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    -1,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,
      21,    -1,    -1,    24,    -1,    26,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    58,    59,    21,
      -1,    23,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    -1,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    58,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    96,     0,    10,    20,    21,    23,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   102,
     103,   104,   105,   106,   107,   108,   109,   147,   149,   150,
     153,   161,    58,    88,    23,    89,    58,    21,   109,    58,
     110,    58,   111,    56,    59,   151,   151,    57,    59,    58,
      57,    56,    34,    55,    63,    55,     3,     4,     7,    11,
      14,    16,    19,    24,    25,    26,    58,    59,    68,    79,
     106,   113,   114,   115,   117,   118,   120,   122,   123,   130,
     133,   135,   137,   138,   140,   143,   144,   152,   159,   166,
      58,   148,   107,   108,   162,   163,    57,   148,    15,    48,
      50,    51,    52,    53,    54,    58,    61,    97,    99,   101,
     133,   136,    58,    50,   112,    58,    63,    63,    63,    58,
      51,    58,   129,    61,   101,    58,    33,   139,    57,    33,
      34,    35,    36,    37,    38,    39,    40,    91,   160,   152,
      58,    58,   109,   152,    56,    56,   152,   152,   152,     5,
       6,   126,   152,   152,   152,   152,   152,   152,   152,   152,
      60,   152,   152,    55,   154,    58,    58,   149,   163,   164,
     165,    56,   148,    57,    33,    61,   101,    34,    55,    64,
      63,   101,   101,    58,   109,   113,   116,    57,    57,    54,
      56,    57,    51,    58,    57,    51,    58,   142,   145,    58,
     133,   101,   101,    33,    60,    34,    34,    56,    63,    63,
      58,    59,    63,    59,    56,    60,   165,    57,    95,   102,
     104,    17,   101,    27,    28,    29,    30,    31,    32,    41,
      42,    43,    44,    45,    46,    47,    49,    62,    65,    92,
      93,    94,    98,   101,    50,    34,   112,    64,    64,    56,
      50,   129,    62,    12,    58,    99,   101,   132,   133,   134,
      58,    65,   146,   139,    58,   133,   152,   136,   136,   101,
     101,    59,    67,    78,   106,   115,   117,   122,   133,   138,
     144,   155,   156,   159,   166,   112,    22,    56,    57,    59,
     106,   115,   117,   122,   131,   133,   135,   137,   138,   140,
     143,   144,   159,   166,   167,   168,   169,    95,    62,   100,
     101,   101,    64,   124,   121,   101,    57,    57,    56,    55,
      56,    55,    56,   141,   142,    56,    56,    56,    64,    64,
     156,    58,    58,   156,   156,   156,   156,   156,   156,   156,
     156,    60,    64,    33,    73,    74,    83,    84,   128,   168,
      60,   168,    62,    98,    34,    59,    59,    56,    50,   128,
     132,    58,   146,   125,   127,    60,    34,    34,    58,   133,
     131,    60,   100,   101,     8,     9,   106,   115,   117,   122,
     130,   133,   135,   138,   140,   143,   144,   157,   158,   159,
     166,   158,    58,   114,    57,    57,   141,    59,    59,   156,
      13,    13,    56,    56,    56,    60,   157,    60,    64,   134,
     128,   158,   158,    56,    56,   119,    56,   131,    60,    60,
      59,   158,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    91,    91,    91,    91,    91,    92,    92,
      92,    92,    92,    92,    93,    93,    93,    93,    93,    93,
      94,    94,    95,    95,    96,    96,    96,    96,    96,    97,
      97,    98,    98,    98,    98,    99,    99,    99,    99,    99,
     100,   100,   101,   101,   101,   101,   101,   101,   102,   102,
     102,   102,   102,   102,   103,   103,   103,   103,   103,   104,
     104,   104,   104,   104,   105,   105,   105,   105,   105,   106,
     106,   107,   107,   107,   107,   108,   108,   109,   109,   110,
     110,   110,   110,   111,   111,   111,   111,   112,   112,   113,
     114,   115,   115,   116,   116,   117,   117,   119,   118,   121,
     120,   122,   124,   123,   125,   123,   127,   126,   126,   128,
     128,   128,   128,   129,   129,   130,   131,   131,   132,   132,
     132,   132,   133,   134,   134,   134,   135,   136,   137,   137,
     138,   139,   139,   139,   140,   141,   141,   142,   142,   143,
     144,   145,   146,   146,   147,   147,   148,   148,   149,   150,
     151,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   154,   153,   155,
     155,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   158,   158,   159,
     160,   160,   161,   162,   162,   163,   163,   164,   164,   165,
     166,   166,   167,   167,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     169,   169
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     5,     3,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     1,     1,     1,     2,     1,     1,     2,     2,     1,
       3,     3,     5,     4,     6,     6,     8,     3,     1,     3,
       3,     2,     2,     1,     1,     1,     1,     0,    12,     0,
       8,     2,     0,     8,     0,     9,     0,     8,     0,     1,
       1,     1,     1,     1,     1,     9,     3,     1,     1,     1,
       1,     1,     5,     1,     3,     1,     9,     3,     5,     5,
       5,     2,     2,     0,     5,     3,     1,     1,     1,     3,
       5,     2,     3,     0,     2,     2,     1,     3,     6,     7,
       3,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     4,     2,     2,     2,     0,     0,     8,     5,
       5,     2,     2,     2,     2,     2,     2,     2,     4,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     2,     2,
       2,     3,     6,     2,     3,     2,     5,     1,     2,     4,
       3,     4,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     2
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
  case 69:
#line 108 "bison.y"
                                        { fprintf(yyout, " : declaration statement"); }
#line 1955 "bison.tab.c"
    break;

  case 70:
#line 109 "bison.y"
                                                        { fprintf(yyout, " : declaration statement"); }
#line 1961 "bison.tab.c"
    break;

  case 91:
#line 144 "bison.y"
                                    { fprintf(yyout, " : assignment statement");  }
#line 1967 "bison.tab.c"
    break;

  case 92:
#line 145 "bison.y"
                                     { fprintf(yyout, " : expression statement");  }
#line 1973 "bison.tab.c"
    break;

  case 97:
#line 156 "bison.y"
                                                                                                   {fprintf(yyout, " : loop statement");}
#line 1979 "bison.tab.c"
    break;

  case 99:
#line 159 "bison.y"
                                               {fprintf(yyout, " : loop statement");}
#line 1985 "bison.tab.c"
    break;

  case 102:
#line 167 "bison.y"
                                                { fprintf(yyout, " : conditional statement");  }
#line 1991 "bison.tab.c"
    break;

  case 104:
#line 168 "bison.y"
                                                                    { fprintf(yyout, " : conditional statement");  }
#line 1997 "bison.tab.c"
    break;

  case 106:
#line 172 "bison.y"
                                                 { fprintf(yyout, " : conditional statement");  }
#line 2003 "bison.tab.c"
    break;

  case 117:
#line 183 "bison.y"
                                                                          { fprintf(yyout, " : analyze statement");  }
#line 2009 "bison.tab.c"
    break;

  case 122:
#line 194 "bison.y"
                                                         { fprintf(yyout, " : call statement");  }
#line 2015 "bison.tab.c"
    break;

  case 126:
#line 204 "bison.y"
                                                                                                           { fprintf(yyout, " : call statement");  }
#line 2021 "bison.tab.c"
    break;

  case 128:
#line 209 "bison.y"
                                                       { fprintf(yyout, " : get statement");  }
#line 2027 "bison.tab.c"
    break;

  case 129:
#line 210 "bison.y"
                                                        { fprintf(yyout, " : get statement");  }
#line 2033 "bison.tab.c"
    break;

  case 130:
#line 215 "bison.y"
                                                          { fprintf(yyout, " : sleep statement");  }
#line 2039 "bison.tab.c"
    break;

  case 136:
#line 230 "bison.y"
     { 
      fprintf(yyout, " : scan statement");
     }
#line 2047 "bison.tab.c"
    break;

  case 139:
#line 240 "bison.y"
                                        { fprintf(yyout, " : return statement"); }
#line 2053 "bison.tab.c"
    break;

  case 140:
#line 244 "bison.y"
       { 
        fprintf(yyout, " : print statement");
       }
#line 2061 "bison.tab.c"
    break;

  case 148:
#line 261 "bison.y"
                                                                            { fprintf(yyout, " : function declaration statement"); }
#line 2067 "bison.tab.c"
    break;

  case 149:
#line 262 "bison.y"
                                                                                      { fprintf(yyout, " : function declaration statement"); }
#line 2073 "bison.tab.c"
    break;

  case 167:
#line 285 "bison.y"
                                      { fprintf(yyout, " : task declaration statement"); }
#line 2079 "bison.tab.c"
    break;


#line 2083 "bison.tab.c"

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
#line 383 "bison.y"


void yyerror(std::string s){
  std::cout << "Syntax Error: " << s << " at line number - " << yylineno << std::endl;
}
