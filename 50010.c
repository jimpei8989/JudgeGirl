#include <stdio.h>
#include <string.h>
#define maxn 100000 + 10

int main(){
	char s[ maxn ];
	scanf("%s", s );
	int n = strlen( s );
	char front[ maxn ];
	int cnt_front = 0;
	int inv[ maxn ] = { 0 };
	int inv_front[ maxn ] = { 0 };
	char l1[ 100 ];
	char l2[ 100 ];
	char command[ maxn ];
	while( scanf("%s", command ) != EOF ){
		if( strcmp( command, "replace" ) == 0 ){
			char x, y;
			scanf("%s", l1 ), x = l1[ 0 ];
			scanf("%s", l2 ), y = l2[ 0 ];
			for( int i = 0; i < n; i++ )
				if( s[ i ] == x ) s[ i ] = y;
			for( int i = 0; i < cnt_front; i++ )
				if( front[ i ] == x ) front[ i ] = y;
		}
		else if( strcmp( command, "remove" ) == 0 ){
			char x;
			scanf("%s", l1 ), x = l1[ 0 ];
			for( int i = 0; i < n; i++ )
				if( s[ i ] == x ) inv[ i ] = 1;
			for( int i = 0; i < cnt_front; i++ )
				if( front[ i ] == x ) inv_front[ i ] = 1;
		}
		else if( strcmp( command, "addhead" ) == 0 ){
			char x;
			scanf("%s", l1 ), x = l1[ 0 ];
			front[ cnt_front++ ] = x;
		}
		else if( strcmp( command, "addtail" ) == 0 ){
			char x;
			scanf("%s", l1 ), x = l1[ 0 ];
			s[ n++ ] = x;
		}
		else if( strcmp( command, "end" ) == 0 ){
			for( int i = cnt_front - 1; i >= 0; i-- )
				if( inv_front[ i ] == 0 ) printf("%c", front[ i ] );
			for( int i = 0; i < n; i++ )
				if( inv[ i ] == 0 ) printf("%c", s[ i ] );
			printf("\0");
			break;
		}
		else{
			printf("invalid command %s\n", command );
			break;
		}
	}
}