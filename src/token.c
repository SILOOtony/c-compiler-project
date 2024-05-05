#include "../includes/token.h"
#include <stdlib.h>
#include <stdio.h>

token *init_token(char *value, Type type){
    token *tok = malloc(sizeof(struct TOKEN_STRUCT));
    tok-> value = value;
    tok->type = type;    
    return tok;
}

void print_token(token *t){
    printf("valule: %s, type: %d", t->value, t->type);
}