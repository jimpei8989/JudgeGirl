#include <stdio.h>
#include <stdlib.h>
#define maxn 1000000 + 10

struct Day{
	int y, m, d;
};

int cmp( const void *a, const void *b ){
	struct Day i = *( struct Day* ) a;
	struct Day j = *( struct Day* ) b;
	if( i.y == j.y ){
		if( i.m == j.m )
			return i.d - j.d;
		return i.m - j.m;
	}
	return i.y - j.y;
}

struct Day day[ maxn ];

int main(){
	int n;
	scanf("%d", &n );
	for( int i = 0; i < n; i++ )
		scanf("%d%d%d", &day[ i ].y, &day[ i ].m, &day[ i ].d );
	qsort( day, n, sizeof( struct Day ), cmp );
	for( int i = 0; i < n; i++ )
		printf("%d %d %d\n", day[ i ].y, day[ i ].m, day[ i ].d );
	return 0;
}