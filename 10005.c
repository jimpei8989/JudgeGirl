#include <stdio.h>
#include <string.h>

int main(){
    char str[ 1010 ];
    while( scanf("%s", str ) == 1 ){
        int flag = 0;
        int leng = strlen( str );
        int now = 0;
        for( int i = 0; i < leng; i++ ){
            if( str[ i ] >= '0' && str[ i ] <= '9' ){
                flag = 1;
                now *= 10;
                now += str[ i ] - '0';
            }
            else{
                if( flag ){
                    printf("%d\n", now );
                    flag = 0;
                    now = 0;
                }
            }
        }
        if( flag )
            printf("%d\n", now );
    }
    return 0;
}