#include <stdio.h>

void print( int w[ 20 ][ 20 ], int m ){
    printf("\n\n\n\n\n\n");
    for( int i = 0; i < m; i++ )
        for( int j = 0; j < m; j++ )
            printf("%d%c", w[ i ][ j ], " \n"[ j == m - 1 ] );
}

int h( int w[20][20], int p[20][20], int m ){
    int val = 0;
    for( int i = 0; i < m; i++ )
        for( int j = 0; j < m; j++ )
            val += p[ i ][ j ] * w[ i ][ j ];
    return val;
}

int main(){
    int w[ 20 ][ 20 ];
    int p[ 20 ][ 20 ];
    int n, m;
    scanf("%d%d", &n, &m );
    for( int i = 0; i < m; i++ )
        for( int j = 0; j < m; j++ )
            w[ i ][ j ] = 1;
    const int T = 2 * m * m;
    for( int i = 0; i < n; i++ ){
        int state;
        int tp[ 20 ][ 20 ];
        scanf("%d", &state );
        for( int i = 0; i < m; i++ )
            for( int j = 0; j < m; j++ )
                scanf("%d", &tp[ i ][ j ] );
        int val = h( w, tp, m );
        if( ( val >= T ) == state ) continue;
        else if( val >= T && state == 0 ){
            for( int i = 0; i < m; i++ )
                for( int j = 0; j < m; j++ )
                    if( tp[ i ][ j ] == 1 && w[ i ][ j ] > 1 ) w[ i ][ j ] /= 2;
        }
        else if( val < T && state == 1 ){
            for( int i = 0; i < m; i++ )
                for( int j = 0; j < m; j++ )
                    if( tp[ i ][ j ] == 1  ) w[ i ][ j ] *= 2;
        }
    }
    int q;
    scanf("%d", &q );
    while( q-- ){
        int val = 0;
        for( int i = 0; i < m; i++ ){
            for( int j = 0; j < m; j++ ){
                scanf("%d", &p[ i ][ j ] );
                val += p[ i ][ j ] * w[ i ][ j ];
            }
        }
        printf("%d\n", val >= T );
    }
    return 0;
}


