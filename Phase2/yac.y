%{
// void yyerror (char *s);
// int yylex();
#include <stdio.h>     /* C declarations used in actions */
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "server.h"
union NodeVal value;
// int yylineno;
int SYMBOL_TABLE_MAX = 1000;

int base = 100;
int scope_depth = 0;
int scope_id = 0;

struct symbolTableStructure {
  char name[31];
  char declaredVariableType[10];
  char type;
  char value[20];
  int scope_depth;
  int scope_id;
  int hcode;
};

struct symbolTableStructure hashTable[1000];

struct variableStackStructure 
{
    int top;
    char s[25][25];
};

struct queue 
{
    char s[25][200];
    int front;
    int back;
};

typedef struct variableStackStructure stack;
typedef struct queue queue;

int highestIDatLevel[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
stack switchConditionStack = {.top = -1};
queue forLoopQueue = {.front = -1, .back = -1};
stack iStack = {.top = -1};
stack vStack = {.top = -1};
stack scopeStack = {.top = -1};
stack tStack = {.top = -1};

char resString[20];
char tempArray[20] = "";
int tempVariableCount = 0;
int labelCount = 0;
char tempVariableStore[10];
char labelStore[10];
FILE* intermediateCodeFile;

char *popFromStack(stack *stackPointer)
{
  char *stackItem;
  stackItem = stackPointer->s[stackPointer->top];
  stackPointer->top--;
  return (stackItem);
}

void pushToStack(stack *stackPointer, char *stackItem)
{
  stackPointer->top++;
  strcpy(stackPointer->s[stackPointer->top], stackItem);
}

int isStackEmpty(stack st)
{
  if(st.top == -1)
    return 1;
  else
    return 0;
}

void insertToQueue(queue *stackPointer, char *stackItem) 
{
	if(stackPointer->back==199)
    {
		printf("Error Queue Full\n");
		exit(1);
	}
	strcpy(stackPointer->s[++stackPointer->back], stackItem);
}

char *removeFromQueue(queue *stackPointer)
{
	if(stackPointer->front==stackPointer->back)
    {
		printf("Cannot remove from empty queue\n");
		exit(1);
	}
	char *stackItem;
	stackItem = strdup(stackPointer->s[++stackPointer->front]);
	return (stackItem);
}

int firstHashFunction(char *inputToHash)
{
    int currValue = 0;
    for (int i = 0; inputToHash[i] != '\0'; i++)
    {
        currValue=(currValue*128+inputToHash[i])%1000000000;
    }
    currValue = currValue % SYMBOL_TABLE_MAX;
    return currValue;
}

int hashTableIndexReturn(char *inputToHash) 
{
    int i = 0; int hashIndex = firstHashFunction(inputToHash);
    while (i < SYMBOL_TABLE_MAX && !(strcmp(hashTable[(hashIndex + i) % SYMBOL_TABLE_MAX].name, inputToHash) == 0 && hashTable[(hashIndex + i) % SYMBOL_TABLE_MAX].scope_depth == scope_depth && hashTable[(hashIndex + i) % SYMBOL_TABLE_MAX].scope_id == scope_id))
    {
        i++;
    }

    if(i == SYMBOL_TABLE_MAX)
    {
        return -1;
    }
    else
    {
        return hashIndex + i;
    }
}

void appendHashTable(char type, char *inputToHash, char *declaredVariableType, char *value, int scope_depth, int scope_id) 
{
    if(hashTableIndexReturn(inputToHash) != -1)
    {
        yyerror("Variable is being Redeclared");
        exit(1);
    }
    int hashIndex223 = firstHashFunction(inputToHash);

    if(hashTable[hashIndex223].hcode != -1)
    {
        int i = 1;
        while(69)
        {
            int newIndex = (hashIndex223 + i) % SYMBOL_TABLE_MAX;

            if(hashTable[newIndex].hcode == -1)
            {
                strcpy(hashTable[newIndex].name, inputToHash);
                strcpy(hashTable[newIndex].declaredVariableType, declaredVariableType);
                strcpy(hashTable[newIndex].value, value);
                hashTable[newIndex].scope_depth = scope_depth;
                hashTable[newIndex].scope_id = scope_id;
                hashTable[newIndex].type = type;
                hashTable[newIndex].hcode = 1;
                break;
            }
            i++;
        }
    }
    else
    {
        strcpy(hashTable[hashIndex223].name, inputToHash);
        strcpy(hashTable[hashIndex223].declaredVariableType, declaredVariableType);
        strcpy(hashTable[hashIndex223].value, value);
        hashTable[hashIndex223].scope_depth = scope_depth;
        hashTable[hashIndex223].scope_id = scope_id;
        hashTable[hashIndex223].type = type;
        hashTable[hashIndex223].hcode = 1;
    }
}
char *findFromHashTable(char *inputToHash)
{
    int i = 0;
    int hashIndex = firstHashFunction(inputToHash);
    while (i < SYMBOL_TABLE_MAX && strcmp(hashTable[(hashIndex + i) % SYMBOL_TABLE_MAX].name, inputToHash) != 0)
    {
        i++;
    }
    if(i == SYMBOL_TABLE_MAX)
    {
        return NULL;
    } 
    else
    {
        return hashTable[hashIndex + i].declaredVariableType;
    }
}

void updateHashTable(char *inputToHash, char *declaredVariableType, char *value) 
{
    int hashIndex223 = scopeOfParentCheck(inputToHash);
    if(hashIndex223 == -1) 
    {
        char ErrorMessage[100];
        // printf("In here\n");
        sprintf(ErrorMessage, "%s Variable undefined", inputToHash);
        yyerror(ErrorMessage);
        exit(1);
    }

    if(hashTable[hashIndex223].type == 'c') 
    {
        char ErrorMessage[100];
        sprintf(ErrorMessage, "Connot Assign to %s it is a Constant Variable", inputToHash);
        yyerror(ErrorMessage);
        exit(1);
    } 
    else 
    {
        if(strcmp(hashTable[hashIndex223].value, "NULL") != 0)
        {
            strcpy(hashTable[hashIndex223].value, value);
        }
        if(strcmp(hashTable[hashIndex223].declaredVariableType, "NULL") != 0)
        {
            strcpy(hashTable[hashIndex223].declaredVariableType, declaredVariableType);
        }
    }
}

void PresentIdentifierAssignment(Node *LeftHandSide, Node *RightHandSide)
{	
	if(LeftHandSide==NULL && RightHandSide==NULL)
    {
		return;
	}
	if(seqLen(LeftHandSide) != seqLen(RightHandSide))
    {
		yyerror("Unequal Length on LHS and RHS");
		exit(1);
	}
    else
    {
		char* resultFromHash = findFromHashTable(LeftHandSide->lop->value.name);
		if(resultFromHash==NULL)
        {
			char ErrorMessage[100];
			sprintf(ErrorMessage, "%s Variable is not Defined", LeftHandSide->lop->value.name);
			yyerror(ErrorMessage);
			exit(1);
		}
		strcpy(resString, resultFromHash);

		Node *cur = RightHandSide->lop;
		while(cur->type == OP)
        {
			cur = cur->lop;
		}
		int type = cur->type;
		union NodeVal value = cur->value;
		if(cur->type == ID)
        {
			char *declaredType = findFromHashTable(cur->value.name);
			if(declaredType==NULL)
            {
				char ErrorMessage[100];
				sprintf(ErrorMessage, "%s Variable is not Defined", LeftHandSide->lop->value.name);
				yyerror(ErrorMessage);
				exit(1);
			}
		}
		// printf("%s %d\n", resString, type);
		if(strcmp(resString, "int") == 0 && type == INT)
        {
			sprintf(resString, "%d", value.i);
			updateHashTable(LeftHandSide->lop->value.name, "int", resString);
		} 
        else if(strcmp(resString, "float") == 0 && type == FLOAT)
        {
			sprintf(resString, "%f", value.f);
			updateHashTable(LeftHandSide->lop->value.name, "float", resString);
		}
        else if(strcmp(resString, "string") == 0 && type == STRING)
        {
			updateHashTable(LeftHandSide->lop->value.name, "string", value.str);
		}
        else if(strcmp(resString, "rune") == 0 && type == RUNE)
        {
			updateHashTable(LeftHandSide->lop->value.name, "rune", value.str);
		}
        else if(strcmp(resString, "bool") == 0 && type == BOOL)
        {
			sprintf(resString, "%dB", value.b);
			updateHashTable(LeftHandSide->lop->value.name, "bool", resString);
		}
        else
        {
			yyerror("Error: type mismatched assignment");
			exit(1);
		}
		fprintf(intermediateCodeFile, "%s = %s\n", LeftHandSide->lop->value.name, RightHandSide->lop->loc);
	}
	PresentIdentifierAssignment(LeftHandSide->rop, RightHandSide->rop);
}

void IdentifierAssignment(char declaredType, Node *LeftHandSide, Node *RightHandSide)
{
	if(LeftHandSide==NULL && RightHandSide==NULL)
    {
		tempArray[0] = 0;
		return;
	}
	if(seqLen(LeftHandSide) != seqLen(RightHandSide) && seqLen(RightHandSide) != 0)
    {
		yyerror("Unequal Length on LHS and RHS");
		exit(1);
	}
    else
    {
		if(seqLen(RightHandSide) == 0)
        {
			appendHashTable(declaredType, popFromStack(&iStack), tempArray, "NULL", scope_depth, scope_id);
			IdentifierAssignment(declaredType, LeftHandSide->rop, RightHandSide);
		}
        else
        {
			if(tempArray[0] != 0)
            {
				if(strcmp(popFromStack(&tStack),tempArray) != 0)
                {
					yyerror("Declared type and Assigned value have conflicting types");
					exit(1);
				}
				appendHashTable(declaredType, popFromStack(&iStack), tempArray, popFromStack(&vStack), scope_depth, scope_id);
			}
            else
            {
				appendHashTable(declaredType, popFromStack(&iStack), popFromStack(&tStack), popFromStack(&vStack), scope_depth, scope_id);
			}
		}
		fprintf(intermediateCodeFile, "%s = %s\n", LeftHandSide->lop->value.name, RightHandSide->lop->loc);
		IdentifierAssignment(declaredType, LeftHandSide->rop, RightHandSide->rop);
	} 
}

int getNextScope(int scope_depth)
{
	int scope_id = -1;
	if(scope_depth == 1)
    {
		scope_id = 1;
	} else
    {
		scope_id = ++highestIDatLevel[scope_depth];
	}
	return scope_id;
}

int getPreviousScope(int scope_depth)
{
	int scope_id = -1;
	if(scope_depth == 1)
    {
		scope_id = 1;
	} 
    else
    {
		scope_id = highestIDatLevel[scope_depth];
	}
	return scope_id;
}

int scopeOfParentCheck(char *inputToHash) 
{
    int i = 0;
    int hashIndex = firstHashFunction(inputToHash);
    while (i < SYMBOL_TABLE_MAX && !(strcmp(hashTable[(hashIndex + i) % SYMBOL_TABLE_MAX].name, inputToHash) == 0 && (hashTable[(hashIndex + i) % SYMBOL_TABLE_MAX].scope_depth == scope_depth && hashTable[(hashIndex + i) % SYMBOL_TABLE_MAX].scope_id == scope_id) || hashTable[(hashIndex + i) % SYMBOL_TABLE_MAX].scope_depth < scope_depth))
    {
        i++;
    }

    if(i == SYMBOL_TABLE_MAX)
    {
        return -1;
    }
    else
    {
        return hashIndex + i;
    }
}

void createTempVariable()
{
	sprintf(tempVariableStore, "_t%d", tempVariableCount++);
}

void createLabel()
{
	sprintf(labelStore, "L%d", labelCount++);
}

void displaySymbolTable()
{
    printf("%s\t|\t%s\t|\t%s\t|\t%s\t|\t%s\t|\n", "Name", "Data Type", "Value","Scope Depth", "Scope ID");
    int base = 100;
    for(int i=0;i<SYMBOL_TABLE_MAX;i++) 
    {
        if(hashTable[i].hcode != -1)
        {
            printf("%s\t|\t%s\t\t|\t%s\t|\t%d\t\t|\t%d\t\t|\n", hashTable[i].name, hashTable[i].declaredVariableType, hashTable[i].value, hashTable[i].scope_depth, hashTable[i].scope_id);
        }
    }
}

%}
%define api.value.type union
%define parse.error verbose
%start s

%type <struct node *> IdentifierList ExpressionList Expression Literal BasicLiteral Operand OperandName RelationalOperation AddOperation MultipyOperation UnaryExpression PrimaryExpression AssignOperation UnaryOperation QualifiedID Assignment VariableSpecification VariableIdList VariableIdListType Type TypeName ConstIdList ConstSpecification

//Tokens go here
%token <char const *> STRING_LITERAL
%token <int> INT_LITERAL
%token <double> FLOAT_LITERAL
%token <char const *> IDENTIFIER

%token KEYWORD_BREAK
%token KEYWORD_DEFAULT
%token KEYWORD_FUNC
%token KEYWORD_INTERFACE
%token KEYWORD_SELECT
%token KEYWORD_CASE
%token KEYWORD_DEFER
%token KEYWORD_GO
%token KEYWORD_MAP
%token KEYWORD_STRUCT
%token KEYWORD_CHAN
%token KEYWORD_ELSE
%token KEYWORD_GOTO
%token KEYWORD_PACKAGE
%token KEYWORD_SWITCH
%token KEYWORD_CONST
%token KEYWORD_FALLTHROUGH
%token KEYWORD_IF
%token KEYWORD_RANGE
%token KEYWORD_TYPE
%token KEYWORD_CONTINUE
%token KEYWORD_FOR
%token KEYWORD_IMPORT
%token KEYWORD_RETURN
%token KEYWORD_VAR

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
        printf("Parsing Successful. The given Code is Valid\n"); 
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
    | KEYWORD_CONST '(' ConstSpecifications ')'
    {
        if(vStack.top != iStack.top && vStack.top != -1) 
        {
            yyerror("Unequal Length on LHS and RHS");
            YYERROR;
        }
        else 
        {
            if(vStack.top == -1)
            {
                while(!isStackEmpty(iStack))
                {
                    appendHashTable('c', popFromStack(&iStack), popFromStack(&tStack), "NULL", scope_depth, scope_id);
                }
            }
            else 
            {
                while(!isStackEmpty(iStack)) 
                {

                    appendHashTable('c', popFromStack(&iStack), popFromStack(&tStack), popFromStack(&vStack), scope_depth, scope_id);
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
    { 
        value.op[0] = '='; value.op[1] = 0; 
        $$ = makeNode(OP, value, $1, $2);
        IdentifierAssignment('c', $1, $2->value.n);
    }
;

ConstIdList:
    PreConstIdList '=' ExpressionList
    {	
        value.n = $3; 
        $$ = makeNode(OP, value, NULL, NULL);
    }
;

PreConstIdList:
    Type %prec NORMAL
    {	
        strcpy(tempArray, $1->value.name);
    }
    | %empty %prec EMPTY
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
    KEYWORD_VAR VariableSpecification
    | KEYWORD_VAR '(' VariableSpecifications ')'
    { 
        if(vStack.top != iStack.top && vStack.top != -1)
        {
            yyerror("Unequal Length on LHS and RHS");
            YYERROR;
        }
        else 
        {
            if(vStack.top == -1){
                while(!isStackEmpty(iStack))
                {
                    appendHashTable('v', popFromStack(&iStack), tempArray, "NULL", scope_depth, scope_id);
                }
            }
            else 
            {
                while(!isStackEmpty(iStack))
                {
                    appendHashTable('v', popFromStack(&iStack), popFromStack(&tStack), popFromStack(&vStack), scope_depth, scope_id);
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
            value.op[0] = '='; value.op[1] = 0; 
            // printf("Outside function: %d %d\n", seqLen($1), seqLen($2->value.n));
            $$ = makeNode(OP, value, $1, $2);
            IdentifierAssignment('v', $1, $2->value.n);
        } 
        else {
            $$ = NULL;
            IdentifierAssignment('v', $1, $2);
            // printf("Done with assign\n");
        }
    }
;

VariableIdList:
    Type VariableIdListType
    {	
    $$ = $2;
    strcpy(tempArray, $1->value.name);
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
    | %empty %prec EMPTY
    {
        $$ = NULL; 
    }
;

IdentifierList:
    IDENTIFIER
    {	
        strcpy(value.name, $1); 
        $$ = makeNode(SEQ, value, makeNode(ID, value, NULL, NULL), NULL); 
        pushToStack(&iStack, value.name);
    }
    | IDENTIFIER ',' IdentifierList
    {
	
	    strcpy(value.name, $1); 
		$$ = makeNode(SEQ, value, makeNode(ID, value, NULL, NULL), $3);
		pushToStack(&iStack, value.name);

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
    {	
        value.name[0] = 0; 
        strcat(value.name, $1); 
        strcat(value.name, "."); 
        strcat(value.name, $3); 
        $$ = makeNode(ID, value, NULL, NULL);
    }
;

/* Expression */

ExpressionList:
    Expression
    {	
        $$ = makeNode(SEQ, value, $1, NULL);  
        switch ($1->type) {
            case INT:
                sprintf(resString, "%d", $1->value.i);
                pushToStack(&tStack, "int");
                break;
            case FLOAT:
                sprintf(resString, "%f", $1->value.f);
                pushToStack(&tStack, "float");
                break;
            case RUNE:
                sprintf(resString, "%s", $1->value.str);
                pushToStack(&tStack, "rune");
                break;
            case STRING:
                sprintf(resString, "%s", $1->value.str);
                pushToStack(&tStack, "string");
                break;
            case BOOL:
                sprintf(resString, "%dB", $1->value.b);
                pushToStack(&tStack, "bool");
                break;
            }       
        pushToStack(&vStack, resString);
        }
    | ExpressionList ',' Expression
    { 
        $$ = makeNode(SEQ, value, $3, $1);

        switch ($3->type) {
            case INT:
                sprintf(resString, "%d", $1->value.i);
                pushToStack(&tStack, "int");
                break;
            case FLOAT:
                sprintf(resString, "%f", $1->value.f);
                pushToStack(&tStack, "float");
                break;
            case RUNE:
                sprintf(resString, "%s", $1->value.str);
                pushToStack(&tStack, "rune");
                break;
            case STRING:
                sprintf(resString, "%s", $1->value.str);
                pushToStack(&tStack, "string");
                break;
            case BOOL:
                sprintf(resString, "%dB", $1->value.b);
                pushToStack(&tStack, "bool");
                break;
            }        
        pushToStack(&vStack, resString);
    }
;

Expression:
    Expression LOGICAL_OR Expression
    {
        strcpy(value.op, $2);
        $$ = makeNode(OP, value, $1, $3);
        createTempVariable();
        fprintf(intermediateCodeFile, "%s = %s %s %s\n", tempVariableStore, $1->loc, value.op, $3->loc);
        strcpy($$->loc, tempVariableStore);
    }
    | Expression LOGICAL_AND Expression
    {
        strcpy(value.op, $2);
        $$ = makeNode(OP, value, $1, $3);
        createTempVariable();
        fprintf(intermediateCodeFile, "%s = %s %s %s\n", tempVariableStore, $1->loc, value.op, $3->loc);
        strcpy($$->loc, tempVariableStore);
    }
    | Expression RelationalOperation Expression %prec REL_EQUAL
    {
        strcpy(value.op, $2->value.op);
        $$ = makeNode(OP, value, $1, $3);
        createTempVariable();
        fprintf(intermediateCodeFile, "%s = %s %s %s\n", tempVariableStore, $1->loc, value.op, $3->loc);
        strcpy($$->loc, tempVariableStore);
        // printf("While setting: %s\n", $$->loc);
    }
    | Expression AddOperation Expression %prec '+'
    {
		 strcpy(value.op, $2->value.op);
		 $$ = makeNode(OP, value, $1, $3);
		 createTempVariable();
		 fprintf(intermediateCodeFile, "%s = %s %s %s\n", tempVariableStore, $1->loc, value.op, $3->loc);
		 strcpy($$->loc, tempVariableStore);
    }
    | Expression MultipyOperation Expression %prec '-'
    {
		 strcpy(value.op, $2->value.op);
		 $$ = makeNode(OP, value, $1, $3);
		 createTempVariable();
		 fprintf(intermediateCodeFile, "%s = %s %s %s\n", tempVariableStore, $1->loc, value.op, $3->loc);
		 strcpy($$->loc, tempVariableStore);
    }
    | UnaryExpression %prec P_UNARY
    {$$ = $1;}
;

RelationalOperation:
    REL_EQUAL
    {
        strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);
    }
    | REL_NEQUAL
    {
        strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);
    }
    | REL_LT
    {
        strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);
    }
    | REL_LEQ
    {
        strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);
    }
    | REL_GT
    {
        strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);
    }
    | REL_GEQ
    {
        strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);
    }
;

AddOperation:
    '+'
    {
        value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);
    }
    | '-'
    {
        value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);
    }
    | '|'
    {
        value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);
    }
    | '^'
    {
        value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);
    }
