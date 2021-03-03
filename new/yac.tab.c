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

int base = 1000;

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
stack stack_t = {.top = -1};
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
    	/*printf("Error: %s is redeclared..!\n", token);
    	exit(0);*/
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
	printf("%s\t%s\t\t%s\t\t%s\t\t%s\n","Name", "Type","Data Type", "Value", "Scope");

	for(int i=0; i<TABLE_SIZE; i++) {
		if(hashTable[i].hcode != -1 )
			printf("%s\t%c\t\t%s\t\t\t%s\t\t%s\n",hashTable[i].name, hashTable[i].type, hashTable[i].dtype, hashTable[i].value, hashTable[i].scope);
		}

}


#line 252 "yac.tab.c"

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
#line 451 "yac.tab.c"

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
#define YYLAST   561

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  77
/* YYNRULES -- Number of rules.  */
#define YYNRULES  167
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  253

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
       0,   262,   262,   275,   281,   282,   286,   287,   291,   295,
     296,   300,   301,   302,   307,   308,   312,   313,   317,   318,
     319,   324,   346,   370,   371,   375,   379,   383,   384,   390,
     394,   395,   399,   400,   404,   405,   409,   413,   420,   446,
     475,   476,   480,   496,   501,   509,   514,   521,   527,   539,
     543,   550,   555,   562,   568,   589,   613,   614,   615,   616,
     617,   618,   622,   624,   625,   626,   627,   628,   632,   633,
     634,   635,   639,   641,   643,   644,   645,   646,   647,   652,
     653,   654,   655,   656,   657,   661,   662,   663,   664,   665,
     666,   667,   668,   669,   670,   671,   675,   676,   677,   684,
     688,   692,   696,   700,   704,   708,   709,   713,   720,   724,
     728,   735,   739,   743,   754,   759,   753,   766,   767,   771,
     772,   773,   774,   778,   779,   780,   781,   785,   786,   790,
     818,   823,   852,   858,   859,   860,   861,   865,   869,   875,
     876,   880,   884,   885,   889,   893,   897,   901,   902,   903,
     909,   911,   915,   918,   919,   923,   927,   928,   932,   936,
     941,   942,   945,   948,   949,   952,   953,   957
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

