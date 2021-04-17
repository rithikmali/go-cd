all: lex.yy.c yac.tab.c common.c common.h
	gcc yac.tab.c lex.yy.c common.c -lfl -o parser

yac.tab.c: yac.y
	bison -d --debug -Wno-other yac.y

lex.yy.c: lex.l
	flex -d lex.l
