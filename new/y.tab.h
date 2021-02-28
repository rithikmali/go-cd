/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
     SHORT_DECLARATION = 295,
     P_BOOL = 296,
     P_NIL = 297,
     P_TYPE = 298,
     P_FUNCTION = 299
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
#define SHORT_DECLARATION 295
#define P_BOOL 296
#define P_NIL 297
#define P_TYPE 298
#define P_FUNCTION 299




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 10 "yac.y"
{char* str;}
/* Line 1529 of yacc.c.  */
#line 139 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

