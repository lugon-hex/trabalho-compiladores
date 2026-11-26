/* erros.h */
#ifndef _ERROS_H_
#define _ERROS_H_

typedef enum {
    FASE_LEXICA,
    FASE_SINTATICA,
    FASE_SEMANTICA
} FaseCompilacao;

void inicializarErros(void);
void reportarErro(FaseCompilacao fase, int linha, const char *mensagem, const char *detalhe);
int obterTotalErros(void);
void imprimirResumoErros(void);

#endif
