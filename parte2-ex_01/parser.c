#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TokenInfo lista_tokens[MAX_TOKENS];
int qtd_tokens = 0;

// --- FUNÇÕES DE BUFFER E ÁRVORE ---

void iniciar_parser(void) {
    qtd_tokens = 0;
}

int adicionar_token(TipoToken tipo, const char *texto) {
    if (qtd_tokens >= MAX_TOKENS) return 0;

    lista_tokens[qtd_tokens].tipo = tipo;
    strncpy(lista_tokens[qtd_tokens].texto, texto, MAXTOKENLEN);
    lista_tokens[qtd_tokens].texto[MAXTOKENLEN] = '\0';
    qtd_tokens++;
    return 1;
}

No* criar_no(const char *nome) {
    No *novo = (No*)malloc(sizeof(No));
    if (!novo) return NULL;

    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';
    novo->qtd_filhos = 0;
    for (int i = 0; i < MAX_FILHOS; i++) {
        novo->filhos[i] = NULL;
    }
    return novo;
}

void imprimir_arvore(No *no, int recuo) {
    if (no == NULL) return;

    for (int i = 0; i < recuo; i++) printf("  ");
    printf("|-- %s\n", no->nome);

    for (int i = 0; i < no->qtd_filhos; i++) {
        imprimir_arvore(no->filhos[i], recuo + 2);
    }
}

void liberar_arvore(No *no) {
    if (no == NULL) return;

    for (int i = 0; i < no->qtd_filhos; i++) {
        liberar_arvore(no->filhos[i]);
    }
    free(no);
}

// --- FUNÇÕES DA PILHA ---

void iniciar_pilha(Pilha *p) {
    p->topo = -1;
}

int pilha_vazia(Pilha *p) {
    return p->topo == -1;
}

int empilhar(Pilha *p, const char *simbolo, No *no) {
    if (p->topo + 1 >= MAX_PILHA) return 0;

    p->topo++;
    strncpy(p->itens[p->topo].simbolo, simbolo, sizeof(p->itens[p->topo].simbolo) - 1);
    p->itens[p->topo].simbolo[sizeof(p->itens[p->topo].simbolo) - 1] = '\0';
    p->itens[p->topo].no = no;
    return 1;
}

ItemPilha desempilhar(Pilha *p) {
    return p->itens[p->topo--];
}

// --- TABELA SINTÁTICA LL(1) ---

int eh_nao_terminal(const char *simbolo) {
    return (strcmp(simbolo, "E")  == 0 || strcmp(simbolo, "E'") == 0 ||
            strcmp(simbolo, "T")  == 0 || strcmp(simbolo, "T'") == 0 ||
            strcmp(simbolo, "F")  == 0 || strcmp(simbolo, "F'") == 0 ||
            strcmp(simbolo, "P")  == 0);
}

const char** buscar_regra(const char *nao_terminal, TipoToken token_atual) {
    static const char *regra_E[]        = {"T", "E'", NULL};
    static const char *regra_Ep_mais[]  = {"MAIS", "T", "E'", NULL};
    static const char *regra_Ep_menos[] = {"MENOS", "T", "E'", NULL};
    static const char *regra_vazia[]    = {NULL}; // epsilon

    static const char *regra_T[]        = {"F", "T'", NULL};
    static const char *regra_Tp_mult[]  = {"VEZES", "F", "T'", NULL};
    static const char *regra_Tp_div[]   = {"DIVISAO", "F", "T'", NULL};

    static const char *regra_F[]        = {"P", "F'", NULL};
    static const char *regra_Fp_pot[]   = {"POTENCIA", "F", NULL};

    static const char *regra_P_num[]    = {"NUMERO", NULL};
    static const char *regra_P_par[]    = {"ABRE_PARENTESE", "E", "FECHA_PARENTESE", NULL};

    if (strcmp(nao_terminal, "E") == 0 && (token_atual == NUMERO || token_atual == ABRE_PARENTESE))
        return regra_E;

    if (strcmp(nao_terminal, "E'") == 0) {
        if (token_atual == MAIS) return regra_Ep_mais;
        if (token_atual == MENOS) return regra_Ep_menos;
        if (token_atual == FECHA_PARENTESE || token_atual == ENDFILE) return regra_vazia;
    }

    if (strcmp(nao_terminal, "T") == 0 && (token_atual == NUMERO || token_atual == ABRE_PARENTESE))
        return regra_T;

    if (strcmp(nao_terminal, "T'") == 0) {
        if (token_atual == VEZES) return regra_Tp_mult;
        if (token_atual == DIVISAO) return regra_Tp_div;
        if (token_atual == MAIS || token_atual == MENOS ||
            token_atual == FECHA_PARENTESE || token_atual == ENDFILE) return regra_vazia;
    }

    if (strcmp(nao_terminal, "F") == 0 && (token_atual == NUMERO || token_atual == ABRE_PARENTESE))
        return regra_F;

    if (strcmp(nao_terminal, "F'") == 0) {
        if (token_atual == POTENCIA) return regra_Fp_pot;
        if (token_atual == MAIS || token_atual == MENOS || token_atual == VEZES ||
            token_atual == DIVISAO || token_atual == FECHA_PARENTESE || token_atual == ENDFILE)
            return regra_vazia;
    }

    if (strcmp(nao_terminal, "P") == 0) {
        if (token_atual == NUMERO) return regra_P_num;
        if (token_atual == ABRE_PARENTESE) return regra_P_par;
    }

    return NULL;
}

