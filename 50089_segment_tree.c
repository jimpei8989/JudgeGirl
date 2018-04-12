#include<stdio.h>

struct Node{
    int L, R;
    int max, max_idx;
}

void first_fit(int bucket[1024],int N,int ball[16384],int M,int method,int result[16384]){
    Node *root = new Node;
}


void place(int bucket[1024],int N,int ball[16384],int M,int method,int result[16384]){
    if( method == 1 )
        first_fit( bucket[1024], N, ball[16384], M, method, result );
}
 
int main(){
    int N,M,method;
    scanf("%d%d%d",&N,&M,&method);
    int buckets[N];
    for(int i=0;i<N;i++)
        scanf("%d",&buckets[i]);
    int balls[M];
    for(int i=0;i<M;i++)
        scanf("%d",&balls[i]);
    int result[M];
    place(buckets,N,balls,M,method,result);
    for(int i=0;i<M;i++)
        printf("%d%s",result[i],i==M-1?"":" ");
    return 0;
}