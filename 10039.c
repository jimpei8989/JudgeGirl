#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn ( 1 << 5 )
#define maxl ( 1 << 17 )

char par[ maxn ];

int main(){
	for( int i = 0; i < maxn; i++ )
		par[ i ] = i + 'A';
	char str[ maxl ];
	scanf("%s", str );
	int N; scanf("%d", &N );
	while( N-- ){
		char A, B;
		scanf(" %c %c", &A, &B );
		for( int i = 0; i < maxn; i++ )
			par[ i ] = ( par[ i ] == B ? A : par[ i ] );
	}
	int L = strlen( str );
	for( int i = 0; i < L; i++ )
		str[ i ] = par[ str[ i ] - 'A' ];
	printf("%s\n", str );
}