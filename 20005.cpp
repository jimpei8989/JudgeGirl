#include <cstdio>
#include <algorithm>

const int maxn = 1 << 10;
const int maxm = 5e6 + 10;

int dp[ 2 ][ maxm ];
int P[ maxn ];
int W[ maxn ];

int solve( int N, int M ){
	for( int i = 0; i < N; i++ ){
		int cur = i % 2;
		int nxt = 1 - cur;
		for( int j = 0; j <= M; j++ ){
			if( j >= W[ i ] )
				dp[ nxt ][ j ] = std::max( dp[ cur ][ j ], dp[ cur ][ j - W[ i ] ] + P[ i ] );
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