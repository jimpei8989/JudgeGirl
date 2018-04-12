#include <stdio.h>
#include "node.h"

int getLength( struct node *now ){
	if( now -> next == NULL ) return 1;
	return getLength( now -> next ) + 1;
}

struct node *getNode(struct node *head, unsigned int x){
	int N = getLength( head );
	if( x >= N ) return NULL;
	struct node *now = head;
	x = ( N - x - 1 );
	while( x-- ){
		now = now -> next;
	}
	return now;
}