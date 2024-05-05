#include "../includes/token.h"
#include "../includes/lexer.h"
#include "../includes/cp.h"
#include <stdlib.h>
#include<stdio.h>
int main(int argc, char *argv[]){
 
    if(argc <2){
        printf("no input file.\ncompilation terminated\n");
        exit(1);
    }

    cp_compile_file(argv[1]);
    
    return 0;
}
