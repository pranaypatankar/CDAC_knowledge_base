#include<stdio.h>

int main(){
	int a,b;

	printf("Enter year:");
	scanf("%d",&a);

	b= a%4;

	if(b==0){
		printf("This is a leap year\n");
	}
	else {printf("This is not a leap year\n");
	}
	return 0;
}
	

