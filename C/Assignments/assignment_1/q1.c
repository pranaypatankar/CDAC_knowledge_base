
#include<stdio.h>

int main(){
	int a,b;

	scanf("%d",&a);
	scanf("%d",&b);

	printf("before swaping a =%d,b=%d\n",a,b);

	a=a+b;
	b=a-b;
	a=a-b;

	printf("after swaping a =%d,b=%d\n",a,b);
}

