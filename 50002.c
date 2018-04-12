#include <stdio.h>

int main(){
    int n, k;
    const int maxn = 110;
    int mp[ 2 ][ maxn ][ maxn ];
    int dur[ maxn ][ maxn ];
    scanf("%d%d", &n, &k );
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            scanf("%d", &mp[ 0 ][ i ][ j ] );
        }
    }
    for( int t = 0; t < k; t++ ){
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < n; j++ ){
                dur[ i ][ j ] += mp[ t % 2 ][ i ][ j ] == 1 ;
                int cnt = 0;
                for( int dx = -1; dx <= 1; dx ++ ){
                    for( int dy = -1; dy <= 1; dy ++ ){
                        if( i + dx < 0 || i + dx >= n || j + dy < 0 || j + dy >= n )
                            continue;
                        if( dx == 0 && dy == 0 )
                            continue;
                        cnt += mp[ t % 2 ][ i + dx ][ j + dy ]; 
                    }
                }
                if( mp[ t % 2 ][ i ][ j ] == 1 ){
                    if( cnt < 2 || cnt > 3 ) 
                        mp[ ( t + 1 ) % 2 ][ i ][ j ] = 0;
                    else mp[ ( t + 1 ) % 2 ][ i ][ j ] = 1;
                }
                else{
                    if( cnt == 3 )
                        mp[ ( t + 1 ) % 2 ][ i ][ j ] = 1;
                    else mp[ ( t + 1 ) % 2 ][ i ][ j ] = 0;

                }
            }
        }
    }
    int x = 0, y = 0;
    int big = 0;
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            dur[ i ][ j ] += mp[ k % 2 ][ i ][ j ];
            if( dur[ i ][ j ] >= big ){
                big = dur[ i ][ j ];
                x = i;
                y = j;
            }

            printf("%d", mp[ k % 2 ][ i ][ j ] );
            if( j == n - 1 ) printf("\n");
            else printf(" ");
        }
    }
    printf("%d %d\n", x + 1, y + 1 );
}