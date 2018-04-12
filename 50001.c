#include <stdio.h>
#include <stdlib.h>

int dx[ 4 ] = { 0, 1, 0, -1 };
int dy[ 4 ] = { 1, 0, -1, 0 };

int main(){
    int a, b, c, d, e, x, y, F;
    int p, q, r, s;
    int cnt = 0;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e );
    scanf("%d%d%d%d", &p, &q, &r, &s );
    scanf("%d%d%d", &x, &y, &F );
    cnt += abs( c * x + d * y ) % e;
    while( F > 0 ){
        int dir = abs( a * x + b * y ) % 4;
        x += dx[ dir ];
        y += dy[ dir ];
        F--;
        if( x == p && y == q ){
            x = r; y = s;
        }
        else if( x == r && y == s ){
            x = p; y = q;
        }
        else{
            cnt += abs( c * x + d * y ) % e;
        }
    }
    printf("%d\n%d %d\n", cnt, x, y );
}