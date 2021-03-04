%{
// void yyerror (char *s);
// int yylex();
#include <stdio.h>     /* C declarations used in actions */
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
union NodeVal value;
// int yylineno;
int TABLE_SIZE = 10009;

int base = 100;

typedef struct symbol_table {
    char name[31];
    char dtype[10];
    char type;
    char value[20];
    char scope[10];
    int hcode;
  }ST;
  
 ST hashTable[10009];

struct Stack {
   char s[25][25];
   int top;
};

typedef struct Stack stack;

stack stack_i = {.top = -1};
stack stack_v = {.top = -1};
stack stack_r = {.top = -1};
stack stack_scope = {.top = -1};


char result[20];
char Tflag[20];

int stfull(stack st,int size) {
	if (st.top >= size - 1)
		return 1;
	else
		return 0;
}

void push(stack *p_st,char *item) {
	p_st->top++;
	strcpy(p_st->s[p_st->top], item);
}

int stempty(stack st) {
	if (st.top == -1)
		return 1;
	else
		return 0;
}

char * pop(stack *p_st) {
	char *item;
	item = p_st->s[p_st->top];
	p_st->top--;
	return (item);
}

int hash1(char *token) {
				
	int hash = 0;
	for (int i = 0; token[i] != '\0'; i++) { 
		hash = ( 256 * hash + token[i] ) % 1000000009; 
	}
	hash = hash % TABLE_SIZE;
	return hash;

}

int check(char *token) {
				
	int index1 = hash1(token); 
	int i = 0;
	while ( i < TABLE_SIZE && strcmp(hashTable[( index1 + i ) % TABLE_SIZE].name, token) != 0 )
		i++;

	if ( i == TABLE_SIZE )
		return 1;
	else
		return index1 + i;

}


void insert(char type, char *token, char *dtype, char *value, char *scope) {

	if (check(token) != 1) {
		yyerror("variable is redeclared");
    	return;
  	}
  	int index = hash1(token);

  	if (hashTable[index].hcode != -1) {

	    int i = 1;
		while (1) {
			int newIndex = (index + i) % TABLE_SIZE;

			if (hashTable[newIndex].hcode == -1) {

				strcpy(hashTable[newIndex].name, token);
				strcpy(hashTable[newIndex].dtype, dtype);
				strcpy(hashTable[newIndex].value, value);
				strcpy(hashTable[newIndex].scope, scope);
				hashTable[newIndex].type = type;
				hashTable[newIndex].hcode = 1;
				break;
			}
			i++;
		}
	}

	else {
		strcpy(hashTable[index].name, token);
		strcpy(hashTable[index].dtype, dtype);
		strcpy(hashTable[index].value, value);
		strcpy(hashTable[index].scope, scope);
		hashTable[index].type = type;
		hashTable[index].hcode = 1;
	}
}
char * search(char *token) {

	int index1 = hash1(token); 
	int i = 0;
	while ( i < TABLE_SIZE && strcmp(hashTable[( index1 + i ) % TABLE_SIZE].name, token)!=0)
		i++;
	if ( i == TABLE_SIZE ) {
		printf("Error: %s is not defined\n", token);
		exit(0);
	}
	else
		return hashTable[index1 + i].dtype;
}


void update(char *token, char *dtype, char *value) {
	int index = check(token);
	if ( index == 1 ) {
		printf("Error: %s is not defined\n", token);
		exit(0);
		return;
	}
	
	if (hashTable[index].type == 'c') {
		printf("Error: cannot assign to %s (declared const)", token);
		exit(0);
		return;
	}
	else {
		if (strcmp(hashTable[index].value, "NULL") != 0)
			strcpy(hashTable[index].value, value);
		if (strcmp(hashTable[index].dtype, "NULL") != 0)
			strcpy(hashTable[index].dtype, dtype);
	}
}

void disp_symtbl() {

	int base = 1000;
	printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n","Name", "Type","Data Type", "Value", "Scope");

	for(int i=0; i<TABLE_SIZE; i++) {
		if(hashTable[i].hcode != -1 )
			printf("%s\t\t%c\t\t%s\t\t\t%s\t\t%s\n",hashTable[i].name, hashTable[i].type, hashTable[i].dtype, hashTable[i].value, hashTable[i].scope);
		}

}

%}
%define api.value.type union
%define parse.error verbose
%start s

