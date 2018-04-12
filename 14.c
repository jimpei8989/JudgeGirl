#include <stdio.h>

int main(){
    int n;
    int arr[ 1010 ];
    scanf("%d", &n );
    for( int i = 0; i < n; i++ )
        scanf("%d", &arr[ i ] );
    for( int i = 0; i < n; i++ ){
        printf("%d", arr[ n - i - 1 ] );
        if( i == n - 1 ) printf("\n");
        else printf(" ");
    }
}