#include <stdio.h>

int max( int a, int b ){
    if( a > b ) return a;
    return b;
}

int min( int a, int b ){
    if( a > b ) return b;
    return a;
}

int area( int l, int d, int r, int u ){
    if( l > r || d > u ) return 0;
    return ( r - l ) * ( u - d );
}

int main(){
    int lf[ 3 ], rt[ 3 ], up[ 3 ], dn[ 3 ];
    for( int i = 0; i < 3; i++ ){
        scanf("%d%d%d%d", &lf[ i ], &dn[ i ], &rt[ i ], &up[ i ] );
    }
    int a = 0;
    for( int i = 0; i < 3; i++ ){
        a += area( lf[ i ], dn[ i ], rt[ i ], up[ i ] );
    }
    for( int i = 0; i < 3; i++ ){
        int j = ( i + 1 ) % 3;
        a -= area( max( lf[ i ], lf[ j ] ), max( dn[ i ], dn[ j ] ),
             min( rt[ i ], rt[ j ] ), min( up[ i ], up[ j ] ) );
    }
    int l = lf[ 0 ], d = dn[ 0 ], r = rt[ 0 ], u = up[ 0 ];
    for( int i = 1; i < 3; i++ ){
        l = max( lf[ i ], l );
        d = max( dn[ i ], d );
        r = min( rt[ i ], r );
        u = min( up[ i ], u );
    }
    a += area( l, d, r, u );
    printf("%d\n", a );
}