%type <struct node *> IdentifierList ExpressionList Expression Literal BasicLiteral Operand OperandName RelationalOperation AddOperation MultipyOperation UnaryExpression PrimaryExpression AssignOperation UnaryOperation QualifiedID Assignment VariableSpecification VariableIdList VariableIdListType Type TypeName

%token <char const *> STRING_LITERAL
%token <int> INT_LITERAL
%token <double> FLOAT_LITERAL
%token <char const *> IDENTIFIER

%token <char const *> LOGICAL_OR
%token <char const *> LOGICAL_AND

%token <char const *> LSHIFT
%token <char const *> RSHIFT
%token <char const *> AMPXOR

%token <char const *> CHANNEL_ASSIGN

%token <char const *> REL_EQUAL
%token <char const *> REL_NEQUAL
%token <char const *> REL_LT
%token <char const *> REL_LEQ
%token <char const *> REL_GT
%token <char const *> REL_GEQ

%token <char const *> ADD_ASSIGN
%token <char const *> SUB_ASSIGN
%token <char const *> OR_ASSIGN
%token <char const *> XOR_ASSIGN
%token <char const *> MUL_ASSIGN
%token <char const *> DIV_ASSIGN
%token <char const *> MOD_ASSIGN
%token <char const *> AND_ASSIGN
%token <char const *> LSHIFT_ASSIGN
%token <char const *> RSHIFT_ASSIGN
%token <char const *> AMPXOR_ASSIGN
%token <char const *> INC_ASSIGN
%token <char const *> DEC_ASSIGN

%token KEYWORD_PACKAGE
%token KEYWORD_IMPORT
%token KEYWORD_FUNC
%token KEYWORD_CONST
%token KEYWORD_TYPE
%token KEYWORD_VAR
%token KEYWORD_FOR
%token KEYWORD_RANGE
%token KEYWORD_DEFAULT
%token KEYWORD_CASE
%token KEYWORD_SWITCH


%token <char const *> SHORT_DECLARATION

%token <char const *> P_BOOL
%token P_NIL
%token <char const *> P_TYPE
%token <char const *> P_FUNCTION

%precedence EMPTY
%precedence NORMAL

%left LOGICAL_OR
%left LOGICAL_AND
%left REL_EQUAL REL_NEQUAL REL_LT REL_LEQ REL_GT REL_GEQ
%left '+' '-' '|' '^'
%left '*' '/' '%' LSHIFT RSHIFT '&' AMPXOR
%nonassoc CHANNEL_ASSIGN
%right P_UNARY
%left   KEYWORD_PACKAGE
%left   '('
%left   ')'
%left   PreferToRightParen
%%

s:
    PackageClause ImportDeclarations TopLevelDeclarations
    {
        if(yychar != YYEOF) 
        {
            printf("Invalid - reached start symbol before EOF\n"); YYERROR;
        }
        printf("Valid\n"); 
        YYACCEPT;
    }
;

/* Package */
PackageClause:
    KEYWORD_PACKAGE IDENTIFIER
;

/*import*/

ImportDeclarations:
    ImportDeclaration ImportDeclarations %prec NORMAL
    | empty %prec EMPTY
;

ImportDeclaration:
    KEYWORD_IMPORT ImportSpecification
    | KEYWORD_IMPORT '(' ImportSpecificationList ')'
;

ImportSpecificationList:
    ImportSpecification ImportSpecificationList2
;

ImportSpecificationList2:
    ImportSpecification ImportSpecificationList2 %prec NORMAL
    | %empty %prec EMPTY
;

ImportSpecification:
    STRING_LITERAL
    | '.' STRING_LITERAL
    | IDENTIFIER STRING_LITERAL
;