#define YYPACT_NINF (-145)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-150)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -28,    13,    26,    -6,  -145,  -145,    22,   132,    -6,  -145,
    -145,    45,    18,    65,  -145,    76,     0,    14,    30,  -145,
     132,  -145,  -145,  -145,  -145,  -145,  -145,    53,    18,  -145,
      72,    69,   129,  -145,    44,    99,   133,  -145,  -145,  -145,
    -145,   129,   129,  -145,   126,  -145,  -145,  -145,    18,    78,
     129,     4,  -145,    81,  -145,    44,  -145,    87,  -145,  -145,
    -145,  -145,    44,  -145,    80,   133,    11,  -145,    57,  -145,
      93,  -145,    91,  -145,  -145,  -145,   138,   101,    57,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,    81,    57,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,    57,  -145,  -145,  -145,
     317,    57,  -145,    98,  -145,  -145,  -145,  -145,    57,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,   380,    57,    57,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,    57,    57,    57,
      57,  -145,    57,  -145,  -145,  -145,  -145,   403,   452,  -145,
     441,   228,   228,   237,    41,  -145,  -145,   -13,   148,   221,
    -145,   127,   453,   292,   102,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,   135,   498,   166,  -145,    91,  -145,
    -145,   116,  -145,  -145,   149,   -31,    66,   119,   122,    57,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,    57,    57,  -145,  -145,  -145,    57,    57,  -145,    57,
      57,   333,    25,    56,  -145,  -145,  -145,   392,   121,   392,
      61,  -145,    57,    77,  -145,   137,  -145,    44,    79,  -145,
     139,   148,   141,  -145,  -145,  -145,  -145,   140,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,   167,    41,    44,    41,
     146,  -145,  -145
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   167,     3,     1,     0,    15,   167,     5,
      11,     0,     0,     0,     6,     0,     0,     0,     0,     2,
      15,    16,    18,    19,    20,     4,    13,     0,    10,    12,
       0,    47,     0,    21,   167,     0,    33,    29,    30,    34,
      35,     0,    38,    40,     0,    14,     7,     8,    10,     0,
       0,     0,    23,     0,    51,     0,    25,     0,    27,    49,
      52,    28,     0,    37,     0,    33,     0,    41,     0,    42,
     167,     9,     0,    48,    22,    24,     0,     0,     0,    36,
      31,    32,    39,   110,   108,   109,   111,     0,   106,   105,
     112,    79,    80,    82,    83,    84,     0,    81,   113,    44,
      54,     0,    61,    98,    99,   102,   107,   103,     0,    43,
      46,   114,    17,    53,    50,    26,    96,     0,     0,     0,
      75,    76,    78,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    77,     0,     0,     0,
       0,    97,     0,   100,    45,   167,   104,    56,    57,    55,
      58,    59,    60,     0,   115,   118,   101,   111,   167,     0,
     120,     0,     0,   123,     0,   117,   119,   124,   125,   126,
     121,   122,   150,   151,     0,     0,    54,   144,     0,   133,
     134,     0,   139,   135,     0,   136,   111,     0,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,     0,     0,   127,   128,   116,   148,   147,   132,     0,
       0,     0,     0,     0,   131,   129,   130,   141,     0,   146,
       0,   157,     0,     0,   154,     0,   164,     0,     0,   161,
       0,   167,     0,   156,   152,   153,   167,   165,   163,   158,
     160,   167,   145,   138,   142,   143,     0,   155,     0,   162,
       0,   166,   159
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,  -145,   201,  -145,  -145,   163,   109,   192,  -145,
      92,  -145,  -145,   -14,  -145,  -145,  -145,  -145,   164,   197,
    -145,  -145,  -145,   190,   -26,  -145,  -145,    -9,   494,  -145,
     -33,   -65,   -84,  -145,  -145,  -145,  -145,  -145,   -49,    21,
    -145,  -145,  -145,  -145,  -145,    62,  -145,  -145,  -107,  -145,
    -144,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,    12,  -145,
    -145,  -145,  -145,    15,  -145,    -7,    -3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,    27,    47,    48,    19,    20,
     160,    22,    51,    33,    56,    57,    23,    37,    64,    65,
      39,    40,    24,    42,    43,    69,   109,   161,   237,    59,
      98,   162,   100,   138,   139,   140,   101,   202,   102,   103,
     143,   104,   105,   106,   107,   112,   145,   164,   154,   165,
     166,   167,   168,   169,   170,   178,   179,   180,   181,   218,
     243,   182,   244,   183,   184,   171,   172,   223,   224,   225,
     173,   188,   228,   229,   230,   238,   155
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    60,    60,    99,     1,     9,    31,    34,  -149,    44,
      31,    60,   117,   115,   177,   187,    67,    31,    52,     4,
      35,    10,    60,    34,    11,    10,     5,     6,    11,    60,
     -47,    61,    44,    44,   147,   148,    31,    75,   116,  -140,
      67,    73,    34,   144,    83,    84,    85,   157,    26,    76,
      53,    50,   141,    87,   150,   151,   152,    44,   153,    32,
      83,    84,    85,    86,    74,   221,   222,   110,    29,    87,
     163,    82,   149,    36,   176,   163,    16,    17,    18,   158,
      13,    12,    30,   159,    13,    88,    89,   242,    90,    41,
      54,    91,    92,   175,    93,    94,   226,   227,    95,    21,
      96,    88,    89,    55,    90,    53,    97,    91,    92,   211,
      93,    94,    21,    46,    95,    14,    96,   221,   222,   226,
     227,    28,    97,   232,   214,   217,   219,   142,    76,   247,
      50,    49,    53,    50,   249,    31,   215,   216,    72,    35,
      80,   214,   215,    76,   113,    54,   234,   163,   239,   174,
      78,    83,    84,    85,   157,   185,   108,   233,    55,   111,
      87,   114,    62,   163,   142,   163,    15,    16,    17,    18,
     189,   205,    54,   118,   119,   120,   121,   122,   206,   123,
     124,   125,   126,   127,   128,    55,   209,   212,   210,    68,
     213,   231,    88,    89,    60,    90,   203,   204,    91,    92,
     246,    93,    94,   250,   248,    95,   252,    96,   236,    25,
     241,    71,    45,    97,    38,    60,   129,   130,   131,   132,
     133,   134,   135,   136,    83,    84,    85,   186,   245,    81,
     137,    66,   220,    87,  -137,   235,  -123,   120,   121,   122,
     208,   251,     0,   240,   118,   119,   120,   121,   122,     0,
     123,   124,   125,   126,   127,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,     0,    90,     0,
       0,    91,    92,     0,    93,    94,     0,     0,    95,     0,
      96,     0,   133,   134,   135,   136,    97,   129,   130,   131,
     132,   133,   134,   135,   136,     0,     0,     0,     0,   118,
     119,   120,   121,   122,   156,   123,   124,   125,   126,   127,
     128,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,   203,   204,   118,   119,   120,   121,   122,     0,
     123,   124,   125,   126,   127,   128,    83,    84,    85,    86,
       0,     0,   129,   130,   131,   132,   133,   134,   135,   136,
       0,     0,     0,     0,     0,   -54,   137,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   129,   130,   131,
     132,   133,   134,   135,   136,     0,     0,    88,    89,     0,
      90,   137,     0,     0,     0,     0,     0,   118,   119,   120,
     121,   122,    96,   123,   124,   125,   126,   127,   128,   118,
     119,   120,   121,   122,     0,   123,   124,   125,   126,   127,
     128,   119,   120,   121,   122,     0,   123,   124,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   130,   131,   132,   133,   134,   135,   136,     0,     0,
     146,     0,   129,   130,   131,   132,   133,   134,   135,   136,
     120,   121,   122,   129,   130,   131,   132,   133,   134,   135,
     136,   120,   121,   122,     0,   123,   124,   125,   126,   127,
     128,     0,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,     0,     0,     0,     0,     0,     0,     0,
       0,   129,   130,   131,   132,   133,   134,   135,   136,     0,
       0,     0,   129,   130,   131,   132,   133,   134,   135,   136,
       0,     0,     0,     0,     0,     0,   201,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    58,    63,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
       0,     0,     0,     0,     0,     0,    79,     0,     0,     0,
       0,   207
};

