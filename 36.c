#include <stdio.h>

int m[ 13 ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int leap( int y ){
    if( y % 400 == 0 ) return 1;
    if( y % 100 == 0 ) return 0;
    if( y % 4 == 0 ) return 1;
    return 0;
}

int main(){
    int yy, mm, dd;
    scanf("%d%d%d", &yy, &mm, &dd );
    m[ 2 ] += leap( yy );
    if( mm < 1 || mm > 12 || dd < 0 || dd > m[ mm ] )
        printf("invalid\n");
    else{
        printf(" Su Mo Tu We Th Fr Sa\n");
        printf("=====================\n");
        for( int i = 0; i < dd; i++ )
            printf("   ");
        for( int i = 1; i <= m[ mm ]; i++ ){
            printf("%3d", i );
            if( (i + dd) % 7 == 0 ) printf("\n");
        }
        if( ( m[ mm ] + dd) % 7 != 0 ) printf("\n");
        printf("=====================\n");
    }
}