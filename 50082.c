#include <stdio.h>

int max( int a, int b ){
    return a > b ? a : b;
}

int main(){
    int n, a, b;
    int nowa = 0, nowb = 0;
    while( scanf("%d%d%d", &n, &a, &b ) != EOF ){
        int starta = max( n, nowa );
        nowa = starta + a;
        int startb = max( starta + a, nowb );
        nowb = startb + b;
        int endtime = nowb;
        printf("%d\n", endtime );
    }
}