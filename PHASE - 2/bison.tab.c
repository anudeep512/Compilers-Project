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
#define YYLAST   1501

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  81
/* YYNRULES -- Number of rules.  */
#define YYNRULES  227
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  412

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
      86,    87,    90,    91,    92,    93,    94,    98,    98,    98,
      98,    98,    98,    99,    99,    99,    99,    99,   101,   101,
     101,   101,   101,   102,   102,   102,   102,   102,   107,   110,
     110,   110,   110,   111,   111,   113,   114,   117,   118,   119,
     120,   123,   124,   125,   126,   129,   130,   136,   139,   142,
     143,   147,   148,   151,   151,   154,   154,   157,   157,   162,
     165,   165,   166,   166,   170,   170,   171,   174,   174,   174,
     174,   177,   177,   179,   181,   181,   186,   188,   191,   192,
     193,   198,   201,   203,   204,   209,   213,   214,   215,   218,
     222,   223,   229,   230,   234,   237,   243,   246,   247,   252,
     252,   254,   254,   255,   256,   258,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   268,   269,   270,   271,   272,
     273,   276,   277,   282,   282,   285,   286,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   320,   321,   325,   326,   327,   331,   334,
     335,   338,   339,   342,   343,   346,   349,   350,   354,   355,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   376,   377
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
  "func_args", "func_decl", "atomic_func_decl", "func_body", "func_scope",
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

