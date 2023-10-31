#include<stdio.h>

int sum_digit(int);
    
int main(){
    int num,rem,sum;

    printf("enter no. :- \t");
    scanf("%d",&num);

    sum=sum_digit(num);
    printf("sum of digits of %d is %d\n",num,sum);
    return 0;
}

int sum_digit(int num){
    //if(num/10==0 ){return num;}
    while(num/10!=0){
    num = num%10+sum_digit(num/10);
    }
    return num;
}