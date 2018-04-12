#include <stdio.h>

int dp[ 32 ][ 32 ];

int find( int a, int b ){
	if( a == 0 || b == 0 ) return 0;
	if( dp[ a ][ b ] != 0 ) return dp[ a ][ b ];
	return dp[ a ][ b ] = find( a - 1, b ) + find( a, b - 1 );
}

int main(){
	dp[ 1 ][ 1 ] = 1;
	int r, c;
	scanf("%d%d", &r, &c );
	printf("%d\n", find( r, c ) );
}