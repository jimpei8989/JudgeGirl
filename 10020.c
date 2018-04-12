#include <stdio.h>
#include <math.h>
#define float double

void swap( float *x, float *y ){
    float tp = *x;
    *x = *y;
    *y  = tp;
}

int main(){
    float a, b, c;
    while( scanf("%lf%lf%lf", &a, &b, &c ) != EOF ){
        float x = (-1 * b - sqrt( b*b - 4 * a * c )) / (2 * a);
        float y = (-1 * b + sqrt( b*b - 4 * a * c )) / (2 * a);
        if( a < 0 ) swap( &x, &y );
        printf("%.20f %.20f\n", x, y );
    }
}