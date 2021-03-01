/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     STRING_LITERAL = 258,
     INT_LITERAL = 259,
     FLOAT_LITERAL = 260,
     IDENTIFIER = 261,
     LOGICAL_OR = 262,
     LOGICAL_AND = 263,
     LSHIFT = 264,
     RSHIFT = 265,
     AMPXOR = 266,
     CHANNEL_ASSIGN = 267,
     REL_EQUAL = 268,
     REL_NEQUAL = 269,
     REL_LT = 270,
     REL_LEQ = 271,
     REL_GT = 272,
     REL_GEQ = 273,
     ADD_ASSIGN = 274,
     SUB_ASSIGN = 275,
     OR_ASSIGN = 276,
     XOR_ASSIGN = 277,
     MUL_ASSIGN = 278,
     DIV_ASSIGN = 279,
     MOD_ASSIGN = 280,
     AND_ASSIGN = 281,
     LSHIFT_ASSIGN = 282,
     RSHIFT_ASSIGN = 283,
     AMPXOR_ASSIGN = 284,
     INC_ASSIGN = 285,
     DEC_ASSIGN = 286,
     KEYWORD_PACKAGE = 287,
     KEYWORD_IMPORT = 288,
     KEYWORD_FUNC = 289,
     KEYWORD_CONST = 290,
     KEYWORD_TYPE = 291,
     KEYWORD_VAR = 292,
     KEYWORD_FOR = 293,
     KEYWORD_RANGE = 294,
     KEYWORD_DEFAULT = 295,
     KEYWORD_CASE = 296,
     KEYWORD_SWITCH = 297,
     SHORT_DECLARATION = 298,
     P_BOOL = 299,
     P_NIL = 300,
     P_TYPE = 301,
     P_FUNCTION = 302
   };
#endif
/* Tokens.  */
#define STRING_LITERAL 258
#define INT_LITERAL 259
#define FLOAT_LITERAL 260
#define IDENTIFIER 261
#define LOGICAL_OR 262
#define LOGICAL_AND 263
#define LSHIFT 264
#define RSHIFT 265
#define AMPXOR 266
#define CHANNEL_ASSIGN 267
#define REL_EQUAL 268
#define REL_NEQUAL 269
#define REL_LT 270
#define REL_LEQ 271
#define REL_GT 272
#define REL_GEQ 273
#define ADD_ASSIGN 274
#define SUB_ASSIGN 275
#define OR_ASSIGN 276
#define XOR_ASSIGN 277
#define MUL_ASSIGN 278
#define DIV_ASSIGN 279
#define MOD_ASSIGN 280
#define AND_ASSIGN 281
#define LSHIFT_ASSIGN 282
#define RSHIFT_ASSIGN 283
#define AMPXOR_ASSIGN 284
#define INC_ASSIGN 285
#define DEC_ASSIGN 286
#define KEYWORD_PACKAGE 287
#define KEYWORD_IMPORT 288
#define KEYWORD_FUNC 289
#define KEYWORD_CONST 290
#define KEYWORD_TYPE 291
#define KEYWORD_VAR 292
#define KEYWORD_FOR 293
#define KEYWORD_RANGE 294
#define KEYWORD_DEFAULT 295
#define KEYWORD_CASE 296
#define KEYWORD_SWITCH 297
#define SHORT_DECLARATION 298
#define P_BOOL 299
#define P_NIL 300
#define P_TYPE 301
#define P_FUNCTION 302




/* Copy the first part of user declarations.  */
#line 1 "yac.y"

