#include <stdio.h>
typedef long long ll;
int main(){
	int T;
	scanf("%d", &T );
	while( T-- ){
		int flag = 0;
		ll D, a, b, c, A, B, C;
		scanf("%lld%lld%lld%lld%lld%lld%lld", &D, &a, &b, &c, &A, &B, &C );
		ll cnt = 0;
		if( D == 0 ){
			printf("yes\n");
			continue;
		}
		for( int i = 0; i <= a && flag == 0; i++ ){
			for( int j = 0; j <= b && flag == 0; j++ ){
				ll left = D - A*i -B*j;
				if( left < 0 ) continue;
				if( C == 0 ){
					if( left == 0 )
						flag = 1;
				}
				else{
					if( left % C == 0 && left / C <= c )
						flag = 1;
				}
			}
		}
		if( flag ) printf("yes\n");
		else printf("no\n");
	}
}