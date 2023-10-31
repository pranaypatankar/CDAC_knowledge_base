#include<stdio.h>

int main(){
    int a=10,b=20,c=30,d;

    d=++a,++b,++c,a+5;
    printf("d=++a,++b,++c,a+5 is equal to %d\n",d);
    //d=11 because assign operator has more presendence than ,(comma) operator
    
    a=10,b=20,c=30;
    d=(++a,++b,++c,a+5);
    printf("d=(++a,++b,++c,a+5)is equal to %d\n",d);
    //d=16 as expression is in paranthesis which neesds to be solved before assign
}