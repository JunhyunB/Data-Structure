#include <stdio.h>
#include "increment.h"

int main(){
	int a;
	a = 10;
	int b;
	
	a = increment(a);
	
	for (int i=0;i<a;i++){

	printf("성규 바보\n");

}	

	printf("%d 번 반복했습니다 ㅎㅎ\n", a);
	scanf("%d", &b);

	printf("b is %d\n", b);
	b = increment(b);
	printf("b is %d\n", b);
return 0;
	
}
