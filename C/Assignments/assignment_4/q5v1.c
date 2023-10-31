#include<stdio.h>

int GCD(int ,int );
int main(){
	int gcd,num1,num2;

	printf("Enter first no.:- ");
	scanf("%d",&num1);
	printf("Enter second no.:- ");
	scanf("%d",&num2);
	gcd=GCD(num1,num2);
	printf("GCD of %d and %d is %d\n",num1,num2,gcd);
	 
	 return 0;
}
int GCD(int num1,int num2){
	int gcd=0;
	for(int i=1;i<=num1&&i<=num2;++i){
	 if(num1%i==0&&num2%i==0){
		gcd=i ;
		}
	}
	return gcd;	
}
