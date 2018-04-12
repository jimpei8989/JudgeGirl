#ifndef _COMPLEX_H
#define _COMPLEX_H
 
typedef struct complex{
	float a, b;
}complex;
 
void init(complex *c, float a, float b);
void complex_print(complex *x);
complex complex_add(complex *x, complex *y);
complex complex_sub(complex *x, complex *y);
complex complex_mul(complex *x, complex *y);
#endif

#include <stdio.h>
#include "complex.h"

void init(complex *c, float a, float b){
	c -> a = a;
	c -> b = b;
}

void complex_print(complex *c){
	printf("%.3f%+.3fi\n", c -> a, c -> b);
}

complex complex_add(complex *x, complex *y){
	complex tmp;
	init( &tmp, x->a + y->a, x->b + y->b );
	return tmp;
}

complex complex_sub(complex *x, complex *y){
	complex tmp;
	init( &tmp, x->a - y->a, x->b - y->b );
	return tmp;
}

complex complex_mul(complex *x, complex *y){
	complex tmp;
	init( &tmp, x->a * y->a - x->b * y->b, x->a * y->b + x->b * y->a );
	return tmp;
}