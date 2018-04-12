#include <stdio.h>
#include <string.h>
#define maxn 128
#define maxl 16
int leng[ maxn ];
char str[ maxn ][ maxl ];
int dp[ maxn ][ maxn ][ maxl ][ maxl ];

void solve( int x, int y ){
	int xl = leng[ x ], yl = leng[ y ];
	for( int i = 0; i <= xl; i++ )
		dp[ x ][ y ][ i ][ 0 ] = i;
	for( int j = 0; j <= yl; j++ )
		dp[ x ][ y ][ 0 ][ j ] = j;
	for( int i = 1; i <= xl; i++ ){
		for( int j = 1; j <= yl; j++ ){
			if( str[ x ][ i-1 ] == str[ y ][ j-1 ] )
				dp[ x ][ y ][ i ][ j ] = dp[ x ][ y ][ i - 1 ][ j - 1 ];
			else{
				dp[ x ][ y ][ i ][ j ] = 100000+ 1;
				if( dp[ x ][ y ][ i ][ j ] > dp[ x ][ y ][ i ][ j - 1 ] + 1 )
					dp[ x ][ y ][ i ][ j ] = dp[ x ][ y ][ i ][ j - 1 ] + 1;
				if( dp[ x ][ y ][ i ][ j ] > dp[ x ][ y ][ i - 1 ][ j ] + 1 )
					dp[ x ][ y ][ i ][ j ] = dp[ x ][ y ][ i - 1 ][ j ] + 1;
			}
		}
	}
}

int main(){
	int n = 0;
	while( scanf("%s", str[ n ] ) != EOF ){
		leng[ n ] = strlen( str[ n ] );
		n++;
	}
	for( int i = 0; i < n; i++ ){
		for( int j = i + 1; j < n; j++ ){
			solve( i, j );
		}
	}
	int min = 2147483647;
	int mini = -1, minj = -1;
	for( int i = 0; i < n; i++ ){
		for( int j = i + 1; j < n; j++ ){
			//printf("i = %d, j = %d, ed = %d\n", i, j, dp[ i ][ j ][ leng[ i ] ][ leng[ j ] ] );
			if( min > dp[ i ][ j ][ leng[ i ] ][ leng[ j ] ] ){
				min = dp[ i ][ j ][ leng[ i ] ][ leng[ j ] ];
				mini = i;
				minj = j;
			}
		}
	}
	printf("%d %d %d\n", min, mini+1, minj+1 );
}