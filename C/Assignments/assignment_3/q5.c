#include<stdio.h>

int main(){
    int hh,mm,ss;
    printf("Enter time  (hh:mm:ss) : ");
    scanf("%d:%d:%d",&hh,&mm,&ss);
    printf("Total seconds : %d",((hh*3600)+(mm*60)+ss));
}