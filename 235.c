#include <stdio.h>
typedef long long ll;

ll l[ 20 ][ 20 ], r[ 20 ][ 20 ], s[ 20 ][ 20 ];
ll son[ 20 ][ 20 ];
ll mom[ 20 ][ 20 ];

ll gcd( ll a, ll b ){
    if( b == 0 ) return a;
    return gcd( b, a % b );
}

int main(){
    for( int i = 0; i < 20; i++ ){
        for( int j = 0; j < 20; j++ ){
            son[ i ][ j ] = 0;
            mom[ i ][ j ] = 1;
            s[ i ][ j ] = 1;
        }
    }
    int n;
    scanf("%d", &n );
    if( n == 0 ) printf("1/1\n");
    for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= i; j++ ){
            scanf("%lld%lld", &l[ i ][ j ], &r[ i ][ j ] );
            s[ i ][ j ] = l[ i ][ j ] + r[ i ][ j ];
        }
    }
    son[ 1 ][ 1 ] = 1;
    mom[ 1 ][ 1 ] = 1;
    for( int i = 2; i <= n + 1; i++ ){
        for( int j = 1; j <= i; j++ ){
            ll l_son = son[ i - 1 ][ j - 1 ] * r[ i - 1 ][ j - 1 ];
            ll l_mom = mom[ i - 1 ][ j - 1 ] * s[ i - 1 ][ j - 1 ];
            ll l_gcd = gcd( l_son, l_mom );
            l_son /= l_gcd;
            l_mom /= l_gcd;
            ll r_son = son[ i - 1 ][ j ] * l[ i - 1 ][ j ];
            ll r_mom = mom[ i - 1 ][ j ] * s[ i - 1 ][ j ];
            ll r_gcd = gcd( r_son, r_mom );
            r_son /= r_gcd;
            r_mom /= r_gcd;

            son[ i ][ j ] = l_son * r_mom + r_son * l_mom;
            mom[ i ][ j ] = l_mom * r_mom;
            ll tgcd = gcd( son[ i ][ j ], mom[ i ][ j ] );
            son[ i ][ j ] /= tgcd;
            mom[ i ][ j ] /= tgcd;
            if( i == n + 1 )
                printf("%lld/%lld\n", son[ i ][ j ], mom[ i ][ j ] );
        }
    }
}