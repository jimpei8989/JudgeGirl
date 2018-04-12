typedef unsigned long long int ull;

int bingo(const ull *ipt, int *x){
	ull board = *ipt;
	ull hori = ( 1 << 9 ) - 1;
	hori <<= 56;
	for( int i = 0; i < 8; i++ ){
		if( ( board & hori ) == hori ){
			*x = i;
			return 1;
		}
		hori >>= 8;
	}
	ull verti = 0;
	for( int i = 0; i < 8; i++ )
		verti = ( verti<<8 ) + 1;
	verti <<= 7;
	for( int i = 0; i < 8; i++ ){
		if( ( board & verti ) == verti ){
			*x = i;
			return 2;
		}
		verti >>= 1;
	}
	ull tp = 0ull;
	for( int i = 0; i < 8; i++ )
		tp += ( 1ull << ( 9*i ) );
	if( ( board & tp ) == tp ){
		*x = 0;
		return 3;
	}
	ull tp2 = 0ull;
	for( int i = 0; i < 8; i++ )
		tp2 += ( 1ull << ( 7 + 7 * i ) );
	if( (board & tp2 ) == tp2 ){
		*x = 1;
		return 3;
	}
	return 0;
}






#include <stdio.h>

void print( const ull x ){
	ull tp = (1ull << 63);
	for( int i = 0; i < 8; i++ ){
		for( int j = 0; j < 8; j++ ){
			printf("%d%c", (x & tp) ? 1 : 0, " \n"[ j == 7 ] );
			tp >>= 1;
		}
	}
}

int main(void)
{
    unsigned long long int board;
    int res = 0, rowColumn = 0;
    scanf("%llu", &board);
    print( board );
    res = bingo(&board, &rowColumn);
    if(res == 0) printf("no\n");
    else printf("%d %d\n", res, rowColumn);
    return 0;
}