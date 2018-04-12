#include <stdio.h>
#include <string.h>
#define hmid (h)/2

char mp[ 16 ][ 128 ];
char s[ 16 ];
int w, h;

void fill_hori( int x, int y, int a ){
	for( int i = 1; i < w - 2; i++ ) mp[ y ][ x + i ] = a + '0';
}

void fill_verti( int x, int y, int a ){
	for( int i = 1; i <= ( h - 3 ) / 2; i++ ) mp[ y + i ][ x ] = a + '0';
}

void init(){
	for( int i = 0; i <128; i++ )
		for( int j = 0; j < 16; j++ )
			mp[ j ][ i ] = ' ';
}

void fill_verti_all( int a, int x ){
	fill_verti( x, 0, a );
	fill_verti( x, hmid, a );
}

void fill_hori_all( int a, int x ){
	fill_hori( x, 0, a );
	fill_hori( x, hmid, a );
	fill_hori( x, h - 1, a );
}

void fill( int a, int st ){
	int lft = st;
	int rgt = st + w - 2;
	if( a == 0 ){
		fill_hori( lft, 0, a );
		fill_hori( lft, h - 1, a );
		fill_verti_all( a, lft );
		fill_verti_all( a, rgt );
	}
	if( a == 1 ){
		fill_verti_all( a, rgt );
	}
	if( a == 2 ){
		fill_hori_all( a, lft );
		fill_verti( rgt, 0, a );
		fill_verti( lft, hmid, a );
	}
	if( a == 3 ){
		fill_hori_all( a, lft );
		fill_verti_all( a, rgt );
	}
	if( a == 4 ){
		fill_verti_all( a, rgt );
		fill_hori( lft, hmid, a );
		fill_verti( lft, 0, a );
	}
	if( a == 5 ){
		fill_hori_all( a, lft );
		fill_verti( lft, 0, a );
		fill_verti( rgt, hmid, a );
	}
	if( a == 6 ){
		fill_hori_all( a, lft );
		fill_verti_all( a, lft );
		fill_verti( rgt, hmid, a );
	}
	if( a == 7 ){
		fill_verti_all( a, rgt );
		fill_hori( lft, 0, a );
		fill_verti( lft, 0, a );
	}
	if( a == 8 ){
		fill_verti_all( a, lft );
		fill_verti_all( a, rgt );
		fill_hori_all( a, lft );
	}
	if( a == 9 ){
		fill_verti_all( a, rgt );
		fill_verti( lft, 0, a );
		fill_hori( lft, 0, a );
		fill_hori( lft, hmid, a );
	}
}

void print( int n ){
	for( int j = 0; j < h; j++ ){
		for( int i = 0; i < w * n; i++ ){
			printf("%c", mp[ j ][ i ] );
		}
		printf("\n");
	}
}

int main(){
	while( scanf("%s", s ) != EOF ){
		init();
		scanf("%d%d", &w, &h );
		int leng = strlen( s );
		for( int i = 0; i < leng; i++ ){
			fill( s[ i ] - '0', i * w );
		}
		print( leng );
	}
	return 0;
}