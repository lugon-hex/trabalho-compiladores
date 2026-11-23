
#include "scan.h"

FILE *Fonte;
FILE *listing;

int yyparse(void);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Uso: %s <arquivo.cm>\n", argv[0]);
        return 1;
    }

    Fonte = fopen(argv[1], "r");

    if (Fonte == NULL)
    {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    int resultado = yyparse();

    if (resultado == 0)
    {
        printf("Programa sintaticamente valido!\n");
    }
    else if (resultado == 1)
    {
        printf("Programa sintaticamente invalido!\n");
    }

    fclose(Fonte);

    return resultado;
}
