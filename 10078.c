#ifndef _DOLL_H
#define _DOLL_H
 
typedef struct Doll {
    char top, bottom;
    struct Doll *interior;
} Doll;
 
Doll *newDoll(char top, char bottom);
void package(Doll *outer, Doll *inter);
const char* doll_c_str(Doll *doll);

#endif

#include "doll.h"
#include <stdio.h>
#include <stdlib.h>

Doll *newDoll(char top, char bottom){
	Doll *tp = (Doll*)malloc( sizeof( Doll ) );
	tp -> top = top;
	tp -> bottom = bottom;
	tp -> interior = NULL;
	return tp;
}
void package(Doll *outer, Doll *inter){
	outer -> interior = inter;
}

int get_size( Doll *doll ){
	if( doll == NULL ) return 0;
	return get_size( doll -> interior ) + 1;
}

const char* doll_c_str(Doll *now){
	int N = get_size( now );
	char *str = (char*)malloc( 2*N + 1 );
	str[ 2 * N ] = 0;
	for( int i = 0; i < N; i++ ){
		str[ i ] = now -> top;
		str[ 2 * N - 1 - i ] = now -> bottom;
		now = now -> interior;
	}
	return str;
}