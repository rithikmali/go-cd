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
int scope_depth = 0;
int scope_id = 0;

typedef struct symbol_table {
  char name[31];
  char dtype[10];
  char type;
  char value[20];
  int scope_depth;
  int scope_id;
  int hcode;
} ST;

ST hashTable[10009];

struct Stack {
  char s[25][25];
  int top;
};

typedef struct queue {
  char s[25][200];
  int front;
	int back;
} queue;

typedef struct Stack stack;

stack stack_i = {.top = -1};
stack stack_v = {.top = -1};
stack stack_t = {.top = -1};
stack stack_scope = {.top = -1};
stack if_cond = {.top = -1};
queue for_loc = {.front = -1, .back = -1};

void add(queue *p_st, char *item) {
	if (p_st->back==199) {
		printf("Cannot insert into full queue\n");
		exit(1);
	}
	strcpy(p_st->s[++p_st->back], item);
}

char *rem(queue *p_st) {
	if (p_st->front==p_st->back) {
		printf("Cannot remove from empty queue\n");
		exit(1);
	}
	char *item;
	item = strdup(p_st->s[++p_st->front]);
	return (item);
}

char result[20];
char Tflag[20] = "";

int tid = 0;
int lid = 0;
char temp[10];
char label[10];
FILE* icfile;

void newtemp() {
	sprintf(temp, "_t%d", tid++);
}

void newlabel() {
	sprintf(label, "L%d", lid++);
}

int stfull(stack st, int size) {
  if (st.top >= size - 1)
    return 1;
  else
    return 0;
}

void push(stack *p_st, char *item) {
  p_st->top++;
  strcpy(p_st->s[p_st->top], item);
}

int stempty(stack st) {
  if (st.top == -1)
    return 1;
  else
    return 0;
}

char *pop(stack *p_st) {
  char *item;
  item = p_st->s[p_st->top];
  p_st->top--;
  return (item);
}

int hash1(char *token) {
  int hash = 0;
  for (int i = 0; token[i] != '\0'; i++) {
    hash = (256 * hash + token[i]) % 1000000009;
  }
  hash = hash % TABLE_SIZE;
  return hash;
}

int check(char *token) {
  int index1 = hash1(token);
  int i = 0;
  while (i < TABLE_SIZE &&
         !(strcmp(hashTable[(index1 + i) % TABLE_SIZE].name, token) == 0 &&
				 hashTable[(index1 + i) % TABLE_SIZE].scope_depth == scope_depth &&
				 hashTable[(index1 + i) % TABLE_SIZE].scope_id == scope_id))
    i++;

  if (i == TABLE_SIZE)
    return -1;
  else
    return index1 + i;
}

int check_parent_scopes(char *token) {
  int index1 = hash1(token);
  int i = 0;
  while (i < TABLE_SIZE &&
         !(strcmp(hashTable[(index1 + i) % TABLE_SIZE].name, token) == 0 &&
				 (hashTable[(index1 + i) % TABLE_SIZE].scope_depth == scope_depth &&
				 hashTable[(index1 + i) % TABLE_SIZE].scope_id == scope_id) ||
				 hashTable[(index1 + i) % TABLE_SIZE].scope_depth < scope_depth))
    i++;

  if (i == TABLE_SIZE)
    return -1;
  else
    return index1 + i;
}

void insert(char type, char *token, char *dtype, char *value, int scope_depth, int scope_id) {
  if (check(token) != -1) {
    yyerror("variable is redeclared");
		exit(1);
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
				hashTable[newIndex].scope_depth = scope_depth;
				hashTable[newIndex].scope_id = scope_id;
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
		hashTable[index].scope_depth = scope_depth;
		hashTable[index].scope_id = scope_id;
    hashTable[index].type = type;
    hashTable[index].hcode = 1;
  }
}
char *search(char *token) {
  int index1 = hash1(token);
  int i = 0;
  while (i < TABLE_SIZE &&
         strcmp(hashTable[(index1 + i) % TABLE_SIZE].name, token) != 0)
    i++;
  if (i == TABLE_SIZE) {
		return NULL;
  } else
    return hashTable[index1 + i].dtype;
}

int max_id_at_depth[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int next_id(int scope_depth) {
	int scope_id = -1;
	if (scope_depth == 1) {
		scope_id = 1;
	} else {
		scope_id = ++max_id_at_depth[scope_depth];
	}
	return scope_id;
}

int restore_id(int scope_depth) {
	int scope_id = -1;
	if (scope_depth == 1) {
		scope_id = 1;
	} else {
		scope_id = max_id_at_depth[scope_depth];
	}
	return scope_id;
}

void update(char *token, char *dtype, char *value) {
  int index = check_parent_scopes(token);
  if (index == -1) {
		char error[100];
		printf("In here\n");
		sprintf(error, "%s is not defined", token);
    yyerror(error);
    exit(1);
  }

  if (hashTable[index].type == 'c') {
		char error[100];
		sprintf(error, "cannot assign to %s (declared const)", token);
		yyerror(error);
    exit(1);
  } else {
    if (strcmp(hashTable[index].value, "NULL") != 0)
      strcpy(hashTable[index].value, value);
    if (strcmp(hashTable[index].dtype, "NULL") != 0)
      strcpy(hashTable[index].dtype, dtype);
  }
}

void disp_symtbl() {
  int base = 1000;
  printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n", "Name", "Data Type", "Value",
         "Scope Depth", "Scope ID");

  for (int i = 0; i < TABLE_SIZE; i++) {
    if (hashTable[i].hcode != -1)
      printf("%s\t\t%s\t\t\t%s\t\t%d\t\t%d\n", hashTable[i].name,
             hashTable[i].dtype, hashTable[i].value,
             hashTable[i].scope_depth, hashTable[i].scope_id);
  }
}

void doAssign(char decltype, Node *lhs, Node *rhs) {
	if (lhs==NULL && rhs==NULL) {
		Tflag[0] = 0;
		return;
	}
	if (seqLen(lhs) != seqLen(rhs) && seqLen(rhs) != 0) {
		yyerror("Imbalanced assignment");
		exit(1);
	} else {
		if (seqLen(rhs) == 0){
			insert(decltype, pop(&stack_i), Tflag, "NULL", scope_depth, scope_id);
			doAssign(decltype, lhs->rop, rhs);
		} else {
			if (Tflag[0] != 0) {
				if (strcmp(pop(&stack_t),Tflag) != 0) {
					yyerror("Mismatch between declared type and assigned value");
					exit(1);
				}
				insert(decltype, pop(&stack_i), Tflag, pop(&stack_v), scope_depth, scope_id);
			} else {
				insert(decltype, pop(&stack_i), pop(&stack_t), pop(&stack_v), scope_depth, scope_id);
			}
		}
		fprintf(icfile, "%s = %s\n", lhs->lop->value.name, rhs->lop->loc);
		doAssign(decltype, lhs->rop, rhs->rop);
	} 
}

