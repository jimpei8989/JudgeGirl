#include <stdio.h>
#include <stdlib.h>
#define maxn 16
 
int ans = 2147483647;
int edge[ maxn ][ maxn ];
 
int min( int a, int b ){
    return a < b ? a : b;
}
 
void recur( int idx, int N, int use, int cost, int *stk ){
    if( cost >= ans ) return;
    if( idx == N ){
        ans = min( ans, cost );
        return;
    }
    for( int now = 0; now < N; now++ ){
        if( ( use & (1 << now) ) == 0 ){
            int tmp = cost;
            for( int i = 0; i < idx; i++ )
                if( edge[ now ][ stk[ i ] ] )
                    tmp += ( idx - i );
            stk[ idx ] = now;
            recur( idx+1, N, use|(1<<now), tmp, stk );
        }
    }
}
 
int main(){
    int N, M;
    scanf("%d%d", &N, &M );
    for( int i = 0; i < M; i++ ){
        int a, b;
        scanf("%d%d", &a, &b);
        edge[ a ][ b ] = 1;
        edge[ b ][ a ] = 1;
    }
    int stk[ maxn ];
    recur( 0, N, 0, 0, stk );
    printf("%d\n", ans);
}