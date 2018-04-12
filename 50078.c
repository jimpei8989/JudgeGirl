#include <stdio.h>

int main(){
    int x[ 3 ], y[ 3 ];
    int dx[ 3 ], dy[ 3 ];
    for( int i = 0; i < 3; i++ ) 
        scanf("%d%d", &x[ i ], &y[ i ] );
    for( int i = 0; i < 3; i++ ){
        dx[ i ] = x[ ( i + 1 ) % 3 ] - x[ ( i ) % 3 ] + x[ ( i + 2 ) % 3 ];
        dy[ i ] = y[ ( i + 1 ) % 3 ] - y[ ( i ) % 3 ] + y[ ( i + 2 ) % 3 ];
        printf("%d\n%d\n", dx[ i ], dy[ i ] );
    }
}