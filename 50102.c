#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define maxn (1<<12)

typedef unsigned char uc;

int max( int a, int b ){
	return a > b ? a : b;
}

uc f( uc G, uc a, uc b ){
	const uc k = ( 1 << 7 ) - 1;
	uc tp = ((a & k) + (b & k) + G) >> 7;
	return ( tp + ( a >> 7 ) + ( b >> 7 ) ) >> 1;
}

int main(){
	char input_A[ 32 ], input_B[ 32 ], output[ 32 ];
	scanf("%s%s%s", input_A, input_B, output );
	FILE *fin_A = fopen( input_A, "rb" );
	FILE *fin_B= fopen( input_B, "rb" );
	FILE *fout = fopen( output, "wb" );

#ifdef RE40
	int size_A = 0, size_B = 0;
	while( fread( &A[ size_A ], sizeof( uc ), 1, fin_A ) == 1 ) size_A ++;
	while( fread( &B[ size_B ], sizeof( uc ), 1, fin_B ) == 1 ) size_B ++;
	int N = max( size_A, size_B );
	uc G = 0;
	for( int i = 0; i < N; i++ ){
		uc tA = (i < size_A) ? A[ size_A - 1 - i ] : 0;
		uc tB = (i < size_B) ? B[ size_B - 1 - i ] : 0;
		opt[ N - 1 - i ] = ( G + tA + tB );
		G = f( G, tA, tB );
	}
	for( int i = 0; i < N; i++ )
		fprintf( fout, "%c", opt[ i ] );
	return 0;
#endif

	int size_A = 0, size_B = 0;
	uc tmp;
	while( fread( &tmp, sizeof( uc ), 1, fin_A ) == 1 ) size_A ++;
	while( fread( &tmp, sizeof( uc ), 1, fin_B ) == 1 ) size_B ++;
	int N = max( size_A, size_B );
	for( int i = 0; i < N; i++ )
		fprintf( fout, "%c", 0 );
	fseek( fin_A, 0, SEEK_END );
	fseek( fin_B, 0, SEEK_END );
	fseek( fout, 0, SEEK_END );
	uc G = 0;
	for( int i = 0; i < N; i++ ){
		int deltap = i == 0 ? -1 : -2;
		uc tA = 0, tB = 0, opt = 0;
		if( i < size_A ){
			fseek( fin_A, deltap, SEEK_CUR );
			fread( &tA, sizeof( uc ), 1, fin_A );
		}
		if( i < size_B ){
			fseek( fin_B, deltap, SEEK_CUR );
			fread( &tB, sizeof( uc ), 1, fin_B );
		}
		opt = ( G + tA + tB );
		G = f( G, tA, tB );

		fseek( fout, deltap, SEEK_CUR );
		fwrite( &opt, sizeof( uc ), 1, fout );
	}
	return 0;
}