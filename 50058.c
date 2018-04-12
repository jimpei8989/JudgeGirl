#include <stdio.h>
#define maxn 20
#define goal ( ( 1 << 26 ) - 1 )
 
int min( int a, int b ){
    return a < b ? a : b;
}
 
int recur( int now, int x, int n, int dict[], int cost[] ){
    if( goal == now ) return 0;
    if( x == n ) return -1;
    int a, b;
    a = recur( (now | dict[ x ] ), x + 1, n, dict, cost );
    b = recur( now, x + 1, n, dict, cost );
    if( a == -1 && b == -1 ) return -1;
    else if( a == -1 ) return b;
    else if( b == -1 ) return a + cost[ x ];
    else return min( a + cost[ x ], b );
}
 
int main(){
    int n;
    scanf("%d", &n );
    int dict[ maxn ] = { 0 }, cost[ maxn ];
    for( int i = 0; i < n; i++ ){
        char c;
        while( (c = getchar()) != EOF && c != ' ' ){
            if( c >= 'a' && c <= 'z' )
            	dict[ i ] |= ( 1 << ( c - 'a' ) );
        }
        scanf("%d", &cost[ i ] );
    }
    int ans = recur( 0, 0, n, dict, cost );
    printf("%d\n", ans );
}