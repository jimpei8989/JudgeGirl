#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn ( 1 << 17 )
#define maxl ( 1 << 6 )

typedef struct Data{
	int height, weight;
	float bmi;
	char name[ maxl ];
} Data;

Data data[ maxn ];

int cmp( const void *pa, const void *pb ){
	Data A = *(Data*)pa;
	Data B = *(Data*)pb;
	if( A.bmi != B.bmi ) return A.bmi > B.bmi ? 1 : -1; 
	if( A.height != B.height ) return A.height - B.height;
	if( A.weight != B.weight ) return A.weight - B.weight;
	return strcmp( A.name, B.name );
}

int main(){
	int N; scanf("%d", &N );
	for( int i = 0; i < N; i++ ){
		scanf("%s %d %d", data[ i ].name, &data[ i ].height, &data[ i ].weight );
		data[ i ].bmi = (float)data[ i ].weight / data[ i ].height / data[ i ].height;
	}
	qsort( data, N, sizeof( Data ), cmp );
	for( int i = 0; i < N; i++ )
		printf("%s %d %d\n", data[ i ].name, data[ i ].height, data[ i ].weight );
}