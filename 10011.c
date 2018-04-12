#include <stdio.h>

int main(){
    int n;
    while( scanf("%d", &n ) != EOF ){
        int a;
        int cnt_0 = 0;
        for( int i = 0; i < n; i++ ){
            scanf("%d", &a );
            if( a != 0 ) {
                printf("%d", a);
                if( i == n - 1 && cnt_0 == 0 )
                    printf("\n");
                else printf(" ");
            }
            else cnt_0 ++;
        }
        for( int i = 0; i < cnt_0; i++ ){
            printf("%d%c", 0, " \n"[ i == cnt_0 - 1 ] );
        }
    }
}