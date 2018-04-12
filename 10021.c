#include <stdio.h>

const int M = 10000;

int main(){
    int n, m;
    while( scanf("%d%d", &n, &m ) != EOF ){
        int dp[ 101 ][ 101 ] = { 0 };
        int mp[ 101 ][ 101 ];
        for( int i = 1; i <= n; i++ )
            for( int j = 1; j <= m; j++ )
                scanf("%d", &mp[ i ][ j ] );
        dp[ 1 ][ 1 ] = 1;
        for( int i = 1; i <= n; i++ ){
            for( int j = 1; j <= m; j++ ){
                if( i == 1 && j == 1 ) continue;
                else if( mp[ i ][ j ] == 1 ) continue;
                else dp[ i ][ j ] = ( dp[ i - 1 ][ j ] % M + dp[ i ][ j - 1 ] % M ) % M;
            }
        }
        printf("%d\n", dp[ n ][ m ] );
    }
    return 0;
}