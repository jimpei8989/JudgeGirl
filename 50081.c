#include <stdio.h>

int dx[ 5 ] = { 0, 1, -1, 0, 0 };
int dy[ 5 ] = { 0, 0, 0, 1, -1 };

int main(){
    int n, m;
    scanf("%d%d", &n, &m );
    int x = 0, y = 0;
    int k;
    printf("0\n0\n");
    while( scanf("%d", &k ) != EOF ){
        int nx = x + k * dx[ k % 5 ];
        int ny = y + k * dy[ k % 5 ];
        if( k % 5 == 0 || nx < 0 || ny < 0 || nx >= n || ny >= m ) continue;
        x = nx;
        y = ny;
        printf("%d\n%d\n", x, y );
    }
}