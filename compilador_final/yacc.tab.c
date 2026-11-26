/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "yacc.y"

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int lineno;
NoAST *raizAST = NULL;

int yylex(void);
void yyerror(const char *mensagem);

#line 83 "yacc.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "yacc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_INT = 3,                      /* T_INT  */
  YYSYMBOL_T_VOID = 4,                     /* T_VOID  */
  YYSYMBOL_T_ELSE = 5,                     /* T_ELSE  */
  YYSYMBOL_T_IF = 6,                       /* T_IF  */
  YYSYMBOL_T_WHILE = 7,                    /* T_WHILE  */
  YYSYMBOL_T_RETURN = 8,                   /* T_RETURN  */
  YYSYMBOL_T_ATRIBUICAO = 9,               /* T_ATRIBUICAO  */
  YYSYMBOL_T_NUMERO = 10,                  /* T_NUMERO  */
  YYSYMBOL_T_IDENTIFICADOR = 11,           /* T_IDENTIFICADOR  */
  YYSYMBOL_T_IGUAL = 12,                   /* T_IGUAL  */
  YYSYMBOL_T_MENOR = 13,                   /* T_MENOR  */
  YYSYMBOL_T_MENOR_IGUAL = 14,             /* T_MENOR_IGUAL  */
  YYSYMBOL_T_MAIOR = 15,                   /* T_MAIOR  */
  YYSYMBOL_T_MAIOR_IGUAL = 16,             /* T_MAIOR_IGUAL  */
  YYSYMBOL_T_DIFERENTE = 17,               /* T_DIFERENTE  */
  YYSYMBOL_T_MAIS = 18,                    /* T_MAIS  */
  YYSYMBOL_T_MENOS = 19,                   /* T_MENOS  */
  YYSYMBOL_T_VEZES = 20,                   /* T_VEZES  */
  YYSYMBOL_T_DIVISAO = 21,                 /* T_DIVISAO  */
  YYSYMBOL_T_PONTO_VIRGULA = 22,           /* T_PONTO_VIRGULA  */
  YYSYMBOL_T_VIRGULA = 23,                 /* T_VIRGULA  */
  YYSYMBOL_T_ABRE_PARENTESE = 24,          /* T_ABRE_PARENTESE  */
  YYSYMBOL_T_FECHA_PARENTESE = 25,         /* T_FECHA_PARENTESE  */
  YYSYMBOL_T_ABRE_COLCHETE = 26,           /* T_ABRE_COLCHETE  */
  YYSYMBOL_T_FECHA_COLCHETE = 27,          /* T_FECHA_COLCHETE  */
  YYSYMBOL_T_ABRE_CHAVE = 28,              /* T_ABRE_CHAVE  */
  YYSYMBOL_T_FECHA_CHAVE = 29,             /* T_FECHA_CHAVE  */
  YYSYMBOL_T_ERROR = 30,                   /* T_ERROR  */
  YYSYMBOL_T_IF_SEM_ELSE = 31,             /* T_IF_SEM_ELSE  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_programa = 33,                  /* programa  */
  YYSYMBOL_lista_declaracoes = 34,         /* lista_declaracoes  */
  YYSYMBOL_declaracao = 35,                /* declaracao  */
  YYSYMBOL_declaracao_variavel = 36,       /* declaracao_variavel  */
  YYSYMBOL_tipo_especificador = 37,        /* tipo_especificador  */
  YYSYMBOL_declaracao_funcao = 38,         /* declaracao_funcao  */
  YYSYMBOL_parametros = 39,                /* parametros  */
  YYSYMBOL_lista_parametros = 40,          /* lista_parametros  */
  YYSYMBOL_parametro = 41,                 /* parametro  */
  YYSYMBOL_comando_composto = 42,          /* comando_composto  */
  YYSYMBOL_declaracoes_locais = 43,        /* declaracoes_locais  */
  YYSYMBOL_lista_comandos = 44,            /* lista_comandos  */
  YYSYMBOL_comando = 45,                   /* comando  */
  YYSYMBOL_comando_expressao = 46,         /* comando_expressao  */
  YYSYMBOL_comando_selecao = 47,           /* comando_selecao  */
  YYSYMBOL_comando_repeticao = 48,         /* comando_repeticao  */
  YYSYMBOL_comando_retorno = 49,           /* comando_retorno  */
  YYSYMBOL_expressao = 50,                 /* expressao  */
  YYSYMBOL_variavel = 51,                  /* variavel  */
  YYSYMBOL_expressao_simples = 52,         /* expressao_simples  */
  YYSYMBOL_operador_relacional = 53,       /* operador_relacional  */
  YYSYMBOL_expressao_aditiva = 54,         /* expressao_aditiva  */
  YYSYMBOL_expressao_multiplicativa = 55,  /* expressao_multiplicativa  */
  YYSYMBOL_fator = 56,                     /* fator  */
  YYSYMBOL_chamada_funcao = 57,            /* chamada_funcao  */
  YYSYMBOL_argumentos = 58,                /* argumentos  */
  YYSYMBOL_lista_argumentos = 59           /* lista_argumentos  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   104

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  102

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    70,    74,    81,    82,    86,    91,    99,
     100,   104,   114,   115,   116,   120,   124,   131,   136,   144,
     151,   155,   162,   166,   173,   174,   175,   176,   177,   181,
     182,   186,   190,   197,   204,   208,   215,   219,   226,   231,
     239,   243,   250,   251,   252,   253,   254,   255,   259,   263,
     267,   274,   278,   282,   289,   290,   291,   292,   296,   304,
     305,   309,   313
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_INT", "T_VOID",
  "T_ELSE", "T_IF", "T_WHILE", "T_RETURN", "T_ATRIBUICAO", "T_NUMERO",
  "T_IDENTIFICADOR", "T_IGUAL", "T_MENOR", "T_MENOR_IGUAL", "T_MAIOR",
  "T_MAIOR_IGUAL", "T_DIFERENTE", "T_MAIS", "T_MENOS", "T_VEZES",
  "T_DIVISAO", "T_PONTO_VIRGULA", "T_VIRGULA", "T_ABRE_PARENTESE",
  "T_FECHA_PARENTESE", "T_ABRE_COLCHETE", "T_FECHA_COLCHETE",
  "T_ABRE_CHAVE", "T_FECHA_CHAVE", "T_ERROR", "T_IF_SEM_ELSE", "$accept",
  "programa", "lista_declaracoes", "declaracao", "declaracao_variavel",
  "tipo_especificador", "declaracao_funcao", "parametros",
  "lista_parametros", "parametro", "comando_composto",
  "declaracoes_locais", "lista_comandos", "comando", "comando_expressao",
  "comando_selecao", "comando_repeticao", "comando_retorno", "expressao",
  "variavel", "expressao_simples", "operador_relacional",
  "expressao_aditiva", "expressao_multiplicativa", "fator",
  "chamada_funcao", "argumentos", "lista_argumentos", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-53)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       3,   -53,   -53,     2,     3,   -53,   -53,     5,   -53,   -53,
     -53,    25,   -53,    63,    15,    12,    19,    51,    31,   -53,
      50,    53,    54,     3,    56,    57,   -53,   -53,   -53,   -53,
     -53,     3,   -53,    69,     4,   -21,    59,    61,     7,   -53,
      29,   -53,    -2,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
      64,    72,   -53,    46,    48,   -53,   -53,    -2,    -2,   -53,
      65,    -2,    -2,    66,   -53,    -2,   -53,   -53,   -53,   -53,
     -53,   -53,    -2,    -2,    -2,    -2,    -2,    67,    68,   -53,
     -53,    70,    71,    62,   -53,   -53,   -53,    48,    48,    52,
     -53,   -53,    28,    28,   -53,    -2,   -53,    83,   -53,   -53,
      28,   -53
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,     0,     7,    14,     0,    10,     0,     0,    12,    16,
       0,    17,     0,     0,     0,     0,    21,    11,    15,     8,
      18,    23,    20,     0,     0,     0,     0,     0,     0,    57,
      38,    30,     0,    19,    25,    22,    24,    26,    27,    28,
       0,    55,    37,    41,    50,    53,    56,     0,     0,    34,
       0,    60,     0,     0,    29,     0,    46,    42,    43,    44,
      45,    47,     0,     0,     0,     0,     0,     0,     0,    35,
      62,     0,    59,     0,    54,    36,    55,    48,    49,    40,
      51,    52,     0,     0,    58,     0,    39,    31,    33,    61,
       0,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,   -53,    86,    73,   -10,   -53,   -53,   -53,    74,
      76,   -53,   -53,   -52,   -53,   -53,   -53,   -53,   -38,   -30,
     -53,   -53,    22,     0,    -1,   -53,   -53,   -53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    17,    18,    19,
      44,    31,    34,    45,    46,    47,    48,    49,    50,    51,
      52,    74,    53,    54,    55,    56,    81,    82
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      60,    12,     9,    16,    63,    14,     1,     2,    39,    40,
      36,    37,    38,    16,    39,    40,    11,    39,    40,    77,
      78,    33,    42,    80,    83,    20,    41,    85,    42,    59,
      21,    42,    26,    43,    36,    37,    38,   -13,    39,    40,
      97,    98,    86,    86,    86,    86,    86,    12,   101,    13,
      41,    14,    42,    61,    23,    62,    26,    99,    66,    67,
      68,    69,    70,    71,    72,    73,     1,    15,    75,    76,
      72,    73,    87,    88,    90,    91,    22,    24,    29,    25,
      35,    65,    26,    57,    30,    58,    64,    79,   100,    96,
      10,    84,    92,    93,    95,    94,    89,    28,    27,     0,
       0,     0,     0,     0,    32
};

static const yytype_int8 yycheck[] =
{
      38,    22,     0,    13,    42,    26,     3,     4,    10,    11,
       6,     7,     8,    23,    10,    11,    11,    10,    11,    57,
      58,    31,    24,    61,    62,    10,    22,    65,    24,    22,
      11,    24,    28,    29,     6,     7,     8,    25,    10,    11,
      92,    93,    72,    73,    74,    75,    76,    22,   100,    24,
      22,    26,    24,    24,    23,    26,    28,    95,    12,    13,
      14,    15,    16,    17,    18,    19,     3,     4,    20,    21,
      18,    19,    72,    73,    75,    76,    25,    27,    22,    26,
      11,     9,    28,    24,    27,    24,    22,    22,     5,    27,
       4,    25,    25,    25,    23,    25,    74,    23,    22,    -1,
      -1,    -1,    -1,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    33,    34,    35,    36,    37,    38,     0,
      35,    11,    22,    24,    26,     4,    37,    39,    40,    41,
      10,    11,    25,    23,    27,    26,    28,    42,    41,    22,
      27,    43,    36,    37,    44,    11,     6,     7,     8,    10,
      11,    22,    24,    29,    42,    45,    46,    47,    48,    49,
      50,    51,    52,    54,    55,    56,    57,    24,    24,    22,
      50,    24,    26,    50,    22,     9,    12,    13,    14,    15,
      16,    17,    18,    19,    53,    20,    21,    50,    50,    22,
      50,    58,    59,    50,    25,    50,    51,    55,    55,    54,
      56,    56,    25,    25,    25,    23,    27,    45,    45,    50,
       5,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    36,    37,
      37,    38,    39,    39,    39,    40,    40,    41,    41,    42,
      43,    43,    44,    44,    45,    45,    45,    45,    45,    46,
      46,    47,    47,    48,    49,    49,    50,    50,    51,    51,
      52,    52,    53,    53,    53,    53,    53,    53,    54,    54,
      54,    55,    55,    55,    56,    56,    56,    56,    57,    58,
      58,    59,    59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     0,     3,     1,     2,     4,     4,
       2,     0,     2,     0,     1,     1,     1,     1,     1,     2,
       1,     5,     7,     5,     2,     3,     3,     1,     1,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     3,     3,     1,     3,     1,     1,     1,     4,     1,
       0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programa: lista_declaracoes  */
