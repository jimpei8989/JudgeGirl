#include "construct.h"
#include <stdio.h>
#include <stdlib.h>
#define S small
#define L large
#define lc left
#define mc mid
#define rc right
 
Node *newNode(){
    Node *now = (Node*)malloc(sizeof(Node));
    now -> S = now -> L = -1;
    now -> lc = now -> mc = now -> rc = NULL;
    return now;
}
 
Node *insert(Node *now, int x){
    if( now == NULL ){
        Node *tmp = newNode();
        tmp -> L = x;
        return tmp;
    }
    if( now -> S == -1 ){
        now -> S = x;
        if( now -> S > now -> L ){
            int k = now -> L;
            now -> L = now -> S;
            now -> S = k;
        }
        return now;
    }
    if( x < now -> S ){
        now -> lc = insert( now -> lc, x );
    }
    else if( x < now -> L ){
        now -> mc = insert( now -> mc, x );
    }
    else{
        now -> rc = insert( now -> rc, x );
    }
    return now;
}
 
Node*ConstructTree(int sequence[],int N){
    Node *root = NULL;
    for( int i = 0; i < N; i++ ){
        root = insert( root, sequence[ i ] );
    }
    return root;
}