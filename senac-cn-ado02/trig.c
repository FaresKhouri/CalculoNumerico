#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "lib.h"

int main() {
	int i = 0;
	double rad;
	double erroAbsoluto = 0.0;
	double erroRelativo = 0.0;
	double resultado = 0.0;
    FILE *arqSeno;
    FILE *arqCosse;

    arqSeno = fopen("seno.dat", "a");

    for(i=0;i<=720;i++){
    	rad = rads(i);
    	resultado = seno(rad);
    	erroAbsoluto = fabs(sin(rad) - resultado);
    	if(resultado != 0){
    		erroRelativo = fabs(erroAbsoluto / resultado);
        }
		fprintf(arqSeno,"%d\t%f\t%f\t%f\n",i,resultado,erroAbsoluto,erroRelativo);
    }
	fclose(arqSeno);

    arqCosse = fopen("cosseno.dat", "a");
   
    for(i=0;i<=720;i++){
    	rad = rads(i);
    	resultado = cosseno(rad);
    	erroAbsoluto = fabs(cos(rad) - resultado);
        if(resultado != 0){
    		erroRelativo = fabs(erroAbsoluto / resultado);
        }
		fprintf(arqSeno,"%d\t%f\t%f\t%f\n",i,resultado,erroAbsoluto,erroRelativo);
    }
    fclose(arqCosse);

    FILE *gnuplot = popen("gnuplot -persistent", "w");
    fprintf(gnuplot, "%s\n%s","set terminal png size 800,600\nset output 'seno.png'","plot 'seno.dat'\n");
    fprintf(gnuplot, "%s\n%s","set terminal png size 800,600\nset output 'cosseno.png'","plot 'cosseno.dat'");
    
    return 0;
}
