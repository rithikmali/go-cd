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
#line 1 "yac.y"

// void yyerror (char *s);
// int yylex();
#include <stdio.h>     /* C declarations used in actions */
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
union NodeVal value;
// int yylineno;
int TABLE_SIZE = 10009;

int base = 100;

typedef struct symbol_table {
    char name[31];
    char dtype[10];
    char type;
    char value[20];
    char scope[10];
    int hcode;
  }ST;
  
 ST hashTable[10009];

struct Stack {
   char s[25][25];
   int top;
};

typedef struct Stack stack;

stack stack_i = {.top = -1};
stack stack_v = {.top = -1};
stack stack_r = {.top = -1};
stack stack_scope = {.top = -1};


char result[20];
char Tflag[20];

int stfull(stack st,int size) {
	if (st.top >= size - 1)
		return 1;
	else
		return 0;
}

void push(stack *p_st,char *item) {
	p_st->top++;
	strcpy(p_st->s[p_st->top], item);
}

int stempty(stack st) {
	if (st.top == -1)
		return 1;
	else
		return 0;
}

char * pop(stack *p_st) {
	char *item;
	item = p_st->s[p_st->top];
	p_st->top--;
	return (item);
}

int hash1(char *token) {
				
	int hash = 0;
	for (int i = 0; token[i] != '\0'; i++) { 
		hash = ( 256 * hash + token[i] ) % 1000000009; 
	}
	hash = hash % TABLE_SIZE;
	return hash;

}

int check(char *token) {
				
	int index1 = hash1(token); 
	int i = 0;
	while ( i < TABLE_SIZE && strcmp(hashTable[( index1 + i ) % TABLE_SIZE].name, token) != 0 )
		i++;

	if ( i == TABLE_SIZE )
		return 1;
	else
		return index1 + i;

}


void insert(char type, char *token, char *dtype, char *value, char *scope) {

	if (check(token) != 1) {
		yyerror("variable is redeclared");
    	return;
  	}
  	int index = hash1(token);

  	if (hashTable[index].hcode != -1) {

	    int i = 1;
		while (1) {
			int newIndex = (index + i) % TABLE_SIZE;

			if (hashTable[newIndex].hcode == -1) {

				strcpy(hashTable[newIndex].name, token);
				strcpy(hashTable[newIndex].dtype, dtype);
				strcpy(hashTable[newIndex].value, value);
				strcpy(hashTable[newIndex].scope, scope);
				hashTable[newIndex].type = type;
				hashTable[newIndex].hcode = 1;
				break;
			}
			i++;
		}
	}

	else {
		strcpy(hashTable[index].name, token);
		strcpy(hashTable[index].dtype, dtype);
		strcpy(hashTable[index].value, value);
		strcpy(hashTable[index].scope, scope);
		hashTable[index].type = type;
		hashTable[index].hcode = 1;
	}
}
char * search(char *token) {

	int index1 = hash1(token); 
	int i = 0;
	while ( i < TABLE_SIZE && strcmp(hashTable[( index1 + i ) % TABLE_SIZE].name, token)!=0)
		i++;
	if ( i == TABLE_SIZE ) {
		printf("Error: %s is not defined\n", token);
		exit(0);
	}
	else
		return hashTable[index1 + i].dtype;
}


void update(char *token, char *dtype, char *value) {
	int index = check(token);
	if ( index == 1 ) {
		printf("Error: %s is not defined\n", token);
		exit(0);
		return;
	}
	
	if (hashTable[index].type == 'c') {
		printf("Error: cannot assign to %s (declared const)", token);
		exit(0);
		return;
	}
	else {
		if (strcmp(hashTable[index].value, "NULL") != 0)
			strcpy(hashTable[index].value, value);
		if (strcmp(hashTable[index].dtype, "NULL") != 0)
			strcpy(hashTable[index].dtype, dtype);
	}
}

void disp_symtbl() {

	int base = 1000;
	printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n","Name", "Type","Data Type", "Value", "Scope");

	for(int i=0; i<TABLE_SIZE; i++) {
		if(hashTable[i].hcode != -1 )
			printf("%s\t\t%c\t\t%s\t\t\t%s\t\t%s\n",hashTable[i].name, hashTable[i].type, hashTable[i].dtype, hashTable[i].value, hashTable[i].scope);
		}

}