;

MultipyOperation:
    '*'
    {
        value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);
    }
    | '/'
    {
        value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);
    }
    | '%'
    {
        value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);
    }
    | LSHIFT
    {
        strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);
    }
    | RSHIFT
    {
        strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);
    }
    | '&'
    {
        value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);
    }
    | AMPXOR
    {
        strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);
    }

;

UnaryOperation:
    '+'
    {
        value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);
    }
    | '-'
    {
        value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);
    }
    | '!'
    {
        value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);
    }
    | '^'
    {
        value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);
    }
    | '*'
    {
        value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);
    }
    | '&'
    {
        value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);
    }
;

AssignOperation:
    ADD_ASSIGN
    {
        strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);
    }
    | SUB_ASSIGN
    {
        strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);
    }
    | OR_ASSIGN
    {
        strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);
    }
    | XOR_ASSIGN
    {
        strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);
    }
    | MUL_ASSIGN
    {
        strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);
    }
    | DIV_ASSIGN
    {
        strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);
    }
    | MOD_ASSIGN
    {
        strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);
    }
    | AND_ASSIGN
    {
        strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);
    }
    | LSHIFT_ASSIGN
    {
        strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);
    }
    | RSHIFT_ASSIGN
    {
        strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);
    }
    | AMPXOR_ASSIGN
    {
        strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);
    }
