%code requires {
    #include "ast.h"
}

%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int lineno;
NoAST *raizAST = NULL;

int yylex(void);
void yyerror(const char *mensagem);
%}

%union {
    int num;
    struct {
        char *texto;
        int linha;
    } id;
    TipoDado tipo;
    OperadorBinario op;
    NoAST *no;
}

%token T_INT T_VOID T_ELSE
%token <num> T_IF T_WHILE T_RETURN T_ATRIBUICAO T_NUMERO
%token <id> T_IDENTIFICADOR

%token T_IGUAL
%token T_MENOR T_MENOR_IGUAL T_MAIOR T_MAIOR_IGUAL T_DIFERENTE

%token T_MAIS T_MENOS T_VEZES T_DIVISAO

%token T_PONTO_VIRGULA T_VIRGULA

%token T_ABRE_PARENTESE T_FECHA_PARENTESE
%token T_ABRE_COLCHETE T_FECHA_COLCHETE
%token T_ABRE_CHAVE T_FECHA_CHAVE

%token T_ERROR

%type <no> programa lista_declaracoes declaracao declaracao_variavel
%type <no> declaracao_funcao parametros lista_parametros parametro
%type <no> comando_composto declaracoes_locais lista_comandos comando
%type <no> comando_expressao comando_selecao comando_repeticao comando_retorno
%type <no> expressao variavel expressao_simples expressao_aditiva
%type <no> expressao_multiplicativa fator chamada_funcao argumentos lista_argumentos
%type <tipo> tipo_especificador
%type <op> operador_relacional

%start programa

%precedence T_IF_SEM_ELSE
%precedence T_ELSE

%%

programa:
    lista_declaracoes
    {
        raizAST = $1;
        $$ = $1;
    }
;

lista_declaracoes:
      lista_declaracoes declaracao
      {
          $$ = anexarIrmao($1, $2);
      }
    | declaracao
      {
          $$ = $1;
      }
;

declaracao:
      declaracao_variavel { $$ = $1; }
    | declaracao_funcao   { $$ = $1; }
;

declaracao_variavel:
      tipo_especificador T_IDENTIFICADOR T_PONTO_VIRGULA
      {
          $$ = criarNoDeclVar($1, $2.texto, 0, false, $2.linha);
          free($2.texto);
      }
    | tipo_especificador T_IDENTIFICADOR T_ABRE_COLCHETE T_NUMERO T_FECHA_COLCHETE T_PONTO_VIRGULA
      {
          $$ = criarNoDeclVar($1, $2.texto, $4, true, $2.linha);
          free($2.texto);
      }
;

tipo_especificador:
      T_INT  { $$ = TipoInt; }
    | T_VOID { $$ = TipoVoid; }
;

declaracao_funcao:
    tipo_especificador T_IDENTIFICADOR
    T_ABRE_PARENTESE parametros T_FECHA_PARENTESE
    comando_composto
    {
        $$ = criarNoDeclFunc($1, $2.texto, $4, $6, $2.linha);
        free($2.texto);
    }
;

parametros:
      lista_parametros { $$ = $1; }
    | T_VOID           { $$ = NULL; }
    | %empty           { $$ = NULL; }
;

lista_parametros:
      lista_parametros T_VIRGULA parametro
      {
          $$ = anexarIrmao($1, $3);
      }
    | parametro
      {
          $$ = $1;
      }
;

parametro:
      tipo_especificador T_IDENTIFICADOR
      {
          $$ = criarNoParam($1, $2.texto, false, $2.linha);
          free($2.texto);
      }
    | tipo_especificador T_IDENTIFICADOR T_ABRE_COLCHETE T_FECHA_COLCHETE
      {
          $$ = criarNoParam($1, $2.texto, true, $2.linha);
          free($2.texto);
      }
;

comando_composto:
    T_ABRE_CHAVE declaracoes_locais lista_comandos T_FECHA_CHAVE
    {
        $$ = criarNoComposto($2, $3, lineno);
    }
;

declaracoes_locais:
      declaracoes_locais declaracao_variavel
      {
          $$ = anexarIrmao($1, $2);
      }
    | %empty
      {
          $$ = NULL;
      }
;

lista_comandos:
      lista_comandos comando
      {
          $$ = anexarIrmao($1, $2);
      }
    | %empty
      {
          $$ = NULL;
      }
