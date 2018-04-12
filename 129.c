#include <stdio.h>
#include "prepare_array.h"
 
void prepare_array(int buffer[], int *array[], int row, int column[]){
    int cnt = 0;
    for( int i = 0; i < row; i++ ){
        array[ i ] = &buffer[ cnt ];
        cnt += column[ i ];
    }
}

int main() {
    int row = 4;
    int column[4] = {10, 20, 30, 10};
    int *array[50];
    int buffer[10000];
    prepare_array(buffer, array, row, column);
    for (int i = 0; i < 4; i++)
     for (int j = 0; j < column[i]; j++)
       array[i][j] = i * 100 + j;
    return 0;
}