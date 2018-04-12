const int di[ 8 ] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dj[ 8 ] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void game_of_cell(int grid[50][50],int outcome[50][50],int N){
	int tp[ 2 ][ 50 ][ 50 ] = { 0 };
	for( int i = 0; i < 50; i++ )
		for( int j = 0; j < 50; j++ )
			tp[ 0 ][ i ][ j ] = grid[ i ][ j ];
	for( int t = 1; t <= N; t++ ){
		int now = t % 2;
		int prev = 1 - now;
		for( int i = 0; i < 50; i++ ){
			for( int j = 0; j < 50; j++ ){
				int cnt = 0;
				for( int k = 0; k < 8; k++ ){
					if( i + di[ k ] < 0 || i + di[ k ] > 49 ) continue;
					if( j + dj[ k ] < 0 || j + dj[ k ] > 49 ) continue;
					cnt += (tp[ prev ][ i + di[ k ] ][ j + dj[ k ] ] >> 1);
				}
				if( tp[ prev ][ i ][ j ] == 2 ){
					if( cnt < 2 ) tp[ now ][ i ][ j ] = 0;
					else if( cnt > 3 ) tp[ now ][ i ][ j ] = 1;
					else tp[ now ][ i ][ j ] = tp[ prev ][ i ][ j ];
				}
				if( tp[ prev ][ i ][ j ] == 1 ){
					if( cnt == 2 ) tp[ now ][ i ][ j ] = 2;
					else tp[ now ][ i ][ j ] = 1;
				}
				if( tp[ prev ][ i ][ j ] == 0 ){
					if( cnt == 3 ) tp[ now ][ i ][ j ] = 2;
					else tp[ now ][ i ][ j ] = 0;
				}
			}
		}
	}
	for( int i = 0; i < 50; i++ )
		for( int j = 0; j < 50; j++ )
			outcome[ i ][ j ] = tp[ N % 2 ][ i ][ j ];

}