#include <stdio.h>

int a[ 3 ], b[ 3 ], c[ 3 ];

int find( int x, int y, int z ){
	if( x < 0 || y < 0 || z < 0 ) return 0;
	if( x == 0 && y == 0 && z == 0 ) return 1;
	int flag = 0;
	flag += find( x - a[ 0 ], y - b[ 0 ], z - c[ 0 ] );
	flag += find( x - a[ 1 ], y - b[ 1 ], z - c[ 1 ] );
	flag += find( x - a[ 2 ], y - b[ 2 ], z - c[ 2 ] );
	return flag;
}

void solve( Q ){
	if( Q == 0 ) return;
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C );
	if( find( A, B, C ) ) printf("yes\n");
	else printf("no\n");
	solve( Q - 1 );
}

int main(){
	int i = 0;
	scanf("%d%d%d", &a[ i ], &b[ i ], &c[ i ] );
	i++;
	scanf("%d%d%d", &a[ i ], &b[ i ], &c[ i ] );
	i++;
	scanf("%d%d%d", &a[ i ], &b[ i ], &c[ i ] );
	int Q;
	scanf("%d", &Q );
	solve( Q );
}