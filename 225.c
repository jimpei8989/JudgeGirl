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

Person *person;
ull **connected;

int cmp( const void *a, const void *b ){
	return strcmp( ((Person*)a)->name, ((Person*)b)->name );
}

void ReadData( FILE *fin, int *P, int *F ){
	fread( P, sizeof( int ), 1, fin );
	person = (Person*)malloc( sizeof( Person ) * ( *P + 1 ) );
	connected = ( ull** )malloc( sizeof( ull* ) * ( *P + 1 ) );
	for( int i = 0; i < *P; i++ )
		connected[ i ] = ( ull* )malloc( sizeof( ull ) * ( ( *P / 64) + 1) );
	fread( person, sizeof( Person ), *P, fin );
	fread( F, sizeof( int ), 1, fin );
	Relationship ipt;
	for( int i = 0; i < *F; i++ ){
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