#line 63 "yacc.y"
    {
        raizAST = (yyvsp[0].no);
        (yyval.no) = (yyvsp[0].no);
    }
#line 1206 "yacc.tab.c"
    break;

  case 3: /* lista_declaracoes: lista_declaracoes declaracao  */
#line 71 "yacc.y"
      {
          (yyval.no) = anexarIrmao((yyvsp[-1].no), (yyvsp[0].no));
      }
#line 1214 "yacc.tab.c"
    break;

  case 4: /* lista_declaracoes: declaracao  */
#line 75 "yacc.y"
      {
          (yyval.no) = (yyvsp[0].no);
      }
#line 1222 "yacc.tab.c"
    break;

  case 5: /* declaracao: declaracao_variavel  */
#line 81 "yacc.y"
                          { (yyval.no) = (yyvsp[0].no); }
#line 1228 "yacc.tab.c"
    break;

  case 6: /* declaracao: declaracao_funcao  */
#line 82 "yacc.y"
                          { (yyval.no) = (yyvsp[0].no); }
#line 1234 "yacc.tab.c"
    break;

  case 7: /* declaracao_variavel: tipo_especificador T_IDENTIFICADOR T_PONTO_VIRGULA  */
#line 87 "yacc.y"
      {
          (yyval.no) = criarNoDeclVar((yyvsp[-2].tipo), (yyvsp[-1].id).texto, 0, false, (yyvsp[-1].id).linha);
          free((yyvsp[-1].id).texto);
      }
