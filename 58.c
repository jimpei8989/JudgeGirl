#include <stdio.h>
#include <stdlib.h>
#define maxn 400

int n, m;
int mp[ maxn ][ maxn ];
int vi[ maxn ][ maxn ];

int di[ 4 ] = { 1, 0, -1, 0 };
int dj[ 4 ] = { 0, 1, 0, -1 };

int in( int a, int b ){
	if( a < 0 || b < 0 ) return 0;
	if( a >= n || b >= m ) return 0;
	return 1;
}

int dfs( int x, int y ){
	vi[ x ][ y ] = 1;
	int flag = 0;
	for( int k = 0; k < 4; k++ ){
		int ni = x + di[ k ];
		int nj = y + dj[ k ];
		if( !in( ni, nj ) ) continue;
		if( !vi[ ni ][ nj ] && mp[ ni ][ nj ] )
			flag += dfs( ni, nj );
	}
	return flag + 1;
}

int ans[ maxn*maxn ];

int cmp( const void *a, const void *b ){
	int aa = *(int*)a, bb = *(int*)b;
	if( aa > bb ) return -1;
	if( aa == bb ) return 0;
	if( aa < bb ) return 1;
}

int main(){
	int cnt = 0;
	scanf("%d%d", &n, &m );
	for( int i = 0; i < n; i++ )
		for( int j = 0; j < m; j++ )
			scanf("%d", &mp[ i ][ j ] );
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < m; j++ ){
			if( !vi[ i ][ j ] && mp[ i ][ j ] ){
				ans[ cnt++ ] = dfs( i, j );
			}
		}
	}
	qsort( ans, cnt, sizeof( int ), cmp );
	for( int i = 0; i < cnt; i++ )
		printf("%d\n", ans[ i ] );
}