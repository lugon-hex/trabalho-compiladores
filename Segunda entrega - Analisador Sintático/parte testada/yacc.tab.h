/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_YACC_TAB_H_INCLUDED
# define YY_YY_YACC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_INT = 258,                   /* T_INT  */
    T_VOID = 259,                  /* T_VOID  */
    T_IF = 260,                    /* T_IF  */
    T_ELSE = 261,                  /* T_ELSE  */
    T_WHILE = 262,                 /* T_WHILE  */
    T_RETURN = 263,                /* T_RETURN  */
    T_IDENTIFICADOR = 264,         /* T_IDENTIFICADOR  */
    T_NUMERO = 265,                /* T_NUMERO  */
    T_ATRIBUICAO = 266,            /* T_ATRIBUICAO  */
    T_IGUAL = 267,                 /* T_IGUAL  */
    T_MENOR = 268,                 /* T_MENOR  */
    T_MENOR_IGUAL = 269,           /* T_MENOR_IGUAL  */
    T_MAIOR = 270,                 /* T_MAIOR  */
    T_MAIOR_IGUAL = 271,           /* T_MAIOR_IGUAL  */
    T_DIFERENTE = 272,             /* T_DIFERENTE  */
    T_MAIS = 273,                  /* T_MAIS  */
    T_MENOS = 274,                 /* T_MENOS  */
    T_VEZES = 275,                 /* T_VEZES  */
    T_DIVISAO = 276,               /* T_DIVISAO  */
    T_PONTO_VIRGULA = 277,         /* T_PONTO_VIRGULA  */
    T_VIRGULA = 278,               /* T_VIRGULA  */
    T_ABRE_PARENTESE = 279,        /* T_ABRE_PARENTESE  */
    T_FECHA_PARENTESE = 280,       /* T_FECHA_PARENTESE  */
    T_ABRE_COLCHETE = 281,         /* T_ABRE_COLCHETE  */
    T_FECHA_COLCHETE = 282,        /* T_FECHA_COLCHETE  */
    T_ABRE_CHAVE = 283,            /* T_ABRE_CHAVE  */
    T_FECHA_CHAVE = 284,           /* T_FECHA_CHAVE  */
    T_ERROR = 285,                 /* T_ERROR  */
    T_IF_SEM_ELSE = 286            /* T_IF_SEM_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */
