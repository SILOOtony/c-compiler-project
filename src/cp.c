#include "../includes/cp.h"
#include "../includes/lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

char *read_file(const char *filename){
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "rb");
    if (fp == NULL){
        printf("could not read file %s\n",filename);
        exit(1);
    }

    char *buffer = (char*) calloc(1, sizeof(char));
    buffer[0] = '\0';

    while (read = getline(&line, &len, fp) !=-1) {
        buffer = realloc(buffer, (strlen(buffer) + strlen(line) +1) * sizeof(char)); 
        strcat(buffer, line);
    }
    
    
    fclose(fp);
    if(line) free(line);
    return buffer;
}

void cp_compile(char *src){
 lexer *lex = init_lexer(src);
 token *tok;

 do
 {
    tok = lexer_next_token(lex);
    printf("\nvalue: %s, type %d", tok->value, tok->type);
 } while (tok->type !=TOKEN_EOF);
 

 free(lex);
 free(tok);
}

void cp_compile_file(const char *filename){
    char *src = read_file(filename);
    printf("%s\n", src);
    cp_compile(src);
    free(src);
}