#line 250 "yac.tab.c"

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
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_YAC_TAB_H_INCLUDED
# define YY_YY_YAC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    P_FUNCTION = 302,
    EMPTY = 303,
    NORMAL = 304,
    P_UNARY = 305,
    PreferToRightParen = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{

  /* STRING_LITERAL  */
  char const * STRING_LITERAL;
  /* IDENTIFIER  */
  char const * IDENTIFIER;
  /* LOGICAL_OR  */
  char const * LOGICAL_OR;
  /* LOGICAL_AND  */
  char const * LOGICAL_AND;
  /* LSHIFT  */
  char const * LSHIFT;
  /* RSHIFT  */
  char const * RSHIFT;
  /* AMPXOR  */
  char const * AMPXOR;
  /* CHANNEL_ASSIGN  */
  char const * CHANNEL_ASSIGN;
  /* REL_EQUAL  */
  char const * REL_EQUAL;
  /* REL_NEQUAL  */
  char const * REL_NEQUAL;
  /* REL_LT  */
  char const * REL_LT;
  /* REL_LEQ  */
  char const * REL_LEQ;
  /* REL_GT  */
  char const * REL_GT;
  /* REL_GEQ  */
  char const * REL_GEQ;
  /* ADD_ASSIGN  */
  char const * ADD_ASSIGN;
  /* SUB_ASSIGN  */
  char const * SUB_ASSIGN;
  /* OR_ASSIGN  */
  char const * OR_ASSIGN;
  /* XOR_ASSIGN  */
  char const * XOR_ASSIGN;
  /* MUL_ASSIGN  */
  char const * MUL_ASSIGN;
  /* DIV_ASSIGN  */
  char const * DIV_ASSIGN;
  /* MOD_ASSIGN  */
  char const * MOD_ASSIGN;
  /* AND_ASSIGN  */
  char const * AND_ASSIGN;
  /* LSHIFT_ASSIGN  */
  char const * LSHIFT_ASSIGN;
  /* RSHIFT_ASSIGN  */
  char const * RSHIFT_ASSIGN;
  /* AMPXOR_ASSIGN  */
  char const * AMPXOR_ASSIGN;
  /* INC_ASSIGN  */
  char const * INC_ASSIGN;
  /* DEC_ASSIGN  */
  char const * DEC_ASSIGN;
  /* SHORT_DECLARATION  */
  char const * SHORT_DECLARATION;
  /* P_BOOL  */
  char const * P_BOOL;
  /* P_TYPE  */
  char const * P_TYPE;
  /* P_FUNCTION  */
  char const * P_FUNCTION;
  /* FLOAT_LITERAL  */
  double FLOAT_LITERAL;
  /* INT_LITERAL  */
  int INT_LITERAL;
  /* VariableSpecification  */
  struct node * VariableSpecification;
  /* VariableIdList  */
  struct node * VariableIdList;
  /* VariableIdListType  */
  struct node * VariableIdListType;
  /* IdentifierList  */
  struct node * IdentifierList;
  /* Type  */
  struct node * Type;
  /* TypeName  */
  struct node * TypeName;
  /* QualifiedID  */
  struct node * QualifiedID;
  /* ExpressionList  */
  struct node * ExpressionList;
  /* Expression  */
  struct node * Expression;
  /* RelationalOperation  */
  struct node * RelationalOperation;
  /* AddOperation  */
  struct node * AddOperation;
  /* MultipyOperation  */
  struct node * MultipyOperation;
  /* UnaryOperation  */
  struct node * UnaryOperation;
  /* AssignOperation  */
  struct node * AssignOperation;
  /* UnaryExpression  */
  struct node * UnaryExpression;
  /* PrimaryExpression  */
  struct node * PrimaryExpression;
  /* Operand  */
  struct node * Operand;
  /* Literal  */
  struct node * Literal;
  /* BasicLiteral  */
  struct node * BasicLiteral;
  /* OperandName  */
  struct node * OperandName;
  /* Assignment  */
  struct node * Assignment;
#line 463 "yac.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YAC_TAB_H_INCLUDED  */



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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   556

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  77
/* YYNRULES -- Number of rules.  */
#define YYNRULES  168
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  258

#define YYUNDEFTOK  2
#define YYMAXUTOK   306


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
       2,     2,     2,    65,     2,     2,     2,    56,    57,     2,
      59,    60,    54,    50,    64,    51,    62,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    71,    70,
       2,    63,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    66,     2,    67,    53,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,    52,    69,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    58,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   258,   258,   271,   277,   278,   282,   283,   287,   291,
     292,   296,   297,   298,   303,   304,   308,   309,   313,   314,
     315,   320,   342,   366,   367,   371,   375,   379,   380,   386,
     390,   391,   395,   396,   400,   401,   405,   409,   416,   442,
     471,   472,   476,   492,   497,   505,   510,   517,   523,   535,
     539,   546,   551,   558,   564,   585,   609,   610,   611,   612,
     613,   614,   618,   620,   621,   622,   623,   624,   628,   629,
     630,   631,   635,   636,   637,   638,   639,   640,   641,   646,
     647,   648,   649,   650,   651,   655,   656,   657,   658,   659,
     660,   661,   662,   663,   664,   665,   669,   670,   671,   678,
     682,   686,   690,   694,   698,   702,   703,   707,   714,   718,
     722,   729,   733,   737,   748,   753,   747,   760,   761,   765,
     766,   767,   768,   772,   773,   774,   775,   779,   780,   784,
     812,   817,   846,   852,   853,   854,   855,   859,   863,   869,
     870,   874,   878,   879,   883,   887,   891,   895,   896,   897,
     903,   904,   908,   911,   912,   916,   920,   921,   925,   929,
     930,   934,   935,   939,   943,   944,   948,   949,   952
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
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
  "P_FUNCTION", "EMPTY", "NORMAL", "'+'", "'-'", "'|'", "'^'", "'*'",
  "'/'", "'%'", "'&'", "P_UNARY", "'('", "')'", "PreferToRightParen",
  "'.'", "'='", "','", "'!'", "'['", "']'", "'{'", "'}'", "';'", "':'",
  "$accept", "s", "PackageClause", "ImportDeclarations",
  "ImportDeclaration", "ImportSpecificationList",
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
  "OperandName", "CodeBlock", "$@1", "$@2", "Statements", "Statement",
  "SimpleStatement", "IncrementDecrement", "Assignment",
  "ShortDeclaration", "ForStatement", "ForClauseParent", "ForCondition",
  "ForClause", "ForClauseInit", "ForClauseCondition", "ForClauseUpdation",
  "InitializeStatement", "UpdationStatement", "RangeClause", "PreForRange",
  "SwitchStatement", "ExprSwitchStmt", "ExprCaseClauses", "ExprCaseClause",
  "ExprSwitchCase", "TypeSwitchStmt", "TypeSwitchGuard", "TypeCaseClauses",
  "TypeCaseClause", "TypeSwitchCase", "TypeList", "empty", YY_NULLPTR
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
      43,    45,   124,    94,    42,    47,    37,    38,   305,    40,
      41,   306,    46,    61,    44,    33,    91,    93,   123,   125,
      59,    58
};
# endif

