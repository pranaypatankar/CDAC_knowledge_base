#include <stdio.h>


int main()
{
    int r,c,n;

    printf("input no. of rows:");

    scanf("%d",&n);

    for(r=1; r<=n; r++)
    {
        // printing the space
        for(c=4; c>=r; c--)
        {
            printf(" ");
        }

        // printing the number
        for(c=1; c<=r; c++)
        {
            printf("%d",r);
        }
        printf("\n");
    }
    return 0;
}
