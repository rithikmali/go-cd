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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

