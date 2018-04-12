#include <stdio.h>
 
int mp[ 9 ][ 9 ] = { 0 };
int ipt[ 9 ][ 9 ] = { 0 };

void init(){
    for( int i = 0; i < 9; i++ )
        for( int j = 0; j < 9; j++ )
            mp[ i ][ j ] = -1;

}

void input(){
    for( int i = 0; i < 9; i++ )
        for( int j = 0; j < 9; j++ )
            scanf("%d", &ipt[ i ][ j ] );
}

void pre(){
    
}
 
int check(){
    for( int i = 0; i < 9; i++ ){
        for( int j = 0; j < 9; j++ ){
            if( ipt[ i ][ j ] != 0 ) return 0;
        }
    }
    for( int i = 0; i < 9; i++ ){
        for( int j = 0; j < 9; j++ ){
            printf("%d", mp[ i ][ j ] );
            if( j == 8 ) printf("\n");
            else printf(" ");
        }
    }
    return 1;
}
 
int fill( int now, int k ){
    
}
 
int recursion( int now ){
    if( now == 81 ){
        return check();
    }
    int nx = now / 9;
    int ny = now % 9;
    if( mp[ nx ][ ny ] != -1 ){
        if( nx >= 1 && ny >= 1 )
            if( ipt[ nx - 1 ][ ny - 1 ] > 0 && mp[ nx ][ ny ] == 0 )
                return 0;
        return recursion( now + 1 );
    }
    int state[ 2 ] = { 0 };
     
    
}
 
int main(){
    init();
    input();
    pre();
    int state = recursion( 0 );
    if( state == 0 ) printf("no solution\n");
    for( int i = 0; i <9; i++ )
        for( int j = 0; j < 9; j++ )
            printf("%d%c", mp[ i ][ j ], " \n"[ j == 8 ] );
 
}