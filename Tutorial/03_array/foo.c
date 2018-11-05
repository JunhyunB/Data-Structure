#include <stdio.h>
#include "increment.h"

int main(){
	int a;
	a = 10;
	int b;
	int data[10] = {10,20,30,40,50,60,70,80,90,100};
	float data_f[10] = {10.0,20.0,30.0,40.0,50.0,60.0,70.0,80.0,90.0,100.0};
	
	a = increment(a);
	
	for (int i=0;i<a;i++){

	printf("성규 바보\n");

}	

	printf("%d 번 반복했습니다 ㅎㅎ\n", a);
	scanf("%d", &b);

	b = increment(b);
	printf("b is %d\n", b);


	int i;
	for (i=0;i<10;i++){
	printf("data[%d] is %d\n",i,data[i]);
}

	i=0;
	for (i=0;i<10;i++){
	printf("data_f[%d] is %f\n",i,data_f[i]);
}
	return 0;
	
}

