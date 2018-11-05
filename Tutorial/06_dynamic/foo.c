#include <stdio.h>
#include <stdlib.h>

struct human {
	char name[100];
	int age;
};

typedef struct human HUMAN;

void update_age(HUMAN* h){
	h->age++;
}

int main(){
	struct human h1 = {"Daejin", 40};
	h1.age = 21;

	struct human h2 = {"Junhyun", 23};
	h2.age = 34;

	struct human* hp1 = (struct human*)malloc(sizeof(struct human));
	hp1 -> age = 12;

	update_age(hp1);
	
	printf("hp1's age: %d\n", hp1->age);
	
	HUMAN* hp2 = (HUMAN*)malloc(sizeof(HUMAN));
	hp2 -> age = 56;

}
