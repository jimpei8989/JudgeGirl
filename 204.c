#include <stdio.h>


int main(){

    const int maxn = 100 + 10;
    int mp[ maxn ][ maxn ];
    int dx[ 4 ] = { 0, -1, 0, 1 };//rt up lf dn
    int dy[ 4 ] = { 1, 0, -1, 0 };
    
    int w, d;
    scanf("%d%d", &w, &d );
    for( int i = 1; i <= d; i++ )
        for( int j = 1; j <= w; j++ )
            scanf("%d", &mp[ i ][ j ]);

    int sd = 0;
    int nx = d + 1;
    int ny = 1;
    for( int i = 0; i < 2 * ( w + d ); i++ ){
        if( (nx < 1 || nx > d ) && (ny < 1 || ny > w ) ){
            sd++;
            nx += dx[ sd ];
            ny += dy[ sd ];
        }
        mp[ nx ][ ny ] = i;
        nx += dx[ sd ];
        ny += dy[ sd ];
    }

    for( int i = 0; i <= d + 1; i++ ){
        for( int j = 0; j <= w + 1; j++ ){
            //printf("%2d ", mp[ i ][ j ] );
        }
        //printf("\n");
    }

    sd = 0;
    int sx = d + 1;
    int sy = 1;
    for( int i = 0; i < 2 * ( w + d ); i++ ){
        //printf("\ni = %d\n", i );
        if( ( sx < 1 || sx > d ) && (sy < 1 || sy > w ) ){
            sd++;
            sx += dx[ sd ];
            sy += dy[ sd ];
        }
        int dir = (sd + 1) % 4;
        nx = sx + dx[ dir ];
        ny = sy + dy[ dir ];
        //printf("%d %d %d %d\n", nx, ny, mp[ nx ][ ny ], dir );
        while( nx >= 1 && nx <= d && ny >= 1 && ny <= w ){
            if( mp[ nx ][ ny ] == 1 ){
                dir = dir / 2 * 2 + ( 1 - dir % 2 );
            }
            nx = nx + dx[ dir ];
            ny = ny + dy[ dir ];
            //printf("%d %d %d %d\n", nx, ny, mp[ nx ][ ny ], dir );
        }
        printf("%d\n", mp[ nx ][ ny ] );
        sx += dx[ sd ];
        sy += dy[ sd ];
    }
}