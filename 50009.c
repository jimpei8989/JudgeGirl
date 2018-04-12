int snake(int *ptr, int *row, int *column){
	*row = 0;
	*column = 0;
	int state = 1;
	for( int i = 0; ptr[ i ] || i == 0; i++ ){
		if( state ) (*column) ++;
		if( ptr[ i ] + 1 != ptr[ i + 1 ] ) state = 0;
	}
	for( ;; (*row) ++ ){
		for( int i = 0; i < *column; i++ ){
			if( *row % 2 ){
				int j = *column - i - 1;
				int expect = *row * *column + j;
				if( expect != ptr[ *row * *column + i ] ){
					*column = j;
					return 0;
				}
			}
			else{
				int expect = *row * *column + i;
				if( expect != ptr[ *row * *column + i ] ){
					*column = i;
					return 0;
				}
			}
		}
		if( ptr[ *row * *column + *column ] == 0 ){
			(*row) ++;
			return 1;
		}
	}
}

#include <stdio.h>

int main(void)
{
    int trav[1024] = {0}, row = 0, column = 0, res = 0;
    scanf("%d %d", &trav[0], &trav[1]);
    for(int i = 1; trav[i]; i++)
      scanf("%d", &trav[i + 1]);
    res = snake(trav, &row, &column);
    if(res) printf("%d %d\n", row, column);
    else printf("err %d %d\n", row, column);
    return 0;
}