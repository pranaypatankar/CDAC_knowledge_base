/* Implementation of merge sort */
/* Merge Sort is the sorting algorithm which works on an array by successively dividing the array of n elements till it gets converted to the n arrays of single element, Single element array is always sorted, so from this end the single element array gets started to merge till we get a complete merged sorted array as result */

#include<stdio.h>
#include<stdlib.h>

void merge_sort(int [], int, int);								// Function to implement merge sort algorithm
void merge(int [], int, int, int, int);								// Function to merge the individual arrays
void display(int [],int,int);									// Function to display the sorted and unsorted array

int main(){

	int num;
	printf("Enter the number of elements in the array to be entered : ");			// User Input
	scanf("%d",&num);
	
	printf("Enter the elements in the array........\n");					// User Input 
	int arr[num], i;
	for(i=0; i< num; i++){								
		scanf("%d",&arr[i]);
	}
	
	printf("\n................... Printing Unsorted array ..................\n");
	display(arr,0,num);									// Calling the display function
	
	merge_sort(arr,0, num-1);								// Calling the merge sort

	return 0;
}

void display(int arr[],int start, int num){							// Defining the display function
	int i;
	for(i = start; i<num; i++){
		
		printf("%d\t", arr[i]);
	}
	printf("\n");

}

void merge_sort(int arr[], int first, int last){						// Defining the merge sort function
	
	printf("Merge Sort called with range %d - %d\n",first, last);				// Printing the result of every pass
	display(arr,first,last);								// Calling the display function

	if(first >= last){									// Termination condition for recursion
		return;
	}
		
	int mid = (first + last)/2;								// Calculating the mid position

	merge_sort(arr,first,mid);								// Calling the merge sort function for position first till mid
	merge_sort(arr, (mid+1),last);								// Calling the merge sort function for position mid +1 till last
	
	printf("\n.................. Sorted array between range %d - %d .................\n",first,mid);
	display(arr,first, mid);								// Calling the display function to display the sorted array1 (from first index to mid index)
	
	printf("\n.................. Sorted array between range %d - %d .................\n",(mid+1),last);
	display(arr, (mid+1),last);								// Calling the display function to display the sorted array2 (from (mid +1) index to last index)
	
	merge(arr,first,mid,(mid+1),last);							// Calling the merge function to merge the sub array after sorting
}

void merge(int arr[],int first1, int last1, int first2 , int last2){				// Defining the merge function to merge the sorted sub arrays
	
	printf("Merging two sorted ranges %d - %d and %d - %d\n", first1,last1,first2,last2);

	int size = (last1 - first1 + 1) + (last2 - first2 + 1);					// Calculating the size of resulted array to store the merged array
	int a = first1;
	int b = first2;
	int c = 0;
	int *result;				

       	result = (int *)malloc((size*sizeof(int)));						// Dynamicaaly allocating the memory for resulted array
	
	while(a <= last1 && b <= last2){							// loop to check till a and b is greater than last1 and last2 respectively
		
		if(arr[a] < arr[b]){								// Condition check for element of array 1 and array 2 
			result[c] = arr[a];							// Store array1 element into result
			a++;									// Increment position of a (the current index of array1)
			c++;									// Increment position of c (the current index of resulted array)
		}

		else{
			result[c] = arr[b];							// Store the array 2 element into result
			b++;									// Increment position of b (the current index of array2)
			c++;									// Increment position of c (the currnt index of resulted array)
		}

	}

	while(a <= last1){									// Loop to store remaining elements of array 1
		result[c] = arr[a];
		a++;
		c++;
	}
	
	while(b <= last2){									// Loop to store remaining elements of array 2
		result[c] = arr[b];
		b++;
		c++;
	}

	c = 0;											// Setting the index of resulted array to 0
	
	for(int i = first1; i<=last2 ; i++){							// Storing the resulted array to the original array
		arr[i] = result[c];								
		c++;										// Incrementing the index of the original array
	}
 
	printf("Merged array from range %d to %d is\n",first1,last2);				// Printing the final array
	display(arr,first1,(last2+1));								// Calling the display function
	
	free(result);										// Freeing the temporary array
}


