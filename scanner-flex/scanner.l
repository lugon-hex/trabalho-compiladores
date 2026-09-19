%{
    #include <stdio.h>
%}

letter     [a-zA-Z]
digit      [0-9]
ID         {letter}{letter}*
NUM        {digit}{digit}*

%%

    /* Comentários */
"/*"([^*]|\*+[^*/])*\*+"/" {}

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
