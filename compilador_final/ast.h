#ifndef _AST_H_
#define _AST_H_

#include "tabela.h"
#include <stdbool.h>

#define MAX_FILHOS 3

typedef enum {
    NO_DECL_VAR,
    NO_DECL_FUNC,
    NO_PARAM,
    NO_COMPOSTO,
    NO_IF,
    NO_WHILE,
    NO_RETURN,
    NO_ATRIBUICAO,
    NO_OP_BINARIO,
    NO_VAR,
    NO_LITERAL,
    NO_CHAMADA
} TipoNoAST;

typedef enum {
    OP_MAIS,
    OP_MENOS,
    OP_VEZES,
    OP_DIVISAO,
    OP_MENOR,
    OP_MENOR_IGUAL,
    OP_MAIOR,
    OP_MAIOR_IGUAL,
    OP_IGUAL,
    OP_DIFERENTE
} OperadorBinario;

typedef struct NoAST {
    TipoNoAST kind;
    int linha;

    char nome[64];
    TipoDado tipoDecl;
    bool ehArray;
    OperadorBinario op;
    int valor;       /* Valor do literal ou tamanho declarado do vetor */

    TipoDado tipo;   /* Atributo sintetizado na analise semantica */

    struct NoAST *filho[MAX_FILHOS];
    struct NoAST *irmao;
} NoAST;

NoAST* anexarIrmao(NoAST *lista, NoAST *novo);
NoAST* criarNoDeclVar(TipoDado tipo, const char *nome, int tamanhoArray, bool ehArray, int linha);
NoAST* criarNoDeclFunc(TipoDado tipoRetorno, const char *nome, NoAST *params, NoAST *corpo, int linha);
NoAST* criarNoParam(TipoDado tipo, const char *nome, bool ehArray, int linha);
NoAST* criarNoComposto(NoAST *declsLocais, NoAST *comandos, int linha);
NoAST* criarNoIf(NoAST *cond, NoAST *ramoThen, NoAST *ramoElse, int linha);
NoAST* criarNoWhile(NoAST *cond, NoAST *corpo, int linha);
NoAST* criarNoReturn(NoAST *expr, int linha);
NoAST* criarNoAtribuicao(NoAST *destino, NoAST *origem, int linha);
NoAST* criarNoOpBinario(OperadorBinario op, NoAST *esq, NoAST *dir, int linha);
NoAST* criarNoVar(const char *nome, NoAST *indice, int linha);
NoAST* criarNoLiteral(int valor, int linha);
NoAST* criarNoChamada(const char *nomeFunc, NoAST *args, int linha);

const char* nomeOperador(OperadorBinario op);
void imprimirASTDecorada(NoAST *raiz, int nivel);
void liberarAST(NoAST *raiz);

#endif
