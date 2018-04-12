#define MAXN 100
#define MAXL 25
 
typedef struct {
    char book_title[MAXL], author[MAXL];
}BookAuthor;
 
typedef struct {
    char book_title[MAXL];
    int selling, date;
}BookSelling;
 
typedef struct {
    char book_title[MAXL], author[MAXL];
    int selling, date;
}BookInfo;
 
typedef struct {
    int num; // the number of BookInfo
    BookInfo books[MAXN];
}BookInfoList;
 
BookInfoList merge(int N, int M, BookAuthor authorArr[], BookSelling sellingArr[]);
//#include "book.h"
#include <string.h>

int cmp( const void *pa, const void *pb ){
	BookInfo *a = pa;
	BookInfo *b = pb;
	if( strcmp( a->book_title, b->book_title ) == 0 )
		return (a->date) - (b->date);
	return strcmp( a->book_title, b->book_title );
}

BookInfoList merge(int N, int M, BookAuthor authorArr[], BookSelling sellingArr[]){
	BookInfoList ret;
	int cnt = 0;
	for( int i = 0; i < N; i++ ){
		for( int j = 0; j < M; j++ ){
			if( strcmp( authorArr[ i ].book_title, sellingArr[ j ].book_title ) == 0 ){
				strcpy( ret.books[ cnt ].book_title, authorArr[ i ].book_title );
				strcpy( ret.books[ cnt ].author, authorArr[ i ].author );
				ret.books[ cnt ].selling = sellingArr[ j ].selling;
				ret.books[ cnt ].date = sellingArr[ j ].date;
				cnt++;
			}
		}
	}
	qsort( ret.books, cnt, sizeof( BookInfo ), cmp );
	ret.num = cnt;
	return ret;
}



//main.c
#include <stdio.h>
#include <assert.h>
 
int main(){
    int N, M;
    BookAuthor authorArr[MAXN];
    BookSelling sellingArr[MAXN];
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%s %s", authorArr[i].book_title, authorArr[i].author);
    for(int i = 0; i < M; i++)
        scanf("%s %d %d", sellingArr[i].book_title, &sellingArr[i].selling, &sellingArr[i].date);
 
    BookInfoList result = merge(N, M, authorArr, sellingArr);
 
    for(int i = 0; i < result.num; i++)
        printf("%s %s %d %d\n", result.books[i].book_title,
                                result.books[i].author,
                                result.books[i].date, result.books[i].selling);
 
    return 0;
}