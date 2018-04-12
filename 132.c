#include <stdio.h>
#define maxn 32

int legal( int N, int edge[][ 32 ], int result[] ){
	for( int i = 0; i < N; i++ )
		for( int j = 0; j < N; j++ )
			if( edge[ i ][ j ] && result[ i ] != 0 )
				if( result[ i ] == result[ j ] )
					return 0;
	return 1;
}

int solve( int now, int N, int C, int edge[][ 32 ], int result[] ){
	if( now == N ){
		return 1;
	}
	int flag = 0;
	for( int i = 1; i <= C && !flag; i++ ){
		result[ now ] = i;
		if( legal( N, edge, result ) ){
			flag += solve( now + 1, N, C, edge, result );
		}
		if( flag ) break;
		else result[ now ] = 0;
	}
	return flag;
}

int main(){
	int N, C, M;
	int result[ maxn ];
	int edge[ maxn ][ maxn ];
	for( int i = 0; i < maxn; i++ ){
		result[ i ] = 0;
		for( int j = 0; j < maxn; j++ ){
			edge[ i ][ j ] = 0;
		}
	}
	scanf("%d%d%d", &N, &C, &M );
	for( int i = 0; i < M; i++ ){
		int a, b;
		scanf("%d%d", &a, &b );
		edge[ a ][ b ] = 1;
		edge[ b ][ a ] = 1;
	}
	if( solve( 0, N, C, edge, result ) ){
		for( int i = 0; i < N; i++ )
			printf("%d\n", result[ i ] );
	}
	else{
		printf("no solution.\n");
	}

}