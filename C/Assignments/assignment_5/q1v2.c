#include<stdio.h>
int n=0;
int *findElement(int [],int);
int main(){
	int a[10],j=0,i;
	int *res;

	printf("Enter 10 integers=\n ");

	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter no. to search: ");
	int num;
	scanf("%d",&num);
	res=findElement(a,num);
	for(j=0;j<n;++j) printf("%u\t",res[j]);
	return 0;

}
	
int *findElement(int a[], int num){
	int j=0;
	static int arr2[10];
	for(int i =0;i<=9;i++){
		if(a[i]==num){
			arr2[n]=i;
			n++;
			j++;
		}
	}
	if(n<1){
		printf("-1\n");
	}
	

	return arr2;
}
