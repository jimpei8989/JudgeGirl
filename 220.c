#include <stdio.h>

int main(){
	char c;
	int is_dot = 0;
	int space = 0;
	int enter = 0;
	int cnt = 0;
	while( scanf("%c", &c ) != EOF ){
		if( is_dot ){
			if( ( space == 0 && enter == 1 ) || ( space == 2 && enter == 0 ) ){
				cnt ++;
				is_dot = 0;
				space = 0;
				enter = 0;
			}
		}
		if( c == '.' ){
			is_dot = 1;
			space = 0;
			enter = 0;
		}
		else if( is_dot && c == ' ' ) space ++;
		else if( is_dot && c == '\n' ) enter ++;
		else if( c == '\0' ) break;
		else{
			is_dot = 0;
			space = 0;
			enter = 0;
		}
	}
	if( is_dot ) cnt ++;

	printf("%d\n", cnt );
}