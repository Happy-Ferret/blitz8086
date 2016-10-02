SRCFILES := src/lex.yy.c src/parser.tab.c
CFLAGS := -O2 ## -g

all: src/parser.tab.c src/lex.yy.c bin/blitz8086

src/parser.tab.c: src/parser.y
	cd src && bison -d parser.y

src/lex.yy.c: src/lexer.l
	cd src && flex lexer.l

bin/blitz8086: $(SRCFILES) src/embed/*.c
	mkdir -p bin/
	$(CC) $(SRCFILES) -o $@ $(CFLAGS)

clean:
	rm -f bin/blitz8086

regenerate:
	rm -f src/parser.tab.* src/lex.yy.c

.PHONY: all clean regenerate
