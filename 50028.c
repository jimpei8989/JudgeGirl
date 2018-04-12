//subtree.h
typedef struct Node {
    int label;
    struct Node *left, *right;
} Node;
 
int getNode(Node *root, int label[], int k);


//#include "subtree.h"
#include <stdio.h>
#define lc left
#define rc right
#define val label

typedef struct Package{
	int ret;
	int with_K;
}Package;

Package solve( Node *now, int label[], int K ){
	Package tmp;
	if( now == NULL ){
		tmp.ret = 0;
		tmp.with_K = 0;
	}
	else{
		int ret = 0, with_K = 0;
		Package lft = solve( now -> lc, label, K );
		ret += lft.ret;
		Package rgt = solve( now -> rc, label + ret, K );
		ret += rgt.ret;
		if( lft.with_K || rgt.with_K || now -> val == K ) with_K = 1;
		if( now -> val != K && lft.with_K && rgt.with_K ) label[ ret++ ] = now -> val;
		tmp.ret = ret;
		tmp.with_K = with_K;
	}
	return tmp;
}

int getNode( Node *root, int label[], int k ){
	return solve( root, label, k ).ret;
}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
Node* newNode(int label, Node *l, Node *r) {
    Node *u = (Node *) malloc(sizeof(Node));
    u->label = label, u->left = l, u->right = r;
    return u;
}
 
int main() {
    Node *root = newNode(
        10,
            newNode(
                5,
                    newNode(1, NULL, NULL),
                    newNode(1, NULL, NULL)                
            ),
            newNode(
                7,
                    newNode(1, NULL, NULL),
                    newNode(5, NULL, NULL)                
            )
    );
    int k;
    while (scanf("%d", &k) == 1) {
        int A[128];
        int n = getNode(root, A, k);
        printf("%d\n", n);
        for (int i = 0; i < n; i++)
            printf("%d%c", A[i], i == n-1 ? '\n' : ' ');
    }
    return 0;
}