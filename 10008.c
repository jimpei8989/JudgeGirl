#include <stdio.h>

int main(){
    int bill[] = { 1000, 500, 100, 50, 10, 5, 1 };
    int n;
    while( scanf("%d", &n ) != EOF ){
        for( int i = 0; i < 7; i++ ){
            printf("%d%c", n / bill[ i ], " \n"[ i == 6 ] );
            n %= bill[ i ];
        }
    }
}