#include <stdio.h>
#include <stdlib.h>

#define maxn 100100
typedef long long ll;
typedef struct Pair{
	int x, y;
} pair;

pair cities[ maxn ];

int cmp( const void *a, const void *b ){
	pair A = *(pair*) a;
	pair B = *(pair*) b;
	int distA = A.x*A.x + A.y*A.y;
	int distB = B.x*B.x + B.y*B.y;
	if( distA == distB ){
		if( A.x == B.x ){
			if( A.y < B.y ) return -1;
			return 1;
		}
		else if( A.x < B.x ) return -1;
		else return 1;
	}
	else if( distA < distB ) return -1;
	return 1;
}

int main(){
	int n = 0;
	while( scanf("%d%d", &cities[ n ].x, &cities[ n ].y ) != EOF ) n++;
	qsort( cities, n, sizeof( pair ), cmp );

	ll ans = 0;
	int nowx = 0, nowy = 0;
	for( int i = 0; i < n; i++ ){
		ans += (ll)( nowx - cities[ i ].x ) * (ll)( nowx - cities[ i ].x ) + 
			(ll)( nowy - cities[ i ].y ) * (ll)( nowy - cities[ i ].y );
		nowx = cities[ i ].x;
		nowy = cities[ i ].y;
	}
	//ans += (ll)nowx*(ll)nowx + (ll)nowy*(ll)nowy;
	printf("%lld\n", ans );
}