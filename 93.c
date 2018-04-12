//Heap
#ifndef HEAPH
#define HEAPH

#define MAXHEAP 101
typedef struct Heap{
    int arr[MAXHEAP];
    int siz;
} Heap;
 
void initialize( Heap *heap);
int removeMin( Heap *heap);
void add( Heap *heap, int x);
int isFull( Heap *heap);
int isEmpty( Heap *heap);

#endif

//#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

void swap( int *a, int *b ){
	int tp = (*a);
	(*a) = (*b);
	(*b) = tp;
}

void initialize( Heap *heap){
	heap -> siz = 0;
}

int removeMin( Heap *heap){
	int ret = heap -> arr[ 1 ];
	swap( &(heap -> arr[ 1 ]), &(heap->arr[ heap->siz ]) );
	int tp = 1;
	heap->siz--;
	while( 1 ){
		int tar = tp;
		if( tp * 2 <= heap -> siz && heap -> arr[ tar ] > heap -> arr[ tp * 2 ] )
			tar = tp * 2;
		if( tp * 2 + 1 <= heap -> siz && heap -> arr[ tar ] > heap -> arr[ tp * 2 + 1 ] )
			tar = tp * 2 + 1;
		if( tar == tp ) break;
		swap( &(heap->arr[ tp ]), &(heap->arr[ tar ]) );
		tp = tar;
	}
	return ret;
}

void add( Heap *heap, int x){
	heap -> siz++;
	int tp = heap->siz;
	heap -> arr[ tp ] = x;
	while( tp > 1 && heap->arr[ tp ] < heap->arr[ tp / 2 ] ){
		swap( &(heap->arr[ tp ]), &(heap->arr[ tp / 2 ]) );
		tp /= 2;
	}
}

int isFull( Heap *heap){
	return heap -> siz >= MAXHEAP - 1;
}

int isEmpty( Heap *heap){
	return heap -> siz == 0;
}

int main(){
	int a, b;
	Heap *heap = (Heap*)malloc( sizeof( Heap ) );
	while( scanf("%d%d", &a, &b ) == 2 ){
		if( a == 1 ){
			if( isFull( heap ) ) printf("Heap is full.\n");
			else  add( heap, b );
		}
		if( a == 2 ){
			if( isEmpty( heap ) ) printf("Heap is empty.\n");
			else printf("%d\n", removeMin( heap ) );
		}
		if( a == 3 ){
			printf("siz = %d\n", heap -> siz );
		}
	}
}
