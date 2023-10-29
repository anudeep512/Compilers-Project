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
#define YYLAST   1697

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  233
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  435

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
     141,   149,   150,   153,   153,   156,   156,   159,   159,   164,
     167,   167,   168,   168,   172,   172,   173,   176,   176,   176,
     176,   179,   179,   181,   183,   183,   188,   189,   190,   191,
     194,   197,   198,   199,   204,   207,   209,   210,   215,   219,
     220,   221,   224,   228,   229,   235,   236,   240,   243,   249,
     252,   253,   258,   258,   260,   260,   261,   262,   264,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   275,
     276,   277,   278,   279,   280,   281,   286,   286,   289,   290,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   326,   327,
     331,   332,   333,   337,   340,   341,   344,   345,   348,   349,
     352,   355,   356,   360,   361,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   383,   384
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
  "assignment_statement", "expression_statement", "both_assignment",
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

#define YYPACT_NINF (-359)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -359,   911,  -359,    -8,   -35,   -12,    -2,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  1609,    23,    44,    40,  -359,    52,    52,
    -359,  -359,    57,    65,    72,  -359,    79,    61,    90,   126,
     109,   107,   117,  -359,  1539,  -359,  -359,   120,  1609,   122,
     120,  -359,   183,   125,   130,   128,   124,   131,   132,   142,
      50,   127,   183,   143,   156,   145,   358,  1539,   146,   152,
    1539,  1539,  1539,  1539,  -359,  -359,  1539,   116,  1539,  1539,
    1539,  1539,  1539,  1539,  1539,  1539,   153,  1539,  1539,  -359,
     157,   158,   159,   872,   165,   120,    13,   199,   178,  -359,
    -359,  -359,  -359,  -359,  -359,   183,  -359,  -359,  -359,  -359,
    -359,   206,  -359,   -10,   180,   183,   183,   981,   189,  -359,
    -359,   190,   194,   193,   196,    59,   197,    62,    25,   183,
    -359,  -359,  -359,  -359,  -359,  -359,   183,   222,   198,   226,
     227,   207,  -359,  -359,  -359,  -359,  -359,   201,   208,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,   204,   209,  -359,   210,   211,   216,    24,  -359,  -359,
      42,   489,   259,   183,   637,   183,   229,   243,   130,   228,
     231,   246,  -359,  -359,   234,   241,    50,   247,  -359,   123,
    -359,  -359,   235,  -359,  -359,   248,   156,  -359,  -359,  -359,
    -359,    33,  1539,   281,   281,  -359,   183,   183,  -359,  1570,
     130,  1102,  -359,  -359,  -359,   489,  -359,  -359,  -359,  -359,
     250,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
     183,  -359,  -359,   183,     3,  -359,  -359,   183,   251,   257,
     262,  -359,  -359,  -359,  -359,  -359,  -359,    88,    97,    62,
    -359,   273,  -359,  -359,  -359,   274,   275,   255,   268,  1570,
     277,   279,  1570,  1570,  1570,  1570,  1570,  1570,  1570,  1570,
    1570,   278,  -359,  -359,    39,   300,  -359,    32,  1102,  1609,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  1016,  -359,  -359,   280,
     782,  -359,   305,   282,   286,   291,   298,    32,  -359,   329,
    -359,   293,  -359,  -359,   248,  -359,  -359,  -359,  -359,  -359,
     292,   322,   323,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,    35,  -359,  -359,  -359,  -359,    98,
     299,  -359,  -359,  -359,   183,   183,  1453,  1453,   302,   301,
     304,  -359,    97,  -359,   303,   308,  1570,   355,   356,   314,
    -359,  -359,  -359,  -359,  -359,   315,   318,  1609,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    1188,  -359,  -359,  1219,   263,   312,   123,    32,  -359,  1453,
    1453,  -359,   328,   333,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,   111,    98,  1305,  1336,  -359,  -359,   319,  -359,  -359,
    -359,  -359,  1453,  1422,  -359
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
      77,     0,    78,    69,   165,   142,   143,     0,     0,     0,
       0,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,     0,     0,   165,     0,     0,
     165,   165,   165,   165,    93,    94,   165,   106,   165,   165,
     165,   165,   165,   165,   165,   165,     0,   165,   165,   144,
     166,     0,     0,     0,     0,     0,     0,     0,     0,    35,
      39,    36,    38,    37,    29,     0,    43,    42,    81,    30,
      47,    80,    88,     0,     0,     0,     0,     0,     0,   111,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     7,     4,     3,     2,     5,     0,   200,     0,     0,
       0,     0,   149,   150,   151,   154,   156,     0,     0,    99,
     157,   153,   152,   162,   160,   158,   155,   159,   148,   164,
     163,     0,     0,   206,     0,     0,     0,     0,   208,   204,
       0,     0,     0,     0,     0,     0,     0,    83,     0,     0,
       0,     0,    92,    91,     0,     0,     0,     0,   137,     0,
     129,   130,     0,   135,   136,   141,   131,   201,   211,    89,
      90,     0,   165,     0,     0,    69,     0,     0,   145,     0,
       0,     0,   205,   203,   209,     0,   146,    23,    22,   125,
       0,    17,    14,    15,    16,    19,    18,    20,    21,     9,
       8,    10,    11,    12,    13,    45,    34,    32,    31,    33,
       0,    82,    87,     0,     0,   100,    97,     0,     0,     0,
       0,   123,    29,    42,   119,   121,    30,     0,     0,     0,
     139,     0,   202,   212,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   180,     0,     0,   115,     0,     0,   215,
     216,   217,   220,   222,   223,   219,   218,   228,   226,   224,
     221,   225,   231,   230,   229,   232,     0,   147,    46,     0,
      41,    85,    84,     0,     0,     0,     0,     0,   128,     0,
     120,     0,   134,   132,   141,   138,   126,   127,   102,   104,
       0,     0,     0,   170,   171,   172,   174,   173,   175,   179,
     176,   177,   167,   207,     0,   108,   107,   110,   109,     0,
       0,   210,   233,    44,     0,     0,     0,     0,     0,     0,
       0,   122,     0,   140,     0,     0,     0,     0,     0,     0,
     214,   114,   227,    40,    86,     0,     0,   182,   183,   184,
     186,   185,   190,   188,   189,   192,   195,   187,   191,   198,
       0,   197,   196,     0,     0,     0,     0,     0,   133,     0,
       0,   178,     0,     0,   213,   193,   194,   101,   199,    98,
      95,     0,     0,     0,     0,   168,   169,     0,   124,   113,
     103,   105,     0,     0,    96
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -359,  -359,  -359,  -359,  -359,   160,  -359,  -359,    80,  -195,
      37,   -54,  -161,  -359,  -135,  -359,    -1,   -41,   -15,   -32,
    -359,  -359,  -147,    38,   167,  -359,   205,  -359,  -359,  -359,
    -359,   334,  -359,  -359,  -359,  -359,  -359,  -320,   214,  -291,
    -353,    74,   -60,     0,  -218,   -45,  -216,   373,   212,  -158,
      41,   138,   113,   432,  -359,    78,  -359,   -16,   414,  -359,
     377,   -67,  -359,  -359,  -359,  -250,  -296,  -358,   505,  -359,
    -359,  -359,   316,  -359,   240,   601,  -359,  -256,  -359
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   146,   247,   248,   249,   226,     1,   116,   250,   117,
     319,   264,    29,    30,    31,    32,    80,    34,    35,    36,
      50,    52,   123,    81,    82,   194,    83,    84,   427,    85,
     324,    86,    87,   323,   374,   159,   375,   359,   131,    88,
     304,   265,    89,   267,    90,   120,    91,    92,   136,    93,
     333,   205,    94,    95,   206,   270,    37,   100,   175,    39,
      55,    96,    40,   172,   290,   291,   399,   400,    97,   147,
      41,   103,   104,   177,   178,    98,   314,   315,   316
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,    48,   119,   306,   263,   307,   381,   370,   118,   403,
     148,    44,   119,   152,   153,   154,   155,   101,   133,   156,
     227,   160,   161,   162,   163,   164,   165,   166,   167,   340,
     169,   170,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   254,   360,   102,   106,   186,   228,     6,   151,    73,
      42,   423,   424,    43,   187,   119,    46,    73,   186,    73,
     362,   184,   101,   309,   227,   119,   119,   322,   171,   429,
     181,   189,   190,   294,   433,   392,   392,    45,   208,   119,
     306,    49,   307,   207,   223,   209,   119,   422,   102,   180,
     228,   272,   210,   379,   186,   192,    53,   171,   306,   225,
     307,   129,    51,   353,   418,   355,   356,   418,   130,   392,
     200,    54,   392,   203,    57,   357,   358,   201,   392,   392,
     204,   157,   158,   119,    58,   119,   411,   418,   418,   230,
      59,   251,   392,   392,   263,   261,    60,   418,   107,   266,
     309,   392,   392,   329,   330,   274,    61,    73,   394,   394,
      45,   273,   331,   332,   296,   297,   119,   119,   309,   287,
      62,   305,   277,   278,    63,   193,   329,   428,   275,   276,
      64,   108,    65,   109,   110,   111,   112,   113,    99,   105,
     122,   262,   394,   121,   115,   394,   124,   125,   132,   135,
     119,   394,   394,   119,   126,   127,   320,   119,   107,   321,
     128,   134,   137,   325,   149,   394,   394,    73,   396,   396,
     150,   263,   171,   168,   394,   394,   173,   174,   282,   287,
     299,   179,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   108,   182,   109,   110,   111,   112,   113,   305,   183,
     185,   114,   396,   188,   115,   396,   195,   196,   197,   198,
     151,   396,   396,   199,   202,   211,   305,   283,   212,   300,
     213,   214,   218,   215,   216,   396,   396,    48,   219,   266,
     221,   217,   222,   220,   396,   396,   229,   253,   282,   252,
     139,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     257,   258,   255,   268,   380,   256,   107,   299,   140,   141,
     142,   143,   144,   145,   119,   119,   393,   393,   326,   260,
     320,   384,   318,   269,   327,   299,   287,   283,   328,   338,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   335,
     336,   337,   339,   354,   310,   341,   300,   342,   352,   365,
     393,   366,   363,   393,   107,   367,   266,   368,   369,   393,
     393,   372,   376,    73,   300,    48,   377,   378,   406,   382,
     404,   407,   409,   393,   393,   387,   387,   410,   412,   413,
     414,   415,   393,   393,   416,   282,   420,   108,   432,   109,
     110,   111,   112,   113,   425,   317,   284,   262,   301,   426,
     115,   138,   139,   140,   141,   142,   143,   144,   145,   387,
     364,   383,   387,   371,   388,   388,   421,   334,   387,   387,
     259,   310,   373,   408,   283,    38,    56,   224,   271,   176,
       0,     0,   387,   387,   285,     0,   302,     0,     0,   310,
       0,   387,   387,     0,     0,     0,     0,     0,   388,     0,
       0,   388,     0,     0,     0,     0,   284,   388,   388,   284,
     284,   284,   284,   284,   284,   284,   284,   284,     0,     0,
       0,   388,   388,     0,     0,   301,     0,     0,     0,     0,
     388,   388,     0,     0,     0,     0,     0,     0,     0,   397,
     397,     0,     0,   301,   285,     0,     0,   285,   285,   285,
     285,   285,   285,   285,   285,   285,     0,     0,     0,     0,
       0,     0,     0,   302,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   397,     0,     0,   397,     0,     0,     0,
       0,   302,   397,   397,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   389,   389,   405,   397,   397,     0,     0,
       0,     0,     0,   284,     0,   397,   397,     0,     0,     0,
       0,     0,     0,   286,     0,   303,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,   389,     0,     0,
     389,   390,   390,     0,     0,     0,   389,   389,     0,     0,
       0,   285,     0,     0,     0,     0,     0,     0,     0,     0,
     389,   389,   288,     0,   308,     0,     0,     0,     0,   389,
     389,     0,     0,     0,     0,   390,     0,     0,   390,     0,
       0,     0,     0,   286,   390,   390,   286,   286,   286,   286,
     286,   286,   286,   286,   286,     0,     0,     0,   390,   390,
       0,     0,   303,     0,     0,     0,     0,   390,   390,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     303,   289,   288,   311,     0,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   231,   232,   233,   234,   235,   236,
       0,   308,     0,     0,     0,     0,     0,     0,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,     0,   308,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   245,
     391,   391,   246,     0,     0,     0,     0,     0,     0,     0,
     286,   289,     0,     0,   289,   289,   289,   289,   289,   289,
     289,   289,   289,     0,   292,     0,   312,     0,     0,     0,
     311,     0,     0,     0,   391,     0,     0,   391,     0,   395,
     395,     0,     0,   391,   391,     0,     0,     0,   311,   288,
       0,     0,     0,     0,     0,     0,     0,   391,   391,     0,
       0,     0,     0,     0,     0,     0,   391,   391,     0,     0,
       0,     0,     0,   395,     0,     0,   395,     0,     0,     0,
       0,     0,   395,   395,   292,     0,     0,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   395,   395,   398,   398,
       0,     0,     0,   312,     0,   395,   395,     0,   289,   231,
     232,   233,   234,   235,   236,     0,     0,     0,     0,     0,
     293,   312,   313,   237,   238,   239,   240,   241,   242,   243,
       0,   244,   398,     0,     0,   398,     0,     0,     0,     0,
       0,   398,   398,     0,     0,     0,     0,   246,     0,     0,
       0,     0,     0,     0,     0,   398,   398,     0,     0,     0,
       0,     0,     0,     0,   398,   398,     0,     0,     0,     0,
       0,   401,   401,     0,     0,     0,     0,     0,     0,     0,
     293,   292,     0,   293,   293,   293,   293,   293,   293,   293,
     293,   293,     0,    47,     0,     6,     0,     0,     0,   313,
       0,     0,     0,     0,     0,   401,     0,     0,   401,     0,
       0,     2,     0,     0,   401,   401,     0,   313,     0,     0,
       0,     3,     0,     0,     0,     0,     0,     0,   401,   401,
       0,     4,     5,     0,     6,     0,     0,   401,   401,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,     0,     0,     0,   402,   402,     0,
       0,     0,     0,     0,     0,     0,     0,   293,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       0,   402,    47,     0,   402,     0,     0,     0,     0,     0,
     402,   402,     0,     0,     0,     0,     0,     0,     0,    66,
      67,     0,     0,    68,   402,   402,     0,    69,     0,     0,
       0,     0,    71,   402,   402,    72,     0,    47,   295,   191,
      73,    74,    75,     0,     0,     0,     0,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       0,     0,   296,   297,    76,   298,   361,     0,     0,     0,
       0,     0,     0,     7,    78,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    79,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    66,    67,     0,     0,    68,
       0,     0,     0,    69,     0,     0,     0,     0,    71,     0,
       0,    72,     0,    47,   295,     0,    73,    74,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   296,   297,
      76,   298,     0,     0,     0,     0,     0,     0,     0,     7,
      78,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    79,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    66,    67,     0,     0,    68,   385,   386,     0,    69,
       0,     0,    70,     0,    71,     0,     0,    72,     0,    47,
       0,     0,    73,    74,    75,     0,     0,     0,     0,     0,
       0,     0,    66,    67,     0,     0,    68,   385,   386,     0,
      69,     0,     0,    70,     0,    71,     0,     0,    72,     0,
      47,     0,     0,    73,    74,    75,    76,     0,   417,     0,
       0,     0,     0,     0,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    76,     0,   419,
       0,     0,     0,     0,     0,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    66,    67,
       0,     0,    68,   385,   386,     0,    69,     0,     0,    70,
       0,    71,     0,     0,    72,     0,    47,     0,     0,    73,
      74,    75,     0,     0,     0,     0,     0,     0,     0,    66,
      67,     0,     0,    68,   385,   386,     0,    69,     0,     0,
      70,     0,    71,     0,     0,    72,     0,    47,     0,     0,
      73,    74,    75,    76,     0,   430,     0,     0,     0,     0,
       0,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    76,     0,   431,     0,     0,     0,
       0,     0,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    66,    67,     0,     0,    68,
     385,   386,     0,    69,     0,     0,    70,     0,    71,     0,
       0,    72,     0,    47,     0,     0,    73,    74,    75,     0,
       0,     0,     0,     0,     0,     0,    66,    67,     0,     0,
      68,   385,   386,     0,    69,     0,     0,    70,     0,    71,
       0,     0,    72,     0,    47,     0,     0,    73,    74,    75,
      76,     0,   434,     0,     0,     0,     0,     0,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    66,    67,     0,     0,    68,     0,     0,     0,
      69,     0,     0,    70,     0,    71,     0,     0,    72,     0,
      47,     0,     0,    73,    74,    75,     0,     0,     0,     0,
       0,     0,     0,    66,    67,     0,     0,    68,     0,     0,
       0,     0,     0,     0,     0,     0,    71,     0,     0,     0,
       0,    47,     0,     0,    73,     0,    75,    76,    77,     0,
       0,     0,     0,     0,     0,     0,     7,    78,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    79,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    76,   279,
      47,     0,     0,     0,     0,     0,     0,   280,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,   281,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28
};

