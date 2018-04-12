#include <stdio.h>
#include <string.h>

int mp[ 26 ][ 26 ];
int visit[ 26 ];
int main(){
	int T;
	scanf("%d", &T );
	char str[ 1<<7 ];
	while( scanf("%s", str ) != EOF ){
		int n = strlen( str );
		for( int i = 0; i < n-1; i++ ){
			mp[ str[ i ] - 'a' ][ str[ i + 1 ] - 'a' ]++;
		}
	}
	for( int i = 0; i < 26; i++ )
		for( int j = 0; j < 26; j++ )
			printf("%d%c", mp[ i ][ j ], " \n"[ j == 25 ] );
	char ans[ 32 ] = { 0 };
	int ans_idx = 1;
	int nxt = -1;
	int now = -1;
	int max = 0;

	for( int i = 0; i < 26; i++ ){
		for( int j = 0; j < 26; j++ ){
			if( i == j ) continue;
			if( mp[ i ][ j ] > max ){
				max = mp[ i ][ j ];
				now = i;
				nxt = j;
			}
		}
	}
	visit[ now ] = 1;
	ans[ 0 ] = 'a' + now;
	now = nxt;
	while( now != -1 ){
		visit[ now ] = 1;
		ans[ ans_idx++ ] = 'a' + now;

		nxt = -1;
		max = T;
		for( int i = 0; i < 26; i++ ){
			if( !visit[ i ] ){
				if( mp[ now ][ i ] > max ){
					nxt = i;
					max = mp[ now ][ i ];
				}
			}
		}
		now = nxt;
	}
	printf("%s\n", ans );
}