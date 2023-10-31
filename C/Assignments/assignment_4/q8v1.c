#include<stdio.h>

int i;

void check1(char *,int);

int main(){
	int n=0;

	printf("Enter binary no. ");
	char input[15];
	scanf("%s",input);

	for(n=0;input[n]!='\0';n++);

	check1(input,n);

	printf("no of 1's is entered binary is %d\n",i);
	printf("no of 0's is entered binary is %d\n",n-i);
	
	return 0;
}

void check1(char *a,int n){
	for(int j=0;j<n;j++){
		if(a[j]=='1')
			i++;
	}
}
