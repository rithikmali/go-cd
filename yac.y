%{
    #include <stdio.h>
    #include <stdlib.h>
    #define YYSTYPE char*
%}

%start SourceFile
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN LSHIFT_ASSIGN RSHIFT_ASSIGN AND_ASSIGN OR_ASSIGN XOR_ASSIGN MOD_ASSIGN INC_ASSIGN DEC_ASSIGN AMPXOR_ASSIGN SHORT_DECLARATION LOGICAL_AND LOGICAL_OR REL_EQUAL REL_NEQUAL REL_GEQ REL_LEQ AMPXOR LSHIFT RSHIFT CHANNEL_ASSIGN REL_GT REL_LT KEYWORD_DEFAULT KEYWORD_BREAK KEYWORD_CHAN KEYWORD_SELECT KEYWORD_FUNC KEYWORD_MAP KEYWORD_INTERFACE KEYWORD_GO KEYWORD_FALLTHROUGH KEYWORD_ELSE KEYWORD_DEFER KEYWORD_GOTO KEYWORD_CONST KEYWORD_STRUCT KEYWORD_CASE KEYWORD_PACKAGE KEYWORD_CONTINUE KEYWORD_SWITCH KEYWORD_TYPE KEYWORD_IMPORT KEYWORD_RANGE KEYWORD_VAR KEYWORD_FOR KEYWORD_RETURN KEYWORD_IF KEYWORD_MAIN P_NIL

%precedence EMPTY
%precedence NORMAL
%token IDENTIFIER FLOAT_LITERAL STRING_LITERAL P_TYPE P_BOOL P_FUNCTION INT_LITERAL

%left LOGICAL_OR
%left LOGICAL_AND
%left REL_EQUAL REL_NEQUAL REL_LT REL_LEQ REL_GT REL_GEQ 
%left '+' '-' '|' '^'
%left '*' '/' '%' LSHIFT RSHIFT '&' AMPXOR
%nonassoc CHANNEL_ASSIGN
%right P_UNARY

%left   NotPackage
%left   KEYWORD_PACKAGE

%left   NotParen
%left   '('

%left   ')'
%left   PreferToRightParen

%%

Expression:
    Expression LOGICAL_OR Expression
    | Expression LOGICAL_AND Expression
    | Expression RelationalOperation Expression %prec REL_EQUAL
    | Expression AddOperation Expression %prec '+'
    | Expression MultipyOperation Expression %prec '-'
    | UnaryExpression %prec P_UNARY
;

ExpressionList:
    Expression
    | ExpressionList ',' Expression
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
    | UnaryOperation UnaryExpression %prec P_UNARY
    | PrimaryExpression
;

/*
PrimaryExpr =
	Operand |
	Conversion |
	MethodExpr |
	PrimaryExpr Selector |
	PrimaryExpr Index |
	PrimaryExpr Slice |
	PrimaryExpr TypeAssertion |
	PrimaryExpr Arguments .

Selector       = "." identifier .
Index          = "[" Expression "]" .
Slice          = "[" [ Expression ] ":" [ Expression ] "]" |
                 "[" [ Expression ] ":" Expression ":" Expression "]" .
TypeAssertion  = "." "(" Type ")" .
Arguments      = "(" [ ( ExpressionList | Type [ "," ExpressionList ] ) [ "..." ] [ "," ] ] ")" 
*/

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

CodeBlock:
    '{'
    Statements
    '}'
;

Statements:
    Statements Statement //%prec NORMAL
    | %empty %prec EMPTY
;

Statement:
    SimpleStatement
    | Declaration
    | ForStatement
    | SwitchStatement
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

SourceFile:
    PackageClause ImportDeclarations TopLevelDeclarations
    {
        if(yychar!=YYEOF)
        {
            printf("Invalid\n");YYERROR;
        }
        printf("Valid\n"); YYACCEPT;
    }
;

PackageClause:
    KEYWORD_PACKAGE PackageName 
;

PackageName:
	IDENTIFIER {printf("got id\n");}
;

/*Import*/
ImportDeclarations:
    ImportDeclaration ImportDeclarations //%prec NORMAL
    | %empty %prec EMPTY
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
    | %empty %prec EMPTY
;

ImportSpecification:
    STRING_LITERAL
    | '.' STRING_LITERAL
    | PackageName STRING_LITERAL
;

Type:
    TypeName
    | '(' Type ')'
;

TypeName:
    P_TYPE
    | QualifiedID
;

QualifiedID:
    PackageName '.' IDENTIFIER
;
TopLevelDeclarations:
    TopLevelDeclaration TopLevelDeclarations //%prec NORMAL
    | %empty %prec EMPTY
;

TopLevelDeclaration:
    Declaration
    | KEYWORD_FUNC KEYWORD_MAIN '(' ')' CodeBlock
;
/* Declerations */
Declaration:
    ConstDeclaration 
    | TypeDeclaration 
    | VariableDeclaration
;

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
    Type //%prec NORMAL
    | %empty %prec EMPTY
;

TypeDeclaration:
    KEYWORD_TYPE TypeSpecifications
;

TypeSpecifications:
    TypeSpecification
    | '(' TypeSpecificationList ')'
;

TypeSpecificationList:
    TypeSpecification TypeSpecificationList //%prec NORMAL
    | %empty %prec EMPTY
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
    '=' ExpressionList //%prec NORMAL
    | %empty %prec EMPTY
;
/*  End of declerations */

IdentifierList:
    IDENTIFIER
    | IdentifierList ',' IDENTIFIER
;

ForStatement: 
    KEYWORD_FOR
    ForClauseParent
    CodeBlock
;

ForClauseParent:
    ForCondition //%prec NORMAL 
    | ForClause //%prec NORMAL
    | RangeClause //%prec NORMAL
    | %empty %prec EMPTY
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
    InitializeStatement //%prec NORMAL
    | %empty %prec EMPTY
;

ForClauseCondition:
    Expression
;

ForClauseUpdation:
    UpdationStatement //%prec NORMAL
    | %empty %prec EMPTY
;

InitializeStatement:
    SimpleStatement
;

UpdationStatement:
    SimpleStatement
;

RangeClause:
    PreForRange
    KEYWORD_RANGE
    Expression
;

PreForRange:
    ExpressionList '=' //%prec NORMAL
    | IdentifierList SHORT_DECLARATION //%prec NORMAL
    | %empty %prec EMPTY
;

/* Switch */
SwitchStatement: 
    ExpressionSwitchStatement 
    | TypeSwitchStatement
;

ExpressionSwitchStatement:
    KEYWORD_SWITCH SimpleStatement ';' Expression '{' ExpressionCaseClause '}'
;

ExpressionCaseClause:
    ExpressionSwitchCase ':' Statements
;

ExpressionSwitchCase:
    KEYWORD_CASE ExpressionList 
    | KEYWORD_DEFAULT
;

TypeSwitchStatement:
    KEYWORD_SWITCH SimpleStatement ';' TypeSwitchGuard '{' TypeCaseClause '}' 
;

TypeSwitchGuard: 
    IDENTIFIER SHORT_DECLARATION PrimaryExpression '.' '(' KEYWORD_TYPE ')'
;

TypeCaseClause:
    TypeSwitchCase ':' Statements
;

TypeSwitchCase:
     KEYWORD_CASE TypeList | KEYWORD_DEFAULT 
;

TypeList:
     Type ',' Type 
;
