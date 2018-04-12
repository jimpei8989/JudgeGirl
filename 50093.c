#include <stdio.h>
#include <string.h>
#define maxn 1024

int check( char s[], int n, int x, char key[] ){
	int kl = strlen( key );
	if( x + kl > n ) return 0;
	for( int i = 0; i < kl; i++ )
		if( s[ x + i ] != key[ i ] ) return 0;
	return 1;
}

void replace( char s[], int n, int x, int rl, char key[] ){
	char first[ maxn ] = {};
	char last[ maxn ] = {};
	for( int i = 0; i < x; i++ )
		first[ i ] = s[ i ];
	for( int i = 0, j = x + rl; j < n; i++, j++ )
		last[ i ] = s[ j ];
	strcpy( s, first );
	strcat( s, key );
	strcat( s, last );
}

int main(){
	char S[ 2 * maxn ];
	scanf("%s", S );
	char ipt[ 2 * maxn ];
	while( scanf("%s", ipt ) != EOF  ){
		if( strcmp( ipt, "p" ) == 0 ){
			printf("%s\n", S );
			continue;
		}
		char key[ 2 ] = {};
		key[ 0 ] = ipt[ 1 ];
		key[ 1 ] = '\0';
		char tp[ 3 ][ maxn ];
		int cnt = 0;
		char *ptr = strtok( ipt+1, key );
		for( int i = 1; i < 3 && ptr != NULL; i++ ){
			strcpy( tp[ i ], ptr );
			ptr = strtok( NULL, key );
		}
		int n = strlen( S );
		for( int i = 0; i < n; i++ ){
			if( check( S, n, i, tp[ 1 ] ) ){
				replace( S, n, i, strlen( tp[ 1 ]), tp[ 2 ] );
				break;
			}
		}
	}
}