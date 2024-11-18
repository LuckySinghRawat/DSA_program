#include <stdio.h>

int merge(int *arr, int i, int mid, int k, int j)
{
    int temp[100], p = i;
    while (i <= mid && k <= j)
    {
        if (arr[i] < arr[k])
        {
            temp[p++] = arr[i++];
        }
        else
            temp[p++] = arr[k++];
    }
    while (i <= mid)
    {
        temp[p++] = arr[i++];
    }
    while (k <= j)
    {
        temp[p++] = arr[k++];
    }
    for (int i = 0; i <= j; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int *arr, int i, int j)
{
    if (i == j)
    {
        return;
    }

    int mid = i + (j - i) / 2;
    mergeSort(arr, i, mid);
    mergeSort(arr, mid + 1, j);
    merge(arr, i, mid, mid + 1, j);
}

int main()
{
    int arr[] = {1, 5, 3, 2, 4, 6, 9, 10, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0])-1, i = 0;

    printf("Before sorting : ");
    for (int i = 0; i <= n; i++)
    {
        printf("%d  ", arr[i]);
    }

    mergeSort(arr, i, n);

    printf("\nAfter sorting : ");
    for (int i = 0; i <= n; i++)
    {
        printf("%d  ", arr[i]);
    }
}