void doAssignExisting(Node *lhs, Node *rhs) {	
	if (lhs==NULL && rhs==NULL) {
		return;
	}
	if (seqLen(lhs) != seqLen(rhs)) {
		yyerror("Imbalanced assignment");
		exit(1);
	} else {
		char* res = search(lhs->lop->value.name);
		if (res==NULL) {
			char error[100];
			sprintf(error, "%s is not defined", lhs->lop->value.name);
			yyerror(error);
			exit(1);
		}
		strcpy(result, res);

		Node *cur = rhs->lop;
		while(cur->type == OP) {
			cur = cur->lop;
		}
		int type = cur->type;
		union NodeVal value = cur->value;
		if(cur->type == ID) {
			char *decltype = search(cur->value.name);
			if(decltype==NULL) {
				char error[100];
				sprintf(error, "%s is not defined", lhs->lop->value.name);
				yyerror(error);
				exit(1);
			}
		}
		printf("%s %d\n", result, type);
		if(strcmp(result, "int") == 0 && type == INT) {
			sprintf(result, "%d", value.i);
			update(lhs->lop->value.name, "int", result);
		} else if(strcmp(result, "float") == 0 && type == FLOAT) {
			sprintf(result, "%f", value.f);
			update(lhs->lop->value.name, "float", result);
		} else if(strcmp(result, "string") == 0 && type == STRING) {
			update(lhs->lop->value.name, "string", value.str);
		} else if(strcmp(result, "rune") == 0 && type == RUNE) {
			update(lhs->lop->value.name, "rune", value.str);
		} else if(strcmp(result, "bool") == 0 && type == BOOL) {
			sprintf(result, "%dB", value.b);
			update(lhs->lop->value.name, "bool", result);
		} else {
			yyerror("Error: type mismatched assignment");
			exit(1);
		}
		fprintf(icfile, "%s = %s\n", lhs->lop->value.name, rhs->lop->loc);
	}
	doAssignExisting(lhs->rop, rhs->rop);
}


#line 411 "yac.tab.c"

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
    KEYWORD_BREAK = 262,
    KEYWORD_DEFAULT = 263,
    KEYWORD_FUNC = 264,
    KEYWORD_INTERFACE = 265,
    KEYWORD_SELECT = 266,
    KEYWORD_CASE = 267,
    KEYWORD_DEFER = 268,
    KEYWORD_GO = 269,
    KEYWORD_MAP = 270,
    KEYWORD_STRUCT = 271,
    KEYWORD_CHAN = 272,
    KEYWORD_ELSE = 273,
    KEYWORD_GOTO = 274,
    KEYWORD_PACKAGE = 275,
    KEYWORD_SWITCH = 276,
    KEYWORD_CONST = 277,
    KEYWORD_FALLTHROUGH = 278,
    KEYWORD_IF = 279,
    KEYWORD_RANGE = 280,
    KEYWORD_TYPE = 281,
    KEYWORD_CONTINUE = 282,
    KEYWORD_FOR = 283,
    KEYWORD_IMPORT = 284,
    KEYWORD_RETURN = 285,
    KEYWORD_VAR = 286,
    LOGICAL_OR = 287,
    LOGICAL_AND = 288,
    LSHIFT = 289,
    RSHIFT = 290,
    AMPXOR = 291,
    CHANNEL_ASSIGN = 292,
    REL_EQUAL = 293,
    REL_NEQUAL = 294,
    REL_LT = 295,
    REL_LEQ = 296,
    REL_GT = 297,
    REL_GEQ = 298,
    ADD_ASSIGN = 299,
    SUB_ASSIGN = 300,
    OR_ASSIGN = 301,
    XOR_ASSIGN = 302,
    MUL_ASSIGN = 303,
    DIV_ASSIGN = 304,
    MOD_ASSIGN = 305,
    AND_ASSIGN = 306,
    LSHIFT_ASSIGN = 307,
    RSHIFT_ASSIGN = 308,
    AMPXOR_ASSIGN = 309,
    INC_ASSIGN = 310,
    DEC_ASSIGN = 311,
    SHORT_DECLARATION = 312,
    P_BOOL = 313,
    P_NIL = 314,
    P_TYPE = 315,
    P_FUNCTION = 316,
    EMPTY = 317,
    NORMAL = 318,
    P_UNARY = 319,
    PreferToRightParen = 320
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
  /* ConstSpecification  */
  struct node * ConstSpecification;
  /* ConstIdList  */
  struct node * ConstIdList;
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
#line 642 "yac.tab.c"

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
#define YYLAST   507

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  82
/* YYNRULES -- Number of rules.  */
#define YYNRULES  173
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  262

#define YYUNDEFTOK  2
#define YYMAXUTOK   320


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
       2,     2,     2,    79,     2,     2,     2,    70,    71,     2,
      73,    74,    68,    64,    78,    65,    76,    69,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    85,    84,
       2,    77,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    80,     2,    81,    67,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    82,    66,    83,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    72,
      75
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   432,   432,   445,   451,   452,   456,   457,   461,   465,
     466,   470,   471,   472,   477,   478,   482,   483,   487,   488,
     489,   494,   495,   524,   525,   529,   538,   546,   550,   556,
     560,   561,   565,   566,   570,   571,   575,   579,   586,   587,
     614,   615,   619,   638,   643,   651,   656,   663,   669,   681,
     685,   692,   697,   704,   717,   744,   775,   783,   791,   800,
     808,   816,   821,   823,   825,   827,   829,   831,   836,   838,
     840,   842,   847,   849,   851,   853,   855,   857,   859,   865,
     867,   869,   871,   873,   875,   880,   882,   884,   886,   888,
     890,   892,   894,   896,   898,   900,   905,   907,   916,   924,
     928,   932,   936,   940,   944,   948,   950,   955,   962,   966,
     970,   977,   981,   985,   996,  1001,   995,  1009,  1010,  1014,
    1015,  1016,  1017,  1021,  1022,  1023,  1024,  1028,  1032,  1039,
    1046,  1054,  1064,  1069,  1063,  1080,  1081,  1082,  1083,  1087,
    1095,  1098,  1100,  1094,  1109,  1110,  1114,  1118,  1119,  1123,
    1127,  1131,  1135,  1136,  1137,  1143,  1144,  1148,  1151,  1152,
    1157,  1156,  1171,  1183,  1187,  1188,  1192,  1193,  1197,  1201,
    1202,  1206,  1207,  1210
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING_LITERAL", "INT_LITERAL",
  "FLOAT_LITERAL", "IDENTIFIER", "KEYWORD_BREAK", "KEYWORD_DEFAULT",
  "KEYWORD_FUNC", "KEYWORD_INTERFACE", "KEYWORD_SELECT", "KEYWORD_CASE",
  "KEYWORD_DEFER", "KEYWORD_GO", "KEYWORD_MAP", "KEYWORD_STRUCT",
  "KEYWORD_CHAN", "KEYWORD_ELSE", "KEYWORD_GOTO", "KEYWORD_PACKAGE",
  "KEYWORD_SWITCH", "KEYWORD_CONST", "KEYWORD_FALLTHROUGH", "KEYWORD_IF",
  "KEYWORD_RANGE", "KEYWORD_TYPE", "KEYWORD_CONTINUE", "KEYWORD_FOR",
  "KEYWORD_IMPORT", "KEYWORD_RETURN", "KEYWORD_VAR", "LOGICAL_OR",
  "LOGICAL_AND", "LSHIFT", "RSHIFT", "AMPXOR", "CHANNEL_ASSIGN",
  "REL_EQUAL", "REL_NEQUAL", "REL_LT", "REL_LEQ", "REL_GT", "REL_GEQ",
  "ADD_ASSIGN", "SUB_ASSIGN", "OR_ASSIGN", "XOR_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "AND_ASSIGN", "LSHIFT_ASSIGN",
  "RSHIFT_ASSIGN", "AMPXOR_ASSIGN", "INC_ASSIGN", "DEC_ASSIGN",
  "SHORT_DECLARATION", "P_BOOL", "P_NIL", "P_TYPE", "P_FUNCTION", "EMPTY",
  "NORMAL", "'+'", "'-'", "'|'", "'^'", "'*'", "'/'", "'%'", "'&'",
  "P_UNARY", "'('", "')'", "PreferToRightParen", "'.'", "'='", "','",
  "'!'", "'['", "']'", "'{'", "'}'", "';'", "':'", "$accept", "s",
  "PackageClause", "ImportDeclarations", "ImportDeclaration",
  "ImportSpecificationList", "ImportSpecificationList2",
  "ImportSpecification", "TopLevelDeclarations", "TopLevelDeclaration",
  "Declaration", "ConstDeclaration", "ConstSpecifications",
  "ConstSpecification", "ConstIdList", "PreConstIdList", "TypeDeclaration",
  "TypeSpecifications", "TypeSpecificationList", "TypeSpecification",
  "AliasDeclaration", "TypeDefinition", "VariableDeclaration",
  "VariableSpecifications", "VariableSpecification", "VariableIdList",
  "VariableIdListType", "IdentifierList", "Type", "TypeName",
  "QualifiedID", "ExpressionList", "Expression", "RelationalOperation",
  "AddOperation", "MultipyOperation", "UnaryOperation", "AssignOperation",
  "UnaryExpression", "PrimaryExpression", "Index", "Operand", "Literal",
  "BasicLiteral", "OperandName", "CodeBlock", "$@1", "$@2", "Statements",
  "Statement", "SimpleStatement", "IncrementDecrement", "Assignment",
  "ShortDeclaration", "ForStatement", "@3", "@4", "ForClauseParent",
  "ForCondition", "ForClause", "@5", "$@6", "$@7", "ForClauseInit",
  "ForClauseCondition", "ForClauseUpdation", "InitializeStatement",
  "UpdationStatement", "RangeClause", "PreForRange", "SwitchStatement",
  "ExprSwitchStmt", "ExprCaseClauses", "ExprCaseClause", "@8",
  "TypeSwitchStmt", "TypeSwitchGuard", "TypeCaseClauses", "TypeCaseClause",
  "TypeSwitchCase", "TypeList", "empty", YY_NULLPTR
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
     315,   316,   317,   318,    43,    45,   124,    94,    42,    47,
      37,    38,   319,    40,    41,   320,    46,    61,    44,    33,
      91,    93,   123,   125,    59,    58
};
# endif

