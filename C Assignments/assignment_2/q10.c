#include<stdio.h>

void list_prime(int,int);
int check(int);

int main(){
	int num1,num2,i=0,j;
	printf("enter range to be listed(num1-num2):");
    scanf("%d-%d",&num1,&num2);
	list_prime(num1,num2);

	return 0;
}	

void list_prime(int a, int b){

	int i,j,k;
	i=0;
	for(i=a;i<=b;i++){
		i++;
		j=check(i);
		if(j==0) printf("%d \t",i);
	}


}
int check(int n){
	int i, flag = 0;
	if (n == 0 || n == 1)
    flag = 1;

  for (i = 2; i <= n / 2; ++i) {

    // if n is divisible by i, then n is not prime
    // change flag to 1 for non-prime number
    if (n % i == 0) {
      flag = 1;
      }
  }

  // flag is 0 for prime numbers
  return flag;
}
