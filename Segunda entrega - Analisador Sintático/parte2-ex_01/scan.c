#include "scan.h"

const char *nomes_tokens[] = {
    "ENDFILE", "ERROR", "ELSE", "IF", "INT", "RETURN", "VOID", "WHILE",
    "IDENTIFICADOR", "NUMERO", "ATRIBUICAO", "IGUAL", "MENOR", "MENOR_IGUAL",
    "MAIOR", "MAIOR_IGUAL", "DIFERENTE", "MAIS", "MENOS", "VEZES", "DIVISAO",
    "POTENCIA", "PONTO_VIRGULA", "VIRGULA", "ABRE_PARENTESE", "FECHA_PARENTESE",
    "ABRE_COLCHETE", "FECHA_COLCHETE", "ABRE_CHAVE", "FECHA_CHAVE"
};

FILE *arquivo_fonte = NULL;
int linha_atual = 1;
char texto_atual[MAXTOKENLEN + 1];

// --- FUNÇÕES UTILITÁRIAS ---

void iniciar_scanner(FILE *arquivo) {
    arquivo_fonte = arquivo;
    linha_atual = 1;
    texto_atual[0] = '\0';
}

const char* obter_lexema_atual(void) {
    return texto_atual;
}

int obter_linha_atual(void) {
    return linha_atual;
}

int ler_char(void) {
    int c = fgetc(arquivo_fonte);
    if (c == '\n') linha_atual++;
    return c;
}

void devolver_char(int c) {
    if (c == '\n') linha_atual--;
    if (c != EOF) ungetc(c, arquivo_fonte);
}

// --- FUNÇÕES DE RECONHECIMENTO ---

void pular_espacos_e_comentarios(int *c) {
    while (1) {
        while (*c == ' ' || *c == '\t' || *c == '\n' || *c == '\r') {
            *c = ler_char();
        }

        if (*c == '/') {
            int prox = ler_char();
            if (prox == '*') {
                // Comentário de bloco /* ... */
                while (1) {
                    *c = ler_char();
                    if (*c == EOF) return;
                    if (*c == '*') {
                        prox = ler_char();
                        if (prox == '/') {
                            *c = ler_char();
                            break;
                        }
                        devolver_char(prox);
                    }
                }
                continue; // Volta para limpar espaços após o comentário
            } else {
                devolver_char(prox);
                return; // Era apenas o operador de divisão
            }
        }
        break;
    }
}

TipoToken ler_numero(int c) {
    int i = 0;
    int tem_ponto = 0;

    while (isdigit(c) || (c == '.' && !tem_ponto)) {
        if (c == '.') tem_ponto = 1;
        if (i < MAXTOKENLEN) texto_atual[i++] = (char)c;
        c = ler_char();
    }
    devolver_char(c);
    texto_atual[i] = '\0';
    return NUMERO;
}

TipoToken verificar_reservada(const char *palavra) {
    if (!strcmp(palavra, "else"))   return ELSE;
    if (!strcmp(palavra, "if"))     return IF;
    if (!strcmp(palavra, "int"))    return INT;
    if (!strcmp(palavra, "return")) return RETURN;
    if (!strcmp(palavra, "void"))   return VOID;
    if (!strcmp(palavra, "while"))  return WHILE;
    return IDENTIFICADOR;
}

TipoToken ler_identificador(int c) {
    int i = 0;
    while (isalpha(c)) {
        if (i < MAXTOKENLEN) texto_atual[i++] = (char)c;
        c = ler_char();
    }
    devolver_char(c);
    texto_atual[i] = '\0';
    return verificar_reservada(texto_atual);
}

TipoToken ler_operador(int c) {
    int prox;
    texto_atual[0] = (char)c;
    texto_atual[1] = '\0';

    switch (c) {
        case '=':
            prox = ler_char();
            if (prox == '=') { texto_atual[1] = '='; texto_atual[2] = '\0'; return IGUAL; }
            devolver_char(prox);
            return ATRIBUICAO;
        case '<':
            prox = ler_char();
            if (prox == '=') { texto_atual[1] = '='; texto_atual[2] = '\0'; return MENOR_IGUAL; }
            devolver_char(prox);
            return MENOR;
        case '>':
            prox = ler_char();
            if (prox == '=') { texto_atual[1] = '='; texto_atual[2] = '\0'; return MAIOR_IGUAL; }
            devolver_char(prox);
            return MAIOR;
        case '!':
            prox = ler_char();
            if (prox == '=') { texto_atual[1] = '='; texto_atual[2] = '\0'; return DIFERENTE; }
            devolver_char(prox);
            return ERROR;
        case '/': return DIVISAO;
        case '+': return MAIS;
        case '-': return MENOS;
        case '*': return VEZES;
        case '^': return POTENCIA;
        case ';': return PONTO_VIRGULA;
        case ',': return VIRGULA;
        case '(': return ABRE_PARENTESE;
        case ')': return FECHA_PARENTESE;
        case '[': return ABRE_COLCHETE;
        case ']': return FECHA_COLCHETE;
        case '{': return ABRE_CHAVE;
        case '}': return FECHA_CHAVE;
        default:  return ERROR;
    }
}

// --- FUNÇÃO PRINCIPAL DO SCANNER ---

TipoToken proximo_token(void) {
    int c = ler_char();
    pular_espacos_e_comentarios(&c);

    if (c == EOF) {
        texto_atual[0] = '\0';
        return ENDFILE;
    }

    if (isdigit(c) || c == '.') return ler_numero(c);
    if (isalpha(c)) return ler_identificador(c);
    return ler_operador(c);
}