#line 1243 "yacc.tab.c"
    break;

  case 8: /* declaracao_variavel: tipo_especificador T_IDENTIFICADOR T_ABRE_COLCHETE T_NUMERO T_FECHA_COLCHETE T_PONTO_VIRGULA  */
#line 92 "yacc.y"
      {
          (yyval.no) = criarNoDeclVar((yyvsp[-5].tipo), (yyvsp[-4].id).texto, (yyvsp[-2].num), true, (yyvsp[-4].id).linha);
          free((yyvsp[-4].id).texto);
      }
#line 1252 "yacc.tab.c"
    break;

  case 9: /* tipo_especificador: T_INT  */
#line 99 "yacc.y"
             { (yyval.tipo) = TipoInt; }
#line 1258 "yacc.tab.c"
    break;

  case 10: /* tipo_especificador: T_VOID  */
#line 100 "yacc.y"
             { (yyval.tipo) = TipoVoid; }
#line 1264 "yacc.tab.c"
    break;

  case 11: /* declaracao_funcao: tipo_especificador T_IDENTIFICADOR T_ABRE_PARENTESE parametros T_FECHA_PARENTESE comando_composto  */
#line 107 "yacc.y"
    {
        (yyval.no) = criarNoDeclFunc((yyvsp[-5].tipo), (yyvsp[-4].id).texto, (yyvsp[-2].no), (yyvsp[0].no), (yyvsp[-4].id).linha);
        free((yyvsp[-4].id).texto);
    }
