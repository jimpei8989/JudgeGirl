#include <stdio.h>

int main () {
    int N, M, P;
    unsigned long long m[ 4 ] = {0};
    unsigned char n[ 32 ];
    unsigned char p;
    scanf ("%d%d%d", &N, &M, &P);
    for( int i = 0; i < M; i++) {
        scanf ("%llu", &m[ i ] );
    }
    for( int i = 0; i < M; i++ ){
        for( int j = 0; ( j + 8 * i ) < N && j < 8; j++){
            unsigned long long tmp = 1ull << 56;
            unsigned long long k = ( m[ i ] / tmp );
            n[ i * 8 + j ] = k % ( 1 << 8 );
            m[ i ] = m[ i ] << 8;
        }
    }
    for ( int i = 0; i < P; i++){
        scanf ("%hhu", &p);
        int d = 1;
        for( int j = 0; j < N && d; j++ ){
            if( n[ j ] == p ) {
                printf ("%hhu\n", n[j]);
                d = 0;
            }
        }
        if( d ){
            for( int j = 0; j < N && d; j++) {
                unsigned char tmp = p ^ n[ j ];
                int sum = 0;
                for( int k = 0; k < 8; k++) {
                    sum += (tmp % 2);
                    tmp = tmp >> 1;
                }
                if (sum == 1) {
                    printf("%hhu\n", n[ j ] );
                    d = 0;
                }
            }
        }
    }
    return 0;
}