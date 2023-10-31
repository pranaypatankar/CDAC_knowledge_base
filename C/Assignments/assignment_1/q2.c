#include<stdio.h>

int main(){
	int a,r;
	printf("enter 3-digit no.");

	scanf("%d",&a);

	r=a%10;
	printf("%d",r);
	r=a/10;
	r=r%10;
	printf("%d",r);
	r=a/100;
	printf("%d\n",r);

	return 0;
}
