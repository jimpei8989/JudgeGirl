#include <stdio.h>

void swap( int *a, int *b ){
    int c = *a;
    *a = *b;
    *b = c;
}

void sort( int a[ ], int n ){
    for( int i = 0; i < n; i++ ){
        int m = a[ i ];
        int idx = i;
        for( int j = i + 1; j < n; j++ ){
            if( a[ j ] < m ){
                m = a[ j ];
                idx = j;
            }
        }
        swap( &a[ i ], &a[ idx ] );
    }
}

void print( int n, int q[] ){
    for( int i = 0; i < n; i++ )
        printf("%d%c", q[ i ], " \n"[ i == n - 1 ] );
}

void recursion( int n, int a[], int used[], int now, int q[] ){
    for( int i = 0; i < n; i++ ){
        if( used[ i ] == 1 ) continue;
        used[ i ] = 1;
        q[ now ] = a[ i ];
        if( now + 1 == n ) print( n, q );
        else recursion( n, a, used, now + 1, q );
        used[ i ] = 0;
    }
}

int main(){
    int n;
    scanf("%d", &n );
    int a[ 100 ];
    for( int i = 0; i < n; i++ )
        scanf("%d", &a[ i ] );
    sort( a, n );
    int used[ 100 ] = { 0 };
    int q[ 100 ] = { 0 };
    recursion( n, a, used, 0, q );
}