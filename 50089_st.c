#include <stdio.h>
#include <assert.h>
#define MAXN 1024

int max( int a, int b ){
	return a > b ? a : b;
}

void build_st( int *st, int* nb, int N, int id, int l, int r ){//both close
	if( l == r ){
		st[ id ] = nb[ l - 1 ];
		return;
	}
	int mid = ( l + r ) / 2;
	build_st( st, nb, N, id * 2, l, mid );
	build_st( st, nb, N, id * 2 + 1, mid + 1, r );
	st[ id ] = max( st[ id * 2 ], st[ id * 2 + 1 ] );
}

int query_st( int *st, int x, int id, int l, int r ){
	if( l == r ) return l;
	if( x > st[ id ] ) return 0;
	int mid = ( l + r ) / 2;
	if( st[ 2 * id ] >= x ) return query_st( st, x, id * 2, l, mid );
	else return query_st( st, x, id * 2 + 1, mid+1, r );
}

int w_query_st( int *st, int x, int id, int l, int r ){
	if( l == r ) return l;
	if( x > st[ id ] ) return 0;
	int mid = ( l + r ) / 2;
	if( st[ id * 2 ] > st[ id * 2 + 1 ] ) return w_query_st( st, x, 2 * id, l, mid);
	else return w_query_st( st, x, 2 * id + 1, mid + 1, r );
}

void modify_st( int *st, int target, int usage, int id, int l, int r ){
	if( l == r ){
		st[ id ] -= usage;
		return;
	}
	int mid = ( l + r ) / 2;
	if( target <= mid ) modify_st( st, target, usage, 2 * id, l, mid );
	else modify_st( st, target, usage, 2 * id + 1, mid+1, r );
	st[ id ] = max( st[ id * 2 ], st[ id * 2 + 1 ] );
}

void firstfit( int bucket[ 1024 ],int N,int ball[16384],int M,int method,int result[16384] ){
	int st[ 4 * MAXN ];
	build_st( st, bucket, N, 1, 1, N );
	for( int i = 0; i < M; i++ ){
		int usebucket = query_st( st, ball[ i ], 1, 1, N );
		modify_st( st, usebucket, ball[ i ], 1, 1, N );
		result[ i ] = usebucket;
	}
	for( int i = 0; i < M; i++ )
		result[ i ] --;
}

void worstfit( int bucket[ 1024 ],int N,int ball[16384],int M,int method,int result[16384] ){
	int st[ 4 * MAXN ];
	build_st( st, bucket, N, 1, 1, N );
	for( int i = 0; i < M; i++ ){
		int usebucket = w_query_st( st, ball[ i ], 1, 1, N );
		if( usebucket != 0 ) 
			modify_st( st, usebucket, ball[ i ], 1, 1, N );
		result[ i ] = usebucket;
	}
	for( int i = 0; i < M; i++ )
		result[ i ] --;
}

struct Treap{
	Treap *lc, *rc;
	int val, idx, pri;

}




void bestfit( int bucket[ 1024 ],int N,int ball[16384],int M,int method,int result[16384] ){
	for( int i = 0; i < M; i++ ){
		int idx = -1;
		int min;
		for( int j = 0; j < N; j++ ){
			if( bucket[ j ] >= ball[ i ] ){
				if( bucket[ j ] < min || idx == -1 ){
					min = bucket[ j ];
					idx = j;
				}
			}
		}
		if( idx != -1 ) bucket [ idx ] -= ball[ i ];
		result[ i ] = idx;
	}
}

void place(int bucket[1024],int N,int ball[16384],int M,int method,int result[16384]){
	if( method == 0 ) firstfit( bucket, N, ball, M, method, result );
	if( method == 1 ) bestfit( bucket, N, ball, M, method, result );
	if( method == 2 ) worstfit( bucket, N, ball, M, method, result );
}




#include<stdio.h>
int main(){
    int N,M,method;
    scanf("%d%d%d",&N,&M,&method);
    int buckets[N];
    for(int i=0;i<N;i++)
        scanf("%d",&buckets[i]);
    int balls[M];
    for(int i=0;i<M;i++)
        scanf("%d",&balls[i]);
    int result[M];
    place(buckets,N,balls,M,method,result);
    for(int i=0;i<M;i++)
        printf("%d%s",result[i],i==M-1?"":" ");
    return 0;
}