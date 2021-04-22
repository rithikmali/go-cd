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

int base = 1000;
int scope_depth = 0;
int scope_id = 0;

typedef struct symbol_table {
  char name[31];
  char dtype[10];
  char type;
  char value[20];
  int scope_depth;
  int scope_id;
  int hcode;
} ST;

ST hashTable[10009];

struct Stack {
  char s[25][25];
  int top;
};

typedef struct queue {
  char s[25][200];
  int front;
	int back;
} queue;

typedef struct Stack stack;

stack stack_i = {.top = -1};
stack stack_v = {.top = -1};
stack stack_t = {.top = -1};
stack stack_scope = {.top = -1};
stack if_cond = {.top = -1};
queue for_loc = {.front = -1, .back = -1};

void add(queue *p_st, char *item) {
	if (p_st->back==199) {
		printf("Cannot insert into full queue\n");
		exit(1);
	}
	strcpy(p_st->s[++p_st->back], item);
}

char *rem(queue *p_st) {
	if (p_st->front==p_st->back) {
		printf("Cannot remove from empty queue\n");
		exit(1);
	}
	char *item;
	item = strdup(p_st->s[++p_st->front]);
	return (item);
}

char result[20];
char Tflag[20] = "";

int tid = 0;
int lid = 0;
char temp[10];
char label[10];
FILE* icfile;

void newtemp() {
	sprintf(temp, "_t%d", tid++);
}

void newlabel() {
	sprintf(label, "L%d", lid++);
}

int stfull(stack st, int size) {
  if (st.top >= size - 1)
    return 1;
  else
    return 0;
}

void push(stack *p_st, char *item) {
  p_st->top++;
  strcpy(p_st->s[p_st->top], item);
}

int stempty(stack st) {
  if (st.top == -1)
    return 1;
  else
    return 0;
}

char *pop(stack *p_st) {
  char *item;
  item = p_st->s[p_st->top];
  p_st->top--;
  return (item);
}

int hash1(char *token) {
  int hash = 0;
  for (int i = 0; token[i] != '\0'; i++) {
    hash = (256 * hash + token[i]) % 1000000009;
  }
  hash = hash % TABLE_SIZE;
  return hash;
}

int check(char *token) {
  int index1 = hash1(token);
  int i = 0;
  while (i < TABLE_SIZE &&
         !(strcmp(hashTable[(index1 + i) % TABLE_SIZE].name, token) == 0 &&
				 hashTable[(index1 + i) % TABLE_SIZE].scope_depth == scope_depth &&
				 hashTable[(index1 + i) % TABLE_SIZE].scope_id == scope_id))
    i++;

  if (i == TABLE_SIZE)
    return -1;
  else
    return index1 + i;
}

int check_parent_scopes(char *token) {
  int index1 = hash1(token);
  int i = 0;
  while (i < TABLE_SIZE &&
         !(strcmp(hashTable[(index1 + i) % TABLE_SIZE].name, token) == 0 &&
				 (hashTable[(index1 + i) % TABLE_SIZE].scope_depth == scope_depth &&
				 hashTable[(index1 + i) % TABLE_SIZE].scope_id == scope_id) ||
				 hashTable[(index1 + i) % TABLE_SIZE].scope_depth < scope_depth))
    i++;

  if (i == TABLE_SIZE)
    return -1;
  else
    return index1 + i;
}

void insert(char type, char *token, char *dtype, char *value, int scope_depth, int scope_id) {
  if (check(token) != -1) {
    yyerror("variable is redeclared");
		exit(1);
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
				hashTable[newIndex].scope_depth = scope_depth;
				hashTable[newIndex].scope_id = scope_id;
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
		hashTable[index].scope_depth = scope_depth;
		hashTable[index].scope_id = scope_id;
    hashTable[index].type = type;
    hashTable[index].hcode = 1;
  }
}
char *search(char *token) {
  int index1 = hash1(token);
  int i = 0;
  while (i < TABLE_SIZE &&
         strcmp(hashTable[(index1 + i) % TABLE_SIZE].name, token) != 0)
    i++;
  if (i == TABLE_SIZE) {
		return NULL;
  } else
    return hashTable[index1 + i].dtype;
}

