#include <stdio.h>

int main(){
    int n;
    int o = 0, e = 0;
    scanf("%d", &n );
    int arr[ 1010 ];
    for( int i = 0; i < n; i++ ){
        scanf("%d", &arr[ i ] );
        if( arr[ i ] % 2 == 1 ) o++;
        else e++;
    }
    for( int i = 0; i < n; i++ ){
        if( arr[ i ] % 2 == 1 ){
            printf("%d", arr[ i ] );
            o--;
            if( o == 0 ) printf("\n");
            else printf(" ");
        }
    }
    for( int i = 0; i < n; i++ ){
        if( arr[ i ] % 2 == 0 ){
            printf("%d", arr[ i ] );
            e--;
            if( e == 0 ) printf("\n");
            else printf(" ");
        }
    }
}