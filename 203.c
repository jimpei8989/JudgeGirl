#include <stdio.h>

void swap( int *x, int *y ){
    int c = *x;
    *x = *y;
    *y = c;
}

int main(){
    int X, Y;
    int x[ 2 ], y[ 2 ];
    int dx[ 2 ], dy[ 2 ];
    scanf("%d%d", &X, &Y );
    for( int i = 0; i < 2; i++ )
        scanf("%d%d", &x[ i ], &y[ i ] );
    for( int i = 0; i < 2; i++ )
        scanf("%d%d", &dx[ i ], &dy[ i ] );
    int T;
    scanf("%d", &T );
    while( T-- ){
        for( int i = 0; i < 2; i++ ){
            x[ i ] += dx[ i ];
            y[ i ] += dy[ i ];

            if( x[ i ] == 1 || x[ i ] == X ) dx[ i ] *= -1;
            if( y[ i ] == 1 || y[ i ] == Y ) dy[ i ] *= -1;
        }

        if( x[ 0 ] == x[ 1 ] && y[ 0 ] == y[ 1 ] ){
            swap( &dx[ 0 ], &dx[ 1 ] );
            swap( &dy[ 0 ], &dy[ 1 ] );
        }
    }
    for( int i = 0; i < 2; i++ )
        printf("%d\n%d\n", x[ i ], y[ i ] );
}