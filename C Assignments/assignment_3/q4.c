#include<stdio.h>

int main(){
    int a, b, c,d;
    printf("enter digits to be compared:\t");
    scanf("%d %d %d",&a,&b,&c);

    d=((a>b&&a>c)?a:((b>c&&b>a)?b:c));
    printf("Largest no among %d, %d & %d is %d",a,b,c,d);
}