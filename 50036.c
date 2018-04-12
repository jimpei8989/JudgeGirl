#include <stdio.h>

int solve( int K, int N, int M, int a[], int now ){
	if( M < 0 ) return 0;
	if( now == N ) return K <= 0 ? 1 : 0;
	if( K + now > N ) return 0;
	int ret = 0;
	ret += solve( K - 1, N, M - a[ now ], a, now + 1 );
	ret += solve( K, N, M, a, now + 1 );
	return ret;
}

int main(){
	int K, N, M;
	int a[ 32 ];
	scanf("%d%d%d", &K, &N, &M );
	for( int i = 0; i < N; i++ ) scanf("%d", &a[ i ] );
	printf("%d\n", solve( K, N, M, a, 0 ) );
}