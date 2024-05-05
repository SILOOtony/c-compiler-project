#include "../includes/lexer.h"
#include "../includes/token.h"
#include<stdlib.h>
#include <ctype.h>
#include <string.h> 
#include <stdio.h>

lexer *init_lexer(char *src){
    lexer *lex = malloc(sizeof(struct LEXER_STRUCT));
    lex->src = src;
    lex->src_size = strlen(lex->src);
    lex->i = 0;
    lex->c = lex->src[lex->i];
    return lex;
}

char lexer_peek(lexer *lex, int offset){
    if (lex->i + offset > lex->src_size){
        return lex->src[lex->src_size];
    }
    return lex->src[lex->i + offset];
}

void lexer_advence(lexer *lex, int offset){
    if (lex->c != '\'0')
    {
        lex->i = lex->i +offset;
        lex->c = lex->src[lex->i];
    }
    return;
}

token *lexer_init_token_advaence(lexer *lex, int offset, char *value, Type type){
    token *tok = init_token(value, type);
    lexer_advence(lex, offset);
    lexer_skip_white_spaces(lex);
    return tok;
}

void lexer_skip_white_spaces(lexer *lex){
    while (lex->c == ' ' ||  lex->c == '\t' ||  lex->c == '\n' || lex->c == '\r') {
        lexer_advence(lex, 1);
    }
}

token *lexer_parse_alpha(lexer *lex){
    char *tok = malloc(sizeof(char));
    lexer_skip_white_spaces(lex);
    if(lex->c == '\0') return init_token("\\0", TOKEN_EOF);
    while (isalnum(lex->c))
    {   
        tok = realloc(tok, strlen(tok) + sizeof(char));
        strcat(tok,(char[]){lex->c,0});
        lexer_advence(lex, 1);
    }
    if(tok =="int") return init_token(tok, TOKEN_INT);
    
    return init_token(tok, TOKEN_ID);
}

token *lexer_parse_alpha_skip(lexer *lex){
    token *tok = lexer_parse_alpha(lex);
    lexer_skip_white_spaces(lex);
    return tok;
}

token *lexer_next_token(lexer *lex){
    if (lex->c != '\0')
    {   
        lexer_skip_white_spaces(lex);
        if (isalnum(lex->c))
        {   
         
         return lexer_parse_alpha_skip(lex);
        }
        char str[2];
        str[0] = lex->c;
        str[1] = '\0';
        switch (lex->c)
        {
        case ',':
            return lexer_init_token_advaence(lex, 1, str, TOKEN_COMMA);
            break;
        case '(':
            return lexer_init_token_advaence(lex, 1, str, TOKEN_LPAREN);
            break;
        case ')':
            return lexer_init_token_advaence(lex, 1, str, TOKEN_RPAREN);
            break;
        case '{':
            return lexer_init_token_advaence(lex, 1, str, TOKEN_LBRACE);
            break;
        case '}':
            return lexer_init_token_advaence(lex, 1, str, TOKEN_RBRACE);
        case '[':
            return lexer_init_token_advaence(lex, 1, str, TOKEN_LSQUARE);
            break;
        case ']':
            return lexer_init_token_advaence(lex, 1, str, TOKEN_RSQUARE);
            break;
        case ';':
            return lexer_init_token_advaence(lex, 1, str, TOKEN_SEMI);
            break;
        case '*':
            return lexer_init_token_advaence(lex, 1, str, TOKEN_STAR);
        case '-':{
            if (lexer_peek(lex, 1) == '>')
            {
                return lexer_init_token_advaence(lex, 2, "->", TOKEN_ARROW);
            }
            printf("[LEXER]: unexpected character, what is this: '%c'", lex->c);
        }
            break;
        default: {
            printf("[LEXER]: unexpected character, what is this: '%c'", lex->c);
            exit(1);
        }
            break;
        }
        if (lex->c == '\0')
        {
            return init_token("\\0",TOKEN_EOF);
        }
        
    }
 
   
   return init_token("\\0", TOKEN_EOF);
}