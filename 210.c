#pragma gcc optimize ("unrolled loops")
#pragma gcc optimize ("-O3")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DATA{
	char lastname[ 128 ], firstname[ 128 ], ID[ 128 ];
	int salary, age;
}Data;

int use( char *ipt ){
	if( !strcmp( ipt, "lastname" ) ) return 0;
	if( !strcmp( ipt, "firstname" ) ) return 1;
	if( !strcmp( ipt, "ID" ) ) return 2;
	if( !strcmp( ipt, "salary" ) ) return 3;
	if( !strcmp( ipt, "age" ) ) return 4;
	return -1;
}

void print( Data tmp, int *queue, int n ){
	for( int i = 0; i < n; i++ ){
		if( queue[ i ] == 0 ) printf("%s", tmp.lastname );
		if( queue[ i ] == 1 ) printf("%s", tmp.firstname );
		if( queue[ i ] == 2 ) printf("%s", tmp.ID );
		if( queue[ i ] == 3 ) printf("%d", tmp.salary );
		if( queue[ i ] == 4 ) printf("%d", tmp.age );
		if( i == n - 1 ) printf("\n");
		else printf(" ");
	}
}

int main(){
	Data data[ 64 ];
	int N;
	scanf("%d", &N );
	for( int i = 0; i < N; i++ )
		scanf("%s%s%s%d%d", data[ i ].lastname, data[ i ].firstname, 
			data[ i ].ID, &data[ i ].salary, &data[ i ].age );
	int Q;
	scanf("%d", &Q );
	while( Q-- ){
		int idx = 0;
		int queue[ 16 ];
		char ipt[ 1024 ];
		while( scanf("%s", ipt ) != EOF ){
			if( strcmp( ipt, "where" ) == 0 ) break;
			if( use( ipt ) != -1 )
				queue[ idx++ ] = use( ipt );
		}
		char field[ 1024 ], oper[ 1024 ], cons[ 1024 ];
		scanf("%s%s%s", field, oper, cons );
		int cmp = use( field );
		int x = atoi( cons );
		if( cmp == 0 ){
			for( int i = 0; i < N; i++ ){
				if( strcmp( oper, "==" ) == 0 && strcmp( data[ i ].lastname, cons) == 0 ) print( data[ i ], queue, idx );
				if( strcmp( oper, "==" ) != 0 && strcmp( data[ i ].lastname, cons) != 0 ) print( data[ i ], queue, idx );		
			}
		}
		if( cmp == 1 ){
			for( int i = 0; i < N; i++ ){
				if( strcmp( oper, "==" ) == 0 && strcmp( data[ i ].firstname, cons) == 0 ) print( data[ i ], queue, idx );
				if( strcmp( oper, "==" ) != 0 && strcmp( data[ i ].firstname, cons) != 0 ) print( data[ i ], queue, idx );		
			}
		}
		if( cmp == 2 ){
			for( int i = 0; i < N; i++ ){
				if( strcmp( oper, "==" ) == 0 && strcmp( data[ i ].ID, cons) == 0 ) print( data[ i ], queue, idx );
				if( strcmp( oper, "==" ) != 0 && strcmp( data[ i ].ID, cons) != 0 ) print( data[ i ], queue, idx );		
			}
		}
		if( cmp == 3 ){
			for( int i = 0; i < N; i++ ){
				if( strcmp( oper, "==" ) == 0 && data[ i ].salary == x ) print( data[ i ], queue, idx );
				if( strcmp( oper, "<" ) == 0 && data[ i ].salary < x ) print( data[ i ], queue, idx );
				if( strcmp( oper, ">" ) == 0 && data[ i ].salary > x ) print( data[ i ], queue, idx );
			}
		}
		if( cmp == 4 ){
			for( int i = 0; i < N; i++ ){
				if( strcmp( oper, "==" ) == 0 && data[ i ].age == x ) print( data[ i ], queue, idx );
				if( strcmp( oper, "<" ) == 0 && data[ i ].age < x ) print( data[ i ], queue, idx );
				if( strcmp( oper, ">" ) == 0 && data[ i ].age > x ) print( data[ i ], queue, idx );
			}
		}
	}
}