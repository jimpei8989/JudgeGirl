
#include <stdio.h>
void fill_array(int *ptr[], int n){
    int *begin = ptr[ 0 ];
    int *last = ptr[ n - 1 ];
    int m = last - begin + 1;
    int use[ 1000000 ] = { 0 };
    for( int i = 0; i < n; i++ ){
        int k = ptr[ i ] - begin;
        use[ k ] = 1;
        *ptr[ i ] = i;
    }
    for( int i = 0; i < n; i++ ){
        int *now = ptr[ i ];
        int posi = ptr[ i ] - begin;
        int tp = posi - 1;
        while( tp > -1 && use[ tp ] == 0 ){
            *( begin + tp ) += i;
            tp --;
        }
        tp = posi + 1;
        while( tp < m && use[ tp ] == 0 ){
            *( begin + tp ) += i;
            tp ++;
        }
    }
}

int main() {
    int arr[100] = {};
    int *ptr[100];
    int n = 6, m = 0;
    int A[100] = {0, 5, 6, 9, 3, 12};
    for (int i = 0; i < n; i++) {
        ptr[i] = &arr[A[i]];
        if (A[i] > m)    m = A[i];
    }
    fill_array(ptr, n);
    for (int i = 0; i <= m; i++)
        printf("%d%c", arr[i], " \n"[i==m]);
    return 0;
}