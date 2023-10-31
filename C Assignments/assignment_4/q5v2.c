#include<stdio.h>

int i=1;
int gcd;

int GCD(int ,int ,int);

int main(){
	int num1,num2;

	printf("Enter first no.:- ");
	scanf("%d",&num1);
	printf("Enter second no.:- ");
	scanf("%d",&num2);
	gcd=GCD(num1,num2,i);
	printf("GCD of %d and %d is %d\n",num1,num2,gcd);
	 
	 return 0;
}
int GCD(int num1,int num2,int j){
	i++;
	 if(num1%j==0&&num2%j==0){
		return gcd=i ;
		}
	 else 
		 return GCD(num1,num2,i);	
}
