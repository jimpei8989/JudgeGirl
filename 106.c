#include <stdio.h>
#include <string.h>


char ans[ 2 ][ 100 ] = {
    "yes",
    "no",
};

int main(){
    char s[ 1000 ];
    while( scanf("%s", s ) ){
        if( strcmp( s, "-1" ) == 0 ) break;
        int leng = strlen( s );
        int last = s[ leng - 1 ] - '0';
        printf("%s ", ans[ last % 2 ] );
        int sum[ 2 ] = { 0 };
        for( int i = 0; i < leng; i++ ){
            sum[ i % 2 ] += ( s[ i ] - '0' );
        }
        printf("%s ", ans[ ( sum[ 0 ] + sum[ 1 ] ) % 3 ? 1 : 0 ] );
        printf("%s ", ans[ last % 5 == 0 ? 0 : 1 ] );
        printf("%s\n", ans[ ( sum[ 0 ] - sum[ 1 ] ) % 11 == 0 ? 0 : 1 ] );
    }
}