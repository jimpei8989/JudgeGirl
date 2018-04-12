#include <stdio.h>
#define maxn (1 << 14)
typedef long long ll;

int find( int *arr, int n ){
	ll sum = 0, now = 0;
	for( int i = 0; i < n; i++ ){
		sum += (ll)arr[ i ];
		now += (ll)arr[ i ] * (ll)i;
	}
	for( int i = 0; i < n; i++ ){
		if( now == 0 ) return i;
		now -= sum;
	}
	return -1;
}

void recur( int *arr, int left, int n ){
	if( n <= 2 ) return;
	int mid = find( arr, n );
	if( mid == -1 ) return;
	recur( arr, left, mid );
	printf("%d\n", left + mid );
	recur( arr + mid + 1, mid + 1, n - mid - 1 );
}

int main(){
	int n, arr[ maxn ];
	scanf("%d", &n );
	for( int i = 0; i < n; i++ )
		scanf("%d", &arr[ i ] );
	recur( arr, 0, n );
	return 0;
}