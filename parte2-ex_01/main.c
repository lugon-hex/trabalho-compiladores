#include <stdio.h>
#include "scan.h"
#include "parser.h"

int ler_tokens(void) {
    TipoToken token;
    printf("=== TOKENS LIDOS ===\n");

    do {
        token = proximo_token();
        if (!adicionar_token(token, obter_lexema_atual())) {
            printf("Erro: Limite maximo de tokens atingido.\n");
            return 0;
        }
        printf("Linha %-3d | %-15s | %s\n",
               obter_linha_atual(), nomes_tokens[token], obter_lexema_atual());
    } while (token != ENDFILE);

    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <arquivo.cm>\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    // Inicializa os modulos
    iniciar_scanner(arquivo);
    iniciar_parser();

    // lexico -> sintatico
    if (ler_tokens()) {
        No *raiz = NULL;
        if (analisar_ll1(&raiz)) {
            printf("\n=== ARVORE SINTATICA ===\n");
            imprimir_arvore(raiz, 0);
        }
        liberar_arvore(raiz);
    }

    fclose(arquivo);
    return 0;
}