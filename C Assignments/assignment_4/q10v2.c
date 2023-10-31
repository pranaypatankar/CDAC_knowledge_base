#include<stdio.h>

int n;

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
	
	if(*i!='\0'){
		n++;
		counter(i+1);
	}
	return n;
}

