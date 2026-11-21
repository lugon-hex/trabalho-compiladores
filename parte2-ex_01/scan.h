#ifndef SCAN_H
#define SCAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKENLEN 40

typedef enum {
    ENDFILE, ERROR, ELSE, IF, INT, RETURN, VOID, WHILE,
    IDENTIFICADOR, NUMERO, ATRIBUICAO, IGUAL, MENOR, MENOR_IGUAL,
    MAIOR, MAIOR_IGUAL, DIFERENTE, MAIS, MENOS, VEZES, DIVISAO,
    POTENCIA, PONTO_VIRGULA, VIRGULA, ABRE_PARENTESE, FECHA_PARENTESE,
    ABRE_COLCHETE, FECHA_COLCHETE, ABRE_CHAVE, FECHA_CHAVE
} TipoToken;

extern const char *nomes_tokens[];

void iniciar_scanner(FILE *arquivo);
TipoToken proximo_token(void);
const char* obter_lexema_atual(void);
int obter_linha_atual(void);

#endif