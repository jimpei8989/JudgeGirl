#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 16384
#define maxm 1024

char ipt[ maxm*maxm ];

char** process_ipt( char* ipt ){
	int cnt = 1, idx = 0;
	int leng = strlen( ipt );
	for( int i = 0; i < leng; i++ )
		if( ipt[ i ] == ' ' ) cnt++;
	char **ret = (char**)malloc( sizeof( char* )*( cnt + 1 ) );
	ret[ cnt ] = NULL;
	//split
	char *ptr = strtok( ipt, " \n" );
	while( ptr != NULL ){
		int l = strlen( ptr );
		char* tp = (char*) malloc( sizeof( char )*( l + 1 ) );
		strcpy( tp, ptr );
		ret[ idx++ ] = tp;
		ptr = strtok( NULL, " \n" );
	}
	return ret;
}

void print( char ***tp ){
	for( int i = 0; tp[ i ] != NULL; i++ ){
		for( int j = 0; tp[ i ][ j ] != NULL; j++ ){
			if( j ) printf(" ");
			printf("%s", tp[ i ][ j ] );
		}
		printf("\n");
	}
}

void swap( char **a, char **b ){
	char **t = *a;
	*a = *b;
	*b = t;
}

int main(){
	int N;
	scanf("%d\n", &N );
	char ***ptr = (char***) malloc( sizeof( char**) * ( N + 1 ) );
	ptr[ N ] = NULL;
	for( int i = 0; i < N; i++ ){
		fgets( ipt, maxm*maxm, stdin );
		ptr[ i ] = process_ipt( ipt );
	}
	int Q;
	scanf("%d", &Q );
	while( Q-- ){
		int ai, aj, bi, bj;
		scanf("%d%d%d%d", &ai, &aj, &bi, &bj );
		swap( &ptr[ ai ][ aj ], &ptr[ bi ][ bj ] );
	}
	print( ptr );
}