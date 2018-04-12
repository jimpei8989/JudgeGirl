//activity.h

typedef struct Activity {
    int start;
    int end;
} Activity;
 
int select(Activity activities[], int n);

//#include "activity.h"
#include <stdio.h>
#include <stdlib.h>
#define maxn 262144

int cmp( const void *a, const void *b ){
	Activity A = *(Activity*)a;
	Activity B = *(Activity*)b;
	return A.end - B.end;
	if( A.end != B.end ) return A.end - B.end;
	else return A.start - B.start;
}



int select(Activity arr[], int N){
	qsort( arr, N, sizeof( Activity ), cmp );

	int E = 0, cnt = 0;
	for( int i = 0; i < N; i++ ){
		if( E > arr[ i ].start ) continue;
		E = arr[ i ].end;
		cnt++;
#ifdef PRINT
		printf("%d %d\n", arr[ i ].start, arr[ i ].end );
#endif
	}
	return cnt;
}

//#include "activity.h"
#include <stdio.h>
 
#define MAXN 262144
Activity A[MAXN];
int main() {
    int n, cases = 0;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++)
            scanf("%d %d", &A[i].start, &A[i].end);
        int ret = select(A, n);
        printf("%d\n", ret);
    }
    return 0;
}
