#include <stdio.h>

int main(){
	int n;
	while( scanf("%d", &n ) != EOF ){
		int cnt = 0;
		int big = 0;
		while( n > 0 ){
			cnt ++;
			if( n % 2 == 0 ) cnt = 0;
			big = cnt > big ? cnt : big;
			n /= 2;
		}
		printf("%d\n", big );
	}
	return 0;
}