#include<stdio.h>
#include<stdlib.h>

int add(int,int);
int sub(int,int);
int multiply(int,int);
int div1(int,int);

int main(){
	int num1,num2,choice,result;
	while(1){
	printf("Enter first no : ");
	scanf("%d",&num1);
	printf("Enter second no: ");
	scanf("%d",&num2);
	printf("Enter choice \n 1--->Addition \t 2---> Subtraction \t 3---> Multiply \t 4--->Division \t 5--->exit  \n ");
	scanf("%d",&choice);
		switch(choice){
			case 1 :
				result = add(num1,num2);
				printf("result is : %d",result);
				break;
			case 2 :
				result = sub(num1,num2);
				printf("result is : %d",result);
				break;
			case 3 :
				result = multiply(num1,num2);
				printf("result is : %d",result);
				break;
			case 4 :
				result = div1(num1,num2);
				printf("result is : %d",result);
				break;
			case 5 :
				exit(1);
			default :
				printf("Enter valid choice....");
				break;
			}
		printf("\n");
	}
	return 0;
}

int add(int x, int y){
	return x+y;
}

int sub(int x, int y){
	return x-y;
}

int multiply(int x, int y){
	return x*y;
}

int div1(int x, int y){
	return x/y;
}


