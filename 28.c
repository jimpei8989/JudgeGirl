#include <stdio.h>
 
int sop( int n ){
	if( n == 0 ) return 0;
	return n * n + sop( n - 1 );
}

int main(){
    int n;
    scanf("%d", &n );
    printf("%d\n", sop( n ) );
}