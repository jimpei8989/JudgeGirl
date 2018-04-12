#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n );
    if( n <= 0 )
        printf("0\n");
    else if( n % 2 )
        printf("0\n");
    else if( n >= 1000 && n <= 10000 )
        printf("0\n");
    else printf("1\n");
}