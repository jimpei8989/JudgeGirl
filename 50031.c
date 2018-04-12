#include <stdio.h>
#include <stdlib.h>

typedef struct Tuple{
	int val;
	int fst, snd;
}Tuple;

int cmp_Tup( const void *pa, const void *pb ){
	Tuple a = *(Tuple*)pa;
	Tuple b = *(Tuple*)pb;
	if( a.val != b.val ) return a.val - b.val;
#ifdef INC
	else return a.fst - b.fst;
#else
	else return a.snd - b.snd;
#endif
}

void pairPrint(int ipt[], int N){
	Tuple *arr = (Tuple*)calloc( N, sizeof( Tuple ) );
	for( int i = 0; i < N; i++ ){
		arr[ i ].val = ipt[ i ];
		arr[ i ].fst = i;
	}
	qsort( arr, N, sizeof( Tuple ), cmp_Tup );
	int M = N / 2;
	Tuple *list = (Tuple*)calloc( M, sizeof( Tuple ) );
	for( int i = 0; i < M; i++ ){
		list[ i ].val = ( arr[ i ].val + arr[ N - i - 1 ].val );
		list[ i ].fst = arr[ i ].fst < arr[ N - i - 1 ].fst ? arr[ i ].fst : arr[ N - i - 1 ].fst;
		list[ i ].snd = arr[ i ].fst > arr[ N - i - 1 ].fst ? arr[ i ].fst : arr[ N - i - 1 ].fst;
	}
#ifdef INC
	qsort( list, M, sizeof( Tuple ), cmp_Tup );
	for( int i = 0; i < M; i++ )
		printf("%d = numbers[%d] + numbers[%d]\n", list[ i ].val, list[ i ].fst, list[ i ].snd );
#else
	qsort( list, M, sizeof( Tuple ), cmp_Tup );
	for( int i = M - 1; i >= 0; i-- )
		printf("%d = numbers[%d] + numbers[%d]\n", list[ i ].val, list[ i ].snd, list[ i ].fst );
#endif
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int *A = (int *) malloc(sizeof(int)*n);
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        pairPrint(A, n);
        free(A);
    }
    return 0;
}