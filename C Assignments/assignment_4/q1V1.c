#include<stdio.h>

void reverse(int *,int );

int main(){
	int a[10],n;

	printf("Enter no. of elements in array: ");
	scanf("%d",&n);

	printf("Enter elements\n");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	reverse(a,n);
	return 0;
}

void reverse(int *ap,int n){
	printf("reverse of entered array \n");

	for(int i=(n-1);i>=0;i--){
		printf("%d\t",ap[i]);}
	printf("\n");
}

