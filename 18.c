#include <stdio.h>

int main(){
    int r, c;
    int arr[ 110 ][ 110 ];
    scanf("%d%d", &r, &c );
    for( int i = 0; i < r; i++ )
        for( int j = 0; j < c; j++ )
            scanf("%d", &arr[ i ][ j ] );
    for( int i = 0; i < r; i++ ){
        for( int j = 0; j < c; j++ ){
            if( i - 1 >= 0 && arr[ i - 1 ][ j ] >= arr[ i ][ j ] ) continue;
            if( i + 1 < r && arr[ i + 1 ][ j ] >= arr[ i ][ j ] ) continue;
            if( j - 1 >= 0 && arr[ i ][ j - 1 ] >= arr[ i ][ j ] ) continue;
            if( j + 1 < c && arr[ i ][ j + 1 ] >= arr[ i ][ j ] ) continue;
            printf("%d\n", arr[ i ][ j ] );
        }
    }
}