#define YYPACT_NINF (-179)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-155)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,    52,    87,    81,  -179,  -179,    15,   127,    81,  -179,
    -179,    58,    10,   108,  -179,   115,    32,    40,    47,  -179,
     127,  -179,  -179,  -179,  -179,  -179,  -179,    59,    10,  -179,
      62,    54,   137,  -179,    29,     5,   146,  -179,  -179,  -179,
    -179,   137,  -179,    57,  -179,  -179,  -179,    10,    68,   137,
      24,  -179,    78,  -179,    29,  -179,    86,  -179,  -179,  -179,
      29,  -179,    95,   146,    25,  -179,    36,  -179,   102,  -179,
      99,  -179,  -179,  -179,   179,   114,    36,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,    78,    36,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,    36,  -179,  -179,   111,   387,
      36,  -179,   113,  -179,  -179,  -179,  -179,    36,  -179,  -179,
    -179,  -179,  -179,   111,  -179,   304,    36,    36,    36,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,    36,    36,    36,  -179,
      36,  -179,   111,  -179,  -179,   387,   398,   436,   136,    -2,
      -2,   286,   119,  -179,    51,   162,  -179,  -179,    35,   347,
     125,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
      61,   109,   128,   191,    36,    36,  -179,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,    36,
    -179,   170,   147,   149,    69,    -1,   233,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,   186,   -10,   111,   111,   387,   138,
     139,   131,    36,     0,  -179,  -179,    29,     2,  -179,   132,
      36,  -179,    99,   129,    36,   145,   151,  -179,   387,  -179,
    -179,   134,  -179,  -179,  -179,  -179,  -179,    36,   387,   193,
     196,   119,   140,    29,   119,   387,  -179,  -179,   157,   158,
    -179,  -179,   150,  -179,  -179,   119,  -179,   191,  -179,  -179,
    -179,  -179
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   173,     3,     1,     0,    15,   173,     5,
      11,     0,     0,     0,     6,     0,     0,     0,     0,     2,
      15,    16,    18,    19,    20,     4,    13,     0,    10,    12,
       0,    47,     0,    21,    28,     0,    33,    29,    30,    34,
      35,     0,    38,     0,    14,     7,     8,    10,     0,     0,
       0,    23,     0,    51,     0,    25,     0,    27,    49,    52,
       0,    37,     0,    33,     0,    40,     0,    42,    46,     9,
       0,    48,    22,    24,     0,     0,     0,    36,    31,    32,
      39,    41,   110,   108,   109,   111,     0,   106,   105,   112,
      79,    80,    82,    83,    84,     0,    81,   113,    44,    54,
       0,    61,    98,    99,   102,   107,   103,     0,    43,   114,
      17,    53,    50,    26,    96,     0,     0,     0,     0,    75,
      76,    78,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    77,     0,     0,     0,    97,
       0,   100,    45,   118,   104,    55,    56,    57,    58,    59,
      60,     0,   115,   101,   111,     0,   132,   120,     0,   123,
       0,   117,   119,   124,   125,   126,   121,   122,   155,   156,
     111,     0,     0,   173,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,   127,   128,     0,
     116,     0,     0,     0,     0,     0,    54,   149,   133,   135,
     136,   140,   144,   137,     0,   138,   131,   129,   130,     0,
       0,     0,     0,     0,   159,   170,     0,     0,   167,     0,
     153,   152,     0,     0,     0,     0,     0,   118,   160,   157,
     158,   171,   169,   163,   166,   118,   134,     0,   151,     0,
       0,   162,     0,     0,   168,   139,   146,   141,     0,     0,
     118,   172,     0,   164,   165,   161,   142,   173,   150,   143,
     147,   148
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -179,  -179,  -179,   228,  -179,  -179,   190,    48,   218,  -179,
      64,  -179,  -179,    20,  -179,  -179,  -179,  -179,   176,   223,
    -179,  -179,  -179,  -179,   -14,  -179,  -179,   -13,    21,  -179,
     -34,   -59,   -93,  -179,  -179,  -179,  -179,  -179,    -7,  -179,
    -179,  -179,    53,  -179,  -179,    23,  -179,  -179,  -178,  -179,
    -151,  -179,  -179,  -179,  -179,  -179,  -179,  -179,     6,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,  -179,    33,  -179,  -179,  -179,  -179,    30,  -179,
       8,  -167
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,    27,    46,    47,    19,    20,
     157,    22,    50,    33,    55,    56,    23,    37,    62,    63,
      39,    40,    24,    64,    42,    67,   108,   158,   231,    58,
      97,   206,    99,   136,   137,   138,   100,   189,   101,   102,
     141,   103,   104,   105,   106,   110,   143,   160,   152,   161,
     162,   163,   164,   165,   166,   173,   222,   198,   199,   200,
     223,   252,   257,   201,   247,   259,   202,   260,   203,   204,
     167,   168,   213,   214,   242,   169,   172,   217,   218,   219,
     232,     9
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,    59,   115,    34,   171,    43,   205,    98,   211,    59,
     215,    52,   212,    10,   216,  -154,    11,   113,    10,    34,
      59,    11,   197,   145,   146,   147,    59,    65,    43,     1,
      31,    31,   119,   120,   121,    52,    71,    34,    31,    82,
      83,    84,    85,   148,   149,   150,    35,   151,   142,   241,
      81,    43,    51,    31,    14,    57,    61,   244,     4,   159,
      28,    26,   159,    52,    68,    53,   132,   133,   134,   135,
      73,    21,   255,    86,  -145,    75,   221,   116,    54,   114,
     196,    77,    60,   229,    21,   233,    13,     5,    12,    53,
     261,    13,   174,   139,    87,    88,   208,    89,    72,    80,
      90,    91,    54,    92,    93,    32,   258,    94,   -47,    95,
       6,    29,   175,    36,   195,    96,   207,    53,   191,   228,
      41,    30,    82,    83,    84,   154,   220,    74,   -47,    49,
      54,   238,    49,    45,    66,    48,    15,    74,   -47,    49,
     155,    16,    70,    31,   245,    17,   175,   156,   159,    16,
      18,   159,    35,    17,    74,   211,    86,   215,    18,   212,
     194,   216,   159,    76,   159,    82,    83,    84,   170,    78,
     119,   120,   121,    82,    83,    84,   209,    87,    88,   107,
      89,   109,    59,    90,    91,   111,    92,    93,   112,   116,
      94,   192,    95,   140,    82,    83,    84,   154,    96,    86,
     128,   129,   130,   131,   132,   133,   134,   135,   190,    59,
     193,   224,   243,   237,   225,   226,   227,   235,   239,   248,
      87,    88,   249,    89,   240,   250,    90,    91,    86,    92,
      93,   253,   254,    94,   256,    95,    25,    69,    44,    79,
      38,    96,     0,   246,   210,   236,   230,   234,     0,    87,
      88,   251,    89,     0,     0,    90,    91,     0,    92,    93,
       0,     0,    94,     0,    95,   117,   118,   119,   120,   121,
      96,   122,   123,   124,   125,   126,   127,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,     0,     0,     0,     0,     0,     0,   128,   129,   130,
     131,   132,   133,   134,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -139,     0,  -123,   117,   118,
     119,   120,   121,     0,   122,   123,   124,   125,   126,   127,
       0,     0,     0,     0,     0,     0,   117,   118,   119,   120,
     121,     0,   122,   123,   124,   125,   126,   127,     0,     0,
     128,   129,   130,   131,   132,   133,   134,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   153,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     0,   144,   117,
     118,   119,   120,   121,     0,   122,   123,   124,   125,   126,
     127,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,     0,     0,     0,     0,     0,
       0,   128,   129,   130,   131,   132,   133,   134,   135,   117,
     118,   119,   120,   121,     0,   122,   123,   124,   125,   126,
     127,   118,   119,   120,   121,     0,   122,   123,   124,   125,
     126,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,     0,   128,   129,   130,   131,   132,   133,   134,   135,
     119,   120,   121,     0,   122,   123,   124,   125,   126,   127,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,   129,   130,   131,   132,   133,   134,   135
};

