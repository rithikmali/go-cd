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
     ADD_ASSIGN = 258,
     SUB_ASSIGN = 259,
     MUL_ASSIGN = 260,
     DIV_ASSIGN = 261,
     LSHIFT_ASSIGN = 262,
     RSHIFT_ASSIGN = 263,
     AND_ASSIGN = 264,
     OR_ASSIGN = 265,
     XOR_ASSIGN = 266,
     MOD_ASSIGN = 267,
     INC_ASSIGN = 268,
     DEC_ASSIGN = 269,
     AMPXOR_ASSIGN = 270,
     SHORT_DECLARATION = 271,
     LOGICAL_AND = 272,
     LOGICAL_OR = 273,
     REL_EQUAL = 274,
     REL_NEQUAL = 275,
     REL_GEQ = 276,
     REL_LEQ = 277,
     AMPXOR = 278,
     LSHIFT = 279,
     RSHIFT = 280,
     CHANNEL_ASSIGN = 281,
     REL_GT = 282,
     REL_LT = 283,
     KEYWORD_DEFAULT = 284,
     KEYWORD_BREAK = 285,
     KEYWORD_CHAN = 286,
     KEYWORD_SELECT = 287,
     KEYWORD_FUNC = 288,
     KEYWORD_MAP = 289,
     KEYWORD_INTERFACE = 290,
     KEYWORD_GO = 291,
     KEYWORD_FALLTHROUGH = 292,
     KEYWORD_ELSE = 293,
     KEYWORD_DEFER = 294,
     KEYWORD_GOTO = 295,
     KEYWORD_CONST = 296,
     KEYWORD_STRUCT = 297,
     KEYWORD_CASE = 298,
     KEYWORD_PACKAGE = 299,
     KEYWORD_CONTINUE = 300,
     KEYWORD_SWITCH = 301,
     KEYWORD_TYPE = 302,
     KEYWORD_IMPORT = 303,
     KEYWORD_RANGE = 304,
     KEYWORD_VAR = 305,
     KEYWORD_FOR = 306,
     KEYWORD_RETURN = 307,
     KEYWORD_IF = 308,
     KEYWORD_MAIN = 309,
     P_NIL = 310,
     IDENTIFIER = 311,
     FLOAT_LITERAL = 312,
     STRING_LITERAL = 313,
     P_TYPE = 314,
     P_BOOL = 315,
     P_FUNCTION = 316,
     INT_LITERAL = 317,
     P_UNARY = 318,
     NotPackage = 319,
     NotParen = 320,
     PreferToRightParen = 321
   };
#endif
/* Tokens.  */
#define ADD_ASSIGN 258
#define SUB_ASSIGN 259
#define MUL_ASSIGN 260
#define DIV_ASSIGN 261
#define LSHIFT_ASSIGN 262
#define RSHIFT_ASSIGN 263
#define AND_ASSIGN 264
#define OR_ASSIGN 265
#define XOR_ASSIGN 266
#define MOD_ASSIGN 267
#define INC_ASSIGN 268
#define DEC_ASSIGN 269
#define AMPXOR_ASSIGN 270
#define SHORT_DECLARATION 271
#define LOGICAL_AND 272
#define LOGICAL_OR 273
#define REL_EQUAL 274
#define REL_NEQUAL 275
#define REL_GEQ 276
#define REL_LEQ 277
#define AMPXOR 278
#define LSHIFT 279
#define RSHIFT 280
#define CHANNEL_ASSIGN 281
#define REL_GT 282
#define REL_LT 283
#define KEYWORD_DEFAULT 284
#define KEYWORD_BREAK 285
#define KEYWORD_CHAN 286
#define KEYWORD_SELECT 287
#define KEYWORD_FUNC 288
#define KEYWORD_MAP 289
#define KEYWORD_INTERFACE 290
#define KEYWORD_GO 291
#define KEYWORD_FALLTHROUGH 292
#define KEYWORD_ELSE 293
#define KEYWORD_DEFER 294
#define KEYWORD_GOTO 295
#define KEYWORD_CONST 296
#define KEYWORD_STRUCT 297
#define KEYWORD_CASE 298
#define KEYWORD_PACKAGE 299
#define KEYWORD_CONTINUE 300
#define KEYWORD_SWITCH 301
#define KEYWORD_TYPE 302
#define KEYWORD_IMPORT 303
#define KEYWORD_RANGE 304
#define KEYWORD_VAR 305
#define KEYWORD_FOR 306
#define KEYWORD_RETURN 307
#define KEYWORD_IF 308
#define KEYWORD_MAIN 309
#define P_NIL 310
#define IDENTIFIER 311
#define FLOAT_LITERAL 312
#define STRING_LITERAL 313
#define P_TYPE 314
#define P_BOOL 315
#define P_FUNCTION 316
#define INT_LITERAL 317
#define P_UNARY 318
#define NotPackage 319
#define NotParen 320
#define PreferToRightParen 321




