#include<stdio.h>

int main(){
	int num;
	int arri[10][10]={0};
	
	printf("enter no. of rows/coloumns in matrix: ");
	scanf("%d",&num);
	
	printf("null matrix of size %dx%d\n",num,num);
//printing null matrix
	for(int i =0;i<num;i++){
		for (int j=0;j<num;j++){
				printf("%d\t",arri[i][j]);
		}
		printf("\n");
		printf("\n");
	}
	printf("\n");
	printf("\n");
//Replacing diagonal elements with 1
//
	for(int i=0;i<num;i++){
		arri[i][i]=1;	
	}

//printing identical matrix
	printf("Identity matrix of size %dx%d\n",num,num);
	
	for(int i =0;i<num;i++){
		for (int j=0;j<num;j++){
			//if(i==j){
				printf("%d\t",arri[i][j]);
			
			//else printf("0\t");
		}
		printf("\n");
		printf("\n");
	}
	return 0;
}

