#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N;
	FILE *file[ 16 ];
	scanf("%d", &N );
	for( int i = 0; i < N; i++ ){
		char ipt[ 16 ];
		scanf("%s", ipt );
		file[ i ] = fopen( ipt, "rb" );
	}
	int head[ 16 ];
	int end[ 16 ] = { 0 };
	for( int i = 0; i < N; i++ ){
		fread( &head[ i ], sizeof( int ), 1, file[ i ] );
	}
	int remain = N;
	while( remain > 0 ){
		int minid = -1;
		for( int i = 0; i < N; i++ )
			if( !end[ i ] && (minid == -1 || head[ i ] < head[ minid ]) )
				minid = i;
		printf("%d\n", head[ minid ] );
		if( fread( &head[ minid ], sizeof( int ) , 1, file[ minid ] ) != 1 ){
			end[ minid ] = 1;
			remain --;
		}
	}
}