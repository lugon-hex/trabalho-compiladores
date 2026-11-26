CC = gcc
YACC = bison
CFLAGS = -Wall -Wextra -g
TARGET = compilador

OBJS = main.o scan.o adapta.o yacc.tab.o erros.o tabela.o ast.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

yacc.tab.c yacc.tab.h: yacc.y
	$(YACC) -d yacc.y

main.o: main.c scan.h ast.h tabela.h erros.h
	$(CC) $(CFLAGS) -c main.c -o main.o

scan.o: scan.c scan.h
	$(CC) $(CFLAGS) -c scan.c -o scan.o

adapta.o: adapta.c scan.h yacc.tab.h erros.h
	$(CC) $(CFLAGS) -c adapta.c -o adapta.o

yacc.tab.o: yacc.tab.c yacc.tab.h ast.h tabela.h
	$(CC) $(CFLAGS) -c yacc.tab.c -o yacc.tab.o

erros.o: erros.c erros.h
	$(CC) $(CFLAGS) -c erros.c -o erros.o

tabela.o: tabela.c tabela.h
	$(CC) $(CFLAGS) -c tabela.c -o tabela.o

ast.o: ast.c ast.h tabela.h
	$(CC) $(CFLAGS) -c ast.c -o ast.o

run: $(TARGET)
	./$(TARGET) teste.cm

clean:
	rm -f $(TARGET) $(OBJS) yacc.tab.c yacc.tab.h saida_mips.txt

.PHONY: all run clean
