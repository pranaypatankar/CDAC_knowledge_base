#include<stdio.h>

int counter(char *);

int main(){
	char input[100];

	printf("Enter number: ");
	scanf("%s",input);

	int count=counter(input);

	printf("no. of digits in input is %d\n",count);

	return 0;
}

int counter(char *i){
	int n;
	for(n=0;i[n]!='\0';n++);
	return n;
}