/* Top Level Declaration */
TopLevelDeclarations:
    TopLevelDeclaration TopLevelDeclarations %prec NORMAL
    | %empty %prec EMPTY
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
    {
        if(stack_v.top != stack_i.top && stack_v.top != -1) {
            yyerror("Imbalanced assignment");
            YYERROR;
        }
        else {
            if (stack_v.top == -1){
                while(!stempty(stack_i)) {

                    insert('c', pop(&stack_i), pop(&stack_r), "NULL", stack_scope.s[stack_scope.top]);

                }
            }
            else {
                while(!stempty(stack_i)) {

                    insert('c', pop(&stack_i), pop(&stack_r), pop(&stack_v), stack_scope.s[stack_scope.top]);
                }
            }
        } 
    }
    | KEYWORD_CONST '(' ConstSpecifications ')'
    {
        if(stack_v.top != stack_i.top && stack_v.top != -1) {
            yyerror("Imbalanced assignment");
            YYERROR;
        }
        else {
            if (stack_v.top == -1){
                while(!stempty(stack_i)) {

                    insert('c', pop(&stack_i), pop(&stack_r), "NULL", stack_scope.s[stack_scope.top]);
                }
            }
            else {
                while(!stempty(stack_i)) {

                    insert('c', pop(&stack_i), pop(&stack_r), pop(&stack_v), stack_scope.s[stack_scope.top]);
                }
            }
        }  
    }
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
    Type %prec NORMAL
    | empty %prec EMPTY
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
    TypeSpecification TypeSpecificationList %prec NORMAL 
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


/* Variable Declaration */

VariableDeclaration:
    KEYWORD_VAR VariableSpecifications
    { 
        if(stack_v.top != stack_i.top && stack_v.top != -1) 
        {
                yyerror("Imbalanced assignment");
                YYERROR;
        }
        else 
        {
            if(stack_v.top == -1)
            {
                while(!stempty(stack_i)) 
                {

                    insert('v', pop(&stack_i), Tflag, "NULL", stack_scope.s[stack_scope.top]);
                }
            }
            else {
                while(!stempty(stack_i)) {

                    insert('v', pop(&stack_i), pop(&stack_r), pop(&stack_v), stack_scope.s[stack_scope.top]);

                }
            }
        } 
    }
    | KEYWORD_VAR '(' VariableSpecifications ')'
    { 
        if(stack_v.top != stack_i.top && stack_v.top != -1) {
            yyerror("Imbalanced assignment");
            YYERROR;
        }
        else 
        {
            if (stack_v.top == -1){
                while(!stempty(stack_i)) 
                {

                    insert('v', pop(&stack_i), Tflag, "NULL", stack_scope.s[stack_scope.top]);

                }
            }
            else 
            {
                while(!stempty(stack_i)) 
                {

                    insert('v', pop(&stack_i), pop(&stack_r), pop(&stack_v), stack_scope.s[stack_scope.top]);
                }
            }
        } 
    }  
;

VariableSpecifications:
    VariableSpecification
    | VariableSpecifications VariableSpecification
;

VariableSpecification:
    IdentifierList VariableIdList
    { 
        if($2) 
        {
            printf("Assigning to variables\nIds: %d Exprs: %d\n", seqLen($1), seqLen($2->value.n)); 
            value.op[0] = '='; value.op[1] = 0; 
            $$ = makeNode(OP, value, $1, $2);
        } 
        else {
            printf("Not assigning\n");
            $$ = NULL;
        }
    }
;

VariableIdList:
    Type VariableIdListType
    {	
    $$ = $2;
    strcpy(Tflag, $1->value.name);
    }
    | '=' ExpressionList
    {	
    value.n = $2; 
    $$ = makeNode(OP, value, NULL, NULL);
    }
;

VariableIdListType:
    '=' ExpressionList %prec NORMAL
    {	
    value.n = $2; 
    $$ = makeNode(OP, value, NULL, NULL);
    }
    | empty %prec EMPTY
    {
        $$ = NULL; 
    }
;

IdentifierList:
    IDENTIFIER
    {
        strcpy(value.name, $1); 
		$$ = makeNode(ID, value, NULL, NULL); 
        push(&stack_i, value.name);
    }
    | IDENTIFIER ',' IdentifierList
    {
	
	    strcpy(value.name, $1); 
		$$ = makeNode(SEQ, value, makeNode(ID, value, NULL, NULL), $3);
		push(&stack_i, value.name);

    }
