// #include <stdio.h>

// int main()
// {
//     int n;

//     printf("Enter a natural number: ");
//     scanf("%d", &n);

//     int p = n;
//     for (size_t i = 0; i < (2 * n - 1); i++)
//     {
//         printf
//     }
    
// }

#include<stdio.h>
void main()
{
    int arr[10]={1,4,2,5,3,9,7,10,8,0};
    int index, min, temp;

    for(int i = 0; i < 10; i++)   
    {
        min = arr[i];
        int flag = 0;

        for (size_t j = i + 1; j < 10; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                index = j;
                flag = 1;
            }           
        }

        if (flag)
        {
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }

    for(int k = 0; k < 10; k++)
    {
        printf("%d\t", arr[k]);
    }
}