#include <stdio.h>
#include <assert.h>

/*
void swap( int **pa, int **pb ){
    int *tmp = pa;
    pa = pb;
    pb = tmp;
}
 */

#define ptr ptr_array

void snake( const int *ptr_array[100][100], int m){
    int n = m * m;
    for( int i = 0; i < n - 1 ; i++ ){
        for( int j = 0; j < n - 1 - i; j++ ){
            if( *ptr[ j / m ][ j % m ] > *ptr[ ( j + 1 ) / m ][ ( j + 1 ) % m ] ){
                const int *tmp = ptr[ j / m ][ j % m ];
                ptr[ j / m ][ j % m ] = ptr[ ( j + 1 ) / m ][ ( j + 1 ) % m ];
                ptr[ ( j + 1 ) / m ][ ( j + 1 ) % m ] = tmp;
            }
        }
    }
    for( int i = 1; i < m; i+= 2 ){
        for( int j = 0; j < m / 2; j++ ){
            const int *tmp = ptr[ i ][ j ];
            ptr[ i ][ j ] = ptr[ i ][ m - j - 1 ];
            ptr[ i ][ m - j - 1 ] = tmp;
        }
    }
}
 
int main(){
  int array[100][100], check[100][100];
  const int *ptr_array[100][100];
  int i, j, m;
 
  scanf("%d", &m);
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) {
      ptr_array[i][j] = &(array[i][j]);
      scanf("%d", &(array[i][j]));
      check[i][j] = array[i][j];
    }
  snake( ptr_array, m);
  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
//      assert(check[i][j] == array[i][j]);
//      assert((ptr_array[i][j] >= &array[0][0]) && (ptr_array[i][j] <= &array[99][99]));
      printf("%d ", *(ptr_array[i][j]));
    }
    printf("\n");
  }
 
  return 0;
}