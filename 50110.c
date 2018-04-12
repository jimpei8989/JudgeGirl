// operation.h
typedef struct Node{
    int n;
    struct Node *left, *right;
}Node;
 
Node *FlipTree(Node *root);
int isIdentical(Node *tree1, Node *tree2);
void depthAvg(Node *root);

//operation.c
//#include "operations.h"
#include <stdio.h>
#include <stdlib.h>
#define val n
#define lc left
#define rc right

Node *newNode(){
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp -> n = 0;
	tmp -> lc = tmp -> rc = NULL;
	return tmp;
}

Node *FlipTree(Node *root){
	if( root == NULL ) return NULL;
	Node *tmp = newNode();
	Node *tmpl = FlipTree( root -> rc );
	Node *tmpr = FlipTree( root -> lc );
	tmp -> val = root -> val;
	tmp -> lc = tmpl;
	tmp -> rc = tmpr;
	return tmp;
}

int isIdentical(Node *A, Node *B ){
	if (A == NULL && B == NULL) return 1;
	if (A -> val != B -> val) return 0;
	if (A -> lc == NULL && B -> lc != NULL) return 0;
	if (A -> lc != NULL && B -> lc == NULL) return 0;
	if (A -> rc == NULL && B -> rc != NULL) return 0;
	if (A -> rc != NULL && B -> rc == NULL) return 0;
	return isIdentical(A->lc, B->lc) & isIdentical(A->rc, B->rc);
}

void traverse(Node *now, int depth, int *cnt, int *sum){
	if (now->lc == NULL && now -> rc == NULL) {
		(*cnt) += 1;
		(*sum) += depth;
		return;
	}
	else{
		if (now -> lc != NULL) traverse(now -> lc, depth + 1, cnt, sum);
		if (now -> rc != NULL) traverse(now -> rc, depth + 1, cnt, sum);
	}
}

void depthAvg(Node *root){
	int sum = 0, cnt = 0;
	traverse(root, 0, &cnt, &sum);
	printf("%d/%d\n", sum, cnt);
}

//main1.c
#include <stdio.h>
 
int main() {
  Node tree1[9];
 
  for(int i = 0; i < 9; i++){
    tree1[i].n = i;
    tree1[i].left = tree1[i].right = NULL;
  }
 
  tree1[0].left = &tree1[1];
  tree1[0].right = &tree1[2];
  tree1[1].left = &tree1[3];
  tree1[1].right = &tree1[4];
  tree1[2].left = &tree1[5];
  tree1[2].right = &tree1[8];
  tree1[4].left = &tree1[6];
  tree1[6].right = &tree1[7];
 
  depthAvg(&tree1[0]);
  return 0;
}