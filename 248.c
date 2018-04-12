#include <stdio.h>

int fill( int x, int y, int d, int mp[][] ){
	for( int di = x - 1; di <= x + 1; di ++ ){
		for( int dj = y - 1; dj <= y + 1; dj++ ){
			if( di < 0 || dj < 0 || di > 8 || dj > 8 ) continue;
			mp[ di ][ dj ] += d;
		}
	}
}

int solve( int x, int y, int mp[][], int ans[][] ){
	if( x == 9 && y == 9 )
		return check();
	if( x > 0 && y > 1 && mp[ x - 1 ][ y - 1 ] > 0 ){

	}
	else{

	}
}

int main(){
	int mp[ 9 ][ 9 ];
	int ans[ 9 ][ 9 ] = { 0 };
	for( int i = 0; i < 9; i++ )
		for( int j = 0; j < 9; j++ )
			scanf("%d", &mp[ i ][ j ] );
	if( solve( 0, 0, mp, ans ) )
		printans();
	else printf("no solution\n");
}