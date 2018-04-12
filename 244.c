#include <stdio.h>

int main(){
    int sp[ 3 ];
    int fp[ 3 ];
    int cnt = 0;
    for( int i = 0; i < 3; i++ )
        scanf("%d", &sp[ i ] );
    for( int i = 0; i < 3; i++ )
        scanf("%d", &fp[ i ] );
    int n;
    while( scanf("%d", &n ) != EOF ){
        if( n == 0 ) break;
        int big = 0;
        for( int i = 0; i < 3; i++ ){
            if( n == sp[ i ] && big < 2000000 ){
                big = 2000000;
            }
        }
        for( int i = 0; i < 3; i++){
            int cp = fp[ i ];
            if( n == cp && big < 200000 ) big = 200000;
            if( n % 10000000 == cp % 10000000 && big < 40000 ) big = 40000;
            if( n % 1000000 == cp % 1000000 && big < 10000 ) big = 10000;
            if( n % 100000 == cp % 100000 && big < 4000 ) big = 4000;
            if( n % 10000 == cp % 10000 && big < 1000 ) big = 1000;
            if( n % 1000 == cp % 1000 && big < 200 ) big = 200;
        }
        cnt += big;
    }
    printf("%d\n", cnt );
    return 0;
}