#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static NoAST* alocarNo(TipoNoAST kind, int linha) {
    NoAST *no = (NoAST*) calloc(1, sizeof(NoAST));
    if (!no) {
        fprintf(stderr, "Erro fatal: sem memoria para AST.\n");
        exit(1);
    }
    no->kind = kind;
    no->linha = linha;
    no->tipo = TipoVoid;
    return no;
}

NoAST* anexarIrmao(NoAST *lista, NoAST *novo) {
    if (lista == NULL) return novo;
    NoAST *atual = lista;
    while (atual->irmao != NULL) atual = atual->irmao;
    atual->irmao = novo;
    return lista;
}

NoAST* criarNoDeclVar(TipoDado tipo, const char *nome, int tamanhoArray, bool ehArray, int linha) {
    NoAST *no = alocarNo(NO_DECL_VAR, linha);
    no->tipoDecl = tipo;
    no->ehArray = ehArray;
    no->valor = tamanhoArray;
    strncpy(no->nome, nome, 63);
    return no;
}

NoAST* criarNoDeclFunc(TipoDado tipoRetorno, const char *nome, NoAST *params, NoAST *corpo, int linha) {
    NoAST *no = alocarNo(NO_DECL_FUNC, linha);
    no->tipoDecl = tipoRetorno;
    strncpy(no->nome, nome, 63);
    no->filho[0] = params;
    no->filho[1] = corpo;
    return no;
}

NoAST* criarNoParam(TipoDado tipo, const char *nome, bool ehArray, int linha) {
    NoAST *no = alocarNo(NO_PARAM, linha);
    no->tipoDecl = tipo;
    no->ehArray = ehArray;
    strncpy(no->nome, nome, 63);
    return no;
}

NoAST* criarNoComposto(NoAST *declsLocais, NoAST *comandos, int linha) {
    NoAST *no = alocarNo(NO_COMPOSTO, linha);
    no->filho[0] = declsLocais;
    no->filho[1] = comandos;
    return no;
}

NoAST* criarNoIf(NoAST *cond, NoAST *ramoThen, NoAST *ramoElse, int linha) {
    NoAST *no = alocarNo(NO_IF, linha);
    no->filho[0] = cond;
    no->filho[1] = ramoThen;
    no->filho[2] = ramoElse;
    return no;
}

NoAST* criarNoWhile(NoAST *cond, NoAST *corpo, int linha) {
    NoAST *no = alocarNo(NO_WHILE, linha);
    no->filho[0] = cond;
    no->filho[1] = corpo;
    return no;
}

NoAST* criarNoReturn(NoAST *expr, int linha) {
    NoAST *no = alocarNo(NO_RETURN, linha);
    no->filho[0] = expr;
    return no;
}

NoAST* criarNoAtribuicao(NoAST *destino, NoAST *origem, int linha) {
    NoAST *no = alocarNo(NO_ATRIBUICAO, linha);
    no->filho[0] = destino;
    no->filho[1] = origem;
    return no;
}

NoAST* criarNoOpBinario(OperadorBinario op, NoAST *esq, NoAST *dir, int linha) {
    NoAST *no = alocarNo(NO_OP_BINARIO, linha);
    no->op = op;
    no->filho[0] = esq;
    no->filho[1] = dir;
    return no;
}

NoAST* criarNoVar(const char *nome, NoAST *indice, int linha) {
    NoAST *no = alocarNo(NO_VAR, linha);
    strncpy(no->nome, nome, 63);
    no->ehArray = (indice != NULL);
    no->filho[0] = indice;
    return no;
}

NoAST* criarNoLiteral(int valor, int linha) {
    NoAST *no = alocarNo(NO_LITERAL, linha);
    no->valor = valor;
    no->tipo = TipoInt;
    return no;
}

NoAST* criarNoChamada(const char *nomeFunc, NoAST *args, int linha) {
    NoAST *no = alocarNo(NO_CHAMADA, linha);
    strncpy(no->nome, nomeFunc, 63);
    no->filho[0] = args;
    return no;
}

const char* nomeOperador(OperadorBinario op) {
    switch (op) {
        case OP_MAIS:        return "+";
        case OP_MENOS:       return "-";
        case OP_VEZES:       return "*";
        case OP_DIVISAO:     return "/";
        case OP_MENOR:       return "<";
        case OP_MENOR_IGUAL: return "<=";
        case OP_MAIOR:       return ">";
        case OP_MAIOR_IGUAL: return ">=";
        case OP_IGUAL:       return "==";
        case OP_DIFERENTE:   return "!=";
        default:             return "?";
    }
}

void imprimirASTDecorada(NoAST *raiz, int nivel) {
    for (NoAST *atual = raiz; atual != NULL; atual = atual->irmao) {
        for (int i = 0; i < nivel; i++) printf("  ");

        switch (atual->kind) {
            case NO_DECL_VAR:
                printf("DeclVar(%s %s%s) [tipo=%s]\n",
                       nomeTipo(atual->tipoDecl), atual->nome,
                       atual->ehArray ? "[]" : "", nomeTipo(atual->tipo));
                break;
            case NO_DECL_FUNC:
                printf("DeclFunc(%s %s) [tipo=%s]\n",
                       nomeTipo(atual->tipoDecl), atual->nome, nomeTipo(atual->tipo));
                break;
            case NO_PARAM:
                printf("Param(%s %s%s) [tipo=%s]\n",
                       nomeTipo(atual->tipoDecl), atual->nome,
                       atual->ehArray ? "[]" : "", nomeTipo(atual->tipo));
                break;
            case NO_COMPOSTO:   printf("BlocoComposto\n"); break;
            case NO_IF:         printf("If\n"); break;
            case NO_WHILE:      printf("While\n"); break;
            case NO_RETURN:     printf("Return [tipo=%s]\n", nomeTipo(atual->tipo)); break;
            case NO_ATRIBUICAO: printf("Atribuicao (=) [tipo=%s]\n", nomeTipo(atual->tipo)); break;
            case NO_OP_BINARIO: printf("OpBinario(%s) [tipo=%s]\n", nomeOperador(atual->op), nomeTipo(atual->tipo)); break;
            case NO_VAR:        printf("Var(%s%s) [tipo=%s]\n", atual->nome, atual->filho[0] ? "[...]" : "", nomeTipo(atual->tipo)); break;
            case NO_LITERAL:    printf("Literal(%d) [tipo=%s]\n", atual->valor, nomeTipo(atual->tipo)); break;
            case NO_CHAMADA:    printf("ChamadaFunc(%s) [tipo=%s]\n", atual->nome, nomeTipo(atual->tipo)); break;
        }

        for (int i = 0; i < MAX_FILHOS; i++) {
            if (atual->filho[i] != NULL) {
                imprimirASTDecorada(atual->filho[i], nivel + 1);
            }
        }
    }
}

void liberarAST(NoAST *raiz) {
    if (raiz == NULL) return;
    for (int i = 0; i < MAX_FILHOS; i++) liberarAST(raiz->filho[i]);
    liberarAST(raiz->irmao);
    free(raiz);
}
