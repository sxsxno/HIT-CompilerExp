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
#line 2 "syntax.y"

    #include<stdio.h>
    #include"main.h"
    int yycolumn = 1;
    #define YY_USER_ACTION \
        yylloc.first_line = yylloc.last_line = yylineno; \
        yylloc.first_column = yycolumn; \
        yylloc.last_column = yycolumn + yyleng - 1; \
        yycolumn += yyleng;
    int yydebug = 1;

#line 82 "syntax.tab.c"

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
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    SEMI = 260,
    COMMA = 261,
    TYPE = 262,
    STRUCT = 263,
    LC = 264,
    RC = 265,
    ID = 266,
    LB = 267,
    RB = 268,
    RETURN = 269,
    IF = 270,
    WHILE = 271,
    ASSIGNOP = 272,
    AND = 273,
    OR = 274,
    RELOP = 275,
    PLUS = 276,
    MINUS = 277,
    STAR = 278,
    NOT = 279,
    DOT = 280,
    LP = 281,
    RP = 282,
    ELSE = 283,
    DIV = 284
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "syntax.y"

    treeNode node_;

#line 168 "syntax.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */



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
typedef yytype_uint8 yy_state_t;

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   296

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

#define YYUNDEFTOK  2
#define YYMAXUTOK   284


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
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    37,    37,    39,    40,    42,    43,    44,    45,    46,
      47,    49,    50,    51,    53,    54,    56,    57,    60,    61,
      64,    67,    68,    69,    70,    73,    74,    75,    76,    79,
      80,    82,    84,    85,    88,    89,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   103,   104,   106,   107,
     108,   110,   111,   113,   114,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   135,   136
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "SEMI", "COMMA", "TYPE",
  "STRUCT", "LC", "RC", "ID", "LB", "RB", "RETURN", "IF", "WHILE",
  "ASSIGNOP", "AND", "OR", "RELOP", "PLUS", "MINUS", "STAR", "NOT", "DOT",
  "LP", "RP", "ELSE", "DIV", "$accept", "Program", "ExtDefList", "ExtDef",
  "ExtDecList", "Specifier", "StructSpecifier", "OptTag", "Tag", "VarDec",
  "FunDec", "VarList", "ParamDec", "CompSt", "StmtList", "Stmt", "DefList",
  "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284
};
# endif

