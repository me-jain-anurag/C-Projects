#include <stdio.h>

int main()
{
    int i,j;
    for(i=100;i>0;i=i-10)
    {
        if((i/10)%2==0)
        {
            for(j=i;j>i-10;j--)
                printf("%d\t",j);
            printf("\n");
        }
        else
        {
            for(j=i-9;j<=i;j++)
                printf("%d\t",j);
            printf("\n");
        }
    }
}