static const yytype_int16 yycheck[] =
{
       3,    34,    35,    68,    32,     8,     6,    16,    39,    18,
       6,    44,    96,    78,   158,   159,    42,     6,    32,     6,
       6,     3,    55,    32,     6,     3,     0,    33,     6,    62,
      43,    34,    41,    42,   118,   119,     6,    51,    87,    70,
      66,    50,    51,   108,     3,     4,     5,     6,     3,    62,
       6,    64,   101,    12,   138,   139,   140,    66,   142,    59,
       3,     4,     5,     6,    60,    40,    41,    70,     3,    12,
     154,    60,   137,    59,   158,   159,    35,    36,    37,    38,
      62,    59,     6,    42,    62,    44,    45,   231,    47,    59,
      46,    50,    51,   158,    53,    54,    40,    41,    57,     7,
      59,    44,    45,    59,    47,     6,    65,    50,    51,    43,
      53,    54,    20,    60,    57,     6,    59,    40,    41,    40,
      41,    12,    65,    62,   189,   209,   210,    66,    62,   236,
      64,    59,     6,    64,   241,     6,   201,   202,    60,     6,
      60,   206,   207,    62,     6,    46,    69,   231,    69,   158,
      63,     3,     4,     5,     6,   158,    63,   222,    59,    68,
      12,    60,    63,   247,    66,   249,    34,    35,    36,    37,
      43,    69,    46,     7,     8,     9,    10,    11,    43,    13,
      14,    15,    16,    17,    18,    59,    70,    68,    39,    63,
      68,    70,    44,    45,   227,    47,    30,    31,    50,    51,
      59,    53,    54,    36,    64,    57,    60,    59,    71,     8,
      71,    48,    20,    65,    17,   248,    50,    51,    52,    53,
      54,    55,    56,    57,     3,     4,     5,     6,   231,    65,
      64,    41,   211,    12,    68,   223,    70,     9,    10,    11,
     178,   248,    -1,   228,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,    -1,
      -1,    50,    51,    -1,    53,    54,    -1,    -1,    57,    -1,
      59,    -1,    54,    55,    56,    57,    65,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,     7,
       8,     9,    10,    11,    67,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    16,    17,    18,     3,     4,     5,     6,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    44,    45,    -1,
      47,    64,    -1,    -1,    -1,    -1,    -1,     7,     8,     9,
      10,    11,    59,    13,    14,    15,    16,    17,    18,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    16,    17,
      18,     8,     9,    10,    11,    -1,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      60,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
       9,    10,    11,    50,    51,    52,    53,    54,    55,    56,
      57,     9,    10,    11,    -1,    13,    14,    15,    16,    17,
      18,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    63
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
     111,    40,    41,   139,   140,   141,    40,    41,   144,   145,
     146,    70,    62,   103,    69,   140,    71,   100,   147,    69,
     145,    71,   122,   132,   134,   148,    59,   120,    64,   120,
      36,   147,    60
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
     144,   144,   145,   146,   146,   147,   147,   148
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
       2,     1,     3,     2,     1,     1,     3,     0
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
#line 263 "yac.y"
    {
        if(yychar != YYEOF) 
        {
            printf("Invalid - reached start symbol before EOF\n"); YYERROR;
        }
        printf("Valid\n"); 
        YYACCEPT;
    }
#line 1913 "yac.tab.c"
    break;

  case 21:
#line 325 "yac.y"
    {
        if(stack_v.top != stack_i.top && stack_v.top != -1) {
            yyerror("Imbalanced assignment");
            YYERROR;
        }
        else {
            if (stack_v.top == -1){
                while(!stempty(stack_i)) {

                    insert('c', pop(&stack_i), pop(&stack_t), "NULL", stack_scope.s[stack_scope.top]);

                }
            }
            else {
                while(!stempty(stack_i)) {

                    insert('c', pop(&stack_i), pop(&stack_t), pop(&stack_v), stack_scope.s[stack_scope.top]);
                }
            }
        } 
    }
#line 1939 "yac.tab.c"
    break;

  case 22:
#line 347 "yac.y"
    {
        if(stack_v.top != stack_i.top && stack_v.top != -1) {
            yyerror("Imbalanced assignment");
            YYERROR;
        }
        else {
            if (stack_v.top == -1){
                while(!stempty(stack_i)) {

                    insert('c', pop(&stack_i), pop(&stack_t), "NULL", stack_scope.s[stack_scope.top]);
                }
            }
            else {
                while(!stempty(stack_i)) {

                    insert('c', pop(&stack_i), pop(&stack_t), pop(&stack_v), stack_scope.s[stack_scope.top]);
                }
            }
        }  
    }
#line 1964 "yac.tab.c"
    break;

  case 38:
#line 421 "yac.y"
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

                    insert('v', pop(&stack_i), pop(&stack_t), pop(&stack_v), stack_scope.s[stack_scope.top]);

                }
            }
        } 
    }
