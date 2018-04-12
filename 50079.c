#include <stdio.h>

int main(){
    int a, b;
    scanf("%d%d", &a, &b );
    int c = ( a + b ) * ( b - a + 1 ) / 2;
    int d = a + b + ( b - a - 1 ) * 2;
    printf("%d\n%d\n", c, d );
}