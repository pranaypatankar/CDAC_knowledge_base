#include<stdio.h>

int res;

void factorial(int);

int main(){
	int a;
	
	printf("input no.");

	scanf("%d",&a);
	res=a;
	factorial(a);
	return 0;
}

void factorial(int a){

	int i,b=1;
	for(i=1;i<=a;i++){
		b=b*i;
	}
	printf("%d\n",b);
}
