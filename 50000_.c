#include <stdio.h>
#include <stdlib.h>

int max( int a, int b ){
    if( a >= b ) return a;
    return b;
}

int min( int a, int b ){
    if( a <= b ) return a;
    return b;
}

int main(){
    int ans = 0;
    int k;
    scanf( "%d", &k );
    int n = 1;
    int prev = 0;
    int cnt = 0;
    int set = 0;

    while( scanf("%d", &n ) != EOF ){
        if( n == 0 ) break;

        int now = n / abs( n );

        if( now == prev ){
            if( cnt == k ){
                if( set % 2 == 1 )
                    ans = max( ans, set );
                if( prev == 1 ) set = 1;
                else set = 0;
            }
            cnt = min( k, cnt + 1 );
        }
        else{
            if( cnt == k ){
                if( set % 2 == 1 )
                    ans = max( ans, set );
                set += 1;
            }
            else if( now == 1 )
                    set = 1;
            else set = 0;

            cnt = 1;
        }
        prev = now;
    }
    if( cnt == k && prev == 1 ){
        ans = max( ans, set );
    }
    if( ans == 1 ) ans = 0;

    printf("%d\n", ans * k );
    return 0;
}