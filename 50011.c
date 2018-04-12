#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 100000 + 10
#define maxw 128

char dic[ maxn ][ maxw ];
int leng[ maxn ];

int valid( char *A, int a, char *B, int b ){
	int idxa = 0;
	int idxb = 0;
	int cnt = 0;
	if( a == b )
		for( int i = 0; i < a; i++ )
			cnt += ( A[ i ] != B[ i ] );
	if( a < b ){
		while( idxa < a && idxb < b ){
			while( A[ idxa ] != B[ idxb ] && idxb < b ){
				cnt++;
				idxb++;
			}
			idxa++;
			idxb++;
		}
		cnt += abs( ( a - idxa ) - ( b - idxb ) );
	}
	if( a > b ){
		while( idxa < a && idxb < b ){
			while( A[ idxa ] != B[ idxb ] && idxa < a ){
				cnt++;
				idxa++;
			}
			idxa++;
			idxb++;
		}
		cnt += abs( ( a - idxa ) - ( b - idxb ) );
	}
	return cnt <= 1; 
}

int main(){
	int n, Q;
	scanf("%d", &n );
	for( int i = 0; i < n; i++ ){
		scanf("%s", dic[ i ] );
		leng[ i ] = strlen( dic[ i ] );
	}
	scanf("%d", &Q );
	while( Q-- ){
		int flag = 0;
		char text[ maxw ];
		scanf("%s", text );
		int lt = strlen( text );
		for( int i = 0; i < n; i++ ){
			if( strcmp( text, dic[ i ] ) == 0 ){
				flag ++;
				printf(">%s\n", text );
			}
		}
		if( flag ) continue;
		for( int i = 0; i < n; i++ ){
			if( abs( leng[ i ] - lt ) > 1 ) continue;
			if( valid( dic[ i ], leng[ i ], text, lt ) )
				printf("%c%s", " ?"[ (flag++) == 0 ], dic[ i ] );
		}
		if( flag ){
			printf("\n");
			continue;
		}
		printf("!%s\n", text );
	}
}