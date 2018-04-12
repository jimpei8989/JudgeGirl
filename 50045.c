#include <stdio.h>
#include <stdlib.h>

int dist( int a[], int b[] ){
    int cnt = 0;
    for( int i = 0; i < 3; i++ ) cnt += abs( a[ i ] - b[ i ] );
    return cnt;
}

int main(){
    int pos[ 3 ];
    int m[ 3 ];
    int b[ 3 ];
    for( int i = 0; i < 3; i++ ) scanf("%d", &pos[ i ] );
    for( int i = 0; i < 3; i++ ) scanf("%d", &m[ i ] );
    for( int i = 0; i < 3; i++ ) scanf("%d", &b[ i ] );
    int blackhole = 0;
    int n;
    scanf("%d", &n );
    for( int i = 0; i < n; i++ ){
        int tp;
        scanf("%d", &tp );
        tp --;
        pos[ tp / 2 ] += ( -2 * ( tp % 2 ) + 1 );

        if( dist( pos, m ) < 10 ) break;
        else if( dist( pos, b ) < 10 && blackhole == 0 ){
            blackhole ++;
            for( int i = 0; i < 3; i++ ) pos[ i ] = b[ i ];
        }
        
        if( i % 5 == 4 ) printf("%d %d %d\n", pos[ 0 ], pos[ 1 ], pos[ 2 ] );
    }
}