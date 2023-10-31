#include<stdio.h>

void Sum(int *,int);

int main(){
	int n=0,input[20];

	printf("No. of inputs: ");
	scanf("%d",&n);

	for(int i=0;i<n;i++){
		printf("Enter %d no.: ",i+1);
		scanf("%d",&input[i]);
	}
	printf("sum of entered no.= ");
	Sum(input,n);
	return 0; 
}

void Sum(int *s,int i){
	int sum=0;
	for(int j=0;j<i;j++){
		sum=s[j]+sum;
	}
	printf("%d\n",sum);
}