;

/* Type */
Type:
    TypeName 
    {
        $$=$1;
    }
    | '(' Type ')'
    {
        $$=$2;
    }
;

TypeName:
    P_TYPE
    {
        strcpy(value.name,$1);
        $$ = makeNode(ID,value,NULL,NULL);
    }
    | QualifiedID
    {
        $$ = $1;
    }
;

QualifiedID:
    IDENTIFIER '.' IDENTIFIER
;

/* Expression */

ExpressionList:
    Expression
    {
        $$ = $1;		 			
    	if ($1->type == INT) 
        {
            sprintf(result, "%d", $1->value.i);
            push(&stack_r, "int");
        }
        if ($1->type == FLOAT) 
        {
            sprintf(result, "%f", $1->value.f);
            push(&stack_r, "float");
        }
        if ($1->type == STRING) 
        {
            strcpy(result, $1->value.str);
            push(&stack_r, "string");
        }
                
        push(&stack_v, result);
    }
    | Expression ',' ExpressionList
    { 
        $$ = makeNode(SEQ, value, $1, $3);

        
        if ($1->type == INT) {
            sprintf(result, "%d", $1->value.i);
            push(&stack_r, "int");
        }
        if ($1->type == FLOAT) {
            sprintf(result, "%f", $1->value.f);
            push(&stack_r, "float");
        }
        if ($1->type == STRING) {
            strcpy(result, $1->value.str);
            push(&stack_r, "string");
        }
                
        push(&stack_v, result);
    			
	}
;

Expression:
    Expression LOGICAL_OR Expression
    | Expression LOGICAL_AND Expression
    | Expression RelationalOperation Expression %prec REL_EQUAL
    | Expression AddOperation Expression %prec '+'
    | Expression MultipyOperation Expression %prec '-'
    | UnaryExpression %prec P_UNARY
;

RelationalOperation:
    REL_EQUAL
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL); }
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
    {
        $$ = $1;
    }
;

PrimaryExpression:
    Operand
    {
        $$ = $1;
    }
    | PrimaryExpression Index
;

Index:
    '[' Expression ']'
;

Operand:
    Literal
    {
        $$ = $1;
    }
    | OperandName
    {
        $$ = $1;
    }
    | '(' Expression ')'
    {
        $$ = $2;
    }
    | P_NIL
    | P_BOOL
;

Literal:
    BasicLiteral
    {
        $$ = $1;
    }
;

BasicLiteral:
    INT_LITERAL
    {
        value.i = $1; $$ = makeNode(INT, value, NULL, NULL);
    }
    | FLOAT_LITERAL
    {
        value.f = $1; $$ = makeNode(FLOAT, value, NULL, NULL);
    }
    | STRING_LITERAL
    {
        strcpy(value.str, $1); $$ = makeNode(STRING, value, NULL, NULL);
    }
;

OperandName:
    IDENTIFIER
    {
        strcpy(value.name, $1); $$ = makeNode(ID, value, NULL, NULL);
    }
    | P_FUNCTION
    {
        strcpy(value.name, $1); $$ = makeNode(FUNC, value, NULL, NULL);
    }
    | QualifiedID
    {
        $$ = $1;
    }
;


/* Code Block */

CodeBlock:
    '{'
    {	
        sprintf(result, "%d", base++);
        push(&stack_scope, result);
    } 
    Statements
    { 
        pop(&stack_scope); 
    }
    '}'
;

Statements:
    Statements Statement %prec NORMAL
    | empty %prec EMPTY
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
    {	
        printf("started\n"); 
        value.op[0] = '='; 
        value.op[1] = 0; 
        printf("Operator: %s\n", value.op); 
        $$ = makeNode(OP, value, $1, $3);
        strcpy(result, search($1->value.name));

        if(strcmp(result, "int") == 0 && $3->type == INT) {
            sprintf(result, "%d", $3->value.i);
            update($1->value.name, "int", result);
        }

        else if(strcmp(result, "float") == 0 && $3->type == FLOAT) {
            sprintf(result, "%f", $3->value.f);
            update($1->value.name, "int", result);
        }	

        else if(strcmp(result, "string") == 0 && $3->type == STRING)
            update($1->value.name, "int", $3->value.str);

        else {
            yyerror("Error type mismatched assignment");
            YYERROR;
        }

        }
    | ExpressionList AssignOperation ExpressionList
    
