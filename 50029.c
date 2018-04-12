//tree.h
typedef struct Node {
    int label;
    struct Node *left, *right;
} Node;
 
Node* construct(int array[], int n);

//#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#define lc left
#define rc right
#define val label

Node *newNode( int x ){
	Node *tp = (Node*)malloc( sizeof( Node ) );
	tp -> val = x;
	tp -> lc = tp -> rc = NULL;
	return tp;
}

Node *build( int arr[], int x, int N ){
	if( x >= N ) return NULL;
	Node *ret = newNode( arr[ x ] );
	ret -> lc = build( arr, 2*x+1, N );
	ret -> rc = build( arr, 2*x+2, N );
	return ret;
}

Node *construct( int array[], int N ){
	return build( array, 0, N );
}


#include <stdio.h>
 
void printAndFree(Node *u) {
    if (u == NULL) return;
    printf("%d ", u->label);
    printAndFree(u->left);
    printAndFree(u->right);
    free(u);
}
 
int main() {
    int A[32767], n;
    while (scanf("%d", &n) == 1 && n != 0) {
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        Node *root = construct(A, n);
        printAndFree(root);
        puts("");
    }
    return 0;
}