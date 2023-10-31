#include<stdio.h>

void reverse_string(char *,int);


int main(){
	int n=0;
	char input[30];

	printf("enter string\n");
	scanf("%s",input);
	
	for(int i=0;input[i]!='\0';i++){
		n++;
	}


	reverse_string(input,n);

	return 0;
}

void reverse_string(char *sp,int i){
	printf("Reverse input: \n");
	for(int j=i;j>0;j--)
		printf("%c ",sp[j-1]);
}

