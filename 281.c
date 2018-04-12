#include <stdio.h>



int main(){
	int n;
	while( scanf("%d", &n ) != EOF ){
		int k = 0;
		while( n > 0 ){
			k += n % 2;
			n /= 2;
		}
		printf("%d\n", k );
	}
	return 0;
}