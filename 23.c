int max(int *iptr[], int n){
    int m = *iptr[ 0 ];
    for( int i = 1; i < n; i++ ){
        if( m < *iptr[ i ] ) m = *iptr[ i ];
    }
    return m;
}


#include <stdio.h>
 
int main() {
    int n, i;
    int array[100];
    int *iptr[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &(array[(i + 3) % n]));
        iptr[i] = &(array[(i + 3) % n]);
    }
    printf("%d\n", max(iptr, n));
    return 0;
}