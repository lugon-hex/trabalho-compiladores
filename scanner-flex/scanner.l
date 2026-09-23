%{
#include "globals.h"

/* Variáveis globais do scanner */
int lineno = 1;
char tokenString[MAXTOKENLEN + 1];
int TraceScan = 1;
%}

%x COMMENT

letter      [a-zA-Z]
digit       [0-9]
identifier  {letter}{letter}*
number      {digit}{digit}*
newline     \n
whitespace  [ \t\r]+

%%

"/*"                    { BEGIN(COMMENT); }

<COMMENT>[^*]+          { /* Ignora o conteúdo interno */ }
<COMMENT>"*"            { /* Ignora asteriscos isolados */ }
<COMMENT>"*"+"/"        { BEGIN(INITIAL); /* Fecha o comentário */ }

<COMMENT><<EOF>>        {
                            return ERROR;
                        }

    /* ERRO: Identificador começando com número */
{digit}+{letter}{identifier}* { 
                            return ERROR; 
                        }

    /* Keywords */
"else"                  { return ELSE; }
"if"                    { return IF; }
"int"                   { return INT; }
"return"                { return RETURN; }
"void"                  { return VOID; }
"while"                 { return WHILE; }

    /* Special Symbols / Operators */
"+"                     { return PLUS; }
"-"                     { return MINUS; }
"*"                     { return TIMES; }
"/"                     { return OVER; }
"="                     { return ASSIGN; }
"=="                    { return EQ; }
"!="                    { return NEQ; }
"<"                     { return LT; }
"<="                    { return LE; }
">"                     { return GT; }
">="                    { return GE; }
";"                     { return SEMI; }
","                     { return COMMA; }
"("                     { return LPAREN; }
")"                     { return RPAREN; }
"["                     { return LBRACKET; }
"]"                     { return RBRACKET; }
"{"                     { return LBRACE; }
"}"                     { return RBRACE; }

    /* Identificadores e Números */
{identifier}            { return ID; }
{number}                { return NUM; }

    /* Quebras de linha e espaços em branco */
{newline}               { lineno++; }
{whitespace}            { /* skip whitespace */ }

    /* Caractere Desconhecido / Erro */
.                       { return ERROR; }

%%

TokenType getToken(void)
{ 
    TokenType currentToken;
    
    currentToken = yylex();
    strncpy(tokenString, yytext, MAXTOKENLEN);
    tokenString[MAXTOKENLEN] = '\0';
    
    if (TraceScan && currentToken != ENDFILE && currentToken != 0) {
        printf("\t%d: ", lineno);
        printToken(currentToken, tokenString);
    }
    
    return currentToken;
}

int main(int argc, char **argv) 
{
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (!f) {
            fprintf(stderr, "Erro ao abrir o arquivo %s\n", argv[1]);
            return 1;
        }
        yyin = f;
    }
    
    TokenType token;
    do {
        token = getToken();
    } while (token != ENDFILE && token != 0);

    if (argc > 1) {
        fclose(yyin);
    }
    
    return 0;
}

int yywrap() {
    return 1;
}