;

ShortDeclaration:
    IdentifierList SHORT_DECLARATION ExpressionList
    {
        if(stack_v.top != stack_i.top && stack_v.top != -1) {
            yyerror("Imbalanced assignment");
            YYERROR;
        }
        else {
            if (stack_v.top == -1){
                while(!stempty(stack_i)) {

                    insert('v', pop(&stack_i), pop(&stack_r), "NULL", stack_scope.s[stack_scope.top]);

                }
            }
            else {
                while(!stempty(stack_i)) {

                    insert('v', pop(&stack_i), pop(&stack_r), pop(&stack_v), stack_scope.s[stack_scope.top]);

                }
            }
                
        }
    }
;

/* For Statement */

ForStatement: 
    KEYWORD_FOR
    ForClauseParent
    CodeBlock
;

ForClauseParent:
    ForCondition %prec NORMAL
    | ForClause %prec NORMAL
    | RangeClause %prec NORMAL 
    | empty %prec EMPTY
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
    InitializeStatement %prec NORMAL
    | empty %prec EMPTY
;

ForClauseCondition:
    Expression
;

ForClauseUpdation:
    UpdationStatement %prec NORMAL
    | empty %prec EMPTY
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
    ExpressionList '=' %prec NORMAL
    | IdentifierList SHORT_DECLARATION %prec NORMAL
    | empty %prec EMPTY
;

/* Switch Statement */

SwitchStatement:
    ExprSwitchStmt 
    | TypeSwitchStmt
;

ExprSwitchStmt:
    KEYWORD_SWITCH SimpleStatement '{' ExprCaseClauses '}'
;
ExprCaseClauses:
    ExprCaseClauses ExprCaseClause
    | ExprCaseClause
;

ExprCaseClause:
    ExprSwitchCase ':' Statements
;

ExprSwitchCase:
    KEYWORD_CASE ExpressionList 
    | KEYWORD_DEFAULT
;

TypeSwitchStmt:
    KEYWORD_SWITCH TypeSwitchGuard '{' TypeCaseClauses '}'
;

TypeSwitchGuard:
   IDENTIFIER SHORT_DECLARATION IDENTIFIER '.' '(' KEYWORD_TYPE ')'
   | IDENTIFIER SHORT_DECLARATION Literal '.' '(' KEYWORD_TYPE ')'
;

TypeCaseClauses:
    TypeCaseClauses TypeCaseClause
    | TypeCaseClause
;

TypeCaseClause:
    TypeSwitchCase ':' Statements
;

TypeSwitchCase: 
    KEYWORD_CASE TypeList
    | KEYWORD_DEFAULT
;

TypeList:
    Type
    | Type ',' TypeList
;

empty: %empty;

/*
TypeSwitchStmt  = "switch" [ SimpleStmt ";" ] TypeSwitchGuard "{" { TypeCaseClause } "}" .
TypeSwitchGuard = [ identifier ":=" ] PrimaryExpr "." "(" "type" ")" .
TypeCaseClause  = TypeSwitchCase ":" StatementList .
TypeSwitchCase  = "case" TypeList | "default" .
TypeList        = Type { "," Type } .
*/

%%

extern int yylineno;

void yyerror(char const* error) {
	fprintf(stderr, "%d: %s\n", yylineno, error);
}


int main () {
	for(int i=0; i<TABLE_SIZE; i++)
		hashTable[i].hcode = -1;

	sprintf(result, "%d", base);
	base++;
	push(&stack_scope, result);

	// yydebug = 1;
	if ( yyparse() != 0){
		printf("BUILD FAILED\n\n");
		exit(1);
	}

	printf("\n\n\n");
	printf("---------------------------------Symbol Table---------------------------------\n\n");
	disp_symtbl();
	return 0;
}