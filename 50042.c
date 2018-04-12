#include <stdio.h>

int main(){
    int n, m;
    scanf("%d%d", &n, &m );
    int ln, lm;
    int M = -1;
    for( int i = 1; i <= n; i++ ){
        int m1 = -1, m2 = -1;
        int p1 = 0, p2 = 0;
        for( int j = 1; j <= m; j++ ){
            int now;
            scanf("%d", &now );
            if( now >= M ){
                ln = i;
                lm = j;
                M = now;
            }
            if( now >= m1 ){
                m2 = m1;
                p2 = p1;
                
                m1 = now;
                p1 = j;
            }
            else if( now >= m2 ){
                m2 = now;
                p2 = j;
            }
        }
        printf("%d %d\n", p1, p2 );
    }
    printf("%d %d\n", ln, lm );
}