#include "scan.h"

FILE *Fonte;
FILE *listing;

static const char *tokenNames[] = {
    "ENDFILE", "ERROR", "ELSE", "IF", "INT", "RETURN", "VOID", "WHILE",
    "IDENTIFICADOR", "NUMERO", "ATRIBUICAO", "IGUAL", "MENOR", "MENOR_IGUAL",
    "MAIOR", "MAIOR_IGUAL", "DIFERENTE", "MAIS", "MENOS", "VEZES", "DIVISAO",
    "PONTO_VIRGULA", "VIRGULA", "ABRE_PARENTESE", "FECHA_PARENTESE",
    "ABRE_COLCHETE", "FECHA_COLCHETE", "ABRE_CHAVE", "FECHA_CHAVE"
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <arquivo.cm>\n", argv[0]);
        return 1;
    }

    Fonte = fopen(argv[1], "r");
    if (Fonte == NULL) {
        perror("Arquivo vazio?");
        return 1;
    }

    listing = stdout;
    TokenType token;

    printf("Linha\tToken\t\tLexema\n");

    do {
        token = getToken();
        if (token != ENDFILE) {
            printf("%d\t%-12s\t%s\n", lineno, tokenNames[token], tokenString);
        }
    } while (token != ENDFILE);

    fclose(Fonte);
    return 0;
}