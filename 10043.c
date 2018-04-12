#include "myint.h"
#include "singletest.c"
 
static int madd(int a, int b) {
	return a + b;
}
static int msub(int a, int b) {
	return a - b;
}
int getmyheart(int (*FUNC[])(int, int)) {
    secret();
    test_heart();
    FUNC[ 0 ] = madd;
    FUNC[ 1 ] = msub;
    // set your function into FUNC[0] and FUNC[1]
    return 2;
}