static const yytype_int16 yycheck[] =
{
      34,    35,    95,    16,   155,    18,   173,    66,     8,    43,
       8,     6,    12,     3,    12,    25,     6,    76,     3,    32,
      54,     6,   173,   116,   117,   118,    60,    41,    41,    20,
       6,     6,    34,    35,    36,     6,    49,    50,     6,     3,
       4,     5,     6,   136,   137,   138,     6,   140,   107,   227,
      64,    64,    32,     6,     6,    34,    35,   235,     6,   152,
      12,     3,   155,     6,    43,    60,    68,    69,    70,    71,
      50,     7,   250,    37,    84,    54,    77,    78,    73,    86,
     173,    60,    77,    83,    20,    83,    76,     0,    73,    60,
     257,    76,    57,   100,    58,    59,   189,    61,    74,    74,
      64,    65,    73,    67,    68,    73,   257,    71,    57,    73,
      29,     3,    77,    73,   173,    79,   175,    60,    57,   212,
      73,     6,     3,     4,     5,     6,    57,    76,    77,    78,
      73,   224,    78,    74,    77,    73,     9,    76,    77,    78,
      21,    22,    74,     6,   237,    26,    77,    28,   241,    22,
      31,   244,     6,    26,    76,     8,    37,     8,    31,    12,
     173,    12,   255,    77,   257,     3,     4,     5,     6,    74,
      34,    35,    36,     3,     4,     5,     6,    58,    59,    77,
      61,    82,   216,    64,    65,     6,    67,    68,    74,    78,
      71,    82,    73,    80,     3,     4,     5,     6,    79,    37,
      64,    65,    66,    67,    68,    69,    70,    71,    83,   243,
      82,    25,    78,    84,    76,    76,    85,    85,    73,    26,
      58,    59,    26,    61,    73,    85,    64,    65,    37,    67,
      68,    74,    74,    71,    84,    73,     8,    47,    20,    63,
      17,    79,    -1,   237,   191,   222,   213,   217,    -1,    58,
      59,   243,    61,    -1,    -1,    64,    65,    -1,    67,    68,
      -1,    -1,    71,    -1,    73,    32,    33,    34,    35,    36,
      79,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    -1,    84,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    64,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    74,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    -1,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    87,    88,     6,     0,    29,    89,    90,   167,
       3,     6,    73,    76,    93,     9,    22,    26,    31,    94,
      95,    96,    97,   102,   108,    89,     3,    91,    93,     3,
       6,     6,    73,    99,   113,     6,    73,   103,   105,   106,
     107,    73,   110,   113,    94,    74,    92,    93,    73,    78,
      98,    99,     6,    60,    73,   100,   101,   114,   115,   116,
      77,   114,   104,   105,   109,   110,    77,   111,   114,    92,
      74,   113,    74,    99,    76,   114,    77,   114,    74,   104,
      74,   110,     3,     4,     5,     6,    37,    58,    59,    61,
      64,    65,    67,    68,    71,    73,    79,   116,   117,   118,
     122,   124,   125,   127,   128,   129,   130,    77,   112,    82,
     131,     6,    74,   117,   124,   118,    78,    32,    33,    34,
      35,    36,    38,    39,    40,    41,    42,    43,    64,    65,
      66,    67,    68,    69,    70,    71,   119,   120,   121,   124,
      80,   126,   117,   132,    74,   118,   118,   118,   118,   118,
     118,   118,   134,    81,     6,    21,    28,    96,   113,   118,
     133,   135,   136,   137,   138,   139,   140,   156,   157,   161,
       6,   136,   162,   141,    57,    77,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,   123,
      83,    57,    82,    82,   113,   117,   118,   136,   143,   144,
     145,   149,   152,   154,   155,   167,   117,   117,   118,     6,
     128,     8,    12,   158,   159,     8,    12,   163,   164,   165,
      57,    77,   142,   146,    25,    76,    76,    85,   118,    83,
     159,   114,   166,    83,   164,    85,   131,    84,   118,    73,
      73,   134,   160,    78,   134,   118,   144,   150,    26,    26,
      85,   166,   147,    74,    74,   134,    84,   148,   136,   151,
     153,   167
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    88,    89,    89,    90,    90,    91,    92,
      92,    93,    93,    93,    94,    94,    95,    95,    96,    96,
      96,    97,    97,    98,    98,    99,   100,   101,   101,   102,
     103,   103,   104,   104,   105,   105,   106,   107,   108,   108,
     109,   109,   110,   111,   111,   112,   112,   113,   113,   114,
     114,   115,   115,   116,   117,   117,   118,   118,   118,   118,
     118,   118,   119,   119,   119,   119,   119,   119,   120,   120,
     120,   120,   121,   121,   121,   121,   121,   121,   121,   122,
     122,   122,   122,   122,   122,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   124,   124,   124,   125,
     125,   126,   127,   127,   127,   127,   127,   128,   129,   129,
     129,   130,   130,   130,   132,   133,   131,   134,   134,   135,
     135,   135,   135,   136,   136,   136,   136,   137,   137,   138,
     138,   139,   141,   142,   140,   143,   143,   143,   143,   144,
     146,   147,   148,   145,   149,   149,   150,   151,   151,   152,
     153,   154,   155,   155,   155,   156,   156,   157,   158,   158,
     160,   159,   159,   161,   162,   162,   163,   163,   164,   165,
     165,   166,   166,   167
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     2,     1,     2,     4,     2,     2,
       0,     1,     2,     2,     2,     0,     1,     5,     1,     1,
       1,     2,     4,     1,     2,     2,     3,     1,     0,     2,
       1,     3,     2,     0,     1,     1,     3,     2,     2,     4,
       1,     2,     2,     2,     2,     2,     0,     1,     3,     1,
       3,     1,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       2,     3,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     0,     5,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       3,     3,     0,     0,     5,     1,     1,     1,     1,     1,
       0,     0,     0,     8,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     2,     1,     1,     1,     5,     2,     1,
       0,     5,     3,     5,     7,     7,     2,     1,     3,     2,
       1,     1,     3,     0
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
#line 433 "yac.y"
    {
        if(yychar != YYEOF) 
        {
            printf("Invalid - reached start symbol before EOF\n"); YYERROR;
        }
        printf("Parsing Successful. The given Code is Valid\n"); 
        YYACCEPT;
    }
#line 2107 "yac.tab.c"
    break;

  case 22:
#line 496 "yac.y"
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
                    insert('c', pop(&stack_i), pop(&stack_t), "NULL", scope_depth, scope_id);
                }
            }
            else 
            {
                while(!stempty(stack_i)) 
                {

                    insert('c', pop(&stack_i), pop(&stack_t), pop(&stack_v), scope_depth, scope_id);
                }
            }
        }  
    }
