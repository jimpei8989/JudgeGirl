#include <stdio.h>

typedef unsigned long long ull;

int main(){
	ull a, b, c;
	while( scanf("%lld%lld%lld", &a, &b, &c ) == 3 ){
		printf("%lld\n", ( ( ( a % c ) * ( b % c ) % c ) ))
	}
}