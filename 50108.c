#define MAXLENGTH 5

typedef struct node{
    int value;
    struct node*left;
    struct node*right;
}Node;

//#include "construct.h"
#include <stdio.h>
#include <stdlib.h>
#define maxn (1<<14)
#define val value
#define lc left
#define rc right

Node *newNode( int x ){
	Node *now = (Node*)malloc( sizeof( Node ) );
	now -> val = x;
	now -> lc = now -> rc = NULL;
	return now;
}

int cmp( const void *a, const void *b ){
	return *(int*)a - *(int*)b;
}

Node *ConstructList( int arr[], int N ){
	if( N <= 0 ) return NULL;
	Node *now = newNode( arr[ N - 1 ] );
	now -> lc = ConstructList( arr, N - 1 );
	return now;
}

int get_idx( int arr[], int N, int K ){
	int new_arr[ maxn ];
	for( int i = 0; i < N; i++ )
		new_arr[ i ] = arr[ i ];
	qsort( new_arr, N, sizeof( int ), cmp );
	for( int i = 0; i < N; i++ )
		if( arr[ i ] == new_arr[ N - K ] )
			return i;
	return -1;
}


Node *ConstructTree( int arr[], int N ){
	if( N < MAXLENGTH )
		return ConstructList( arr, N );
	int x = get_idx( arr, N, MAXLENGTH );
	Node *now = newNode( arr[ x ] );
	now -> lc = ConstructTree( arr, x );
	now -> rc = ConstructTree( arr + x + 1, N - x - 1);
	return now;
}


#include <stdio.h>
#define MAXN 16384
 
int sequence[MAXN];
 
void PrintTree( Node *root ){
    if (root == NULL)
        return;
    printf("%d\n", root->value);
    PrintTree(root->left);
    PrintTree(root->right);
    return;
}

int main(){
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &sequence[i]);
    Node *tree = ConstructTree( sequence, N );
    PrintTree( tree );
    return 0;
}