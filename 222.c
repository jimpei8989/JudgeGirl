#include <stdio.h>

int hasEOF = 0;
int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;    
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}


void swap( int *a, int *b ){
    int tp = *a;
    *a = *b;
    *b = tp;
}

int main() {
    int x;
    int K = 256;
    int bookshelf[ 8 ] = { 0 };
    int in[ 256 ] = { 0 };
    while (ReadInt(&x)) {
        if( x == -1 ) break;
        if( in[ x ] == 0 ){
            in[ bookshelf[ 0 ] ] = 0;
            in[ x ] = 1;
            bookshelf[ 0 ] = x;
        }
        for( int i = 0; i < 7; i++ ){
            if( bookshelf[ i ] == x ){
                swap( &bookshelf[ i ], &bookshelf[ i + 1 ] );
            }
        }
    }
    for( int i = 0; i < 8; i++ ){
        printf("%d%c", bookshelf[ i ], " \n"[ i == 7 ] );
    }
    return 0;
}