#include <stdio.h>
#define maxn (1 << 14)
typedef long long ll;

int find( int *arr, int L, int R ){
	ll sum = 0, now = 0;
	for( int i = L; i < R; i++ ){
		sum += (ll)arr[ i ];
		now += (ll)arr[ i ] * (ll)( i - L );
	}
	for( int i = L; i < R; i++ ){
		if( now == 0 ) return i;
		now -= sum;
	}
	return -1;
}

void recur( int *arr, int L, int R ){
	if( R - L <= 2 ) return;
	int mid = find( arr, L, R );
	if( mid == -1 ) return;
	recur( arr, L, mid );
	printf("%d\n", mid );
	recur( arr, mid + 1, R );
}

int main(){
	int n, arr[ maxn ];
	scanf("%d", &n );
	for( int i = 0; i < n; i++ )
		scanf("%d", &arr[ i ] );
	recur( arr, 0, n );
}