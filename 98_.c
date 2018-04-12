#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 128

int num[ maxn ];
char name[ maxn ][ maxn ];
char ing[ maxn ][ maxn ][ maxn ];

int cmp( const void *a, const void *b ){
	return strcmp( *(char**)a, *(char**)b );
}

int main(){
	int n;
	scanf("%d", &n );
	for( int i = 0; i < n; i++ ){
		scanf("%s", name[ i ] );
		scanf("%d", &num[ i ] );
		for( int j = 0; j < num[ i ]; j++ ) scanf("%s", ing[ i ][ j ] );
		for( int j = 0; j < num[ i ]; j++ ) printf("%s\n", ing[ i ][ j ] );
		qsort( ing[ i ], num[ i ], sizeof( char* ), cmp );
		printf("sort done\n");
		for( int j = 0; j < num[ i ]; j++ ) printf("%s\n", ing[ i ][ j ] );
	}
	//input done
	int k;
	scanf("%d", &k );
	while( k -- ){
		char a[ maxn ], b[ maxn ];
		scanf("%s%s", a, b );
		int idxa, idxb;
		for( int j = 0; j < n; j++ ){
			if( strcmp( a, name[ j ] ) == 0 ) idxa = j;
			if( strcmp( b, name[ j ] ) == 0 ) idxb = j;
		}
		printf("%d %d\n", idxa, idxb );
		char tp[ maxn ][ maxn ] = {};
		int na = num[ idxa ], nb = num[ idxb ];
		for( int i = 0; i < na; i++ )
			strcpy( tp[ i ], ing[ idxa ][ i ] );
		for( int j = 0; j < nb; j++ )
			strcpy( tp[ na + j ], ing[ idxb ][ j ] );
		printf("before sort\n");
		qsort( tp, na+nb, sizeof( char* ), cmp );
		printf("sort done\n");
		int cnt = 0;
		for( int i = 0; i < na+nb - 1; i++ ){
			if( strcmp( tp[ i ], tp[ i + 1 ] ) == 0 ){
				if( cnt++ ) printf(" ");
				printf("%s", tp[ i ] );
			}
		}
		if( cnt == 0 ) printf("nothing");
		printf("\n");
	}
	return 0;

}