#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn ( 1 << 6 )

int max( int a, int b ){
	return a > b ? a : b;
}

int cmp( const void *a, const void *b ){
	return *( char* )a - *( char* ) b;
}

void sort( char *ipt ){
	int len = strlen( ipt );
	for( int i = 0; i < len; i++ )
		if( 'a' <= ipt[ i ] && ipt[ i ] <= 'z' ) ipt[ i ] += ( 'A' - 'a' );
	qsort( ipt, len, sizeof( char ), cmp );
}

int main(){
	int N, R, W, M;
	while( scanf("%d%d%d", &N, &R, &W ) != EOF ){
		char ans[ maxn ][ maxn ] = { 0 };
		for( int i = 0; i < N; i++ ){
			scanf("%s", ans[ i ] );
			sort( ans[ i ] );
		}
		scanf("%d", &M );
		while( M-- ){
			int score = 0;
			for( int i = 0; i < N; i++ ){
				char ipt[ maxn ];
				scanf("%s", ipt );
				if( strcmp( ipt, "N/A" ) == 0 ) continue;
				sort( ipt );
				if( strcmp( ipt, ans[ i ] ) == 0 )
					score += R;
				else score -= W;	
			}
			printf("%d\n", max( score, 0 ) );
		}
	}
}