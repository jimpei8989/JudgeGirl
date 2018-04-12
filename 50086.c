#include <stdio.h>

int rela[ 1 << 15 ][ 1 << 8 ];
int go[ 1 << 15 ];
int idx[ 1 << 15 ];

int main(){
	int n, m;
	scanf("%d%d", &n, &m );
	for( int i = 0; i < m; i++ ){
		int a, b;
		scanf("%d%d", &a, &b );
		rela[ a ][ idx[ a ]++ ] = b;
		rela[ b ][ idx[ b ]++ ] = a;
	}
	int q;
	while( scanf("%d", &q ) != EOF ){
		go[ q ] = 1;
		for( int i = 0; i < idx[ q ]; i++ ){
			go[ rela[ q ][ i ] ] = 1;
		}
	}
	for( int i = 0; i < n; i++ ){
		if( go[ i ] == 0 ){
			printf("%d\n", i );
		}
	}
}