#include "construct.h"
#include <stdio.h>
#include <stdlib.h>
#define lc left
#define rc right
typedef long long ll;

Node *get_Node( int x ){
    Node *tp = (Node*)malloc( sizeof( Node ) );
    tp -> value = x;
    tp -> lc = tp -> rc = NULL;
    return tp;
}

Node *get_link_list( int T[], int N ){
    if( N < 1 ) return NULL;
    Node *tp = get_Node( T[ N - 1 ] );
    tp -> lc = get_link_list( T, N - 1 );
    return tp;
}

int getBalance( int T[], int N ){
    ll sum = 0, tmp = 0;
    for( int i = 0; i < N; i++ ){
        sum += T[ i ];
        tmp += ( (ll)i * T[ i ] );
    }
    for( int i = 0; i < N; i++, tmp -= sum )
        if( tmp == 0 )
            return i;
    return -1;
}

Node *ConstructTree( int T[], int N ){
    int mid = getBalance( T, N );
    if( mid == -1 || N < 3 )
        return get_link_list( T, N );
    else{
        Node *tp = get_Node( T[ mid ] );
        if( mid > 0 ) tp -> lc = ConstructTree( T, mid );
        if( N - mid - 1 > 0 ) tp -> rc = ConstructTree( T + mid + 1, N - mid - 1 );
        return tp;
    }
    return NULL;
}