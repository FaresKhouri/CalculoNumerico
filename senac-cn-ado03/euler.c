#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <math.h>
#include <tgmath.h>
#include <stdlib.h>
#include "lib.h"

int main() {
    double i = 1.0;
    float aux = 10e20;
    float xFloat = 0.0;
    double xDouble = 0.0;
    long double xLDouble = 0.0;
    float resultadoFloat = 0.0;
    double resultadodouble = 0.0;
    long double resultadoLdouble = 0.0;
    FILE *arqTemp;

    arqTemp = fopen("euler_flt.dat", "a");
    
    fprintf(arqTemp,"%.50f\t%.50f\n",0,1);
    while(i<=aux){
    	xFloat = log10f(i);
    	resultadoFloat = feuler(xFloat);
        fprintf(arqTemp,"%.50f\t%.50f\n",xFloat,resultadoFloat);
        i=i*1.01;
    }
   
    fclose(arqTemp);

    i= 1.0;
    arqTemp = fopen("euler_dbl.dat", "a");
    
    fprintf(arqTemp,"%.50lf\t%.50lf\n",0,1);
    while(i<=aux){
    	xDouble = log10(i);
    	resultadodouble = deuler(xDouble);
        fprintf(arqTemp,"%.50lf\t%.50lf\n",xDouble,resultadodouble);
        i=i*1.01;
    }
   
    fclose(arqTemp);

    i= 1.0;
    arqTemp = fopen("euler_ldbl.dat", "a");
    
    fprintf(arqTemp,"%.50lf\t%.50lf\n",0,1);
     while(i<=aux){
    	xDouble = log10(i);
    	resultadoLdouble = ldeuler(xDouble);
        fprintf(arqTemp,"%.50lf\t%.50Lf\n",xDouble,resultadoLdouble);
        i=i*1.01;
    }
   
    fclose(arqTemp);

    FILE *gnuplot = popen("gnuplot -persistent", "w");
    fprintf(gnuplot, "%s\n%s","set terminal png size 1000,800\nset output 'euler_flt.png'","plot 'euler_flt.dat'\n");
    fprintf(gnuplot, "%s\n%s","set terminal png size 1000,800\nset output 'euler_dbl.png'","plot 'euler_dbl.dat'\n");
    fprintf(gnuplot, "%s\n%s","set terminal png size 1000,800\nset output 'euler_ldbl.png'","plot 'euler_ldbl.dat'\n");
    fclose(gnuplot);
    remove("euler_flt.dat");
    remove("euler_dbl.dat");
    remove("euler_ldbl.dat");

    return 0;
}
