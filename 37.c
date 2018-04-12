#include <stdio.h>

int gcd( int a, int b ){
    if( b == 0 ) return a;
    return gcd( b, a % b );
}


int value(int type, int width, int height, int length){
    int t = -1;
    int DT[ 6 ] = { 79, 47, 29, 82, 26, 22 };
    int VT[ 6 ] = { 30, 10, 4, 5, 3, 9 };
    for( int i = 0; i < 6; i++ ){
        if( type == DT[ i ] ) t = i;
    }
    if( t == -1 ) return -1;
    if( width <= 0 || height <= 0 || length <= 0 ) return -2;
    int g = gcd( width, gcd( height, length ) );
    int ans = width * height * length * g * g * g;
    ans *= VT[ t ];
    return ans;
}

int main(){
    printf("%d\n", value( 79, 0, 8, 2 ) );
}