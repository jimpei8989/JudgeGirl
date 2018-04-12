#include <stdio.h>
#include <string.h>

char storage[ 1024 ][ 256 ];

void print( int k, int cnt, int n ){
	if( k == 1 ){
		printf("%s", storage[ 0 ] );
		for( int i = cnt; i < n; i++ )
			printf(" ");
		printf("\n");
		return;
	}

	int spaces = n  - cnt;
	for( int i = 0; i < k; i++ ){
		printf("%s", storage[ i ] );
		if( i == k - 1 ) break;
		for( int j = 0; j < ( spaces / ( k - 1 ) + ( i < spaces%(k-1) ) ); j++ )
			printf(" ");
	}
	printf("\n");
}

int main(){
	int n;
	scanf("%d", &n );
	int cnt = 0;
	int idx = 0;
	char ipt[ 256 ];
	while( scanf("%s", ipt ) != EOF ){
		int x = strlen( ipt );

		if( x > n ){
			print( idx, cnt, n );
			printf("%s\n", ipt );
			cnt = idx = 0;
			continue;
		}

		if( cnt + x + idx <= n );
		else{
			print( idx, cnt, n );
			cnt = idx = 0;
		}
		strcpy( storage[ idx++ ], ipt );
		cnt += x;
	}
	print( idx, cnt, n );
	return 0;
}