#define YYPACT_NINF (-335)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -335,   498,  -335,   -24,   -45,   -21,   -12,  -335,  -335,  -335,
    -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,  -335,  -335,    -4,    25,    32,  -335,    57,    57,
    -335,  -335,    34,    66,    56,  -335,    70,    98,    75,    86,
     108,  -335,  1235,  -335,  -335,   109,  1374,   111,   109,   208,
     112,   119,   113,   110,   114,   115,   116,    12,   120,   208,
      93,   126,   152,   136,   276,  1235,   137,   139,  -335,   142,
     145,  -335,  -335,  -335,  -335,  -335,    61,  -335,  -335,  -335,
    -335,  -335,  -335,  -335,  -335,  -335,  1032,  -335,  -335,  -335,
     147,   146,   148,  1305,   151,   109,   -15,   133,  -335,  -335,
    -335,  -335,  -335,  -335,   208,  -335,  -335,  -335,  -335,   174,
    -335,   -14,   157,   208,   208,  1336,   154,  -335,  -335,   164,
     156,   166,   167,    38,   169,    51,   -13,   208,  -335,  -335,
    -335,  -335,  -335,  -335,   208,   190,  1118,   197,   199,  -335,
    -335,   172,   176,  -335,  -335,  -335,   182,   183,  -335,   178,
     184,   189,     9,  -335,  -335,    55,    67,   208,   682,   208,
     198,   213,   119,   187,   188,   223,  -335,  -335,   207,   214,
      12,   203,  -335,   138,  -335,  -335,   209,  -335,  -335,   205,
     152,  -335,  -335,  -335,  -335,     7,  -335,   253,   253,   208,
     208,  -335,  1266,   119,   681,  -335,  -335,  -335,    67,  -335,
    -335,  -335,   210,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,   208,  -335,  -335,   208,    29,  -335,  -335,   208,
     216,   217,   215,  -335,  -335,  -335,    65,    96,    51,  -335,
     228,  -335,  -335,   252,   230,   231,   224,   227,  1266,   235,
     240,  1266,  1266,  1266,  1266,  1266,  1266,  1266,  1266,   243,
    -335,  -335,    49,   267,  -335,    45,   681,  -335,  -335,  -335,
    -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,  -335,   595,  -335,  -335,   242,  1436,  -335,   273,
     258,   259,   264,   271,    45,  -335,   208,  -335,   268,  -335,
    -335,   205,  -335,   305,  -335,  -335,  -335,  -335,   265,   293,
     295,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,    36,  -335,  -335,  -335,  -335,   102,   272,  -335,  -335,
    -335,   208,   208,  1149,  1149,   277,   279,   284,  -335,    96,
    -335,  -335,   275,   285,  1266,   333,   334,   292,  -335,  -335,
    -335,  -335,  -335,   294,   300,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,  -335,  -335,  -335,  -335,  -335,   767,  -335,  -335,
     798,   241,   301,   138,    45,  -335,  1149,  1149,  -335,   302,
     303,  -335,  -335,  -335,  -335,  -335,  -335,  -335,   105,   102,
     884,   915,  -335,  -335,   290,  -335,  -335,  -335,  -335,  1149,
    1001,  -335
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      24,     0,     1,     0,     0,     0,     0,    47,    48,    49,
      50,    51,    52,    58,    59,    60,    61,    62,    53,    54,
      55,    56,    57,    63,    64,    65,    66,    67,    71,    69,
      70,    73,    74,    25,     0,     0,     0,    26,     0,     0,
      27,    28,     0,     0,     0,    72,     0,    77,    75,     0,
      76,    68,     0,   139,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   128,     0,     0,     0,     0,     0,   146,     0,
       0,   147,   150,    93,    94,   152,   106,   153,   149,   148,
     158,   156,   154,   151,   155,   161,     0,   160,   159,   141,
     163,     0,     0,     0,     0,     0,     0,     0,    35,    39,
      36,    38,    37,    29,     0,    43,    42,    79,    30,    78,
      86,     0,     0,     0,     0,     0,     0,   111,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       4,     3,     2,     5,     0,   195,     0,     0,     0,    89,
      90,     0,     0,    99,   145,   162,     0,     0,   201,     0,
       0,     0,     0,   203,   199,     0,     0,     0,     0,     0,
       0,    81,     0,     0,     0,     0,    92,    91,     0,     0,
       0,     0,   134,     0,   126,   127,     0,   132,   133,   138,
     128,   196,   206,    87,    88,     0,   157,     0,     0,     0,
       0,   142,     0,     0,     0,   200,   198,   204,     0,   143,
      23,    22,     0,    17,    14,    15,    16,    19,    18,    20,
      21,     9,     8,    10,    11,    12,    13,    45,    34,    32,
      31,    33,     0,    80,    85,     0,     0,   100,    97,     0,
       0,     0,     0,   120,   116,   118,     0,     0,     0,   136,
       0,   197,   207,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     177,   176,     0,     0,   115,     0,     0,   210,   211,   214,
     216,   217,   213,   212,   222,   220,   218,   215,   219,   225,
     224,   223,   226,     0,   144,    46,     0,    41,    83,    82,
       0,     0,     0,     0,     0,   125,     0,   117,     0,   131,
     129,   138,   135,     0,   124,   123,   102,   104,     0,     0,
       0,   167,   168,   170,   169,   171,   175,   172,   173,   164,
     202,     0,   108,   107,   110,   109,     0,     0,   205,   227,
      44,     0,     0,     0,     0,     0,     0,     0,   119,     0,
     137,   122,     0,     0,     0,     0,     0,     0,   209,   114,
     221,    40,    84,     0,     0,   178,   179,   181,   180,   185,
     183,   184,   187,   190,   182,   186,   193,     0,   192,   191,
       0,     0,     0,     0,     0,   130,     0,     0,   174,     0,
       0,   208,   188,   189,   101,   194,    98,    95,     0,     0,
       0,     0,   165,   166,     0,   121,   113,   103,   105,     0,
       0,    96
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -335,  -335,  -335,  -335,  -335,   158,  -335,  -335,    71,  -335,
      23,   -52,  -128,  -335,  -127,  -335,    -1,   -27,   -26,   246,
    -335,  -335,  -139,   250,    22,   -47,  -335,    26,  -335,  -335,
    -335,  -335,    30,  -335,  -335,  -335,  -335,  -335,  -298,   201,
     -48,  -320,    72,   -49,    -6,   -40,   185,  -203,    79,   192,
     -39,    35,   140,   -38,   104,  -335,    76,  -335,   -50,   388,
    -335,   351,   -87,   316,  -335,  -335,  -335,  -243,  -277,  -334,
     153,  -335,  -335,  -335,   289,  -335,   232,   249,  -335,  -232,
    -335
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   144,   229,   230,   231,   209,     1,   115,   232,   116,
     296,   244,    29,    30,    31,    32,   261,    34,    35,    36,
      48,    50,   121,    79,    80,   262,   178,   263,    83,   404,
      84,   301,   264,    86,   300,   352,   153,   353,   336,   129,
     369,   281,   245,   118,   246,   371,   254,    90,   266,   134,
     373,   310,   189,   374,   267,   190,   249,    37,   100,   160,
      39,    53,    95,    96,    40,   157,   268,   269,   376,   377,
     270,   145,    41,   103,   104,   162,   163,   271,   291,   292,
     293
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,   284,    44,    88,    87,    81,   347,   117,   106,   155,
     380,    71,    89,    92,    93,   318,   359,   131,   321,   322,
     323,   324,   325,   326,   327,   328,    88,    87,    81,   101,
     102,    71,     6,   236,    42,    89,    92,    93,   210,   211,
     156,   170,   166,    43,   337,   191,    46,    88,    87,    81,
     171,    78,   400,   401,    47,   165,    89,    92,    93,   155,
      71,   339,   168,   127,   272,   251,   151,   152,    45,   206,
     128,   173,   174,   284,    78,   410,   101,   102,    82,   406,
     210,   211,    85,    49,   170,   193,   399,   192,    51,   184,
     284,    55,   194,   299,   357,    78,   185,    88,    87,    81,
     395,    82,   187,   395,   170,    85,    89,    92,    93,   188,
     156,   388,   208,   330,    57,   212,    52,   233,   332,   333,
     306,   307,    82,   395,   395,    56,    85,    58,   334,   335,
      60,    91,    59,   395,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    78,   252,   256,   257,    61,
     243,   308,   309,   265,    91,   282,    94,   278,   274,   275,
     306,   405,    71,    62,   283,   286,   287,    99,   105,   120,
     119,   122,    82,   123,   126,    91,    85,   124,   125,    94,
     297,   130,    45,   298,   132,   133,   107,   302,   108,   109,
     110,   111,   112,   135,   167,   147,   113,   148,   149,   114,
      94,   150,   156,   277,   158,    97,   159,   164,   169,   265,
     181,   179,   265,   265,   265,   265,   265,   265,   265,   265,
     172,   180,   182,   195,   183,    91,   186,   282,    97,   278,
     279,   197,    71,   198,   280,   199,   283,   286,   287,   200,
     201,   203,   202,   204,   282,   205,   278,   235,   234,    97,
      94,   237,   238,   283,   286,   287,   107,   137,   108,   109,
     110,   111,   112,   239,   240,   242,   113,   247,   253,   114,
     248,   305,   295,   303,   304,   277,   138,   139,   140,   141,
     142,   143,   358,   285,   312,   313,   314,   315,   316,   297,
     362,   317,   277,   319,   370,   370,   366,   366,   320,    97,
     331,    98,   279,   329,   340,   265,   280,   342,   288,   136,
     137,   138,   139,   140,   141,   142,   143,   343,   344,   279,
     345,   346,   351,   280,    98,   354,   349,   355,   370,   356,
     366,   370,   360,   366,   386,   381,   383,   370,   370,   366,
     366,   384,   365,   365,   387,    98,   389,   390,   391,   409,
     392,   370,   370,   366,   366,   285,   393,   289,   402,   403,
     370,   370,   366,   366,   361,   397,   294,   382,   341,   367,
     367,   176,   285,   368,   368,   177,   365,   398,   348,   365,
     288,   241,   250,   255,   385,   365,   365,   350,   311,    38,
      54,   146,   161,     0,   207,    98,     0,   288,     0,   365,
     365,     0,     0,   367,     0,     0,   367,   368,   365,   365,
     368,     0,   367,   367,     0,     0,   368,   368,     0,     0,
       0,     0,   372,   372,     0,     0,   367,   367,     0,   289,
     368,   368,     0,     0,     0,   367,   367,     0,     0,   368,
     368,     0,     0,     0,     0,     0,   289,   375,   375,     0,
       0,     0,     0,   290,     0,     0,   372,     0,     0,   372,
       0,     0,     0,     0,     0,   372,   372,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   372,
     372,   375,     0,     0,   375,     0,     0,     0,   372,   372,
     375,   375,     0,     0,     0,     0,   378,   378,     2,     0,
       0,     0,     0,     0,   375,   375,     0,     0,     3,     0,
       0,     0,     0,   375,   375,     0,     0,     0,     4,     5,
       0,     6,     0,     0,     0,   290,     0,     0,     0,     0,
     378,     0,     0,   378,     0,     0,     0,     0,     0,   378,
     378,     0,   290,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   378,   378,     0,     0,     0,     0,     0,
       0,     0,   378,   378,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
       0,     0,   379,   379,     0,     0,     0,     0,    63,    64,
       0,     0,    65,     0,     0,     0,    66,     0,     0,     0,
       0,    68,     0,     0,    69,     0,    70,   273,     0,    71,
      72,    73,     0,     0,     0,     0,   379,     0,     0,   379,
       0,     0,     0,     0,     0,   379,   379,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   379,
     379,   274,   275,    74,   276,   338,     0,     0,   379,   379,
       0,     0,     7,    76,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    77,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    63,    64,     0,     0,    65,     0,
       0,     0,    66,     0,     0,     0,     0,    68,     0,     0,
      69,     0,    70,   273,     0,    71,    72,    73,     0,   213,
     214,   215,   216,   217,   218,     0,     0,     0,     0,     0,
       0,     0,     0,   219,   220,   221,   222,   223,   224,   225,
       0,   226,     0,     0,     0,     0,     0,   274,   275,    74,
     276,     0,     0,     0,   227,     0,     0,   228,     7,    76,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      77,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      63,    64,     0,     0,    65,   363,   364,     0,    66,     0,
       0,    67,     0,    68,     0,     0,    69,     0,    70,     0,
       0,    71,    72,    73,     0,     0,     0,     0,     0,     0,
       0,    63,    64,     0,     0,    65,   363,   364,     0,    66,
       0,     0,    67,     0,    68,     0,     0,    69,     0,    70,
       0,     0,    71,    72,    73,    74,     0,   394,     0,     0,
       0,     0,     0,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    74,     0,   396,     0,
       0,     0,     0,     0,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    63,    64,     0,
       0,    65,   363,   364,     0,    66,     0,     0,    67,     0,
      68,     0,     0,    69,     0,    70,     0,     0,    71,    72,
      73,     0,     0,     0,     0,     0,     0,     0,    63,    64,
       0,     0,    65,   363,   364,     0,    66,     0,     0,    67,
       0,    68,     0,     0,    69,     0,    70,     0,     0,    71,
      72,    73,    74,     0,   407,     0,     0,     0,     0,     0,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    74,     0,   408,     0,     0,     0,     0,
       0,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    63,    64,     0,     0,    65,   363,
     364,     0,    66,     0,     0,    67,     0,    68,     0,     0,
      69,     0,    70,     0,     0,    71,    72,    73,     0,     0,
       0,     0,     0,     0,     0,    63,    64,     0,     0,    65,
       0,     0,     0,    66,     0,     0,    67,     0,    68,     0,
       0,    69,     0,    70,     0,     0,    71,    72,    73,    74,
       0,   411,     0,     0,     0,     0,     0,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      74,    75,   154,     0,     0,     0,     0,     0,     0,     7,
      76,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    77,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    63,    64,     0,     0,    65,     0,     0,     0,    66,
       0,     0,    67,     0,    68,     0,     0,    69,     0,    70,
       0,     0,    71,    72,    73,     0,     0,     0,     0,     0,
       0,     0,    63,    64,     0,     0,    65,   363,   364,     0,
      66,     0,     0,    67,     0,    68,     0,     0,    69,     0,
      70,     0,     0,    71,    72,    73,    74,    75,   196,     0,
       0,     0,     0,     0,     0,     7,    76,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    77,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    63,    64,
       0,     0,    65,     0,     0,     0,    66,     0,     0,    67,
       0,    68,     0,     0,    69,     0,    70,     0,     0,    71,
      72,    73,     0,     0,     0,     0,     0,     0,     0,    63,
      64,     0,     0,    65,     0,     0,     0,     0,     0,     0,
       0,     0,    68,     0,     0,     0,     0,    70,     0,     0,
      71,     0,    73,    74,    75,     0,     0,     0,     0,     0,
       0,     0,     7,    76,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    77,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    74,   258,    70,     0,     6,     0,
       0,     0,     0,   259,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,   260,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     0,     0,    70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,   175,    70,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   213,   214,   215,   216,   217,   218,     0,
       0,     0,     0,     0,     0,     0,     0,   219,   220,   221,
     222,   223,   224,   225,     0,   226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   228
};

