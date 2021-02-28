%{
void yyerror (char *s);
int yylex();
#include <stdio.h>     /* C declarations used in actions */
#include <stdlib.h>
#include <ctype.h>
int yylineno;
%}

%union {char* str;}
%start s
%token STRING_LITERAL
%token INT_LITERAL
%token FLOAT_LITERAL
%token IDENTIFIER

%token LOGICAL_OR
%token LOGICAL_AND

%token LSHIFT
%token RSHIFT
%token AMPXOR

%token CHANNEL_ASSIGN

%token REL_EQUAL
%token REL_NEQUAL
%token REL_LT
%token REL_LEQ
%token REL_GT
%token REL_GEQ

%token ADD_ASSIGN
%token SUB_ASSIGN
%token OR_ASSIGN
%token XOR_ASSIGN
%token MUL_ASSIGN
%token DIV_ASSIGN
%token MOD_ASSIGN
%token AND_ASSIGN
%token LSHIFT_ASSIGN
%token RSHIFT_ASSIGN
%token AMPXOR_ASSIGN
%token INC_ASSIGN
%token DEC_ASSIGN

%token KEYWORD_PACKAGE
%token KEYWORD_IMPORT
%token KEYWORD_FUNC
%token KEYWORD_CONST
%token KEYWORD_TYPE
%token KEYWORD_VAR
%token KEYWORD_FOR
%token KEYWORD_RANGE

%token SHORT_DECLARATION

%token P_BOOL
%token P_NIL
%token P_TYPE
%token P_FUNCTION

%%

s:
    PackageClause ImportDeclarations TopLevelDeclarations
;

/* Package */
PackageClause:
    KEYWORD_PACKAGE PackageName 
;

PackageName:
	IDENTIFIER
;

/*import*/

ImportDeclarations:
    ImportDeclaration ImportDeclarations
    | empty
;

ImportDeclaration:
    KEYWORD_IMPORT ImportSpecification
    | KEYWORD_IMPORT '(' ImportSpecificationList ')'
;

ImportSpecificationList:
    ImportSpecification ImportSpecificationList2
;

ImportSpecificationList2:
    ImportSpecification ImportSpecificationList2 //%prec NORMAL
    | empty
;

ImportSpecification:
    STRING_LITERAL
    | '.' STRING_LITERAL
    | PackageName STRING_LITERAL
;

/* Top Level Declaration */
TopLevelDeclarations:
    TopLevelDeclaration TopLevelDeclarations
    | empty
;

TopLevelDeclaration:
    Declaration
    | KEYWORD_FUNC IDENTIFIER '(' ')' CodeBlock
;

Declaration:
    ConstDeclaration 
    | TypeDeclaration 
    | VariableDeclaration
;

/* const declaration */
ConstDeclaration:
    KEYWORD_CONST ConstSpecification
    | KEYWORD_CONST '(' ConstSpecifications ')'
;

ConstSpecifications:
    ConstSpecification 
    | ConstSpecifications ConstSpecification
;

ConstSpecification:
    IdentifierList ConstIdList
;

ConstIdList:
    PreConstIdList '=' ExpressionList
;

PreConstIdList:
    Type
    | empty
;

/* Type Declaration */

TypeDeclaration:
    KEYWORD_TYPE TypeSpecifications
;

TypeSpecifications:
    TypeSpecification
    | '(' TypeSpecificationList ')'
;

TypeSpecificationList:
    TypeSpecification TypeSpecificationList 
    | empty
;

TypeSpecification:
    AliasDeclaration 
    | TypeDefinition
;

AliasDeclaration: 
    IDENTIFIER '=' Type
;

TypeDefinition:
    IDENTIFIER Type
;


/* Variable Declaration */

VariableDeclaration:
    KEYWORD_VAR VariableSpecifications
    | KEYWORD_VAR '(' VariableSpecifications ')'
;

VariableSpecifications:
    VariableSpecification
    | VariableSpecifications VariableSpecification
;

VariableSpecification:
    IdentifierList VariableIdList
