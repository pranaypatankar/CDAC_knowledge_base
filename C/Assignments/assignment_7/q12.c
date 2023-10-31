#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int sum(int ,int);
int sub(int ,int);
int mul(int ,int);
int div1(int ,int);

void test(int,int, int (*)(int,int));

int main(){
	int x,y;
	int choice;

	while(1){
	printf("Enter nos. (a,b): ");
	scanf("%d,%d",&x,&y);
	printf("Select function :\n1.Sum\n2.Sub\n3.Multiply\n4.Divide\n5.Exit \n");
	scanf("%d",&choice);

	switch(choice){
	
	case 1:
		test(x,y,sum);
		break;
	
	case 2:
		test(x,y,sub);
		break;
	
	case 3:
		test(x,y,mul);
		break;
	
	case 4:
		test(x,y,div1);
		break;
	
	case 5:
		exit(1);
		break;
	
	default:
		printf("Enter valid choice.\n");
		break;
	}
}

	return 0;
}

int sum(int a, int b){
	return (a+b);
}

int sub(int a, int b){
	return (a-b);
}

int mul(int a, int b){
	return (a*b);
}

int div1(int a, int b){
	return (a/b);
}

void test(int a, int b, int (*fp)(int,int)){

	int z= fp(a,b);
	printf("result = %d\n",z);

}
