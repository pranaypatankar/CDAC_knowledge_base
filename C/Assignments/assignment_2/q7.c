/* (not working)
 * #include<stdio.h>

int main(){
	int n,i=0,j,temp=1,rem[i];

	printf("Enter no. :-");
	scanf("%d",&n);
	for(i=0;n/10==0;i++){
		rem[i]=n%10;
	}
	for(i;i==0;--i){
		for(j=0;j==i;j++){
			temp = temp*rem[i];
		}
		rem[i]=temp;
	}
	int sum=0;
	for(j=0;j==i;j++){
		sum=sum+rem[j];
	}
	if(n==sum) printf("This is a Armstrong No.\n");
	else printf("This is not a Armstrong no.\n");
	return 0;
}
*/
#include <stdio.h>

int main() {
   int num, originalNum, remainder, n = 0;
   float result = 0.0;

   printf("Enter an integer: ");
   scanf("%d", &num);

   originalNum = num;

   // store the number of digits of num in n
   for (originalNum = num; originalNum != 0; ++n) {
       originalNum /= 10;
   }

   for (originalNum = num; originalNum != 0; originalNum /= 10) {
       remainder = originalNum % 10;

      // store the sum of the power of individual digits in result
      result += pow(remainder, n);
   }

// checking number is Armstrong number or not
   if ((int)result == num)
    printf("%d is an Armstrong number.", num);
   else
    printf("%d is not an Armstrong number.", num);
   return 0;
}