int max_id_at_depth[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int next_id(int scope_depth) {
	int scope_id = -1;
	if (scope_depth == 1) {
		scope_id = 1;
	} else {
		scope_id = ++max_id_at_depth[scope_depth];
	}
	return scope_id;
}

int restore_id(int scope_depth) {
	int scope_id = -1;
	if (scope_depth == 1) {
		scope_id = 1;
	} else {
		scope_id = max_id_at_depth[scope_depth];
	}
	return scope_id;
}

void update(char *token, char *dtype, char *value) {
  int index = check_parent_scopes(token);
  if (index == -1) {
		char error[100];
		printf("In here\n");
		sprintf(error, "%s is not defined", token);
    yyerror(error);
    exit(1);
  }

  if (hashTable[index].type == 'c') {
		char error[100];
		sprintf(error, "cannot assign to %s (declared const)", token);
		yyerror(error);
    exit(1);
  } else {
    if (strcmp(hashTable[index].value, "NULL") != 0)
      strcpy(hashTable[index].value, value);
    if (strcmp(hashTable[index].dtype, "NULL") != 0)
      strcpy(hashTable[index].dtype, dtype);
  }
}

void disp_symtbl() {
  int base = 1000;
  printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n", "Name", "Data Type", "Value",
         "Scope Depth", "Scope ID");

  for (int i = 0; i < TABLE_SIZE; i++) {
    if (hashTable[i].hcode != -1)
      printf("%s\t\t%s\t\t\t%s\t\t%d\t\t%d\n", hashTable[i].name,
             hashTable[i].dtype, hashTable[i].value,
             hashTable[i].scope_depth, hashTable[i].scope_id);
  }
}

void doAssign(char decltype, Node *lhs, Node *rhs) {
	if (lhs==NULL && rhs==NULL) {
		Tflag[0] = 0;
		return;
	}
	if (seqLen(lhs) != seqLen(rhs) && seqLen(rhs) != 0) {
		yyerror("Imbalanced assignment");
		exit(1);
	} else {
		if (seqLen(rhs) == 0){
			insert(decltype, pop(&stack_i), Tflag, "NULL", scope_depth, scope_id);
			doAssign(decltype, lhs->rop, rhs);
		} else {
			if (Tflag[0] != 0) {
				if (strcmp(pop(&stack_t),Tflag) != 0) {
					yyerror("Mismatch between declared type and assigned value");
					exit(1);
				}
				insert(decltype, pop(&stack_i), Tflag, pop(&stack_v), scope_depth, scope_id);
			} else {
				insert(decltype, pop(&stack_i), pop(&stack_t), pop(&stack_v), scope_depth, scope_id);
			}
		}
		fprintf(icfile, "%s = %s\n", lhs->lop->value.name, rhs->lop->loc);
		doAssign(decltype, lhs->rop, rhs->rop);
	} 
}

void doAssignExisting(Node *lhs, Node *rhs) {	
	if (lhs==NULL && rhs==NULL) {
		return;
	}
	if (seqLen(lhs) != seqLen(rhs)) {
		yyerror("Imbalanced assignment");
		exit(1);
	} else {
		char* res = search(lhs->lop->value.name);
		if (res==NULL) {
			char error[100];
			sprintf(error, "%s is not defined", lhs->lop->value.name);
			yyerror(error);
			exit(1);
		}
		strcpy(result, res);

		Node *cur = rhs->lop;
		while(cur->type == OP) {
			cur = cur->lop;
		}
		int type = cur->type;
		union NodeVal value = cur->value;
		if(cur->type == ID) {
			char *decltype = search(cur->value.name);
			if(decltype==NULL) {
				char error[100];
				sprintf(error, "%s is not defined", lhs->lop->value.name);
				yyerror(error);
				exit(1);
			}
		}
		printf("%s %d\n", result, type);
		if(strcmp(result, "int") == 0 && type == INT) {
			sprintf(result, "%d", value.i);
			update(lhs->lop->value.name, "int", result);
		} else if(strcmp(result, "float") == 0 && type == FLOAT) {
			sprintf(result, "%f", value.f);
			update(lhs->lop->value.name, "float", result);
		} else if(strcmp(result, "string") == 0 && type == STRING) {
			update(lhs->lop->value.name, "string", value.str);
		} else if(strcmp(result, "rune") == 0 && type == RUNE) {
			update(lhs->lop->value.name, "rune", value.str);
		} else if(strcmp(result, "bool") == 0 && type == BOOL) {
			sprintf(result, "%dB", value.b);
			update(lhs->lop->value.name, "bool", result);
		} else {
			yyerror("Error: type mismatched assignment");
			exit(1);
		}
		fprintf(icfile, "%s = %s\n", lhs->lop->value.name, rhs->lop->loc);
	}
	doAssignExisting(lhs->rop, rhs->rop);
}

%}
%define api.value.type union
%define parse.error verbose
%start s