#define YYPACT_NINF (-70)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-36)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     288,   135,   -70,    42,    63,   -70,   277,    11,   -70,   -70,
      96,    89,   102,   -70,   -70,   -70,    13,   -70,    90,   127,
      72,    48,   -70,    73,   -70,   -70,    73,     0,   -70,    78,
      12,    43,   129,    73,   -70,    49,   131,    73,    12,   117,
     140,   121,   -70,   123,   -70,   139,   -70,   -70,   144,   150,
     -70,    93,   101,     2,    23,   165,   -70,   -70,   166,   -70,
      73,   -70,   -70,   -70,   -70,    95,   -70,   -70,   160,   125,
     164,   174,   151,   151,   151,   -70,   182,    93,    47,   -70,
     151,   -70,   -70,    12,   -70,   -70,   134,   199,    70,   151,
     151,    33,    30,   162,   -70,   -70,   201,   -70,   151,   151,
     151,   151,   151,   151,   151,   151,   203,   151,   222,   -70,
     -70,   147,   189,   -70,   -70,   -70,   176,   190,   -70,   -70,
     208,   222,   246,   234,   258,    33,    33,    30,   -70,    30,
     151,   -70,   109,   109,   -70,   -70,   194,   -70,   109,   -70
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    14,    19,     0,     2,     0,     0,    15,     9,
       0,    20,     0,    17,     1,     3,     0,     6,    21,     0,
       0,     0,    10,    47,     8,    24,     0,     0,     5,     0,
       0,     0,     0,    47,     7,     0,     0,    47,     0,     0,
      30,     0,    26,     0,    13,     0,    21,    12,     0,     0,
      33,     0,     0,    53,     0,    51,    16,    46,    31,    28,
       0,    27,    25,    23,    22,     0,    71,    72,    70,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,    49,
       0,    50,    48,     0,    29,    42,     0,     0,     0,     0,
       0,    64,    65,     0,    32,    34,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,    52,
      67,    74,     0,    45,    44,    38,     0,     0,    63,    43,
       0,    55,    56,    57,    58,    59,    60,    61,    69,    62,
       0,    66,     0,     0,    68,    73,    39,    41,     0,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -70,    -4,   -70,   188,    14,   -70,   -70,   -70,   -29,
     -70,   -17,   -70,   202,   155,   -11,    97,   -70,   141,   -70,
     -69,   105
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    19,     7,     8,    12,    13,    20,
      21,    39,    40,    75,    76,    77,    36,    37,    54,    55,
      78,   112
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      88,    41,    15,    91,    92,    93,    53,     2,     3,    58,
      43,   108,    16,    45,    31,    10,    17,   111,    24,    80,
     116,   117,    18,    46,    81,    44,    25,    42,    82,   120,
     121,   122,   123,   124,   125,   126,   127,    35,   129,    26,
      38,    38,    98,    84,    48,    98,    49,    35,    96,    32,
      52,    35,    97,    11,    53,   106,   105,    33,   106,    98,
      46,   111,   107,    14,    99,   100,   101,   102,   103,   104,
     105,   114,   106,    29,    38,   115,   107,   -11,    30,     1,
       2,     3,    98,    -4,    31,     2,     3,    99,   100,   101,
     102,   103,   104,   105,    65,   106,    66,    67,   -18,   107,
      85,    22,    33,   -35,    68,    50,    79,    69,    70,    71,
      65,    23,    66,    67,    25,    72,    27,    73,    33,    74,
      68,   136,   137,    69,    70,    71,    87,   139,    66,    67,
      51,    72,    28,    73,    57,    74,    68,    66,    67,    50,
       9,    56,     2,     3,    59,    68,    60,    72,    61,    73,
      62,    74,    25,   130,    66,    67,    72,    63,    73,    98,
      74,   110,    68,    64,    99,   100,   101,   102,   103,   104,
     105,    83,   106,    72,    98,    73,   107,    74,    31,    99,
     100,   101,   102,   103,   104,   105,    86,   106,    98,   118,
      89,   107,    94,    99,   100,   101,   102,   103,   104,   105,
      90,   106,    98,   132,   113,   107,   119,    99,   100,   101,
     102,   103,   104,   105,   128,   106,   131,   133,    47,   107,
      98,   134,   138,    34,   109,    99,   100,   101,   102,   103,
     104,   105,    95,   106,    98,   135,     0,   107,     0,    99,
     100,   101,   102,   103,   104,   105,    98,   106,     0,     0,
       0,   107,   100,     0,   102,   103,   104,   105,    98,   106,
       0,     0,     0,   107,     0,     0,   102,   103,   104,   105,
      98,   106,     0,     0,     0,   107,     0,    -4,     1,   103,
     104,   105,    -4,   106,     2,     3,     0,   107,    -4,     1,
       0,     0,     0,     0,     0,     2,     3
};

