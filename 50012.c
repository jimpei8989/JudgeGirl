#include <stdio.h>
void printBlock(unsigned long long int *block);
void initialize(unsigned long long int *block, int row, int column, int size);
int moveLeft(unsigned long long int *block);
int moveRight(unsigned long long int *block);
int moveUp(unsigned long long int *block);
int moveDown(unsigned long long int *block);

typedef unsigned long long ull;
void printBlock( ull *x ){
	ull tp = 1;
	for( int i = 0; i < 8; i++ ){
		for( int j = 0; j < 8; j++ ){
			if( tp & *x ) putchar('1');
			else putchar('0');
			tp <<= 1;
		}
		putchar( '\n' );
	}
}

#define testL ( (1ull) + (1ull<<8) + (1ull<<16) + (1ull<<24) + (1ull<<32) + (1ull<<40) + (1ull<<48) + (1ull<<56) )
#define testR ( testL << 7 )
#define testU ( ( 1ull << 8 ) - 1 )
#define testD ( testU << 56 )

const ull tL = testL;
const ull tR = testR;
const ull tU = testU;
const ull tD = testD;

int moveLeft( ull *x ){
	if( testL & *x ) return 0;
	(*x) >>= 1;
	return 1;
}
int moveRight( ull *x ){
	if( testR & *x ) return 0;
	(*x) <<= 1;
	return 1;
}
int moveUp( ull *x ){
	if( testU & *x ) return 0;
	(*x) >>= 8;
	return 1;
}
int moveDown( ull *x ){
	if( testD & *x ) return 0;
	(*x) <<= 8;
	return 1;
}

void initialize( ull *x, int r, int c, int d ){
	(*x) = 0;
	for( int i = 0; i < d; i++ ){
		(*x) = ( (*x) << 8 ) + ( ( 1ull << ( d ) ) - 1);
	}
	for( int i = 0; i < c; i++ )
		moveRight( x );
	for( int i = 0; i < r; i++ )
		moveDown( x );
}

#ifdef DB
#include <stdio.h>
 
int main() {
    unsigned long long int num;
    char operation;
    int ret;
 
    scanf("%llu", &num);
 
    while (1) {
        ret = 1;
 
        scanf("%c", &operation);
 
        if (operation == 'p') {
            printBlock(&num);
            break;
        } else if (operation == 'u')
            ret = moveUp(&num);
        else if (operation == 'd')
            ret = moveDown(&num);
        else if (operation == 'l')
            ret = moveLeft(&num);
        else if (operation == 'r')
            ret = moveRight(&num);
        else if (operation == 'i') {
            int row, column, size;
            scanf("%d %d %d", &row, &column, &size);
            initialize(&num, row, column, size);
        }
 		printf("---\n");
 		printBlock( &num );
 		printf("---\n");
        if (ret == 0)
            printf("Invalid move!\n");
    }
 
    return 0;
}

#endif


int main(){
	ull tpL = testL;
	ull tpR = testR;
	ull tpU = testU;
	ull tpD = testD;
	printBlock( &tpL );
	printBlock( &tpR );
	printBlock( &tpU );
	printBlock( &tpD );
}
