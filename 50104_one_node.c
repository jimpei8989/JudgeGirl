#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxl (1<<6)

typedef struct Node{
	char *value, *leader;
	struct Node *lc, *rc;
	struct Node *root;
}Node;

Node *init_node( char *str ){
	Node *tp = (Node*)malloc( sizeof( Node ) );
	memset( tp, 0, sizeof( Node ) );
	tp -> value = (char*)malloc( sizeof(char) * ( strlen(str) + 1 ) );
	strcpy( tp -> value, str );
	return tp;
}

Node* build_node( Node *now, char *str, char *leader ){
	if( now == NULL ){
		Node *tp = init_node( str );
		if( leader[ 0 ] != 0 ){
			tp -> leader = (char*)malloc( sizeof(char) * ( strlen(leader) + 1 ) );
			strcpy( tp -> leader, leader );
			tp -> root = build_node( tp -> root, leader, "\0" );
		}
		return tp;
	}
	if( strcmp( str, now -> value ) < 0 )
		now -> lc = build_node( now -> lc, str, leader );
	if( strcmp( str, now -> value ) > 0 )
		now -> rc = build_node( now -> rc, str, leader );
	return now;
}

Node* get_node( Node* now, char *str ){
	if( now == NULL || strcmp( str, now -> value ) == 0 )
		return now;
	if( strcmp( str, now -> value ) < 0 )
		return get_node( now -> lc, str );
	if( strcmp( str, now -> value ) > 0 )
		return get_node( now -> rc, str );
}

int main(){
	Node *root = NULL;
	int N; scanf("%d", &N );
	while( N-- ){
		int cmd;
		char name[ maxl ], club[ maxl ];
		scanf("%d%s%s", &cmd, name, club );
		if( cmd == 0 )
			root = build_node( root, club, name );
		else{
			Node *tmp = get_node( root, club );
			if( tmp == NULL )
				printf("error\n");
			else
				build_node( tmp -> root, name, "\0" );
		}
	}
	int Q; scanf("%d", &Q );
	while( Q-- ){
		int cmd; scanf("%d", &cmd );
		char name[ maxl ], club[ maxl ];
		if( cmd == 0 ){
			scanf("%s", club );
			Node *tmp = get_node( root, club );
			if( tmp == NULL ) printf("None\n");
			else printf("%s\n", tmp -> leader );
		}
		else{
			scanf("%s%s", name, club );
			Node *tmp = get_node( root, club );
			if( tmp == NULL ) printf("-1\n");
			else{
				Node *tmp2 = get_node( tmp -> root, name );
				if( tmp2 == NULL ) printf("0\n");
				else printf("1\n");
			}
		}
	}
}