#include <stdio.h>
#include <stdlib.h>

int gcd( int a, int b ){
    if( a == 0 ) return b;
    if( b == 0 ) return a;
    return gcd( b, a % b );
}

int main(){
    int a, b, c, d, e, f, g;
    scanf("%d%d%d", &a, &b, &c );
    scanf("%d", &d );
    scanf("%d%d%d", &e, &f, &g );

    int sx = abs( a ) * c + b;
    sx *= ( a / abs( a ) );
    int mx = c;

    int sy = abs( e ) * g + f;
    sy *= ( e / abs( e ) );
    int my = g;
    int sz, mz;

    if( d < 2 ){
        mz = mx * my;
        if( d == 1 ) sy *= -1;
        sx *= my;
        sy *= mx;
        sz = sx + sy;
    }

    if( d == 2 ){
        mz = mx * my;
        sz = sx * sy;
    }
    if( d == 3 ){
        mz = mx * sy;
        sz = my * sx;
        if( sz < 0 && mz < 0 ){
            sz *= -1;
            mz *= -1;
        }
    }

    if( sz < 0 ){
        printf("-");
        sz *= -1;
    }

    int q = sz / mz;
    int w = sz % mz;
    int r = mz;
    int tp = gcd( w, r );
    w /= tp;
    r /= tp;
    printf("%d\n%d\n%d\n", q, w, r );
}