#line 2137 "yac.tab.c"
    break;

  case 25:
#line 530 "yac.y"
    { 
        value.op[0] = '='; value.op[1] = 0; 
        (yyval.ConstSpecification) = makeNode(OP, value, (yyvsp[-1].IdentifierList), (yyvsp[0].ConstIdList));
        doAssign('c', (yyvsp[-1].IdentifierList), (yyvsp[0].ConstIdList)->value.n);
    }
#line 2147 "yac.tab.c"
    break;

  case 26:
#line 539 "yac.y"
    {	
        value.n = (yyvsp[0].ExpressionList); 
        (yyval.ConstIdList) = makeNode(OP, value, NULL, NULL);
    }
#line 2156 "yac.tab.c"
    break;

  case 27:
#line 547 "yac.y"
    {	
        strcpy(Tflag, (yyvsp[0].Type)->value.name);
    }
#line 2164 "yac.tab.c"
    break;

  case 39:
#line 588 "yac.y"
    { 
        if(stack_v.top != stack_i.top && stack_v.top != -1)
        {
            yyerror("Imbalanced assignment");
            YYERROR;
        }
        else 
        {
            if (stack_v.top == -1){
                while(!stempty(stack_i))
                {
                    insert('v', pop(&stack_i), Tflag, "NULL", scope_depth, scope_id);
                }
            }
            else 
            {
                while(!stempty(stack_i))
                {
                    insert('v', pop(&stack_i), pop(&stack_t), pop(&stack_v), scope_depth, scope_id);
                }
            }
        } 
    }
#line 2192 "yac.tab.c"
    break;

  case 42:
#line 620 "yac.y"
    { 
        if((yyvsp[0].VariableIdList)) 
        {
            value.op[0] = '='; value.op[1] = 0; 
            printf("Outside function: %d %d\n", seqLen((yyvsp[-1].IdentifierList)), seqLen((yyvsp[0].VariableIdList)->value.n));
            (yyval.VariableSpecification) = makeNode(OP, value, (yyvsp[-1].IdentifierList), (yyvsp[0].VariableIdList));
            doAssign('v', (yyvsp[-1].IdentifierList), (yyvsp[0].VariableIdList)->value.n);
        } 
        else {
            (yyval.VariableSpecification) = NULL;
            printf("Beginning with assign\n");
            doAssign('v', (yyvsp[-1].IdentifierList), (yyvsp[0].VariableIdList));
            printf("Done with assign\n");
        }
    }
#line 2212 "yac.tab.c"
    break;

  case 43:
#line 639 "yac.y"
    {	
    (yyval.VariableIdList) = (yyvsp[0].VariableIdListType);
    strcpy(Tflag, (yyvsp[-1].Type)->value.name);
    }
#line 2221 "yac.tab.c"
    break;

  case 44:
#line 644 "yac.y"
    {	
    value.n = (yyvsp[0].ExpressionList); 
    (yyval.VariableIdList) = makeNode(OP, value, NULL, NULL);
    }
#line 2230 "yac.tab.c"
    break;

  case 45:
#line 652 "yac.y"
    {	
    value.n = (yyvsp[0].ExpressionList); 
    (yyval.VariableIdListType) = makeNode(OP, value, NULL, NULL);
    }
#line 2239 "yac.tab.c"
    break;

  case 46:
#line 657 "yac.y"
    {
        (yyval.VariableIdListType) = NULL; 
    }
#line 2247 "yac.tab.c"
    break;

  case 47:
#line 664 "yac.y"
    {	
        strcpy(value.name, (yyvsp[0].IDENTIFIER)); 
        (yyval.IdentifierList) = makeNode(SEQ, value, makeNode(ID, value, NULL, NULL), NULL); 
        push(&stack_i, value.name);
    }
#line 2257 "yac.tab.c"
    break;

  case 48:
#line 670 "yac.y"
    {
	
	    strcpy(value.name, (yyvsp[-2].IDENTIFIER)); 
		(yyval.IdentifierList) = makeNode(SEQ, value, makeNode(ID, value, NULL, NULL), (yyvsp[0].IdentifierList));
		push(&stack_i, value.name);

    }
#line 2269 "yac.tab.c"
    break;

  case 49:
#line 682 "yac.y"
    {
        (yyval.Type)=(yyvsp[0].TypeName);
    }
#line 2277 "yac.tab.c"
    break;

  case 50:
#line 686 "yac.y"
    {
        (yyval.Type)=(yyvsp[-1].Type);
    }
#line 2285 "yac.tab.c"
    break;

  case 51:
#line 693 "yac.y"
    {
        strcpy(value.name,(yyvsp[0].P_TYPE));
        (yyval.TypeName) = makeNode(ID,value,NULL,NULL);
    }
#line 2294 "yac.tab.c"
    break;

  case 52:
#line 698 "yac.y"
    {
        (yyval.TypeName) = (yyvsp[0].QualifiedID);
    }
#line 2302 "yac.tab.c"
    break;

  case 53:
#line 705 "yac.y"
    {	
        value.name[0] = 0; 
        strcat(value.name, (yyvsp[-2].IDENTIFIER)); 
        strcat(value.name, "."); 
        strcat(value.name, (yyvsp[0].IDENTIFIER)); 
        (yyval.QualifiedID) = makeNode(ID, value, NULL, NULL);
    }
