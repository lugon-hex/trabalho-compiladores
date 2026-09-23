#include "util.h"

void printToken(TokenType token, const char* tokenString)
{
    switch (token)
    {
        case IF:        
        case ELSE:     
        case INT:     
        case RETURN: 
        case VOID:    
        case WHILE:     printf("reserved word: %s\n", tokenString); break;
        case ASSIGN:    printf("=\n"); break;
        case EQ:        printf("==\n"); break;
        case NEQ:       printf("!=\n"); break;
        case LT:        printf("<\n"); break;
        case LE:        printf("<=\n"); break;
        case GT:        printf(">\n"); break;
        case GE:        printf(">=\n"); break;
        case PLUS:      printf("+\n"); break;
        case MINUS:     printf("-\n"); break;
        case TIMES:     printf("*\n"); break;
        case OVER:      printf("/\n"); break;
        case LPAREN:    printf("(\n"); break;
        case RPAREN:    printf(")\n"); break;
        case LBRACKET:  printf("[\n"); break;
        case RBRACKET:  printf("]\n"); break;
        case LBRACE:    printf("{\n"); break;
        case RBRACE:    printf("}\n"); break;
        case SEMI:      printf("SEMI ;\n"); break;
        case COMMA:     printf(",\n"); break;
        case NUM:       printf("NUM, val= %s\n", tokenString); break;
        case ID:        printf("ID, name= %s\n", tokenString); break;
        case ERROR:     printf("LEXICAL ERROR: %s\n", tokenString); break;
        case ENDFILE:   printf("EOF\n"); break;
        default:        printf("Unknown token %d\n", token);
    }
}
