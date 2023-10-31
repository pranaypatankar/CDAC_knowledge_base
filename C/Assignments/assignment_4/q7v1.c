#include<stdio.h>
void convert(int, int);

int main()
{
        int num;
        printf("Enter a positive decimal number : ");
        scanf("%d", &num);
        printf("\nBinary number :: ");
        convert(num, 2);
        printf("\n");
        printf("\nOctal number :: ");
        convert(num, 8);
        printf("\n");
        printf("\nHexadecimal number :: ");
        convert(num, 16);
        printf("\n");

        return 0;
}

void convert (int num, int base)
{
        int rem[10],n=0;
       	for(int i=0;num!=0;i++){
       		rem[i]= num%base;
		num= num/base;
		n++;
	}
        for (int i=n;i>0;i--){
		if(rem[i-1]< 10)
                printf("%d", rem[i-1]);
        else
                printf("%c", rem[i-1]-10+'A' );
	}
}
