#include <stdio.h>

int mp[ 4 ][ 4 ];
int x[ 16 ], y[ 16 ];

void swap( int *a, int *b ){
    int c = *a;
    *a = *b;
    *b = c;
}

int dx[ 4 ] = { 1, 0, -1, 0 };
int dy[ 4 ] = { 0, 1, 0, -1 };

int check(){
    for( int i = 0; i < 4; i++ ){
        for( int j = 0; j < 4; j++ ){
            if( ( i * 4 + j + 1 ) % 16 != mp[ i ][ j ] ) return 0;
        }
    }
    return 1;
}

void print(){
    for( int i =0 ; i < 4; i++ ){
        for( int j = 0; j <4 ; j++ ){
            printf("%d", mp[ i ][ j ] );
            if( j == 3 ) printf("\n");
            else printf(" ");
        }
    }
}

int main(){
    for( int i = 0; i < 4; i++ ){
        for( int j = 0; j < 4; j++ ){
            scanf("%d", &mp[ i ][ j ] );
            x[ mp[ i ][ j ] ] = i;
            y[ mp[ i ][ j ] ] = j;
        }
    }
    int win = 0;
    int k;
    while( scanf("%d", &k ) != EOF ){
        if( k == 0 ) break;
        int xx = x[ k ], yy = y[ k ];
        for( int i = 0; i < 4; i++ ){
            int nx = xx + dx[ i ];
            int ny = yy + dy[ i ];
            if( nx < 0 || nx > 3 || ny < 0 || ny > 4 ) continue;
            if( mp[ nx ][ ny ] == 0 ){
                swap( &x[ k ], &x[ 0 ] );
                swap( &y[ k ], &y[ 0 ] );
                mp[ nx ][ ny ] = k;
                mp[ xx ][ yy ] = 0;
                break;
            }
        }
        if( check() == 1 ){
            win = 1;
            break;
        }
    }
    print();
    if( win == 0 ) printf("0\n");
    else printf("%d %d\n", 1, k );
}