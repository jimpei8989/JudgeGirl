#include <stdio.h>
#define maxn 105

int main(){
    int a[ maxn ];
    int b[ maxn ];
    int c[ maxn * maxn ] = {0};
    int n, m;
    scanf("%d", &n );
    for( int i = 0; i < n; i++ )
        scanf("%d", &a[ i ] );
    scanf("%d", &m );
    for( int i = 0; i < m; i++) 
        scanf("%d", &b[ i ] );
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < m; j++ ){
            c[ i + j ] += a[ i ] * b[ j ];
        }
    }
    for( int i = 0; i <= n + m - 2; i++ ){
        printf("%d", c[ i ] );
        if( i == n + m - 2 ) printf("\n");
        else printf(" ");
    }
}