;

VariableIdList:
    Type VariableIdListType
;

VariableIdListType:
    '=' ExpressionList
    | empty
;

IdentifierList:
    IDENTIFIER
    | IdentifierList ',' IDENTIFIER
;

/* Type */
Type:
    TypeName
    | '(' Type ')'
    | empty
;

TypeName:
    P_TYPE
    | QualifiedID
;

QualifiedID:
    PackageName '.' IDENTIFIER
;

/* Expression */

ExpressionList:
    Expression
    | ExpressionList ',' Expression
;

Expression:
    Expression LOGICAL_OR Expression
    | Expression LOGICAL_AND Expression
    | Expression RelationalOperation Expression
    | Expression AddOperation Expression
    | Expression MultipyOperation Expression
    | UnaryExpression
;

RelationalOperation:
    REL_EQUAL
    | REL_NEQUAL
    | REL_LT
    | REL_LEQ
    | REL_GT
    | REL_GEQ
;

AddOperation:
    '+'
    | '-'
    | '|'
    | '^'
;

MultipyOperation:
    '*'
    | '/'
    | '%'
    | LSHIFT
    | RSHIFT
    | '&'
    | AMPXOR

;

UnaryOperation:
    '+'
    | '-'
    | '!'
    | '^'
    | '*'
    | '&'
;

AssignOperation:
    ADD_ASSIGN
    | SUB_ASSIGN
    | OR_ASSIGN
    | XOR_ASSIGN
    | MUL_ASSIGN
    | DIV_ASSIGN
    | MOD_ASSIGN
    | AND_ASSIGN
    | LSHIFT_ASSIGN
    | RSHIFT_ASSIGN
    | AMPXOR_ASSIGN
;

UnaryExpression:
    CHANNEL_ASSIGN UnaryExpression
    | UnaryOperation UnaryExpression
    | PrimaryExpression
;

PrimaryExpression:
    Operand
    | PrimaryExpression Index
;

Index:
    '[' Expression ']'
;

Operand:
    Literal
    | OperandName
    | '(' Expression ')'
    | P_NIL
    | P_BOOL
;

Literal:
    BasicLiteral
;

BasicLiteral:
    INT_LITERAL
    | FLOAT_LITERAL
    | STRING_LITERAL
;

OperandName:
    IDENTIFIER
    | P_FUNCTION
;


/* Code Block */

CodeBlock:
    '{'
    Statements
    '}'
;

Statements:
    Statements Statement
    | empty
;

Statement:
    SimpleStatement
    | Declaration
    | ForStatement
    /*
    | SwitchStatement
    */
;

SimpleStatement:
    Expression
    | IncrementDecrement
    | Assignment
    | ShortDeclaration
;

IncrementDecrement:
    Expression INC_ASSIGN
    | Expression DEC_ASSIGN
;

Assignment:
    ExpressionList '=' ExpressionList
    | Expression AssignOperation Expression
;

ShortDeclaration:
    IdentifierList SHORT_DECLARATION ExpressionList
;

/* For Statement */

ForStatement: 
    KEYWORD_FOR
    ForClauseParent
    CodeBlock
;

ForClauseParent:
    ForCondition 
    | ForClause
    | RangeClause 
    | empty
;

ForCondition:
    Expression
;

ForClause:
    ForClauseInit ';' 
    ForClauseCondition ';' 
    ForClauseUpdation
;

ForClauseInit:
    InitializeStatement
    | empty
;

ForClauseCondition:
    Expression
;

ForClauseUpdation:
    UpdationStatement
    | empty
;

InitializeStatement:
    SimpleStatement
;

UpdationStatement:
    SimpleStatement
;

RangeClause:
    PreForRange KEYWORD_RANGE Expression
;

PreForRange:
    ExpressionList '='
    | IdentifierList SHORT_DECLARATION
    | empty
;


empty: ;

%%
int main (void) {
	
	return yyparse();
}

void yyerror (char *s) {fprintf (stderr, "%d %s\n",yylineno, s);} 