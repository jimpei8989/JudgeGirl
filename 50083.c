#include <stdio.h>


int main(){
    int N, M, R;
    scanf("%d%d%d", &N, &M, &R );
    int ipt;
    while( scanf("%d", &ipt ) != EOF ){
        int ra = N - ipt;
        int rb = M - ipt;
        if( R == 0 ){
            if( ra >= 0 ) N = ra;
            else if( rb >= 0 ) M = rb;
        }
        else{
            if( ra > rb ){
                if( rb >= 0 ) M = rb;
                else if( ra >= 0 ) N = ra;
            }
            else{
                if( ra >= 0 ) N = ra;
                else if( rb >= 0 ) M = rb;
            }
        }
        printf("%d %d\n", N, M );
    }
}