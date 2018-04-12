#include <stdio.h>
typedef unsigned char uc;

uc Mirror( uc tmp ){
	uc x = 0;
	for( int i = 0; i < 8; i++ )
		x |= ( (tmp >> i ) & 1 ) << ( 7 - i );
	return x;
}

int main(){
	char input[ 16 ], output[ 16 ];
	int shift;
	scanf("%s%s%d", input, output, &shift );
	FILE *fin = fopen( input, "rb" );
	FILE *fout = fopen( output, "w" );
	int N = 0;
	uc tmp;
	while( fread( &tmp, sizeof( uc ), 1, fin ) == 1 ) N++;
	for( int i = 0; i < N; i++ ){
		int tar = ( N + N - i - shift - 1 ) % N;
		fseek( fin, tar, SEEK_SET );
		fread( &tmp, sizeof( uc ), 1, fin );
		tmp = Mirror( tmp );
		fwrite( &tmp, sizeof( uc ), 1, fout );
	}
	return 0;
}