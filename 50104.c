#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxl (1<<6)

typedef struct Memb{
	char *name;
	struct Memb *lc, *rc;
}Memb;

typedef struct Club{
	char *name, *leader;
	struct Club *lc, *rc;
	struct Memb *root;
}Club;

Memb *get_Memb( char *name ){
	Memb *tp = (Memb*)malloc( sizeof( Memb ) );
	tp -> lc = tp -> rc = NULL;
	tp -> name = malloc( sizeof( char ) * ( strlen( name ) + 1 ) );
	strcpy( tp -> name, name );
	return tp;
}

Club *get_Club( char *club, char *name ){
	Club *tp = (Club*)malloc( sizeof( Club ) );
	tp -> lc = tp -> rc = tp -> root = NULL;
	tp -> name = malloc( sizeof( char ) * ( strlen( club ) + 1 ) );
	tp -> leader = malloc( sizeof( char ) * ( strlen( name ) + 1 ) );
	strcpy( tp -> name, club );
	strcpy( tp -> leader, name );
	return tp;
}

Memb *build_Memb( Memb *now, char *name ){
	if( now == NULL || strcmp( name, now -> name ) == 0 )
		return get_Memb( name );
	if( strcmp( name, now -> name ) < 0 )
		now -> lc = build_Memb( now -> lc, name );
	if( strcmp( name, now -> name ) > 0 )
		now -> rc = build_Memb( now -> rc, name );
	return now;
}

Club *build_Club( Club *now, char *club, char *name ){
	if( now == NULL || strcmp( club, now -> name ) == 0 ){
		now = get_Club( club, name );
		now -> root = build_Memb( now -> root, name );
	}
	if( strcmp( club, now -> name ) < 0 )
		now -> lc = build_Club( now -> lc, club, name );
	if( strcmp( club, now -> name ) > 0 )
		now -> rc = build_Club( now -> rc, club, name );
	return now;
}

Memb *find_Memb( Memb *now, char *name ){
	if( now == NULL || strcmp( name, now -> name ) == 0 ) return now;
	if( strcmp( name, now -> name ) < 0 ) return find_Memb( now -> lc, name );
	if( strcmp( name, now -> name ) > 0 ) return find_Memb( now -> rc, name );
}

Club *find_Club( Club *now, char *name ){
	if( now == NULL || strcmp( name, now -> name ) == 0 ) return now;
	if( strcmp( name, now -> name ) < 0 ) return find_Club( now -> lc, name );
	if( strcmp( name, now -> name ) > 0 ) return find_Club( now -> rc, name );
}

int main(){
	Club *root = NULL;
	char name[ maxl ], club[ maxl ];
	int cmd, N; scanf("%d", &N );
	while( N-- ){
		scanf("%d%s%s", &cmd, name, club );
		if( cmd == 0 )
			root = build_Club( root, club, name );
		else{
			Club *tmp = find_Club( root, club );
			if( tmp == NULL ) printf("error\n");
			else tmp -> root = build_Memb( tmp -> root, name );
		}
	}
	int Q; scanf("%d", &Q );
	while( Q-- ){
		scanf("%d", &cmd );
		if( cmd == 0 ){
			scanf("%s", club );
			Club *tmp = find_Club( root, club );
			printf("%s\n", tmp == NULL ? "None" : tmp -> leader );
		}
		else{
			scanf("%s%s", name, club );
			Club *tmp = find_Club( root, club );
			if( tmp == NULL ) printf("-1\n");
			else printf("%d\n", find_Memb( tmp -> root, name ) == NULL ? 0 : 1 );
		}
	}
}