#line 2314 "yac.tab.c"
    break;

  case 54:
#line 718 "yac.y"
    {	
        (yyval.ExpressionList) = makeNode(SEQ, value, (yyvsp[0].Expression), NULL);  
        switch ((yyvsp[0].Expression)->type) {
            case INT:
                sprintf(result, "%d", (yyvsp[0].Expression)->value.i);
                push(&stack_t, "int");
                break;
            case FLOAT:
                sprintf(result, "%f", (yyvsp[0].Expression)->value.f);
                push(&stack_t, "float");
                break;
            case RUNE:
                sprintf(result, "%s", (yyvsp[0].Expression)->value.str);
                push(&stack_t, "rune");
                break;
            case STRING:
                sprintf(result, "%s", (yyvsp[0].Expression)->value.str);
                push(&stack_t, "string");
                break;
            case BOOL:
                sprintf(result, "%dB", (yyvsp[0].Expression)->value.b);
                push(&stack_t, "bool");
                break;
            }       
        push(&stack_v, result);
        }
#line 2345 "yac.tab.c"
    break;

  case 55:
#line 745 "yac.y"
    { 
        (yyval.ExpressionList) = makeNode(SEQ, value, (yyvsp[0].Expression), (yyvsp[-2].ExpressionList));

        switch ((yyvsp[0].Expression)->type) {
            case INT:
                sprintf(result, "%d", (yyvsp[-2].ExpressionList)->value.i);
                push(&stack_t, "int");
                break;
            case FLOAT:
                sprintf(result, "%f", (yyvsp[-2].ExpressionList)->value.f);
                push(&stack_t, "float");
                break;
            case RUNE:
                sprintf(result, "%s", (yyvsp[-2].ExpressionList)->value.str);
                push(&stack_t, "rune");
                break;
            case STRING:
                sprintf(result, "%s", (yyvsp[-2].ExpressionList)->value.str);
                push(&stack_t, "string");
                break;
            case BOOL:
                sprintf(result, "%dB", (yyvsp[-2].ExpressionList)->value.b);
                push(&stack_t, "bool");
                break;
            }        
        push(&stack_v, result);
    }
#line 2377 "yac.tab.c"
    break;

  case 56:
#line 776 "yac.y"
    {
        strcpy(value.op, (yyvsp[-1].LOGICAL_OR));
        (yyval.Expression) = makeNode(OP, value, (yyvsp[-2].Expression), (yyvsp[0].Expression));
        newtemp();
        fprintf(icfile, "%s = %s %s %s\n", temp, (yyvsp[-2].Expression)->loc, value.op, (yyvsp[0].Expression)->loc);
        strcpy((yyval.Expression)->loc, temp);
    }
#line 2389 "yac.tab.c"
    break;

  case 57:
#line 784 "yac.y"
    {
        strcpy(value.op, (yyvsp[-1].LOGICAL_AND));
        (yyval.Expression) = makeNode(OP, value, (yyvsp[-2].Expression), (yyvsp[0].Expression));
        newtemp();
        fprintf(icfile, "%s = %s %s %s\n", temp, (yyvsp[-2].Expression)->loc, value.op, (yyvsp[0].Expression)->loc);
        strcpy((yyval.Expression)->loc, temp);
    }
#line 2401 "yac.tab.c"
    break;

  case 58:
#line 792 "yac.y"
    {
        strcpy(value.op, (yyvsp[-1].RelationalOperation)->value.op);
        (yyval.Expression) = makeNode(OP, value, (yyvsp[-2].Expression), (yyvsp[0].Expression));
        newtemp();
        fprintf(icfile, "%s = %s %s %s\n", temp, (yyvsp[-2].Expression)->loc, value.op, (yyvsp[0].Expression)->loc);
        strcpy((yyval.Expression)->loc, temp);
        printf("While setting: %s\n", (yyval.Expression)->loc);
    }
#line 2414 "yac.tab.c"
    break;

  case 59:
#line 801 "yac.y"
    {
		 strcpy(value.op, (yyvsp[-1].AddOperation)->value.op);
		 (yyval.Expression) = makeNode(OP, value, (yyvsp[-2].Expression), (yyvsp[0].Expression));
		 newtemp();
		 fprintf(icfile, "%s = %s %s %s\n", temp, (yyvsp[-2].Expression)->loc, value.op, (yyvsp[0].Expression)->loc);
		 strcpy((yyval.Expression)->loc, temp);
    }
#line 2426 "yac.tab.c"
    break;

  case 60:
#line 809 "yac.y"
    {
		 strcpy(value.op, (yyvsp[-1].MultipyOperation)->value.op);
		 (yyval.Expression) = makeNode(OP, value, (yyvsp[-2].Expression), (yyvsp[0].Expression));
		 newtemp();
		 fprintf(icfile, "%s = %s %s %s\n", temp, (yyvsp[-2].Expression)->loc, value.op, (yyvsp[0].Expression)->loc);
		 strcpy((yyval.Expression)->loc, temp);
    }
#line 2438 "yac.tab.c"
    break;

  case 61:
#line 817 "yac.y"
    {(yyval.Expression) = (yyvsp[0].UnaryExpression);}
#line 2444 "yac.tab.c"
    break;

  case 62:
#line 822 "yac.y"
    {strcpy(value.op, (yyvsp[0].REL_EQUAL)); (yyval.RelationalOperation) = makeNode(OP, value, NULL, NULL);}
#line 2450 "yac.tab.c"
    break;

  case 63:
#line 824 "yac.y"
    {strcpy(value.op, (yyvsp[0].REL_NEQUAL)); (yyval.RelationalOperation) = makeNode(OP, value, NULL, NULL);}
#line 2456 "yac.tab.c"
    break;

  case 64:
#line 826 "yac.y"
    {strcpy(value.op, (yyvsp[0].REL_LT)); (yyval.RelationalOperation) = makeNode(OP, value, NULL, NULL);}
#line 2462 "yac.tab.c"
    break;

  case 65:
#line 828 "yac.y"
    {strcpy(value.op, (yyvsp[0].REL_LEQ)); (yyval.RelationalOperation) = makeNode(OP, value, NULL, NULL);}
#line 2468 "yac.tab.c"
    break;

  case 66:
#line 830 "yac.y"
    {strcpy(value.op, (yyvsp[0].REL_GT)); (yyval.RelationalOperation) = makeNode(OP, value, NULL, NULL);}
#line 2474 "yac.tab.c"
    break;

  case 67:
#line 832 "yac.y"
    {strcpy(value.op, (yyvsp[0].REL_GEQ)); (yyval.RelationalOperation) = makeNode(OP, value, NULL, NULL);}
#line 2480 "yac.tab.c"
    break;

  case 68:
#line 837 "yac.y"
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; (yyval.AddOperation) = makeNode(OP, value, NULL, NULL);}
#line 2486 "yac.tab.c"
    break;

  case 69:
#line 839 "yac.y"
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; (yyval.AddOperation) = makeNode(OP, value, NULL, NULL);}
#line 2492 "yac.tab.c"
    break;

  case 70:
#line 841 "yac.y"
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; (yyval.AddOperation) = makeNode(OP, value, NULL, NULL);}
#line 2498 "yac.tab.c"
    break;

  case 71:
