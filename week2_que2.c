#include <stdio.h>
int main()
{
    int test, num, temp, key;
    printf("Enter test case : ");
    scanf("%d", &test);
    for (int k = 0; k < test; k++)
    {

        printf("Enter no. for square matrix : ");
        scanf("%d", &num);
        int arr[num][num];
        printf("Enter elements\n");
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        printf("Enter key : ");
        scanf("%d", &key);
        int i = 0, j = num - 1;
        while (i < num && j >= 0)
        {
            if (arr[i][j] == key)
            {
                temp = 1;
                break;
            }
            else if (arr[i][j] < key)
            {
                i++;
            }
            else if (arr[i][j] > key)
            {
                j--;
            }
            else
            {
                continue;
            }
        }
        if (temp == 1)
        {
            printf("present\n");
        }
        else
            printf("not present\n");
    }
}