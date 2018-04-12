#include <stdio.h>

int gcd( int a, int b ){
    if( b == 0 ) return a;
    return gcd( b, a % b );
}

int main(){
    int k = 1;
    int a;
    while( scanf("%d", &a ) != EOF ){
        int tp = a / gcd( a, k );
        k *= tp;
    }
    printf("%d\n", k );
}