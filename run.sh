flex lex.l
bison -dy yac.y
gcc lex.yy.c y.tab.c