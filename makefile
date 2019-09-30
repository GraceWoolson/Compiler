decafp: lex.yy.o y.tab.o decafp.o parsetree.o parse.o
	g++ -o decafp lex.yy.o y.tab.o decafp.o parsetree.o parse.o

parse.o: parse.cc
	g++ $(CFLAGS) -c parse.cc

decafp.o: decafp.cc
	g++ $(CFLAGS) -c decafp.cc

parsetree.o: parsetree.cc
	g++ $(CFLAGS) -c parsetree.cc

y.tab.o: y.tab.c
	g++ $(CFLAGS) -c y.tab.c

lex.yy.o: lex.yy.c
	g++ $(CFLAGS) -c lex.yy.c

#y.tab.h: decaf.y
#	yacc -t -d -v decaf.y # -t supports runtime debug info
#	yacc -d -v decaf.y

y.tab.c: decaf.y parsetree.h
	yacc -t -d -v decaf.y # -t supports runtime debug info
#	yacc -d -v decaf.y

lex.yy.c: decaf.lex # y.tab.h
	flex decaf.lex

clean:
	rm -rf *~ lex.yy.* *.o y.tab.* decafp a.out y.output
