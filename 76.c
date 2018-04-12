#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp( const void *a, const void *b ){
	return strcmp( *(char**)a, *(char**)b );
}

int main(){
	char ipt[ 64 ];
	char *str[ 64 ];
	int n = 0;
	while( fgets( ipt, 64, stdin ) != NULL ){
		char *tp = (char*) malloc( sizeof(char) * ( strlen( ipt ) + 1 ) );
		strcpy( tp, ipt );
		str[ n++ ] = tp;
	}
	qsort( str, n, sizeof( char* ), cmp );
	for( int i = 0; i < n; i++ )
		printf("%s", str[ i ] );
}