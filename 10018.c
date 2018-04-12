#include <stdio.h>

int main(){
    int used[ 100000 + 10 ];
    int n;
    scanf("%d", &n );
    int ans = -1;
    for( int i = 0; i < n; i++ ){
        int a;
        scanf("%d", &a );
        if( used[ a ] ) ans = a;   
        used[ a ] ++;
    }
    printf("%d\n", ans );
}