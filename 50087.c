#include <stdio.h>

void swap( int *i, int *j ){
	int tp = *i;
	*i = *j;
	*j = tp;
}

int main(){
	int arr[ 1 << 11 ];
	int n;
	scanf("%d", &n );
	for( int i = 0; i < n; i++ )
		scanf("%d", &arr[ i ] );
	int mid;
	int idx = 0;
	while( 1 ){
		int flag = 0;
		for( int i = 0; i < n; i++ ){
			int k = 0;
			for( int j = 0; j < n; j++ ){
				k += arr[ j ] * ( i - j );
			}
			if( k == 0 ){
				mid = i;
				flag = 1;
				break;
			}
		}
		if( flag ){
			break;
		}
		swap( &arr[ idx ], &arr[ n - 1 - idx ] );
		idx++;
	}
	for( int i = 0; i < n; i++ ){
		if( i == mid ) printf("v");
		else printf("%d", arr[ i ] );
		printf("%c", " \n"[ i == n - 1 ] );
	}
	return 0;
}