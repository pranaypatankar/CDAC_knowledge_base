#include<stdio.h>

int main(){
	int i,a,b=1;
	
	printf("input no.");

	scanf("%d",&a);
	
	for(i=1;i<=a;i++){
		b=b*i;
	}
	printf("%d\n",b);
	return 0;
}


