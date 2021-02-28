yacc -d yac2.y
lex lex.l
gcc lex.yy.c y.tab.c -ll