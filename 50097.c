#include<stdio.h>
#define maxn 1048576
typedef unsigned long long ull;
typedef long long ll;

ull newa[ maxn ];
void transmission(long long belt[],int N,int T){
	int shift = ( T / 64 ) % N;
	for( int i = 0; i < N; i++ )
		newa[ i ] = belt[ ( i + shift ) % N ];
	int shifta = T % 64;
	int shiftb = 64 - shifta;
	for( int i = 0; i < N; i++ ){
		belt[ i ] = ( newa[ i ] << shifta );
        if( shiftb < 64 )
            belt[ i ] |= ( newa[ ( i + 1 ) % N ] >> shiftb );
    }
}

#define MAXSIZE 1048576
long long int belt[MAXSIZE];

int main(){
    int N,T;
    scanf("%d%d",&N,&T);
    for(int i=0;i<N;i++)
        scanf("%lld",&belt[i]);
    transmission(belt,N,T);
    for(int i=0;i<N;i++)
        printf("%lld%s",belt[i],i==N-1?"\n":" ");
    return 0;
}