#include "scan.h"
#include "yacc.tab.h"
#include "erros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* copiarLexema(const char *s) {
    size_t len = strlen(s) + 1;
    char *copia = (char*) malloc(len);
    if (copia != NULL) {
        memcpy(copia, s, len);
    }
    return copia;
}

void yyerror(const char *mensagem) {
    reportarErro(FASE_SINTATICA, lineno, mensagem, tokenString);
}

int adaptaToken(void) {
    TokenType token = getToken();

    switch (token) {
        case INT:             return T_INT;
        case VOID:            return T_VOID;
        case ELSE:            return T_ELSE;
        case IF:         yylval.num = lineno; return T_IF;
        case WHILE:      yylval.num = lineno; return T_WHILE;
        case RETURN:     yylval.num = lineno; return T_RETURN;
        case ATRIBUICAO: yylval.num = lineno; return T_ATRIBUICAO;
        
        case IDENTIFICADOR:
            yylval.id.texto = copiarLexema(tokenString);
            yylval.id.linha = lineno;
            return T_IDENTIFICADOR;

        case NUMERO:
            yylval.num = atoi(tokenString);
            return T_NUMERO;

        case IGUAL:           return T_IGUAL;
        case MENOR:           return T_MENOR;
        case MENOR_IGUAL:     return T_MENOR_IGUAL;
        case MAIOR:           return T_MAIOR;
        case MAIOR_IGUAL:     return T_MAIOR_IGUAL;
        case DIFERENTE:       return T_DIFERENTE;
        case MAIS:            return T_MAIS;
        case MENOS:           return T_MENOS;
        case VEZES:           return T_VEZES;
        case DIVISAO:         return T_DIVISAO;
        case PONTO_VIRGULA:   return T_PONTO_VIRGULA;
        case VIRGULA:         return T_VIRGULA;
        case ABRE_PARENTESE:  return T_ABRE_PARENTESE;
        case FECHA_PARENTESE: return T_FECHA_PARENTESE;
        case ABRE_COLCHETE:   return T_ABRE_COLCHETE;
        case FECHA_COLCHETE:  return T_FECHA_COLCHETE;
        case ABRE_CHAVE:      return T_ABRE_CHAVE;
        case FECHA_CHAVE:     return T_FECHA_CHAVE;
        case ENDFILE:         return 0;

        case ERROR:
        default:
            reportarErro(FASE_LEXICA, lineno, "Token ou caractere invalido", tokenString);
            return T_ERROR;
    }
}

int yylex(void) {
    return adaptaToken();
}
