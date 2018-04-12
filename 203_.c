#include <stdio.h>

int accu( int k, int K ){
    k %= 2 * K;
    if( k < K )
        return k;
    else return 2 * K - k;
}

int main(){
    int cnt = 0;
    int X, Y, T;
    int x[ 2 ], y[ 2 ];
    int dx[ 2 ], dy[ 2 ];
    scanf("%d%d", &X, &Y );
    for( int i = 0; i < 2; i++ ){
        scanf("%d%d", &x[ i ], &y[ i ] );
        x[ i ] --;
        y[ i ] --;
        x[ i ] += 200000 * X;
        y[ i ] += 200000 * Y;
    }
    for( int i = 0; i < 2; i++ )
        scanf("%d%d", &dx[ i ], &dy[ i ] );
    scanf("%d", &T );
    while( T-- ){
        int nx[ 2 ], ny[ 2 ];
        for( int i = 0; i < 2; i++ ){
            nx[ i ] = x[ i ] + dx[ i ];
            ny[ i ] = y[ i ] + dy[ i ];
        }
        if( accu( nx[ 0 ], X ) == accu( nx[ 1 ], X ) && accu( ny[ 0 ], Y ) == accu( ny[ 1 ], Y ) )
            cnt ++;
        else if( accu( nx[ 0 ], X ) + accu( x[ 0 ], X ) == accu( nx[ 1 ], X ) + accu( x[ 1 ], X )
            && accu( ny[ 0 ], Y ) + accu( y[ 0 ], Y ) == accu( ny[ 1 ], Y ) + accu( y[ 1 ], Y ) )
            cnt ++;

        for( int i = 0; i < 2; i++ ){
            x[ i ] = nx[ i ];
            y[ i ] = ny[ i ];
        }
    }
    for( int i = 0; i < 2; i++ )
        printf("%d\n%d\n", accu( x[ ( i + cnt ) % 2 ], X ) + 1, accu( y[ ( i + cnt ) % 2 ], Y ) + 1 );
}