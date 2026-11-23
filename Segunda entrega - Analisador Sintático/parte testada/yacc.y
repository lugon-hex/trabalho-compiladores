%{
#include <stdio.h>

int yylex(void);
void yyerror(const char *mensagem);
%}

%token T_INT T_VOID T_IF T_ELSE T_WHILE T_RETURN
%token T_IDENTIFICADOR T_NUMERO

%token T_ATRIBUICAO T_IGUAL
%token T_MENOR T_MENOR_IGUAL T_MAIOR T_MAIOR_IGUAL T_DIFERENTE

%token T_MAIS T_MENOS T_VEZES T_DIVISAO

%token T_PONTO_VIRGULA T_VIRGULA

%token T_ABRE_PARENTESE T_FECHA_PARENTESE
%token T_ABRE_COLCHETE T_FECHA_COLCHETE
%token T_ABRE_CHAVE T_FECHA_CHAVE

%token T_ERROR

%start programa



%precedence T_IF_SEM_ELSE
%precedence T_ELSE

%%

programa:
    lista_declaracoes
;

lista_declaracoes:
      lista_declaracoes declaracao
    | declaracao
;

declaracao:
      declaracao_variavel
    | declaracao_funcao
;

declaracao_variavel:
      tipo_especificador T_IDENTIFICADOR T_PONTO_VIRGULA
    | tipo_especificador T_IDENTIFICADOR T_ABRE_COLCHETE T_NUMERO T_FECHA_COLCHETE T_PONTO_VIRGULA
;

tipo_especificador:
      T_INT
    | T_VOID
;

declaracao_funcao:
    tipo_especificador T_IDENTIFICADOR
    T_ABRE_PARENTESE parametros T_FECHA_PARENTESE
    comando_composto
;

parametros:
      lista_parametros
    | T_VOID
    | %empty
;

lista_parametros:
      lista_parametros T_VIRGULA parametro
    | parametro
;

parametro:
      tipo_especificador T_IDENTIFICADOR
    | tipo_especificador T_IDENTIFICADOR T_ABRE_COLCHETE T_FECHA_COLCHETE
;

comando_composto:
    T_ABRE_CHAVE declaracoes_locais lista_comandos T_FECHA_CHAVE
;

declaracoes_locais:
      declaracoes_locais declaracao_variavel
    | %empty
;

lista_comandos:
      lista_comandos comando
    | %empty
;

comando:
      comando_expressao
    | comando_composto
    | comando_selecao
    | comando_repeticao
    | comando_retorno
;

comando_expressao:
      expressao T_PONTO_VIRGULA
    | T_PONTO_VIRGULA
;

comando_selecao:
      T_IF T_ABRE_PARENTESE expressao T_FECHA_PARENTESE comando
        %prec T_IF_SEM_ELSE
    | T_IF T_ABRE_PARENTESE expressao T_FECHA_PARENTESE comando T_ELSE comando
;

comando_repeticao:
    T_WHILE T_ABRE_PARENTESE expressao T_FECHA_PARENTESE comando
;

comando_retorno:
      T_RETURN T_PONTO_VIRGULA
    | T_RETURN expressao T_PONTO_VIRGULA
;

expressao:
      variavel T_ATRIBUICAO expressao
    | expressao_simples
;

variavel:
      T_IDENTIFICADOR
    | T_IDENTIFICADOR T_ABRE_COLCHETE expressao T_FECHA_COLCHETE
;

expressao_simples:
      expressao_aditiva operador_relacional expressao_aditiva
    | expressao_aditiva
;

operador_relacional:
      T_MENOR
    | T_MENOR_IGUAL
    | T_MAIOR
    | T_MAIOR_IGUAL
    | T_IGUAL
    | T_DIFERENTE
;

expressao_aditiva:
      expressao_aditiva T_MAIS expressao_multiplicativa
    | expressao_aditiva T_MENOS expressao_multiplicativa
    | expressao_multiplicativa
;

expressao_multiplicativa:
      expressao_multiplicativa T_VEZES fator
    | expressao_multiplicativa T_DIVISAO fator
    | fator
;

fator:
      T_ABRE_PARENTESE expressao T_FECHA_PARENTESE
    | variavel
    | chamada_funcao
    | T_NUMERO
;

chamada_funcao:
    T_IDENTIFICADOR T_ABRE_PARENTESE argumentos T_FECHA_PARENTESE
;

argumentos:
      lista_argumentos
    | %empty
;

lista_argumentos:
      lista_argumentos T_VIRGULA expressao
    | expressao
;

%%
