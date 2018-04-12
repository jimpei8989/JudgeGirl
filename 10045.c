#include <stdio.h>
#include <stdlib.h>

int g( int x ){
	if( x <= 2 ) return x*x - 1;
	else return 2;
}

int h( int x ){
	if( x < 2 ) return -1;
	else return 2 + h( x - 1 ) - h( x - 2 ) ;
}

int f( int x ){
	if( x > h( x ) ){
		return f( x - 1 ) - h( x );
	}
	else if( x == h( x ) ){
		return 1;
	}
	else{
		int tp = g( x );
		return f( tp ) - tp;
	}
}

int main(){
	int x;
	scanf("%d", &x );
	printf("%d\n", f( x ) );
}