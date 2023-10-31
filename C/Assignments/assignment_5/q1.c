#include<stdio.h>
int n;
int find_element(int *,int);
int main(){
	int a[10],j=0,i,arr[10];

	printf("Enter 10 integers= ");

	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter no. to search: ");
	int num;
	scanf("%d",&num);
	arr[10]=find_element(a,num);
	for(j=0;j<=n;j++)
		printf("%d\t",arr[j]);
	printf("\n");
	return 0;
}

int find_element(int a[],int num){
	int i,j=0,arr[n];
	for(int i =0;i<=9;i++){
		if(a[i]==num){
			arr[n]=i;
			n++;
			//printf("No. found at index %d\n",i);
			j++;
			}
	}

	if(j<1){
		printf("-1\n");
		return -1;
	}
	return *arr;
}
