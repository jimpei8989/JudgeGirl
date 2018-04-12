#include <stdio.h>

enum Type {NOVEL, COMICS, MANUAL, TEXTBOOK}; 
struct Book {
    char title[128];
    enum Type type;
    char ISBN[128];
    char authors[128];
    unsigned int importance;
};
 
struct Date {
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

//---
const int Month[ 13 ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int is_leap( int yy ){
    if( yy % 400 == 0 ) return 1;
    else if( yy % 100 == 0 ) return 0;
    else if( yy % 4 == 0 ) return 1;
    else return 0;
}

int dist( struct Date a, struct Date b ){
    int cnt = 1;
    if( a.month == b.month && a.year == b.year ){
        cnt += b.day - a.day;
    }
    else if( a.year == b.year ){
        cnt += Month[ a.month ] - a.day;
        if( a.month == 2 && is_leap( a.year ) )
            cnt++;
        for( int i = a.month + 1; i < b.month; i++ ){
            cnt += Month[ i ];
            if( i == 2 && is_leap( a.year ) ) cnt++;
        }
        cnt += b.day;
    }
    else{
        cnt += Month[ a.month ] - a.day;
        if( a.month == 2 && is_leap( a.year ) )
            cnt++;
        for( int i = a.month + 1; i <= 12 && a.year < b.year; i++ ){
            cnt += Month[ i ];
            if( i == 2 && is_leap( a.year ) ) cnt++;
        }
        for (int i = a.year + 1; i < b.year; i++) {
            cnt += is_leap( i ) ? 366 : 365;
        }
        for( int i = 1; i < b.month && a.year < b.year; i++ ){
            cnt += Month[ i ];
            if( i == 2 && is_leap( b.year ) ) cnt ++;
        }
        cnt += b.day;
    }
    return cnt;
}

int fine( unsigned int X ){
    while( (X & 1) == 0 ) X >>= 1;
    X >>= 1;
    int cnt = 0;
    while( (X & 1) == 0 ){
        cnt ++;
        X >>= 1;
    }
    return cnt;
}

unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned){
    int dis = dist( date_borrowed, date_returned );
    int X = fine( book.importance );
    if (book.type == NOVEL) {
        if( dis <= 90 ) return 0;
        else return ( dis - 90 ) * X;
    } else if (book.type == COMICS) {
        if( dis <= 10 ) return 0;
        else return ( dis - 10 ) * X;
    } else if (book.type == MANUAL) {
        if( dis <= 100 ) return 0;
        else return ( dis - 100 ) * X;
    } else {
        if( dis <= 5 ) return 0;
        else return ( dis - 5 ) * X;
    }
}

int main(){
    struct Book book = {
        "Neon Genesis Evangelion",
        COMICS,
        "978-159-116-400-5",
        "Yoshiyuki Sadamoto",
        17
    };
    struct Date date_borrowed, date_returned;
    date_borrowed.year  = 2004;
    date_borrowed.month = 2;
    date_borrowed.day   = 21;
    date_returned.year  = 2004;
    date_returned.month = 3;
    date_returned.day   = 2;
    printf("The fine is $%d.\n", library_fine(book, date_borrowed, date_returned));
    printf("The date is %d.\n", dist( date_borrowed, date_returned ) );
    return 0;
}