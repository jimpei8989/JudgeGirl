#include <stdio.h>

int main(){
    int dx[ 4 ] = { 1, 0, -1, 0 };
    int dy[ 4 ] = { 0, 1, 0, -1 };
    int n;
    int mp[ 110 ][ 110 ] = { 0 };
    scanf("%d", &n );
    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= n; j++ )
            scanf("%d", &mp[ i ][ j ] );
    int I, T, t, e;
    I = T = t = e = 0;
    for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= n; j++ ){
            if( mp[ i ][ j ] == 1 ){
                int cnt = 0;
                for( int d = 0; d < 4; d++ ){
                    cnt += mp[ i + dx[ d ] ][ j + dy[ d ] ];
                }
                if( cnt == 4 ) I++;
                if( cnt == 3 ) T++;
                if( cnt == 2 && mp[ i + 1 ][ j ] != mp[ i - 1 ][ j ] ) t++;
                if( cnt == 1 ) e++;
            }
        }
    }
    printf("%d\n%d\n%d\n%d\n", I, T, t, e );
}