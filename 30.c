#include <stdio.h>

int dp[ 32 ][ 32 ];

int find( int a, int b ){
	if( dp[ a ][ b ] != -1 ) return dp[ a ][ b ];
	return dp[ a ][ b ] = find( a - 1, b ) + find( a, b - 1 );
}

int main(){
	int r, c;
	scanf("%d%d", &r, &c );
	for( int i = 1; i <= r; i++ ){
		for( int j = 1; j <= c; j++ ){
			scanf("%d", &dp[ r - i + 1 ][ j ] );
			dp[ r - i + 1 ][ j ] *= -1;
		}
	}
	dp[ 1 ][ 1 ] = 1;
	printf("%d\n", find( r, c ) );
}