/* erros.c */
#include "erros.h"
#include <stdio.h>

static int totalErros = 0;

void inicializarErros(void) {
    totalErros = 0;
}

static const char* nomeFase(FaseCompilacao fase) {
    switch (fase) {
        case FASE_LEXICA:    return "LEXICO";
        case FASE_SINTATICA: return "SINTATICO";
        case FASE_SEMANTICA: return "SEMANTICO";
        default:             return "COMPILADOR";
    }
}

void reportarErro(FaseCompilacao fase, int linha, const char *mensagem, const char *detalhe) {
    totalErros++;
    fprintf(stderr, "\n[ERRO %s] Linha %d: %s\n", nomeFase(fase), linha, mensagem);
    if (detalhe != NULL && detalhe[0] != '\0') {
        fprintf(stderr, "   -> Detalhe: %s\n", detalhe);
    }
}

int obterTotalErros(void) {
    return totalErros;
}

void imprimirResumoErros(void) {
    printf("\n============================================================\n");
    printf(" RELATORIO DE COMPILACAO | Total de Erros: %d\n", totalErros);
    printf(" Status: %s\n", totalErros == 0 ? "SUCESSO" : "FALHA NA COMPILACAO");
    printf("============================================================\n");
}
