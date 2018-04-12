#include <stdio.h>

int find( int n, int a[], int k ){
	if( k < 0 ) return 0;
	if( k == 0 ) return 1;
	if( n == 0 ) return 0;
	return find( n - 1, a, k - a[ n - 1 ] ) + find( n - 1 , a, k );
}

int main(){
	int n;
	int a[ 16 ];
	scanf("%d", &n );
	for( int i = 0; i < n; i++ )
		scanf("%d", &a[ i ] );
	int k;
	while( scanf("%d", &k ) != EOF )
		printf("%d\n", find( n, a, k ) );
}