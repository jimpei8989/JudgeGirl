int matrixA[ 1 << 10 ][ 1 << 10 ] = { 0 };

void matrix_multiplication(int N, int** ptrA, int M, int** ptrB, int S, int *result){
	for( int i = 0; i < S; i++ )
		for( int j = 0; j < S; j++ )
			result[ i * S + j ] = 0;

	for( int i = 0; i < N; i++ ){
		int element = ptrA[ 0 ][ i ];
		int rowidx = ptrA[ 1 ][ i ];
		int colidx = ptrA[ 2 ][ i ];
		matrixA[ rowidx ][ colidx ] = element;
	}
	for( int i = 0; i < M; i++ ){
		int element = ptrB[ 0 ][ i ];
		int rowidx = ptrB[ 1 ][ i ];
		int colidx = ptrB[ 2 ][ i ];
		for( int j = 0; j < S; j++ )
			result[ j * S + colidx ] += element * matrixA[ j ][ rowidx ];
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 1000
static int A_elements[MAX], A_rowind[MAX], A_colind[MAX];
static int B_elements[MAX], B_rowind[MAX], B_colind[MAX];
int main(int argc, char const *argv[])
{    
    int N, M, S;
    assert(scanf("%d %d %d", &N, &M, &S) == 3);
 
    int *ptrA[3]; 
    int *ptrB[3];
    ptrA[0] = A_elements, ptrA[1] = A_rowind, ptrA[2] = A_colind;
    ptrB[0] = B_elements, ptrB[1] = B_rowind, ptrB[2] = B_colind;
 
    for(int i = 0; i < N; ++i)
        assert(scanf("%d", &A_elements[i]) == 1);
    for(int i = 0; i < N; ++i)
        assert(scanf("%d", &A_rowind[i]) == 1);    
    for(int i = 0; i < N; ++i)
        assert(scanf("%d", &A_colind[i]) == 1);            
    for(int i = 0; i < M; ++i)
        assert(scanf("%d", &B_elements[i]) == 1);
    for(int i = 0; i < M; ++i)
        assert(scanf("%d", &B_rowind[i]) == 1);    
    for(int i = 0; i < M; ++i)
        assert(scanf("%d", &B_colind[i]) == 1);
 
    int *result = malloc(S*S*sizeof(int));
    matrix_multiplication(N, ptrA, M, ptrB, S, result);
    for (int i = 0; i < S; ++i)
        for (int j = 0; j < S; ++j)
              printf("%d%c", result[i * S + j], " \n"[j == S - 1]);
    return 0;
}