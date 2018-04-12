#include <stdio.h>

int main(){
    int M, N;
    int explode = 0;
    scanf("%d%d", &M, &N );
    int x[ 2 ], y[ 2 ], e[ 2 ], n[ 2 ], f[ 2 ];
    for( int i = 0; i < 2; i++ )
        scanf("%d%d%d%d%d", &x[ i ], &y[ i ], &e[ i ], &n[ i ], &f[ i ] );
    int nowt = 0;
    while( f[ 0 ] > 0 || f[ 1 ] > 0  ){
        if( f[ 0 ] > 0 ){
            f[ 0 ]--;
            if( nowt % ( e[ 0 ] + n[ 0 ] ) < n[ 0 ] ) y[ 0 ] ++;
            else x[ 0 ]++;
            x[ 0 ] %= M;
            y[ 0 ] %= N;
        }
        if( f[ 1 ] > 0 ){
            f[ 1 ]--;
            if( nowt % ( e[ 1 ] + n[ 1 ] ) < e[ 1 ] ) x[ 1 ] ++;
            else y[ 1 ]++;
            x[ 1 ] %= M;
            y[ 1 ] %= N;
        }
        nowt++;
        //printf("on time %d, R1 is on %d, %d; R2 is on %d, %d\n", nowt, x[ 0 ], y[ 0 ], x[ 1 ], y[ 1 ] );
        if( x[ 0 ] == x[ 1 ] && y[ 0 ] == y[ 1 ] ){
            explode = 1;
            printf("robots explode at time %d\n", nowt );
            break;
        }
    }
    if( explode == 0 ) printf("robots will not explode\n");

}