#line 843 "yac.y"
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; (yyval.AddOperation) = makeNode(OP, value, NULL, NULL);}
#line 2504 "yac.tab.c"
    break;

  case 72:
#line 848 "yac.y"
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; (yyval.MultipyOperation) = makeNode(OP, value, NULL, NULL);}
#line 2510 "yac.tab.c"
    break;

  case 73:
#line 850 "yac.y"
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; (yyval.MultipyOperation) = makeNode(OP, value, NULL, NULL);}
#line 2516 "yac.tab.c"
    break;

  case 74:
#line 852 "yac.y"
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; (yyval.MultipyOperation) = makeNode(OP, value, NULL, NULL);}
#line 2522 "yac.tab.c"
    break;

  case 75:
#line 854 "yac.y"
    {strcpy(value.op, (yyvsp[0].LSHIFT)); (yyval.MultipyOperation) = makeNode(OP, value, NULL, NULL);}
#line 2528 "yac.tab.c"
    break;

  case 76:
#line 856 "yac.y"
    {strcpy(value.op, (yyvsp[0].RSHIFT)); (yyval.MultipyOperation) = makeNode(OP, value, NULL, NULL);}
#line 2534 "yac.tab.c"
    break;

  case 77:
#line 858 "yac.y"
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; (yyval.MultipyOperation) = makeNode(OP, value, NULL, NULL);}
#line 2540 "yac.tab.c"
    break;

  case 78:
#line 860 "yac.y"
    {strcpy(value.op, (yyvsp[0].AMPXOR)); (yyval.MultipyOperation) = makeNode(OP, value, NULL, NULL);}
#line 2546 "yac.tab.c"
    break;

  case 79:
#line 866 "yac.y"
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; (yyval.UnaryOperation) = makeNode(OP, value, NULL, NULL);}
#line 2552 "yac.tab.c"
    break;

  case 80:
#line 868 "yac.y"
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; (yyval.UnaryOperation) = makeNode(OP, value, NULL, NULL);}
#line 2558 "yac.tab.c"
    break;

  case 81:
#line 870 "yac.y"
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; (yyval.UnaryOperation) = makeNode(OP, value, NULL, NULL);}
#line 2564 "yac.tab.c"
    break;

  case 82:
#line 872 "yac.y"
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; (yyval.UnaryOperation) = makeNode(OP, value, NULL, NULL);}
#line 2570 "yac.tab.c"
    break;

  case 83:
#line 874 "yac.y"
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; (yyval.UnaryOperation) = makeNode(OP, value, NULL, NULL);}
#line 2576 "yac.tab.c"
    break;

  case 84:
#line 876 "yac.y"
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; (yyval.UnaryOperation) = makeNode(OP, value, NULL, NULL);}
#line 2582 "yac.tab.c"
    break;

  case 85:
#line 881 "yac.y"
    {strcpy(value.op, (yyvsp[0].ADD_ASSIGN)); (yyval.AssignOperation) = makeNode(OP, value, NULL, NULL);}
#line 2588 "yac.tab.c"
    break;

  case 86:
#line 883 "yac.y"
    {strcpy(value.op, (yyvsp[0].SUB_ASSIGN)); (yyval.AssignOperation) = makeNode(OP, value, NULL, NULL);}
#line 2594 "yac.tab.c"
    break;

  case 87:
#line 885 "yac.y"
    {strcpy(value.op, (yyvsp[0].OR_ASSIGN)); (yyval.AssignOperation) = makeNode(OP, value, NULL, NULL);}
#line 2600 "yac.tab.c"
    break;

  case 88:
#line 887 "yac.y"
    {strcpy(value.op, (yyvsp[0].XOR_ASSIGN)); (yyval.AssignOperation) = makeNode(OP, value, NULL, NULL);}
#line 2606 "yac.tab.c"
    break;

  case 89:
#line 889 "yac.y"
    {strcpy(value.op, (yyvsp[0].MUL_ASSIGN)); (yyval.AssignOperation) = makeNode(OP, value, NULL, NULL);}
#line 2612 "yac.tab.c"
    break;

  case 90:
#line 891 "yac.y"
    {strcpy(value.op, (yyvsp[0].DIV_ASSIGN)); (yyval.AssignOperation) = makeNode(OP, value, NULL, NULL);}
#line 2618 "yac.tab.c"
    break;

  case 91:
#line 893 "yac.y"
    {strcpy(value.op, (yyvsp[0].MOD_ASSIGN)); (yyval.AssignOperation) = makeNode(OP, value, NULL, NULL);}
#line 2624 "yac.tab.c"
    break;

  case 92:
#line 895 "yac.y"
    {strcpy(value.op, (yyvsp[0].AND_ASSIGN)); (yyval.AssignOperation) = makeNode(OP, value, NULL, NULL);}
#line 2630 "yac.tab.c"
    break;

  case 93:
#line 897 "yac.y"
    {strcpy(value.op, (yyvsp[0].LSHIFT_ASSIGN)); (yyval.AssignOperation) = makeNode(OP, value, NULL, NULL);}
#line 2636 "yac.tab.c"
    break;

  case 94:
#line 899 "yac.y"
    {strcpy(value.op, (yyvsp[0].RSHIFT_ASSIGN)); (yyval.AssignOperation) = makeNode(OP, value, NULL, NULL);}
#line 2642 "yac.tab.c"
    break;

  case 95:
#line 901 "yac.y"
    {strcpy(value.op, (yyvsp[0].AMPXOR_ASSIGN)); (yyval.AssignOperation) = makeNode(OP, value, NULL, NULL);}
#line 2648 "yac.tab.c"
    break;

  case 96:
#line 906 "yac.y"
    {strcpy(value.op, (yyvsp[-1].CHANNEL_ASSIGN)); (yyval.UnaryExpression) = makeNode(OP, value, (yyvsp[0].UnaryExpression), NULL);}
#line 2654 "yac.tab.c"
    break;

  case 97:
#line 908 "yac.y"
    {
        strcpy(value.op, (yyvsp[-1].UnaryOperation)->value.op);
        (yyval.UnaryExpression) = makeNode(OP, value, (yyvsp[0].UnaryExpression), NULL);
        strcpy((yyval.UnaryExpression)->loc,getLoc((yyvsp[0].UnaryExpression)));
        newtemp();
        fprintf(icfile, "%s = -%s\n", temp, (yyval.UnaryExpression)->loc);
        strcpy((yyval.UnaryExpression)->loc, temp);
    }
#line 2667 "yac.tab.c"
    break;

  case 98:
#line 917 "yac.y"
    {
        (yyval.UnaryExpression) = (yyvsp[0].PrimaryExpression); 
        strcpy((yyval.UnaryExpression)->loc,getLoc((yyvsp[0].PrimaryExpression)));
    }
#line 2676 "yac.tab.c"
    break;

  case 99:
#line 925 "yac.y"
    {
        (yyval.PrimaryExpression) = (yyvsp[0].Operand);
    }
#line 2684 "yac.tab.c"
    break;

  case 102:
#line 937 "yac.y"
    {
        (yyval.Operand) = (yyvsp[0].Literal);
    }
#line 2692 "yac.tab.c"
    break;

  case 103:
#line 941 "yac.y"
    {
        (yyval.Operand) = (yyvsp[0].OperandName);
    }
#line 2700 "yac.tab.c"
    break;

  case 104:
#line 945 "yac.y"
    {
        (yyval.Operand) = (yyvsp[-1].Expression);
    }
#line 2708 "yac.tab.c"
    break;

  case 105:
