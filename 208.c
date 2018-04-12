#include <stdio.h>
typedef unsigned int ui;

int main(){
	int w, l;
	char give[ 2 ];
	ui uis[ 1024 ];
	scanf("%d%d", &w, &l );
	int n = 0;
	char tp;
	while( scanf("%c", &tp ) != EOF ){
		if( tp == ' ' || tp == '\n' ) continue;
		give[ 1 - n ] = tp;
		n++;
		if( n == 2 ) break;
	}
	n = ( w * l - 1 ) / 32 + 1;
	for( int i = 0; i < n; i++ ) scanf("%u", &uis[ i ] );

#ifdef Debug
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < 32; j++ ){
			printf("%d", (uis[ i ] >> ( 31 - j )) % 2 );
		}
		printf("\n");
	}
#endif

	int idx = -1;
	for( int i = 0; i < w * l; i++ ){
		if( i % 32 == 0 ) idx++;
		printf("%c", give[ (uis[ idx ]>>(31 - (i%32) )) % 2 ] );
		if( i%w == w - 1 ) printf("\n");
	}
	return 0;
}