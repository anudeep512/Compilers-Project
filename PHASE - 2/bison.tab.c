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
#define YYLAST   1577

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  230
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  429

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
     111,   111,   111,   111,   112,   112,   114,   115,   118,   119,
     120,   121,   124,   125,   126,   127,   130,   131,   137,   140,
     143,   144,   148,   149,   152,   152,   155,   155,   158,   158,
     163,   166,   166,   167,   167,   171,   171,   172,   175,   175,
     175,   175,   178,   178,   180,   182,   182,   187,   188,   189,
     190,   193,   196,   197,   198,   203,   206,   208,   209,   214,
     218,   219,   220,   223,   227,   228,   234,   235,   239,   242,
     248,   251,   252,   257,   257,   259,   259,   260,   261,   263,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   273,
     274,   275,   276,   277,   278,   279,   284,   284,   287,   288,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   322,   323,   327,   328,
     329,   333,   336,   337,   340,   341,   344,   345,   348,   351,
     352,   356,   357,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   378,
     379
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

#define YYPACT_NINF (-354)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -354,    38,  -354,    -9,   -78,   -17,     6,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,     9,    27,    18,  -354,    31,    31,
    -354,  -354,    41,    68,    79,  -354,    82,   111,   100,    94,
     104,  -354,  1351,  -354,  -354,   106,  1450,   105,   106,   239,
     108,   123,   117,   115,   120,   126,   122,    24,   113,   239,
     107,   140,   160,   146,   612,  1351,   148,   159,  1351,   163,
     164,  1351,  1351,  -354,  -354,  1351,   135,  1351,  1351,  1351,
    1351,  1351,  1351,  1351,  1351,   161,  1351,  1351,  -354,   167,
     166,   176,   794,   169,   106,    46,   202,   177,  -354,  -354,
    -354,  -354,  -354,  -354,   239,  -354,  -354,  -354,  -354,  -354,
     216,  -354,   -39,   173,   239,   239,  1421,   194,  -354,  -354,
     195,   199,   200,   198,    37,   205,    42,    -6,   239,  -354,
    -354,  -354,  -354,  -354,  -354,   239,   226,   204,   231,   232,
    -354,  -354,  -354,  -354,  -354,  -354,   206,   209,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
     210,   208,  -354,   212,   214,   221,    16,  -354,  -354,    47,
     411,   261,   239,   915,   239,   238,   262,   123,   234,   235,
     267,  -354,  -354,   246,   253,    24,   242,  -354,   134,  -354,
    -354,   251,  -354,  -354,   245,   160,  -354,  -354,  -354,  -354,
      -2,  1351,   297,   297,   239,   239,  -354,  1382,   123,   914,
    -354,  -354,  -354,   411,  -354,  -354,  -354,  -354,   254,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,   239,  -354,
    -354,   239,    25,  -354,  -354,   239,   258,   263,   265,  -354,
    -354,  -354,  -354,  -354,  -354,    92,    96,    42,  -354,   266,
    -354,  -354,  -354,   269,   270,   255,   264,  1382,   260,   271,
    1382,  1382,  1382,  1382,  1382,  1382,  1382,  1382,   272,  -354,
    -354,    32,   294,  -354,    59,   914,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,   828,  -354,  -354,   268,  1512,  -354,   300,   276,
     277,   281,   288,    59,  -354,   380,  -354,   283,  -354,  -354,
     245,  -354,  -354,  -354,  -354,  -354,   279,   308,   310,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,    39,
    -354,  -354,  -354,  -354,    97,   291,  -354,  -354,  -354,   239,
     239,  1265,  1265,   290,   295,   296,  -354,    96,  -354,   298,
     299,  1382,   341,   342,   306,  -354,  -354,  -354,  -354,  -354,
     311,   312,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  1000,  -354,  -354,  1031,   175,   305,
     134,    59,  -354,  1265,  1265,  -354,   315,   318,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,   116,    97,  1117,  1148,  -354,
    -354,   316,  -354,  -354,  -354,  -354,  1265,  1234,  -354
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      24,     0,     1,     0,     0,     0,     0,    48,    49,    50,
      51,    52,    53,    59,    60,    61,    62,    63,    54,    55,
      56,    57,    58,    64,    65,    66,    67,    68,    72,    70,
      71,    74,    75,    25,     0,     0,     0,    26,     0,     0,
      27,    28,     0,     0,     0,    73,     0,    78,    76,     0,
      77,    69,   165,   143,   144,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   132,     0,     0,   165,     0,     0,   165,     0,
       0,   165,   165,    94,    95,   165,   107,   165,   165,   165,
     165,   165,   165,   165,   165,     0,   165,   165,   145,   166,
       0,     0,     0,     0,     0,     0,     0,     0,    35,    39,
      36,    38,    37,    29,     0,    43,    42,    80,    30,    47,
      79,    87,     0,     0,     0,     0,     0,     0,   112,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       7,     4,     3,     2,     5,     0,   198,     0,     0,     0,
     150,    90,    91,   151,   154,   156,     0,     0,   100,   157,
     153,   152,   162,   160,   158,   155,   159,   149,   164,   163,
       0,     0,   204,     0,     0,     0,     0,   206,   202,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,    93,    92,     0,     0,     0,     0,   138,     0,   130,
     131,     0,   136,   137,   142,   132,   199,   209,    88,    89,
       0,   165,     0,     0,     0,     0,   146,     0,     0,     0,
     203,   201,   207,     0,   147,    23,    22,   126,     0,    17,
      14,    15,    16,    19,    18,    20,    21,     9,     8,    10,
      11,    12,    13,    45,    34,    32,    31,    33,     0,    81,
      86,     0,     0,   101,    98,     0,     0,     0,     0,   124,
      29,    42,   120,   122,    30,     0,     0,     0,   140,     0,
     200,   210,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   180,
     179,     0,     0,   116,     0,     0,   213,   214,   217,   219,
     220,   216,   215,   225,   223,   221,   218,   222,   228,   227,
     226,   229,     0,   148,    46,     0,    41,    84,    83,     0,
       0,     0,     0,     0,   129,     0,   121,     0,   135,   133,
     142,   139,   127,   128,   103,   105,     0,     0,     0,   170,
     171,   173,   172,   174,   178,   175,   176,   167,   205,     0,
     109,   108,   111,   110,     0,     0,   208,   230,    44,     0,
       0,     0,     0,     0,     0,     0,   123,     0,   141,     0,
       0,     0,     0,     0,     0,   212,   115,   224,    40,    85,
       0,     0,   181,   182,   184,   183,   188,   186,   187,   190,
     193,   185,   189,   196,     0,   195,   194,     0,     0,     0,
       0,     0,   134,     0,     0,   177,     0,     0,   211,   191,
     192,   102,   197,    99,    96,     0,     0,     0,     0,   168,
     169,     0,   125,   114,   104,   106,     0,     0,    97
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -354,  -354,  -354,  -354,  -354,   153,  -354,  -354,    61,  -196,
      19,   -46,  -168,  -354,  -161,  -354,    -1,   -49,   -48,   257,
    -354,  -354,  -153,   259,    23,   -38,  -354,   128,  -354,  -354,
    -354,  -354,   165,  -354,  -354,  -354,  -354,  -354,  -320,   186,
    -227,  -350,    62,   -54,   -10,   112,    -5,  -218,   181,   187,
     401,    30,   124,   419,   332,  -354,    64,  -354,   -47,   398,
    -354,   362,   -61,  -354,  -354,  -354,  -240,  -157,  -353,   348,
    -354,  -354,  -354,   304,  -354,   243,   385,  -354,  -226,  -354
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   145,   245,   246,   247,   224,     1,   115,   248,   116,
     315,   262,    29,    30,    31,    32,    78,    34,    35,    36,
      48,    50,   122,    79,    80,    81,   193,    82,    83,   421,
      84,   320,    85,    86,   319,   369,   158,   370,   354,   130,
      87,   300,   263,    88,   265,    89,   119,    90,    91,   135,
      92,   329,   204,    93,    94,   205,   268,    37,    99,   174,
      39,    53,    95,    40,   171,   287,   288,   393,   394,    96,
     146,    41,   102,   103,   176,   177,    97,   310,   311,   312
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,   303,   261,   365,   376,   118,    44,   100,   101,   397,
      43,   105,   225,   117,   147,   118,   185,   150,    71,   226,
     153,   154,    71,   132,   155,   186,   159,   160,   161,   162,
     163,   164,   165,   166,   252,   168,   169,   336,     2,     6,
     339,   340,   341,   342,   343,   344,   345,   346,     3,    42,
     417,   418,   206,   100,   101,   225,   270,   179,     4,     5,
     118,     6,   226,    71,    46,   291,   423,    47,   183,   355,
     118,   118,    45,   427,    51,   128,   221,   303,   188,   189,
     185,   416,   129,   207,   118,    49,   357,   185,   199,   318,
      52,   118,   208,   202,   303,   200,   348,   374,    55,   209,
     203,   170,   170,   180,   223,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    56,   118,   261,
     118,   405,   350,   351,   386,   386,   228,    57,   249,    58,
     156,   157,   352,   353,   264,    59,   259,   325,   326,   106,
     272,   327,   328,   293,   294,    60,   271,    61,    71,    62,
     118,   118,   104,   284,    98,   301,   120,   386,   275,   276,
     386,   325,   422,   121,   131,   123,   386,   386,   124,   281,
     127,   297,   107,   125,   108,   109,   110,   111,   112,   126,
     386,   386,   260,   134,   118,   114,    45,   118,   133,   386,
     386,   118,   316,   136,   261,   317,   148,   273,   274,   321,
     139,   140,   141,   142,   143,   144,   280,   149,   296,   151,
     152,   167,   170,   284,   172,   178,   284,   284,   284,   284,
     284,   284,   284,   284,   173,   181,   187,   412,   182,   281,
     412,   301,   281,   281,   281,   281,   281,   281,   281,   281,
     184,   194,   195,   196,   106,   198,   197,   297,   301,   210,
     412,   412,   201,    71,   211,   212,   213,   217,   216,   214,
     412,   264,   215,   219,   297,   218,   280,   220,   227,   280,
     280,   280,   280,   280,   280,   280,   280,   107,   250,   108,
     109,   110,   111,   112,   296,   375,   251,   113,   253,   254,
     114,   138,   255,   256,   258,   118,   118,   387,   387,   266,
     267,   296,   106,   316,   379,   322,   314,   284,   337,   334,
     323,   324,   331,   383,   383,   332,   333,   349,   335,   338,
     358,   302,   347,   281,   360,   361,   362,   363,   364,   371,
     387,   367,   372,   387,   373,   282,   264,   298,   398,   387,
     387,   377,   400,   401,   406,   407,   383,   403,   404,   383,
     382,   382,   408,   387,   387,   383,   383,   409,   410,   414,
     280,   419,   387,   387,   420,   426,   313,   359,   378,   383,
     383,   257,   283,   191,   299,   192,   399,   366,   383,   383,
     415,   330,   269,   382,   368,   106,   382,   402,   285,    38,
     304,    54,   382,   382,    71,   282,   175,   302,   282,   282,
     282,   282,   282,   282,   282,   282,   382,   382,     0,   222,
       0,     0,     0,   298,   302,   382,   382,     0,   107,     0,
     108,   109,   110,   111,   112,     0,     0,     0,   260,     0,
     298,   114,   283,     0,     0,   283,   283,   283,   283,   283,
     283,   283,   283,     0,     0,     0,     0,     0,   285,     0,
     299,   285,   285,   285,   285,   285,   285,   285,   285,     0,
       0,     0,     0,   388,   388,     0,   304,   299,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,   384,
     384,     0,     0,   304,     0,     0,     0,     0,     0,   282,
       0,     0,     0,     0,     0,     0,   388,     0,     0,   388,
       0,     0,     0,     0,     0,   388,   388,     0,     0,     0,
       0,     0,   384,     0,     0,   384,   385,   385,     0,   388,
     388,   384,   384,     0,     0,     0,   283,     0,   388,   388,
       0,     0,   389,   389,     0,   384,   384,     0,     0,   286,
       0,   307,   285,     0,   384,   384,     0,     0,     0,   385,
       0,     0,   385,     0,     0,   289,     0,   308,   385,   385,
       0,     0,     0,     0,     0,   389,     0,     0,   389,     0,
       0,     0,   385,   385,   389,   389,     0,     0,     0,     0,
       0,   385,   385,     0,     0,     0,     0,     0,   389,   389,
       0,     0,   290,     0,   309,     0,     0,   389,   389,   286,
       0,     0,   286,   286,   286,   286,   286,   286,   286,   286,
     305,     0,     0,     0,     0,   289,     0,   307,   289,   289,
     289,   289,   289,   289,   289,   289,     0,     0,   306,     0,
       0,     0,     0,   308,   307,   137,   138,   139,   140,   141,
     142,   143,   144,     0,     0,     0,     0,     0,     0,     0,
     308,     0,   290,     0,     0,   290,   290,   290,   290,   290,
     290,   290,   290,     0,     0,     0,     0,     0,     0,     0,
     309,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   392,   392,     0,   305,   309,     0,     0,
       0,     0,     0,   286,     0,     0,     0,     0,     0,   395,
     395,     0,     0,   305,   306,     0,     0,     0,     0,   289,
       0,     0,     0,     0,     0,     0,   392,     0,     0,   392,
       0,   306,     0,     0,     0,   392,   392,     0,     0,     0,
       0,     0,   395,     0,     0,   395,   396,   396,     0,   392,
     392,   395,   395,     0,     0,     0,   290,     0,   392,   392,
       0,     0,   390,   390,     0,   395,   395,     0,     0,     0,
       0,     0,     0,     0,   395,   395,     0,     0,     0,   396,
     391,   391,   396,     0,     0,     0,     0,     0,   396,   396,
       0,     0,     0,     0,     0,   390,     0,     0,   390,     0,
       0,     0,   396,   396,   390,   390,     0,     0,     0,     0,
       0,   396,   396,   391,     0,    70,   391,     6,   390,   390,
       0,     0,   391,   391,     0,     0,     0,   390,   390,     0,
       0,    63,    64,     0,     0,    65,   391,   391,     0,    66,
       0,     0,     0,     0,    68,   391,   391,    69,     0,    70,
     292,     0,    71,    72,    73,     0,     0,     0,     0,     0,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,   293,   294,    74,   295,   356,     0,
       0,     0,     0,     0,     0,     7,    76,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    77,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    63,    64,     0,
       0,    65,     0,     0,     0,    66,     0,     0,     0,     0,
      68,     0,     0,    69,     0,    70,   292,     0,    71,    72,
      73,     0,   229,   230,   231,   232,   233,   234,     0,     0,
       0,     0,     0,     0,     0,     0,   235,   236,   237,   238,
     239,   240,   241,     0,   242,     0,     0,     0,     0,     0,
     293,   294,    74,   295,     0,     0,     0,   243,     0,     0,
     244,     7,    76,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    77,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    63,    64,     0,     0,    65,   380,   381,
       0,    66,     0,     0,    67,     0,    68,     0,     0,    69,
       0,    70,     0,     0,    71,    72,    73,     0,     0,     0,
       0,     0,     0,     0,    63,    64,     0,     0,    65,   380,
     381,     0,    66,     0,     0,    67,     0,    68,     0,     0,
      69,     0,    70,     0,     0,    71,    72,    73,    74,     0,
     411,     0,     0,     0,     0,     0,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    74,
       0,   413,     0,     0,     0,     0,     0,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      63,    64,     0,     0,    65,   380,   381,     0,    66,     0,
       0,    67,     0,    68,     0,     0,    69,     0,    70,     0,
       0,    71,    72,    73,     0,     0,     0,     0,     0,     0,
       0,    63,    64,     0,     0,    65,   380,   381,     0,    66,
       0,     0,    67,     0,    68,     0,     0,    69,     0,    70,
       0,     0,    71,    72,    73,    74,     0,   424,     0,     0,
       0,     0,     0,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    74,     0,   425,     0,
       0,     0,     0,     0,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    63,    64,     0,
       0,    65,   380,   381,     0,    66,     0,     0,    67,     0,
      68,     0,     0,    69,     0,    70,     0,     0,    71,    72,
      73,     0,     0,     0,     0,     0,     0,     0,    63,    64,
       0,     0,    65,   380,   381,     0,    66,     0,     0,    67,
       0,    68,     0,     0,    69,     0,    70,     0,     0,    71,
      72,    73,    74,     0,   428,     0,     0,     0,     0,     0,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    74,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    63,    64,     0,     0,    65,     0,
       0,     0,    66,     0,     0,    67,     0,    68,     0,     0,
      69,     0,    70,     0,     0,    71,    72,    73,     0,     0,
       0,     0,     0,     0,     0,    63,    64,     0,     0,    65,
       0,     0,     0,     0,     0,     0,     0,     0,    68,     0,
       0,     0,     0,    70,     0,     0,    71,     0,    73,    74,
      75,     0,     0,     0,     0,     0,     0,     0,     7,    76,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      77,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      74,   277,    70,     0,     0,     0,     0,     0,     0,   278,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
     279,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    70,     0,     0,     0,     0,     0,     0,     0,   190,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,   229,
     230,   231,   232,   233,   234,     0,     0,     0,     0,     0,
       0,     0,     0,   235,   236,   237,   238,   239,   240,   241,
       0,   242,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244
};