;

comando:
      comando_expressao { $$ = $1; }
    | comando_composto  { $$ = $1; }
    | comando_selecao   { $$ = $1; }
    | comando_repeticao { $$ = $1; }
    | comando_retorno   { $$ = $1; }
;

comando_expressao:
      expressao T_PONTO_VIRGULA { $$ = $1; }
    | T_PONTO_VIRGULA           { $$ = NULL; }
;

comando_selecao:
      T_IF T_ABRE_PARENTESE expressao T_FECHA_PARENTESE comando %prec T_IF_SEM_ELSE
      {
          $$ = criarNoIf($3, $5, NULL, $1);
      }
    | T_IF T_ABRE_PARENTESE expressao T_FECHA_PARENTESE comando T_ELSE comando
      {
          $$ = criarNoIf($3, $5, $7, $1);
      }
;

comando_repeticao:
    T_WHILE T_ABRE_PARENTESE expressao T_FECHA_PARENTESE comando
    {
        $$ = criarNoWhile($3, $5, $1);
    }
;

comando_retorno:
      T_RETURN T_PONTO_VIRGULA
      {
          $$ = criarNoReturn(NULL, $1);
      }
    | T_RETURN expressao T_PONTO_VIRGULA
      {
          $$ = criarNoReturn($2, $1);
      }
;

expressao:
      variavel T_ATRIBUICAO expressao
      {
          $$ = criarNoAtribuicao($1, $3, $2);
      }
    | expressao_simples
      {
          $$ = $1;
      }
;

variavel:
      T_IDENTIFICADOR
      {
          $$ = criarNoVar($1.texto, NULL, $1.linha);
          free($1.texto);
      }
    | T_IDENTIFICADOR T_ABRE_COLCHETE expressao T_FECHA_COLCHETE
      {
          $$ = criarNoVar($1.texto, $3, $1.linha);
          free($1.texto);
      }
;

expressao_simples:
      expressao_aditiva operador_relacional expressao_aditiva
      {
          $$ = criarNoOpBinario($2, $1, $3, lineno);
      }
    | expressao_aditiva
      {
          $$ = $1;
      }
;

operador_relacional:
      T_MENOR       { $$ = OP_MENOR; }
    | T_MENOR_IGUAL { $$ = OP_MENOR_IGUAL; }
    | T_MAIOR       { $$ = OP_MAIOR; }
    | T_MAIOR_IGUAL { $$ = OP_MAIOR_IGUAL; }
    | T_IGUAL       { $$ = OP_IGUAL; }
    | T_DIFERENTE   { $$ = OP_DIFERENTE; }
;

expressao_aditiva:
      expressao_aditiva T_MAIS expressao_multiplicativa
      {
          $$ = criarNoOpBinario(OP_MAIS, $1, $3, lineno);
      }
    | expressao_aditiva T_MENOS expressao_multiplicativa
      {
          $$ = criarNoOpBinario(OP_MENOS, $1, $3, lineno);
      }
    | expressao_multiplicativa
      {
          $$ = $1;
      }
;

expressao_multiplicativa:
      expressao_multiplicativa T_VEZES fator
      {
          $$ = criarNoOpBinario(OP_VEZES, $1, $3, lineno);
      }
    | expressao_multiplicativa T_DIVISAO fator
      {
          $$ = criarNoOpBinario(OP_DIVISAO, $1, $3, lineno);
      }
    | fator
      {
          $$ = $1;
      }
;

fator:
      T_ABRE_PARENTESE expressao T_FECHA_PARENTESE { $$ = $2; }
    | variavel                                     { $$ = $1; }
    | chamada_funcao                               { $$ = $1; }
    | T_NUMERO                                     { $$ = criarNoLiteral($1, lineno); }
;

chamada_funcao:
    T_IDENTIFICADOR T_ABRE_PARENTESE argumentos T_FECHA_PARENTESE
    {
        $$ = criarNoChamada($1.texto, $3, $1.linha);
        free($1.texto);
    }
;

argumentos:
      lista_argumentos { $$ = $1; }
    | %empty           { $$ = NULL; }
;

lista_argumentos:
      lista_argumentos T_VIRGULA expressao
      {
          $$ = anexarIrmao($1, $3);
      }
    | expressao
      {
          $$ = $1;
      }
;

%%
