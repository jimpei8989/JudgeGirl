#include <stdio.h>

int cross( int ax, int ay, int bx, int by, int cx, int cy ){
    int ix = ( bx - ax );
    int iy = ( by - ay );
    int jx = ( cx - ax );
    int jy = ( cy - ay );
    return ix * jy - jx * iy;
}

int main(){
    int x[ 3 ], y[ 3 ];
    int maxn = 1010;
    int in[ 2 ][ 2 * 1010 ] = { 0 };
    int cnt = 0;

    for( int i = 0; i < 3; i++ )
        scanf("%d%d", &x[ i ], &y[ i ] );

    for( int i = 1; i < 2 * maxn; i++ ){
        for( int j = 1; j < 2 * maxn; j++ ){
            int nx = i - maxn;
            int ny = j - maxn;
            int c[ 3 ];
            for( int k = 0; k < 3; k++ ){
                c[ k ] = cross( nx, ny, x[ k ], y[ k ], x[ ( k + 1 ) % 3 ], y[ ( k + 1 ) % 3 ] );
                if( c[ k ] != 0 )
                    c[ k ] = ( c[ k ] > 0 ? 1 : -1 );
            }
            int ni = i % 2;
            if( c[ 0 ] * c[ 1 ] * c[ 2 ] == 0 ) in[ ni ][ j ] = 1;
            else in[ ni ][ j ] = ( c[ 0 ] == c[ 1 ] && c[ 1 ] == c[ 2 ] ? 1 : 0 );

            if( in[ ni ][ j - 1 ] == 1 && in[ ni ][ j ] == 1 &&
                in[ 1 - ni ][ j - 1 ] == 1 && in[ 1 - ni ][ j ] == 1 )
                cnt ++;
        }
    }
    printf("%d\n", cnt );
}