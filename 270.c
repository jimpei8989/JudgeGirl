#include <stdio.h>

char ipt[ 1024 ][ 1024 ];
char name[ 128 ][ 8 ];
int value[ 128 ];
int num_ipt, num_var;

void process_variables(){
	char tp* = strtok( ipt[ 0 ], " =" );
	while( tp != NULL ){
		if( strcmp( tp, "END" ) == 0 ) break;
		strcpy( name[ num_var ], tp );
		tp = strtok( NULL, " =" );
		value[ num_var ] = atoi( tp );
		tp = strtok( NULL, " =" );
	}
}

int main(){
	fgets( ipt[ idx_ipt++ ], 1024, stdin );
	process_variables();
	while( fgets( ipt[ idx_ipt++ ], 1024, stdin ) != EOF );
}