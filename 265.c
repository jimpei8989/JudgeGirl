#include <stdio.h>

int max( int a, int b ){
    return a > b ? a : b;
}
int min( int a, int b ){
    return a < b ? a : b;
}

int main(){
    int up = -100000;
    int dn = 100000;
    int lf = 100000;
    int rt = -100000;
    int x, y;
    while( scanf("%d%d", &x, &y ) != EOF ){
        up = max( up, y );
        dn = min( dn, y );
        lf = min( lf, x );
        rt = max( rt, x );
    }
    printf("%d\n", ( up - dn ) * ( rt - lf ) );
}