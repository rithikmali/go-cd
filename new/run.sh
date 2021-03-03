lex lex.l
bison -d yac.y
gcc lex.yy.c yac.tab.c