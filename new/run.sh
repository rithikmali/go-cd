yacc -d yac.y
lex lex.l
gcc lex.yy.c y.tab.c