static const yytype_int16 yycheck[] =
{
       1,    33,    62,   221,   199,   221,   359,   327,    62,   367,
      77,    23,    72,    80,    81,    82,    83,    58,    72,    86,
     181,    88,    89,    90,    91,    92,    93,    94,    95,   279,
      97,    98,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   188,   298,    58,    60,    55,   181,    23,    80,    24,
      58,   409,   410,    88,    64,   115,    58,    24,    55,    24,
     316,   115,   103,   221,   225,   125,   126,    64,    55,   422,
      57,   125,   126,   220,   432,   366,   367,    89,   138,   139,
     298,    58,   298,    58,    60,   139,   146,   407,   103,   105,
     225,    58,   146,    58,    55,   127,    56,    55,   316,    57,
     316,    51,    58,    64,   400,    73,    74,   403,    58,   400,
      51,    59,   403,    51,    57,    83,    84,    58,   409,   410,
      58,     5,     6,   183,    59,   185,   376,   423,   424,   183,
      58,   185,   423,   424,   329,    12,    57,   433,    15,   199,
     298,   432,   433,    55,    56,   212,    56,    24,   366,   367,
      89,   211,    55,    56,    56,    57,   216,   217,   316,   219,
      34,   221,   216,   217,    55,   127,    55,    56,   213,   214,
      63,    48,    55,    50,    51,    52,    53,    54,    58,    57,
      50,    58,   400,    58,    61,   403,    58,    63,    61,    33,
     250,   409,   410,   253,    63,    63,   250,   257,    15,   253,
      58,    58,    57,   257,    58,   423,   424,    24,   366,   367,
      58,   406,    55,    60,   432,   433,    58,    58,   219,   279,
     221,    56,   282,   283,   284,   285,   286,   287,   288,   289,
     290,    48,    33,    50,    51,    52,    53,    54,   298,    61,
      34,    58,   400,    63,    61,   403,    57,    57,    54,    56,
     282,   409,   410,    57,    57,    33,   316,   219,    60,   221,
      34,    34,    58,    56,    63,   423,   424,   299,    59,   329,
      59,    63,    56,    63,   432,   433,    17,    34,   279,    50,
      34,   282,   283,   284,   285,   286,   287,   288,   289,   290,
      56,    50,    64,    58,   354,    64,    15,   298,    35,    36,
      37,    38,    39,    40,   364,   365,   366,   367,    57,    62,
     364,   365,    62,    65,    57,   316,   376,   279,    56,    64,
     282,   283,   284,   285,   286,   287,   288,   289,   290,    56,
      56,    56,    64,    33,   221,    58,   298,    58,    60,    34,
     400,    59,    62,   403,    15,    59,   406,    56,    50,   409,
     410,    58,    60,    24,   316,   387,    34,    34,    57,    60,
      58,    57,    59,   423,   424,   366,   367,    59,    13,    13,
      56,    56,   432,   433,    56,   376,    64,    48,    59,    50,
      51,    52,    53,    54,    56,   225,   219,    58,   221,    56,
      61,    33,    34,    35,    36,    37,    38,    39,    40,   400,
     320,   364,   403,   329,   366,   367,   406,   269,   409,   410,
     196,   298,   334,   372,   376,     1,    39,   177,   206,   103,
      -1,    -1,   423,   424,   219,    -1,   221,    -1,    -1,   316,
      -1,   432,   433,    -1,    -1,    -1,    -1,    -1,   400,    -1,
      -1,   403,    -1,    -1,    -1,    -1,   279,   409,   410,   282,
     283,   284,   285,   286,   287,   288,   289,   290,    -1,    -1,
      -1,   423,   424,    -1,    -1,   298,    -1,    -1,    -1,    -1,
     432,   433,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   366,
     367,    -1,    -1,   316,   279,    -1,    -1,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   298,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   400,    -1,    -1,   403,    -1,    -1,    -1,
      -1,   316,   409,   410,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   366,   367,   368,   423,   424,    -1,    -1,
      -1,    -1,    -1,   376,    -1,   432,   433,    -1,    -1,    -1,
      -1,    -1,    -1,   219,    -1,   221,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,   400,    -1,    -1,
     403,   366,   367,    -1,    -1,    -1,   409,   410,    -1,    -1,
      -1,   376,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     423,   424,   219,    -1,   221,    -1,    -1,    -1,    -1,   432,
     433,    -1,    -1,    -1,    -1,   400,    -1,    -1,   403,    -1,
      -1,    -1,    -1,   279,   409,   410,   282,   283,   284,   285,
     286,   287,   288,   289,   290,    -1,    -1,    -1,   423,   424,
      -1,    -1,   298,    -1,    -1,    -1,    -1,   432,   433,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     316,   219,   279,   221,    -1,   282,   283,   284,   285,   286,
     287,   288,   289,   290,    27,    28,    29,    30,    31,    32,
      -1,   298,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,    -1,   316,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
     366,   367,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     376,   279,    -1,    -1,   282,   283,   284,   285,   286,   287,
     288,   289,   290,    -1,   219,    -1,   221,    -1,    -1,    -1,
     298,    -1,    -1,    -1,   400,    -1,    -1,   403,    -1,   366,
     367,    -1,    -1,   409,   410,    -1,    -1,    -1,   316,   376,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   423,   424,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   432,   433,    -1,    -1,
      -1,    -1,    -1,   400,    -1,    -1,   403,    -1,    -1,    -1,
      -1,    -1,   409,   410,   279,    -1,    -1,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   423,   424,   366,   367,
      -1,    -1,    -1,   298,    -1,   432,   433,    -1,   376,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
     219,   316,   221,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,   400,    -1,    -1,   403,    -1,    -1,    -1,    -1,
      -1,   409,   410,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   423,   424,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   432,   433,    -1,    -1,    -1,    -1,
      -1,   366,   367,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     279,   376,    -1,   282,   283,   284,   285,   286,   287,   288,
     289,   290,    -1,    21,    -1,    23,    -1,    -1,    -1,   298,
      -1,    -1,    -1,    -1,    -1,   400,    -1,    -1,   403,    -1,
      -1,     0,    -1,    -1,   409,   410,    -1,   316,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,   423,   424,
      -1,    20,    21,    -1,    23,    -1,    -1,   432,   433,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    -1,    -1,    -1,    -1,    -1,   366,   367,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   376,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,   400,    21,    -1,   403,    -1,    -1,    -1,    -1,    -1,
     409,   410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    -1,     7,   423,   424,    -1,    11,    -1,    -1,
      -1,    -1,    16,   432,   433,    19,    -1,    21,    22,    58,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    -1,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     3,     4,    -1,    -1,     7,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    19,    -1,    21,    22,    -1,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     3,     4,    -1,    -1,     7,     8,     9,    -1,    11,
      -1,    -1,    14,    -1,    16,    -1,    -1,    19,    -1,    21,
      -1,    -1,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    -1,     7,     8,     9,    -1,
      11,    -1,    -1,    14,    -1,    16,    -1,    -1,    19,    -1,
      21,    -1,    -1,    24,    25,    26,    58,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    58,    -1,    60,
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
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
       7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,    16,
      -1,    -1,    19,    -1,    21,    -1,    -1,    24,    25,    26,
      58,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     3,     4,    -1,    -1,     7,    -1,    -1,    -1,
      11,    -1,    -1,    14,    -1,    16,    -1,    -1,    19,    -1,
      21,    -1,    -1,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    24,    -1,    26,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    58,    59,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    96,     0,    10,    20,    21,    23,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   102,
     103,   104,   105,   106,   107,   108,   109,   146,   148,   149,
     152,   160,    58,    88,    23,    89,    58,    21,   109,    58,
     110,    58,   111,    56,    59,   150,   150,    57,    59,    58,
      57,    56,    34,    55,    63,    55,     3,     4,     7,    11,
      14,    16,    19,    24,    25,    26,    58,    59,    68,    79,
     106,   113,   114,   116,   117,   119,   121,   122,   129,   132,
     134,   136,   137,   139,   142,   143,   151,   158,   165,    58,
     147,   107,   108,   161,   162,    57,   147,    15,    48,    50,
      51,    52,    53,    54,    58,    61,    97,    99,   101,   132,
     135,    58,    50,   112,    58,    63,    63,    63,    58,    51,
      58,   128,    61,   101,    58,    33,   138,    57,    33,    34,
      35,    36,    37,    38,    39,    40,    91,   159,   151,    58,
      58,   109,   151,   151,   151,   151,   151,     5,     6,   125,
     151,   151,   151,   151,   151,   151,   151,   151,    60,   151,
     151,    55,   153,    58,    58,   148,   162,   163,   164,    56,
     147,    57,    33,    61,   101,    34,    55,    64,    63,   101,
     101,    58,   109,   113,   115,    57,    57,    54,    56,    57,
      51,    58,    57,    51,    58,   141,   144,    58,   132,   101,
     101,    33,    60,    34,    34,    56,    63,    63,    58,    59,
      63,    59,    56,    60,   164,    57,    95,   102,   104,    17,
     101,    27,    28,    29,    30,    31,    32,    41,    42,    43,
      44,    45,    46,    47,    49,    62,    65,    92,    93,    94,
      98,   101,    50,    34,   112,    64,    64,    56,    50,   128,
      62,    12,    58,    99,   101,   131,   132,   133,    58,    65,
     145,   138,    58,   132,   151,   135,   135,   101,   101,    59,
      67,    78,   106,   113,   114,   116,   121,   132,   137,   143,
     154,   155,   158,   165,   112,    22,    56,    57,    59,   106,
     113,   114,   116,   121,   130,   132,   134,   136,   137,   139,
     142,   143,   158,   165,   166,   167,   168,    95,    62,   100,
     101,   101,    64,   123,   120,   101,    57,    57,    56,    55,
      56,    55,    56,   140,   141,    56,    56,    56,    64,    64,
     155,    58,    58,   155,   155,   155,   155,   155,   155,   155,
     155,   155,    60,    64,    33,    73,    74,    83,    84,   127,
     167,    60,   167,    62,    98,    34,    59,    59,    56,    50,
     127,   131,    58,   145,   124,   126,    60,    34,    34,    58,
     132,   130,    60,   100,   101,     8,     9,   106,   113,   114,
     116,   121,   129,   132,   134,   137,   139,   142,   143,   156,
     157,   158,   165,   157,    58,   114,    57,    57,   140,    59,
      59,   155,    13,    13,    56,    56,    56,    60,   156,    60,
      64,   133,   127,   157,   157,    56,    56,   118,    56,   130,
      60,    60,    59,   157,    60
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
     114,   115,   115,   116,   116,   118,   117,   120,   119,   121,
     123,   122,   124,   122,   126,   125,   125,   127,   127,   127,
     127,   128,   128,   129,   130,   130,   131,   131,   131,   131,
     132,   133,   133,   133,   134,   135,   136,   136,   137,   138,
     138,   138,   139,   140,   140,   141,   141,   142,   143,   144,
     145,   145,   146,   146,   147,   147,   148,   149,   150,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   153,   152,   154,   154,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   157,   157,
     158,   159,   159,   160,   161,   161,   162,   162,   163,   163,
     164,   165,   165,   166,   166,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   168,   168
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
       3,     1,     1,     1,     1,     0,    12,     0,     8,     2,
       0,     8,     0,     9,     0,     8,     0,     1,     1,     1,
       1,     1,     1,     9,     3,     1,     1,     1,     1,     1,
       5,     1,     3,     1,     9,     3,     5,     5,     5,     2,
       2,     0,     5,     3,     1,     1,     1,     3,     5,     2,
       3,     0,     2,     2,     1,     3,     6,     7,     3,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     4,     2,     2,     2,     0,     0,     8,     5,     5,
       2,     2,     2,     2,     2,     2,     2,     2,     4,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     2,
       2,     2,     3,     6,     2,     3,     2,     5,     1,     2,
       4,     3,     4,     4,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     2
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
#line 1973 "bison.tab.c"
    break;

  case 70:
#line 109 "bison.y"
                                                        { fprintf(yyout, " : declaration statement"); }
#line 1979 "bison.tab.c"
    break;

  case 95:
#line 156 "bison.y"
                                                                                                   {fprintf(yyout, " : loop statement");}
#line 1985 "bison.tab.c"
    break;

  case 97:
#line 159 "bison.y"
                                               {fprintf(yyout, " : loop statement");}
#line 1991 "bison.tab.c"
    break;

  case 100:
#line 167 "bison.y"
                                                { fprintf(yyout, " : conditional statement");  }
#line 1997 "bison.tab.c"
    break;

  case 102:
#line 168 "bison.y"
                                                                    { fprintf(yyout, " : conditional statement");  }
#line 2003 "bison.tab.c"
    break;

  case 104:
#line 172 "bison.y"
                                                 { fprintf(yyout, " : conditional statement");  }
#line 2009 "bison.tab.c"
    break;

  case 115:
#line 183 "bison.y"
                                                                          { fprintf(yyout, " : analyze statement");  }
#line 2015 "bison.tab.c"
    break;

  case 120:
#line 194 "bison.y"
                                                         { fprintf(yyout, " : call statement");  }
#line 2021 "bison.tab.c"
    break;

  case 124:
#line 204 "bison.y"
                                                                                                           { fprintf(yyout, " : call statement");  }
#line 2027 "bison.tab.c"
    break;

  case 126:
#line 209 "bison.y"
                                                       { fprintf(yyout, " : get statement");  }
#line 2033 "bison.tab.c"
    break;

  case 127:
#line 210 "bison.y"
                                                        { fprintf(yyout, " : get statement");  }
#line 2039 "bison.tab.c"
    break;

  case 128:
#line 215 "bison.y"
                                                          { fprintf(yyout, " : sleep statement");  }
#line 2045 "bison.tab.c"
    break;

  case 134:
#line 230 "bison.y"
     { 
      fprintf(yyout, " : scan statement");
     }
#line 2053 "bison.tab.c"
    break;

  case 137:
#line 240 "bison.y"
                                        { fprintf(yyout, " : return statement"); }
#line 2059 "bison.tab.c"
    break;

  case 138:
#line 244 "bison.y"
       { 
        fprintf(yyout, " : print statement");
       }
#line 2067 "bison.tab.c"
    break;

  case 146:
#line 261 "bison.y"
                                                                            { fprintf(yyout, " : function declaration statement"); }
#line 2073 "bison.tab.c"
    break;

  case 147:
#line 262 "bison.y"
                                                                                      { fprintf(yyout, " : function declaration statement"); }
#line 2079 "bison.tab.c"
    break;

  case 166:
#line 286 "bison.y"
                                      { fprintf(yyout, " : task declaration statement"); }
#line 2085 "bison.tab.c"
    break;


#line 2089 "bison.tab.c"

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
#line 387 "bison.y"


void yyerror(std::string s){
  std::cout << "Syntax Error: " << s << " at line number - " << yylineno << std::endl;
}
