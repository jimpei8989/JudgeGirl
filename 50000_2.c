#include <stdio.h>
#include <stdlib.h>

int max( int a, int b ){
    if( a >= b ) return a;
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
    while( scanf("%d", &n ) != EOF && n != 0 ){
        int now = n / abs( n );
        if( prev != now ){
            if( cnt == k && ( set > 0 || now == 1 ) ){
                set ++;
                if( set % 2 ) ans = max( ans, set );
            }
            else{
                set = 0;
            }
            cnt = 0;
        }
        cnt ++;
        if( cnt > k ){
            set = 1;
            cnt = k;
        }
        prev = now;
        //printf("n = %d, cnt = %d, set = %d, ans = %d\n", n, cnt, set, ans );
    }
    printf("%d\n", ans * k );
    return 0;
}