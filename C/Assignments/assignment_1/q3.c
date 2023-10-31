#include<stdio.h>

int main(){
	int a,b,c;

	scanf("%d\n %d\n %d",&a,&b,&c);

	printf("largest no. among these is:\n");
	if(a>b&&a>c){
		printf("%d",a);}
	else if (b>a&&b>c){
		printf("%d",b);}
	else{printf("%d",c);}
	printf("\n");

	return 0;
}


