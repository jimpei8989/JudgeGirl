#include <stdio.h>
#include <string.h>

int atoi_( char* s, int n ){
	int k = 1;
	int cnt = 0;
	for( int i = n-1; i >= 0; i-- ){
		if( '0' <= s[ i ] && s[ i ] <= '9' ){
			cnt += ( s[ i ] - '0' ) * k;
			k *= 10;
		}
		else return -1;
	}
	return cnt;
}

int my_fgets( char *s ){
	int n = 0;
	char c;
	while( scanf("%c", &c ) != EOF ){
		s[ n++ ] = c;
		if( c == '\n' ){
			s[ n - 1 ] = '\0';
			return n;
		}
	}
	return 0;
}

void chasing(int **A[], int a, int *B[], int b, int C[], int c){
	for( int i = 0; i < a; i++ ) A[ i ] = NULL;
	for( int j = 0; j < b; j++ ) B[ j ] = NULL;
	char ipt[ 100 ];
	while( my_fgets( ipt ) ){
		if( strcmp( ipt, "\n" ) == 0 ) continue;
		int flag = 1;
		int cnt_op = 0;
		char op[ 100 ][ 100 ];
		char *ptr = strtok( ipt, " " );
		while( ptr != NULL ){
			strcpy( op[ cnt_op++ ], ptr );
			ptr = strtok( NULL, " " );
		}
		if( cnt_op != 4 ){
			printf("0\n");
			continue;
		}
		int x = atoi_( op[ 1 ], strlen( op[ 1 ] ) );
		int y = atoi_( op[ 3 ], strlen( op[ 3 ] ) );
		if( x == -1 || y == -1 ){
			printf("0\n");
			continue;
		}
		if( strcmp( op[ 0 ], "A" ) == 0 && strcmp( op[ 2 ], "B" ) == 0 ){
			if( 0 <= x && x < a && 0 <= y && y < b ){
				A[ x ] = &B[ y ];
			}
			else flag = 0;
		}
		else if( strcmp( op[ 0 ], "B" ) == 0 && strcmp( op[ 2 ], "C" ) == 0 ){
			if( 0 <= x && x < b && 0 <= y && y < c ){
				B[ x ] = &C[ y ];
			}
			else flag = 0;
		}
		else flag = 0;
		printf("%d\n", flag );
	}
}

#ifdef DB
#include <stdio.h>
int main() {
        int a = 5, b = 4, c = 3;
        int **A[5] = {}, *B[4] = {}, C[3] = {2, 1, 4};
        chasing(A, a, B, b, C, c);
 
        int **ansA[5] = {} ,*ansB[4] = {};
        for (int i = 0; i < a; i++)
                ansA[i] = NULL;
        for (int i = 0; i < b; i++)
                ansB[i] = NULL;
        ansA[2] = &B[1], ansA[3] = &B[0], ansB[1] = &C[1], ansB[2] = &C[0];
        /*Check A*/
        for (int i = 0; i < a; i++)
                if (A[i] != ansA[i] )
                        printf("A[%d] wrong answer!\n", i);
 
        /*Check B*/
        for (int i = 0; i < b; i++)
                if (B[i] != ansB[i] )
                        printf("B[%d] wrong answer!\n", i);
        printf("Code End\n");
        return 0;
}
#endif