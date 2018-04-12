#include <stdio.h>

int main(){
    int r, c;
    int arr[ 110 ][ 110 ];
    scanf("%d%d", &r, &c );
    for( int i = 0; i < r; i++ )
        for( int j = 0; j < c; j++ )
            scanf("%d", &arr[ i ][ j ] );
    for( int j = 0; j < c; j++ ){
        int cnt = 0;
        for( int i = 0; i < r; i++ )
            cnt += arr[ i ][ j ];
        printf("%d\n", cnt / r );
    }
}