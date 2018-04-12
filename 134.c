#include <stdio.h>
#define maxn ( 1 << 10 )

typedef struct Node{
	int value;
	struct Node *lc, *rc;
} Node;

typedef struct {
	int d, l;
} Ipt;

int cmpIpt( const void *a, const void *b ){
	if( (Ipt*)a->l == (Ipt*)b->l ) return (Ipt*)a->d - (Ipt*)b->d;
	return (Ipt*)a->l - (Ipt*)b->l;
}

Node *build( Node *now)

int main(){
	int N; scanf("%d", &N );
	Ipt ipt[ maxn ];
	for( int i = 0; i < N; i++ )
		scanf("%d%d", ipt[ i ].d, ipt[ i ].l );
	qsort( ipt, N, sizeof( Ipt ), cmpIpt );
	Node *root = NULL;
	for( int i = 0; i < N; i++ ){
		root = build( root, ipt[ i ] );
	}
	int Q; scanf("%d", &Q );
	while( Q-- ){
		int a, b;
		scanf("%d%d", &a, &b );
	}
}