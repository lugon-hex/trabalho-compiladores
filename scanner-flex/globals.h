#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#define MAXTOKENLEN 40

typedef enum {
    ENDFILE, ERROR,

    IF, ELSE, INT, RETURN, VOID, WHILE,

    ID, NUM,
    
    PLUS, MINUS, TIMES, OVER, ASSIGN, EQ, NEQ, LT, LE, GT, GE,
    SEMI, COMMA, LPAREN, RPAREN, LBRACKET, RBRACKET, LBRACE, RBRACE
} TokenType;

extern int lineno;
extern char tokenString[MAXTOKENLEN + 1];
extern int TraceScan;

void printToken(TokenType token, const char* tokenString);
TokenType getToken(void);

#endif
