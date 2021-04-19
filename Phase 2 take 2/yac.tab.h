/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
#line 236 "yac.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YAC_TAB_H_INCLUDED  */