%type <struct node *> IdentifierList ExpressionList Expression Literal BasicLiteral Operand OperandName RelationalOperation AddOperation MultipyOperation UnaryExpression PrimaryExpression AssignOperation UnaryOperation QualifiedID Assignment VariableSpecification VariableIdList VariableIdListType Type TypeName ConstIdList ConstSpecification

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
        if(yychar != YYEOF) 
        {
            printf("Invalid - reached start symbol before EOF\n"); YYERROR;
        }
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
                    insert('c', pop(&stack_i), pop(&stack_t), "NULL", scope_depth, scope_id);
                }
            }
            else 
            {
                while(!stempty(stack_i)) 
                {

                    insert('c', pop(&stack_i), pop(&stack_t), pop(&stack_v), scope_depth, scope_id);
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
        doAssign('c', $1, $2->value.n);
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
        strcpy(Tflag, $1->value.name);
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
        if(stack_v.top != stack_i.top && stack_v.top != -1)
        {
            yyerror("Imbalanced assignment");
            YYERROR;
        }
        else 
        {
            if (stack_v.top == -1){
                while(!stempty(stack_i))
                {
                    insert('v', pop(&stack_i), Tflag, "NULL", scope_depth, scope_id);
                }
            }
            else 
            {
                while(!stempty(stack_i))
                {
                    insert('v', pop(&stack_i), pop(&stack_t), pop(&stack_v), scope_depth, scope_id);
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
            printf("Outside function: %d %d\n", seqLen($1), seqLen($2->value.n));
            $$ = makeNode(OP, value, $1, $2);
            doAssign('v', $1, $2->value.n);
        } 
        else {
            $$ = NULL;
            printf("Beginning with assign\n");
            doAssign('v', $1, $2);
            printf("Done with assign\n");
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
                sprintf(result, "%d", $1->value.i);
                push(&stack_t, "int");
                break;
            case FLOAT:
                sprintf(result, "%f", $1->value.f);
                push(&stack_t, "float");
                break;
            case RUNE:
                sprintf(result, "%s", $1->value.str);
                push(&stack_t, "rune");
                break;
            case STRING:
                sprintf(result, "%s", $1->value.str);
                push(&stack_t, "string");
                break;
            case BOOL:
                sprintf(result, "%dB", $1->value.b);
                push(&stack_t, "bool");
                break;
            }       
        push(&stack_v, result);
        }
    | ExpressionList ',' Expression
    { 
        $$ = makeNode(SEQ, value, $3, $1);

        switch ($3->type) {
            case INT:
                sprintf(result, "%d", $1->value.i);
                push(&stack_t, "int");
                break;
            case FLOAT:
                sprintf(result, "%f", $1->value.f);
                push(&stack_t, "float");
                break;
            case RUNE:
                sprintf(result, "%s", $1->value.str);
                push(&stack_t, "rune");
                break;
            case STRING:
                sprintf(result, "%s", $1->value.str);
                push(&stack_t, "string");
                break;
            case BOOL:
                sprintf(result, "%dB", $1->value.b);
                push(&stack_t, "bool");
                break;
            }        
        push(&stack_v, result);
    }
;

Expression:
    Expression LOGICAL_OR Expression
    {
        strcpy(value.op, $2);
        $$ = makeNode(OP, value, $1, $3);
        newtemp();
        fprintf(icfile, "%s = %s %s %s\n", temp, $1->loc, value.op, $3->loc);
        strcpy($$->loc, temp);
    }
    | Expression LOGICAL_AND Expression
    {
        strcpy(value.op, $2);
        $$ = makeNode(OP, value, $1, $3);
        newtemp();
        fprintf(icfile, "%s = %s %s %s\n", temp, $1->loc, value.op, $3->loc);
        strcpy($$->loc, temp);
    }
    | Expression RelationalOperation Expression %prec REL_EQUAL
    {
        strcpy(value.op, $2->value.op);
        $$ = makeNode(OP, value, $1, $3);
        newtemp();
        fprintf(icfile, "%s = %s %s %s\n", temp, $1->loc, value.op, $3->loc);
        strcpy($$->loc, temp);
        printf("While setting: %s\n", $$->loc);
    }
    | Expression AddOperation Expression %prec '+'
    {
		 strcpy(value.op, $2->value.op);
		 $$ = makeNode(OP, value, $1, $3);
		 newtemp();
		 fprintf(icfile, "%s = %s %s %s\n", temp, $1->loc, value.op, $3->loc);
		 strcpy($$->loc, temp);
    }
    | Expression MultipyOperation Expression %prec '-'
    {
		 strcpy(value.op, $2->value.op);
		 $$ = makeNode(OP, value, $1, $3);
		 newtemp();
		 fprintf(icfile, "%s = %s %s %s\n", temp, $1->loc, value.op, $3->loc);
		 strcpy($$->loc, temp);
    }
    | UnaryExpression %prec P_UNARY
    {$$ = $1;}
;

RelationalOperation:
    REL_EQUAL
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);}
    | REL_NEQUAL
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);}
    | REL_LT
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);}
    | REL_LEQ
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);}
    | REL_GT
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);}
    | REL_GEQ
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);}
;

AddOperation:
    '+'
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);}
    | '-'
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);}
    | '|'
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);}
    | '^'
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);}
;

