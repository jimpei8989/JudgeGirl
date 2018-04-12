#include <stdio.h>
#include <string.h>

void print( int exp[], int n ){
    for( int i = 1; i < n; i++ )
        printf("%d%c", exp[ i ], " \n"[ i == n - 1 ] );
}

int eval(int exp[]){
    const int ERR1 = -2147483646;
    const int ERR2 = ERR1 - 1;
    int n = exp[ 0 ] + 1;
    for( int i = 2; i < n; i+= 2 ){
        if( exp[ i ] < 1 || exp[ i ] > 4 ) return ERR1;
        if( exp[ i ] == 3 || exp[ i ] == 4 ){
            if( exp[ i ] == 3 ) exp[ i - 1 ] *= exp[ i + 1 ];
            if( exp[ i ] == 4 && exp[ i + 1 ] == 0 ) return ERR2;
            if( exp[ i ] == 4 ) exp[ i - 1 ] /= exp[ i + 1 ];
            n -= 2;
            for( int j = i; j < n; j++ ){
                exp[ j ] = exp[ j + 2 ];
            }
            i -= 2;
        }
    }
    int now = exp[ 1 ];
    for( int i = 2; i < n; i+=2 ){
        if( exp[ i ] == 1 ) now += exp[ i + 1 ];
        if( exp[ i ] == 2 ) now -= exp[ i + 1 ];
    }
    return now;
}

int main() {
    int exp[1024];
    memset(exp, -1, sizeof(exp));
    scanf("%d", &exp[0]);
    for (int i = 1; i <= exp[0]; i++)
        scanf("%d", &exp[i]);
    int ret = eval(exp);
    printf("%d\n", ret);
    return 0;
}