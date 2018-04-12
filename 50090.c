int ***constructTable(int A[], int B[]){
	int siz_a = 0;
	while( A[ siz_a ] != 0 ) siz_a++;
	int ***ptr = ( int*** ) malloc( sizeof( int** ) * ( siz_a + 1 ) );
	int ptr_B = 0;
	for( int i = 0; i < siz_a; i++ ){
		int **tp = ( int** ) malloc( sizeof( int* ) * ( A[ i ] + 1 ) );
		for( int j = 0; j < A[ i ]; j++ ){
			tp[ j ] = &B[ ptr_B ];
			while( B[ ptr_B ] != 0 ) ptr_B++;
			ptr_B++;
		}
		ptr[ i ] = tp;
	}
	return ptr;
}