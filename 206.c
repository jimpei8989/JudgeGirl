#include <stdio.h>

void shuffle(int *deck[]){
    int n = 0;
    while( deck[ n ] != NULL ){
        n++;
    }
    int half = ( n + 1 ) / 2;
    int *nw[ 10000 ];
    for( int i = 0; i < n; i++ ){
        if( i % 2 == 0 ) nw[ i ] = deck[ i / 2 ];
        else nw[ i ] = deck[ half + i / 2 ];
    }
    for( int i = 0; i < n; i++ ){
        deck[ i ] = nw[ i ];
    }
}

void print( int *deck[] ){
    int n = 0;
    while( deck[ n ] != NULL ){
        n++;
    }
    for( int i = 0; i < n; i++ ){
        printf("%d", *deck[ i ] );
        if( i == n - 1 ) printf("\n");
        else printf(" ");
    }
}
 
int main()
{
  int card[10000];
  int *deck[10000];
  int index = 0;
 
  while (scanf("%d", &(card[index])) != EOF) {
    if( (card[index]) == -1 ) break;
    deck[index] = &(card[index]);
    index++;
  }
  deck[index] = NULL;
  shuffle(deck);
  print(deck);  
  return 0;
}