#include <stdio.h>
#include <math.h>
#include <tgmath.h>
#include <stdlib.h>

float feuler(float x){
    float n = x;
    if(x == 0){
       n=1;
    }
    
    n= 1+(1.0/n);

    n = powf(n,x);

    return n;
}

double deuler(double x){
    double n = x;
    if(x == 0){
       n=1;
    }
    
    n= 1+(1.0/n);

    n = pow(n,x);

    return n;
}

long double ldeuler(double x){
    long double n = x;
    if(x == 0){
       n=1;
    }
    
    n= 1+(1.0/n);

    n = powl(n,x);

    return n;
}