#line 949 "yac.y"
    {value.n = NULL; (yyval.Operand) = makeNode(NIL, value, NULL, NULL);}
#line 2714 "yac.tab.c"
    break;

  case 106:
#line 951 "yac.y"
    {value.b = strcmp((yyvsp[0].P_BOOL), "true")==0 ? 1 : 0; (yyval.Operand) = makeNode(BOOL, value, NULL, NULL);}
#line 2720 "yac.tab.c"
    break;

  case 107:
#line 956 "yac.y"
    {
        (yyval.Literal) = (yyvsp[0].BasicLiteral);
    }
#line 2728 "yac.tab.c"
    break;

  case 108:
#line 963 "yac.y"
    {
        value.i = (yyvsp[0].INT_LITERAL); (yyval.BasicLiteral) = makeNode(INT, value, NULL, NULL);
    }
#line 2736 "yac.tab.c"
    break;

  case 109:
#line 967 "yac.y"
    {
        value.f = (yyvsp[0].FLOAT_LITERAL); (yyval.BasicLiteral) = makeNode(FLOAT, value, NULL, NULL);
    }
#line 2744 "yac.tab.c"
    break;

  case 110:
#line 971 "yac.y"
    {
        strcpy(value.str, (yyvsp[0].STRING_LITERAL)); (yyval.BasicLiteral) = makeNode(STRING, value, NULL, NULL);
    }
#line 2752 "yac.tab.c"
    break;

  case 111:
#line 978 "yac.y"
    {
        strcpy(value.name, (yyvsp[0].IDENTIFIER)); (yyval.OperandName) = makeNode(ID, value, NULL, NULL);
    }
#line 2760 "yac.tab.c"
    break;

  case 112:
#line 982 "yac.y"
    {
        strcpy(value.name, (yyvsp[0].P_FUNCTION)); (yyval.OperandName) = makeNode(FUNC, value, NULL, NULL);
    }
#line 2768 "yac.tab.c"
    break;

  case 113:
#line 986 "yac.y"
    {
        (yyval.OperandName) = (yyvsp[0].QualifiedID);
    }
#line 2776 "yac.tab.c"
    break;

  case 114:
#line 996 "yac.y"
    {
        ++scope_depth; 
        scope_id = next_id(scope_depth);
    }
#line 2785 "yac.tab.c"
    break;

  case 115:
#line 1001 "yac.y"
    {
        --scope_depth; 
        scope_id = restore_id(scope_depth);
    }
#line 2794 "yac.tab.c"
    break;

  case 127:
#line 1029 "yac.y"
    {
        newtemp(); fprintf(icfile, "%s = %s + 1\n", temp, (yyvsp[-1].Expression)->loc), fprintf(icfile, "%s = %s\n", (yyvsp[-1].Expression)->loc, temp);
    }
#line 2802 "yac.tab.c"
    break;

  case 128:
#line 1033 "yac.y"
    {
        newtemp(); fprintf(icfile, "%s = %s - 1\n", temp, (yyvsp[-1].Expression)->loc), fprintf(icfile, "%s = %s\n", (yyvsp[-1].Expression)->loc, temp);
    }
#line 2810 "yac.tab.c"
    break;

  case 129:
#line 1040 "yac.y"
    {
        value.op[0] = '='; 
        value.op[1] = 0; 
        (yyval.Assignment) = makeNode(OP, value, (yyvsp[-2].IdentifierList), (yyvsp[0].ExpressionList));
        doAssignExisting((yyvsp[-2].IdentifierList), (yyvsp[0].ExpressionList));
    }
#line 2821 "yac.tab.c"
    break;

  case 130:
#line 1047 "yac.y"
    {	
        strcpy(value.op, (yyvsp[-1].AssignOperation)->value.op); 
        (yyval.Assignment) = makeNode(OP, value, (yyvsp[-2].Expression), (yyvsp[0].Expression));
    }
#line 2830 "yac.tab.c"
    break;

  case 131:
#line 1055 "yac.y"
    {
        doAssign('v', (yyvsp[-2].IdentifierList), (yyvsp[0].ExpressionList));
    }
#line 2838 "yac.tab.c"
    break;

  case 132:
#line 1064 "yac.y"
    {
        newlabel(); add(&for_loc, label); newlabel(); add(&for_loc, label); 
        strcpy((*(IfNode*)(&yyval)).next, label);
    }
#line 2847 "yac.tab.c"
    break;

  case 133:
#line 1069 "yac.y"
    {
        strcpy((*(IfNode*)(&yyval)).next, label);
    }
#line 2855 "yac.tab.c"
    break;

  case 134:
#line 1073 "yac.y"
    {
        fprintf(icfile, "GOTO %s\n", label);
        fprintf(icfile, "%s:\n", (*(IfNode*)(&yyvsp[-3])).next);
    }
#line 2864 "yac.tab.c"
    break;

  case 139:
#line 1088 "yac.y"
    {
        fprintf(icfile, "IFFALSE %s GOTO %s\n", (yyvsp[0].Expression)->loc, rem(&for_loc));
    }
#line 2872 "yac.tab.c"
    break;

  case 140:
#line 1095 "yac.y"
    {strcpy((*(IfNode*)(&yyval)).next, rem(&for_loc)); fprintf(icfile, "%s:\n", (*(IfNode*)(&yyval)).next); }
#line 2878 "yac.tab.c"
    break;

  case 141:
#line 1098 "yac.y"
    {newlabel();fprintf(icfile, "GOTO %s\n", label); add(&for_loc, label);}
#line 2884 "yac.tab.c"
    break;

  case 142:
#line 1100 "yac.y"
    {newlabel(); fprintf(icfile, "%s:\n", label);}
#line 2890 "yac.tab.c"
    break;

  case 143:
#line 1102 "yac.y"
    {
        fprintf(icfile, "GOTO %s\n", (*(IfNode*)(&yyvsp[-6])).next); 
        fprintf(icfile, "%s:\n", rem(&for_loc));
    }
#line 2899 "yac.tab.c"
    break;

  case 160:
#line 1157 "yac.y"
    {
        newlabel();
        newtemp();
        fprintf(icfile, "%s = i == %s\n", temp, (yyvsp[0].Expression)->loc);
        fprintf(icfile, "IFFALSE %s GOTO %s\n", temp, label);
        strcpy((*(IfNode*)(&yyval)).next, label);
    }
#line 2911 "yac.tab.c"
    break;

  case 161:
#line 1166 "yac.y"
    { 
        push(&if_cond, (yyvsp[-3].Expression)->loc); 
        fprintf(icfile, "%s:\n", (*(IfNode*)(&yyvsp[-2])).next); 
    }
#line 2920 "yac.tab.c"
    break;


#line 2924 "yac.tab.c"

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
#line 1220 "yac.y"


extern int yylineno;
char codeline[100];
void yyerror(char const* error) {
	fprintf(stderr, "Syntax error in line %d: %s\n", yylineno, error);
}

int main()
{
	icfile = fopen("code optimization/intermediate.txt", "w");
	for(int i=0; i<TABLE_SIZE; i++)
		hashTable[i].hcode = -1;

	sprintf(result, "%d", base);
	base++;
	push(&stack_scope, result);

	yydebug = 1;
	if ( yyparse() != 0){
		printf("Build Failed\n\n");
		exit(1);
	}

	printf("\n\n\n");
	printf("---------------------------------Symbol Table---------------------------------\n\n");
	disp_symtbl();

	return 0;
}
