#include<stdio.h>
void check_identity(int [][10],int);

int main(){
	int num;
	int arri[10][10]={0};
	
	printf("enter no. of rows/coloumns in matrix: ");
	scanf("%d",&num);
	
	printf("Enter matrix of size %dx%d\n",num,num);
//scanning matrix
	for(int i =0;i<num;i++){
		for (int j=0;j<num;j++){
				scanf("%d",&arri[i][j]);
		}
	}
	check_identity(arri,num);
	return 0;	
}

void check_identity(int arr[10][10],int n){

	int count1 =0, count2=0;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j && arr[i][j]==1) count1++;
			if(i!=j && arr[i][j]!=0) count2++;
		}
	}
	if(count1==n && count2==0)
		printf("Entered matrix is identity\n");
	else
		printf("Entered matrix is not an identity\n");
}	
