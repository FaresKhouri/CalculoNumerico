#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int fatorial(int n){
    int i, f =1;
    
    for(i=1;i<=n;i++){
        f=f*i;
    }
    
    return f;
}

double cosseno(double x){
    int n;
    double c = 0.0;
    for(n=0; n<= 6; n++){
        c = c + (pow(-1,n) * pow(x,2*n))/fatorial(2*n);
    }

    return c;
}

double seno(double x){
    int n;
    double c = 0.0;
    for(n=0; n<= 6; n++){
        c = c + (pow(-1,n) * pow(x,2*n+1))/fatorial(2*n + 1);
    }

    return c;
}

double rads(int n){
    return (3.1415 * n)/180.0;

}

