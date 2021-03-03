lex lex.l
bison -d yac.y
gcc lex.yy.c yac.tab.c common.c common.h -ll

#export PATH="$(brew --prefix bison)/bin:$PATH"