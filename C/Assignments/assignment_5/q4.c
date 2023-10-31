#include<stdio.h>

void add(int *, int *,int);

int main(){
	int n;

	printf("No of elements in array :- ");
	scanf("%d",&n);

	int a[n],b[n];

	printf("Enter first array ");
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	printf("Enter second array ");
	for (int i=0;i<n;i++)
		scanf("%d",&b[i]);

	add(a,b,n);
	
	return 0;
}

void add(int *x,int *y,int n){
	int res[n];

	for(int i=0;i<n;i++){
		res[i]=x[i]+y[i];
	}
	printf("a+b=\t");
	for(int i=0;i<n;i++){
		printf("%d\t",res[i]);}
	printf("\n");
}

