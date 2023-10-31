#include<stdio.h>

int Sum(int *,int);
int sum;
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
	printf("%d\n",sum);
	return 0; 
}

int  Sum(int *s,int i){
	int j=i;
	if(j>0){
		sum=s[j-1]+sum;
		return (Sum(s,(i-1)));
}
	return sum;
}

