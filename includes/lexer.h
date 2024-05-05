#ifndef LEXER_H
#define LEXER_H
#include "token.h"
typedef struct LEXER_STRUCT{
    char c;
    int src_size;
    int i;
    char *src;
}lexer;

lexer *init_lexer(char *src);
char lexer_peek(lexer *lex, int offset);
void lexer_advence(lexer *lex, int offset);
void lexer_skip_white_spaces(lexer *lex);
token *lexer_next_token(lexer *lex);
token *init_token_advence(lexer *lex, int offset, char *value, Type type);
token *lexer_parse_alpha(lexer *lex);

#endif