#include <stdio.h>

int main(){
    int n;
    int hori[ 2 ][ 3 ] = { 0 };
    int verti[ 2 ][ 3 ] = { 0 };
    int c1[ 2 ] = { 0 };
    int c2[ 2 ] = { 0 };
    int used[ 3 ][ 3 ] = { 0 };
    int state = -1;
    int p = 0;
    scanf("%d", &n );
    while( n -- ){
        int x, y;
        scanf("%d%d", &x, &y );
        if( state != -1 ) continue;
        if( x < 0 || y < 0 || x >= 3 || y >= 3 ) continue;
        if( used[ x ][ y ] == 1 ) continue;
        used[ x ][ y ] = 1;
        verti[ p ][ x ] ++;
        hori[ p ][ y ] ++;
        if( x == y ) c1[ p ] ++;
        if( x + y == 2 ) c2[ p ] ++;
        if( hori[ p ][ y ] == 3 || verti[ p ][ x ] == 3 || c1[ p ] == 3 || c2[ p ] == 3 ){
            state = p;
        }
        p = 1 - p;
    }
    if( state == -1 ) printf("There is a draw.\n");
    if( state == 0 ) printf("Black wins.\n");
    if( state == 1 ) printf("White wins.\n");
}