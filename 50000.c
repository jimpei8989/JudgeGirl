#include <stdio.h>
#include <stdlib.h>

int main(){
    int prv = 0;
    int ans = 0;
    int cnt = 0;
    int set = 0;
    int k;
    scanf("%d", &k );
    int n;
    while( scanf("%d", &n ) != EOF ){
        if( n == 0 ) break;
        int now = n / abs( n );

        if( now == prv ){
            cnt ++;
            if( now == 1 && cnt > k ){
                if( set + 1 > ans && set >= 2 ) ans = set + 1;
            }
        }

        else{
            if( prv != 1 ){
                if( cnt == k ) set ++;
                else set = 0;
            }
            else{
                if( cnt == k ) set ++;
                else if( cnt > k && prv == 1 ) set = 1;
                else set = 0;
            }
            prv = now;
            cnt = 1;
        }
        if( set % 2 && set > 1 ){
            if( ans < set ) ans = set;
        }
    }
    if( prv == 1 && cnt == k && ans < set + 1 && set >= 2 && set % 2 == 0 )
        ans = set + 1;
    printf("%d\n", ans * k );
}