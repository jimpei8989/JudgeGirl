#include <stdio.h>
#include <stdlib.h>

int main(){
    int k;
    scanf("%d", &k );
    int n;
    int ans = 0;
    int cnt = 0;
    int prev = 0;
    int tmp = 0;
    while( scanf("%d", &n ) != EOF ){
        if( n == 0 ) break;

        int now = n / abs( n );
        if( prev == now ){
            tmp ++;
            if( tmp >= k ){
                tmp = k;
                ans = max( ans, cnt + 2 );
            }
        }
        else{
            if( tmp == k )

        }


        prev = now;
    }
    return 0;
}