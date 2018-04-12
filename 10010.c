#include <stdio.h>

int main(){
    int mp[ 1010 ][ 1010 ];
    int n, m;
    scanf("%d%d", &n, &m );
    for( int i = 0; i < 1010; i++ )
        for( int j = 0; j < 1010; j++ )
            mp[ i ][ j ] = 1;
    int q;
    scanf("%d", &q );

    while( q-- ){
        int lx, ly, rx, ry;
        int cnt = 0;
        scanf("%d%d%d%d", &lx, &ly, &rx, &ry );
        for( int i = lx; i <= rx; i++ ){
            for( int j = ly; j <= ry; j++ ){
                if( mp[ i ][ j ] == 1 ){ 
                    cnt ++;
                    mp[ i ][ j ] = -q;
                }
            }
        }
        printf("%d", cnt );
        for( int i = lx; i <= rx; i++ ){
            for( int j = ly; j <= ry; j++ ){
                if( mp[ i ][ j ] == -q ){
                    printf(" (%d, %d)", i, j );
                }
            }
        }
        printf("\n");
    }
    
}