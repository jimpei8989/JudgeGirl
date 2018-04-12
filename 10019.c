#include <stdio.h>
#include <ctype.h>

int main(){
    char c;
    int start = 0;
    char s[ 1000 ];
    while( scanf("%c", &c ) != EOF ){
     int idx = 0;
        int start = 0;
        if( !isspace( c ) ){
            start = 1;
            s[ idx++ ] = c;
        }
        while( scanf("%c", &c ) != EOF ){
            if( c == '\n' ) break;
            if( start == 0 && !isspace( c ) )
                start = 1;
            if( start == 1 )s[ idx ++ ] = c;
        }
        for( int i = idx - 1; i >= 0; i-- ){
            if( isspace( s[ i ] ) )
                idx--;
            else break;
        }
        for( int i = 0; i < idx; i++ )
            printf("%c", s[ i ] );
        printf("\n");
    }
    return 0;
}