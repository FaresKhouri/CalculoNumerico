#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double fatorial(double n){
    double i, f =1;
    
    for(i=n;i>0;i--){
        f=f*i;
    }
    
    return f;
}

double cosseno(double x){
    int n;
    double c = 0.0;
    for(n=0; n<= 30; n++){
        c = c + (pow(-1,n) * pow(x,2*n))/fatorial(2*n);
    }

    return c;
}

double seno(double x){
    int n;
    double c = 0.0;
    for(n=0; n<= 30; n++){
        c = c + (pow(-1,n) * pow(x,2*n+1))/fatorial(2*n + 1);
    }

    return c;
}

double rads(int n){
    return (3.1415 * n)/180.0;

}

