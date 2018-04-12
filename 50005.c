#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, k, m, d;
    scanf("%d%d%d%d", &n, &k, &m, &d );
    int A[ 11 ][ 11 ], B[ 11 ][ 11 ];
    for( int i = 0; i < n; i++ )
        for( int j = 0; j < n; j++ )
            scanf("%d", &A[ i ][ j ] );
    for( int i = 0; i < k; i++ )
        for( int j = 0; j < k; j++ )
            scanf("%d", &B[ i ][ j ] );
    int ax = -1, ay = -1;
    for( int i = 0; i <= n - k; i++ ){
        for( int j = 0; j <= n - k; j++ ){
            int cnt = 0;
            int sum = 0;
            for( int p = 0; p < k; p++ ){
                for( int q = 0; q < k; q++ ){
                    if( B[ p ][ q ] != A[ i + p ][ j + q ] ) cnt ++;

                    sum += ( B[ p ][ q ] - A[ i + p ][ j + q ] );
                }
            }
            if( cnt <= m && abs( sum ) <= d ){
                ax = i; ay = j;
            }
        }
    }
    printf("%d %d\n", ax, ay );
}