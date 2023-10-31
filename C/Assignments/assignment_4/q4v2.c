#include<stdio.h>

int res=1;

int factorial(int);

int main(){
	int a;
	
	printf("input no. ");

	scanf("%d",&a);
	factorial(a);
	printf("Factorial of %d is %d\n",a,res);
	return 0;
}

int factorial(int a){
	if(a>=1){
		res=res*a;
		return(factorial(a-1));
	}
	else       			
		return res;
}
