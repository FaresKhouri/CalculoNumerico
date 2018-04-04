#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"

void eulerFloat(FILE *fp){	
	for(float n = 1; n <= 10e20; n *= 5){
		float x = powf(1 + (1/n), n);
		fprintf(fp, "%f %f\n", n, x); 
	}

}
void eulerDouble(FILE *fp){
	for(double n = 1; n <= 10e20; n *= 5){
		double x = pow(1 + (1/n), n);
		fprintf(fp, "%lf %lf\n", n, x); 
	}
}
void eulerLongDouble(FILE *fp){
	for(long double n = 1; n <= 10e20; n *= 5){
		long double x = powl(1 + (1/n), n);
		fprintf(fp, "%LF %LF\n", n, x); 
	}
} 
