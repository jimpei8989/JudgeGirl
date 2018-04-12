#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node *lc, *rc;
}Node;

void HLHR( Node *now );
void HRHL( Node *now );

Node *build( char *ipt, int *idx ){
	Node *tmp = (Node*)malloc( sizeof( Node ) );
	tmp -> value = 0;
	tmp -> lc = tmp -> rc = NULL;

	if( '0' <= ipt[ *idx ] && ipt[ *idx ] <= '9' ){
		int x = 0;
		while( '0' <= ipt[ *idx ] && ipt[ *idx ] <= '9' ){
			x = ( x * 10 ) + ( ipt[ *idx ] - '0' );
			(*idx)++;
		}
		tmp -> value = x;
		return tmp;
	}

	if( ipt[ *idx ] == '(' ){
		(*idx)++;
		tmp -> lc = build( ipt, idx );
		tmp -> value += tmp -> lc -> value;
	}
	if( ipt[ *idx ] == ',' ){
		(*idx)++;
		tmp -> rc = build( ipt, idx );
		tmp -> value += tmp -> rc -> value;
	}
	if( ipt[ *idx ] == ')' ){
		(*idx)++;
	}
	return tmp;
}

int main(){
	char ipt[ 4000 ];
	int idx = 0;
	fgets( ipt, 4000, stdin );
	Node *root = build( ipt, &idx );
	HLHR( root );
	return 0;
}

void HLHR( Node *now ){
	printf("%d\n", now -> value );
	if( now -> lc != NULL ) HRHL( now -> lc );
	printf("%d\n", now -> value );
	if( now -> rc != NULL ) HRHL( now -> rc );
}

void HRHL( Node *now ){
	printf("%d\n", now -> value );
	if( now -> rc ) HLHR( now -> rc );
	printf("%d\n", now -> value );
	if( now -> lc ) HLHR( now -> lc );
}