#include <stdio.h>
#include <string.h>
#define maxn 128
#define maxl 64
char author[ maxn ][ maxl ];
char book[ maxn ][ maxl ];
int book_aut[ maxn ];
int cnt[ maxn ];
int idx[ maxn ];
int idx_a;

int main(){
	int n;
	scanf("%d", &n );
	for( int i = 0; i < n; i++ ){
		char A[ maxl ];
		scanf("%s%s", A, book[ i ] );
		int auth_ID = -1;
		for( int j = 0; j < idx_a; j++ )
			if( strcmp( A, author[ j ] ) == 0 )
				auth_ID = j;
		if( auth_ID == -1 ){
			strcpy( author[ idx_a ], A );
			auth_ID = idx_a++;
		}
		book_aut[ i ] = auth_ID;
	}
	char tar[ maxl ];
	int x;
	while( scanf("%s%d", tar, &x ) != EOF ){
		for( int i = 0; i < n; i++ )
			if( strcmp( book[ i ], tar ) == 0 )
				cnt[ book_aut[ i ] ] += x;
	}
	int max = cnt[ 0 ], maxid = 0;
	for( int i = 1; i < idx_a; i++ ){
		if( cnt[ i ] > max ){
			max = cnt[ i ];
			maxid = i;
		}
		if( cnt[ i ] == max && strcmp( author[ i ], author[ maxid ] ) < 0 ){
			max = cnt[ i ];
			maxid = i;
		}
	}
	printf("%s %d\n", author[ maxid ], max );
}