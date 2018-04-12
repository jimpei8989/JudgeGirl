#include <stdio.h>
#include <string.h>
#define maxs ( 1 << 10 )
#define maxn ( 1 << 14 )
#define maxl ( 1 << 7 )

char ipt[ maxn ][ maxl ];
int hash_table[ maxn ];
int cnt[ maxs ];

int f( char* str, int s ){
	int l = strlen( str );
	int x = 0;
	for( int i = 0; i < l; i++ ){
		if( '0' <= str[ i ] && str[ i ] <= '9' ) x += str[ i ] - '0';
		else x += str[ i ];
		x %= s;
	}
	return x % s;
}

int main(){
	int s, n, q;
	scanf("%d%d%d", &s, &n, &q );
	for( int i = 0; i < n; i++ ){
		scanf("%s", ipt[ i ] );
		hash_table[ i ] = f( ipt, s );
	}
	while( q-- ){
		char ipt[ 1 << 7 ];
		scanf("%s", ipt );
		int x = f( ipt, s );
		if( hash_table[ x ] ) printf("%d\n", x );
		else printf("-1\n");
	}
}