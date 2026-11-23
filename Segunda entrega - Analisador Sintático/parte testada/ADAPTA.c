#include "SCAN.h"
#include "yacc.tab.h"
#include <stdio.h>

void yyerror(const char *mensagem)
{
    printf("Erro sintatico na linha %d: %s\n", lineno, mensagem);
}

int adaptaToken(void)
{
    TokenType token = getToken();

    switch (token)
    {
        case INT:
            return T_INT;

        case VOID:
            return T_VOID;

        case IF:
            return T_IF;

        case ELSE:
            return T_ELSE;

        case WHILE:
            return T_WHILE;

        case RETURN:
            return T_RETURN;

        case IDENTIFICADOR:
            return T_IDENTIFICADOR;

        case NUMERO:
            return T_NUMERO;

        case ATRIBUICAO:
            return T_ATRIBUICAO;

        case IGUAL:
            return T_IGUAL;

        case MENOR:
            return T_MENOR;

        case MENOR_IGUAL:
            return T_MENOR_IGUAL;

        case MAIOR:
            return T_MAIOR;

        case MAIOR_IGUAL:
            return T_MAIOR_IGUAL;

        case DIFERENTE:
            return T_DIFERENTE;

        case MAIS:
            return T_MAIS;

        case MENOS:
            return T_MENOS;

        case VEZES:
            return T_VEZES;

        case DIVISAO:
            return T_DIVISAO;

        case PONTO_VIRGULA:
            return T_PONTO_VIRGULA;

        case VIRGULA:
            return T_VIRGULA;

        case ABRE_PARENTESE:
            return T_ABRE_PARENTESE;

        case FECHA_PARENTESE:
            return T_FECHA_PARENTESE;

        case ABRE_COLCHETE:
            return T_ABRE_COLCHETE;

        case FECHA_COLCHETE:
            return T_FECHA_COLCHETE;

        case ABRE_CHAVE:
            return T_ABRE_CHAVE;

        case FECHA_CHAVE:
            return T_FECHA_CHAVE;

        case ENDFILE:
            return 0;

        case ERROR:
            return T_ERROR;

        default:
            return T_ERROR;
    }
}

int yylex(void)
{
    return adaptaToken();
}