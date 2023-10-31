#include <stdio.h>
#include <stdlib.h>

int main(){
	int row;
	int *col;
	int **arr2d;

	printf("Enter no. of Rows: ");
	scanf("%d",&row);

	col=(int *)malloc(sizeof(int *)*row);
	
	if(col==NULL){
		printf("memory not allocated\n");
		exit(1);
	}
	
	arr2d=(int **)malloc(sizeof(int *) * row);

	for(int i=0;i<row;i++){
		printf("No. of coloumns in row %d: ",i);
		scanf("%d",col+i);
		arr2d[i]=(int *)malloc(sizeof(int)*col[i]);
	}

	for(int i=0;i<row;i++){
		for(int j=0;j<col[i];j++){
			printf("Enter %d element of %d: ",j,i);
			scanf("%d",&arr2d[i][j]);
		}
	}
	printf("\n");

	for(int i=0;i<row;i++){
		for(int j=0;j<col[i];j++){
			printf("%d\t",arr2d[i][j]);
		}
		printf("\n");
	}

	for (int i=0;i<row;i++)
		free(arr2d[i]);

	free(arr2d);

	free(col);

	return 0;
}   