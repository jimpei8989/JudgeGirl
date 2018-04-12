#include <stdio.h>
#include <stdlib.h>
#define maxn (1<<10)

int edge[ maxn ][ maxn ];
int size[ maxn ];

int traverse(int now, int remain, int *vis, int *stk, int idx){
	stk[ idx ] = now;
	if (remain == 1) {
		for (int i = 0; i < size[ now ]; i++)
			if( edge[ now ][ i ] == 0 )
				return 1;
		return 0;
	}
	vis[ now ] = 1;
	for (int i = 0; i < size[ now ]; i++) {
		int tar = edge[ now ][ i ];
		if (vis[ tar ]) continue;
		if (traverse(tar, remain - 1, vis, stk, idx + 1)) return 1;
	}
	vis[ now ] = 0;
	return 0;
}

int cmp( const void *a, const void *b ){
	return *(int*)a - *(int*)b;
}

int main(){
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		edge[ a ][ size[ a ]++ ] = b;
		edge[ b ][ size[ b ]++ ] = a;
	}
	for (int i = 0; i < N; i++)
		qsort( edge[ i ], size[ i ], sizeof( int ), cmp );
	
	int vis[ maxn ] = { 0 };
	int stk[ maxn ] = { 0 };
	if (traverse(0, N, vis, stk, 0)){
		for (int i = 0; i < N; i++) printf("%d ", stk[ i ] );
		printf("0\n");
	} else {
		printf("NO SOLUTION\n");
	}
}