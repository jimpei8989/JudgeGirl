#include <stdio.h>
#define maxn 105
int main(){
    int idx = 0;
    int a[ maxn ];
    while( scanf("%d", &a[ idx ] ) != EOF ){
        //if( a[ idx ] == 0 ) break;
        idx++;
    }
    int is[ maxn ][ maxn ] = { 0 };
    for( int i = 0; i < idx; i++ ){
        for( int j = i; j < idx; j++ ){
            for( int k = 0; k <= j - i; k++ ){
                if( a[ i + k  ] != a[ j - k ] )
                    is[ i ][ j ] = -1;
            }
            is[ i ][ j ] ++;
        }
    }
    int x = 0, y = 0;
    for( int i = 0; i < idx; i++ ){
        for( int j = i + 1; j < idx; j++ ){
            for( int k = j; k < idx; k++ ){
                if( is[ i ][ j - 1 ] == 1 && is[ j ][ k ] == 1 ){
                    if( (k - i) >= (y - x) ){
                        x = i;
                        y = k;
                    }
                }
            }
        }
    }
    for( int i = x; i <=y; i++ ){
        printf("%d", a[ i ] );
        if( i == y ) printf("\n");
        else printf(" ");
    }
}