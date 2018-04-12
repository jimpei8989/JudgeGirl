#include <stdio.h>
#include <string.h>

int is( char c ){
	if( '0' <= c && c <= '9' ) return c - '0';
	if( 'A' <= c && c <= 'Z' ) return c - 'A' + 10;
	if( 'a' <= c && c <= 'z' ) return c - 'a' + 36;
	return -1;
}

int check( char *s, int x ){
	int cnt[ 64 ] = { 0 };
	int sum = 0;
	for( int i = 0; i < 7; i++ ){
		if( i == x ) continue;
		int k = is( s[ i ] );
		if( k == -1 || cnt[ k ] == 2 ) return 0;
		else cnt[ k ]++;
		if( i >= 1 && s[ i ] == '4' && s[ i - 1 ] == '4' ) return 0;
		if( k <= 9 ) sum += k;
	}
	return sum % 7;
}

void bubble_sort( char s[ 32 ][ 8 ], int n ){
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < n - 1; j++ ){
			if( strcmp( s[ j ], s[ j + 1 ] ) > 0 ){
				char tp[ 8 ];
				strcpy( tp, s[ j ] );
				strcpy( s[ j ], s[ j + 1 ] );
				strcpy( s[ j + 1 ], tp );
			}
		}
	}
}

int main(){
	int n;
	char str[ 32 ][ 8 ];
	char type1[ 32 ][ 8 ];
	char type2[ 32 ][ 8 ];
	int idx1 = 0, idx2 = 0;
	scanf("%d", &n );
	for( int i = 0; i < n; i++ ){
		scanf("%s", str[ i ] );
		if( str[ i ][ 2 ] == '-' ){
			if( !check( str[ i ], 2 ) ) continue;
			strcpy( type1[ idx1++ ], str[ i ] );
		}
		if( str[ i ][ 3 ] == '-' ){
			if( !check( str[ i ], 3 ) ) continue;
			strcpy( type2[ idx2++ ], str[ i ] );
		}
	}
	bubble_sort( type1, idx1 );
	for( int i = 0; i < idx1; i++ )
		printf("%s\n", type1[ i ] );
	bubble_sort( type2, idx2 );
	for( int i = 0; i < idx2; i++ )
		printf("%s\n", type2[ i ] );
	return 0;
}