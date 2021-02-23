%{
	#include<stdio.h>
    #include "cdgolanghead.h"
    
%}

single_comment \/\/.* 
multi_comment "/*"[^*]*"*"+([^*/][^*]*"*"+)*"/"  
letter [a-zA-Z_]
digit [0-9]
operators [+&()\-|\[\]\^:\.{}\/\*=,;%!]

%%
{single_comment} ;
{multi_comment} ;

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
"++"    return INC_ASSIGN;
"--"    return DEC_ASSIGN;

":="    return SHORT_DECLARATION;

"&&"    return LOGICAL_AND;
"||"    return LOGICAL_OR;
"=="    return REL_EQUAL;
"!="    return REL_NEQUAL;
">="    return REL_GEQ;
"<="    return REL_LEQ;
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
"package"       return KEYWORD_PACKAGE;
"continue"      return KEYWORD_CONTINUE;
"switch"        return KEYWORD_SWITCH;
"type"          return KEYWORD_TYPE;
"import"        return KEYWORD_IMPORT;
"range"         return KEYWORD_RANGE;
"var"           return KEYWORD_VAR;
"for"           return KEYWORD_FOR;
"return"        return KEYWORD_RETURN;
"if"            return KEYWORD_IF;

{operators}     return yytext[0];
{letter}[{letter}{digit}]* return yytext;
"\".*\"" | "`[.\n]*`"   return STRING;




. printf("unexpected character",yytext);
%%
int yywrap(void)
{
    return 1;
}