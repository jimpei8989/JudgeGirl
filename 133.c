#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct string_count {
    char seen[80];
    int count;
}SC;

int compare_and_add(char *string, struct string_count strings[]){
	int idx = 0;
	while( strings[ idx ].count != 0 ){
		if( strcmp( string , strings[ idx ].seen ) == 0 ){
			strings[ idx ].count ++;
			return 1;
		}
		idx++;
	}
	strcpy( strings[ idx ].seen, string );
	strings[ idx ].count ++;
	return 0;
}

int cmp( const void *a, const void *b ){
	SC x = *(SC*)a;
	SC y = *(SC*)b;
	if( x.count == y.count ){
		return strcmp( x.seen, y.seen );
	}
	else if( x.count < y.count )
		return -1;
	else return 1;
}
void sort(struct string_count strings[]){
	int n = 0;
	while( strings[ n ].count != 0 ) n++;
	qsort( strings, n, sizeof( strings[ 0 ] ), cmp );
}
void print(struct string_count strings[]){
	int n = 0;
	while( strings[ n ].count != 0 ){
		printf("%d %s\n", strings[ n ].count, strings[ n ].seen );
		n++;
	}
}

/* your uploaded code will be here */
int main() {
        struct string_count strings[20];
        int i;
        for( i=0 ; i<20 ; i++ )
                strings[i].count = 0;
        compare_and_add( "This", strings );
        compare_and_add( "is", strings );
        compare_and_add( "an", strings );
        compare_and_add( "apple,", strings );
        compare_and_add( "and", strings );
        compare_and_add( "this", strings );
        compare_and_add( "is", strings );
        compare_and_add( "a", strings );
        compare_and_add( "book.", strings );
        sort( strings );
        print( strings );
        return 0;
}