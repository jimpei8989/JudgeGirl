#include <stdio.h>
#include <string.h>

int main(){
	char s[ 128 ] = "";
	char ipt[ 128 ];
	int idx = 0;
	while( scanf("%s", ipt ) != EOF ){
		int l_ipt = strlen( ipt );
		int same = 0;
		for( int i = l_ipt; i > 0; i-- ){
			if( i > idx ) continue;
			int flag = 1;
			for( int j = 0; j < i; j++ )
				if( s[ idx - i + j ] != ipt[ j ] )
					flag = 0;
			if( flag ){
				same = i;
				break;
			}
		}

		for( int i = same; i < l_ipt; i++ ){
			s[ idx++ ] = ipt[ i ];
		}
	}
	printf("%s\n", s );
	return 0;
}