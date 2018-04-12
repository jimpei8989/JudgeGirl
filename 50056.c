#include <stdio.h>
#include <string.h>
#define maxl ( 1 << 6 )
#define maxn ( 1 << 7 )
#define INF ( 1 << 30 )

char mate[ maxn ][ maxl ];
int num[ maxn ];
int pri[ maxn ];

int min( int a, int b ){
	return a < b ? a : b;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m );
	for( int i = 0; i < n; i++ )
		scanf("%s%d%d", mate[ i ], &num[ i ], &pri[ i ] );
	char best[ maxl ];
	int most = -1;
	for( int i = 0; i < m; i++ ){
		char prod[ maxl ];
		int k;
		int x = INF;
		int cost = 0;
		scanf("%s%d", prod, &k );
		for( int j = 0; j < k; j++ ){
			char use[ maxl ];
			int cnt;
			scanf("%s%d", use, &cnt );
			for( int k = 0; k < n; k++ ){
				if( strcmp( use, mate[ k ] ) == 0 ){
					x = min( x, num[ k ] / cnt );
					cost += cnt * pri[ k ];
					//printf("--%s, %d, %d\n", mate[ k ], x, cost );
				}
			}
		}
		int sell;
		scanf("%d", &sell );
		int tp = x * ( sell - cost );
		//printf("%s %d\n", prod, tp );
		if( tp > most || ( tp == most && strcmp( prod, best ) < 0 ) ){
			most = tp;
			strcpy( best, prod );
		}
	}
	printf("%s %d\n", best, most );
}