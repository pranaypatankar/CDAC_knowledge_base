#include<stdio.h>

int res=1;

int power(int ,int);

int main(){
	int n,b;
	
	
	printf("Enter digit : ");
	scanf("%d",&b);
	
	printf("Enter power to which %d is to be raised :",b);
	scanf("%d",&n);
	
	res=power(b,n);

	printf("%d raised to %d is %d\n",b,n,res);

	return 0;
	}

int power(int i,int b){
	
	if(b>0){
		res=res*i;
		power(i,b-1);
	}
	return res;
}