#line 1994 "yac.tab.c"
    break;

  case 39:
#line 447 "yac.y"
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

                    insert('v', pop(&stack_i), pop(&stack_t), pop(&stack_v), stack_scope.s[stack_scope.top]);
                }
            }
        } 
    }
#line 2024 "yac.tab.c"
    break;

  case 42:
#line 481 "yac.y"
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
#line 2041 "yac.tab.c"
    break;

  case 43:
#line 497 "yac.y"
    {	
    (yyval.VariableIdList) = (yyvsp[0].VariableIdListType);
    strcpy(Tflag, (yyvsp[-1].Type)->value.name);
    }
#line 2050 "yac.tab.c"
    break;

  case 44:
#line 502 "yac.y"
    {	
    value.n = (yyvsp[0].ExpressionList); 
    (yyval.VariableIdList) = makeNode(OP, value, NULL, NULL);
    }
#line 2059 "yac.tab.c"
    break;

  case 45:
#line 510 "yac.y"
    {	
    value.n = (yyvsp[0].ExpressionList); 
    (yyval.VariableIdListType) = makeNode(OP, value, NULL, NULL);
    }
#line 2068 "yac.tab.c"
    break;

  case 46:
#line 515 "yac.y"
    {
        (yyval.VariableIdListType) = NULL; 
    }
