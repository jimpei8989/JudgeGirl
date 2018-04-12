#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

int cmp( const void *i, const void *j ){
	ll a = *(ll *) i;
	ll b = *(ll *) j;
	int cnta = 0;
	int cntb = 0;
	ll k = 1;
	while( k != 0 ){
		cnta += (a & k) / k;
		cntb += (b & k) / k;
		k <<= 1;
	}
	if( cnta == cntb ){
		if( a < b ) return -1;
		if( a > b ) return 1;
		return 0;
	}
	return cnta - cntb;
}



int main(){
	int n = 0;
	ll arr[ 1 << 10 ];
	while( scanf("%lld", &arr[ n ] ) != EOF ) n++;
	qsort( arr, n, sizeof( ll ), cmp );
	for( int i = 0; i < n; i++ )
		printf("%lld\n", arr[ i ] );
	return 0;
}