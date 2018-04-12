#include <stdio.h>

const double pi = 3.1415926;

int main(){
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c );
    double area = 0;
    area += pi * c * c * 3 / 4;
    if( c > b ) area += pi * ( c - b ) * ( c - b ) * 1 / 4;
    if( c > a ) area += pi * ( c - a ) * ( c - a ) * 1 / 4;
    printf("%f\n", area);
}
