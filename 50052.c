#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 64
#define maxl 16

void bubble_sort( char s[][ maxl ], int n ){
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < n - 1; j++ ){
			if( strcmp( s[ j ], s[ j + 1 ] ) > 0 ){
				char tp[ maxl ];
				strcpy( tp, s[ j ] );
				strcpy( s[ j ], s[ j + 1 ] );
				strcpy( s[ j + 1 ], tp );
			}
		}
	}
}

int man_dis( char *a, char *b, int n ){
	int cnt = 0;
	for( int i = 0; i < n; i++ )
		cnt += abs( (int)a[ i ] - (int)b[ i ] );

	return cnt;
}

int belong( char s[ maxl ], char leader[ 3 ][ maxl ], int l ){
	int min = 2147483647, minid = -1;
	for( int i = 0; i < 3; i++ ){
		int cnt = man_dis( s, leader[ i ], l );
		if( cnt < min ){
			min = cnt;
			minid = i;
		}
	}
	return minid;
}

int find( int l, char s[][ maxl ], int member[], int n, int vec[ maxl ] ){
	int min = 2147483647, minid = -1;
	for( int i = 0; i < n; i++ ){
		int now = member[ i ];
		int cnt = 0;
		for( int i = 0; i < l; i++ )
			cnt += abs( (int)s[ now ][ i ] - vec[ i ] );
		if( cnt < min ){
			min = cnt;
			minid = now;
		}
	}
	return minid;
}

int main(){
	int n, l, r;
	char str[ maxn ][ maxl ];
	char leader[ 3 ][ maxl ];
	scanf("%d%d%d", &n, &l, &r );
	for( int i = 0; i < n; i++ )
		scanf("%s", str[ i ] );
	for( int i = 0; i < 3; i++ )
		strcpy( leader[ i ], str[ i ] );
	bubble_sort( str, n );
	bubble_sort( leader, 3 );

	while( r-- ){
		int idx[ 3 ] = { 0 };
		int vec[ 3 ][ maxl ] = { 0 };
		int member[ 3 ][ maxn ] = { 0 };
		for( int i = 0; i < n; i++ ){
			int x = belong( str[ i ], leader, l );
			member[ x ][ idx[ x ]++ ] = i;
			for( int j = 0; j < l; j++ )
				vec[ x ][ j ] += (int) str[ i ][ j ];
		}
		for( int i = 0; i < 3; i++ )
			for( int j = 0; j < l; j++ )
				vec[ i ][ j ] /= idx[ i ];
		//assign new leaders
		for( int i = 0; i < 3; i++ ){
			int new_leader = find( l, str, member[ i ], idx[ i ], vec[ i ] );
			strcpy(leader[ i ], str[ new_leader ]);
		}
		bubble_sort( leader, 3 );
		//for( int i = 0; i < 3; i++ ) printf("%s\n", leader[ i ] );
	}
	for( int i = 0; i < 3; i++ ) printf("%s\n", leader[ i ] );
}