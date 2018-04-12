#include <stdio.h>

#define maxn ( 1 << 10 )
#define maxm ( 5000000 + 10 )

int max( int a, int b ){
	return a > b ? a : b;
}

int dp[ 2 ][ maxm ];
int P[ maxn ];
int W[ maxn ];

int solve( int N, int M ){
	for( int i = 0; i < N; i++ ){
		int cur = i % 2;
		int nxt = 1 - cur;
		for( int j = 0; j <= M; j++ ){
			if( j >= W[ i ] )
				dp[ nxt ][ j ] = max( dp[ cur ][ j ], dp[ cur ][ j - W[ i ] ] + P[ i ] );
			else
				dp[ nxt ][ j ] = dp[ cur ][ j ];
		}
	}
	return dp[ N % 2 ][ M ];
}

int main(){
	int N, M;
	scanf("%d%d", &M, &N );
	for( int i = 0; i < N; i++ )
		scanf("%d%d", &P[ i ], &W[ i ] );
	printf("%d\n", solve( N, M ) );
}