#line 1273 "yacc.tab.c"
    break;

  case 12: /* parametros: lista_parametros  */
#line 114 "yacc.y"
                       { (yyval.no) = (yyvsp[0].no); }
#line 1279 "yacc.tab.c"
    break;

  case 13: /* parametros: T_VOID  */
#line 115 "yacc.y"
                       { (yyval.no) = NULL; }
#line 1285 "yacc.tab.c"
    break;

  case 14: /* parametros: %empty  */
#line 116 "yacc.y"
                       { (yyval.no) = NULL; }
#line 1291 "yacc.tab.c"
    break;

  case 15: /* lista_parametros: lista_parametros T_VIRGULA parametro  */
#line 121 "yacc.y"
      {
          (yyval.no) = anexarIrmao((yyvsp[-2].no), (yyvsp[0].no));
      }
#line 1299 "yacc.tab.c"
    break;

  case 16: /* lista_parametros: parametro  */
#line 125 "yacc.y"
      {
          (yyval.no) = (yyvsp[0].no);
      }
#line 1307 "yacc.tab.c"
    break;

  case 17: /* parametro: tipo_especificador T_IDENTIFICADOR  */
#line 132 "yacc.y"
      {
          (yyval.no) = criarNoParam((yyvsp[-1].tipo), (yyvsp[0].id).texto, false, (yyvsp[0].id).linha);
          free((yyvsp[0].id).texto);
      }