// --- EXECUÇÃO DO PARSER LL(1) ---

int expandir_nao_terminal(Pilha *pilha, const char *simbolo_topo, No *no_atual, TokenInfo token_atual, int *passo) {
    const char **regra = buscar_regra(simbolo_topo, token_atual.tipo);
    if (regra == NULL) {
        printf("\nErro Sintatico: Nenhuma regra na tabela para [%s, %s]\n",
               simbolo_topo, nomes_tokens[token_atual.tipo]);
        return 0;
    }

    int qtd_simbolos = 0;
    while (regra[qtd_simbolos] != NULL) qtd_simbolos++;

    printf("%-5d | Aplica Regra      | %-25s | %s -> ", (*passo)++, nomes_tokens[token_atual.tipo], simbolo_topo);
    if (qtd_simbolos == 0) {
        printf("epsilon\n");
        no_atual->filhos[0] = criar_no("epsilon");
        no_atual->qtd_filhos = 1;
    } else {
        for (int i = 0; i < qtd_simbolos; i++) printf("%s ", regra[i]);
        printf("\n");
    }

    No *novos_filhos[MAX_FILHOS];
    for (int i = 0; i < qtd_simbolos; i++) {
        novos_filhos[i] = criar_no(regra[i]);
        no_atual->filhos[i] = novos_filhos[i];
        no_atual->qtd_filhos++;
    }

    for (int i = qtd_simbolos - 1; i >= 0; i--) {
        if (!empilhar(pilha, regra[i], novos_filhos[i])) {
            printf("Erro: Estouro de pilha.\n");
            return 0;
        }
    }
    return 1;
}

int analisar_ll1(No **raiz_saida) {
    Pilha pilha;
    iniciar_pilha(&pilha);

    No *raiz = criar_no("E");
    *raiz_saida = raiz;

    empilhar(&pilha, "ENDFILE", NULL);
    empilhar(&pilha, "E", raiz);

    int idx_token = 0;
    int passo = 1;

    printf("\n=== PASSOS DO PARSE LL(1) ===\n");
    printf("%-5s | %-17s | %-25s | %s\n", "Passo", "Operacao", "Token Atual", "Detalhe");
    printf("----------------------------------------------------------------------\n");

    while (!pilha_vazia(&pilha)) {
        if (idx_token >= qtd_tokens) {
            printf("\nErro Sintatico: Fim inesperado dos tokens (faltou ENDFILE).\n");
            return 0;
        }

        ItemPilha topo = desempilhar(&pilha);
        TokenInfo token_atual = lista_tokens[idx_token];

        if (strcmp(topo.simbolo, "ENDFILE") == 0 && token_atual.tipo == ENDFILE) {
            printf("\nAnalise concluida com sucesso! Expressao aceita.\n");
            return 1;
        }

        if (!eh_nao_terminal(topo.simbolo)) {
            if (strcmp(topo.simbolo, nomes_tokens[token_atual.tipo]) == 0) {
                printf("%-5d | Match Terminal    | %-25s | '%s'\n",
                       passo++, nomes_tokens[token_atual.tipo], token_atual.texto);

                if (topo.no != NULL) {
                    snprintf(topo.no->nome, sizeof(topo.no->nome), "%s (%s)", topo.simbolo, token_atual.texto);
                }
                idx_token++;
            } else {
                printf("\nErro Sintatico: Esperado '%s', encontrou '%s'\n",
                       topo.simbolo, nomes_tokens[token_atual.tipo]);
                return 0;
            }
        } else {
            if (!expandir_nao_terminal(&pilha, topo.simbolo, topo.no, token_atual, &passo)) {
                return 0;
            }
        }
    }
    return 0;
}