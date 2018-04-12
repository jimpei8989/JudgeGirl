#include <stdio.h>
#include <math.h>
typedef long long int ll;

int main(){
    ll a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c );
    ll d, e, f;
    for( ll i = -100000; i <= 100000; i++ ){
        if(  i * i * i + a * i * i + b * i + c == 0 ){
            d = -i;
        }
    }
    c = b - d * ( a - d );
    b = a - d;

    e = ( -b +  sqrt( b * b - 4 * 1 * c ) ) / 2;
    f = ( -b -  sqrt( b * b - 4 * 1 * c ) ) / 2;
    printf("%lld %lld %lld\n", d, -e, -f );

}
