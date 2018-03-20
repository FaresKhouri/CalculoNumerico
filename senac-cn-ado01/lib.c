#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isNumeric (char * str){

    int i = 0;
    int letra = 0;
    while(str[i] != '\0'){
        letra = (int)str[i];
        if(letra < 48 || letra > 57) {
            return 1;
        }
        i++;
    }
    return 0;
}

int consiste(char * str,int base){
    char *caracteres = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" ;
    int i = 0;
    int numero = 0;
    char *p;
    while(str[i] != '\0'){
        if((p=strchr(caracteres, str[i]))) {
            numero = (long int)(p - caracteres);
            if(numero >= base){
                return 1;
            }
        }
        i++;
    }
    return 0;
}

long int Valor_caractere(char c) {
    char *caracteres = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" ;
    char *p ;

    if((p=strchr(caracteres, c))) {
        return (long int)(p - caracteres);
    } else {
        return (long int)NULL ;
    }
}

long int baseNtobase10(char *numInput, int basen) {
    long int resultado = 0;
    long int exp = 1;
    long int index;

    index = strlen(numInput) - 1;

    if(index <= 0) return -1 ;

    while(index >= 0) {
        resultado += Valor_caractere(numInput[index])*exp;
        index-- ; exp = exp * basen ;
    }

    return resultado ;
}

void base10tobaseM(char *str, long int inpnum, int basem) {
    char *caracteres = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" ;
    int istr = 0;

    /* Número zero. */
    if(inpnum == 0) {
        str[0]='0'; istr=1;
    }

    /* Mapeia o resto da divisão no alfabeto e
     * faz do quociente o novo dividendo. */
    while(inpnum) {
        str[istr++]=caracteres[inpnum%basem];
        inpnum /= basem;
    }
    str[istr]=0 ;

    /* Inverte a string. */
    if(istr>0) {
        char t ;
        long int i=0 ;

        istr-- ;
        while(i <= istr/2) {
            t = str[istr-i] ;
            str[istr-i] = str[i];
            str[i++] = t;
        }
    }
}