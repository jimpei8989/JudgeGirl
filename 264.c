#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn ( 1 << 16 )

typedef unsigned short int usi;

unsigned int cnt[ maxn ];

int main(){
	char ipt[ 256 ];
	while( fscanf( stdin, "%s", ipt ) != EOF ){
		FILE *fin;
		fin = fopen( ipt, "rb" );
		int N;
		fread( &N, 4, 1, fin );
		for( int i = 0; i < N; i++ ){
			short int buf;
			fread( &buf, 2, 1, fin );
			cnt[ (usi) buf ]++;
		}
		int maxidx = 32767;
		for( int i = 32767; i >= -32768; i-- ){
			if( cnt[ (usi)i ] > cnt[ (usi)maxidx ] )
				maxidx = i;
		}
		printf("%d\n%d\n", maxidx, cnt[ (usi)maxidx ] );
	}
}