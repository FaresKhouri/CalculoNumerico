#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, char **argv) {
    char resultado[100] ;
    long int numbase10 ;

    if(argc != 4) {
        printf("[uso] ./dbase <numero a converter> <base do numero > <base desejada>\n") ;
        return 1 ;
    }
    
    if (isNumeric(argv[2]) == 1){
        printf("Base do numero inconsisente\n");
        return 1;
    }
    else if (isNumeric(argv[3]) == 1){
        printf("Base do numero inconsisente\n");
        return 1;
    }
    else if ((atoi(argv[2]) < 1 || atoi(argv[2]) > 36) || (atoi(argv[3]) < 1 || atoi(argv[3]) > 36)){
        printf("Base deve estar entre 1 e 36\n");
        return 1;
    }

    if (consiste(argv[1],(atoi(argv[2]))) == 1){
        printf("Numero inconsisente para sua base\n");
        return 1;
    }

    numbase10 = baseNtobase10(argv[1], atoi(argv[2])) ;
    base10tobaseM(resultado, numbase10, atoi(argv[3])) ;

    puts(resultado);

    return 0;
}