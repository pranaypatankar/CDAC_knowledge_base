// C Program to calculate calling of function
//
#include <stdio.h>

// function with static variable
int fun(int);

int main()
{	printf("In this Code, fun() is called ");
	printf("%d times \n", fun(10));

	return 0;
}

int fun(int n)
{
	static int count = 0;
	
	if(n!=0){
		count++;
		return fun(n-1);
	}
	else return count;
}
