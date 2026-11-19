#ifndef PARSER_H
#define PARSER_H

#include "scan.h"

#define MAX_FILHOS 10
#define MAX_TOKENS 500
#define MAX_PILHA  200

typedef struct No {
    char nome[100];
    int qtd_filhos;
    struct No *filhos[MAX_FILHOS];
} No;

typedef struct {
    TipoToken tipo;
    char texto[MAXTOKENLEN + 1];
} TokenInfo;

typedef struct {
    char simbolo[20];
    No *no;
} ItemPilha;

typedef struct {
    ItemPilha itens[MAX_PILHA];
    int topo;
} Pilha;

void iniciar_parser(void);
int adicionar_token(TipoToken tipo, const char *texto);
int analisar_ll1(No **raiz_saida);
void imprimir_arvore(No *no, int recuo);
void liberar_arvore(No *no);

#endif