static const yytype_int16 yycheck[] =
{
       1,   204,    23,    52,    52,    52,   304,    59,    58,    96,
     344,    24,    52,    52,    52,   258,   336,    69,   261,   262,
     263,   264,   265,   266,   267,   268,    75,    75,    75,    56,
      56,    24,    23,   172,    58,    75,    75,    75,   166,   166,
      55,    55,    57,    88,   276,    58,    58,    96,    96,    96,
      64,    52,   386,   387,    58,   105,    96,    96,    96,   146,
      24,   293,   114,    51,   203,    58,     5,     6,    89,    60,
      58,   123,   124,   276,    75,   409,   103,   103,    52,   399,
     208,   208,    52,    58,    55,   137,   384,   136,    56,    51,
     293,    57,   144,    64,    58,    96,    58,   146,   146,   146,
     377,    75,    51,   380,    55,    75,   146,   146,   146,    58,
      55,   354,    57,    64,    58,   167,    59,   169,    73,    74,
      55,    56,    96,   400,   401,    59,    96,    57,    83,    84,
      55,    52,    34,   410,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,   146,   195,   199,   200,    63,
      12,    55,    56,   202,    75,   204,    52,   204,    56,    57,
      55,    56,    24,    55,   204,   204,   204,    58,    57,    50,
      58,    58,   146,    63,    58,    96,   146,    63,    63,    75,
     232,    61,    89,   235,    58,    33,    48,   239,    50,    51,
      52,    53,    54,    57,    61,    58,    58,    58,    56,    61,
      96,    56,    55,   204,    58,    52,    58,    56,    34,   258,
      54,    57,   261,   262,   263,   264,   265,   266,   267,   268,
      63,    57,    56,    33,    57,   146,    57,   276,    75,   276,
     204,    34,    24,    34,   204,    63,   276,   276,   276,    63,
      58,    63,    59,    59,   293,    56,   293,    34,    50,    96,
     146,    64,    64,   293,   293,   293,    48,    34,    50,    51,
      52,    53,    54,    56,    50,    62,    58,    58,    15,    61,
      65,    56,    62,    57,    57,   276,    35,    36,    37,    38,
      39,    40,   331,   204,    56,    33,    56,    56,    64,   341,
     342,    64,   293,    58,   343,   344,   343,   344,    58,   146,
      33,    52,   276,    60,    62,   354,   276,    34,   204,    33,
      34,    35,    36,    37,    38,    39,    40,    59,    59,   293,
      56,    50,    17,   293,    75,    60,    58,    34,   377,    34,
     377,   380,    60,   380,    59,    58,    57,   386,   387,   386,
     387,    57,   343,   344,    59,    96,    13,    13,    56,    59,
      56,   400,   401,   400,   401,   276,    56,   204,    56,    56,
     409,   410,   409,   410,   341,    64,   208,   345,   297,   343,
     344,   125,   293,   343,   344,   125,   377,   383,   306,   380,
     276,   180,   190,   198,   349,   386,   387,   311,   248,     1,
      39,    75,   103,    -1,   162,   146,    -1,   293,    -1,   400,
     401,    -1,    -1,   377,    -1,    -1,   380,   377,   409,   410,
     380,    -1,   386,   387,    -1,    -1,   386,   387,    -1,    -1,
      -1,    -1,   343,   344,    -1,    -1,   400,   401,    -1,   276,
     400,   401,    -1,    -1,    -1,   409,   410,    -1,    -1,   409,
     410,    -1,    -1,    -1,    -1,    -1,   293,   343,   344,    -1,
      -1,    -1,    -1,   204,    -1,    -1,   377,    -1,    -1,   380,
      -1,    -1,    -1,    -1,    -1,   386,   387,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,
     401,   377,    -1,    -1,   380,    -1,    -1,    -1,   409,   410,
     386,   387,    -1,    -1,    -1,    -1,   343,   344,     0,    -1,
      -1,    -1,    -1,    -1,   400,   401,    -1,    -1,    10,    -1,
      -1,    -1,    -1,   409,   410,    -1,    -1,    -1,    20,    21,
      -1,    23,    -1,    -1,    -1,   276,    -1,    -1,    -1,    -1,
     377,    -1,    -1,   380,    -1,    -1,    -1,    -1,    -1,   386,
     387,    -1,   293,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   400,   401,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   409,   410,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    -1,    -1,
      -1,    -1,   343,   344,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,     7,    -1,    -1,    -1,    11,    -1,    -1,    -1,
      -1,    16,    -1,    -1,    19,    -1,    21,    22,    -1,    24,
      25,    26,    -1,    -1,    -1,    -1,   377,    -1,    -1,   380,
      -1,    -1,    -1,    -1,    -1,   386,   387,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,
     401,    56,    57,    58,    59,    60,    -1,    -1,   409,   410,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     3,     4,    -1,    -1,     7,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    -1,    16,    -1,    -1,
      19,    -1,    21,    22,    -1,    24,    25,    26,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    -1,    -1,    62,    -1,    -1,    65,    67,    68,
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
      -1,    -1,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,
      -1,    19,    -1,    21,    -1,    -1,    24,    25,    26,    58,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     3,     4,    -1,    -1,     7,    -1,    -1,    -1,    11,
      -1,    -1,    14,    -1,    16,    -1,    -1,    19,    -1,    21,
      -1,    -1,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    -1,     7,     8,     9,    -1,
      11,    -1,    -1,    14,    -1,    16,    -1,    -1,    19,    -1,
      21,    -1,    -1,    24,    25,    26,    58,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    58,    -1,    -1,
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
      85,    86,    87,    88,    58,    59,    21,    -1,    23,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    58,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    96,     0,    10,    20,    21,    23,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   102,
     103,   104,   105,   106,   107,   108,   109,   147,   149,   150,
     154,   162,    58,    88,    23,    89,    58,    58,   110,    58,
     111,    56,    59,   151,   151,    57,    59,    58,    57,    34,
      55,    63,    55,     3,     4,     7,    11,    14,    16,    19,
      21,    24,    25,    26,    58,    59,    68,    79,   106,   113,
     114,   115,   117,   118,   120,   122,   123,   130,   133,   135,
     137,   138,   140,   143,   144,   152,   153,   160,   167,    58,
     148,   107,   108,   163,   164,    57,   148,    48,    50,    51,
      52,    53,    54,    58,    61,    97,    99,   101,   133,    58,
      50,   112,    58,    63,    63,    63,    58,    51,    58,   129,
      61,   101,    58,    33,   139,    57,    33,    34,    35,    36,
      37,    38,    39,    40,    91,   161,   153,    58,    58,    56,
      56,     5,     6,   126,    60,   152,    55,   155,    58,    58,
     149,   164,   165,   166,    56,   148,    57,    61,   101,    34,
      55,    64,    63,   101,   101,    58,   109,   113,   116,    57,
      57,    54,    56,    57,    51,    58,    57,    51,    58,   142,
     145,    58,   133,   101,   101,    33,    60,    34,    34,    63,
      63,    58,    59,    63,    59,    56,    60,   166,    57,    95,
     102,   104,   101,    27,    28,    29,    30,    31,    32,    41,
      42,    43,    44,    45,    46,    47,    49,    62,    65,    92,
      93,    94,    98,   101,    50,    34,   112,    64,    64,    56,
      50,   129,    62,    12,   101,   132,   134,    58,    65,   146,
     139,    58,   133,    15,   136,   136,   101,   101,    59,    67,
      78,   106,   115,   117,   122,   133,   138,   144,   156,   157,
     160,   167,   112,    22,    56,    57,    59,   106,   115,   117,
     122,   131,   133,   135,   137,   138,   140,   143,   144,   160,
     167,   168,   169,   170,    95,    62,   100,   101,   101,    64,
     124,   121,   101,    57,    57,    56,    55,    56,    55,    56,
     141,   142,    56,    33,    56,    56,    64,    64,   157,    58,
      58,   157,   157,   157,   157,   157,   157,   157,   157,    60,
      64,    33,    73,    74,    83,    84,   128,   169,    60,   169,
      62,    98,    34,    59,    59,    56,    50,   128,   132,    58,
     146,    17,   125,   127,    60,    34,    34,    58,   133,   131,
      60,   100,   101,     8,     9,   106,   115,   117,   122,   130,
     133,   135,   138,   140,   143,   144,   158,   159,   160,   167,
     159,    58,   114,    57,    57,   141,    59,    59,   157,    13,
      13,    56,    56,    56,    60,   158,    60,    64,   134,   128,
     159,   159,    56,    56,   119,    56,   131,    60,    60,    59,
     159,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    91,    91,    91,    91,    91,    92,    92,
      92,    92,    92,    92,    93,    93,    93,    93,    93,    93,
      94,    94,    95,    95,    96,    96,    96,    96,    96,    97,
      97,    98,    98,    98,    98,    99,    99,    99,    99,    99,
     100,   100,   101,   101,   101,   101,   101,   102,   102,   102,
     102,   102,   102,   103,   103,   103,   103,   103,   104,   104,
     104,   104,   104,   105,   105,   105,   105,   105,   106,   107,
     107,   107,   107,   108,   108,   109,   109,   110,   110,   110,
     110,   111,   111,   111,   111,   112,   112,   113,   114,   115,
     115,   116,   116,   117,   117,   119,   118,   121,   120,   122,
     124,   123,   125,   123,   127,   126,   126,   128,   128,   128,
     128,   129,   129,   130,   131,   131,   132,   133,   134,   134,
     134,   135,   136,   137,   137,   138,   139,   139,   139,   140,
     141,   141,   142,   142,   143,   144,   145,   146,   146,   147,
     147,   148,   148,   149,   150,   151,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   153,   153,   155,   154,   156,   156,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   159,   159,   160,   161,   161,   162,   163,
     163,   164,   164,   165,   165,   166,   167,   167,   168,   168,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   170,   170
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
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     2,     1,     1,     2,     2,     1,     3,     3,
       5,     4,     6,     6,     8,     3,     1,     3,     3,     2,
       2,     1,     1,     1,     1,     0,    12,     0,     8,     2,
       0,     8,     0,     9,     0,     8,     0,     1,     1,     1,
       1,     1,     1,     9,     3,     1,     1,     5,     1,     3,
       1,     9,     3,     5,     5,     5,     2,     2,     0,     5,
       3,     1,     1,     1,     3,     5,     2,     3,     0,     2,
       2,     1,     3,     6,     7,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     2,     0,     8,     5,     5,     2,     2,     2,
       2,     2,     2,     2,     4,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     2,     2,     2,     3,     6,     2,
       3,     2,     5,     1,     2,     4,     3,     4,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     2
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
  case 68:
#line 107 "bison.y"
                                        { fprintf(yyout, " : declaration statement"); }
#line 1928 "bison.tab.c"
    break;

  case 89:
#line 142 "bison.y"
                                    { fprintf(yyout, " : assignment statement");  }
#line 1934 "bison.tab.c"
    break;

  case 90:
#line 143 "bison.y"
                                     { fprintf(yyout, " : expression statement");  }
#line 1940 "bison.tab.c"
    break;

  case 95:
#line 154 "bison.y"
                                                                                                   {fprintf(yyout, " : loop statement");}
#line 1946 "bison.tab.c"
    break;

  case 97:
#line 157 "bison.y"
                                               {fprintf(yyout, " : loop statement");}
#line 1952 "bison.tab.c"
    break;

  case 100:
#line 165 "bison.y"
                                                { fprintf(yyout, " : conditional statement");  }
#line 1958 "bison.tab.c"
    break;

  case 102:
#line 166 "bison.y"
                                                                    { fprintf(yyout, " : conditional statement");  }
#line 1964 "bison.tab.c"
    break;

  case 104:
#line 170 "bison.y"
                                                 { fprintf(yyout, " : conditional statement");  }
#line 1970 "bison.tab.c"
    break;

  case 115:
#line 181 "bison.y"
                                                                          { fprintf(yyout, " : analyze statement");  }
#line 1976 "bison.tab.c"
    break;

  case 117:
#line 188 "bison.y"
                                                         { fprintf(yyout, " : call statement");  }
#line 1982 "bison.tab.c"
    break;

  case 121:
#line 198 "bison.y"
                                                                                                           { fprintf(yyout, " : call statement");  }
#line 1988 "bison.tab.c"
    break;

  case 123:
#line 203 "bison.y"
                                                       { fprintf(yyout, " : get statement");  }
#line 1994 "bison.tab.c"
    break;

  case 124:
#line 204 "bison.y"
                                                       { fprintf(yyout, " : get statement");  }
#line 2000 "bison.tab.c"
    break;

  case 125:
#line 209 "bison.y"
                                                          { fprintf(yyout, " : sleep statement");  }
#line 2006 "bison.tab.c"
    break;

  case 131:
#line 224 "bison.y"
     { 
      fprintf(yyout, " : scan statement");
     }
#line 2014 "bison.tab.c"
    break;

  case 134:
#line 234 "bison.y"
                                        { fprintf(yyout, " : return statement"); }
#line 2020 "bison.tab.c"
    break;

  case 135:
#line 238 "bison.y"
       { 
        fprintf(yyout, " : print statement");
       }
#line 2028 "bison.tab.c"
    break;

  case 143:
#line 255 "bison.y"
                                                                            { fprintf(yyout, " : function declaration statement"); }
#line 2034 "bison.tab.c"
    break;

  case 144:
#line 256 "bison.y"
                                                                                      { fprintf(yyout, " : function declaration statement"); }
#line 2040 "bison.tab.c"
    break;

  case 163:
#line 282 "bison.y"
                                      { fprintf(yyout, " : task declaration statement"); }
#line 2046 "bison.tab.c"
    break;


#line 2050 "bison.tab.c"

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
#line 380 "bison.y"


void yyerror(std::string s){
  std::cout << "Syntax Error: " << s << " at line number - " << yylineno << std::endl;
}
