#include "10016_f.h"
typedef long long ll;

ll gcd( ll a, ll b ){
    if( b == 0 ) return a;
    return gcd( b, a % b );
}

Frac normal(long long a, long long b) {
    /* add your code */
    Frac now;
    ll tp = gcd( a, b );
    now.a = a / tp;
    now.b = b / tp;
    return now;
}
Frac add(Frac x, Frac y) {
    /* add your code */
    ll mom = x.b * y.b;
    ll son = x.a * y.b + x.b * y.a;
    return normal( son, mom );
}
Frac subtract(Frac x, Frac y) {
    /* add your code */
    ll mom = x.b * y.b;
    ll son = x.a * y.b - x.b * y.a;
    return normal( son, mom );
}
Frac multipy(Frac x, Frac y) {
    /* add your code */
    ll mom = x.b * y.b;
    ll son = x.a * y.a;
    return normal( son, mom );
}
Frac divide(Frac x, Frac y) {
    /* add your code */
    ll mom = x.b * y.a;
    ll son = x.a * y.b;
    return normal( son, mom );
}