#include<stdio.h>
#include<stdlib.h>


int n;
int searchEle(int *, int, int);
void printArr(int *, int);
void revPrintArr(int *, int);

int main()
{
	printf("ENTER THE SIZE OF ARRAY: ");
	scanf("%d", &n);
	int *arr;
	int i=0;

	arr = (int *)malloc(n*sizeof(int));
	if(arr == NULL)
	{
		printf("MEMORY NOT ALLOCATED!\n");
		exit(1);
	}
	int ele=0;
	for(int i = 0; i < n; i++)
	{
		int flag=0;
		printf("Enter element %d: ", i+1);
		scanf("%d", &ele);
		for(int j=0; j<i; j++)
		{
			if(ele == arr[j])
			{
				flag++;
			}
		}
		if(flag==0)
		{
			arr[i]=ele;
		}
		else
		{
			printf("ENTER A UNIQUE ELEMENT!\n");
			i--;
		}
	}
	printf("----ENTERED ARRAY----\n");
	printArr(arr,i);
	printf("\n");

	int elem;
	printf("ENTER THE ELEMENT TO SEARCH: ");
	scanf("%d", &elem);

	int s;
	s = searchEle(arr, elem, i);
	if(s == 0)
	{
		printf("%d NOT FOUND IN ARRAY!\n", elem);
	}
	else
	{
		printf("%d FOUND AT INDEX %d\n", elem, s);
	}
	printf("\n");

	printf("----REVERSED ARRAY----\n");
	revPrintArr(arr,n-1);

	free(arr);

	return 0;
}

int searchEle(int *array, int ele, int i)
{
	int temp=0;

	if(array[i]!=ele)
	{
		if(i>n)
		{
			return 0;
		}
		else
		{
			searchEle(array, ele, i+1);	
		}

	}
	else
	{
		return i+1;
	}
}

void printArr(int *array,int i)
{
	if(i >= n)
	{
		printf("\n");
		return;
	}else
	{
		printf("%d\t",array[i]);
		printArr(array,i+1);
	}
}

void revPrintArr(int *array, int i)
{
	if(i < 0 )
	{
		printf("\n");
		return;
	}else
	{
		printf("%d\t",array[i]);
		revPrintArr(array,i-1);
		return;
	}
}