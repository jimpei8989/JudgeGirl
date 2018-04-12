#include <stdio.h>

int main(){
    int n;
    while( scanf("%d", &n ) != EOF ){
        int prev = -1;
        int cnt = 0;
        for( int i = 0; i < n; i++ ){
            int a;
            scanf("%d", &a );
            if( a != prev ){
                prev = a;
                cnt ++;
            }
        }
        printf("%d\n", cnt );
    }
}