#line 1316 "yacc.tab.c"
    break;

  case 18: /* parametro: tipo_especificador T_IDENTIFICADOR T_ABRE_COLCHETE T_FECHA_COLCHETE  */
#line 137 "yacc.y"
      {
          (yyval.no) = criarNoParam((yyvsp[-3].tipo), (yyvsp[-2].id).texto, true, (yyvsp[-2].id).linha);
          free((yyvsp[-2].id).texto);
      }
#line 1325 "yacc.tab.c"
    break;

  case 19: /* comando_composto: T_ABRE_CHAVE declaracoes_locais lista_comandos T_FECHA_CHAVE  */
#line 145 "yacc.y"
    {
        (yyval.no) = criarNoComposto((yyvsp[-2].no), (yyvsp[-1].no), lineno);
    }
#line 1333 "yacc.tab.c"
    break;

  case 20: /* declaracoes_locais: declaracoes_locais declaracao_variavel  */
#line 152 "yacc.y"
      {
          (yyval.no) = anexarIrmao((yyvsp[-1].no), (yyvsp[0].no));
      }
#line 1341 "yacc.tab.c"
    break;

  case 21: /* declaracoes_locais: %empty  */
#line 156 "yacc.y"
      {
          (yyval.no) = NULL;
      }
#line 1349 "yacc.tab.c"
    break;

  case 22: /* lista_comandos: lista_comandos comando  */
#line 163 "yacc.y"
      {
          (yyval.no) = anexarIrmao((yyvsp[-1].no), (yyvsp[0].no));
      }
#line 1357 "yacc.tab.c"
    break;

  case 23: /* lista_comandos: %empty  */
#line 167 "yacc.y"
      {
          (yyval.no) = NULL;
      }
#line 1365 "yacc.tab.c"
    break;

  case 24: /* comando: comando_expressao  */
#line 173 "yacc.y"
                        { (yyval.no) = (yyvsp[0].no); }
#line 1371 "yacc.tab.c"
    break;

  case 25: /* comando: comando_composto  */
#line 174 "yacc.y"
                        { (yyval.no) = (yyvsp[0].no); }
#line 1377 "yacc.tab.c"
    break;

  case 26: /* comando: comando_selecao  */
#line 175 "yacc.y"
                        { (yyval.no) = (yyvsp[0].no); }
#line 1383 "yacc.tab.c"
    break;

  case 27: /* comando: comando_repeticao  */
#line 176 "yacc.y"
                        { (yyval.no) = (yyvsp[0].no); }
#line 1389 "yacc.tab.c"
    break;

  case 28: /* comando: comando_retorno  */
#line 177 "yacc.y"
                        { (yyval.no) = (yyvsp[0].no); }
#line 1395 "yacc.tab.c"
    break;

  case 29: /* comando_expressao: expressao T_PONTO_VIRGULA  */
#line 181 "yacc.y"
                                { (yyval.no) = (yyvsp[-1].no); }
#line 1401 "yacc.tab.c"
    break;

  case 30: /* comando_expressao: T_PONTO_VIRGULA  */
#line 182 "yacc.y"
                                { (yyval.no) = NULL; }
#line 1407 "yacc.tab.c"
    break;

  case 31: /* comando_selecao: T_IF T_ABRE_PARENTESE expressao T_FECHA_PARENTESE comando  */
#line 187 "yacc.y"
      {
          (yyval.no) = criarNoIf((yyvsp[-2].no), (yyvsp[0].no), NULL, (yyvsp[-4].num));
      }
#line 1415 "yacc.tab.c"
    break;

  case 32: /* comando_selecao: T_IF T_ABRE_PARENTESE expressao T_FECHA_PARENTESE comando T_ELSE comando  */
#line 191 "yacc.y"
      {
          (yyval.no) = criarNoIf((yyvsp[-4].no), (yyvsp[-2].no), (yyvsp[0].no), (yyvsp[-6].num));
      }
