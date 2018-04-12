#include <stdio.h>

int main(){
    double mp[ 20 ][ 20 ];
    double y[ 20 ], x[ 20 ];
    int n;
    scanf("%d", &n );
    for( int i = 0; i < n; i++ )
        for( int j = 0; j < n; j++ )
            scanf("%lf", &mp[ i ][ j ] );
    for( int i = 0; i < n; i++ )
        scanf("%lf", &y[ i ] );
    for( int i = n - 1; i >= 0; i-- ){
        for( int j = n - 1; j > i; j-- ){
            y[ i ] -= mp[ i ][ j ] * x[ j ];
        }
        x[ i ] = y[ i ] / mp[ i ][ i ];
    }
    for( int i = 0; i < n; i++ )
        printf("%f\n", x[ i ] );
}