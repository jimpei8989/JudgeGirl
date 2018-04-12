#include<stdio.h>

int main(){
    int a[ 3 ], b[ 3 ];
    for( int i = 0; i < 3; i++ )
        scanf("%d", &a[ i ] );
    for( int i = 0; i < 3; i++ )
        scanf("%d", &b[ i ] );
    int ip = 0;
    for( int i = 0; i < 3; i++ )
        ip += a[ i ] * b[ i ];
    int op[ 3 ];
    for( int i = 3; i < 6; i++ ){
        op[ i % 3 ] = a[ ( i + 1 ) % 3 ] * b[ ( i - 1 ) % 3 ] - b[ ( i + 1 ) % 3 ] * a[ ( i - 1 ) % 3 ];
    }
    printf("%d\n", ip );
    printf("%d %d %d\n", op[ 0 ], op[ 1 ], op[ 2 ] );
}