#include <stdio.h>
#include <string.h>

int main(){
    char s[ 1000 ];
    scanf("%s", s );
    int cnt [ 30 ] = { 0 };
    for( int i = 0; i < strlen( s ); i++ ){
        if( s[ i ] >= 'a' && s[ i ] <= 'z'){
            cnt[ ( s[ i ] - 'a' ) ] ++;
        }
        if( s[ i ] >= 'A' && s[ i ] <= 'Z' ){
            cnt[ s[ i ] - 'A' ] ++;
        }
    }
    for( int i = 0; i < 26; i++ ) printf("%d\n", cnt[ i ] );
}