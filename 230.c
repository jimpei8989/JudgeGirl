#include <stdio.h>

int w[ 20 ];
int v[ 20 ];

int max( int a, int b ){
	return a > b ? a : b;
}

int find( int N, int W ){
	if( N == 0 ) return 0;
	if( W < w[ N ] ) return find( N - 1, W );
	return max( find( N - 1, W ), find( N - 1, W-w[ N ] ) + v[ N ] );
}

int main(){
	int N, W;
	scanf("%d%d", &N, &W );
	for( int i = 0; i < N; i++ )
		scanf("%d%d", &w[ i+1 ], &v[ i+1 ] );
	printf("%d\n", find( N, W ) );
}