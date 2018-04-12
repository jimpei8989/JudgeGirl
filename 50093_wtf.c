#include <stdio.h>
#include <string.h>
#include <assert.h>
#define maxn 1024

int my_fgets( char *s ){
	for( int i = 0; i < 2*maxn; i++ ) s[ i ] = '\0';
	int n = 0;
	char c;
	while( scanf("%c", &c ) != EOF ){
		s[ n++ ] = c;
		if( c == '\n' ){
			s[ n - 1 ] = '\0';
			return n;
		}
	}
	return 0;
}

int check( char *s, int *n, int x, char *key ){
	int kl = strlen( key );
	if( x + kl > *n ) return 0;
	for( int i = 0; i < kl; i++ ){
		if( s[ x + i ] != key[ i ] ) return 0;
	}
	for( int j = x; j < *n; j++ ){
		s[ j ] = s[ j + kl ];
	}
	for( int i = *n - kl; i < 2 * maxn; i++ )
		s[ i ] = '\0';
	*n -= kl;
	return 1;
}

void replace( char *s, int *n, int x, char *key ){
	int kl = strlen( key );
	for( int i = *n - 1; i >= x; i-- )
		s[ i + kl ] = s[ i ];
	for( int i = 0; i < kl; i++ )
		s[ x + i ] = key[ i ];
	*n += kl;
}

void print( char *str, int n ) {
	for( int i = 0; i < n; i++ ) putchar( str[ i ] );
	puts("");
}

int main(){
	char S[ 2 * maxn ];
	my_fgets( S );
	int n = strlen( S );

	char ipt[ 2 * maxn ];
	while( my_fgets( ipt ) ){
		if( strcmp( ipt, "p" ) == 0 ){
			print( S, n );
			continue;
		}
		char key[ 10 ];
		key[ 0 ] = ipt[ 1 ];
		char tp[ 3 ][ maxn ];
		int cnt = 0;
		char *ptr = strtok( ipt, key );
		while( ptr != NULL ){
			strcpy( tp[ cnt++ ], ptr );
			ptr = strtok( NULL, key );
		}
		for( int i = 0; i < n; i++ ){
			if( check( S, &n, i, tp[ 1 ] ) ){
				replace( S, &n, i, tp[ 2 ] );
				break;
			}
		}
	}
}