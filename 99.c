#include <stdio.h>

int main(){
    int n, m;
    scanf("%d%d", &n, &m );
    char name[ 11 ][ 100 ];
    int mp[ 11 ][ 256 + 10 ][ 256 + 10 ];
    int posi[ 11 ][ 256 * 256 + 10 ];
    int hori[ 11 ][ 256 + 10 ] = { 0 };
    int verti[ 11 ][ 256 + 10 ] = { 0 };
    int c1[ 11 ] = { 0 };
    int c2[ 11 ] = { 0 };
    int win[ 11 ] = { 0 };
    for( int i = 0; i < n; i++ ){
        scanf("%s", name[ i ] );
        for( int j = 0; j < m; j++ ){
            for( int k = 0; k < m; k++ ){
                scanf("%d", &mp[ i ][ j ][ k ] );
                posi[ i ][ mp[ i ][ j ][ k ] ] = j * m + k;
            }
        }
    }
    int gameover = 0;
    int stamp = 0;
    for( int i = 0; i < m * m; i++ ){
        int a;
        scanf("%d", &a );
        if( gameover == 1 ) continue;
        for( int p = 0; p < n; p++ ){
            int x = posi[ p ][ a ];
            int y = x % m;
            x /= m;
            verti[ p ][ x ]++;
            hori[ p ][ y ] ++;
            if( x == y )
                c1[ p ] ++;
            if( x + y == m - 1 )
                c2[ p ] ++;
            if( verti[ p ][ x ] == m || hori[ p ][ y ] == m || c1[ p ] == m || c2[ p ] == m ){
                gameover = 1;
                win[ p ] = 1;
                stamp = a;
            }
        }
    }
    printf("%d", stamp );
    for( int i = 0; i < n; i++ ){
        if( win[ i ] == 1 ) printf(" %s", name[ i ] );
    }
    printf("\n");
}