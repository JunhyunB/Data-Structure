#include <stdio.h>

struct student	{
	char name[20];
	int age;
	int score;
	struct student* friend;
};

typedef struct student std;

int main(){

	struct student s1 = {"Hong", 23, 99};
	std s2 = {"Daejin", 23, 40};
	printf("student name: %s\n", s1.name);
	
	
	s1.friend = &s2;
	// s2.friend = &s1;
	std* f = s1.friend;		
//	printf("friend name: %s\n", (*(std*)f).name);
	printf("friend name: %s\n", s1.friend->name);
	printf("student name: %s\n", s2.name);


	return 0;
}
