#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn ( 1 << 8 )
#define maxl ( 1 << 6 )


int is_substring( char *a, char *b ){
	int la = strlen( a );
	int lb = strlen( b );
	for( int i = 0; i <= la - lb; i++ ){
		char tmp[ maxl ] = { 0 };
		strncpy( tmp, a + i, lb );
		if( strcmp( tmp, b ) == 0 )
			return 1;
	}
	return 0;
}

int main(){
	int N; scanf("%d", &N );
	char dict[ maxn ][ maxl ];
	for( int i = 0; i < N; i++ )
		scanf("%s", dict[ i ] );
	int Q; scanf("%d", &Q );
	while( Q-- ){
		char str[ maxl ];
		scanf("%s", str );
		int cnt = 0;
		for( int i = 0; i < N; i++ )
			if( is_substring( dict[ i ], str ) ) cnt++;
		printf("%d\n", cnt );
	}
}