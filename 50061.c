#include <stdio.h>
#define maxn ( 1 << 6 )
#define max( a, b ) ( a > b ? a : b )

typedef unsigned long long ull;

int N;
int D[ maxn ], forbid[ maxn ];
int edge[ maxn ][ maxn ];

int recur( int idx, ull forbid ){
	if( idx == N ) return 0;
	if( forbid & ( 1ull << idx ) ) return recur( idx + 1, forbid );
	int a = recur( idx + 1, forbid );

	for( int i = idx + 1; i < N; i++ )
		if( edge[ idx ][ i ] )
			forbid |= ( 1ull << i );
	int b = recur( idx + 1, forbid ) + D[ idx ];
	return max( a, b );
}

int main(){
	scanf("%d", &N );
	for( int i = 0; i < N; i++ ){
		scanf("%d", &D[ i ] );
	}
	for( int i = 0; i < N; i++ )
		for( int j = 0; j < N; j++ )
			scanf("%d", &edge[ i ][ j ] );
	printf("%d\n", recur( 0, 0 ) );
}