#line 2076 "yac.tab.c"
    break;

  case 47:
#line 522 "yac.y"
    {
        strcpy(value.name, (yyvsp[0].IDENTIFIER)); 
		(yyval.IdentifierList) = makeNode(ID, value, NULL, NULL); 
        push(&stack_i, value.name);
    }
#line 2086 "yac.tab.c"
    break;

  case 48:
#line 528 "yac.y"
    {
	
	    strcpy(value.name, (yyvsp[-2].IDENTIFIER)); 
		(yyval.IdentifierList) = makeNode(SEQ, value, makeNode(ID, value, NULL, NULL), (yyvsp[0].IdentifierList));
		push(&stack_i, value.name);

    }
#line 2098 "yac.tab.c"
    break;

  case 49:
#line 540 "yac.y"
    {
        (yyval.Type)=(yyvsp[0].TypeName);
    }
#line 2106 "yac.tab.c"
    break;

  case 50:
#line 544 "yac.y"
    {
        (yyval.Type)=(yyvsp[-1].Type);
    }
#line 2114 "yac.tab.c"
    break;

  case 51:
#line 551 "yac.y"
    {
        strcpy(value.name,(yyvsp[0].P_TYPE));
        (yyval.TypeName) = makeNode(ID,value,NULL,NULL);
    }
#line 2123 "yac.tab.c"
    break;

  case 52:
#line 556 "yac.y"
    {
        (yyval.TypeName) = (yyvsp[0].QualifiedID);
    }
#line 2131 "yac.tab.c"
    break;

  case 54:
#line 569 "yac.y"
    {
        (yyval.ExpressionList) = (yyvsp[0].Expression);		 			
    	if ((yyvsp[0].Expression)->type == INT) 
        {
            sprintf(result, "%d", (yyvsp[0].Expression)->value.i);
            push(&stack_t, "int");
        }
        if ((yyvsp[0].Expression)->type == FLOAT) 
        {
            sprintf(result, "%f", (yyvsp[0].Expression)->value.f);
            push(&stack_t, "float");
        }
        if ((yyvsp[0].Expression)->type == STRING) 
        {
            strcpy(result, (yyvsp[0].Expression)->value.str);
            push(&stack_t, "string");
        }
                
        push(&stack_v, result);
    }
#line 2156 "yac.tab.c"
    break;

  case 55:
#line 590 "yac.y"
    { 
        (yyval.ExpressionList) = makeNode(SEQ, value, (yyvsp[-2].Expression), (yyvsp[0].ExpressionList));

        
        if ((yyvsp[-2].Expression)->type == INT) {
            sprintf(result, "%d", (yyvsp[-2].Expression)->value.i);
            push(&stack_t, "int");
        }
        if ((yyvsp[-2].Expression)->type == FLOAT) {
            sprintf(result, "%f", (yyvsp[-2].Expression)->value.f);
            push(&stack_t, "float");
        }
        if ((yyvsp[-2].Expression)->type == STRING) {
            strcpy(result, (yyvsp[-2].Expression)->value.str);
            push(&stack_t, "string");
        }
                
        push(&stack_v, result);
    			
	}
#line 2181 "yac.tab.c"
    break;

  case 62:
#line 623 "yac.y"
    {strcpy(value.op, (yyvsp[0].REL_EQUAL)); (yyval.RelationalOperation) = makeNode(OP, value, NULL, NULL); }
#line 2187 "yac.tab.c"
    break;

  case 72:
#line 640 "yac.y"
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; (yyval.MultipyOperation) = makeNode(OP, value, NULL, NULL);}
#line 2193 "yac.tab.c"
    break;

  case 73:
#line 642 "yac.y"
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; (yyval.MultipyOperation) = makeNode(OP, value, NULL, NULL);}
#line 2199 "yac.tab.c"
    break;

  case 98:
#line 678 "yac.y"
    {
        (yyval.UnaryExpression) = (yyvsp[0].PrimaryExpression);
    }
