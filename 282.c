#include <stdio.h>

int main(){
	long long n;
	while( scanf("%lld", &n ) != EOF ){
		int cnt = 0;
		while( n > 0 ){
			cnt += n % 2;
			n /= 2;
		}
		printf("%d\n", cnt );
	}
	return 0;
}