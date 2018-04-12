#include <stdio.h>
#define maxn (1<<7)
#define maxm (1<<6)
typedef unsigned long long ull;

void print( int ans[], int n ){
	for( int i = 0; i < n; i++ )
		printf("%d\n", ans[ i ] );
}

int recur( int ans[], ull people, int now, int N, int idx, int K, ull memb[] ){
	if( idx == K ){
		print( ans, K );
		return 1;
	}
	if( idx > K ) return 0;
	if( N - now < K - idx ) return 0;
	ans[ idx ] = now;
	if( !(people & memb[ now ]) && recur( ans, people|memb[ now ], now + 1, N, idx + 1, K, memb ) ) return 1;	
	else return recur( ans, people, now + 1, N, idx, K, memb );
}

int main() {
	int N, K, M, ans[ maxn ];
	ull memb[ maxn ] = { 0 };
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &M);
		for (int j = 0; j < M; j++){
			int k;
			scanf("%d", &k );
			memb[ i ] |= (1ull << k);
		}
	}
	recur( ans, 0, 0, N, 0, K, memb );
	return 0;
}