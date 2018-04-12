#include <stdio.h>
#include <stdlib.h>

int main(){
    const int maxn = 110;
    int mp[ 110 ][ 110 ] = { 0 };
    int L, X, Y;
    scanf("%d%d%d", &L, &X, &Y );
    int err = 0;
    for( int i = 0; i < L; i++ ){
        int n;
        scanf("%d", &n );
        if( err == 1 ) continue;
        int nx, ny;
        int px, py;
        for( int j = 0; j < n; j++ ){
            scanf("%d%d", &ny, &nx );
            if( err == 1 ) continue;
            if( nx < 0 || nx >= X || ny < 0 || ny >= Y ){
                err = 1;
            }
            else{
                if( j == 0 ){
                    px = nx; py = ny;
                    mp[ px ][ py ] = 1;
                }
                else if( px == nx || py == ny || abs( nx - px ) == abs( ny - py ) ){
                    do{
                        if( px != nx ) px += ( nx - px ) / abs( nx - px );
                        if( py != ny ) py += ( ny - py ) / abs( ny - py );
                        mp[ px ][ py ] = 1;
                    }while( px != nx || ny != py );
                    px = nx;
                    py = ny;

                }
                else err = 1;
            }
            if( err )
                printf("ERROR %d %d\n", i + 1, j + 1 );
        }
    }
    if( err == 0 ){
        for( int i = X - 1; i >= 0; i-- ){
            for( int j = 0; j < Y; j++ ){
                printf("%d", mp[ i ][ j ] );
            }
            printf("\n");
        }
    }
}