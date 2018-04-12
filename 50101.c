#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "componentPart.h"

int getPrice( ComponentPart list[], int x ){
	if (list[ x ].price != 0) return list[ x ].price;
	int cnt = 0;
	for (int i = 0; i < list[ x ].numComponent; i++) 
		cnt += getPrice( list, list[ x ].componentPartList[ i ] );
	return list[ x ].price = cnt;
}

int cmp( const void *a, const void *b ){
	return strcmp( ((ComponentPart*)a)->name, ((ComponentPart*)b)->name );
}

void findPrice(int N, ComponentPart list[]){
	for (int i = 0; i < N; i++)
		if( list[ i ].price == 0 )
			list[ i ].price = getPrice( list, i );
	qsort( list, N, sizeof( ComponentPart ), cmp );
	for (int i = 0; i < N; i++)
		printf("%s %d\n", list[ i ].name, list[ i ].price);
}