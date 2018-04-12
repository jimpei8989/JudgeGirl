#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int KKK = 0;

struct Node{
	char c;
	int num;
	struct Node *nxt;
};

int c_to_i( char *ipt, int N ){
	if( strcmp( ipt, "left" ) == 0 ) return 0;
	if( strcmp( ipt, "right" ) == 0 ) return N;
	return atoi( ipt );
}

struct Node* find( struct Node* now, int remain ){
	if( remain == 0 ) return now;
	if( now -> nxt ) return find( now -> nxt, remain - 1 );
}

void insert( struct Node* rt, int k, char x ){
	printf("inserting k = %d, x = %c\n", k, x );
	struct Node *tp = find( rt, k );
	printf("%d\n", tp -> num );
	struct Node *now = (struct Node* )malloc( sizeof( struct Node ) );
	now -> c = x;
	now -> num = KKK ++;
	now -> nxt = NULL;
	struct Node *ori = tp -> nxt;
	tp -> nxt = now;
	now -> nxt = ori;
	printf("tp -> nxt = %p, now = %p\n", tp -> nxt, now );
	printf("now->c = %c, now ->num = %d, now ->nxt = %p\n", now->c, now->num, now->nxt?now->nxt:0);
}

void delete( struct Node *rt, int k ){
	struct Node *tp = find( rt, k - 1 );
	struct Node *a = tp -> nxt -> nxt;
	free( tp -> nxt );
	tp -> nxt = a;
}

void print( struct Node* now ){
	printf("%c", now -> c );
	if( now -> nxt ) print( now -> nxt );
}

int main(){
	struct Node *root = NULL;
	root = (struct Node* ) malloc( sizeof( struct Node ) );
	root -> num = KKK++;
	int N = 0;
	char cmd[ 100 ];
	while( scanf("%s", cmd ) != EOF ){
		if( strcmp( cmd, "insert" ) == 0 ){
			char target[ 1000 ], x;
			scanf("%s", target );
			printf("%s, ", target);
			while( scanf("%c", &x) != EOF )
				if( x != ' ' )
					break;
			//printf("%c, %d\n", x, x );
			int k = c_to_i( target, N );
			insert( root, k, x );
			N++;
			printf("insert done\n");
		}
		else{
			char target[ 1000 ];
			scanf("%s", target );
			int k = c_to_i( target, N );
			delete( root, k );
			N--;
		}
	}
	if( root->nxt != NULL ) print( root -> nxt );
}