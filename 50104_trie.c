#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxl (1<<6)

int getidx( char c ){
	return (int)c;
}

typedef struct Trie{
	int exist;
	char leader[ maxl ];
	struct Trie *child[ 128 ];
	struct Trie *root;
}Trie;

Trie *init_trie(){
	Trie *now = (Trie*)malloc( sizeof( Trie ) );
	memset( now, 0, sizeof( Trie ) );
	return now;
}

void build_trie( Trie *now, char *str, char *name ){
	if( str[ 0 ] == 0 ){
		now->exist = 1;
		strcpy( now->leader, name );
		if( name[ 0 ] == 0 ) return;
		now -> root = init_trie();
		build_trie( now -> root, name, "\0" );
	}
	else{
		if( now->child[ getidx( str[ 0 ] ) ] == NULL ){
			now->child[ getidx( str[ 0 ] ) ] = init_trie();
		}
		build_trie( now->child[ getidx( str[ 0 ] ) ], str + 1, name );
	}
}

Trie *get_trie( Trie *now, char *str ){
	if( str[ 0 ] == 0 )
		return now;
	else{
		if( now -> child[ getidx( str[ 0 ] ) ] == NULL ) return NULL;
		return get_trie( now -> child[ getidx( str[ 0 ] ) ], str + 1 );
	}
}

int main(){
	Trie *root = init_trie();
	int N; scanf("%d", &N );
	while( N-- ){
		int cmd;
		char name[ maxl ], club[ maxl ];
		scanf("%d%s%s", &cmd, name, club );
		if( cmd == 0 ){
			build_trie( root, club, name );
		} else {
			Trie *tmp = get_trie( root, club );
			if( tmp == NULL ) printf("error\n");
			else build_trie( tmp -> root, name, "\0" );
		}
	}
	int Q; scanf("%d", &Q );
	while( Q-- ){
		int cmd;
		char name[ maxl ], club[ maxl ];
		scanf("%d", &cmd );
		if( cmd == 0 ){
			scanf("%s", club );
			Trie *tmp = get_trie( root, club );
			if( tmp == NULL || tmp -> exist == 0 ) printf("None\n");
			else printf("%s\n", tmp -> leader );
		}
		else{
			scanf("%s%s", name, club );
			Trie *tmp = get_trie( root, club );
			if( tmp == NULL || tmp -> exist == 0 )
				printf("-1\n");
			else{
				Trie *tmp2 = get_trie( tmp -> root, name );
				if( tmp2 == NULL || tmp2 -> exist == 0 ) printf("0\n");
				else printf("1\n");
			}
		}
	}
}