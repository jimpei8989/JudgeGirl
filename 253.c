#ifndef MWTIME
#define MWTIME
 
typedef struct Time {
    int hour;
    int minute;
    int second;
} Time;
 
void initTime(Time *time);
void setTime(Time *time, int hour, int minute, int second);
void addTime(Time *time, int hour, int minute, int second);
void printTime(Time *time);
#endif

#include <stdio.h>

void initTime(Time *time){
	time -> hour = time -> minute = time -> second = 0;
}
void setTime(Time *time, int hour, int minute, int second){
	time -> hour = hour;
	time -> minute = minute;
	time -> second = second;
}
void addTime(Time *time, int hour, int minute, int second){
	time -> second += second;
	time -> minute += ( minute + time -> second / 60 );
	time -> second %= 60;
	time -> hour += ( hour + time -> minute / 60 );
	time -> minute %= 60;
	time -> hour %= 24;
}

#define print( x ) { printf("%s%d", ( (x) < 10 ? "0" : "" ), (x) ); }

void printTime(Time *time){
	
#ifdef H24
	print( time -> hour );
#endif

#ifndef H24
	int am = ( time ->hour < 12 ? 1 : 0 );
	print( (time -> hour) % 12 + ( (time -> hour) % 12 ? 0 : 12 ) );
	printf( am ? "am" : "pm" );
#endif

	printf(":");
	print( (time -> minute) );
	printf(":");
	print( (time -> second) );
	printf("\n");
}


int main(){
	Time A, B;
	setTime( &A, 15, 15, 0 );
	printTime( &A );

	setTime( &B, 2, 40, 0 );
	printTime( &B );
}