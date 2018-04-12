#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 32

typedef struct Employee {
	int ID, boss;
	char first_name[ maxn ], last_name[ maxn ];
	int boss_idx;
	int boss_IDs[ maxn ];
}Person;

Person emp[ maxn ];

int getidx_by_name( char *f, char *l, int N ){
	for (int i = 0; i < N; i++)
		if (!strcmp( f, emp[ i ].first_name ) && !(strcmp(l, emp[ i ].last_name) ) )
			return i;
	return -1;
}

int getidx_by_ID( int k, int N ){
	for( int i = 0; i < N; i++ )
		if( emp[ i ].ID == k )
			return i;
	return -1;
}

int is_boss( int A, int B ){
	int tar = emp[ B ].ID;
	for( int i = 0; i < emp[ A ].boss_idx; i++ ){
		if( emp[ A ].boss_IDs[ i ] == tar )
			return 1;
	}
	return 0;
}


int is_colleague( int A, int B ){
	if( emp[ A ].boss_idx == 0 || emp[ B ].boss_idx == 0 ) return 0;
	return emp[ A ].boss_IDs[ emp[ A ].boss_idx - 1 ] == emp[ B ].boss_IDs[ emp[ B ].boss_idx - 1 ];
}

void pre( int N ){
	for( int i = 0; i < N; i++ ){
		int tp = emp[ i ].ID;
		while( emp[ getidx_by_ID( tp, N ) ].boss != tp ){
			tp = emp[ getidx_by_ID( tp, N ) ].boss;
			emp[ i ].boss_IDs[ emp[ i ].boss_idx++ ] = tp;
		}
	}
}

int main(){
	int N;
	scanf("%d", &N );
	for( int i = 0; i < N; i++ ){
		scanf("%d%s%s%d", &emp[ i ].ID, emp[ i ].first_name, emp[ i ].last_name, &emp[ i ].boss );
	}
	pre( N );
	int Q;
	scanf("%d", &Q );
	while( Q-- ){
		char af[ maxn ], al[ maxn ], bf[ maxn ], bl[ maxn ];
		scanf("%s%s%s%s", af, al, bf, bl );
		int A = getidx_by_name( af, al, N );
		int B = getidx_by_name( bf, bl, N );
		if( is_boss( A, B ) )
			printf("subordinate\n");
		else if( is_boss( B, A ) )
			printf("supervisor\n");
		else if( is_colleague( A, B ) )
			printf("colleague\n");
		else printf("unrelated\n");
	}
	return 0;
}