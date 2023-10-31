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

	printf("reverse of entered array \n");
	reverse(a,n);
	return 0;
}

void reverse(int *ap,int n){
	if(n>0){
		printf("%d\t",ap[n-1]);
		reverse(ap,(n-1));}
	else 	
		printf("\n");
}

