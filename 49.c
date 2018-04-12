#include <stdio.h>
#define maxm 1000 + 10

int sum[ maxm ];
int mx[ maxm ];
int mn[ maxm ];

int min( int a, int b ){
    return a < b ? a : b;
}
int max( int a, int b ){
    return a > b ? a : b;
}

void init(){
    for( int i = 0 ; i < maxm; i++ ){
        mx[ i ] = -1;
        mn[ i ] = 10 * maxm;
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m );
    init();
    for( int i = 0; i < n; i++ ){
        int a;
        scanf("%d", &a );
        int kk = a % m;
        sum[ kk ] += a;
        mx[ kk ] = max( mx[ kk ], a );
        mn[ kk ] = min( mn[ kk ], a );
    }
    for( int i = 0; i < m; i++ ){
        printf("%d %d %d\n", sum[ i ], mx[ i ], mn[ i ] );
    }
}