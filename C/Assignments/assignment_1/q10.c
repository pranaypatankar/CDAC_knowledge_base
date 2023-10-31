#include <stdio.h>

int main()
{
    int r,c;

    for(r=1; r<=5; r++)
    {
        // printing the space
        for(c=4; c>=r; c--)
        {
            printf(" ");
        }

        // printing the star
        for(c=1; c<=r; c++)
        {
            printf("%d ",r);		// print the star with a space, it will make a triangle
        }
        printf("\n");
    }
    return 0;
}
