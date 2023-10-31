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


	printf("Reverse input: \n");
	reverse_string(input,n);

	return 0;
}

void reverse_string(char *sp,int i){
	if(i>0){
		printf("%c ",sp[i-1]);
		reverse_string(sp,(i-1));
	}
	else 
		printf("\n");
}

