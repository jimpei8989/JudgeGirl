//reservation.h
typedef struct RoomStatus {
    int capacity;
    struct Reservation *reservation;
} RoomStatus;

typedef struct Reservation {
    int nP;
    int StartTime;
    int EndTime;
    struct Reservation *next;
} Reservation;

int ReserveRoom(RoomStatus list[], int nR, int nP, int StartTime, int EndTime);

//#include "reservation.h"
#include <stdlib.h>

Reservation *init_reservation( int M, int S, int E ){
	Reservation *tp = ( Reservation* )malloc( sizeof( Reservation ) );
	tp -> nP = M;
	tp -> StartTime = S;
	tp -> EndTime = E;
	tp -> next = NULL;
	return tp;
}

int ReserveRoom(RoomStatus list[], int nR, int nP, int StartTime, int EndTime){
	for( int i = 0; i < nR; i++ ){
		if( list[ i ].capacity < nP ) continue;
		else{
			if( list[ i ].reservation == NULL ){
				list[ i ].reservation = init_reservation( nP, StartTime, EndTime );
				return 1;
			}
			else{
				Reservation *now = list[ i ].reservation;
				if( EndTime <= now -> StartTime ){
					list[ i ].reservation = init_reservation( nP, StartTime, EndTime );
					list[ i ].reservation -> next = now;
					return 1;
				}
				while( now -> next != NULL && now -> next -> EndTime <= StartTime )
					now = now -> next;
				if( now -> EndTime > StartTime )
					continue;
				if( now -> next != NULL ){
					if( EndTime > now -> next -> StartTime )
						continue;
				}
				Reservation *nnxt = now -> next;
				now -> next = init_reservation( nP, StartTime, EndTime );
				now -> next -> next = nnxt;
				return 1;
			}
		}
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
 
int main(){
    int n = 3;
    RoomStatus list[n];
    for(int i=0; i < n; i++){
        list[i].capacity = i+2;
        list[i].reservation = NULL;
    }
    int nP, sTime, eTime;
    while(scanf("%d %d %d", &nP, &sTime, &eTime)!=EOF)
        printf("%d", ReserveRoom(list, n, nP, sTime, eTime));
    puts("");
    printf("---Room Status List---\n");
    for(int i=0; i<n; i++){
        printf("%d ---", list[i].capacity);
        for(Reservation *tmp = list[i].reservation; tmp!=NULL; tmp=tmp->next)
            printf("->(%d:%d, %d)", tmp->nP, tmp->StartTime, tmp->EndTime);
        puts("");
    }
    printf("---      End       ---\n");
    return 0;
}