#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int T;
    scanf("%d", &T );
    while( T -- ){
        char s1[ 128 ], s2[ 128 ];
        scanf("%s", s1 );
        scanf("%s", s2 );
        int l1 = strlen( s1 );
        int l2 = strlen( s2 );

        int state = 1;
        if( strcmp( s1, s2 ) == 0 ) state = 1;
        else if( l1 == l2 ){
            int cnt = 0;
            for( int i = 0; i < l1; i++ ){
                if( s1[ i ] != s2[ i ] ){
                    if( s1[ i ] == s2[ i + 1 ] && s2[ i ] == s1[ i + 1 ] ){
                        cnt ++;
                        i++;
                    }
                    else state = 0;
                }
            }
            if( cnt > 1 ) state = 0;
        }
        else if( l1 - l2 == 1 ){
            int diff = 0;
            int idx1 = 0, idx2 = 0;
            while( idx1 < l1 && idx2 < l2 ){
                if( s1[ idx1 ] != s2[ idx2 ] ){
                    diff ++;
                    idx1 ++;
                }
                else{
                    idx1 ++;
                    idx2 ++;
                }
            }
            diff += abs( (l1 - idx1) - (l2 - idx2) );
            if( diff > 1 ) state = 0;
        }
        else if( l2 - l1 == 1 ){
            int diff = 0;
            int idx1 = 0, idx2 = 0;
            while( idx1 < l1 && idx2 < l2 ){
                if( s1[ idx1 ] != s2[ idx2 ] ){
                    diff ++;
                    idx2 ++;
                }
                else{
                    idx1 ++;
                    idx2 ++;
                }
            }
            diff += abs( (l1 - idx1) - (l2 - idx2) );
            if( diff > 1 ) state = 0;
        }
        else state = 0;

        if( state ) printf("yes\n");
        else printf("no\n");
    }
}