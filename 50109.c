#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn ( 1 << 15 )
#define maxl ( 1 << 4 )

typedef struct {
	char name[ maxl ];
	int num;
}Data;

Data data[ maxn ];

int cmp( const void *a, const void *b ){
	Data A = *(Data*)a;
	Data B = *(Data*)b;
	if( strcmp( A.name, B.name ) == 0 )
		return -( A.num - B.num );
	return strcmp( A.name, B.name );
}

int main(){
	int N = 0;
	while( scanf("%s %d", data[ N ].name, &data[ N ].num ) != EOF ) N++;
	qsort( data, N, sizeof( Data ), cmp );
	for( int i = 0; i < N;){
		char *str = data[ i ].name;
		int H = 0;
		while( i < N && strcmp( data[ i ].name, str ) == 0 ){
			if( data[ i ].num > H ) H++;
			i++;
		}
		printf("%s %d\n", str, H );
	}
	return 0;
}