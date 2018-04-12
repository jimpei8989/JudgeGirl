#include <stdio.h>
#define MAXN 1024

void swap( int *i, int *j ){
	int tp = *i;
	*i = *j;
	*j = tp;
}

void sort( int *arr, int N ){
	for( int i = 0; i < N; i++ )
		for( int j = 0; j < N-1; j++ )
			if( arr[ j ] >= arr[ j + 1 ] )
				swap( &arr[ j ], &arr[ j + 1 ] );
}

void print( int *arr, int N ){
	for( int i = 0; i < N; i++ ){
		printf("%d %d\n", arr[ i ] % MAXN, arr[ i ] / MAXN );
	}
}

void count(int **p[]){
	int cnt[ MAXN ] = { 0 };
	int *sample[ MAXN ];
	int sample_idx = 0;
	int n = 0;
	while( p[ n ] != NULL ){
		int flag = -1;
		for( int i = 0; i < sample_idx; i++ )
			if( *p[ n ] == sample[ i ] )
				flag = i;
		if( flag == -1 ){
			sample[ sample_idx ] = *p[ n ];
			flag = sample_idx;
			sample_idx++;
		}
		cnt[ flag ] ++;
		n++;
	}
	int arr[ MAXN ] = { 0 };
	for( int i = 0; i < sample_idx; i++ )
		arr[ i ] = (cnt[ i ] * MAXN) + (*sample[ i ]);
	sort( arr, sample_idx );
	print( arr, sample_idx );
}

 
#define MAX_SIZE_PTRARRAY 512
#define MAX_NUM_PTR 512
#define MAX_NUM_INTVAR 512
 
int main(){
  int **ptrArray[MAX_SIZE_PTRARRAY] = {};
  int  *intPtr[MAX_NUM_PTR];
  int   intVar[MAX_NUM_INTVAR];
 
  intVar[0] = 7;
  intVar[1] = 6;
  intVar[2] = 2;
  intVar[3] = 9;
  ptrArray[0] = &intPtr[0];
  ptrArray[1] = &intPtr[1];
  ptrArray[2] = &intPtr[2];
  ptrArray[3] = &intPtr[3];
  ptrArray[4] = NULL;
  intPtr[0] = &intVar[0];
  intPtr[1] = &intVar[1];
  intPtr[2] = &intVar[2];
  intPtr[3] = &intVar[3];
 
  count(ptrArray);
 
  return 0;
}