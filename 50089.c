void place(int bucket[1024],int N,int ball[16384],int M,int method,int result[16384]){
	for( int i = 0; i < M; i++ ){
		int idx = -1;
		if( method == 0 ){
			for( int j = 0; j < N; j++ ){
				if( bucket[ j ] >= ball[ i ] ){
					idx = j;
					break;
				}
			}
		}
		if( method == 1 ){
			int min;
			for( int j = 0; j < N; j++ ){
				if( bucket[ j ] >= ball[ i ] ){
					if( bucket[ j ] < min || idx == -1 ){
						min = bucket[ j ];
						idx = j;
					}
				}
			}
		}
		if( method == 2 ){
			int max;
			for( int j = 0; j < N; j++ ){
				if( bucket[ j ] >= ball[ i ] ){
					if( bucket[ j ] >= max || idx == -1 ){
						max = bucket[ j ];
						idx = j;
					}
				}
			}
		}
		if( idx != -1 ) bucket [ idx ] -= ball[ i ];
		result[ i ] = idx;
	}
}