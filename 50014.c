
int subset(int numbers[], int n, int K, int S){
	if( K == 0 && S == 0 ) return 1;
	if( n == 0 ) return 0;
	if( S < 0 || K < 0 ) return 0;
	if( n < S ) return 0;
	if( subset( numbers, n - 1, K - numbers[ n - 1 ], S - 1 ) ) return 1;
	return subset( numbers, n - 1, K, S );
}