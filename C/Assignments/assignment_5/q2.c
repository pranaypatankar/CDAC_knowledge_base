#include<stdio.h>
int n;
int* findElement(int *,int);
int main(){
	int a[10],j=0,i,*res[n];

	printf("Enter 10 integers=\n ");

	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter no. to search: ");
	int num;
	scanf("%d",&num);
	res[n]=findElement(a,num);
	for(;j<=n;printf("%p\t",res[j]));
	return 0;

}
	
int* findElement(int a[], int num){
	int j=0,*arr2[n];
	for(int i =0;i<=9;i++){
		if(a[i]==num){
			n++;
			arr2[n]=&a[i];
			j++;
		}
	}
	if(j<1){
		printf("-1\n");
	}
	return *arr2;
}
