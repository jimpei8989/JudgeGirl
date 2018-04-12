#include <stdio.h>

#define MAXN 512

int max( int a, int b ){
    return( a > b ? a : b );
}

int main(){
    int M, N;
    int idx[ MAXN ] = {0};
    int avai[ MAXN ] = {0};
    int arri[ MAXN ] = {0};
    int tstp[ MAXN ] = {0};
    int wcnt[ MAXN ] = {0};
    int num[ MAXN ][ MAXN ];
    int dur[ MAXN ][ MAXN ];
    int end[ MAXN ];
    int done = 0;
    scanf("%d%d", &N, &M );
    for( int i = 0; i < M; i++ ){
        scanf("%d%d", &arri[ i ], &wcnt[ i ] );
        for( int j = 0; j < wcnt[ i ]; j++ )
            scanf("%d%d", &num[ i ][ j ], &dur[ i ][ j ] );
        tstp[ i ] = arri[ i ];
    }
    while( done < M ){
        int now = -1;
        int least_cpt = 1e9;
        for( int i = 0; i < M; i++ ){
            if( idx[ i ] == wcnt[ i ] ) continue;
            int cpt = max( tstp[ i ], avai[ num[i][idx[i]] ] );
            cpt += dur[ i ][ idx[ i ] ];
            if( cpt < least_cpt ){
                least_cpt = cpt;
                now = i;
            }
        }
        int cur_m = num[ now ][ idx[now] ];
        tstp[ now ] = least_cpt;
        avai[ cur_m ] = tstp[ now ];
#ifdef DEBUG
        printf("now = %d, cur_m = %d, lcpt = %d, tstp = %d\n", now+1, cur_m, least_cpt, tstp[ now ] );
#endif
        idx[ now ]++;
        if( idx[ now ] == wcnt[ now ] ) done ++;
    }
    for( int i = 0; i < M; i++ )
        printf("%d\n", tstp[ i ] );
}