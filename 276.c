#include <stdio.h>
#include <string.h>

int main(){
	char s[ 128 ];
	int next = 1;
	while( scanf("%s", s ) != EOF ){
		int flag = 0;
		if( s[ strlen( s ) - 1 ] == '.' ){
			flag = 1;
			s[ strlen( s ) - 1 ] = 0;
		}

		if( strcmp( s, "the" ) == 0 ) flag += 0;
		else if( strcmp( s, "of" ) == 0 ) flag += 0;
		else if( strcmp( s, "and" ) == 0 ) flag += 0;
		else if( strcmp( s, "at" ) == 0 ) flag += 0;
		else printf("%c", s[ 0 ] + 'A' - 'a' );

		if( flag ) printf("\n");
	}
	return 0;
}