#include <stdio.h>
#include <string.h>
#define maxn ( 1 << 5 )
typedef unsigned long long ull;
 
char forbid[ 1000 ][ maxn ];
int len[ 1000 ];
 
int diff( char *s1, char *s2, int n ){
    for( int i = 0; i < n; i++ ){
        if( s1[ i ] != s2[ i ] ) return 0;
    }
    return 1;
}
 
void recur( int cnt[ maxn ], char *s, int n, int N, int T ){
    for( int i = 0; i < T; i++ ){
        if( n >= len[ i ] ){
            if( diff( s + n - len[ i ], forbid[ i ], len[ i ] ) )
                return;
        }
    }
    if( n == N ){
        printf("%s\n", s );
    }
    for( int i = 0; i < 26; i++ ){
        if( cnt[ i ] ){
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
        scanf("%s", forbid[ i ] );
        len[ i ] = strlen( forbid[ i ] );
    }
    char ans[ maxn ] = { 0 };
    recur( cnt, ans, 0, N, T );
}