//memory.h

typedef struct Node{
	int beg, end, val;
	struct Node *next;
}Node;
typedef struct Node Memory;


void initMemory(Memory *memory, int length);
void printMemory(Memory *memory);
void allocateMemory(Memory *memory, int start, int length);
void freeMemory( Memory *memory, int S, int N );

//memory.c
//#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Node *newNode( int beg, int end, int val, Node *next ){
	if( beg == end ) return next;
	Node *now = (Node*)malloc( sizeof( Node ) );
	now -> beg = beg;
	now -> end = end;
	now -> val = val;
	now -> next = next;
	return now;
}

void initMemory( Node *head, int N ){
	head -> next = newNode( 0, N, 0, NULL );
}

void printMemory( Node *head ){
	Node *now = head -> next;
	printf("==========\n");
	while( now != NULL ){
		if( now -> val == 0 )
			printf("start %d, length %d\n", now -> beg, now -> end - now -> beg );
		now = now -> next;
	}
}

void update( Node *head, int S, int N, int V ){
	Node *now = head -> next;
	while( now != NULL && now -> end <= S ) now = now -> next;
	assert( now != NULL );
	Node *rgt = newNode( S + N, now -> end, now -> val, now -> next );
	if( now -> beg == S ){
		now -> end = S + N;
		now -> val = 1;
		now -> next = rgt;
	}
	else{
		Node *ins = newNode( S, S + N, V, rgt );
		now -> end = S;
		now -> next = ins;
	}
}

void allocateMemory( Node *head, int S, int N ){
	update( head, S, N, 1 );
}
void freeMemory( Memory *head, int S, int N ){
	update( head, S, N, 0 );
}

//main.c

int main() {
        Memory myMemory;
        initMemory(&myMemory, 100);
        printMemory(&myMemory);
        allocateMemory(&myMemory, 0, 100);
        printMemory(&myMemory);
        /*
        allocateMemory(&myMemory, 70, 10);
        printMemory(&myMemory);
        allocateMemory(&myMemory, 0, 10);
        printMemory(&myMemory);
        allocateMemory(&myMemory, 30, 10);
        printMemory(&myMemory);
        */
        return 0;
}