void yyerror (char *s);
int yylex();
#include <stdio.h>     /* C declarations used in actions */
#include <stdlib.h>
#include <ctype.h>
int yylineno;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 10 "yac.y"
{char* str;}
/* Line 193 of yacc.c.  */
#line 201 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 214 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   455

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  162
/* YYNRULES -- Number of states.  */
#define YYNSTATES  251

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,     2,     2,    59,    60,     2,
      48,    49,    57,    53,    52,    54,    50,    58,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    67,    66,
       2,    51,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,    56,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,    55,    65,     2,     2,     2,     2,
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
      45,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    10,    12,    15,    17,    20,    25,
      28,    31,    33,    35,    38,    41,    44,    46,    48,    54,
      56,    58,    60,    63,    68,    70,    73,    76,    80,    82,
      84,    87,    89,    93,    96,    98,   100,   102,   106,   109,
     112,   117,   119,   122,   125,   128,   131,   133,   135,   139,
     141,   145,   147,   149,   151,   155,   157,   161,   165,   169,
     173,   177,   181,   183,   185,   187,   189,   191,   193,   195,
     197,   199,   201,   203,   205,   207,   209,   211,   213,   215,
     217,   219,   221,   223,   225,   227,   229,   231,   233,   235,
     237,   239,   241,   243,   245,   247,   249,   251,   254,   257,
     259,   261,   264,   268,   270,   272,   276,   278,   280,   282,
     284,   286,   288,   290,   292,   296,   299,   301,   303,   305,
     307,   309,   311,   313,   315,   317,   320,   323,   327,   331,
     335,   339,   341,   343,   345,   347,   349,   355,   357,   359,
     361,   363,   365,   367,   369,   373,   376,   379,   381,   383,
     385,   391,   394,   396,   400,   403,   405,   412,   420,   424,
     427,   429,   433
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      69,     0,    -1,    70,    72,    77,    -1,    32,    71,    -1,
       6,    -1,    73,    72,    -1,   142,    -1,    33,    76,    -1,
      33,    48,    74,    49,    -1,    76,    75,    -1,    76,    75,
      -1,   142,    -1,     3,    -1,    50,     3,    -1,    71,     3,
      -1,    78,    77,    -1,   142,    -1,    79,    -1,    34,     6,
      48,    49,   114,    -1,    80,    -1,    85,    -1,    91,    -1,
      35,    82,    -1,    35,    48,    81,    49,    -1,    82,    -1,
      81,    82,    -1,    96,    83,    -1,    84,    51,   100,    -1,
      97,    -1,   142,    -1,    36,    86,    -1,    88,    -1,    48,
      87,    49,    -1,    88,    87,    -1,   142,    -1,    89,    -1,
      90,    -1,     6,    51,    97,    -1,     6,    97,    -1,    37,
      92,    -1,    37,    48,    92,    49,    -1,    93,    -1,    92,
      93,    -1,    96,    94,    -1,    97,    95,    -1,    51,   100,
      -1,   142,    -1,     6,    -1,    96,    52,     6,    -1,    98,
      -1,    48,    97,    49,    -1,   142,    -1,    46,    -1,    99,
      -1,    71,    50,     6,    -1,   101,    -1,   100,    52,   101,
      -1,   101,     7,   101,    -1,   101,     8,   101,    -1,   101,
     102,   101,    -1,   101,   103,   101,    -1,   101,   104,   101,
      -1,   107,    -1,    13,    -1,    14,    -1,    15,    -1,    16,
      -1,    17,    -1,    18,    -1,    53,    -1,    54,    -1,    55,
      -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,     9,
      -1,    10,    -1,    60,    -1,    11,    -1,    53,    -1,    54,
      -1,    61,    -1,    56,    -1,    57,    -1,    60,    -1,    19,
      -1,    20,    -1,    21,    -1,    22,    -1,    23,    -1,    24,
      -1,    25,    -1,    26,    -1,    27,    -1,    28,    -1,    29,
      -1,    12,   107,    -1,   105,   107,    -1,   108,    -1,   110,
      -1,   108,   109,    -1,    62,   101,    63,    -1,   111,    -1,
     113,    -1,    48,   101,    49,    -1,    45,    -1,    44,    -1,
     112,    -1,     4,    -1,     5,    -1,     3,    -1,     6,    -1,
      47,    -1,    64,   115,    65,    -1,   115,   116,    -1,   142,
      -1,   117,    -1,    79,    -1,   121,    -1,   132,    -1,   101,
      -1,   118,    -1,   119,    -1,   120,    -1,   101,    30,    -1,
     101,    31,    -1,   100,    51,   100,    -1,   101,   106,   101,
      -1,    96,    43,   100,    -1,    38,   122,   114,    -1,   123,
      -1,   124,    -1,   130,    -1,   142,    -1,   101,    -1,   125,
      66,   126,    66,   127,    -1,   128,    -1,   142,    -1,   101,
      -1,   129,    -1,   142,    -1,   117,    -1,   117,    -1,   131,
      39,   101,    -1,   100,    51,    -1,    96,    43,    -1,   142,
      -1,   133,    -1,   137,    -1,    42,   117,    64,   134,    65,
      -1,   134,   135,    -1,   135,    -1,   136,    67,   115,    -1,
      41,   100,    -1,    40,    -1,    42,   117,   138,    64,   139,
      65,    -1,     6,    43,   108,    50,    48,    36,    49,    -1,
     140,    67,   115,    -1,    41,   141,    -1,    40,    -1,    97,
      52,    97,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    75,    79,    85,    86,    90,    91,    95,
      99,   100,   104,   105,   106,   111,   112,   116,   117,   121,
     122,   123,   128,   129,   133,   134,   138,   142,   146,   147,
     153,   157,   158,   162,   163,   167,   168,   172,   176,   183,
     184,   188,   189,   193,   197,   201,   202,   206,   207,   212,
     213,   214,   218,   219,   223,   229,   230,   234,   235,   236,
     237,   238,   239,   243,   244,   245,   246,   247,   248,   252,
     253,   254,   255,   259,   260,   261,   262,   263,   264,   265,
     270,   271,   272,   273,   274,   275,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   293,   294,   295,
     299,   300,   304,   308,   309,   310,   311,   312,   316,   320,
     321,   322,   326,   327,   334,   340,   341,   345,   346,   347,
     348,   352,   353,   354,   355,   359,   360,   364,   365,   369,
     375,   381,   382,   383,   384,   388,   392,   398,   399,   403,
     407,   408,   412,   416,   420,   424,   425,   426,   432,   433,
     437,   440,   441,   445,   449,   450,   454,   458,   462,   465,
     466,   469,   472
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING_LITERAL", "INT_LITERAL",
  "FLOAT_LITERAL", "IDENTIFIER", "LOGICAL_OR", "LOGICAL_AND", "LSHIFT",
  "RSHIFT", "AMPXOR", "CHANNEL_ASSIGN", "REL_EQUAL", "REL_NEQUAL",
  "REL_LT", "REL_LEQ", "REL_GT", "REL_GEQ", "ADD_ASSIGN", "SUB_ASSIGN",
  "OR_ASSIGN", "XOR_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "AND_ASSIGN", "LSHIFT_ASSIGN", "RSHIFT_ASSIGN", "AMPXOR_ASSIGN",
  "INC_ASSIGN", "DEC_ASSIGN", "KEYWORD_PACKAGE", "KEYWORD_IMPORT",
  "KEYWORD_FUNC", "KEYWORD_CONST", "KEYWORD_TYPE", "KEYWORD_VAR",
  "KEYWORD_FOR", "KEYWORD_RANGE", "KEYWORD_DEFAULT", "KEYWORD_CASE",
  "KEYWORD_SWITCH", "SHORT_DECLARATION", "P_BOOL", "P_NIL", "P_TYPE",
  "P_FUNCTION", "'('", "')'", "'.'", "'='", "','", "'+'", "'-'", "'|'",
  "'^'", "'*'", "'/'", "'%'", "'&'", "'!'", "'['", "']'", "'{'", "'}'",
  "';'", "':'", "$accept", "s", "PackageClause", "PackageName",
  "ImportDeclarations", "ImportDeclaration", "ImportSpecificationList",
  "ImportSpecificationList2", "ImportSpecification",
  "TopLevelDeclarations", "TopLevelDeclaration", "Declaration",
  "ConstDeclaration", "ConstSpecifications", "ConstSpecification",
  "ConstIdList", "PreConstIdList", "TypeDeclaration", "TypeSpecifications",
  "TypeSpecificationList", "TypeSpecification", "AliasDeclaration",
  "TypeDefinition", "VariableDeclaration", "VariableSpecifications",
  "VariableSpecification", "VariableIdList", "VariableIdListType",
  "IdentifierList", "Type", "TypeName", "QualifiedID", "ExpressionList",
  "Expression", "RelationalOperation", "AddOperation", "MultipyOperation",
  "UnaryOperation", "AssignOperation", "UnaryExpression",
  "PrimaryExpression", "Index", "Operand", "Literal", "BasicLiteral",
  "OperandName", "CodeBlock", "Statements", "Statement", "SimpleStatement",
  "IncrementDecrement", "Assignment", "ShortDeclaration", "ForStatement",
  "ForClauseParent", "ForCondition", "ForClause", "ForClauseInit",
  "ForClauseCondition", "ForClauseUpdation", "InitializeStatement",
  "UpdationStatement", "RangeClause", "PreForRange", "SwitchStatement",
  "ExprSwitchStmt", "ExprCaseClauses", "ExprCaseClause", "ExprSwitchCase",
  "TypeSwitchStmt", "TypeSwitchGuard", "TypeCaseClause", "TypeSwitchCase",
  "TypeList", "empty", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    40,    41,
      46,    61,    44,    43,    45,   124,    94,    42,    47,    37,
      38,    33,    91,    93,   123,   125,    59,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    70,    71,    72,    72,    73,    73,    74,
      75,    75,    76,    76,    76,    77,    77,    78,    78,    79,
      79,    79,    80,    80,    81,    81,    82,    83,    84,    84,
      85,    86,    86,    87,    87,    88,    88,    89,    90,    91,
      91,    92,    92,    93,    94,    95,    95,    96,    96,    97,
      97,    97,    98,    98,    99,   100,   100,   101,   101,   101,
     101,   101,   101,   102,   102,   102,   102,   102,   102,   103,
     103,   103,   103,   104,   104,   104,   104,   104,   104,   104,
     105,   105,   105,   105,   105,   105,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   107,   107,   107,
     108,   108,   109,   110,   110,   110,   110,   110,   111,   112,
     112,   112,   113,   113,   114,   115,   115,   116,   116,   116,
     116,   117,   117,   117,   117,   118,   118,   119,   119,   120,
     121,   122,   122,   122,   122,   123,   124,   125,   125,   126,
     127,   127,   128,   129,   130,   131,   131,   131,   132,   132,
     133,   134,   134,   135,   136,   136,   137,   138,   139,   140,
     140,   141,   142
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     2,     1,     2,     4,     2,
       2,     1,     1,     2,     2,     2,     1,     1,     5,     1,
       1,     1,     2,     4,     1,     2,     2,     3,     1,     1,
       2,     1,     3,     2,     1,     1,     1,     3,     2,     2,
       4,     1,     2,     2,     2,     2,     1,     1,     3,     1,
       3,     1,     1,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     2,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     5,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     2,     1,     1,     1,
       5,     2,     1,     3,     2,     1,     6,     7,     3,     2,
       1,     3,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   162,     4,     3,     1,     0,   162,   162,
       6,    12,     0,     0,     0,     7,     0,     0,     0,     0,
       2,   162,    17,    19,    20,    21,    16,     5,     0,   162,
      13,    14,     0,    47,     0,    22,   162,   162,   162,    30,
      31,    35,    36,     0,    39,    41,   162,    15,     8,     9,
     162,    11,     0,     0,    24,    52,   162,     0,     0,    26,
       0,    28,    49,    53,    29,   162,    38,    51,     0,   162,
      34,     0,    42,    43,   162,    10,     0,    23,    25,     0,
      48,     0,     0,    37,    32,    33,    40,     0,    44,    46,
     162,    18,    50,    54,   111,   109,   110,   112,     0,   107,
     106,   113,     0,    80,    81,    83,    84,    85,    82,    27,
      55,     0,    62,    99,   100,   103,   108,   104,    45,     0,
     116,    97,     0,     0,     0,     0,    76,    77,    79,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    78,     0,     0,     0,    98,     0,   101,   112,
     162,     0,   114,   118,     0,     0,   121,   115,   117,   122,
     123,   124,   119,   120,   148,   149,   105,    56,    57,    58,
      59,    60,    61,     0,     0,     0,    55,   142,     0,   131,
     132,     0,   137,   133,     0,   134,     0,     0,     0,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
     125,   126,     0,   102,   146,   145,   130,     0,     0,     0,
       0,     0,   129,   127,   128,   139,     0,   144,     0,   155,
       0,     0,   152,     0,     0,   162,     0,   154,   150,   151,
     162,   160,   162,     0,     0,   143,   136,   140,   141,     0,
     153,     0,   159,   156,   162,     0,   162,   158,     0,   161,
     157
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    58,     8,     9,    28,    49,    50,    20,
      21,   153,    23,    53,    35,    59,    60,    24,    39,    68,
      69,    41,    42,    25,    44,    45,    73,    88,   154,    61,
      62,    63,   155,   110,   143,   144,   145,   111,   202,   112,
     113,   148,   114,   115,   116,   117,    91,   119,   157,   158,
     159,   160,   161,   162,   178,   179,   180,   181,   216,   236,
     182,   237,   183,   184,   163,   164,   221,   222,   223,   165,
     211,   233,   234,   242,    67
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -148
static const yytype_int16 yypact[] =
{
     -21,     8,    17,     9,  -148,  -148,  -148,    24,   107,     9,
    -148,  -148,    25,    65,    80,  -148,    89,    28,    63,    74,
    -148,   107,  -148,  -148,  -148,  -148,  -148,  -148,    50,    25,
    -148,  -148,    66,  -148,   142,  -148,    33,    38,   151,  -148,
    -148,  -148,  -148,   142,   142,  -148,    33,  -148,  -148,  -148,
      25,  -148,   110,     2,  -148,  -148,    42,   155,   116,  -148,
     117,  -148,  -148,  -148,  -148,    42,  -148,  -148,   118,   151,
    -148,    16,  -148,  -148,   119,  -148,   109,  -148,  -148,   133,
    -148,   179,    49,  -148,  -148,  -148,  -148,    49,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,    49,  -148,
    -148,  -148,    49,  -148,  -148,  -148,  -148,  -148,  -148,   134,
     395,    49,  -148,   135,  -148,  -148,  -148,  -148,   134,   127,
    -148,  -148,   383,    49,    49,    49,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,    49,    49,    49,  -148,    49,  -148,   -31,
     146,   146,  -148,  -148,    75,    -6,   329,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,   395,   395,   395,
     395,   395,   395,   316,    76,    85,   229,  -148,   109,  -148,
    -148,   123,  -148,  -148,   156,   -23,     3,    49,    49,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,    49,  -148,    49,    49,  -148,    49,    49,   158,
     105,   140,   134,   134,   395,   395,   132,   395,   173,  -148,
      49,    51,  -148,   138,   114,   146,    73,   134,  -148,  -148,
    -148,  -148,    42,   143,   144,  -148,  -148,  -148,  -148,   161,
     261,   160,  -148,  -148,  -148,   177,    42,   261,   165,  -148,
    -148
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,  -148,  -148,    12,   206,  -148,  -148,   166,   122,   198,
    -148,    96,  -148,  -148,    48,  -148,  -148,  -148,  -148,   154,
     207,  -148,  -148,  -148,   181,    29,  -148,  -148,     6,   -36,
    -148,  -148,   -80,   -87,  -148,  -148,  -148,  -148,  -148,    15,
      10,  -148,  -148,  -148,  -148,  -148,    52,  -132,  -148,  -147,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,     5,  -148,  -148,
    -148,  -148,  -148,  -148,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -148
static const yytype_int16 yytable[] =
{
      10,    66,   109,   177,   186,    26,    10,   118,    33,   209,
      74,     1,   -47,     5,     4,   122,  -147,     6,    26,    14,
      79,   -47,    33,    36,    14,    46,    51,    11,    11,    83,
       4,     4,   156,    64,    33,    70,   167,   168,   169,     4,
      36,    14,     7,  -138,     4,   188,   123,    51,     4,    46,
      46,    77,    94,    95,    96,    97,   170,   171,   172,    36,
     173,    98,    14,   176,   156,    86,    70,   210,    30,    37,
     175,    89,    12,    72,    13,    13,    34,    46,   235,    55,
      33,    56,    54,    31,    55,    57,    56,   120,    55,    65,
      56,   219,   220,    99,   100,    32,   101,   102,   240,    48,
      72,    78,   103,   104,    22,   105,   106,   212,   213,   107,
     108,    38,   247,   121,    52,   214,   228,    22,   187,   204,
     215,   217,    43,   239,   212,   213,   146,    57,    57,    15,
      94,    95,    96,   149,    29,   147,   205,   123,   156,    98,
     227,    16,    17,    18,    19,   219,   220,   185,    33,    94,
      95,    96,   149,   156,   231,   232,   174,    37,    98,    76,
     156,    80,    17,    18,    19,   150,    81,    84,    82,   151,
      87,    99,   100,    90,   101,   102,    94,    95,    96,    97,
     103,   104,    92,   105,   106,    93,   123,   107,   108,   207,
      99,   100,   152,   101,   102,   208,   241,   147,   225,   103,
     104,   218,   105,   106,   224,   230,   107,   108,   243,   245,
     249,   244,   246,   248,   250,    27,    75,    99,   100,    47,
     101,   102,   238,    85,    71,    40,   229,   120,   226,     0,
     206,     0,     0,     0,     0,     0,   124,   125,   126,   127,
     128,   120,   129,   130,   131,   132,   133,   134,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,     0,     0,     0,    94,    95,    96,   149,     0,     0,
       0,     0,     0,    98,     0,     0,     0,     0,     0,     0,
       0,     0,   135,   136,   137,   138,   139,   140,   141,   142,
       0,     0,     0,  -135,     0,  -121,    17,    18,    19,   150,
       0,     0,     0,   151,     0,    99,   100,     0,   101,   102,
       0,     0,     0,     0,   103,   104,     0,   105,   106,     0,
       0,   107,   108,   124,   125,   126,   127,   128,     0,   129,
     130,   131,   132,   133,   134,     0,   124,   125,   126,   127,
     128,     0,   129,   130,   131,   132,   133,   134,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,     0,     0,     0,     0,     0,     0,     0,     0,   135,
     136,   137,   138,   139,   140,   141,   142,     0,     0,   203,
     -55,   -55,   135,   136,   137,   138,   139,   140,   141,   142,
     124,   125,   126,   127,   128,     0,   129,   130,   131,   132,
     133,   134,   124,   125,   126,   127,   128,     0,   129,   130,
     131,   132,   133,   134,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   166,     0,     0,     0,   135,   136,   137,   138,
     139,   140,   141,   142,     0,     0,     0,     0,   135,   136,
     137,   138,   139,   140,   141,   142
};

static const yytype_int16 yycheck[] =
{
       3,    37,    82,   150,   151,     8,     9,    87,     6,     6,
      46,    32,    43,     1,     6,   102,    39,     0,    21,     7,
      56,    52,     6,    17,    12,    19,    29,     3,     3,    65,
       6,     6,   119,    36,     6,    38,   123,   124,   125,     6,
      34,    29,    33,    66,     6,    51,    52,    50,     6,    43,
      44,    49,     3,     4,     5,     6,   143,   144,   145,    53,
     147,    12,    50,   150,   151,    49,    69,    64,     3,     6,
     150,    74,    48,    44,    50,    50,    48,    71,   225,    46,
       6,    48,    34,     3,    46,    52,    48,    90,    46,    51,
      48,    40,    41,    44,    45,     6,    47,    48,   230,    49,
      71,    53,    53,    54,     8,    56,    57,   187,   188,    60,
      61,    48,   244,    98,    48,   202,    65,    21,    43,    43,
     207,   208,    48,    50,   204,   205,   111,    52,    52,     7,
       3,     4,     5,     6,    12,    62,    51,    52,   225,    12,
     220,    34,    35,    36,    37,    40,    41,   150,     6,     3,
       4,     5,     6,   240,    40,    41,   150,     6,    12,    49,
     247,     6,    35,    36,    37,    38,    50,    49,    51,    42,
      51,    44,    45,    64,    47,    48,     3,     4,     5,     6,
      53,    54,    49,    56,    57,     6,    52,    60,    61,    66,
      44,    45,    65,    47,    48,    39,   232,    62,    66,    53,
      54,    43,    56,    57,    64,    67,    60,    61,    65,    48,
     246,    67,    52,    36,    49,     9,    50,    44,    45,    21,
      47,    48,   225,    69,    43,    18,   221,   230,   218,    -1,
     178,    -1,    -1,    -1,    -1,    -1,     7,     8,     9,    10,
      11,   244,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    64,    -1,    66,    35,    36,    37,    38,
      -1,    -1,    -1,    42,    -1,    44,    45,    -1,    47,    48,
      -1,    -1,    -1,    -1,    53,    54,    -1,    56,    57,    -1,
      -1,    60,    61,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    16,    17,    18,    -1,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    -1,    63,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    16,
      17,    18,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    57,    58,    59,    60
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    69,    70,     6,    71,     0,    33,    72,    73,
     142,     3,    48,    50,    71,    76,    34,    35,    36,    37,
      77,    78,    79,    80,    85,    91,   142,    72,    74,    76,
       3,     3,     6,     6,    48,    82,    96,     6,    48,    86,
      88,    89,    90,    48,    92,    93,    96,    77,    49,    75,
      76,   142,    48,    81,    82,    46,    48,    52,    71,    83,
      84,    97,    98,    99,   142,    51,    97,   142,    87,    88,
     142,    92,    93,    94,    97,    75,    49,    49,    82,    97,
       6,    50,    51,    97,    49,    87,    49,    51,    95,   142,
      64,   114,    49,     6,     3,     4,     5,     6,    12,    44,
      45,    47,    48,    53,    54,    56,    57,    60,    61,   100,
     101,   105,   107,   108,   110,   111,   112,   113,   100,   115,
     142,   107,   101,    52,     7,     8,     9,    10,    11,    13,
      14,    15,    16,    17,    18,    53,    54,    55,    56,    57,
      58,    59,    60,   102,   103,   104,   107,    62,   109,     6,
      38,    42,    65,    79,    96,   100,   101,   116,   117,   118,
     119,   120,   121,   132,   133,   137,    49,   101,   101,   101,
     101,   101,   101,   101,    96,   100,   101,   117,   122,   123,
     124,   125,   128,   130,   131,   142,   117,    43,    51,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,   106,    63,    43,    51,   114,    66,    39,     6,
      64,   138,   100,   100,   101,   101,   126,   101,    43,    40,
      41,   134,   135,   136,    64,    66,   108,   100,    65,   135,
      67,    40,    41,   139,   140,   117,   127,   129,   142,    50,
     115,    97,   141,    65,    67,    48,    52,   115,    36,    97,
      49
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
      
/* Line 1267 of yacc.c.  */
#line 1721 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 474 "yac.y"

int main (void) {
	
	return yyparse();
}

void yyerror (char *s) {fprintf (stderr, "%d %s\n",yylineno, s);} 
