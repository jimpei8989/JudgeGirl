#include <stdio.h>
#define maxn (11)

int mn = maxn * maxn;
int rela[ maxn ][ maxn ];
int ans[ maxn ];

int max( int a, int b ){
	return a > b ? a : b;
}

void solve( int depth, int N, int used, int cost, int stk[] ){
	if( cost >= mn ) return;
	if( depth == N ){
		mn = cost;
		for( int i = 0; i < N; i++ )
			ans[ i ] = stk[ i ];
		return;
	}
	for( int x = 0; x < N; x++ ){
		if( !( used & ( 1 << x ) ) ){
			int dcost = 0;
			for( int i = 0; i < depth; i++ )
				if( rela[ stk[ i ] ][ x ] )
					dcost = max( dcost, depth - i );
			stk[ depth ] = x;
			solve( depth + 1, N, used | ( 1 << x ), max( dcost, cost ), stk );
		}
	}
}

int main(){
	int N, M;
	scanf("%d %d", &N, &M );
	for( int i = 0; i < M; i++ ){
		char a, b;
		scanf(" %c %c", &a, &b );
		rela[ a - 'A' ][ b - 'A' ] = 1;
		rela[ b - 'A' ][ a - 'A' ] = 1;
	}
	int stk[ maxn ];
	solve( 0, N, 0, 0, stk );
	printf("%d\n", mn );
	for( int i = 0; i < N; i++ )
		printf("%c%c", 'A' + ans[ i ], " \n"[ i == N - 1 ] );
}