#line 2207 "yac.tab.c"
    break;

  case 99:
#line 685 "yac.y"
    {
        (yyval.PrimaryExpression) = (yyvsp[0].Operand);
    }
#line 2215 "yac.tab.c"
    break;

  case 102:
#line 697 "yac.y"
    {
        (yyval.Operand) = (yyvsp[0].Literal);
    }
#line 2223 "yac.tab.c"
    break;

  case 103:
#line 701 "yac.y"
    {
        (yyval.Operand) = (yyvsp[0].OperandName);
    }
#line 2231 "yac.tab.c"
    break;

  case 104:
#line 705 "yac.y"
    {
        (yyval.Operand) = (yyvsp[-1].Expression);
    }
#line 2239 "yac.tab.c"
    break;

  case 107:
#line 714 "yac.y"
    {
        (yyval.Literal) = (yyvsp[0].BasicLiteral);
    }
#line 2247 "yac.tab.c"
    break;

  case 108:
#line 721 "yac.y"
    {
        value.i = (yyvsp[0].INT_LITERAL); (yyval.BasicLiteral) = makeNode(INT, value, NULL, NULL);
    }
#line 2255 "yac.tab.c"
    break;

  case 109:
#line 725 "yac.y"
    {
        value.f = (yyvsp[0].FLOAT_LITERAL); (yyval.BasicLiteral) = makeNode(FLOAT, value, NULL, NULL);
    }
#line 2263 "yac.tab.c"
    break;

  case 110:
#line 729 "yac.y"
    {
        strcpy(value.str, (yyvsp[0].STRING_LITERAL)); (yyval.BasicLiteral) = makeNode(STRING, value, NULL, NULL);
    }
#line 2271 "yac.tab.c"
    break;

  case 111:
#line 736 "yac.y"
    {
        strcpy(value.name, (yyvsp[0].IDENTIFIER)); (yyval.OperandName) = makeNode(ID, value, NULL, NULL);
    }
#line 2279 "yac.tab.c"
    break;

  case 112:
#line 740 "yac.y"
    {
        strcpy(value.name, (yyvsp[0].P_FUNCTION)); (yyval.OperandName) = makeNode(FUNC, value, NULL, NULL);
    }
#line 2287 "yac.tab.c"
    break;

  case 113:
#line 744 "yac.y"
    {
        (yyval.OperandName) = (yyvsp[0].QualifiedID);
    }
#line 2295 "yac.tab.c"
    break;

  case 114:
#line 754 "yac.y"
    {	
        sprintf(result, "%d", base++);
        push(&stack_scope, result);
    }
#line 2304 "yac.tab.c"
    break;

  case 115:
#line 759 "yac.y"
    { 
        pop(&stack_scope); 
    }
#line 2312 "yac.tab.c"
    break;

  case 129:
#line 791 "yac.y"
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
#line 2344 "yac.tab.c"
    break;

  case 131:
#line 824 "yac.y"
    {
        if(stack_v.top != stack_i.top && stack_v.top != -1) {
            yyerror("Imbalanced assignment");
            YYERROR;
        }
        else {
            if (stack_v.top == -1){
                while(!stempty(stack_i)) {

                    insert('v', pop(&stack_i), pop(&stack_t), "NULL", stack_scope.s[stack_scope.top]);

                }
            }
            else {
                while(!stempty(stack_i)) {

                    insert('v', pop(&stack_i), pop(&stack_t), pop(&stack_v), stack_scope.s[stack_scope.top]);

                }
            }
                
        }
    }
#line 2372 "yac.tab.c"
    break;

  case 150:
#line 910 "yac.y"
    {printf("switch expr done\n");}
#line 2378 "yac.tab.c"
    break;

  case 159:
#line 937 "yac.y"
    {printf("typeswitchguard done\n");}
#line 2384 "yac.tab.c"
    break;


#line 2388 "yac.tab.c"

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
#line 967 "yac.y"


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
		printf("BUILD FAILED...!!\n\n");
		exit(1);
	}

	printf("\n\n\n");
	printf("---------------------------------Symbol Table---------------------------------\n\n");
	disp_symtbl();
	return 0;
}
