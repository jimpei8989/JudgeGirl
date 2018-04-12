#include <stdio.h>
#include <string.h>
typedef long long ll;

int change[ 64 ];
int visit[ 32 ];
char ipta[ 16 ], iptb[ 16 ], iptp[ 32 ];
char ipt[ 64 ];
int la, lb, lp, l;

int digit[ 32 ];

int is_char( char c ){
	return 'A' <= c && c <= 'Z';
}

int is_int( char c ){
	return '0' <= c && c <= '9';
}

void pre(){
	la = strlen( ipta );
	lb = strlen( iptb );
	lp = strlen( iptp );
	strcpy( ipt, ipta );
	strcat( ipt, iptb );
	strcat( ipt, iptp );
	l = strlen( ipt );
	for( int i = 0; i < l; i++ ){
		if( is_char( ipt[ i ] ) && !visit[ ipt[ i ] - 'A' ] ){
			visit[ ipt[ i ] - 'A' ] = 1;
			change[ i ] = 1;
		}
	}
}

ll a_to_i( char *s, int n ){
	ll x = 0;
	for( int i = 0; i < n; i++ ){
		x *= 10;
		if( is_int( s[ i ] ) ) x += ( s[ i ] - '0' );
		else x += digit[ s[ i ] - 'A' ];
	}
	return x;
}

int check(){
	ll a = a_to_i( ipta, la );
	ll b = a_to_i( iptb, lb );
	ll p = a_to_i( iptp, lp );
	return a * b == p ? 1 : 0;
}

int recur( int now ){
	if( now == l ) return check();
	if( change[ now ] == 0 ) return recur( now + 1 );
	for( int i = 0; i < 10; i++ ){
		digit[ ipt[ now ] - 'A' ] = i;
		if( recur( now + 1 ) ) return 1;
	}
	return 0;
}

void print( char s[], int n ){
	for( int i = 0; i < n; i++ ){
		if( is_int( s[ i ] ) ) putchar( s[ i ] );
		else putchar( digit[ s[ i ] - 'A' ] + '0' );
	}
}

void output(){
	print( ipta, la );
	printf(" x ");
	print( iptb, lb );
	printf(" = ");
	print( iptp, lp );
	printf("\n");
}

int main(){
	scanf("%s%s%s", ipta, iptb, iptp );
	pre();
	int ans = recur( 0 );
	if( ans ) output();
	else printf("no solution.\n");
}