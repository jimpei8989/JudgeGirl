#include <stdio.h>

int evaluate_f(int *iptr[], int n, int *index){
    int x = *iptr[ 0 ];
    int y = *( iptr[ 0 ] + 1 );
    *index = 0;
    int m = 4 * x - 6 * y;
    
    for( int i = 1; i < n; i++ ){
        int nx = *iptr[ i ];
        int ny = *( iptr[ i ] + 1 );
        if( m < nx * 4 - ny * 6 ){
            m = nx * 4 - ny * 6;
            *index = i;
        }
    }
    
    return m;
}
 
int main(){
  int a[] = { 9, 7 };
  int b[] = { 3, 2 };
  int c[] = { 3, 2 };
  int d[] = { 9, 7 };
  int *iptr[] = { a, b, c, d };
  int max, index;
  max = evaluate_f(iptr, 4, &index);
  printf("%d %d\n", max, index);
}