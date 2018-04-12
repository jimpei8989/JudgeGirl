#include <stdio.h>
#include <stdlib.h>
#define maxn (1 << 20)

typedef struct HEAP{
	int arr[ 1<<11 ];
	int size;
} heap;

void swap( int *a, int *b ){
	int tp = *a;
	*a = *b;
	*b = tp;
}

void push( heap *pq, int x ){
	pq->size ++;
	int tp = pq->size;	
	pq->arr[ tp ] = x;
	while( tp > 1 ){
		if( pq->arr[ tp ] < pq->arr[ tp / 2 ] ){
			swap( &pq->arr[ tp ], &pq->arr[ tp / 2 ] );
			tp /= 2;
		}
		else break;
	}
}

int top( heap *pq ){
	if( pq -> size == 0 ) return -1;
	return pq -> arr[ 1 ];
}

void pop( heap *pq ){
	if( pq -> size == 0 ) return;
	pq -> arr[ 1 ] = pq -> arr[ pq -> size ];
	pq -> size --;
	int tp = 1;
	while( tp * 2 <= pq -> size ){
		if( tp * 2 + 1 > pq -> size ){
			if( pq -> arr[ tp ] <= pq -> arr[ tp * 2 ] )
				break;
			else{
				swap( &pq->arr[ tp * 2 ], &pq->arr[ tp ] );
				tp *= 2;
			}
		}
		else{
			if( pq->arr[ tp ] <= pq->arr[ tp * 2 ] && pq->arr[ tp ] <= pq->arr[ tp * 2 + 1 ] )
				break;
			else if( pq->arr[ tp*2 ] <= pq->arr[ tp * 2 + 1 ] ){
				swap( &pq->arr[ tp * 2 ], &pq->arr[ tp ] );
				tp *= 2;
			}
			else{
				swap( &pq->arr[ tp * 2 + 1 ], &pq->arr[ tp ] );
				tp = tp * 2 + 1;
			}
		}
	}
	return;
}

int main(){
	int n, m;
	heap *pq = (heap*)malloc( sizeof( heap ) );
	scanf("%d%d", &n, &m );
	for( int i = 0; i < n; i++ ) push( pq, 0 );
	int cnt = 0;
	for( int i = 0; i < m; i++ ){
		int t, s;
		scanf("%d%d", &t, &s );

		int x = top( pq ) > t ? top( pq ) : t;
		pop( pq );
		if( x > t ) cnt += (x - t);
		push( pq, x + s );
	}
	printf("%d\n", cnt );
}