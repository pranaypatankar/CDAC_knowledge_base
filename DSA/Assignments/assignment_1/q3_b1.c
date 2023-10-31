#include <stdio.h>
#include <stdlib.h>

int main(){
	int row,col;
	int **arr2d;

	printf("Enter no. of Rows: ");
	scanf("%d",&row);
	printf("Enter no. of Coloumns: ");
	scanf("%d",&col);

	arr2d=(int **)malloc(sizeof(int *)*row);
	if(arr2d==NULL){
		printf("memory not allocated\n");
		exit(1);
	}

	for(int i=0;i<row;i++){
		arr2d[i]=(int *)malloc(sizeof(int)*col);
	}

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("Enter %d element of %d: ",j,i);
			scanf("%d",&arr2d[i][j]);
		}
	}
	printf("\n");

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%d\t",arr2d[i][j]);
		}
		printf("\n");
	}

	for(int i=0;i<row;i++)
		free(arr2d[i]);

	free(arr2d);
	
	return 0;
}