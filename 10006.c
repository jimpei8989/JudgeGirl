#include <stdio.h>
typedef long long ll;

int main(){
    ll cnt = 0;
    ll k;
    while( scanf("%lld", &k ) != EOF ){
        cnt += k;
    }
    printf("%lld\n", cnt );
}