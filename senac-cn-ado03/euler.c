#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"

void inicializar (FILE *gnu, char *nome_arquivo, char * tipo_arquivo){

	 	fprintf(gnu, "set terminal png\n");
        	fprintf(gnu, "set output '%s'\n", nome_arquivo);
        	fprintf(gnu, "set logscale x\n");			
		fprintf(gnu, "set yrange [0:4]\n");
		fprintf(gnu, "set title 'Euler Com ''%s''\n", tipo_arquivo);
		fprintf(gnu, "set ylabel 'euler'\n"); 
		fprintf(gnu, "set xlabel 'n'\n");
		fprintf(gnu, "set nokey\n");
		fprintf(gnu, "plot '-' w l\n");
}

int main(void){
	FILE *  fpFloat;
	FILE *  fpDouble;
	FILE *  fpLDouble;

        fpFloat = popen("gnuplot -persistent", "w");
	fpDouble = popen("gnuplot -persistent", "w");
	fpLDouble = popen("gnuplot -persistent", "w");

	inicializar(fpFloat, "euler_flt.png", "Float");
	inicializar(fpDouble, "euler_dbl.png", "Double");
	inicializar(fpLDouble, "euler_ldbl.png", "Long Double");

	eulerFloat(fpFloat);
	eulerDouble(fpDouble);
	eulerLongDouble(fpLDouble);

	pclose(fpFloat);
        pclose(fpDouble);	
        pclose(fpLDouble);		
	
	return 0;	
}
