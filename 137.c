#include <stdio.h>

const int grade[11] = { 0, 60, 63, 67, 70, 73, 77, 80, 85, 90, 101 };
const char rank[10][5] = { "F", "C-", "C", "C+", "B-", "B", "B+", "A-", "A", "A+" };
const int hgrade[10] = { 50, 60, 65, 68, 70, 75, 78, 82, 87, 95 };
const int rankg[ 10 ] = { 0, 17, 20, 23, 27, 30, 33, 37, 40, 43 };

int main(){
	int n = 0;
	int a;
	int sum = 0;
	int rankgrade_sum = 0;
	int hgrade_sum = 0;
	while( scanf("%d", &a ) != EOF ){
#ifdef HUNDRED
		printf("%d ", a );
		sum += a;
#endif

#ifdef APLUS
		int now_rank = 0;
		while( !( grade[ now_rank ] <= a && a < grade[ now_rank + 1 ] ) && now_rank < 10 )
			now_rank ++;
		rankgrade_sum += rankg[ now_rank ];
		hgrade_sum += hgrade[ now_rank ];
		printf("%s ", rank[ now_rank ] );
#endif
		n++;

	}
#ifdef HUNDRED
	printf("%.1f\n", (sum + 0.0) / (n + 0.0) );
#endif

#ifdef APLUS
	printf("%.1f %.1f\n", (rankgrade_sum + 0.0 ) / ( n*10 + 0.0 ), (hgrade_sum + 0.0 ) / ( n + 0.0 ) );
#endif
}