%{
    void yyerror (char *s);
    int yylex();
    #include <stdio.h>     /* C declarations used in actions */
    #include <stdlib.h>
    #include <ctype.h>
%}

%start s
%union {int num; double f;char op; char* id; char* str;}
%token ADD_ASSIGN 
%token SUB_ASSIGN
%token MUL_ASSIGN
%token DIV_ASSIGN
%token LSHIFT_ASSIGN
%token RSHIFT_ASSIGN
%token AND_ASSIGN
%token OR_ASSIGN
%token XOR_ASSIGN
%token MOD_ASSIGN
%token INC_ASSIGN
%token DEC_ASSIGN
%token AMPXOR_ASSIGN
%token SHORT_DECLARATION
%token LOGICAL_AND
%token LOGICAL_OR
%token REL_EQUAL
%token REL_NEQUAL
%token REL_GEQ
%token REL_LEQ
%token AMPXOR
%token LSHIFT
%token RSHIFT
%token CHANNEL_ASSIGN
%token REL_GT
%token REL_LT
%token KEYWORD_DEFAULT
%token KEYWORD_BREAK
%token KEYWORD_CHAN
%token KEYWORD_SELECT
%token KEYWORD_FUNC
%token KEYWORD_MAP
%token KEYWORD_INTERFACE
%token KEYWORD_GO
%token KEYWORD_FALLTHROUGH
%token KEYWORD_ELSE
%token KEYWORD_DEFER
%token KEYWORD_GOTO
%token KEYWORD_CONST
%token KEYWORD_STRUCT
%token KEYWORD_CASE
%token KEYWORD_PACKAGE
%token KEYWORD_CONTINUE
%token KEYWORD_SWITCH
%token KEYWORD_TYPE
%token KEYWORD_IMPORT
%token KEYWORD_RANGE
%token KEYWORD_VAR
%token KEYWORD_FOR
%token KEYWORD_RETURN
%token KEYWORD_IF
%token KEYWORD_MAIN
%token P_NIL


%token <id> IDENTIFIER
%token <f> FLOAT_LITERAL
%token <str> STRING_LITERAL
%token <id> P_TYPE
%token <id> P_BOOL
%token <id> P_FUNCTION
%token <num> INT_LITERAL

%%

s:
    PackageClause ImportDecl '\n'
;

PackageClause:
    KEYWORD_PACKAGE IDENTIFIER '\n'
;

ImportDecl:
    KEYWORD_IMPORT STRING_LITERAL '\n'
;

%%
extern int yylineno;

void yyerror(char* error) {
	fprintf(stderr, "%d: %s\n", yylineno, error);
}

int main()
{
    if (yyparse()==0)
        printf("accepted\n");
    else
        printf("wrong\n");
}