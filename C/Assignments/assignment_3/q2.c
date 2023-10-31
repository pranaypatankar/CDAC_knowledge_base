//swapping 2 numbers using one line code

#include<stdio.h>

int main(){
    int x,y;
    printf("Enter no. to be swapped(num1,num2)");//taking inputs
    scanf("%d,%d",&x,&y);

    x=x^y^(y=x);
    printf("After swap: num1= %d, num2=%d",x,y);
}