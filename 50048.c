int is_leap( int y ){
	if( y % 400 == 0 ) return 1;
	if( y % 100 == 0 ) return 0;
	if( y % 4 == 0 ) return 1;
}



void count_day(int year, int day, int month, int results[7]){
	for( int i = 0; i < 7; i++ ) results[ i ] = 0;
	int k = day;
	int mth[ 13 ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	mth[ 2 ] += is_leap( year );
	for( int i = 1; i < month; i++ ) k += mth[ i ];
	for( int j = 1; j <= mth[ month ]; j++ ){
		results[ k % 7 ]++;
		k++;
	}
}