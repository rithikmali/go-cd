%{
	#include<stdio.h>
    #include <string.h>
    #include "y.tab.h"
    void yyerror (char *s);
    int yylex();

%}
%option yylineno
single_comment \/\/.* 
multi_comment "/*"[^*]*"*"+([^*/][^*]*"*"+)*"/"  
letter [a-zA-Z_]
digit [0-9]
decimal_digit [0-9]
operators [+&()\-|\[\]\^:\.{}\/\*=,;%!]
predeclared_functions append|cap|close|complex|copy|delete|imag|len|make|new|panic|print|println|real|recover
predeclared_type bool|byte|complex64|complex128|error|float32|float64|int|int8|int16|int32|int64|rune|string|uint|uint8|uint16|uint32|uint64|uintptr
whitespace     [[:space:]]+

/* Digits */
decimal_digits {decimal_digit}(_?{decimal_digit})*
binary_digit   0|1
binary_digits  {binary_digit}(_?{binary_digit})*
octal_digit    [0-7]
octal_digits   {octal_digit}(_?{octal_digit})*
hex_digit      [0-9]|[A-F]|[a-f]
hex_digits     {hex_digit}(_?{hex_digit})*

/* Integer literals */
int_lit     {decimal_lit}|{binary_lit}|{octal_lit}|{hex_lit}
decimal_lit 0|([1-9](_?{decimal_digits})?)
octal_lit   0[oO]_?{octal_digits}
hex_lit     0[xX]_?{hex_digits}
binary_lit  0[bB]_?{binary_digits}

/* Float literals */
float_lit         {decimal_float_lit}|{hex_float_lit}
decimal_float_lit ({decimal_digits}"."{decimal_digits}?{decimal_exponent}?)|{decimal_digits}{decimal_exponent}
decimal_exponent  [eE][+-]?{decimal_digits}
hex_float_lit     0[xX]{hex_mantissa}{hex_exponent}
hex_mantissa      (_?{hex_digits}"."{hex_digits}?)|(_?{hex_digits})|("."{hex_digits})
hex_exponent      [pP][+-]?{decimal_digits}

tab_newline [ \t\n] 
string_lit \".*?\"
identifier {letter}({letter}|{digit})*
%%

{tab_newline} ;
{single_comment} {printf("removed cmt\n");}
{multi_comment} ;
{whitespace} ;
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

":="    return SHORT_DECLARATION;

"&&"    return LOGICAL_AND;
"||"    return LOGICAL_OR;
"=="    return REL_EQUAL;
"!="    return REL_NEQUAL;
">="    return REL_GEQ;
"<="    return REL_LEQ;
"&^"    return AMPXOR;
"<<"    return LSHIFT;
">>"    return RSHIFT;
"<-"    return CHANNEL_ASSIGN;
">"     return REL_GT;
"<"     return REL_LT;

"default"       return KEYWORD_DEFAULT;
"break"         return KEYWORD_BREAK;
"chan"          return KEYWORD_CHAN;
"select"        return KEYWORD_SELECT;
"func"          return KEYWORD_FUNC;
"map"           return KEYWORD_MAP;
"interface"     return KEYWORD_INTERFACE;
"go"            return KEYWORD_GO;
"fallthrough"   return KEYWORD_FALLTHROUGH;
"else"          return KEYWORD_ELSE;
"defer"         return KEYWORD_DEFER;
"goto"          return KEYWORD_GOTO;
"const"         return KEYWORD_CONST;
"struct"        return KEYWORD_STRUCT;
"case"          return KEYWORD_CASE;
"package"       {printf("found package\n");return KEYWORD_PACKAGE;}
"continue"      return KEYWORD_CONTINUE;
"switch"        return KEYWORD_SWITCH;
"type"          return KEYWORD_TYPE;
"import"        return KEYWORD_IMPORT;
"range"         return KEYWORD_RANGE;
"var"           return KEYWORD_VAR;
"for"           return KEYWORD_FOR;
"return"        return KEYWORD_RETURN;
"if"            return KEYWORD_IF;
"main"          return KEYWORD_MAIN;
"nil"           return P_NIL;
"true"|"false" return P_BOOL;
{operators}     return yytext[0];
{identifier} {printf("%s\n",yytext);yylval.id = yytext; return IDENTIFIER;}
{string_lit}  {printf("%s\n",yytext);yylval.str = yytext; return STRING_LITERAL;
{predeclared_functions} {yylval.id = yytext; return P_FUNCTION;}
{predeclared_type} {yylval.id = yytext; return P_TYPE;}
{int_lit} {yylval.num = atoi(yytext); return INT_LITERAL;}
{float_lit} {yylval.f = atof(yytext); return FLOAT_LITERAL;}
. {printf("unexpected character %s",yytext);}

%%{}