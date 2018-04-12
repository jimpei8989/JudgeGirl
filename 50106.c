//construct.h
typedef struct Node{
    char name[16];
    int height;
    int weight;
    struct Node *left, *right;
} Node;
 
Node *ConstructBSTree(int N, char name[][16], int height[], int weight[]);

//#include "construct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define lc left
#define rc right

Node *build( Node *now, char *s, int h, int w ){
    if( now == NULL ){
        now = (Node*)malloc( sizeof( Node ) );
        strcpy( now->name, s );
        now -> height = h;
        now -> weight = w;
        now -> lc = now -> rc = NULL;
        return now;
    }
#ifdef HEIGHT
    if( h < now -> height ) now -> lc = build( now -> lc, s, h, w );
    else now -> rc = build( now -> rc, s, h, w );
#endif
#ifdef WEIGHT
    if( w < now -> weight ) now -> lc = build( now -> lc, s, h, w );
    else now -> rc = build( now -> rc, s, h, w );
#endif
    return now;
}


Node *ConstructBSTree(int N, char name[][16], int height[], int weight[]){
    Node *root = NULL;
    for( int i = 0; i < N; i++ )
        root = build( root, name[ i ], height[ i ], weight[ i ] );
    return root;
}

#include <stdio.h>

#define MAXN 1024
char name[MAXN][16];
int height[MAXN];
int weight[MAXN];
 
void PrintBSTree( Node *root ){
    if (root == NULL)
        return;
    printf("%s\n", root->name);
    PrintBSTree(root->left);
    PrintBSTree(root->right);
    return;
}
 
int main(){
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%s %d %d", name[i], &height[i], &weight[i]);
 
    Node *tree = ConstructBSTree( N, name, height, weight );
 
    PrintBSTree( tree );
    return 0;
}