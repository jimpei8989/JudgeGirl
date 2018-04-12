#pragma optimize "-O3"
#include <stdio.h>
typedef unsigned long long ull;
typedef unsigned char uc;

int dist( uc a, uc b ){
	int cnt = 0;
	uc tp = 1;
	for( int i = 0; i < 8; i++ ){
		if( ( a & tp ) != ( b & tp ) )
			cnt ++;
		tp <<= 1;
	}
	return cnt;
}

int main(){
	int N, M, P;
	ull store[ 4 ];
	scanf("%d%d%d", &N, &M, &P );
	for( int i = 0; i < M; i++ )
		scanf("%llu", &store[ i ] );

	for( int i = 0; i < P; i++ ){
		uc text;
		scanf("%hhu", &text );
		for( int j = 0; j < N; j++ ){
			uc tp = (store[ j / 8 ]) >> ( 56 - 8 * ( j % 8 ) );
			if( dist( text, tp ) <= 1 )
				printf("%d\n", (int)tp );
		}
	}
}
