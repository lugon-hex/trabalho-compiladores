%{
    #include <stdio.h>
%}

%x COMMENT

letter     [a-zA-Z]
digit      [0-9]
ID         {letter}{letter}*
NUM        {digit}{digit}*

%%

    /* Comentários */
"/*"                 { BEGIN(COMMENT); }

<COMMENT>[^*]+       { /* Ignora o conteúdo interno */ }
<COMMENT>"*"         { /* Ignora asteriscos isolados */ }
<COMMENT>"*"+"/"     { BEGIN(INITIAL); /* Fecha o comentário */ }

<COMMENT><<EOF>>     {
    printf("LEXICAL ERROR: Unclosed block comment at EOF\n");
    yyterminate();
}

    /* ERRO: Identificador começando com número (ex: 123var) */
{digit}+{letter}{letter}* { 
    printf("LEXICAL ERROR: Invalid identifier '%s'\n", yytext); 
}

    /* Keywords */
"else"|"if"|"int"|"return"|"void"|"while" { 
    printf("KEYWORD: %s\n", yytext); 
}

    /* Special */
"+"|"-"|"*"|"/"|"="|[;,()\[\]{}]|"<="|">="|"=="|"!="|"<"|">" {
    printf("SPECIAL: %s\n", yytext); 
}

    /* Identificadores e Números  */
{ID} { 
    printf("ID: %s\n", yytext); 
}

{NUM} { 
    printf("NUM: %s\n", yytext); 
}

    /* Espaço em Branco */
[ \t\n]+ { }

    /* Error */
.   { printf("LEXICAL ERROR: Unknown character '%s'\n", yytext); }

%%

int main(int argc, char **argv) {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
