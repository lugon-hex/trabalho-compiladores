#include "scan.h"
#include "ast.h"
#include "tabela.h"
#include "erros.h"
/* #include "semantica.h" */
/* #include "mips.h" */

FILE *Fonte;
FILE *listing;

extern NoAST *raizAST;
int yyparse(void);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <arquivo.cm> [saida_mips.txt]\n", argv[0]);
        return 1;
    }

    listing = stdout;
    Fonte = fopen(argv[1], "r");
    if (Fonte == NULL) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    inicializarErros();

    int resultadoSintatico = yyparse();
    fclose(Fonte);

    if (resultadoSintatico != 0 || obterTotalErros() > 0) {
        imprimirResumoErros();
        liberarAST(raizAST);
        return 1;
    }

    /* TODO (Membro 1 - Semantica):
     * analisarSemantica(raizAST);
     * imprimirTabelaSimbolos();
     */

    printf("\n============================================================\n");
    printf(" AST CONSTRUIDA\n");
    printf("============================================================\n");
    imprimirASTDecorada(raizAST, 0);

    imprimirResumoErros();

    /* TODO (Membro 2 - Geracao MIPS):
     * if (obterTotalErros() == 0) {
     *     const char *saida = (argc >= 3) ? argv[2] : "saida_mips.txt";
     *     gerarCodigoMIPS(raizAST, saida);
     * }
     */

    liberarAST(raizAST);
    return (obterTotalErros() > 0) ? 1 : 0;
}
