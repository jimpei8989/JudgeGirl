#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 50000

int c_to_i( char *ipt, int N ){
	if( strcmp( ipt, "left" ) == 0 ) return 0;
	if( strcmp( ipt, "right" ) == 0 ) return N;
	return atoi( ipt ) - 1;
}

void insert( char *s, int k, char x, int *N ){
	for( int i = *N - 1; i >= k; i-- )
		s[ i + 1 ] = s[ i ];
	s[ k ] = x;
	(*N)++;
}

void delete( char *s, int k, int *N ){
	for( int i = k; i < *N - 1; i++ )
		s[ i ] = s[ i + 1 ];
	(*N)--;
}

void print( char *s, int N ){
	s[ N ] = '.';
	int big = 0;
	char tp[ MAXN ];
	int idx = 0;
	char prev = s[ 0 ];
	int cnt = 1;
	for( int i = 1; i <= N; i++ ){
		if( prev == s[ i ] ) cnt ++;
		else{
			if( cnt > big ){
				idx = 0;
				big = cnt;
			}
			if( big == cnt )
				tp[ idx++ ] = prev;

			prev = s[ i ];
			cnt = 1;
		}
	}
	for( int i = 0; i < idx; i++ )
		printf("%c ", tp[ i ] );
	printf("%d\n", big );
}

int main(){
	int N = 0;
	char str[ MAXN ];
	char cmd[ 1000 ];
	while( scanf("%s", cmd ) != EOF ){
		if( strcmp( cmd, "insert" ) == 0 ){
			char target[ 1000 ], x;
			scanf("%s", target );
			while( scanf("%c", &x) != EOF )
				if( x != ' ' )
					break;
			int k = c_to_i( target, N );
			insert( str, k, x, &N );
			//printf("insert done\n");
		}
		else{
			char target[ 1000 ];
			scanf("%s", target );
			int k = c_to_i( target, N );
			delete( str, k, &N );
			//printf("delete done\n");
		}
		/*
		for( int i = 0; i < N; i++ )
			printf("%c", str[ i ] );
		printf("\n");
		*/
	}
	print( str, N );
}