;

UnaryExpression:
    CHANNEL_ASSIGN UnaryExpression
    {strcpy(value.op, $1); $$ = makeNode(OP, value, $2, NULL);}
    | UnaryOperation UnaryExpression %prec P_UNARY
    {
        strcpy(value.op, $1->value.op);
        $$ = makeNode(OP, value, $2, NULL);
        strcpy($$->loc,getLoc($2));
        createTempVariable();
        fprintf(intermediateCodeFile, "%s = -%s\n", tempVariableStore, $$->loc);
        strcpy($$->loc, tempVariableStore);
    }
    | PrimaryExpression
    {
        $$ = $1; 
        strcpy($$->loc,getLoc($1));
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
    {value.n = NULL; $$ = makeNode(NIL, value, NULL, NULL);}
    | P_BOOL
    {value.b = strcmp($1, "true")==0 ? 1 : 0; $$ = makeNode(BOOL, value, NULL, NULL);}
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
        ++scope_depth; 
        scope_id = getNextScope(scope_depth);
    }
    Statements
    {
        --scope_depth; 
        scope_id = getPreviousScope(scope_depth);
    }
    '}'
;

Statements:
    Statements Statement %prec NORMAL
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
    {
        createTempVariable(); fprintf(intermediateCodeFile, "%s = %s + 1\n", tempVariableStore, $1->loc), fprintf(intermediateCodeFile, "%s = %s\n", $1->loc, tempVariableStore);
    }
    | Expression DEC_ASSIGN
    {
        createTempVariable(); fprintf(intermediateCodeFile, "%s = %s - 1\n", tempVariableStore, $1->loc), fprintf(intermediateCodeFile, "%s = %s\n", $1->loc, tempVariableStore);
    }
