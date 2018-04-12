const int di[ 8 ] = { 0, 0, 1, -1, 1, -1, -1, 1 };
const int dj[ 8 ] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int visit[ 1 << 10 ][ 1 << 10 ] = { 0 };

void travel(int map[1024][1024], int N, int M, int A_r, int A_c, int B_r, int B_c, int directionA[], int directionB[]){
	int idx_a = 0, idx_b = 0;
	while( 1 ){
		if( idx_a != -1 ){
			visit[ A_r ][ A_c ] = 1;
			int idx = -1;
			int max = 0;
			for( int i = 0; i < 8; i++ ){
				int nxtr = A_r + di[ i ];
				int nxtc = A_c + dj[ i ];
				if( nxtr < 0 || nxtr >= N || nxtc < 0 || nxtc >= M ) continue;
				if( map[ nxtr ][ nxtc ] - map[ A_r ][ A_c ] > max ){
					max = map[ nxtr ][ nxtc ] - map[ A_r ][ A_c ];
					idx = i;
				}
			}
			directionA[ idx_a++ ] = idx;
			if( idx == -1 ) idx_a = -1;
			else{
				A_r += di[ idx ];
				A_c += dj[ idx ];
				if( visit[ A_r ][ A_c ] == 1 ){
					directionA[ idx_a++ ] = -1;
					idx_a = -1;
				}
			}
		}
		if( idx_b != -1 ){
			visit[ B_r ][ B_c ] = 1;
			int idx = -1;
			int min = 0;
			for( int i = 0; i < 8; i++ ){
				int nxtr = B_r + di[ i ];
				int nxtc = B_c + dj[ i ];
				if( nxtr < 0 || nxtr >= N || nxtc < 0 || nxtc >= M ) continue;
				if( map[ nxtr ][ nxtc ] - map[ B_r ][ B_c ] < min ){
					min = map[ nxtr ][ nxtc ] - map[ B_r ][ B_c ];
					idx = i;
				}
			}
			directionB[ idx_b++ ] = idx;
			if( idx == -1 ) idx_b = -1;
			else{
				B_r += di[ idx ];
				B_c += dj[ idx ];
				if( visit[ B_r ][ B_c ] == 1 ){
					directionB[ idx_b++ ] = -1;
					idx_b = -1;
				}
			}
		}
		if( A_r == B_r && A_c == B_c ){
			directionA[ idx_a++ ] = -1;
			idx_a = -1;
		}
		if( idx_a == -1 && idx_b == -1 ) break;
	}
}




#include <stdio.h>
int main() {
    int N, M;
    int map[1024][1024];
    int A_r, A_c, B_r, B_c;
    int directionA[1024], directionB[1024];
 
    scanf("%d%d", &N, &M);
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
 
    scanf("%d%d%d%d", &A_r, &A_c, &B_r, &B_c);
 
    travel(map, N, M, A_r, A_c, B_r, B_c, directionA, directionB);
 
    int i = 0;
    while (directionA[i] != -1) {
        printf("%d ", directionA[i]);
        i++;
    }
    printf("-1\n");
    i = 0;
    while (directionB[i] != -1) {
        printf("%d ", directionB[i]);
        i++;
    }
    printf("-1\n");
 
    return 0;
}