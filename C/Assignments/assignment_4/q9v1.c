#include<stdio.h>

int power(int ,int);

int main(){
	int a,n,b;
	
	
	printf("Enter digit : ");
	scanf("%d",&b);
	
	printf("Enter power to which %d is to be raised :",b);
	scanf("%d",&n);
	
	a=power(b,n);

	printf("%d raised to %d is %d\n",b,n,a);

	return 0;
	}

int power(int a,int b){
	int res=1;
	for(int i=1;i<=b;i++)
			res=a*res;
	return res;
}

