all: lex.yy.c yac.tab.c server.c server.h
	gcc yac.tab.c lex.yy.c server.c -lfl -o compiler

yac.tab.c: yac.y
	bison -d --debug yac.y

lex.yy.c: lex.l
	# flex -d lex.l
	flex lex.l