# Makefile

OBJS	= bison.o lex.o cg.o main.o

CC	= g++
CFLAGS = -g -Wall -ansi -pedantic

mono:	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o mono -lfl

lex.o:	lex.c
		$(CC) $(CFLAGS) -c lex.c -o lex.o

lex.c:	LexicalAnalyzer.flex 
		flex LexicalAnalyzer.flex
		cp lex.yy.c lex.c

bison.o:bison.c
		$(CC) $(CFLAGS) -c bison.c -o bison.o

bison.c:Parser.y
		bison -d -v Parser.y
		cp Parser.tab.c bison.c
		cmp -s Parser.tab.h tok.h || cp Parser.tab.h tok.h

main.o:	main.cpp
		$(CC) $(CFLAGS) -c main.cpp -o main.o

lex.o main.o: tok.h

cg.o:	CG.cpp
		$(CC) $(CFLAGS) -c CG.cpp -o cg.o


install:mono
		cp mono $(exec_prefix)/bin/

clean:
	rm -f *.o *~ lex.c lex.yy.c bison.c tok.h Parser.tab.c Parser.tab.h Parser.output mono 
