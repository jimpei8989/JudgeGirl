#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 100001
#define maxw 101
char ans[ maxn ][ maxw ];
 
typedef struct Trie{
    int end;
    struct Trie *son[ 26 ];
} ST;
 
ST* new_node(){
    ST *tmp= (ST*)malloc( sizeof( struct Trie ) );
    for( int i = 0; i < 26; i++ )
        tmp -> son[ i ] = NULL;
    tmp -> end = 0;
    return tmp;
}
 
void build( ST *now, char *s ){
    if( s[ 0 ] == '\0' ){
        now -> end = 1;
        return;
    }
    int x = s[ 0 ] -'a';
    if( !now -> son[ x ] ) now -> son[ x ] = new_node();
    build( now -> son[ x ], s + 1 );
}
 
int find_ambi( ST *now, char *s, int remain, char *rcd, int idx, int *cnt ){
    int flag = 0;
    if( s[ 0 ] == '\0' ){
        rcd[ idx ] = '\0';
        if( now -> end == 1 ){
        	strcpy( ans[ (*cnt)++ ], rcd );
            flag ++;
        }
        if( remain ){
            for( int i = 0; i < 26; i++ ){
                if( now -> son[ i ] ){
                    rcd[ idx ] = 'a' + i;
                    flag += find_ambi( now -> son[ i ], s, remain - 1, rcd, idx + 1, cnt );
                }
            }
        }
    }
    else{
        int x = s[ 0 ] - 'a';
        if( remain == 0 ){
            if( now -> son[ x ] ){
                rcd[ idx ] = 'a' + x;
                flag += find_ambi( now -> son[ x ], s + 1, remain, rcd, idx + 1, cnt );
            }
        }
        else{
            for( int i = 0; i < 26; i++ ){
                if( now -> son[ i ] != NULL ){
                    rcd[ idx ] = 'a' + i;
                    if( i == x )
                        flag += find_ambi( now -> son[ i ], s + 1, remain, rcd, idx + 1, cnt );
                    else if( remain > 0 ) //replace this char
                        flag += find_ambi( now -> son[ i ], s + 1, remain - 1, rcd, idx + 1, cnt );
                } 
            }
            //skip this char
            flag += find_ambi( now , s + 1, remain - 1, rcd, idx, cnt );
            //skip this level
            for( int i = 0; i < 26; i++ ){
                if( now -> son[ i ] != NULL ){
                    rcd[ idx ] = 'a' + i;
                    flag += find_ambi( now -> son[ i ], s, remain - 1, rcd, idx+1, cnt );
                }
            }
        }
    }
    return flag > 0;
}

void print( int n ){
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < n - i - 1; j++ ){
			if( strcmp( ans[ j ], ans[ j + 1 ] ) > 0 ){
				char tp[ maxw ];
				strcpy( tp, ans[ j ] );
				strcpy( ans[ j ], ans[ j + 1 ] );
				strcpy( ans[ j + 1 ], tp );
			}
		}
	}
	
	for( int i = 0; i < n; i++ ){
		printf("%c%s", " ?"[ i==0 ], ans[ i ] );
		while( i < n - 1 && strcmp( ans[ i ], ans[ i + 1 ] ) == 0 ) i++;
	}
	printf("\n");
}
 
int find_exact( ST *now, char* s ){
    if( s[ 0 ] == '\0' ) return now -> end;
    int x = s[ 0 ] - 'a';
    if( now -> son[ x ] == NULL ) return 0;
    return find_exact( now -> son[ x ], s + 1 );
}
 
int main(){
    ST* root = new_node();
    int N;
    scanf("%d", &N );
    while( N-- ){
        char ipt[ 128 ];
        scanf("%s", ipt );
        build( root, ipt );
    }
    int Q;
    scanf("%d", &Q );
    while( Q-- ){
        char ipt[ 128 ];
        char record[ 2*128 ] = { 0 };
        scanf("%s", ipt );
        int cnt = 0;
        if( find_exact( root, ipt ) )
            printf(">%s\n", ipt );
        else if( find_ambi( root, ipt, 1, record, 0, &cnt ) )
        	print( cnt );
        else
            printf("!%s\n", ipt );
    }
}