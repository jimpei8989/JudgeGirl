#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 10000
typedef unsigned long long ull;

typedef struct{
    unsigned int id;
    char name[ 32 ];
}Person;

typedef struct{
    unsigned int id1;
    unsigned int id2;
}Relationship;

typedef struct{
	int id;
	Node *child[ 32 ];
}Node;

void ReadData( FILE *fin, Node *root, int *P, int *F ){
	fread( P, sizeof( int ), 1, fin );
	for( int i = 0; i < *P; i++ ){
		Person ipt;
		fread( &ipt, sizeof( Person ), 1, fin );
		build( root, )
	}
	fread( F, sizeof( int ), 1, fin );
	for( int i = 0; i < *F; i++ ){
		Relationship ipt;
		fread( &ipt, sizeof( Relationship ), 1, fin );
		connected[ ipt.id1 ][ (ipt.id2) / 64 ] |= ( (1ull) << ((ipt.id2) % 64) );
		connected[ ipt.id2 ][ (ipt.id1) / 64 ] |= ( (1ull) << ((ipt.id1) % 64) );
	}
	qsort( person, *P, sizeof( Person ), cmp );
}

int getID( char *tar, int L, int R ){
	if( L == R - 1 ) return person[ L ].id;
	int M = ( L + R ) >> 1;
	if( strcmp( tar, person[ M ].name ) < 0 ) return getID( tar, L, M );
	else return getID( tar, M, R );
}

int main(){
	int P, F;
	FILE *fin = fopen( "friends", "rb" );
	ReadData( fin, &P, &F );
	char A[ 32 ], B[ 32 ];
	while( scanf("%s%s", A, B ) == 2 ){
		int idA = getID( A, 0, P );
		int idB = getID( B, 0, P );
		if( connected[ idA ][ idB / 64 ] & ( (1ull) << idB % 64 ) ) printf("yes\n");
		else printf("no\n");
	}
}
