#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[ 64 ];
	int occur;
	int ncite;
} store;

store ans[ 1024 ] = {};
int in[ 1024 ];

int cmp( const void *a, const void *b ){
	return strcmp( ((store*)a) -> name, ((store*)b) -> name );
}

void compute(paper P[], int N){
	int M = 0;
	for( int i = 0; i < N; i++ ){
		int flag = 1;
		for( int j = 0; j < M && flag; j++ ){
			if( !strcmp( P[ i ].journalName, ans[ j ].name ) ){
				flag = 0;
				ans[ j ].occur ++;
				in[ i ] = j;
			}
		}
		if( flag ){
			in[ i ] = M;
			ans[ M ].occur = 1;
			strcpy( ans[ M ].name, P[ i ].journalName );
			M++;
		}
	}
	for( int i = 0; i < N; i++ )
		for( int j = 0; j < P[ i ].numCitedPaper; j++ )
			ans[ in[ P[ i ].citedPaperIndex[ j ] ] ].ncite ++;
	qsort( ans, M, sizeof( store ), cmp );
	for( int i = 0; i < M; i++ ){
		printf("%s %d/%d\n", ans[ i ].name, ans[ i ].ncite, ans[ i ].occur );
	}
}

#ifdef main

#include <stdio.h>
#define MAXP 1024

int main() {
    int N;
    paper P[MAXP] = {};
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s%d", P[i].journalName, &P[i].numCitedPaper);
        for (int j = 0; j < P[i].numCitedPaper; j++)
            scanf("%d", &P[i].citedPaperIndex[j]);
    }
    compute(P, N);
    return 0;
}

#endif