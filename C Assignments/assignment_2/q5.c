#include <stdio.h>

int main() {

  int n;
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  check(n);

  // 0 and 1 are not prime numbers
  // change flag to 1 for non-prime number
  

  return 0;
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
  if (flag == 0)
    printf("%d is a prime number.", n);
  else
    printf("%d is not a prime number.", n);
}