#line 1423 "yacc.tab.c"
    break;

  case 33: /* comando_repeticao: T_WHILE T_ABRE_PARENTESE expressao T_FECHA_PARENTESE comando  */
#line 198 "yacc.y"
    {
        (yyval.no) = criarNoWhile((yyvsp[-2].no), (yyvsp[0].no), (yyvsp[-4].num));
    }
#line 1431 "yacc.tab.c"
    break;

  case 34: /* comando_retorno: T_RETURN T_PONTO_VIRGULA  */
#line 205 "yacc.y"
      {
          (yyval.no) = criarNoReturn(NULL, (yyvsp[-1].num));
      }
#line 1439 "yacc.tab.c"
    break;

  case 35: /* comando_retorno: T_RETURN expressao T_PONTO_VIRGULA  */
#line 209 "yacc.y"
      {
          (yyval.no) = criarNoReturn((yyvsp[-1].no), (yyvsp[-2].num));
      }
#line 1447 "yacc.tab.c"
    break;

  case 36: /* expressao: variavel T_ATRIBUICAO expressao  */
#line 216 "yacc.y"
      {
          (yyval.no) = criarNoAtribuicao((yyvsp[-2].no), (yyvsp[0].no), (yyvsp[-1].num));
      }
#line 1455 "yacc.tab.c"
    break;

  case 37: /* expressao: expressao_simples  */
#line 220 "yacc.y"
      {
          (yyval.no) = (yyvsp[0].no);
      }
#line 1463 "yacc.tab.c"
    break;

  case 38: /* variavel: T_IDENTIFICADOR  */
#line 227 "yacc.y"
      {
          (yyval.no) = criarNoVar((yyvsp[0].id).texto, NULL, (yyvsp[0].id).linha);
          free((yyvsp[0].id).texto);
      }
#line 1472 "yacc.tab.c"
    break;

  case 39: /* variavel: T_IDENTIFICADOR T_ABRE_COLCHETE expressao T_FECHA_COLCHETE  */
#line 232 "yacc.y"
      {
          (yyval.no) = criarNoVar((yyvsp[-3].id).texto, (yyvsp[-1].no), (yyvsp[-3].id).linha);
          free((yyvsp[-3].id).texto);
      }
#line 1481 "yacc.tab.c"
    break;

  case 40: /* expressao_simples: expressao_aditiva operador_relacional expressao_aditiva  */
#line 240 "yacc.y"
      {
          (yyval.no) = criarNoOpBinario((yyvsp[-1].op), (yyvsp[-2].no), (yyvsp[0].no), lineno);
      }
#line 1489 "yacc.tab.c"
    break;

  case 41: /* expressao_simples: expressao_aditiva  */
#line 244 "yacc.y"
      {
          (yyval.no) = (yyvsp[0].no);
      }
#line 1497 "yacc.tab.c"
    break;

  case 42: /* operador_relacional: T_MENOR  */
#line 250 "yacc.y"
                    { (yyval.op) = OP_MENOR; }
#line 1503 "yacc.tab.c"
    break;

  case 43: /* operador_relacional: T_MENOR_IGUAL  */
#line 251 "yacc.y"
                    { (yyval.op) = OP_MENOR_IGUAL; }
#line 1509 "yacc.tab.c"
    break;

  case 44: /* operador_relacional: T_MAIOR  */
#line 252 "yacc.y"
                    { (yyval.op) = OP_MAIOR; }
#line 1515 "yacc.tab.c"
    break;

  case 45: /* operador_relacional: T_MAIOR_IGUAL  */
#line 253 "yacc.y"
                    { (yyval.op) = OP_MAIOR_IGUAL; }
#line 1521 "yacc.tab.c"
    break;

  case 46: /* operador_relacional: T_IGUAL  */
#line 254 "yacc.y"
                    { (yyval.op) = OP_IGUAL; }
#line 1527 "yacc.tab.c"
    break;

  case 47: /* operador_relacional: T_DIFERENTE  */
#line 255 "yacc.y"
                    { (yyval.op) = OP_DIFERENTE; }
