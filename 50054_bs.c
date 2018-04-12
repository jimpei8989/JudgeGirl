#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxs ( 1 << 10 )
#define maxn ( 1 << 14 )
#define maxl ( 1 << 7 )

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

int cmp( const void *a, const void *b ){
	return strcmp( *(char**)a, *(char**)b );
}

int find( char* key, char** dict, int l, int r, int s ){
	if( l == r - 1 ){
		if( strcmp( key , dict[ l ] ) == 0 ) return f( key, s );
		else return -1;
	}
	int mid = ( l + r ) >> 1;
	if( strcmp( key, dict[ mid ] ) < 0 )
		return find( key, dict, l, mid, s );
	else return find( key, dict, mid, r, s );
}

int main(){
	int s, n, q;
	scanf("%d%d%d", &s, &n, &q );
	char buf[ maxl ];
	char** dict = (char**) malloc( sizeof( char* ) * (n + 1) );
	dict[ n ] = NULL;
	for( int i = 0; i < n; i++ ){
		scanf("%s", buf );
		char *tp = (char*) malloc ( strlen( buf ) + 1 );
		strcpy( tp, buf );
		dict[ i ] = tp;
	}
	qsort( dict, n, sizeof( char*), cmp );
	while( q-- ){
		char ipt[ 1 << 7 ];
		scanf("%s", ipt );
		printf("%d\n", find( ipt, dict, 0, n, s ) );
	}
}