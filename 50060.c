#include <stdio.h>
#define maxn (1<<4)
int dist[ maxn ][ maxn ];
int n;
int ans = 2147483647;

int min( int a, int b ){
	return a < b ? a : b;
}

void recursion( int vis, int x, int start, int cnt, int k ){
	if( k > ans ) return;
	if( cnt == n ){
		ans = min( ans, k + dist[ x ][ start ] );
	}
	int tp = 1;
	for( int i = 0; i < n; i++ ){
		if( vis & tp );
		else{
			recursion( ( vis | tp ), i, start, cnt + 1, k + dist[ x ][ i ] );
		}
		tp <<= 1;
	}
}

int main(){
	scanf("%d", &n );
	for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
			scanf("%d", &dist[ i ][ j ] );
	for( int i = 0; i < 1; i++ ){
		int vis[ maxn ] = { 0 };
		int k = 0;
		recursion( (1<<i), i, i, 1, 0 );
	}
	printf("%d\n", ans );
}