#line 1533 "yacc.tab.c"
    break;

  case 48: /* expressao_aditiva: expressao_aditiva T_MAIS expressao_multiplicativa  */
#line 260 "yacc.y"
      {
          (yyval.no) = criarNoOpBinario(OP_MAIS, (yyvsp[-2].no), (yyvsp[0].no), lineno);
      }
#line 1541 "yacc.tab.c"
    break;

  case 49: /* expressao_aditiva: expressao_aditiva T_MENOS expressao_multiplicativa  */
#line 264 "yacc.y"
      {
          (yyval.no) = criarNoOpBinario(OP_MENOS, (yyvsp[-2].no), (yyvsp[0].no), lineno);
      }
#line 1549 "yacc.tab.c"
    break;

  case 50: /* expressao_aditiva: expressao_multiplicativa  */
#line 268 "yacc.y"
      {
          (yyval.no) = (yyvsp[0].no);
      }
#line 1557 "yacc.tab.c"
    break;

  case 51: /* expressao_multiplicativa: expressao_multiplicativa T_VEZES fator  */
#line 275 "yacc.y"
      {
          (yyval.no) = criarNoOpBinario(OP_VEZES, (yyvsp[-2].no), (yyvsp[0].no), lineno);
      }
#line 1565 "yacc.tab.c"
    break;

  case 52: /* expressao_multiplicativa: expressao_multiplicativa T_DIVISAO fator  */
#line 279 "yacc.y"
      {
          (yyval.no) = criarNoOpBinario(OP_DIVISAO, (yyvsp[-2].no), (yyvsp[0].no), lineno);
      }
#line 1573 "yacc.tab.c"
    break;

  case 53: /* expressao_multiplicativa: fator  */
#line 283 "yacc.y"
      {
          (yyval.no) = (yyvsp[0].no);
      }
#line 1581 "yacc.tab.c"
    break;

  case 54: /* fator: T_ABRE_PARENTESE expressao T_FECHA_PARENTESE  */
#line 289 "yacc.y"
                                                   { (yyval.no) = (yyvsp[-1].no); }
#line 1587 "yacc.tab.c"
    break;

  case 55: /* fator: variavel  */
#line 290 "yacc.y"
                                                   { (yyval.no) = (yyvsp[0].no); }
#line 1593 "yacc.tab.c"
    break;

  case 56: /* fator: chamada_funcao  */
#line 291 "yacc.y"
                                                   { (yyval.no) = (yyvsp[0].no); }
#line 1599 "yacc.tab.c"
    break;

  case 57: /* fator: T_NUMERO  */
#line 292 "yacc.y"
                                                   { (yyval.no) = criarNoLiteral((yyvsp[0].num), lineno); }
#line 1605 "yacc.tab.c"
    break;

  case 58: /* chamada_funcao: T_IDENTIFICADOR T_ABRE_PARENTESE argumentos T_FECHA_PARENTESE  */
#line 297 "yacc.y"
    {
        (yyval.no) = criarNoChamada((yyvsp[-3].id).texto, (yyvsp[-1].no), (yyvsp[-3].id).linha);
        free((yyvsp[-3].id).texto);
    }
#line 1614 "yacc.tab.c"
    break;

  case 59: /* argumentos: lista_argumentos  */
#line 304 "yacc.y"
                       { (yyval.no) = (yyvsp[0].no); }
#line 1620 "yacc.tab.c"
    break;

  case 60: /* argumentos: %empty  */
#line 305 "yacc.y"
                       { (yyval.no) = NULL; }
#line 1626 "yacc.tab.c"
    break;

  case 61: /* lista_argumentos: lista_argumentos T_VIRGULA expressao  */
#line 310 "yacc.y"
      {
          (yyval.no) = anexarIrmao((yyvsp[-2].no), (yyvsp[0].no));
      }
#line 1634 "yacc.tab.c"
    break;

  case 62: /* lista_argumentos: expressao  */
#line 314 "yacc.y"
      {
          (yyval.no) = (yyvsp[0].no);
      }
#line 1642 "yacc.tab.c"
    break;


#line 1646 "yacc.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 319 "yacc.y"

