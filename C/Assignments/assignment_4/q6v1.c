#include<stdio.h>

int main(){
	int a,b,c,n,i,temp;

	printf("Input no. of elements in series");
	scanf("%d",&n);

	a=0;
	b=1;
	c=a+b;
//	printf("%d\n",c);
	printf("Fibonacci Series :-%d\t%d\t",a,b);

	for(i=0;i<=n;++i){
	
		temp=c+b;
		printf("%d\t",temp);
		b=c;
	}
	return 0 ;
}