;

Assignment:
    IdentifierList '=' ExpressionList
    {
        value.op[0] = '='; 
        value.op[1] = 0; 
        $$ = makeNode(OP, value, $1, $3);
        PresentIdentifierAssignment($1, $3);
    }
    | Expression AssignOperation Expression
    {	
        strcpy(value.op, $2->value.op); 
        $$ = makeNode(OP, value, $1, $3);
    }
;

ShortDeclaration:
    IdentifierList SHORT_DECLARATION ExpressionList
    {
        IdentifierAssignment('v', $1, $3);
    }
;

/* For Statement */

ForStatement: 
    KEYWORD_FOR
    {
        createLabel(); insertToQueue(&forLoopQueue, labelStore); createLabel(); insertToQueue(&forLoopQueue, labelStore); 
        strcpy($<IfNode>$.next, labelStore);
    } 
    ForClauseParent
    {
        strcpy($<IfNode>$.next, labelStore);
    }
    CodeBlock
    {
        fprintf(intermediateCodeFile, "GOTO %s\n", labelStore);
        fprintf(intermediateCodeFile, "%s:\n", $<IfNode>2.next);
    }
;

ForClauseParent:
    ForCondition %prec NORMAL
    | ForClause %prec NORMAL
    | RangeClause %prec NORMAL 
    | empty %prec EMPTY
