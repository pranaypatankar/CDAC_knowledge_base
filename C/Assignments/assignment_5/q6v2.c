#include<stdio.h>
#include<stdlib.h>

int m,n;
int x,y;

void addmat(int [][n],int [][y],int[][y]);
void submat(int [][n],int [][y],int[][y]);
void mulmat(int [][n],int [][y],int[][y]);

int main(){
	int num,choice;
	
	printf("Enter size of first matrix: ");
	scanf("%dx%d",&m,&n);

	int a[m][n];
	
	printf("Enter size of second matrix: ");
	scanf("%dx%d",&x,&y);
	
	int b[x][y];
	int res[m][y];
	
	printf("Enter first matrix: \n");

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
	//		printf("%d",a[i][j]);
		}
		printf("\n");
	}

	printf("Enter second matrix: \n");
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			scanf("%d",&b[i][j]);
	//		printf("%d",b[i][j]);
		}
		printf("\n");
	}
	int ch;

	printf("Enter the operation to perform \n1 --> Addition\n2 --> Subtraction\n3 --> Multiplication\n4 --> Exit\n");
	
	scanf("%d",&ch);
	
	switch(ch){
		case 1 :
			if(m==x)
				addmat(a,b,res);
			else exit(1);
			break;
		case 2 :
			if(m==x)
				submat(a,b,res);
			else exit(1);
			break;
		case 3 :
			if(m==y)
				mulmat(a,b,res);
			else exit(1);
			break;
		case 4 :
			exit(1);
			break;
		default :
			printf("invalid choice");
			break;
	}
	return 0;
}
void addmat(int a1[m][n], int b1[x][y],int res1[m][y]){
	printf("Sum of arrays\n");	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			res1[i][j]= a1[i][j] + b1[i][j];
			printf("%d\t",res1[i][j]);
		}
	printf("\n");
	}
}
void submat(int a1[m][n], int b1[x][y],int res1[m][y]){
	printf("Sum of arrays\n");	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			res1[i][j]= a1[i][j] - b1[i][j];
			printf("%d\t",res1[i][j]);
		}
	printf("\n");
	}
}
void mulmat(int arr1[m][n], int arr2[x][y],int arr3[m][y]){
	printf("Sum of arrays\n");	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			arr3[i][j] = 0;
			for(int k = 0; k < n; k++){
				arr3[i][j] += arr1[i][k]*arr2[k][j];
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<y;j++){
			printf("%d\t",arr3[i][j]);
		}
	printf("\n");
	}
}
