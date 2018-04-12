#define nk ( k + 1 ) % 4
int map[ 1 << 10 ][ 1 << 10 ];

void snail( int N, int map[ 1 << 10 ][ 1 << 10 ] ){
	for( int i = 0; i < N; i++ )
		for( int j = 0; j < N; j++ )
			map[ i ][ j ] = -1;
	int di[ 4 ] = { 0, -1, 0, 1 };
	int dj[ 4 ] = { -1, 0, 1, 0 };
	int k = 0;
	int now = 0;
	int ni, nj;
	ni = nj = N / 2;
	while( now < N * N ){
		map[ ni ][ nj ] = now++;
		ni += di[ k ];
		nj += dj[ k ];
		if( map[ ni + di[ nk ] ][ nj + dj[ nk ] ] == -1 )
			k = nk;
	}
}

void SpiralSnake(int N, int *snake, int *result){
	for( int i = 0; i < N; i++ )
		for( int j = 0; j < N; j++ )
			map[ i ][ j ] = 0;
	snail( N, map );
	for( int i = 0; i < N; i++ )
		for( int j = 0; j < N; j++ )
			result[ i * N + j ] = snake[ map[ i ][ j ] ];
}