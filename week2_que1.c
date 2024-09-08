#include <stdio.h>
int main()
{
    int test = 0, element, count, i, flag = 1;
    printf("Enter no. of test case:  ");
    scanf("%d", &test);
    for (int k = 1; k <= test; k++)
    {
        printf("Enter no. of elements : ");
        scanf("%d", &element);
        int arr[element];
        printf("Enter Elements \n");
        for (i = 0; i < element; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (i = 0; i < element; i++)
        {
            count = 0;
            for (int j = 0; j < element; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
            }
            if (count % 2 != 0)
            {
                printf("Element present odd number of times is %d\n", arr[i]);
                flag = -1;
            }
        }
        if (flag != -1)
        {
            printf("No such element is present in array\n");
        }
    }
}