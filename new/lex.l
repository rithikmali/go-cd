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

decimal_digits {digit}(_?{digit})*

decimal_exponent  [eE][+-]?{decimal_digits}
float_literal ({decimal_digits}"."{decimal_digits}?{decimal_exponent}?)|{decimal_digits}{decimal_exponent}

int_literal 0|([1-9]{digit}*)
identifier {letter}({letter}|{digit})*
operator_char "+"|"&"|"("|")"|"-"|"|"|"["|"]"|"^"|":"|"."|"{"|"}"|"/"|"*"|"="|","|";"|"%"|"!"
predeclared_type (bool)|(byte)|(complex64)|(complex128)|(error)|(float32)|(float64)|(int)|(int8)|(int16)|(int32)|(int64)|(rune)|(string)|(uint)|(uint8)|(uint16)|(uint32)|(uint64)|(uintptr)
predeclared_functions (append)|(cap)|(close)|(complex)|(copy)|(delete)|(imag)|(len)|(make)|(new)|(panic)|(print)|(println)|(real)|(recover)

%%

"nil"           return P_NIL;
"true"|"false" return P_BOOL;

"&&"    return LOGICAL_AND;
"||"    return LOGICAL_OR;
"=="    return REL_EQUAL;
"!="    return REL_NEQUAL;
">="    return REL_GEQ;
"<="    return REL_LEQ;
">"     return REL_GT;
"<"     return REL_LT;

"&^"    return AMPXOR;
"<<"    return LSHIFT;
">>"    return RSHIFT;

"<-"    return CHANNEL_ASSIGN;

":="    return SHORT_DECLARATION;

"+="    return ADD_ASSIGN;
"-="    return SUB_ASSIGN;
"*="    return MUL_ASSIGN;
"/="    return DIV_ASSIGN;
"<<="   return LSHIFT_ASSIGN;
">>="   return RSHIFT_ASSIGN;
"&="    return AND_ASSIGN;
"|="    return OR_ASSIGN;
"^="    return XOR_ASSIGN;
"%="    return MOD_ASSIGN;
"&^="   return AMPXOR_ASSIGN;
"++"    return INC_ASSIGN;
"--"    return DEC_ASSIGN;

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
{predeclared_type} return P_TYPE;
{predeclared_functions} return P_FUNCTION;
{operator_char}   return yytext[0];
{identifier}  {printf("ID: %s\n",yytext); return IDENTIFIER;}  
\".*\"      {printf("str: %s\n",yytext); return STRING_LITERAL;}
{int_literal} {printf("integer: %s\n",yytext); return INT_LITERAL;}
{float_literal} {printf("floatt: %s\n",yytext); return FLOAT_LITERAL;}
[ \t\n]                ;

%%
// int yywrap (void) {return 1;}