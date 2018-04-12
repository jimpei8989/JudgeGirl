#include <stdio.h>
#define MAXN 512

int N, M, L, W;
int mp[ MAXN ][ MAXN ];

int di[ 6 ] = { 0, 0, 1, 0, -1, 1 };
int dj[ 6 ] = { 0, 1, 0, -1, 0, 1 };

void print(){
	for( int i = 0; i < N; i++ ){
		for( int j = 0; j < M; j++ ){
			printf("%d", mp[ i ][ j ] );
		}
		printf("\n");
	}
}

int main(){
	scanf("%d%d%d%d", &N, &M, &L, &W );
	int o;
	scanf("%d", &o );
	while( o-- ){
		int i, j;
		scanf("%d%d", &j, &i );
		mp[ i ][ j ] = 2;
	}
	for( int i = 0; i < L; i++ )
		for( int j = 0; j < W; j++ )
			mp[ i ][ j ] = 1;

	int cmd;
	int ni = 0, nj = 0;
	while( scanf("%d", &cmd ) != EOF ){
		if( cmd == 0 ){
			print();
			continue;
		}
		int upp = ni;
		int dwn = ni + L - 1;
		int lft = nj;
		int rgt = nj + W - 1;
		int use_big = 1 - ( (cmd-1) / 2 );
		if( cmd == 5 ) use_big = 1;
		if( upp + di[ cmd ] < 0 || dwn + di[ cmd ] >= N ) continue;
		if( lft + dj[ cmd ] < 0 || rgt + dj[ cmd ] >= M ) continue;

		int cnt = 0;
		if( cmd % 2 == 1 || cmd == 5 ){
			//check rgt & lft
			for( int i = upp; i <= dwn; i++ ){
				if( use_big == 0 )
					cnt += mp[ i + ( cmd / 5 ) ][ lft + dj[ cmd ] ] / 2;
				else
					cnt += mp[ i + ( cmd / 5 ) ][ rgt + dj[ cmd ] ] / 2;
			}
		}
		if( cmd % 2 == 0 || cmd == 5 ){
			//check upp and dwn
			for( int j = lft; j <= rgt; j++ ){
				if( use_big == 0 )
					cnt += mp[ upp + di[ cmd ] ][ j + (cmd / 5) ] / 2;
				else
					cnt += mp[ dwn + di[ cmd ] ][ j + (cmd / 5) ] / 2;
			}
		}
		if( cmd == 5 )
			if( mp[ dwn + 1 ][ rgt + 1 ] == 2 )
				cnt --;
		if( cnt > 1 ) continue;
		
		if( cmd % 2 == 1 || cmd == 5){
			//update lft and rgt
			for( int i = upp; i <= dwn; i++ ){
				mp[ i + cmd / 5 ][ nj + use_big * ( W + 1 ) - 1 ] = 1;
				mp[ i ][ nj + W - 1 - use_big*( W - 1 ) ] = 0;
			}
		}
		if( cmd % 2 == 0 || cmd == 5 ){
			//update upp and dwn
			for( int j = lft; j <= rgt; j++ ){
				mp[ ni + use_big * ( L + 1 ) - 1 ][ j + cmd / 5 ] = 1;
				mp[ ni + L - 1 - use_big*( L - 1 ) ][ j ] = 0;
			}
		}
		ni += di[ cmd ];
		nj += dj[ cmd ];
	}
}