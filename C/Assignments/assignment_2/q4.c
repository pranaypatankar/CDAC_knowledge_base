#include<stdio.h>

int main(){
	int gcd,num1,num2,LCM,i;

	printf("Enter first no.:- ");
	scanf("%d",&num1);
	printf("Enter second no.:- ");
	scanf("%d",&num2);
	for(i=1;i<=num1&&i<=num2;++i){
	 if(num1%i==0&&num2%i==0){
		gcd=i ;
		}
	}
	 printf("GCD of %d and %d is %d\n",num1,num2,gcd);
	 
	 LCM=(num1*num2)/gcd;

	 printf("LCM of %d and %d is %d\n",num1,num2,LCM);
	 
	 return 0;
}
	
