#include <stdio.h>
#include <string.h>
#include <assert.h>
#define maxn ( 1 << 5 )
typedef unsigned long long ull;
 
int forbid[ maxn ][ maxn ];
 
void recur( int cnt[ maxn ], char *s, int n, int N, int T ){
    if( n == N ){
        printf("%s\n", s );
    }
    for( int i = 0; i < 26; i++ ){
        if( cnt[ i ] ){
        	if( n > 0 && forbid[ s[ n - 1 ] - 'a' ][ i ] ) continue;
            cnt[ i ] --;
            s[ n ] = 'a' + i;
            recur( cnt, s, n + 1, N, T );
            cnt[ i ] ++;
            s[ n ] = 0;
        }
    }
}
 
int main(){
    char s[ maxn ];
    scanf("%s", s );
    int N = strlen( s );
    int cnt[ maxn ] = { 0 };
    for( int i = 0; i < N; i++ ){
        cnt[ s[ i ] - 'a' ]++;
    }
    int T;
    scanf("%d", &T );
    for( int i = 0; i < T; i++ ){
    	char tmp[ maxn ];
    	scanf("%s", tmp );
    	forbid[ tmp[ 0 ] - 'a' ][ tmp[ 1 ] - 'a' ] = 1;
    }
    char ans[ maxn ] = { 0 };
    recur( cnt, ans, 0, N, T );
}