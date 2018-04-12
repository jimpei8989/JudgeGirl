#include <stdio.h>
typedef unsigned int ui;

void print( ui ipt, int *last, int *cnt ){
	ui k = 1 << 31;
	while( k > 0 ){
		int now = ( k & ipt ? 1 : 0 );
		if( now != *last && *last != -1 ){
			putchar( '\n' );
			for( int i = 0; i < (*cnt) % 40; i++ )
				putchar( ' ' );
		}
		putchar( now + '0' );
		*last = now;
		*cnt = ( *cnt + 1 ) % 40;
		k >>= 1;
	}
}

int main(){
	int n;
	scanf("%d", &n );
	char ans[ (1 << 20) ] = { 0 };
	int last = -1;
	int cnt = 0;
	for( int i = 0; i < n; i++ ){
		ui ipt;
		scanf("%u", &ipt );
		print( ipt, &last, &cnt );
	}
	printf("\n");
}