;

ForCondition:
    Expression
    {
        fprintf(intermediateCodeFile, "IFFALSE %s GOTO %s\n", $1->loc, removeFromQueue(&forLoopQueue));
    }
;

ForClause:
    ForClauseInit 
    {strcpy($<IfNode>$.next, removeFromQueue(&forLoopQueue)); fprintf(intermediateCodeFile, "%s:\n", $<IfNode>$.next); }
    ';' 
    ForClauseCondition 
    {createLabel();fprintf(intermediateCodeFile, "GOTO %s\n", labelStore); insertToQueue(&forLoopQueue, labelStore);}
    ';'
    {createLabel(); fprintf(intermediateCodeFile, "%s:\n", labelStore);}
    ForClauseUpdation
    {
        fprintf(intermediateCodeFile, "GOTO %s\n", $<IfNode>2.next); 
        fprintf(intermediateCodeFile, "%s:\n", removeFromQueue(&forLoopQueue));
    }
;

ForClauseInit:
    InitializeStatement %prec NORMAL
    | empty %prec EMPTY
;

ForClauseCondition:
    ForCondition
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
    KEYWORD_CASE Expression
    {
        createLabel();
        createTempVariable();
        fprintf(intermediateCodeFile, "%s = i != %s\n", tempVariableStore, $2->loc);
        fprintf(intermediateCodeFile, "IFFALSE %s GOTO %s\n", tempVariableStore, labelStore);
        strcpy($<IfNode>$.next, labelStore);
    } 
    ':'
    Statements
    { 
        pushToStack(&switchConditionStack, $2->loc); 
        fprintf(intermediateCodeFile, "%s:\n", $<IfNode>3.next); 
    }
    |
    KEYWORD_DEFAULT 
    ':'
    Statements
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
char codeline[100];
void yyerror(char const* ErrorMessage) 
{
	fprintf(stderr, "Syntax ErrorMessage in line %d: %s\n", yylineno, ErrorMessage);
}

int main()
{
	intermediateCodeFile = fopen("code optimization/icg_igo.txt", "w");
	for(int i=0; i<SYMBOL_TABLE_MAX; i++)
	{
        hashTable[i].hcode = -1;
    }

	sprintf(resString, "%d", base);
	base++;
	pushToStack(&scopeStack, resString);
	yydebug = 1;
	if( yyparse() != 0)
    {
		printf("Build Failed\n\n");
		exit(1);
	}
	printf("\n\nSymbol-Table\n\n");
	displaySymbolTable();
	return 0;
}