%{
#include "yac.tab.h"
#include <string.h>
#include "common.h"
// void yyerror (char *s);
// int yylex();
%}
%option yylineno
digit [0-9]
letter [a-zA-Z_]

whitespace [[:space:]]+

decimal_digits {digit}(_?{digit})*

decimal_exponent  [eE][+-]?{decimal_digits}
float_literal ({decimal_digits}"."{decimal_digits}?{decimal_exponent}?)|{decimal_digits}{decimal_exponent}

int_literal 0|([1-9]{digit}*)
identifier {letter}({letter}|{digit})*
operator_char "+"|"&"|"("|")"|"-"|"|"|"["|"]"|"^"|":"|"."|"{"|"}"|"/"|"*"|"="|","|";"|"%"|"!"
predeclared_type (bool)|(byte)|(complex64)|(complex128)|(error)|(float32)|(float64)|(int)|(int8)|(int16)|(int32)|(int64)|(rune)|(string)|(uint)|(uint8)|(uint16)|(uint32)|(uint64)|(uintptr)
predeclared_functions (append)|(cap)|(close)|(complex)|(copy)|(delete)|(imag)|(len)|(make)|(new)|(panic)|(print)|(println)|(real)|(recover)

comment       {line_comment}|{block_comment}
line_comment  "//".*
block_comment "/*"[^*]*"*"+([^*/][^*]*"*"+)*"/" 

%%
{whitespace} ;
{comment} ;
{operator_char}         {*((char*)&yylval) = yytext[0]; return yytext[0];}
"nil"          return P_NIL;
"true"|"false" return P_BOOL;

"&&"    {yylval.LOGICAL_AND = strdup(yytext); return LOGICAL_AND;}
"||"    {yylval.LOGICAL_OR = strdup(yytext); return LOGICAL_OR;}
"=="    {yylval.REL_EQUAL = strdup(yytext); return REL_EQUAL;}
"!="    {yylval.REL_NEQUAL = strdup(yytext); return REL_NEQUAL;}
">="    {yylval.REL_GEQ = strdup(yytext); return REL_GEQ;}
"<="    {yylval.REL_LEQ = strdup(yytext); return REL_LEQ;}
">"     {yylval.REL_GT = strdup(yytext); return REL_GT;}
"<"     {yylval.REL_LT = strdup(yytext); return REL_LT;}

"&^"    {yylval.AMPXOR = strdup(yytext); return AMPXOR;}
"<<"    {yylval.LSHIFT = strdup(yytext); return LSHIFT;}
">>"    {yylval.RSHIFT = strdup(yytext); return RSHIFT;}

"<-"    {yylval.CHANNEL_ASSIGN = strdup(yytext); return CHANNEL_ASSIGN;}

":="    {yylval.SHORT_DECLARATION = strdup(yytext); return SHORT_DECLARATION;}

"+="    {yylval.ADD_ASSIGN = strdup(yytext); return ADD_ASSIGN;}
"-="    {yylval.SUB_ASSIGN = strdup(yytext); return SUB_ASSIGN;}
"*="    {yylval.MUL_ASSIGN = strdup(yytext); return MUL_ASSIGN;}
"/="    {yylval.DIV_ASSIGN = strdup(yytext); return DIV_ASSIGN;}
"<<="   {yylval.LSHIFT_ASSIGN = strdup(yytext); return LSHIFT_ASSIGN;}
">>="   {yylval.RSHIFT_ASSIGN = strdup(yytext); return RSHIFT_ASSIGN;}
"&="    {yylval.AND_ASSIGN = strdup(yytext); return AND_ASSIGN;}
"|="    {yylval.OR_ASSIGN = strdup(yytext); return OR_ASSIGN;}
"^="    {yylval.XOR_ASSIGN = strdup(yytext); return XOR_ASSIGN;}
"%="    {yylval.MOD_ASSIGN = strdup(yytext); return MOD_ASSIGN;}
"&^="   {yylval.AMPXOR_ASSIGN = strdup(yytext); return AMPXOR_ASSIGN;}
"++"    {yylval.INC_ASSIGN = strdup(yytext); return INC_ASSIGN;}
"--"    {yylval.DEC_ASSIGN = strdup(yytext); return DEC_ASSIGN;}

"package"   return KEYWORD_PACKAGE;
"import"    return KEYWORD_IMPORT;
"func"      return KEYWORD_FUNC;
"const"     return KEYWORD_CONST;
"type"      return KEYWORD_TYPE;
"var"       return KEYWORD_VAR;
"for"       return KEYWORD_FOR;
"range"     return KEYWORD_RANGE;
"switch"    return KEYWORD_SWITCH;
"case"      return KEYWORD_CASE;
"default"   return KEYWORD_DEFAULT;

"break"     ;
"interface" ;
"select"    ;
"defer"     ;
"go"        ;
"map"       ;
"struct"    ;
"chan"      ;
"else"      ;
"goto"      ;
"fallthrough"   ;
"if"        ;
"continue"  ;

{predeclared_type}      {yylval.P_TYPE = strdup(yytext); return P_TYPE;}
{predeclared_functions} {yylval.P_FUNCTION = strdup(yytext); return P_FUNCTION;}
{identifier}            {yylval.IDENTIFIER = strdup(yytext); return IDENTIFIER;}  
\".*\"                  {yylval.STRING_LITERAL = strdup(yytext); return STRING_LITERAL;}
{int_literal}           {yylval.INT_LITERAL = atoi(yytext); return INT_LITERAL;}
{float_literal}         {yylval.FLOAT_LITERAL = atof(yytext); return FLOAT_LITERAL;}


%%