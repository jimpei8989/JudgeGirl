#include <stdio.h>

int main(){
    int n, m;
    int mp[ 110 ][ 110 ];
    while( scnaf("%d%d", &n, &m ) != EOF ){
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < m; j++ )
                scanf("%d", &mp[ i ][ j ] );

    }
}