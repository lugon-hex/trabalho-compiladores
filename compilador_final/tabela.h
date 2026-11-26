#ifndef _TABELA_H_
#define _TABELA_H_

#include <stdbool.h>

#define MAX_SIMBOLOS 256
#define MAX_ESCOPOS  64
#define MAX_PARAMS   16

typedef enum {
    TipoInt,
    TipoBool,
    TipoVoid,
    TipoArray,
    TipoFuncao,
    TipoErro
} TipoDado;

typedef enum {
    CAT_VARIAVEL,
    CAT_PARAMETRO,
    CAT_FUNCAO
} CategoriaSimbolo;

typedef struct {
    char nome[64];
    TipoDado tipo;
    int tamanhoArray;
    TipoDado tipoRetorno;
    int qtdParams;
    TipoDado tiposParams[MAX_PARAMS];
    CategoriaSimbolo categoria;
    int linhaDeclaracao;
    int nivelEscopo;
    char nomeEscopo[64];
} Simbolo;

void inicializarTabelaSimbolos(void);
void entrarEscopo(const char *nomeEscopo);
void sairEscopo(void);

bool inserirSimbolo(const char *nome, TipoDado tipo, CategoriaSimbolo categoria, int tamanhoArray, int linha);
Simbolo* buscarSimbolo(const char *nome);
Simbolo* buscarSimboloEscopoAtual(const char *nome);
void registrarParametroFuncao(Simbolo *funcSimb, TipoDado tipoParam);
const char* nomeTipo(TipoDado tipo);
void imprimirTabelaSimbolos(void);

#endif