MultipyOperation:
    '*'
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);}
    | '/'
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);}
    | '%'
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);}
    | LSHIFT
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);}
    | RSHIFT
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);}
    | '&'
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);}
    | AMPXOR
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);}

;

UnaryOperation:
    '+'
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);}
    | '-'
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);}
    | '!'
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);}
    | '^'
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);}
    | '*'
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);}
    | '&'
    {value.op[0] = *((int*)&yylval); value.op[1] = 0; $$ = makeNode(OP, value, NULL, NULL);}
;

AssignOperation:
    ADD_ASSIGN
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);}
    | SUB_ASSIGN
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);}
    | OR_ASSIGN
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);}
    | XOR_ASSIGN
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);}
    | MUL_ASSIGN
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);}
    | DIV_ASSIGN
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);}
    | MOD_ASSIGN
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);}
    | AND_ASSIGN
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);}
    | LSHIFT_ASSIGN
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);}
    | RSHIFT_ASSIGN
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);}
    | AMPXOR_ASSIGN
    {strcpy(value.op, $1); $$ = makeNode(OP, value, NULL, NULL);}
;

UnaryExpression:
    CHANNEL_ASSIGN UnaryExpression
    {strcpy(value.op, $1); $$ = makeNode(OP, value, $2, NULL);}
    | UnaryOperation UnaryExpression %prec P_UNARY
    {
        strcpy(value.op, $1->value.op);
        $$ = makeNode(OP, value, $2, NULL);
        strcpy($$->loc,getLoc($2));
        newtemp();
        fprintf(icfile, "%s = -%s\n", temp, $$->loc);
        strcpy($$->loc, temp);
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
        scope_id = next_id(scope_depth);
    }
    Statements
    {
        --scope_depth; 
        scope_id = restore_id(scope_depth);
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
        newtemp(); fprintf(icfile, "%s = %s + 1\n", temp, $1->loc), fprintf(icfile, "%s = %s\n", $1->loc, temp);
    }
    | Expression DEC_ASSIGN
    {
        newtemp(); fprintf(icfile, "%s = %s - 1\n", temp, $1->loc), fprintf(icfile, "%s = %s\n", $1->loc, temp);
    }
;

Assignment:
    IdentifierList '=' ExpressionList
    {
        value.op[0] = '='; 
        value.op[1] = 0; 
        $$ = makeNode(OP, value, $1, $3);
        doAssignExisting($1, $3);
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
        doAssign('v', $1, $3);
    }
;

/* For Statement */

ForStatement: 
    KEYWORD_FOR
    {
        newlabel(); add(&for_loc, label); newlabel(); add(&for_loc, label); 
        strcpy($<IfNode>$.next, label);
    } 
    ForClauseParent
    {
        strcpy($<IfNode>$.next, label);
    }
    CodeBlock
    {
        fprintf(icfile, "GOTO %s\n", label);
        fprintf(icfile, "%s:\n", $<IfNode>2.next);
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
        fprintf(icfile, "IFFALSE %s GOTO %s\n", $1->loc, rem(&for_loc));
    }
;

ForClause:
    ForClauseInit 
    {strcpy($<IfNode>$.next, rem(&for_loc)); fprintf(icfile, "%s:\n", $<IfNode>$.next); }
    ';' 
    ForClauseCondition 
    {newlabel();fprintf(icfile, "GOTO %s\n", label); add(&for_loc, label);}
    ';'
    {newlabel(); fprintf(icfile, "%s:\n", label);}
    ForClauseUpdation
    {
        fprintf(icfile, "GOTO %s\n", $<IfNode>2.next); 
        fprintf(icfile, "%s:\n", rem(&for_loc));
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
        newlabel();
        newtemp();
        fprintf(icfile, "%s = i == %s\n", temp, $2->loc);
        fprintf(icfile, "IFFALSE %s GOTO %s\n", temp, label);
        strcpy($<IfNode>$.next, label);
    } 
    ':'
    Statements
    { 
        push(&if_cond, $2->loc); 
        fprintf(icfile, "%s:\n", $<IfNode>3.next); 
    }
    |
    KEYWORD_DEFAULT 
    ':'
    Statements
;

// ExprSwitchCase:
     
    
//     | KEYWORD_DEFAULT
// ;

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
void yyerror(char const* error) {
	fprintf(stderr, "Syntax error in line %d: %s\n", yylineno, error);
}

int main()
{
	icfile = fopen("code optimization/intermediate.txt", "w");
	for(int i=0; i<TABLE_SIZE; i++)
		hashTable[i].hcode = -1;

	sprintf(result, "%d", base);
	base++;
	push(&stack_scope, result);

	yydebug = 1;
	if ( yyparse() != 0){
		printf("Build Failed\n\n");
		exit(1);
	}

	printf("\n\n\n");
	printf("---------------------------------Symbol Table---------------------------------\n\n");
	disp_symtbl();

	return 0;
}