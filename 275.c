#include <stdio.h>
typedef unsigned long long Set;
void init(Set *set){
	*set = 0;
}
void add(Set *set, int i){
	*set |= (1ull << i);
}
void has(Set set, int i){
	if( set & ( 1ull << i ) ) printf("set has %d\n", i );
	else printf("set does not have %d\n", i );
}
Set setUnion(Set a, Set b){
	return ( a | b );
}
Set setIntersect(Set a, Set b){
	return ( a & b );
}
Set setDifference(Set a, Set b){
	return ( a ^ b );
}


 
int main()
{
  Set a, b, c;
 
  init(&a);
  add(&a, 3);
  add(&a, 5);
  add(&a, 2);
 
  init(&b);
  add(&b, 3);
  add(&b, 7);
  add(&b, 9);
 
  c = setUnion(a, b);
  has(c, 2);
  has(c, 3);
  has(c, 5);
  has(c, 7);
  has(c, 9);
 
  c = setIntersect(a, b);
  has(c, 2);
  has(c, 3);
  has(c, 5);
  has(c, 7);
  has(c, 9);
 
  c = setDifference(a, b);
  has(c, 2);
  has(c, 3);
  has(c, 5);
  has(c, 7);
  has(c, 9);
 
  return 0;
}