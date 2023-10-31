#include<stdio.h>  

int main()  {  
	// declare and initialize the variables  
	int num, rem, sum = 0, i;  
	// take an input from the user.  
	printf("Enter a number\t");  
	scanf("%d", &num);      
	// find all divisors and add them  
	for(i = 1; i<=num; i++)  
                     {
		        rem = num % i;  
			if (rem == 0)   sum = sum + i;  
                     }  
	if ((sum/2) == num)    printf(" %d is a Perfect Number\n",num);  
        else                   printf("\n %d is not a Perfect Number\n",num);  
	return 0;  
}  
