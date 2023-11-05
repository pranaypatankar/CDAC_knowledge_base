#include<stdio.h>
#include<stdlib.h>

int n;
int searchEle(int *, int);
void printArr(int *);
void revPrintArr(int *);

int main()
{
	printf("ENTER THE SIZE OF ARRAY: ");
	scanf("%d", &n);
	int *arr;

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
	printArr(arr);
	printf("\n");

	int elem;
	printf("ENTER THE ELEMENT TO SEARCH: ");
	scanf("%d", &elem);

	int s;
	s = searchEle(arr, elem);
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
	revPrintArr(arr);

	free(arr);

	return 0;
}

void printArr(int *array)
{
	for(int i=0; i<n; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
}

int searchEle(int *array, int ele)
{
	int temp = 0;

	for(int i = 0; i < n; i++)
	{
		if(ele == array[i])
		{
			temp = i;
		}
	}
	return temp;
}

void revPrintArr(int *array)
{
	for(int i = n-1; i >= 0; i--)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
}