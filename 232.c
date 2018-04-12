#include <stdio.h>

int month[ 13 ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int is_leap( int k ){
    if( k % 400 == 0 ) return 1;
    if( k % 100 == 0 ) return 0;
    if( k % 4 == 0 ) return 1;
    return 0;
}

int main(){
    int yr, st;
    int n;
    scanf("%d%d%d", &yr, &st, &n );
    month[ 2 ] += is_leap( yr );

    for( int i = 0; i < n; i++ ){
        int m, d;
        scanf("%d%d", &m, &d );
        if( m < 1 || m > 12 ) printf("-1\n");
        else if( d < 1 || d > month[ m ] ) printf("-2\n");
        else{
            int now = st - 1;
            for( int j = 1; j < m; j++ )
                now += month[ j ];
            now += d;
            now %= 7;
            printf("%d\n", now);
        }
    }
}