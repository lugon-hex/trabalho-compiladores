#include "tabela.h"
#include <stdio.h>
#include <string.h>

static Simbolo tabela[MAX_SIMBOLOS];
static int totalSimbolos = 0;

static int pilhaEscopos[MAX_ESCOPOS];
static char nomesEscopos[MAX_ESCOPOS][64];
static int topoEscopo = -1;

void inicializarTabelaSimbolos(void) {
    totalSimbolos = 0;
    topoEscopo = -1;
    entrarEscopo("global");
}

void entrarEscopo(const char *nomeEscopo) {
    if (topoEscopo + 1 >= MAX_ESCOPOS) return;
    topoEscopo++;
    pilhaEscopos[topoEscopo] = totalSimbolos;
    strncpy(nomesEscopos[topoEscopo], nomeEscopo ? nomeEscopo : "bloco", 63);
    nomesEscopos[topoEscopo][63] = '\0';
}

void sairEscopo(void) {
    if (topoEscopo > 0) topoEscopo--;
}

Simbolo* buscarSimboloEscopoAtual(const char *nome) {
    if (topoEscopo < 0) return NULL;
    for (int i = totalSimbolos - 1; i >= pilhaEscopos[topoEscopo]; i--) {
        if (tabela[i].nivelEscopo == topoEscopo && strcmp(tabela[i].nome, nome) == 0) {
            return &tabela[i];
        }
    }
    return NULL;
}

Simbolo* buscarSimbolo(const char *nome) {
    for (int nivel = topoEscopo; nivel >= 0; nivel--) {
        for (int i = totalSimbolos - 1; i >= pilhaEscopos[nivel]; i--) {
            if (tabela[i].nivelEscopo == nivel && strcmp(tabela[i].nome, nome) == 0) {
                return &tabela[i];
            }
        }
    }
    return NULL;
}

bool inserirSimbolo(const char *nome, TipoDado tipo, CategoriaSimbolo categoria, int tamanhoArray, int linha) {
    if (totalSimbolos >= MAX_SIMBOLOS || buscarSimboloEscopoAtual(nome) != NULL) {
        return false;
    }

    Simbolo *s = &tabela[totalSimbolos++];
    strncpy(s->nome, nome, 63);
    s->nome[63] = '\0';
    s->tipo = (categoria == CAT_FUNCAO) ? TipoFuncao : tipo;
    s->tamanhoArray = tamanhoArray;
    s->tipoRetorno = (categoria == CAT_FUNCAO) ? tipo : TipoVoid;
    s->qtdParams = 0;
    s->categoria = categoria;
    s->linhaDeclaracao = linha;
    s->nivelEscopo = topoEscopo;
    strncpy(s->nomeEscopo, nomesEscopos[topoEscopo], 63);
    s->nomeEscopo[63] = '\0';
    return true;
}

void registrarParametroFuncao(Simbolo *funcSimb, TipoDado tipoParam) {
    if (funcSimb != NULL && funcSimb->qtdParams < MAX_PARAMS) {
        funcSimb->tiposParams[funcSimb->qtdParams++] = tipoParam;
    }
}

const char* nomeTipo(TipoDado tipo) {
    switch (tipo) {
        case TipoInt:    return "TipoInt";
        case TipoBool:   return "TipoBool";
        case TipoVoid:   return "TipoVoid";
        case TipoArray:  return "TipoArray(int)";
        case TipoFuncao: return "TipoFuncao";
        case TipoErro:   return "TipoErro";
        default:         return "Desconhecido";
    }
}

void imprimirTabelaSimbolos(void) {
    printf("\n================================================================================\n");
    printf(" TABELA DE SIMBOLOS\n");
    printf("================================================================================\n");
    printf(" %-15s | %-10s | %-15s | %-12s | %-5s | %s\n",
           "Identificador", "Categoria", "Tipo", "Escopo", "Linha", "Detalhes");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < totalSimbolos; i++) {
        Simbolo *s = &tabela[i];
        const char *cat = (s->categoria == CAT_FUNCAO) ? "Funcao" :
                          (s->categoria == CAT_PARAMETRO) ? "Parametro" : "Variavel";
        char extra[64] = "-";

        if (s->tipo == TipoArray) {
            snprintf(extra, sizeof(extra), "tam=%d", s->tamanhoArray);
        } else if (s->categoria == CAT_FUNCAO) {
            snprintf(extra, sizeof(extra), "ret=%s, params=%d", nomeTipo(s->tipoRetorno), s->qtdParams);
        }

        printf(" %-15s | %-10s | %-15s | %-12s | %-5d | %s\n",
               s->nome, cat, nomeTipo(s->tipo), s->nomeEscopo, s->linhaDeclaracao, extra);
    }
    printf("================================================================================\n");
}
