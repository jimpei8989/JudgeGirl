#include <stdio.h>

int main(){
    int n, m;
    int c[ 20 ][ 20 ] = { 0 };
    for( int i = 1; i < 17; i++ ){
        for( int j = 0; j <= i; j++ ){
            if( j == 0 || j == i ) c[ i ][ j ] = 1;
            else c[ i ][ j ] = c[ i - 1 ][ j - 1 ] + c[ i - 1 ][ j ];
        }
    }
    int cnt = 0;
    scanf("%d%d", &n, &m );
    for( int i = 0; i <= m; i++ ){
        cnt += c[ n ][ i ];
    }
    printf("%d\n", cnt );
}