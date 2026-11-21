#ifndef _SCAN_H_
#define _SCAN_H_

#define FALSE 0
#define TRUE 1
#define MAXTOKENLEN 40

#include <stdio.h>
#include <string.h>
#include <ctype.h>

extern int lineno;
extern FILE* Fonte;
extern char tokenString[MAXTOKENLEN + 1];

typedef enum
{
    ENDFILE,
    ERROR,

    ELSE,
    IF,
    INT,
    RETURN,
    VOID,
    WHILE,

    IDENTIFICADOR,
    NUMERO,

    ATRIBUICAO,
    IGUAL,
    MENOR,
    MENOR_IGUAL,
    MAIOR,
    MAIOR_IGUAL,
    DIFERENTE,

    MAIS,
    MENOS,
    VEZES,
    DIVISAO,

    PONTO_VIRGULA,
    VIRGULA,
    ABRE_PARENTESE,
    FECHA_PARENTESE,
    ABRE_COLCHETE,
    FECHA_COLCHETE,
    ABRE_CHAVE,
    FECHA_CHAVE

} TokenType;

TokenType getToken(void);

#endif