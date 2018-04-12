#include <stdio.h>

int main(){
    int n, m;
    int arr[ 200010 ];
    int cnt[ 200010 ] = { 0 };
    scanf("%d", &n );
    for( int i = 0; i < n; i++ )
        scanf("%d", &arr[ i ] );
    scanf("%d", &m );
    for( int i = 0; i < n; i++ ){
        cnt[ arr[ i ] % m ]++;
    }
    for( int i = 0; i < m; i++ )
        printf("%d\n", cnt[ i ] );
}