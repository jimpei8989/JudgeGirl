#include <stdio.h>

void processSetMatrix(int ***ptr){
	int start = 0;
	int idx_mat = 0;
	while( ptr[ idx_mat ] != NULL ){
		int idx_arr = 0;
		while( ptr[ idx_mat ][ idx_arr ] != NULL ){
			int idx_set = 0;
			while( ptr[ idx_mat ][ idx_arr ][ idx_set ] != 0 ){
				if( start ) printf(" ");
				start = 1;
				printf("%d", ptr[ idx_mat ][ idx_arr ][ idx_set ]);
				idx_set++;
			}
			idx_arr++;
		}
		idx_mat++;
	}
}