#define YYPACT_NINF (-147)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-150)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -13,    22,    39,    23,  -147,  -147,    49,   169,    23,  -147,
    -147,    59,    21,    61,  -147,    48,     9,    10,    11,  -147,
     169,  -147,  -147,  -147,  -147,  -147,  -147,    19,    21,  -147,
      30,    29,    93,  -147,     4,   156,    95,  -147,  -147,  -147,
    -147,    93,    93,  -147,   178,  -147,  -147,  -147,    21,    72,
      93,    -2,  -147,    52,  -147,     4,  -147,    46,  -147,  -147,
    -147,  -147,     4,  -147,    74,    95,     0,  -147,    31,  -147,
      85,  -147,    82,  -147,  -147,  -147,   148,   109,    31,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,    52,    31,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,    31,  -147,  -147,  -147,
     323,    31,  -147,    90,  -147,  -147,  -147,  -147,    31,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,   375,    31,    31,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,    31,    31,    31,
      31,  -147,    31,  -147,  -147,  -147,  -147,   398,   447,  -147,
     436,   189,   189,   243,    68,  -147,  -147,    64,   132,   227,
    -147,   135,   448,   298,   111,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,   138,   493,   157,  -147,    82,  -147,
    -147,   122,  -147,  -147,   151,   -19,    81,   125,   126,    31,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,    31,    31,  -147,  -147,  -147,    31,    31,  -147,    31,
      31,   259,   112,   120,  -147,  -147,  -147,   387,   131,   387,
     134,   154,  -147,    31,    51,  -147,   146,  -147,     4,    54,
    -147,   149,   132,   163,   164,  -147,  -147,  -147,  -147,   162,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,   192,   198,
      68,     4,    68,   175,   176,  -147,  -147,  -147
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   168,     3,     1,     0,    15,   168,     5,
      11,     0,     0,     0,     6,     0,     0,     0,     0,     2,
      15,    16,    18,    19,    20,     4,    13,     0,    10,    12,
       0,    47,     0,    21,   168,     0,    33,    29,    30,    34,
      35,     0,    38,    40,     0,    14,     7,     8,    10,     0,
       0,     0,    23,     0,    51,     0,    25,     0,    27,    49,
      52,    28,     0,    37,     0,    33,     0,    41,     0,    42,
     168,     9,     0,    48,    22,    24,     0,     0,     0,    36,
      31,    32,    39,   110,   108,   109,   111,     0,   106,   105,
     112,    79,    80,    82,    83,    84,     0,    81,   113,    44,
      54,     0,    61,    98,    99,   102,   107,   103,     0,    43,
      46,   114,    17,    53,    50,    26,    96,     0,     0,     0,
      75,    76,    78,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    77,     0,     0,     0,
       0,    97,     0,   100,    45,   168,   104,    56,    57,    55,
      58,    59,    60,     0,   115,   118,   101,   111,   168,     0,
     120,     0,     0,   123,     0,   117,   119,   124,   125,   126,
     121,   122,   150,   151,     0,     0,    54,   144,     0,   133,
     134,     0,   139,   135,     0,   136,   111,     0,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,     0,     0,   127,   128,   116,   148,   147,   132,     0,
       0,     0,     0,     0,   131,   129,   130,   141,     0,   146,
       0,     0,   157,     0,     0,   154,     0,   165,     0,     0,
     162,     0,   168,     0,     0,   156,   152,   153,   168,   166,
     164,   158,   161,   168,   145,   138,   142,   143,     0,     0,
     155,     0,   163,     0,     0,   167,   159,   160
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,  -147,   230,  -147,  -147,   194,    47,   220,  -147,
      80,  -147,  -147,   -11,  -147,  -147,  -147,  -147,   182,   231,
    -147,  -147,  -147,   208,   -28,  -147,  -147,    -9,    96,  -147,
     -33,   -60,   -93,  -147,  -147,  -147,  -147,  -147,   -57,  -147,
    -147,  -147,    44,  -147,  -147,    88,  -147,  -147,  -141,  -147,
    -146,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,    43,  -147,
    -147,  -147,  -147,    40,  -147,    17,    -3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,    27,    47,    48,    19,    20,
     160,    22,    51,    33,    56,    57,    23,    37,    64,    65,
      39,    40,    24,    42,    43,    69,   109,   161,   239,    59,
      98,   162,   100,   138,   139,   140,   101,   202,   102,   103,
     143,   104,   105,   106,   107,   112,   145,   164,   154,   165,
     166,   167,   168,   169,   170,   178,   179,   180,   181,   218,
     245,   182,   246,   183,   184,   171,   172,   224,   225,   226,
     173,   188,   229,   230,   231,   240,   155
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    60,    60,   117,    31,     9,    31,    34,    99,    44,
      53,    60,   177,   187,    67,    31,    35,    31,   115,     1,
    -149,    52,    60,    34,    10,   147,   148,    11,     4,    60,
     116,    61,    44,    44,    83,    84,    85,    86,    67,     5,
      75,    73,    34,    87,   141,   150,   151,   152,   144,   153,
      54,  -140,    10,    14,    30,    11,     6,    44,    74,    28,
      82,   163,    26,    55,    29,   176,   163,   110,    32,    36,
      41,    83,    84,    85,   157,    88,    89,   149,    90,    46,
      87,    91,    92,    13,    93,    94,   244,    21,    95,    49,
      96,   222,   223,    50,   227,   228,    97,   250,   175,    31,
      21,    35,   252,    16,    17,    18,   158,   -47,    12,    78,
     159,    13,    88,    89,    76,    90,   217,   219,    91,    92,
     236,    93,    94,   241,   211,    95,    76,    96,    50,   214,
      58,    63,    72,    97,    80,    83,    84,    85,   157,   163,
      70,   215,   216,    76,    87,    50,   214,   215,   108,   174,
     111,    77,   222,   223,   113,   185,   142,   163,    79,   163,
     227,   228,    53,   235,   118,   119,   120,   121,   122,   114,
     123,   124,   125,   126,   127,   128,    88,    89,   189,    90,
     205,   206,    91,    92,    53,    93,    94,   203,   204,    95,
     210,    96,   209,   212,   213,    60,   233,    97,   120,   121,
     122,   232,    54,    15,    16,    17,    18,   129,   130,   131,
     132,   133,   134,   135,   136,    55,   234,   238,    60,    62,
     243,   137,   248,   249,    54,  -137,   251,  -123,   253,   247,
      83,    84,    85,   186,   254,   256,   257,    55,    25,    87,
      45,    68,    71,   133,   134,   135,   136,    81,    38,    66,
     118,   119,   120,   121,   122,   221,   123,   124,   125,   126,
     127,   128,    83,    84,    85,   220,   208,   237,   255,   242,
       0,    88,    89,     0,    90,     0,     0,    91,    92,     0,
      93,    94,     0,     0,    95,     0,    96,     0,     0,     0,
       0,     0,    97,   129,   130,   131,   132,   133,   134,   135,
     136,     0,     0,     0,     0,   118,   119,   120,   121,   122,
     156,   123,   124,   125,   126,   127,   128,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   203,   204,
     118,   119,   120,   121,   122,     0,   123,   124,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,   129,   130,
     131,   132,   133,   134,   135,   136,     0,     0,     0,     0,
       0,   -54,   137,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   129,   130,   131,   132,   133,   134,   135,
     136,     0,   118,   119,   120,   121,   122,   137,   123,   124,
     125,   126,   127,   128,   118,   119,   120,   121,   122,     0,
     123,   124,   125,   126,   127,   128,   119,   120,   121,   122,
       0,   123,   124,   125,   126,   127,   128,     0,     0,     0,
       0,     0,     0,     0,     0,   129,   130,   131,   132,   133,
     134,   135,   136,     0,     0,   146,     0,   129,   130,   131,
     132,   133,   134,   135,   136,   120,   121,   122,   129,   130,
     131,   132,   133,   134,   135,   136,   120,   121,   122,     0,
     123,   124,   125,   126,   127,   128,     0,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,   129,   130,   131,
     132,   133,   134,   135,   136,     0,     0,     0,     0,     0,
       0,   201,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   207
};

