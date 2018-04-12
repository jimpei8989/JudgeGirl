#include <stdio.h>

int max( int a, int b ){
    if( a > b ) return a;
    return b;
}

int min( int a, int b ){
    if( a < b ) return a;
    return b;
}

int main(){
    int n;
    int M, m;
    while( scanf("%d", &n ) != EOF ){
        M = -100000;
        m = 100000;
        int tp = 0;
        while( n > 0 && scanf("%d", &tp )!= EOF ){
            M = max( M, tp );
            m = min( m, tp );
            n--;
        }
        if( n == 0 ) printf("%d\n", M );
    }
    if( n > 0 ) printf("%d\n", m );
    return 0;
}