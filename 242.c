#include <stdio.h>
typedef long long ll;
int x[ 3 ], y[ 3 ];
int r[ 3 ];

int in( ll nx, ll ny, int k ){
    ll tmp = ( x[ k ] - nx ) * ( x[ k ] - nx ) + ( y[ k ] - ny ) * ( y[ k ] - ny );
    if( tmp <= ( r[ k ] * (ll) r[ k ] ) ) return 1;
    else return 0;
}

int main(){
    int T;
    scanf("%d", &T );
    while( T-- ){
        int cnt = 0;
        for( int i = 0; i < 3; i++ )
            scanf("%d%d%d", &x[ i ], &y[ i ], &r[ i ] );
        for( int i = 0; i < 3; i++ ){
            for( int dx = x[ i ] - r[ i ]; dx <= x[ i ] + r[ i ]; dx++ ){
                for( int dy = y[ i ] - r[ i ]; dy <= y[ i ] + r[ i ]; dy++ ){
                    if( in( dx, dy, i ) == 0 ) continue;
                    int tp = 0;
                    for( int j = 0; j < 3; j++ ){
                        tp += in( dx, dy, j );
                    }
                    if( tp == 1 ){
                        cnt ++;
                    }
                }
            }
        }
        for( int dx = x[ 0 ] - r[ 0 ]; dx <= x[ 0 ] + r[ 0 ]; dx ++ ){
            for( int dy = y[ 0 ] - r[ 0 ]; dy <= y[ 0 ] + r[ 0 ]; dy ++ ){
                int tp = 0;
                for( int j = 0; j < 3; j++ )
                    tp += in( dx, dy, j );
                if( tp == 3 )
                    cnt ++;
            }
        }
        printf("%d\n", cnt );
    }
    return 0;
}