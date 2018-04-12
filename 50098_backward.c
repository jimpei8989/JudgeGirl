#include <stdio.h>
#define maxn (1<<7)
#define maxm (1<<6)
typedef unsigned long long ull;

void print( int ans[] ){
	int idx = -1;
	while( ans[ ++idx ] != -1 )
		printf("%d\n", ans[ idx ] );
}

int recur( int ans[], ull people, int N, int K, ull memb[] ){
	if( K == 0 ){
		print( ans );
		return 1;
	}
	if( N <= 0 || N < K || K < 0 ) return 0;
	if( recur( ans, people, N - 1, K, memb ) ) return 1;
	else if( people & memb[ N - 1 ] ) return 0;
	else{
		ans[ K - 1 ] = N - 1;
		return recur( ans, people | memb[ N - 1 ], N - 1, K - 1, memb );
	}
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
	ans[ K ] = -1;
	recur( ans, 0, N, K, memb );
	return 0;
}