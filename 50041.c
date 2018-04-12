#include <stdio.h>


int main(){
    int n;
    scanf("%d", &n );
    int prev = 1;
    int a, b;
    int cost = 0;
    scanf("%d", &a );
    for( int i = 0; i < n - 1; i++ ){
        scanf("%d", &b );
        if( b > a ) cost += ( 4 - prev ) * ( b - a );
        else cost += ( 3 - prev ) * ( a - b );
        prev = ( b > a ? 0 : 1 );
        a = b;
    }
    printf("%d\n", cost );
}