static const yytype_int16 yycheck[] =
{
       3,    34,    35,    96,     6,     8,     6,    16,    68,    18,
       6,    44,   158,   159,    42,     6,     6,     6,    78,    32,
      39,    32,    55,    32,     3,   118,   119,     6,     6,    62,
      87,    34,    41,    42,     3,     4,     5,     6,    66,     0,
      51,    50,    51,    12,   101,   138,   139,   140,   108,   142,
      46,    70,     3,     6,     6,     6,    33,    66,    60,    12,
      60,   154,     3,    59,     3,   158,   159,    70,    59,    59,
      59,     3,     4,     5,     6,    44,    45,   137,    47,    60,
      12,    50,    51,    62,    53,    54,   232,     7,    57,    59,
      59,    40,    41,    64,    40,    41,    65,   238,   158,     6,
      20,     6,   243,    35,    36,    37,    38,    43,    59,    63,
      42,    62,    44,    45,    62,    47,   209,   210,    50,    51,
      69,    53,    54,    69,    43,    57,    62,    59,    64,   189,
      34,    35,    60,    65,    60,     3,     4,     5,     6,   232,
      44,   201,   202,    62,    12,    64,   206,   207,    63,   158,
      68,    55,    40,    41,     6,   158,    66,   250,    62,   252,
      40,    41,     6,   223,     7,     8,     9,    10,    11,    60,
      13,    14,    15,    16,    17,    18,    44,    45,    43,    47,
      69,    43,    50,    51,     6,    53,    54,    30,    31,    57,
      39,    59,    70,    68,    68,   228,    62,    65,     9,    10,
      11,    70,    46,    34,    35,    36,    37,    50,    51,    52,
      53,    54,    55,    56,    57,    59,    62,    71,   251,    63,
      71,    64,    59,    59,    46,    68,    64,    70,    36,   232,
       3,     4,     5,     6,    36,    60,    60,    59,     8,    12,
      20,    63,    48,    54,    55,    56,    57,    65,    17,    41,
       7,     8,     9,    10,    11,   211,    13,    14,    15,    16,
      17,    18,     3,     4,     5,     6,   178,   224,   251,   229,
      -1,    44,    45,    -1,    47,    -1,    -1,    50,    51,    -1,
      53,    54,    -1,    -1,    57,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    65,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    -1,     7,     8,     9,    10,    11,
      67,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,     7,     8,     9,    10,    11,    64,    13,    14,
      15,    16,    17,    18,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    16,    17,    18,     8,     9,    10,    11,
      -1,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    60,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,     9,    10,    11,    50,    51,
      52,    53,    54,    55,    56,    57,     9,    10,    11,    -1,
      13,    14,    15,    16,    17,    18,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    73,    74,     6,     0,    33,    75,    76,   148,
       3,     6,    59,    62,    79,    34,    35,    36,    37,    80,
      81,    82,    83,    88,    94,    75,     3,    77,    79,     3,
       6,     6,    59,    85,    99,     6,    59,    89,    91,    92,
      93,    59,    95,    96,    99,    80,    60,    78,    79,    59,
      64,    84,    85,     6,    46,    59,    86,    87,   100,   101,
     102,   148,    63,   100,    90,    91,    95,    96,    63,    97,
     100,    78,    60,    99,    60,    85,    62,   100,    63,   100,
      60,    90,    60,     3,     4,     5,     6,    12,    44,    45,
      47,    50,    51,    53,    54,    57,    59,    65,   102,   103,
     104,   108,   110,   111,   113,   114,   115,   116,    63,    98,
     148,    68,   117,     6,    60,   103,   110,   104,     7,     8,
       9,    10,    11,    13,    14,    15,    16,    17,    18,    50,
      51,    52,    53,    54,    55,    56,    57,    64,   105,   106,
     107,   110,    66,   112,   103,   118,    60,   104,   104,   103,
     104,   104,   104,   104,   120,   148,    67,     6,    38,    42,
      82,    99,   103,   104,   119,   121,   122,   123,   124,   125,
     126,   137,   138,   142,    99,   103,   104,   122,   127,   128,
     129,   130,   133,   135,   136,   148,     6,   122,   143,    43,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    63,   109,    30,    31,    69,    43,    63,   117,    70,
      39,    43,    68,    68,   103,   103,   103,   104,   131,   104,
       6,   114,    40,    41,   139,   140,   141,    40,    41,   144,
     145,   146,    70,    62,    62,   103,    69,   140,    71,   100,
     147,    69,   145,    71,   122,   132,   134,   148,    59,    59,
     120,    64,   120,    36,    36,   147,    60,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    74,    75,    75,    76,    76,    77,    78,
      78,    79,    79,    79,    80,    80,    81,    81,    82,    82,
      82,    83,    83,    84,    84,    85,    86,    87,    87,    88,
      89,    89,    90,    90,    91,    91,    92,    93,    94,    94,
      95,    95,    96,    97,    97,    98,    98,    99,    99,   100,
     100,   101,   101,   102,   103,   103,   104,   104,   104,   104,
     104,   104,   105,   105,   105,   105,   105,   105,   106,   106,
     106,   106,   107,   107,   107,   107,   107,   107,   107,   108,
     108,   108,   108,   108,   108,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   110,   110,   110,   111,
     111,   112,   113,   113,   113,   113,   113,   114,   115,   115,
     115,   116,   116,   116,   118,   119,   117,   120,   120,   121,
     121,   121,   121,   122,   122,   122,   122,   123,   123,   124,
     124,   125,   126,   127,   127,   127,   127,   128,   129,   130,
     130,   131,   132,   132,   133,   134,   135,   136,   136,   136,
     137,   137,   138,   139,   139,   140,   141,   141,   142,   143,
     143,   144,   144,   145,   146,   146,   147,   147,   148
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     2,     1,     2,     4,     2,     2,
       0,     1,     2,     2,     2,     0,     1,     5,     1,     1,
       1,     2,     4,     1,     2,     2,     3,     1,     1,     2,
       1,     3,     2,     0,     1,     1,     3,     2,     2,     4,
       1,     2,     2,     2,     2,     2,     1,     1,     3,     1,
       3,     1,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       2,     3,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     0,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     5,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     2,     1,
       1,     1,     5,     2,     1,     3,     2,     1,     5,     7,
       7,     2,     1,     3,     2,     1,     1,     3,     0
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
  case 2:
#line 259 "yac.y"
    {
        if(yychar != YYEOF) 
        {
            printf("Invalid - reached start symbol before EOF\n"); YYERROR;
        }
        printf("Parsing Successful. The given Code is Valid\n"); 
        YYACCEPT;
    }
#line 1923 "yac.tab.c"
    break;

  case 21:
#line 321 "yac.y"
    {
        if(stack_v.top != stack_i.top && stack_v.top != -1) {
            yyerror("Imbalanced assignment");
            YYERROR;
        }
        else {
            if (stack_v.top == -1){
                while(!stempty(stack_i)) {

                    insert('c', pop(&stack_i), pop(&stack_r), "NULL", stack_scope.s[stack_scope.top]);

                }
            }
            else {
                while(!stempty(stack_i)) {

                    insert('c', pop(&stack_i), pop(&stack_r), pop(&stack_v), stack_scope.s[stack_scope.top]);
                }
            }
        } 
    }
#line 1949 "yac.tab.c"
    break;

  case 22:
#line 343 "yac.y"
    {
        if(stack_v.top != stack_i.top && stack_v.top != -1) {
            yyerror("Imbalanced assignment");
            YYERROR;
        }
        else {
            if (stack_v.top == -1){
                while(!stempty(stack_i)) {

                    insert('c', pop(&stack_i), pop(&stack_r), "NULL", stack_scope.s[stack_scope.top]);
                }
            }
            else {
                while(!stempty(stack_i)) {

                    insert('c', pop(&stack_i), pop(&stack_r), pop(&stack_v), stack_scope.s[stack_scope.top]);
                }
            }
        }  
    }
#line 1974 "yac.tab.c"
    break;

  case 38:
#line 417 "yac.y"
    { 
        if(stack_v.top != stack_i.top && stack_v.top != -1) 
        {
                yyerror("Imbalanced assignment");
                YYERROR;
        }
        else 
        {
            if(stack_v.top == -1)
            {
                while(!stempty(stack_i)) 
                {

                    insert('v', pop(&stack_i), Tflag, "NULL", stack_scope.s[stack_scope.top]);
                }
            }
            else {
                while(!stempty(stack_i)) {

                    insert('v', pop(&stack_i), pop(&stack_r), pop(&stack_v), stack_scope.s[stack_scope.top]);

                }
            }
        } 
    }
#line 2004 "yac.tab.c"
    break;

  case 39:
#line 443 "yac.y"
    { 
        if(stack_v.top != stack_i.top && stack_v.top != -1) {
            yyerror("Imbalanced assignment");
            YYERROR;
        }
        else 
        {
            if (stack_v.top == -1){
                while(!stempty(stack_i)) 
                {

                    insert('v', pop(&stack_i), Tflag, "NULL", stack_scope.s[stack_scope.top]);

                }
            }
            else 
            {
                while(!stempty(stack_i)) 
                {

                    insert('v', pop(&stack_i), pop(&stack_r), pop(&stack_v), stack_scope.s[stack_scope.top]);
                }
            }
        } 
    }
#line 2034 "yac.tab.c"
    break;

  case 42:
#line 477 "yac.y"
    { 
        if((yyvsp[0].VariableIdList)) 
        {
            printf("Assigning to variables\nIds: %d Exprs: %d\n", seqLen((yyvsp[-1].IdentifierList)), seqLen((yyvsp[0].VariableIdList)->value.n)); 
            value.op[0] = '='; value.op[1] = 0; 
            (yyval.VariableSpecification) = makeNode(OP, value, (yyvsp[-1].IdentifierList), (yyvsp[0].VariableIdList));
        } 
        else {
            printf("Not assigning\n");
            (yyval.VariableSpecification) = NULL;
        }
    }
#line 2051 "yac.tab.c"
    break;

  case 43:
#line 493 "yac.y"
    {	
    (yyval.VariableIdList) = (yyvsp[0].VariableIdListType);
    strcpy(Tflag, (yyvsp[-1].Type)->value.name);
    }
#line 2060 "yac.tab.c"
    break;

  case 44:
#line 498 "yac.y"
    {	
    value.n = (yyvsp[0].ExpressionList); 
    (yyval.VariableIdList) = makeNode(OP, value, NULL, NULL);
    }
#line 2069 "yac.tab.c"
    break;

  case 45:
#line 506 "yac.y"
    {	
    value.n = (yyvsp[0].ExpressionList); 
    (yyval.VariableIdListType) = makeNode(OP, value, NULL, NULL);
    }
#line 2078 "yac.tab.c"
    break;

  case 46:
#line 511 "yac.y"
    {
        (yyval.VariableIdListType) = NULL; 
    }
#line 2086 "yac.tab.c"
    break;

  case 47:
#line 518 "yac.y"
    {
        strcpy(value.name, (yyvsp[0].IDENTIFIER)); 
		(yyval.IdentifierList) = makeNode(ID, value, NULL, NULL); 
        push(&stack_i, value.name);
    }
#line 2096 "yac.tab.c"
    break;

  case 48:
#line 524 "yac.y"
    {
	
	    strcpy(value.name, (yyvsp[-2].IDENTIFIER)); 
		(yyval.IdentifierList) = makeNode(SEQ, value, makeNode(ID, value, NULL, NULL), (yyvsp[0].IdentifierList));
		push(&stack_i, value.name);

    }
#line 2108 "yac.tab.c"
    break;

  case 49:
#line 536 "yac.y"
    {
        (yyval.Type)=(yyvsp[0].TypeName);
    }
#line 2116 "yac.tab.c"
    break;

  case 50:
#line 540 "yac.y"
    {
        (yyval.Type)=(yyvsp[-1].Type);
    }
#line 2124 "yac.tab.c"
    break;

  case 51:
#line 547 "yac.y"
    {
        strcpy(value.name,(yyvsp[0].P_TYPE));
        (yyval.TypeName) = makeNode(ID,value,NULL,NULL);
    }
#line 2133 "yac.tab.c"
    break;

  case 52:
#line 552 "yac.y"
    {
        (yyval.TypeName) = (yyvsp[0].QualifiedID);
    }
#line 2141 "yac.tab.c"
    break;

  case 54:
#line 565 "yac.y"
    {
        (yyval.ExpressionList) = (yyvsp[0].Expression);		 			
    	if ((yyvsp[0].Expression)->type == INT) 
        {
            sprintf(result, "%d", (yyvsp[0].Expression)->value.i);
            push(&stack_r, "int");
        }
        if ((yyvsp[0].Expression)->type == FLOAT) 
        {
            sprintf(result, "%f", (yyvsp[0].Expression)->value.f);
            push(&stack_r, "float");
        }
        if ((yyvsp[0].Expression)->type == STRING) 
        {
            strcpy(result, (yyvsp[0].Expression)->value.str);
            push(&stack_r, "string");
        }
                
        push(&stack_v, result);
    }
#line 2166 "yac.tab.c"
    break;

  case 55:
#line 586 "yac.y"
    { 
        (yyval.ExpressionList) = makeNode(SEQ, value, (yyvsp[-2].Expression), (yyvsp[0].ExpressionList));

        
        if ((yyvsp[-2].Expression)->type == INT) {
            sprintf(result, "%d", (yyvsp[-2].Expression)->value.i);
            push(&stack_r, "int");
        }
        if ((yyvsp[-2].Expression)->type == FLOAT) {
            sprintf(result, "%f", (yyvsp[-2].Expression)->value.f);
            push(&stack_r, "float");
        }
        if ((yyvsp[-2].Expression)->type == STRING) {
            strcpy(result, (yyvsp[-2].Expression)->value.str);
            push(&stack_r, "string");
        }
                
        push(&stack_v, result);
    			
	}
#line 2191 "yac.tab.c"
    break;

  case 62:
#line 619 "yac.y"
    {strcpy(value.op, (yyvsp[0].REL_EQUAL)); (yyval.RelationalOperation) = makeNode(OP, value, NULL, NULL); }
#line 2197 "yac.tab.c"
    break;

  case 98:
#line 672 "yac.y"
    {
        (yyval.UnaryExpression) = (yyvsp[0].PrimaryExpression);
    }
#line 2205 "yac.tab.c"
    break;

  case 99:
#line 679 "yac.y"
    {
        (yyval.PrimaryExpression) = (yyvsp[0].Operand);
    }
#line 2213 "yac.tab.c"
    break;

  case 102:
#line 691 "yac.y"
    {
        (yyval.Operand) = (yyvsp[0].Literal);
    }
#line 2221 "yac.tab.c"
    break;

  case 103:
#line 695 "yac.y"
    {
        (yyval.Operand) = (yyvsp[0].OperandName);
    }
#line 2229 "yac.tab.c"
    break;

  case 104:
#line 699 "yac.y"
    {
        (yyval.Operand) = (yyvsp[-1].Expression);
    }
#line 2237 "yac.tab.c"
    break;

  case 107:
#line 708 "yac.y"
    {
        (yyval.Literal) = (yyvsp[0].BasicLiteral);
    }
#line 2245 "yac.tab.c"
    break;

  case 108:
#line 715 "yac.y"
    {
        value.i = (yyvsp[0].INT_LITERAL); (yyval.BasicLiteral) = makeNode(INT, value, NULL, NULL);
    }
#line 2253 "yac.tab.c"
    break;

  case 109:
#line 719 "yac.y"
    {
        value.f = (yyvsp[0].FLOAT_LITERAL); (yyval.BasicLiteral) = makeNode(FLOAT, value, NULL, NULL);
    }
#line 2261 "yac.tab.c"
    break;

  case 110:
#line 723 "yac.y"
    {
        strcpy(value.str, (yyvsp[0].STRING_LITERAL)); (yyval.BasicLiteral) = makeNode(STRING, value, NULL, NULL);
    }
#line 2269 "yac.tab.c"
    break;

  case 111:
#line 730 "yac.y"
    {
        strcpy(value.name, (yyvsp[0].IDENTIFIER)); (yyval.OperandName) = makeNode(ID, value, NULL, NULL);
    }
#line 2277 "yac.tab.c"
    break;

  case 112:
#line 734 "yac.y"
    {
        strcpy(value.name, (yyvsp[0].P_FUNCTION)); (yyval.OperandName) = makeNode(FUNC, value, NULL, NULL);
    }
#line 2285 "yac.tab.c"
    break;

  case 113:
#line 738 "yac.y"
    {
        (yyval.OperandName) = (yyvsp[0].QualifiedID);
    }
#line 2293 "yac.tab.c"
    break;

  case 114:
#line 748 "yac.y"
    {	
        sprintf(result, "%d", base++);
        push(&stack_scope, result);
    }
#line 2302 "yac.tab.c"
    break;

  case 115:
#line 753 "yac.y"
    { 
        pop(&stack_scope); 
    }
#line 2310 "yac.tab.c"
    break;

  case 129:
#line 785 "yac.y"
    {	
        printf("started\n"); 
        value.op[0] = '='; 
        value.op[1] = 0; 
        printf("Operator: %s\n", value.op); 
        (yyval.Assignment) = makeNode(OP, value, (yyvsp[-2].ExpressionList), (yyvsp[0].ExpressionList));
        strcpy(result, search((yyvsp[-2].ExpressionList)->value.name));

        if(strcmp(result, "int") == 0 && (yyvsp[0].ExpressionList)->type == INT) {
            sprintf(result, "%d", (yyvsp[0].ExpressionList)->value.i);
            update((yyvsp[-2].ExpressionList)->value.name, "int", result);
        }

        else if(strcmp(result, "float") == 0 && (yyvsp[0].ExpressionList)->type == FLOAT) {
            sprintf(result, "%f", (yyvsp[0].ExpressionList)->value.f);
            update((yyvsp[-2].ExpressionList)->value.name, "int", result);
        }	

        else if(strcmp(result, "string") == 0 && (yyvsp[0].ExpressionList)->type == STRING)
            update((yyvsp[-2].ExpressionList)->value.name, "int", (yyvsp[0].ExpressionList)->value.str);

        else {
            yyerror("Error type mismatched assignment");
            YYERROR;
        }

        }
#line 2342 "yac.tab.c"
    break;

  case 131:
#line 818 "yac.y"
    {
        if(stack_v.top != stack_i.top && stack_v.top != -1) {
            yyerror("Imbalanced assignment");
            YYERROR;
        }
        else {
            if (stack_v.top == -1){
                while(!stempty(stack_i)) {

                    insert('v', pop(&stack_i), pop(&stack_r), "NULL", stack_scope.s[stack_scope.top]);

                }
            }
            else {
                while(!stempty(stack_i)) {

                    insert('v', pop(&stack_i), pop(&stack_r), pop(&stack_v), stack_scope.s[stack_scope.top]);

                }
            }
                
        }
    }
#line 2370 "yac.tab.c"
    break;


#line 2374 "yac.tab.c"

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
#line 962 "yac.y"


extern int yylineno;

void yyerror(char const* error) {
	fprintf(stderr, "%d: %s\n", yylineno, error);
}


int main () {
	for(int i=0; i<TABLE_SIZE; i++)
		hashTable[i].hcode = -1;

	sprintf(result, "%d", base);
	base++;
	push(&stack_scope, result);

	// yydebug = 1;
	if ( yyparse() != 0){
		printf("Build Failed. Invalid Code\n\n");
		exit(1);
	}

	printf("\n\n\n");
	printf("---------------------------------Symbol Table---------------------------------\n\n");
	disp_symtbl();
	return 0;
}
