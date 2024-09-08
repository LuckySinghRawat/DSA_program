#include <stdio.h>
int main()
{
    int n, m, count;
    printf("enter row and column :  ");
    scanf("%d", &n);
    scanf("%d", &m);
    int arr[n][m];
    printf("enter elements\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int i = 0, j = n - 1;
    while (i < n && j >= 0)
    {
        if (arr[i][j] == 0)
        {
            i++;
        }
        else
        {
            j--;
            count = i;
        }
    }
    if (count > 0)
    {
        printf("row - %d", ++count);
    }
    else
    {
        printf("Not Present");
    }
    return 0;
}