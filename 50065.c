//car.h
#define MAXN 100
 
typedef struct{
    int x, y;
    int g;
} CarStatus;
 
typedef struct{
    int t, v;
} Command;
 
typedef struct{
    int num;
    CarStatus status[MAXN];
} CarStatusList;
 
CarStatusList carSimulation(CarStatus car, Command commands[]);
//

int dx[ 6 ] = { 0, 0, 1, -1, 0, 0 };
int dy[ 6 ] = { 0, 0, 0, 0, 1, -1 };

CarStatusList carSimulation(CarStatus car, Command commands[]){
	int idx = -1;
	CarStatusList ret;
	ret.num = 0;
	while( commands[ ++idx ].t != 0 ){
		int t = commands[ idx ].t;
		int v = commands[ idx ].v;
		if( commands[ idx ].t == 1 ){
			car.g += v;
		}
		else{
			if( v <= car.g ){
				car.x += dx[ t ] * v;
				car.y += dy[ t ] * v;
				car.g -= v;
				ret.status[ ret.num++ ] = car;
			}
			else break;
		}
	}
	return ret;
}


#include <stdio.h>
#include <assert.h>
int main(){
    int N;
    CarStatus car;
    Command commands[MAXN];
 
    assert(scanf("%d%d%d", &car.x, &car.y, &car.g) == 3);
    assert(scanf("%d", &N) == 1);
    for(int i = 0; i < N; i++)
        assert(scanf("%d%d", &commands[i].t, &commands[i].v) == 2);
 
    CarStatusList result= carSimulation(car, commands);
 
    for(int i = 0; i < result.num; i++)
        printf("%d %d %d\n", result.status[i].x, result.status[i].y, result.status[i].g);
 
    return 0;
}