/* Copy the first part of user declarations.  */
#line 1 "yac.y"

    #include <stdio.h>
    #include <stdlib.h>
    #define YYSTYPE char*


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
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 244 "yac.tab.c"

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   623

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNRULES -- Number of states.  */
#define YYNSTATES  251

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    78,     2,     2,     2,    69,    70,     2,
      74,    75,    67,    63,    77,    64,    85,    68,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    86,    83,
       2,    84,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    79,     2,    80,    66,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    81,    65,    82,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    71,    72,
      73,    76
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    15,    19,    23,    25,    27,
      31,    33,    35,    37,    39,    41,    43,    45,    47,    49,
      51,    53,    55,    57,    59,    61,    63,    65,    67,    69,
      71,    73,    75,    77,    79,    81,    83,    85,    87,    89,
      91,    93,    95,    97,    99,   102,   105,   107,   109,   112,
     116,   118,   120,   124,   126,   128,   130,   132,   134,   136,
     138,   140,   144,   147,   149,   151,   153,   155,   157,   159,
     161,   163,   165,   168,   171,   175,   179,   183,   187,   190,
     192,   194,   197,   199,   202,   207,   210,   213,   215,   217,
     220,   223,   225,   229,   231,   233,   237,   240,   242,   244,
     250,   252,   254,   256,   259,   264,   266,   269,   272,   276,
     278,   280,   283,   285,   289,   292,   294,   296,   298,   302,
     305,   308,   313,   315,   318,   321,   324,   327,   329,   331,
     335,   339,   341,   343,   345,   347,   349,   355,   357,   359,
     361,   363,   365,   367,   369,   373,   376,   379,   381,   383,
     385,   393,   397,   400,   402,   410,   418,   422,   425,   427
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     109,     0,    -1,    88,    18,    88,    -1,    88,    17,    88,
      -1,    88,    90,    88,    -1,    88,    91,    88,    -1,    88,
      92,    88,    -1,    95,    -1,    88,    -1,    89,    77,    88,
      -1,    19,    -1,    20,    -1,    28,    -1,    22,    -1,    27,
      -1,    21,    -1,    63,    -1,    64,    -1,    65,    -1,    66,
      -1,    67,    -1,    68,    -1,    69,    -1,    24,    -1,    25,
      -1,    70,    -1,    23,    -1,    63,    -1,    64,    -1,    78,
      -1,    66,    -1,    67,    -1,    70,    -1,     3,    -1,     4,
      -1,    10,    -1,    11,    -1,     5,    -1,     6,    -1,    12,
      -1,     9,    -1,     7,    -1,     8,    -1,    15,    -1,    26,
      95,    -1,    93,    95,    -1,    96,    -1,    98,    -1,    96,
      97,    -1,    79,    88,    80,    -1,    99,    -1,   101,    -1,
      74,    88,    75,    -1,    55,    -1,    60,    -1,   100,    -1,
      62,    -1,    57,    -1,    58,    -1,    56,    -1,    61,    -1,
      81,   103,    82,    -1,   103,   104,    -1,    83,    -1,   105,
      -1,   122,    -1,   140,    -1,   151,    -1,    88,    -1,   106,
      -1,   107,    -1,   108,    -1,    88,    13,    -1,    88,    14,
      -1,    89,    84,    89,    -1,    88,    94,    88,    -1,   139,
      16,    89,    -1,   110,   112,   120,    -1,    44,   111,    -1,
      83,    -1,    56,    -1,   113,   112,    -1,    83,    -1,    48,
     116,    -1,    48,    74,   114,    75,    -1,   116,   115,    -1,
     116,   115,    -1,    83,    -1,    58,    -1,    85,    58,    -1,
     111,    58,    -1,   118,    -1,    74,   117,    75,    -1,    59,
      -1,   119,    -1,   111,    85,    56,    -1,   121,   120,    -1,
      83,    -1,   122,    -1,    33,    54,    74,    75,   102,    -1,
     123,    -1,   128,    -1,   134,    -1,    41,   125,    -1,    41,
      74,   124,    75,    -1,   125,    -1,   124,   125,    -1,   139,
     126,    -1,   127,    84,    89,    -1,   117,    -1,    83,    -1,
      47,   129,    -1,   131,    -1,    74,   130,    75,    -1,   131,
     130,    -1,    83,    -1,   132,    -1,   133,    -1,    56,    84,
     117,    -1,    56,   117,    -1,    50,   135,    -1,    50,    74,
     135,    75,    -1,   136,    -1,   135,   136,    -1,   139,   137,
      -1,   117,   138,    -1,    84,    89,    -1,    83,    -1,    56,
      -1,   139,    77,    56,    -1,    51,   141,   102,    -1,   142,
      -1,   143,    -1,   149,    -1,    83,    -1,    88,    -1,   144,
      83,   145,    83,   146,    -1,   147,    -1,    83,    -1,    88,
      -1,   148,    -1,    83,    -1,   105,    -1,   105,    -1,   150,
      49,    88,    -1,    89,    84,    -1,   139,    16,    -1,    83,
      -1,   152,    -1,   155,    -1,    46,   105,    83,    88,    81,
     153,    82,    -1,   154,    86,   103,    -1,    43,    89,    -1,
      29,    -1,    46,   105,    83,   156,    81,   157,    82,    -1,
      56,    16,    96,    85,    74,    47,    75,    -1,   158,    86,
     103,    -1,    43,   159,    -1,    29,    -1,   117,    77,   117,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    34,    34,    35,    36,    37,    38,    39,    43,    44,
      48,    49,    50,    51,    52,    53,    57,    58,    59,    60,
      64,    65,    66,    67,    68,    69,    70,    75,    76,    77,
      78,    79,    80,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    98,    99,   100,   123,   124,   128,
     132,   133,   134,   135,   136,   140,   144,   145,   146,   150,
     151,   155,   161,   162,   166,   167,   168,   169,   173,   174,
     175,   176,   180,   181,   185,   186,   190,   194,   205,   206,
     210,   215,   216,   220,   221,   225,   229,   230,   234,   235,
     236,   240,   241,   245,   246,   250,   253,   254,   258,   259,
     263,   264,   265,   269,   270,   274,   275,   279,   283,   287,
     288,   292,   296,   297,   301,   302,   306,   307,   311,   315,
     319,   320,   324,   325,   329,   333,   337,   338,   343,   344,
     348,   354,   355,   356,   357,   361,   365,   371,   372,   376,
     380,   381,   385,   389,   393,   399,   400,   401,   406,   407,
     411,   415,   419,   420,   424,   428,   432,   436,   436,   440
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "LSHIFT_ASSIGN", "RSHIFT_ASSIGN", "AND_ASSIGN",
  "OR_ASSIGN", "XOR_ASSIGN", "MOD_ASSIGN", "INC_ASSIGN", "DEC_ASSIGN",
  "AMPXOR_ASSIGN", "SHORT_DECLARATION", "LOGICAL_AND", "LOGICAL_OR",
  "REL_EQUAL", "REL_NEQUAL", "REL_GEQ", "REL_LEQ", "AMPXOR", "LSHIFT",
  "RSHIFT", "CHANNEL_ASSIGN", "REL_GT", "REL_LT", "KEYWORD_DEFAULT",
  "KEYWORD_BREAK", "KEYWORD_CHAN", "KEYWORD_SELECT", "KEYWORD_FUNC",
  "KEYWORD_MAP", "KEYWORD_INTERFACE", "KEYWORD_GO", "KEYWORD_FALLTHROUGH",
  "KEYWORD_ELSE", "KEYWORD_DEFER", "KEYWORD_GOTO", "KEYWORD_CONST",
  "KEYWORD_STRUCT", "KEYWORD_CASE", "KEYWORD_PACKAGE", "KEYWORD_CONTINUE",
  "KEYWORD_SWITCH", "KEYWORD_TYPE", "KEYWORD_IMPORT", "KEYWORD_RANGE",
  "KEYWORD_VAR", "KEYWORD_FOR", "KEYWORD_RETURN", "KEYWORD_IF",
  "KEYWORD_MAIN", "P_NIL", "IDENTIFIER", "FLOAT_LITERAL", "STRING_LITERAL",
  "P_TYPE", "P_BOOL", "P_FUNCTION", "INT_LITERAL", "'+'", "'-'", "'|'",
  "'^'", "'*'", "'/'", "'%'", "'&'", "P_UNARY", "NotPackage", "NotParen",
  "'('", "')'", "PreferToRightParen", "','", "'!'", "'['", "']'", "'{'",
  "'}'", "';'", "'='", "'.'", "':'", "$accept", "Expression",
  "ExpressionList", "RelationalOperation", "AddOperation",
  "MultipyOperation", "UnaryOperation", "AssignOperation",
  "UnaryExpression", "PrimaryExpression", "Index", "Operand", "Literal",
  "BasicLiteral", "OperandName", "CodeBlock", "Statements", "Statement",
  "SimpleStatement", "IncrementDecrement", "Assignment",
  "ShortDeclaration", "SourceFile", "PackageClause", "PackageName",
  "ImportDeclarations", "ImportDeclaration", "ImportSpecificationList",
  "ImportSpecificationList2", "ImportSpecification", "Type", "TypeName",
  "QualifiedID", "TopLevelDeclarations", "TopLevelDeclaration",
  "Declaration", "ConstDeclaration", "ConstSpecifications",
  "ConstSpecification", "ConstIdList", "PreConstIdList", "TypeDeclaration",
  "TypeSpecifications", "TypeSpecificationList", "TypeSpecification",
  "AliasDeclaration", "TypeDefinition", "VariableDeclaration",
  "VariableSpecifications", "VariableSpecification", "VariableIdList",
  "VariableIdListType", "IdentifierList", "ForStatement",
  "ForClauseParent", "ForCondition", "ForClause", "ForClauseInit",
  "ForClauseCondition", "ForClauseUpdation", "InitializeStatement",
  "UpdationStatement", "RangeClause", "PreForRange", "SwitchStatement",
  "ExpressionSwitchStatement", "ExpressionCaseClause",
  "ExpressionSwitchCase", "TypeSwitchStatement", "TypeSwitchGuard",
  "TypeCaseClause", "TypeSwitchCase", "TypeList", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    43,    45,   124,    94,    42,    47,    37,
      38,   318,   319,   320,    40,    41,   321,    44,    33,    91,
      93,   123,   125,    59,    61,    46,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    88,    88,    88,    88,    88,    89,    89,
      90,    90,    90,    90,    90,    90,    91,    91,    91,    91,
      92,    92,    92,    92,    92,    92,    92,    93,    93,    93,
      93,    93,    93,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    95,    95,    95,    96,    96,    97,
      98,    98,    98,    98,    98,    99,   100,   100,   100,   101,
     101,   102,   103,   103,   104,   104,   104,   104,   105,   105,
     105,   105,   106,   106,   107,   107,   108,   109,   110,   110,
     111,   112,   112,   113,   113,   114,   115,   115,   116,   116,
     116,   117,   117,   118,   118,   119,   120,   120,   121,   121,
     122,   122,   122,   123,   123,   124,   124,   125,   126,   127,
     127,   128,   129,   129,   130,   130,   131,   131,   132,   133,
     134,   134,   135,   135,   136,   137,   138,   138,   139,   139,
     140,   141,   141,   141,   141,   142,   143,   144,   144,   145,
     146,   146,   147,   148,   149,   150,   150,   150,   151,   151,
     152,   153,   154,   154,   155,   156,   157,   158,   158,   159
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     3,     3,     3,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     2,     3,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     3,     3,     3,     2,     1,
       1,     2,     1,     2,     4,     2,     2,     1,     1,     2,
       2,     1,     3,     1,     1,     3,     2,     1,     1,     5,
       1,     1,     1,     2,     4,     1,     2,     2,     3,     1,
       1,     2,     1,     3,     2,     1,     1,     1,     3,     2,
       2,     4,     1,     2,     2,     2,     2,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     5,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     2,     1,     1,     1,
       7,     3,     2,     1,     7,     7,     3,     2,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    79,     0,     0,    80,    78,     1,     0,    82,
       0,     0,    88,     0,     0,     0,    83,     0,     0,     0,
       0,    97,    77,     0,    98,   100,   101,   102,    81,     0,
       0,    89,    90,     0,   128,     0,   103,     0,     0,     0,
     111,   112,   116,   117,     0,   120,   122,     0,    96,    84,
      87,    85,     0,     0,     0,   105,    93,     0,     0,   110,
       0,   109,    91,    94,   107,     0,     0,   119,   115,     0,
       0,     0,   123,     0,   124,    86,     0,   104,   106,     0,
     129,     0,     0,   118,   113,   114,   121,   127,     0,   125,
       0,    99,    92,    95,     0,    53,    59,    57,    58,    54,
      60,    56,    27,    28,    30,    31,    32,     0,    29,     8,
     108,     0,     7,    46,    47,    50,    55,    51,   126,    63,
       0,    44,     0,     0,     0,    10,    11,    15,    13,    26,
      23,    24,    14,    12,    16,    17,    18,    19,    20,    21,
      22,    25,     0,     0,     0,     0,    45,     0,    48,     0,
       0,    59,    61,    68,     0,    62,    64,    69,    70,    71,
      65,     0,    66,    67,   148,   149,    52,     3,     2,     4,
       5,     6,     9,     0,     0,   134,     8,     0,   142,     0,
       0,   131,   132,     0,   137,   133,     0,    33,    34,    37,
      38,    41,    42,    40,    35,    36,    39,    72,    73,    43,
       0,     0,     0,    49,     0,   145,   146,   130,     0,     0,
      75,    74,    76,    59,     0,     0,   139,     0,   144,     0,
       0,     0,     0,     0,   153,     0,     0,     0,   158,     0,
       0,     0,   141,   143,   136,   140,     0,   152,   150,     0,
       0,   157,   154,     0,     0,   151,     0,   156,     0,   159,
     155
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   109,   154,   142,   143,   144,   111,   200,   112,   113,
     148,   114,   115,   116,   117,    91,   120,   155,   156,   157,
     158,   159,     3,     4,    60,    10,    11,    29,    51,    52,
      61,    62,    63,    22,    23,   160,    25,    54,    36,    64,
      65,    26,    40,    69,    70,    42,    43,    27,    45,    46,
      74,    89,   161,   162,   180,   181,   182,   183,   217,   234,
     184,   235,   185,   186,   163,   164,   226,   227,   165,   215,
     230,   231,   241
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -140
static const yytype_int16 yypact[] =
{
     -30,   -24,  -140,    22,   -31,  -140,  -140,  -140,    34,  -140,
      14,   -31,  -140,   -18,   -21,     1,  -140,    12,   -40,    44,
      60,  -140,  -140,    14,  -140,  -140,  -140,  -140,  -140,    -7,
     -25,  -140,  -140,    38,  -140,    58,  -140,   540,   145,   -29,
    -140,  -140,  -140,  -140,    58,    58,  -140,   243,  -140,  -140,
    -140,  -140,   -25,    70,   -33,  -140,  -140,    48,    91,  -140,
      87,  -140,  -140,  -140,  -140,    93,    48,  -140,  -140,   100,
     -29,    24,  -140,   122,  -140,  -140,   126,  -140,  -140,   143,
    -140,   164,   482,  -140,  -140,  -140,  -140,  -140,   482,  -140,
     139,  -140,  -140,  -140,   482,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,   482,  -140,   411,
     147,   482,  -140,   148,  -140,  -140,  -140,  -140,   147,  -140,
     345,  -140,   315,   482,   482,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,   482,   482,   482,   482,  -140,   482,  -140,   506,
      15,   209,  -140,   146,    29,  -140,  -140,  -140,  -140,  -140,
    -140,   -14,  -140,  -140,  -140,  -140,  -140,   227,   423,    63,
      71,    71,   411,   261,   149,   -34,   175,    59,  -140,   -12,
     126,  -140,  -140,   150,  -140,  -140,   177,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
     482,   482,   482,  -140,   531,   482,   482,  -140,   482,   482,
     411,   147,   147,   212,   242,   153,   411,   152,   411,   397,
     -17,   133,   289,    32,  -140,   482,   154,   151,  -140,    48,
     171,   182,  -140,  -140,  -140,  -140,   157,   147,  -140,   139,
     180,  -140,  -140,   139,   224,   456,    48,   456,   197,  -140,
    -140
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,   -99,   -81,  -140,  -140,  -140,  -140,  -140,   -20,    54,
    -140,  -140,  -140,  -140,  -140,    94,   -22,  -140,  -139,  -140,
    -140,  -140,  -140,  -140,     5,   264,  -140,  -140,   225,   129,
     -38,  -140,  -140,   253,  -140,    92,  -140,  -140,    49,  -140,
    -140,  -140,  -140,   217,   279,  -140,  -140,  -140,   256,    -9,
    -140,  -140,   -15,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -148
static const yytype_int16 yytable[] =
{
      67,   110,   202,    37,   206,    47,     6,   118,   122,    73,
     174,   178,   224,    15,     1,  -147,    34,     8,    15,    79,
      37,   153,     7,    34,   167,   168,   225,    38,    83,    47,
      47,     5,     5,    12,    35,    15,    72,    31,     5,    37,
      12,    94,    77,   169,   170,   171,   172,    17,   173,  -138,
     153,   176,     9,     2,    68,    18,    47,    15,    50,    32,
      14,    19,    72,    58,    20,    58,    33,    14,    49,   177,
      95,   151,    97,    98,   121,    99,   100,   101,   102,   103,
      34,   104,   105,   233,    55,   106,   129,   130,   131,   107,
       5,   146,    12,   108,   129,   130,   131,    21,   175,    86,
      38,   210,    24,    78,     5,   214,   145,    56,    13,   216,
     218,   147,    53,   201,    34,    24,    34,   236,    39,    14,
     211,   212,    57,   153,   211,   212,   134,   135,   136,   137,
     138,   139,   140,   141,    44,   179,   145,    16,   138,   139,
     140,   141,    30,   205,   237,    76,   153,    80,   153,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   228,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    81,   132,   133,    84,   229,    82,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   240,   123,   124,   125,   126,   127,   128,   129,   130,
     131,     5,   132,   133,    56,    87,    88,    90,   249,   134,
     135,   136,   137,   138,   139,   140,   141,   245,    92,    57,
      93,   247,   119,    -8,   145,  -128,   209,   147,   219,    66,
      -8,   244,   204,   208,   221,   222,   238,   239,   134,   135,
     136,   137,   138,   139,   140,   141,   125,   126,   127,   128,
     129,   130,   131,   242,   132,   133,  -135,   246,   -68,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   243,   132,
     133,   248,   250,   223,   207,    28,    48,    75,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    85,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    41,     5,
      71,     0,    56,     0,     0,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,    94,     0,    57,     0,     0,
      58,     0,     0,   220,   134,   135,   136,   137,   138,   139,
     140,   141,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   203,   132,   133,    95,   151,    97,    98,     0,    99,
     100,   101,   102,   103,     0,   104,   105,     0,     0,   106,
       0,     0,     0,   107,     0,     0,     0,   108,     0,     0,
       0,    94,   232,     0,     0,     0,     0,     0,   134,   135,
     136,   137,   138,   139,   140,   141,    18,     0,     0,     0,
     166,   149,    19,     0,     0,    20,   150,     0,     0,     0,
      95,   151,    97,    98,     0,    99,   100,   101,   102,   103,
       0,   104,   105,     0,     0,   106,     0,     0,     0,   107,
       0,     0,     0,   108,     0,     0,     0,   152,   123,   124,
     125,   126,   127,   128,   129,   130,   131,     0,   132,   133,
     123,     0,   125,   126,   127,   128,   129,   130,   131,     0,
     132,   133,    95,    96,    97,    98,     0,    99,   100,   101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,     0,     0,   134,   135,   136,   137,   138,   139,
     140,   141,    94,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,     0,    18,     0,     0,
       0,     0,   149,    19,     0,     0,    20,   150,    94,     0,
       0,    95,   151,    97,    98,     0,    99,   100,   101,   102,
     103,     0,   104,   105,     0,     0,   106,     0,     0,     0,
     107,     0,    94,     0,   108,     0,     0,    95,    96,    97,
      98,     0,    99,   100,   101,   102,   103,     0,   104,   105,
       0,     0,   106,     0,     0,     0,   107,    94,     0,     0,
     108,    95,   151,    97,    98,     0,    99,   100,   101,   102,
     103,     0,   104,   105,     0,     0,   106,     0,     0,     0,
     107,     0,     0,     0,   108,     0,    95,   213,    97,    98,
       0,    99,   100,   101,   102,   103,     5,   104,   105,    56,
       0,   106,     0,     0,     0,   107,     0,     0,     0,   108,
       0,     0,     0,     0,    57,     0,     0,    58,     0,     0,
       0,     0,     0,    59
};

static const yytype_int16 yycheck[] =
{
      38,    82,    16,    18,    16,    20,     1,    88,   107,    47,
     149,   150,    29,     8,    44,    49,    56,    48,    13,    57,
      35,   120,     0,    56,   123,   124,    43,    56,    66,    44,
      45,    56,    56,    58,    74,    30,    45,    58,    56,    54,
      58,    26,    75,   142,   143,   144,   145,    33,   147,    83,
     149,   150,    83,    83,    83,    41,    71,    52,    83,    58,
      85,    47,    71,    77,    50,    77,    54,    85,    75,   150,
      55,    56,    57,    58,    94,    60,    61,    62,    63,    64,
      56,    66,    67,   222,    35,    70,    23,    24,    25,    74,
      56,   111,    58,    78,    23,    24,    25,    83,    83,    75,
      56,   200,    10,    54,    56,   204,    77,    59,    74,   208,
     209,    79,    74,    84,    56,    23,    56,    85,    74,    85,
     201,   202,    74,   222,   205,   206,    63,    64,    65,    66,
      67,    68,    69,    70,    74,   150,    77,     8,    67,    68,
      69,    70,    13,    84,   225,    75,   245,    56,   247,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    29,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    85,    27,    28,    75,    43,    84,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,   229,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    56,    27,    28,    59,    83,    84,    81,   246,    63,
      64,    65,    66,    67,    68,    69,    70,   239,    75,    74,
      56,   243,    83,    77,    77,    16,    49,    79,    16,    84,
      84,    74,    83,    83,    81,    83,    82,    86,    63,    64,
      65,    66,    67,    68,    69,    70,    19,    20,    21,    22,
      23,    24,    25,    82,    27,    28,    81,    77,    83,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    86,    27,
      28,    47,    75,   219,   180,    11,    23,    52,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    70,    27,    28,
      63,    64,    65,    66,    67,    68,    69,    70,    19,    56,
      44,    -1,    59,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    26,    -1,    74,    -1,    -1,
      77,    -1,    -1,    81,    63,    64,    65,    66,    67,    68,
      69,    70,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    80,    27,    28,    55,    56,    57,    58,    -1,    60,
      61,    62,    63,    64,    -1,    66,    67,    -1,    -1,    70,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    26,    83,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    70,    41,    -1,    -1,    -1,
      75,    46,    47,    -1,    -1,    50,    51,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    60,    61,    62,    63,    64,
      -1,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    82,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    28,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    55,    56,    57,    58,    -1,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    70,    26,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    46,    47,    -1,    -1,    50,    51,    26,    -1,
      -1,    55,    56,    57,    58,    -1,    60,    61,    62,    63,
      64,    -1,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,
      74,    -1,    26,    -1,    78,    -1,    -1,    55,    56,    57,
      58,    -1,    60,    61,    62,    63,    64,    -1,    66,    67,
      -1,    -1,    70,    -1,    -1,    -1,    74,    26,    -1,    -1,
      78,    55,    56,    57,    58,    -1,    60,    61,    62,    63,
      64,    -1,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    78,    -1,    55,    56,    57,    58,
      -1,    60,    61,    62,    63,    64,    56,    66,    67,    59,
      -1,    70,    -1,    -1,    -1,    74,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    83
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    83,   109,   110,    56,   111,     0,    48,    83,
     112,   113,    58,    74,    85,   111,   116,    33,    41,    47,
      50,    83,   120,   121,   122,   123,   128,   134,   112,   114,
     116,    58,    58,    54,    56,    74,   125,   139,    56,    74,
     129,   131,   132,   133,    74,   135,   136,   139,   120,    75,
      83,   115,   116,    74,   124,   125,    59,    74,    77,    83,
     111,   117,   118,   119,   126,   127,    84,   117,    83,   130,
     131,   135,   136,   117,   137,   115,    75,    75,   125,   117,
      56,    85,    84,   117,    75,   130,    75,    83,    84,   138,
      81,   102,    75,    56,    26,    55,    56,    57,    58,    60,
      61,    62,    63,    64,    66,    67,    70,    74,    78,    88,
      89,    93,    95,    96,    98,    99,   100,   101,    89,    83,
     103,    95,    88,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    27,    28,    63,    64,    65,    66,    67,    68,
      69,    70,    90,    91,    92,    77,    95,    79,    97,    46,
      51,    56,    82,    88,    89,   104,   105,   106,   107,   108,
     122,   139,   140,   151,   152,   155,    75,    88,    88,    88,
      88,    88,    88,    88,   105,    83,    88,    89,   105,   139,
     141,   142,   143,   144,   147,   149,   150,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      94,    84,    16,    80,    83,    84,    16,   102,    83,    49,
      88,    89,    89,    56,    88,   156,    88,   145,    88,    16,
      81,    81,    83,    96,    29,    43,   153,   154,    29,    43,
     157,   158,    83,   105,   146,   148,    85,    89,    82,    86,
     117,   159,    82,    86,    74,   103,    77,   103,    47,   117,
      75
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
        case 77:
#line 195 "yac.y"
    {
        if(yychar!=YYEOF)
        {
            printf("Invalid\n");YYERROR;
        }
        printf("Valid\n"); YYACCEPT;
    ;}
    break;

  case 80:
#line 210 "yac.y"
    {printf("got id\n");;}
    break;


/* Line 1267 of yacc.c.  */
#line 1806 "yac.tab.c"
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



