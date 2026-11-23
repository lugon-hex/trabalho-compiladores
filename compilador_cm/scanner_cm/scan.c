#include "scan.h"

int lineno = 1;
char tokenString[MAXTOKENLEN + 1];

int pegaChar(void)
{
    int c = fgetc(Fonte);

    if (c == '\n')
        lineno++;

    return c;
}

void devolveChar(int c)
{
    if (c == '\n')
        lineno--;

    if (c != EOF)
        ungetc(c, Fonte);
}

TokenType reservado(char *s)
{
    if (!strcmp(s, "else"))   return ELSE;
    if (!strcmp(s, "if"))     return IF;
    if (!strcmp(s, "int"))    return INT;
    if (!strcmp(s, "return")) return RETURN;
    if (!strcmp(s, "void"))   return VOID;
    if (!strcmp(s, "while"))  return WHILE;

    return IDENTIFICADOR;
}

TokenType getToken(void)
{
    int idx;
    int c;
    int p;

    while (1)
    {
        idx = 0;
        c = pegaChar();

        if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
            continue;

        if (c == EOF)
        {
            tokenString[0] = '\0';
            return ENDFILE;
        }

        if (c == '/')
        {
            p = pegaChar();

            if (p == '*')
            {
                while (1)
                {
                    c = pegaChar();

                    if (c == EOF)
                    {
                        tokenString[0] = '\0';
                        return ENDFILE;
                    }

                    if (c == '*')
                    {
                        p = pegaChar();

                        if (p == '/')
                            break;

                        devolveChar(p);
                    }
                }

                continue;
            }

            devolveChar(p);

            tokenString[0] = '/';
            tokenString[1] = '\0';

            return DIVISAO;
        }

        if (isdigit(c))
        {
            while (isdigit(c))
            {
                if (idx < MAXTOKENLEN)
                    tokenString[idx++] = c;

                c = pegaChar();
            }

            devolveChar(c);

            tokenString[idx] = '\0';

            return NUMERO;
        }

        if (isalpha(c))
        {
            while (isalpha(c))
            {
                if (idx < MAXTOKENLEN)
                    tokenString[idx++] = c;

                c = pegaChar();
            }

            devolveChar(c);

            tokenString[idx] = '\0';

            return reservado(tokenString);
        }

        tokenString[0] = c;
        tokenString[1] = '\0';

        switch (c)
        {
            case '=':
                p = pegaChar();

                if (p == '=')
                {
                    tokenString[1] = '=';
                    tokenString[2] = '\0';
                    return IGUAL;
                }

                devolveChar(p);
                return ATRIBUICAO;

            case '<':
                p = pegaChar();

                if (p == '=')
                {
                    tokenString[1] = '=';
                    tokenString[2] = '\0';
                    return MENOR_IGUAL;
                }

                devolveChar(p);
                return MENOR;

            case '>':
                p = pegaChar();

                if (p == '=')
                {
                    tokenString[1] = '=';
                    tokenString[2] = '\0';
                    return MAIOR_IGUAL;
                }

                devolveChar(p);
                return MAIOR;

            case '!':
                p = pegaChar();

                if (p == '=')
                {
                    tokenString[1] = '=';
                    tokenString[2] = '\0';
                    return DIFERENTE;
                }

                devolveChar(p);
                return ERROR;

            case '+':
                return MAIS;

            case '-':
                return MENOS;

            case '*':
                return VEZES;

            case ';':
                return PONTO_VIRGULA;

            case ',':
                return VIRGULA;

            case '(':
                return ABRE_PARENTESE;

            case ')':
                return FECHA_PARENTESE;

            case '[':
                return ABRE_COLCHETE;

            case ']':
                return FECHA_COLCHETE;

            case '{':
                return ABRE_CHAVE;

            case '}':
                return FECHA_CHAVE;

            default:
                return ERROR;
        }
    }
}