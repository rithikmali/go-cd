flex lex.l
bison -dy lex.y
gcc lex.yy.c y.tab.c