static const yytype_int16 yycheck[] =
{
      69,     1,     6,    72,    73,    74,    35,     7,     8,    38,
      27,    80,     1,     1,    12,     1,     5,    86,     5,    17,
      89,    90,    11,    11,     1,    29,    13,    27,     5,    98,
      99,   100,   101,   102,   103,   104,   105,    23,   107,    26,
      26,    27,    12,    60,     1,    12,     3,    33,     1,     1,
       1,    37,     5,    11,    83,    25,    23,     9,    25,    12,
      11,   130,    29,     0,    17,    18,    19,    20,    21,    22,
      23,     1,    25,     1,    60,     5,    29,     5,     6,     1,
       7,     8,    12,     5,    12,     7,     8,    17,    18,    19,
      20,    21,    22,    23,     1,    25,     3,     4,     9,    29,
       5,     5,     9,    10,    11,    10,     5,    14,    15,    16,
       1,     9,     3,     4,    13,    22,    26,    24,     9,    26,
      11,   132,   133,    14,    15,    16,     1,   138,     3,     4,
      33,    22,     5,    24,    37,    26,    11,     3,     4,    10,
       5,    10,     7,     8,    27,    11,     6,    22,    27,    24,
      27,    26,    13,     6,     3,     4,    22,    13,    24,    12,
      26,    27,    11,    13,    17,    18,    19,    20,    21,    22,
      23,     6,    25,    22,    12,    24,    29,    26,    12,    17,
      18,    19,    20,    21,    22,    23,    26,    25,    12,    27,
      26,    29,    10,    17,    18,    19,    20,    21,    22,    23,
      26,    25,    12,    27,     5,    29,     5,    17,    18,    19,
      20,    21,    22,    23,    11,    25,    27,    27,    30,    29,
      12,    13,    28,    21,    83,    17,    18,    19,    20,    21,
      22,    23,    77,    25,    12,   130,    -1,    29,    -1,    17,
      18,    19,    20,    21,    22,    23,    12,    25,    -1,    -1,
      -1,    29,    18,    -1,    20,    21,    22,    23,    12,    25,
      -1,    -1,    -1,    29,    -1,    -1,    20,    21,    22,    23,
      12,    25,    -1,    -1,    -1,    29,    -1,     0,     1,    21,
      22,    23,     5,    25,     7,     8,    -1,    29,     0,     1,
      -1,    -1,    -1,    -1,    -1,     7,     8
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     7,     8,    31,    32,    33,    35,    36,     5,
      35,    11,    37,    38,     0,    32,     1,     5,    11,    34,
      39,    40,     5,     9,     5,    13,    26,    26,     5,     1,
       6,    12,     1,     9,    43,    35,    46,    47,    35,    41,
      42,     1,    27,    41,    32,     1,    11,    34,     1,     3,
      10,    46,     1,    39,    48,    49,    10,    46,    39,    27,
       6,    27,    27,    13,    13,     1,     3,     4,    11,    14,
      15,    16,    22,    24,    26,    43,    44,    45,    50,     5,
      17,     1,     5,     6,    41,     5,    26,     1,    50,    26,
      26,    50,    50,    50,    10,    44,     1,     5,    12,    17,
      18,    19,    20,    21,    22,    23,    25,    29,    50,    48,
      27,    50,    51,     5,     1,     5,    50,    50,    27,     5,
      50,    50,    50,    50,    50,    50,    50,    50,    11,    50,
       6,    27,    27,    27,    13,    51,    45,    45,    28,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    33,    33,    33,
      33,    34,    34,    34,    35,    35,    36,    36,    37,    37,
      38,    39,    39,    39,    39,    40,    40,    40,    40,    41,
      41,    42,    43,    43,    44,    44,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    46,    46,    47,    47,
      47,    48,    48,    49,    49,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    51,    51
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     3,     2,
       3,     1,     3,     3,     1,     1,     5,     2,     1,     0,
       1,     1,     4,     4,     2,     4,     3,     4,     4,     3,
       1,     2,     4,     2,     2,     0,     2,     1,     3,     5,
       7,     5,     2,     3,     3,     3,     2,     0,     3,     3,
       3,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     4,     3,     4,     3,
       1,     1,     1,     3,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 37 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Program");treeNode N_list[1]={(yyvsp[0].node_)};link_node((yyval.node_),1,N_list);if(is_wrong==0) print_tree((yyval.node_),0); }
#line 1574 "syntax.tab.c"
    break;

  case 3:
#line 39 "syntax.y"
                                { (yyval.node_) = make_node(yylineno,-1,"ExtDefList");treeNode N_list[2]={(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),2,N_list); }
#line 1580 "syntax.tab.c"
    break;

  case 4:
#line 40 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"ExtDefList");}
#line 1586 "syntax.tab.c"
    break;

  case 5:
#line 42 "syntax.y"
                                   { (yyval.node_) = make_node(yylineno,-1,"ExtDef");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1592 "syntax.tab.c"
    break;

  case 6:
#line 43 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"ExtDef");treeNode N_list[2]={(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),2,N_list); }
#line 1598 "syntax.tab.c"
    break;

  case 7:
#line 44 "syntax.y"
                              { (yyval.node_) = make_node(yylineno,-1,"ExtDef");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1604 "syntax.tab.c"
    break;

  case 8:
#line 45 "syntax.y"
                           { is_wrong=1;(yyval.node_) = make_node(yylineno,-1,"ExtDef");printf("Error type B at line %d : Missing character\n",yylloc.first_line); }
#line 1610 "syntax.tab.c"
    break;

  case 9:
#line 46 "syntax.y"
                  { is_wrong=1;(yyval.node_) = make_node(yylineno,-1,"ExtDef");printf("Error type B at line %d : Missing character\n",yylloc.first_line); }
#line 1616 "syntax.tab.c"
    break;

  case 10:
#line 47 "syntax.y"
                           { is_wrong=1;(yyval.node_) = make_node(yylineno,-1,"ExtDef");printf("Error type B at line %d : Missing character\n",yylloc.first_line); }
#line 1622 "syntax.tab.c"
    break;

  case 11:
#line 49 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"ExtDecList");treeNode N_list[1]={(yyvsp[0].node_)};link_node((yyval.node_),1,N_list); }
#line 1628 "syntax.tab.c"
    break;

  case 12:
#line 50 "syntax.y"
                                { (yyval.node_) = make_node(yylineno,-1,"ExtDecList");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1634 "syntax.tab.c"
    break;

  case 13:
#line 51 "syntax.y"
                              { is_wrong=1;printf("Error type B at line %d : Missing character\n",yylloc.first_line); }
#line 1640 "syntax.tab.c"
    break;

  case 14:
#line 53 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Specifier");treeNode N_list[1]={(yyvsp[0].node_)};link_node((yyval.node_),1,N_list); }
#line 1646 "syntax.tab.c"
    break;

  case 15:
#line 54 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Specifier");treeNode N_list[1]={(yyvsp[0].node_)};link_node((yyval.node_),1,N_list); }
#line 1652 "syntax.tab.c"
    break;

  case 16:
#line 56 "syntax.y"
                                              { (yyval.node_) = make_node(yylineno,-1,"StructSpecifier");treeNode N_list[5]={(yyvsp[-4].node_),(yyvsp[-3].node_),(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),5,N_list); }
#line 1658 "syntax.tab.c"
    break;

  case 17:
#line 57 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"StructSpecifier");treeNode N_list[2]={(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),2,N_list); }
#line 1664 "syntax.tab.c"
    break;

  case 18:
#line 60 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"OptTag");treeNode N_list[1]={(yyvsp[0].node_)};link_node((yyval.node_),1,N_list); }
#line 1670 "syntax.tab.c"
    break;

  case 19:
#line 61 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"OptTag");}
#line 1676 "syntax.tab.c"
    break;

  case 20:
#line 64 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Tag");treeNode N_list[1]={(yyvsp[0].node_)};link_node((yyval.node_),1,N_list); }
#line 1682 "syntax.tab.c"
    break;

  case 21:
#line 67 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"VarDec");treeNode N_list[1]={(yyvsp[0].node_)};link_node((yyval.node_),1,N_list); }
#line 1688 "syntax.tab.c"
    break;

  case 22:
#line 68 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"VarDec");treeNode N_list[4]={(yyvsp[-3].node_),(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),4,N_list); }
#line 1694 "syntax.tab.c"
    break;

  case 23:
#line 69 "syntax.y"
                         { is_wrong=1;printf("Error type B at line %d : Missing character\n",yylloc.first_line); }
#line 1700 "syntax.tab.c"
    break;

  case 24:
#line 70 "syntax.y"
               { is_wrong=1;printf("Error type B at line %d : Missing character\n",yylloc.first_line); }
#line 1706 "syntax.tab.c"
    break;

  case 25:
#line 73 "syntax.y"
                          { (yyval.node_) = make_node(yylineno,-1,"FunDec");treeNode N_list[4]={(yyvsp[-3].node_),(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),4,N_list); }
#line 1712 "syntax.tab.c"
    break;

  case 26:
#line 74 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"FunDec");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1718 "syntax.tab.c"
    break;

  case 27:
#line 75 "syntax.y"
                     { is_wrong=1;printf("Error type B at line %d : Missing character\n",yylloc.first_line); }
#line 1724 "syntax.tab.c"
    break;

  case 28:
#line 76 "syntax.y"
                          { is_wrong=1;printf("Error type B at line %d : Missing character\n",yylloc.first_line); }
#line 1730 "syntax.tab.c"
    break;

  case 29:
#line 79 "syntax.y"
                                 { (yyval.node_) = make_node(yylineno,-1,"VarList");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1736 "syntax.tab.c"
    break;

  case 30:
#line 80 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"VarList");treeNode N_list[1]={(yyvsp[0].node_)};link_node((yyval.node_),1,N_list); }
#line 1742 "syntax.tab.c"
    break;

  case 31:
#line 82 "syntax.y"
                            { (yyval.node_) = make_node(yylineno,-1,"ParamDec");treeNode N_list[2]={(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),2,N_list); }
#line 1748 "syntax.tab.c"
    break;

  case 32:
#line 84 "syntax.y"
                                { (yyval.node_) = make_node(yylineno,-1,"CompSt");treeNode N_list[4]={(yyvsp[-3].node_),(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),4,N_list); }
#line 1754 "syntax.tab.c"
    break;

  case 33:
#line 85 "syntax.y"
               { is_wrong=1;(yyval.node_) = make_node(yylineno,-1,"CompSt");printf("Error type B at line %d : Missing character\n",yylloc.first_line); }
#line 1760 "syntax.tab.c"
    break;

  case 34:
#line 88 "syntax.y"
                         { (yyval.node_) = make_node(yylineno,-1,"StmtList");treeNode N_list[2]={(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),2,N_list); }
#line 1766 "syntax.tab.c"
    break;

  case 35:
#line 89 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"StmtList");}
#line 1772 "syntax.tab.c"
    break;

  case 36:
#line 91 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Stmt");treeNode N_list[2]={(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),2,N_list); }
#line 1778 "syntax.tab.c"
    break;

  case 37:
#line 92 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Stmt");treeNode N_list[1]={(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1784 "syntax.tab.c"
    break;

  case 38:
#line 93 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Stmt");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1790 "syntax.tab.c"
    break;

  case 39:
#line 94 "syntax.y"
                         { (yyval.node_) = make_node(yylineno,-1,"Stmt");treeNode N_list[5]={(yyvsp[-4].node_),(yyvsp[-3].node_),(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),5,N_list); }
#line 1796 "syntax.tab.c"
    break;

  case 40:
#line 95 "syntax.y"
                                  { (yyval.node_) = make_node(yylineno,-1,"Stmt");treeNode N_list[7]={(yyvsp[-6].node_),(yyvsp[-5].node_),(yyvsp[-4].node_),(yyvsp[-3].node_),(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),7,N_list); }
#line 1802 "syntax.tab.c"
    break;

  case 41:
#line 96 "syntax.y"
                           { (yyval.node_) = make_node(yylineno,-1,"Stmt");treeNode N_list[5]={(yyvsp[-4].node_),(yyvsp[-3].node_),(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),5,N_list); }
#line 1808 "syntax.tab.c"
    break;

  case 42:
#line 97 "syntax.y"
                    { is_wrong=1;(yyval.node_) = make_node(yylineno,-1,"CompSt");printf("Error type B at line %d : Missing character\n",yylloc.first_line); }
#line 1814 "syntax.tab.c"
    break;

  case 43:
#line 98 "syntax.y"
                     { is_wrong=1;(yyval.node_) = make_node(yylineno,-1,"CompSt");printf("Error type B at line %d : Missing character\n",yylloc.first_line); }
#line 1820 "syntax.tab.c"
    break;

  case 44:
#line 99 "syntax.y"
                        { is_wrong=1;(yyval.node_) = make_node(yylineno,-1,"CompSt");printf("Error type B at line %d : Missing character\n",yylloc.first_line); }
#line 1826 "syntax.tab.c"
    break;

  case 45:
#line 100 "syntax.y"
                         { is_wrong=1;(yyval.node_) = make_node(yylineno,-1,"CompSt");printf("Error type B at line %d : Missing character\n",yylloc.first_line); }
#line 1832 "syntax.tab.c"
    break;

  case 46:
#line 103 "syntax.y"
                      { (yyval.node_) = make_node(yylineno,-1,"DefList");treeNode N_list[2]={(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),2,N_list); }
#line 1838 "syntax.tab.c"
    break;

  case 47:
#line 104 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"DefList");}
#line 1844 "syntax.tab.c"
    break;

  case 48:
#line 106 "syntax.y"
                              { (yyval.node_) = make_node(yylineno,-1,"Def");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1850 "syntax.tab.c"
    break;

  case 49:
#line 107 "syntax.y"
                           { is_wrong=1;(yyval.node_) = make_node(yylineno,-1,"CompSt");printf("Error type B at line %d : Missing character\n",yylloc.first_line); }
#line 1856 "syntax.tab.c"
    break;

  case 50:
#line 108 "syntax.y"
                              { is_wrong=1;(yyval.node_) = make_node(yylineno,-1,"CompSt");printf("Error type B at line %d : Missing character\n",yylloc.first_line); }
#line 1862 "syntax.tab.c"
    break;

  case 51:
#line 110 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"DecList");treeNode N_list[1]={(yyvsp[0].node_)};link_node((yyval.node_),1,N_list); }
#line 1868 "syntax.tab.c"
    break;

  case 52:
#line 111 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"DecList");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1874 "syntax.tab.c"
    break;

  case 53:
#line 113 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Dec");treeNode N_list[1]={(yyvsp[0].node_)};link_node((yyval.node_),1,N_list); }
#line 1880 "syntax.tab.c"
    break;

  case 54:
#line 114 "syntax.y"
                           { (yyval.node_) = make_node(yylineno,-1,"Dec");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1886 "syntax.tab.c"
    break;

  case 55:
#line 116 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Exp");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1892 "syntax.tab.c"
    break;

  case 56:
#line 117 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Exp");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1898 "syntax.tab.c"
    break;

  case 57:
#line 118 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Exp");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1904 "syntax.tab.c"
    break;

  case 58:
#line 119 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Exp");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1910 "syntax.tab.c"
    break;

  case 59:
#line 120 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Exp");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1916 "syntax.tab.c"
    break;

  case 60:
#line 121 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Exp");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1922 "syntax.tab.c"
    break;

  case 61:
#line 122 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Exp");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1928 "syntax.tab.c"
    break;

  case 62:
#line 123 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Exp");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1934 "syntax.tab.c"
    break;

  case 63:
#line 124 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Exp");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1940 "syntax.tab.c"
    break;

  case 64:
#line 125 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Exp");treeNode N_list[2]={(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),2,N_list); }
#line 1946 "syntax.tab.c"
    break;

  case 65:
#line 126 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Exp");treeNode N_list[2]={(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),2,N_list); }
#line 1952 "syntax.tab.c"
    break;

  case 66:
#line 127 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Exp");treeNode N_list[4]={(yyvsp[-3].node_),(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),4,N_list); }
#line 1958 "syntax.tab.c"
    break;

  case 67:
#line 128 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Exp");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1964 "syntax.tab.c"
    break;

  case 68:
#line 129 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Exp");treeNode N_list[4]={(yyvsp[-3].node_),(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),4,N_list); }
#line 1970 "syntax.tab.c"
    break;

  case 69:
#line 130 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Exp");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 1976 "syntax.tab.c"
    break;

  case 70:
#line 131 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Exp");treeNode N_list[1]={(yyvsp[0].node_)};link_node((yyval.node_),1,N_list); }
#line 1982 "syntax.tab.c"
    break;

  case 71:
#line 132 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Exp");treeNode N_list[1]={(yyvsp[0].node_)};link_node((yyval.node_),1,N_list); }
#line 1988 "syntax.tab.c"
    break;

  case 72:
#line 133 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Exp");treeNode N_list[1]={(yyvsp[0].node_)};link_node((yyval.node_),1,N_list); }
#line 1994 "syntax.tab.c"
    break;

  case 73:
#line 135 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Args");treeNode N_list[3]={(yyvsp[-2].node_),(yyvsp[-1].node_),(yyvsp[0].node_)};link_node((yyval.node_),3,N_list); }
#line 2000 "syntax.tab.c"
    break;

  case 74:
#line 136 "syntax.y"
                        { (yyval.node_) = make_node(yylineno,-1,"Args");treeNode N_list[1]={(yyvsp[0].node_)};link_node((yyval.node_),1,N_list); }
#line 2006 "syntax.tab.c"
    break;


#line 2010 "syntax.tab.c"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 138 "syntax.y"

#include"lex.yy.c"
yyerror(char* msg){
    return 0;
}
