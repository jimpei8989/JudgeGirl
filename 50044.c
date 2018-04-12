#include <stdio.h>
#include <stdlib.h>

int dx[ 4 ] = { 1, -1, 0, 0 };
int dy[ 4 ] = { 0, 0, 1, -1 };

int main(){
    int n, m;
    scanf("%d%d", &n, &m );
    int x[ 1010 ];
    int y[ 1010 ];

    int sx, sy, ex, ey;
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey );

    int delta = ( sx == ex ? abs( ey - sy ) + 1 : abs( ex - sx ) + 1 );
    for( int i = 0; i < delta; i++ ){
        if( ex != sx ) x[ i ] = sx + ( ( ex - sx ) / abs( ex - sx ) ) * i ;
        else x[ i ] = sx;
        if( ey != sy ) y[ i ] = sy + ( ( ey - sy ) / abs( ey - sy ) ) * i ;
        else y[ i ] = sy;
    }

    int mp[ 1010 ][ 1010 ] = { 0 };
    for( int i = 0; i < delta; i++ ){
        mp[ x[ i ] ][ y [ i ] ] = 1; 
    }
    int q, idx = 0;
    scanf("%d", &q );

    while( q-- ){
        int k;
        scanf("%d", &k );
        int nx = x[ idx ];
        int ny = y[ idx ];
        int px = nx + dx[ k ];
        int py = ny + dy[ k ];
        if( px < 0 || px >= n || py < 0 ||py >= m ) break;
        int cc = ( idx - 1 + delta ) % delta;
        int cx = x[ cc ];
        int cy = y[ cc ];
        if( mp[ px ][ py ] == 1 && !( cx == px && cy == py ) ) break;

        mp[ cx ][ cy ] = 0;
        idx = cc;

        mp[ px ][ py ] = 1;
        x[ idx ] = px;
        y[ idx ] = py;
    }
    
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < m; j++ )
            printf("%d", mp[ i ][ j ] );
        printf("\n");
    }
    return 0;
}