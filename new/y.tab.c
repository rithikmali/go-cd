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
#define YYLAST   527

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  166
/* YYNRULES -- Number of states.  */
#define YYNSTATES  258

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
     141,   145,   147,   149,   151,   155,   162,   169,   171,   175,
     179,   183,   187,   191,   195,   197,   199,   201,   203,   205,
     207,   209,   211,   213,   215,   217,   219,   221,   223,   225,
     227,   229,   231,   233,   235,   237,   239,   241,   243,   245,
     247,   249,   251,   253,   255,   257,   259,   261,   263,   265,
     268,   271,   273,   275,   278,   282,   284,   286,   290,   292,
     294,   296,   298,   300,   302,   304,   306,   310,   313,   315,
     317,   319,   321,   323,   325,   327,   329,   331,   334,   337,
     341,   345,   349,   353,   355,   357,   359,   361,   363,   369,
     371,   373,   375,   377,   379,   381,   383,   387,   390,   393,
     395,   397,   399,   405,   408,   410,   414,   417,   419,   425,
     433,   436,   438,   442,   445,   447,   451
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      69,     0,    -1,    70,    72,    77,    -1,    32,    71,    -1,
       6,    -1,    73,    72,    -1,   143,    -1,    33,    76,    -1,
      33,    48,    74,    49,    -1,    76,    75,    -1,    76,    75,
      -1,   143,    -1,     3,    -1,    50,     3,    -1,    71,     3,
      -1,    78,    77,    -1,   143,    -1,    79,    -1,    34,     6,
      48,    49,   114,    -1,    80,    -1,    85,    -1,    91,    -1,
      35,    82,    -1,    35,    48,    81,    49,    -1,    82,    -1,
      81,    82,    -1,    96,    83,    -1,    84,    51,   100,    -1,
      97,    -1,   143,    -1,    36,    86,    -1,    88,    -1,    48,
      87,    49,    -1,    88,    87,    -1,   143,    -1,    89,    -1,
      90,    -1,     6,    51,    97,    -1,     6,    97,    -1,    37,
      92,    -1,    37,    48,    92,    49,    -1,    93,    -1,    92,
      93,    -1,    96,    94,    -1,    97,    95,    -1,    51,   100,
      -1,   143,    -1,     6,    -1,    96,    52,     6,    -1,    98,
      -1,    48,    97,    49,    -1,   143,    -1,    46,    -1,    99,
      -1,    71,    50,     6,    -1,    71,    50,     6,    48,     6,
      49,    -1,    71,    50,     6,    48,   112,    49,    -1,   101,
      -1,   100,    52,   101,    -1,   101,     7,   101,    -1,   101,
       8,   101,    -1,   101,   102,   101,    -1,   101,   103,   101,
      -1,   101,   104,   101,    -1,   107,    -1,    13,    -1,    14,
      -1,    15,    -1,    16,    -1,    17,    -1,    18,    -1,    53,
      -1,    54,    -1,    55,    -1,    56,    -1,    57,    -1,    58,
      -1,    59,    -1,     9,    -1,    10,    -1,    60,    -1,    11,
      -1,    53,    -1,    54,    -1,    61,    -1,    56,    -1,    57,
      -1,    60,    -1,    19,    -1,    20,    -1,    21,    -1,    22,
      -1,    23,    -1,    24,    -1,    25,    -1,    26,    -1,    27,
      -1,    28,    -1,    29,    -1,    12,   107,    -1,   105,   107,
      -1,   108,    -1,   110,    -1,   108,   109,    -1,    62,   101,
      63,    -1,   111,    -1,   113,    -1,    48,   101,    49,    -1,
      45,    -1,    44,    -1,   112,    -1,     4,    -1,     5,    -1,
       3,    -1,     6,    -1,    47,    -1,    64,   115,    65,    -1,
     115,   116,    -1,   143,    -1,   117,    -1,    79,    -1,   121,
      -1,   132,    -1,   101,    -1,   118,    -1,   119,    -1,   120,
      -1,   101,    30,    -1,   101,    31,    -1,   100,    51,   100,
      -1,   101,   106,   101,    -1,    96,    43,   100,    -1,    38,
     122,   114,    -1,   123,    -1,   124,    -1,   130,    -1,   143,
      -1,   101,    -1,   125,    66,   126,    66,   127,    -1,   128,
      -1,   143,    -1,   101,    -1,   129,    -1,   143,    -1,   117,
      -1,   117,    -1,   131,    39,   101,    -1,   100,    51,    -1,
      96,    43,    -1,   143,    -1,   133,    -1,   137,    -1,    42,
     117,    64,   134,    65,    -1,   134,   135,    -1,   135,    -1,
     136,    67,   115,    -1,    41,   100,    -1,    40,    -1,    42,
     138,    64,   139,    65,    -1,     6,    43,   108,    50,    48,
      36,    49,    -1,   139,   140,    -1,   140,    -1,   141,    67,
     115,    -1,    41,   142,    -1,    40,    -1,    97,    52,    97,
      -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    75,    79,    85,    86,    90,    91,    95,
      99,   100,   104,   105,   106,   111,   112,   116,   117,   121,
     122,   123,   128,   129,   133,   134,   138,   142,   146,   147,
     153,   157,   158,   162,   163,   167,   168,   172,   176,   183,
     184,   188,   189,   193,   197,   201,   202,   206,   207,   212,
     213,   214,   218,   219,   223,   224,   225,   231,   232,   236,
     237,   238,   239,   240,   241,   245,   246,   247,   248,   249,
     250,   254,   255,   256,   257,   261,   262,   263,   264,   265,
     266,   267,   272,   273,   274,   275,   276,   277,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   295,
     296,   297,   301,   303,   307,   311,   312,   313,   314,   315,
     319,   323,   324,   325,   329,   330,   337,   343,   344,   348,
     349,   350,   351,   355,   356,   357,   358,   362,   363,   367,
     368,   372,   378,   384,   385,   386,   387,   391,   395,   401,
     402,   406,   410,   411,   415,   419,   423,   427,   428,   429,
     435,   437,   441,   444,   445,   449,   453,   454,   458,   462,
     467,   468,   471,   474,   475,   478,   481
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
  "TypeSwitchStmt", "TypeSwitchGuard", "TypeCaseClauses", "TypeCaseClause",
  "TypeSwitchCase", "TypeList", "empty", 0
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
      97,    97,    98,    98,    99,    99,    99,   100,   100,   101,
     101,   101,   101,   101,   101,   102,   102,   102,   102,   102,
     102,   103,   103,   103,   103,   104,   104,   104,   104,   104,
     104,   104,   105,   105,   105,   105,   105,   105,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   107,
     107,   107,   108,   108,   109,   110,   110,   110,   110,   110,
     111,   112,   112,   112,   113,   113,   114,   115,   115,   116,
     116,   116,   116,   117,   117,   117,   117,   118,   118,   119,
     119,   120,   121,   122,   122,   122,   122,   123,   124,   125,
     125,   126,   127,   127,   128,   129,   130,   131,   131,   131,
     132,   132,   133,   134,   134,   135,   136,   136,   137,   138,
     139,   139,   140,   141,   141,   142,   143
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     2,     1,     2,     4,     2,
       2,     1,     1,     2,     2,     2,     1,     1,     5,     1,
       1,     1,     2,     4,     1,     2,     2,     3,     1,     1,
       2,     1,     3,     2,     1,     1,     1,     3,     2,     2,
       4,     1,     2,     2,     2,     2,     1,     1,     3,     1,
       3,     1,     1,     1,     3,     6,     6,     1,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     2,     3,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     5,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     2,     1,
       1,     1,     5,     2,     1,     3,     2,     1,     5,     7,
       2,     1,     3,     2,     1,     3,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   166,     4,     3,     1,     0,   166,   166,
       6,    12,     0,     0,     0,     7,     0,     0,     0,     0,
       2,   166,    17,    19,    20,    21,    16,     5,     0,   166,
      13,    14,     0,    47,     0,    22,   166,   166,   166,    30,
      31,    35,    36,     0,    39,    41,   166,    15,     8,     9,
     166,    11,     0,     0,    24,    52,   166,     0,     0,    26,
       0,    28,    49,    53,    29,   166,    38,    51,     0,   166,
      34,     0,    42,    43,   166,    10,     0,    23,    25,     0,
      48,     0,     0,    37,    32,    33,    40,     0,    44,    46,
     166,    18,    50,    54,   113,   111,   112,   114,     0,   109,
     108,   115,     0,    82,    83,    85,    86,    87,    84,    27,
      57,     0,    64,   101,   102,   105,   110,   106,    45,     0,
     118,     0,    99,     0,     0,     0,     0,    78,    79,    81,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    80,     0,     0,     0,   100,     0,   103,
     114,   166,     0,   116,   120,     0,     0,   123,   117,   119,
     124,   125,   126,   121,   122,   150,   151,     0,     0,   107,
      58,    59,    60,    61,    62,    63,     0,     0,     0,    57,
     144,     0,   133,   134,     0,   139,   135,     0,   136,   114,
       0,     0,     0,     0,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,   127,   128,     0,    55,    56,
     104,   148,   147,   132,     0,     0,     0,     0,     0,   131,
     129,   130,   141,     0,   146,     0,   157,     0,     0,   154,
       0,   164,   166,     0,   161,     0,   166,     0,   156,   152,
     153,   166,     0,   163,   158,   160,   166,   145,   138,   142,
     143,     0,   155,   166,   162,     0,   165,   159
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    58,     8,     9,    28,    49,    50,    20,
      21,   154,    23,    53,    35,    59,    60,    24,    39,    68,
      69,    41,    42,    25,    44,    45,    73,    88,   155,    61,
      62,    63,   156,   110,   144,   145,   146,   111,   207,   112,
     113,   149,   114,   115,   116,   117,    91,   119,   158,   159,
     160,   161,   162,   163,   181,   182,   183,   184,   223,   248,
     185,   249,   186,   187,   164,   165,   228,   229,   230,   166,
     191,   233,   234,   235,   243,    67
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -141
static const yytype_int16 yypact[] =
{
     -13,    33,    78,   -10,  -141,  -141,  -141,    11,    93,   -10,
    -141,  -141,    18,    86,   103,  -141,   126,     1,    22,    49,
    -141,    93,  -141,  -141,  -141,  -141,  -141,  -141,    94,    18,
    -141,  -141,   104,  -141,   135,  -141,    28,    40,   153,  -141,
    -141,  -141,  -141,   135,   135,  -141,    28,  -141,  -141,  -141,
      18,  -141,   113,    -4,  -141,  -141,    31,   159,   121,  -141,
     123,  -141,  -141,  -141,  -141,    31,  -141,  -141,   129,   153,
    -141,     7,  -141,  -141,   130,  -141,   118,  -141,  -141,   134,
    -141,   171,   141,  -141,  -141,  -141,  -141,   141,  -141,  -141,
    -141,  -141,  -141,   139,  -141,  -141,  -141,  -141,   141,  -141,
    -141,  -141,   141,  -141,  -141,  -141,  -141,  -141,  -141,   138,
     467,   141,  -141,   131,  -141,  -141,  -141,  -141,   138,   119,
    -141,   132,  -141,   455,   141,   141,   141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,   141,   141,   141,  -141,   141,  -141,
      17,   315,   333,  -141,  -141,    57,    67,   401,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,   142,   143,  -141,
     467,   467,   467,   467,   467,   467,   388,    60,    88,   237,
    -141,   118,  -141,  -141,   133,  -141,  -141,   161,     9,    64,
     140,   144,   141,   141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,   141,  -141,  -141,
    -141,   141,   141,  -141,   141,   141,    37,   110,   128,   138,
     138,   467,   467,   137,   467,   -47,  -141,   141,    52,  -141,
     145,  -141,    31,    61,  -141,   146,   315,   157,   138,  -141,
    -141,  -141,   154,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,   173,   269,    31,   269,   158,  -141,  -141
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,  -141,    15,   201,  -141,  -141,   164,    92,   190,
    -141,    87,  -141,  -141,    30,  -141,  -141,  -141,  -141,   147,
     197,  -141,  -141,  -141,   175,    23,  -141,  -141,    19,   -36,
    -141,  -141,   -78,   -94,  -141,  -141,  -141,  -141,  -141,     0,
       3,  -141,  -141,  -141,    99,  -141,    41,  -136,  -141,  -140,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,    -7,  -141,  -141,
    -141,  -141,    -9,  -141,  -141,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -150
static const yytype_int16 yytable[] =
{
      10,    66,    33,   237,   109,    26,    10,    33,   123,   118,
      74,   180,   190,    33,    11,   148,     5,     4,    26,     1,
      79,    11,    14,     7,     4,   157,    51,    14,    37,    83,
     170,   171,   172,    64,     4,    70,    36,     4,    46,     4,
      94,    95,    96,    97,    14,    77,     4,    51,  -149,    34,
     173,   174,   175,    36,   176,    33,    86,   179,   157,    12,
     -47,    13,    46,    46,    54,    14,    70,    72,    13,   -47,
      38,    89,    36,   178,    55,  -140,    56,    55,     6,    56,
      57,    99,   100,    78,   101,   102,    55,   120,    56,    30,
      46,    65,   226,   227,    72,    22,   247,    43,   122,    15,
     192,   231,   232,   211,    29,   252,    31,   216,    22,    57,
     254,   147,    57,   221,   219,   220,   -47,   239,   193,   124,
     222,   224,    94,    95,    96,   150,   244,    16,    17,    18,
      19,    98,    32,   219,   220,    94,    95,    96,   167,   212,
     124,    33,   157,    48,    94,    95,    96,    97,   188,   238,
     226,   227,    52,    98,    17,    18,    19,   151,   157,    37,
     157,   152,    76,    99,   100,    80,   101,   102,   231,   232,
     177,    81,   103,   104,    82,   105,   106,    93,    84,   107,
     108,    87,    90,    92,   153,    99,   100,   121,   101,   102,
     124,   208,   209,   148,   103,   104,   242,   105,   106,   214,
     215,   107,   108,   236,   217,   251,   253,   257,   218,   255,
      27,    47,   241,   246,    75,    40,    85,   256,    71,   225,
     168,   240,   213,     0,   245,     0,     0,     0,     0,     0,
       0,     0,     0,   250,     0,     0,     0,     0,   120,     0,
       0,     0,     0,   120,   125,   126,   127,   128,   129,     0,
     130,   131,   132,   133,   134,   135,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,     0,
       0,     0,    94,    95,    96,   150,     0,     0,     0,     0,
       0,    98,     0,     0,     0,     0,     0,     0,     0,     0,
     136,   137,   138,   139,   140,   141,   142,   143,     0,     0,
       0,  -137,     0,  -123,    17,    18,    19,   151,     0,     0,
       0,   152,     0,    99,   100,     0,   101,   102,    94,    95,
      96,   150,   103,   104,     0,   105,   106,    98,     0,   107,
     108,     0,     0,     0,     0,     0,    94,    95,    96,   189,
       0,     0,     0,     0,     0,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
     100,     0,   101,   102,     0,     0,     0,     0,   103,   104,
       0,   105,   106,     0,     0,   107,   108,    99,   100,     0,
     101,   102,     0,     0,     0,     0,   103,   104,     0,   105,
     106,     0,     0,   107,   108,   125,   126,   127,   128,   129,
       0,   130,   131,   132,   133,   134,   135,     0,   125,   126,
     127,   128,   129,     0,   130,   131,   132,   133,   134,   135,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,     0,     0,     0,     0,     0,     0,     0,
       0,   136,   137,   138,   139,   140,   141,   142,   143,     0,
       0,   210,   -57,   -57,   136,   137,   138,   139,   140,   141,
     142,   143,   125,   126,   127,   128,   129,     0,   130,   131,
     132,   133,   134,   135,   125,   126,   127,   128,   129,     0,
     130,   131,   132,   133,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,     0,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,     0,     0,     0,     0,
     136,   137,   138,   139,   140,   141,   142,   143
};

static const yytype_int16 yycheck[] =
{
       3,    37,     6,    50,    82,     8,     9,     6,   102,    87,
      46,   151,   152,     6,     3,    62,     1,     6,    21,    32,
      56,     3,     7,    33,     6,   119,    29,    12,     6,    65,
     124,   125,   126,    36,     6,    38,    17,     6,    19,     6,
       3,     4,     5,     6,    29,    49,     6,    50,    39,    48,
     144,   145,   146,    34,   148,     6,    49,   151,   152,    48,
      43,    50,    43,    44,    34,    50,    69,    44,    50,    52,
      48,    74,    53,   151,    46,    66,    48,    46,     0,    48,
      52,    44,    45,    53,    47,    48,    46,    90,    48,     3,
      71,    51,    40,    41,    71,     8,   236,    48,    98,     7,
      43,    40,    41,    43,    12,   241,     3,    43,    21,    52,
     246,   111,    52,   207,   192,   193,    52,    65,    51,    52,
     214,   215,     3,     4,     5,     6,    65,    34,    35,    36,
      37,    12,     6,   211,   212,     3,     4,     5,     6,    51,
      52,     6,   236,    49,     3,     4,     5,     6,   151,   227,
      40,    41,    48,    12,    35,    36,    37,    38,   252,     6,
     254,    42,    49,    44,    45,     6,    47,    48,    40,    41,
     151,    50,    53,    54,    51,    56,    57,     6,    49,    60,
      61,    51,    64,    49,    65,    44,    45,    48,    47,    48,
      52,    49,    49,    62,    53,    54,   232,    56,    57,    66,
      39,    60,    61,    66,    64,    48,    52,    49,    64,    36,
       9,    21,    67,    67,    50,    18,    69,   253,    43,   216,
     121,   228,   181,    -1,   233,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,   241,    -1,
      -1,    -1,    -1,   246,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    64,    -1,    66,    35,    36,    37,    38,    -1,    -1,
      -1,    42,    -1,    44,    45,    -1,    47,    48,     3,     4,
       5,     6,    53,    54,    -1,    56,    57,    12,    -1,    60,
      61,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    -1,    47,    48,    -1,    -1,    -1,    -1,    53,    54,
      -1,    56,    57,    -1,    -1,    60,    61,    44,    45,    -1,
      47,    48,    -1,    -1,    -1,    -1,    53,    54,    -1,    56,
      57,    -1,    -1,    60,    61,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    16,    17,    18,    -1,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      -1,    63,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    16,    17,    18,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    57,    58,    59,    60
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    69,    70,     6,    71,     0,    33,    72,    73,
     143,     3,    48,    50,    71,    76,    34,    35,    36,    37,
      77,    78,    79,    80,    85,    91,   143,    72,    74,    76,
       3,     3,     6,     6,    48,    82,    96,     6,    48,    86,
      88,    89,    90,    48,    92,    93,    96,    77,    49,    75,
      76,   143,    48,    81,    82,    46,    48,    52,    71,    83,
      84,    97,    98,    99,   143,    51,    97,   143,    87,    88,
     143,    92,    93,    94,    97,    75,    49,    49,    82,    97,
       6,    50,    51,    97,    49,    87,    49,    51,    95,   143,
      64,   114,    49,     6,     3,     4,     5,     6,    12,    44,
      45,    47,    48,    53,    54,    56,    57,    60,    61,   100,
     101,   105,   107,   108,   110,   111,   112,   113,   100,   115,
     143,    48,   107,   101,    52,     7,     8,     9,    10,    11,
      13,    14,    15,    16,    17,    18,    53,    54,    55,    56,
      57,    58,    59,    60,   102,   103,   104,   107,    62,   109,
       6,    38,    42,    65,    79,    96,   100,   101,   116,   117,
     118,   119,   120,   121,   132,   133,   137,     6,   112,    49,
     101,   101,   101,   101,   101,   101,   101,    96,   100,   101,
     117,   122,   123,   124,   125,   128,   130,   131,   143,     6,
     117,   138,    43,    51,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,   106,    49,    49,
      63,    43,    51,   114,    66,    39,    43,    64,    64,   100,
     100,   101,   101,   126,   101,   108,    40,    41,   134,   135,
     136,    40,    41,   139,   140,   141,    66,    50,   100,    65,
     135,    67,    97,   142,    65,   140,    67,   117,   127,   129,
     143,    48,   115,    52,   115,    36,    97,    49
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
        case 102:
#line 302 "yac.y"
    {printf("primary operand done\n");}
    break;

  case 150:
#line 436 "yac.y"
    {printf("switch expr done\n");}
    break;

  case 159:
#line 463 "yac.y"
    {printf("typeswitchguard done\n");}
    break;


/* Line 1267 of yacc.c.  */
#line 1752 "y.tab.c"
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


#line 491 "yac.y"

int main (void) {
	
	return yyparse();
}


void yyerror (char *s) {fprintf (stderr, "%d %s\n",yylineno, s);} 
