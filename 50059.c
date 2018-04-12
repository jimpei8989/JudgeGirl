#include <stdio.h>
typedef unsigned int ui;

void print( int arr[], char key[] ){
	int tp = 0;
	for( int i = 0; i < 5; i++ ){
		tp = tp * 2 + arr[ i ];
	}
	putchar( key[ tp ] );
}

int main(){
	char key[ 1 << 6 ];
	int arr[ 5 ];
	scanf("%s", key );
	int n;
	scanf("%d", &n );
	int cnt = 0;
	while( n-- ){
		ui ipt, k = 1 << 31;
		scanf("%u", &ipt );
		while( k > 0 ){
			arr[ cnt++ ] = ( ipt & k ? 1 : 0 );
			if( cnt == 5 ){
				cnt = 0;
				print( arr, key );
			}
			k >>= 1;
		}
	}
	putchar( '\n' );
	return 0;
}