static const yytype_int16 yycheck[] =
{
       1,   219,   198,   323,   354,    59,    23,    56,    56,   362,
      88,    58,   180,    59,    75,    69,    55,    78,    24,   180,
      81,    82,    24,    69,    85,    64,    87,    88,    89,    90,
      91,    92,    93,    94,   187,    96,    97,   277,     0,    23,
     280,   281,   282,   283,   284,   285,   286,   287,    10,    58,
     403,   404,    58,   102,   102,   223,    58,   104,    20,    21,
     114,    23,   223,    24,    58,   218,   416,    58,   114,   295,
     124,   125,    89,   426,    56,    51,    60,   295,   124,   125,
      55,   401,    58,   137,   138,    58,   312,    55,    51,    64,
      59,   145,   138,    51,   312,    58,    64,    58,    57,   145,
      58,    55,    55,    57,    57,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    59,   182,   325,
     184,   371,    73,    74,   361,   362,   182,    58,   184,    57,
       5,     6,    83,    84,   198,    34,    12,    55,    56,    15,
     211,    55,    56,    56,    57,    55,   210,    63,    24,    55,
     214,   215,    57,   217,    58,   219,    58,   394,   214,   215,
     397,    55,    56,    50,    61,    58,   403,   404,    63,   217,
      58,   219,    48,    63,    50,    51,    52,    53,    54,    63,
     417,   418,    58,    33,   248,    61,    89,   251,    58,   426,
     427,   255,   248,    57,   400,   251,    58,   212,   213,   255,
      35,    36,    37,    38,    39,    40,   217,    58,   219,    56,
      56,    60,    55,   277,    58,    56,   280,   281,   282,   283,
     284,   285,   286,   287,    58,    33,    63,   394,    61,   277,
     397,   295,   280,   281,   282,   283,   284,   285,   286,   287,
      34,    57,    57,    54,    15,    57,    56,   295,   312,    33,
     417,   418,    57,    24,    60,    34,    34,    59,    58,    63,
     427,   325,    63,    59,   312,    63,   277,    56,    17,   280,
     281,   282,   283,   284,   285,   286,   287,    48,    50,    50,
      51,    52,    53,    54,   295,   349,    34,    58,    64,    64,
      61,    34,    56,    50,    62,   359,   360,   361,   362,    58,
      65,   312,    15,   359,   360,    57,    62,   371,    58,    64,
      57,    56,    56,   361,   362,    56,    56,    33,    64,    58,
      62,   219,    60,   371,    34,    59,    59,    56,    50,    60,
     394,    58,    34,   397,    34,   217,   400,   219,    58,   403,
     404,    60,    57,    57,    13,    13,   394,    59,    59,   397,
     361,   362,    56,   417,   418,   403,   404,    56,    56,    64,
     371,    56,   426,   427,    56,    59,   223,   316,   359,   417,
     418,   195,   217,   126,   219,   126,   363,   325,   426,   427,
     400,   267,   205,   394,   330,    15,   397,   367,   217,     1,
     219,    39,   403,   404,    24,   277,   102,   295,   280,   281,
     282,   283,   284,   285,   286,   287,   417,   418,    -1,   176,
      -1,    -1,    -1,   295,   312,   426,   427,    -1,    48,    -1,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    58,    -1,
     312,    61,   277,    -1,    -1,   280,   281,   282,   283,   284,
     285,   286,   287,    -1,    -1,    -1,    -1,    -1,   277,    -1,
     295,   280,   281,   282,   283,   284,   285,   286,   287,    -1,
      -1,    -1,    -1,   361,   362,    -1,   295,   312,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,   361,
     362,    -1,    -1,   312,    -1,    -1,    -1,    -1,    -1,   371,
      -1,    -1,    -1,    -1,    -1,    -1,   394,    -1,    -1,   397,
      -1,    -1,    -1,    -1,    -1,   403,   404,    -1,    -1,    -1,
      -1,    -1,   394,    -1,    -1,   397,   361,   362,    -1,   417,
     418,   403,   404,    -1,    -1,    -1,   371,    -1,   426,   427,
      -1,    -1,   361,   362,    -1,   417,   418,    -1,    -1,   217,
      -1,   219,   371,    -1,   426,   427,    -1,    -1,    -1,   394,
      -1,    -1,   397,    -1,    -1,   217,    -1,   219,   403,   404,
      -1,    -1,    -1,    -1,    -1,   394,    -1,    -1,   397,    -1,
      -1,    -1,   417,   418,   403,   404,    -1,    -1,    -1,    -1,
      -1,   426,   427,    -1,    -1,    -1,    -1,    -1,   417,   418,
      -1,    -1,   217,    -1,   219,    -1,    -1,   426,   427,   277,
      -1,    -1,   280,   281,   282,   283,   284,   285,   286,   287,
     219,    -1,    -1,    -1,    -1,   277,    -1,   295,   280,   281,
     282,   283,   284,   285,   286,   287,    -1,    -1,   219,    -1,
      -1,    -1,    -1,   295,   312,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     312,    -1,   277,    -1,    -1,   280,   281,   282,   283,   284,
     285,   286,   287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   361,   362,    -1,   295,   312,    -1,    -1,
      -1,    -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,   361,
     362,    -1,    -1,   312,   295,    -1,    -1,    -1,    -1,   371,
      -1,    -1,    -1,    -1,    -1,    -1,   394,    -1,    -1,   397,
      -1,   312,    -1,    -1,    -1,   403,   404,    -1,    -1,    -1,
      -1,    -1,   394,    -1,    -1,   397,   361,   362,    -1,   417,
     418,   403,   404,    -1,    -1,    -1,   371,    -1,   426,   427,
      -1,    -1,   361,   362,    -1,   417,   418,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   426,   427,    -1,    -1,    -1,   394,
     361,   362,   397,    -1,    -1,    -1,    -1,    -1,   403,   404,
      -1,    -1,    -1,    -1,    -1,   394,    -1,    -1,   397,    -1,
      -1,    -1,   417,   418,   403,   404,    -1,    -1,    -1,    -1,
      -1,   426,   427,   394,    -1,    21,   397,    23,   417,   418,
      -1,    -1,   403,   404,    -1,    -1,    -1,   426,   427,    -1,
      -1,     3,     4,    -1,    -1,     7,   417,   418,    -1,    11,
      -1,    -1,    -1,    -1,    16,   426,   427,    19,    -1,    21,
      22,    -1,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    56,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     3,     4,    -1,
      -1,     7,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,
      16,    -1,    -1,    19,    -1,    21,    22,    -1,    24,    25,
      26,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    -1,    -1,    62,    -1,    -1,
      65,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     3,     4,    -1,    -1,     7,     8,     9,
      -1,    11,    -1,    -1,    14,    -1,    16,    -1,    -1,    19,
      -1,    21,    -1,    -1,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,     7,     8,
       9,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,    -1,
      19,    -1,    21,    -1,    -1,    24,    25,    26,    58,    -1,
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
      82,    83,    84,    85,    86,    87,    88,     3,     4,    -1,
      -1,     7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,
      16,    -1,    -1,    19,    -1,    21,    -1,    -1,    24,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,     7,     8,     9,    -1,    11,    -1,    -1,    14,
      -1,    16,    -1,    -1,    19,    -1,    21,    -1,    -1,    24,
      25,    26,    58,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    58,    -1,    -1,    -1,    -1,    -1,    -1,
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
      88,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    96,     0,    10,    20,    21,    23,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   102,
     103,   104,   105,   106,   107,   108,   109,   147,   149,   150,
     153,   161,    58,    88,    23,    89,    58,    58,   110,    58,
     111,    56,    59,   151,   151,    57,    59,    58,    57,    34,
      55,    63,    55,     3,     4,     7,    11,    14,    16,    19,
      21,    24,    25,    26,    58,    59,    68,    79,   106,   113,
     114,   115,   117,   118,   120,   122,   123,   130,   133,   135,
     137,   138,   140,   143,   144,   152,   159,   166,    58,   148,
     107,   108,   162,   163,    57,   148,    15,    48,    50,    51,
      52,    53,    54,    58,    61,    97,    99,   101,   133,   136,
      58,    50,   112,    58,    63,    63,    63,    58,    51,    58,
     129,    61,   101,    58,    33,   139,    57,    33,    34,    35,
      36,    37,    38,    39,    40,    91,   160,   152,    58,    58,
     152,    56,    56,   152,   152,   152,     5,     6,   126,   152,
     152,   152,   152,   152,   152,   152,   152,    60,   152,   152,
      55,   154,    58,    58,   149,   163,   164,   165,    56,   148,
      57,    33,    61,   101,    34,    55,    64,    63,   101,   101,
      58,   109,   113,   116,    57,    57,    54,    56,    57,    51,
      58,    57,    51,    58,   142,   145,    58,   133,   101,   101,
      33,    60,    34,    34,    63,    63,    58,    59,    63,    59,
      56,    60,   165,    57,    95,   102,   104,    17,   101,    27,
      28,    29,    30,    31,    32,    41,    42,    43,    44,    45,
      46,    47,    49,    62,    65,    92,    93,    94,    98,   101,
      50,    34,   112,    64,    64,    56,    50,   129,    62,    12,
      58,    99,   101,   132,   133,   134,    58,    65,   146,   139,
      58,   133,   152,   136,   136,   101,   101,    59,    67,    78,
     106,   115,   117,   122,   133,   138,   144,   155,   156,   159,
     166,   112,    22,    56,    57,    59,   106,   115,   117,   122,
     131,   133,   135,   137,   138,   140,   143,   144,   159,   166,
     167,   168,   169,    95,    62,   100,   101,   101,    64,   124,
     121,   101,    57,    57,    56,    55,    56,    55,    56,   141,
     142,    56,    56,    56,    64,    64,   156,    58,    58,   156,
     156,   156,   156,   156,   156,   156,   156,    60,    64,    33,
      73,    74,    83,    84,   128,   168,    60,   168,    62,    98,
      34,    59,    59,    56,    50,   128,   132,    58,   146,   125,
     127,    60,    34,    34,    58,   133,   131,    60,   100,   101,
       8,     9,   106,   115,   117,   122,   130,   133,   135,   138,
     140,   143,   144,   157,   158,   159,   166,   158,    58,   114,
      57,    57,   141,    59,    59,   156,    13,    13,    56,    56,
      56,    60,   157,    60,    64,   134,   128,   158,   158,    56,
      56,   119,    56,   131,    60,    60,    59,   158,    60
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
     107,   107,   107,   107,   108,   108,   109,   109,   110,   110,
     110,   110,   111,   111,   111,   111,   112,   112,   113,   114,
     115,   115,   116,   116,   117,   117,   119,   118,   121,   120,
     122,   124,   123,   125,   123,   127,   126,   126,   128,   128,
     128,   128,   129,   129,   130,   131,   131,   132,   132,   132,
     132,   133,   134,   134,   134,   135,   136,   137,   137,   138,
     139,   139,   139,   140,   141,   141,   142,   142,   143,   144,
     145,   146,   146,   147,   147,   148,   148,   149,   150,   151,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   154,   153,   155,   155,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   158,   158,   159,   160,
     160,   161,   162,   162,   163,   163,   164,   164,   165,   166,
     166,   167,   167,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   169,
     169
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
       1,     1,     1,     2,     1,     1,     2,     2,     1,     3,
       3,     5,     4,     6,     6,     8,     3,     1,     3,     3,
       2,     2,     1,     1,     1,     1,     0,    12,     0,     8,
       2,     0,     8,     0,     9,     0,     8,     0,     1,     1,
       1,     1,     1,     1,     9,     3,     1,     1,     1,     1,
       1,     5,     1,     3,     1,     9,     3,     5,     5,     5,
       2,     2,     0,     5,     3,     1,     1,     1,     3,     5,
       2,     3,     0,     2,     2,     1,     3,     6,     7,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     4,     2,     2,     2,     0,     0,     8,     5,     5,
       2,     2,     2,     2,     2,     2,     2,     4,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     2,     2,     2,
       3,     6,     2,     3,     2,     5,     1,     2,     4,     3,
       4,     4,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       2
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
#line 1946 "bison.tab.c"
    break;

  case 90:
#line 143 "bison.y"
                                    { fprintf(yyout, " : assignment statement");  }
#line 1952 "bison.tab.c"
    break;

  case 91:
#line 144 "bison.y"
                                     { fprintf(yyout, " : expression statement");  }
#line 1958 "bison.tab.c"
    break;

  case 96:
#line 155 "bison.y"
                                                                                                   {fprintf(yyout, " : loop statement");}
#line 1964 "bison.tab.c"
    break;

  case 98:
#line 158 "bison.y"
                                               {fprintf(yyout, " : loop statement");}
#line 1970 "bison.tab.c"
    break;

  case 101:
#line 166 "bison.y"
                                                { fprintf(yyout, " : conditional statement");  }
#line 1976 "bison.tab.c"
    break;

  case 103:
#line 167 "bison.y"
                                                                    { fprintf(yyout, " : conditional statement");  }
#line 1982 "bison.tab.c"
    break;

  case 105:
#line 171 "bison.y"
                                                 { fprintf(yyout, " : conditional statement");  }
#line 1988 "bison.tab.c"
    break;

  case 116:
#line 182 "bison.y"
                                                                          { fprintf(yyout, " : analyze statement");  }
#line 1994 "bison.tab.c"
    break;

  case 121:
#line 193 "bison.y"
                                                         { fprintf(yyout, " : call statement");  }
#line 2000 "bison.tab.c"
    break;

  case 125:
#line 203 "bison.y"
                                                                                                           { fprintf(yyout, " : call statement");  }
#line 2006 "bison.tab.c"
    break;

  case 127:
#line 208 "bison.y"
                                                       { fprintf(yyout, " : get statement");  }
#line 2012 "bison.tab.c"
    break;

  case 128:
#line 209 "bison.y"
                                                        { fprintf(yyout, " : get statement");  }
#line 2018 "bison.tab.c"
    break;

  case 129:
#line 214 "bison.y"
                                                          { fprintf(yyout, " : sleep statement");  }
#line 2024 "bison.tab.c"
    break;

  case 135:
#line 229 "bison.y"
     { 
      fprintf(yyout, " : scan statement");
     }
#line 2032 "bison.tab.c"
    break;

  case 138:
#line 239 "bison.y"
                                        { fprintf(yyout, " : return statement"); }
#line 2038 "bison.tab.c"
    break;

  case 139:
#line 243 "bison.y"
       { 
        fprintf(yyout, " : print statement");
       }
#line 2046 "bison.tab.c"
    break;

  case 147:
#line 260 "bison.y"
                                                                            { fprintf(yyout, " : function declaration statement"); }
#line 2052 "bison.tab.c"
    break;

  case 148:
#line 261 "bison.y"
                                                                                      { fprintf(yyout, " : function declaration statement"); }
#line 2058 "bison.tab.c"
    break;

  case 166:
#line 284 "bison.y"
                                      { fprintf(yyout, " : task declaration statement"); }
#line 2064 "bison.tab.c"
    break;


#line 2068 "bison.tab.c"

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
#line 382 "bison.y"


void yyerror(std::string s){
  std::cout << "Syntax Error: " << s << " at line number - " << yylineno << std::endl;
}
