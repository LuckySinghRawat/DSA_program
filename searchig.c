/*
SEARCHING
        # Sequential Search
        -> recursion
        -> iteration
        # Binary Search
        -> recursion
        -> iteration
        # Index Sequential Search

*/

#include <stdio.h>
#include <stdlib.h>

void sequentialSearch(int arr[], int start, int end, int key)
{
    int i, flag = 0;
    for (i = start; i <= end; i++)
    {
        if (arr[i] == key)
        {
            printf("Fount at position : %d\n", i + 1);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Not found\n");
    }
}

int recursiveSequentialSearch(int *arr, int start, int end, int key)
{
    if (key == arr[start])
    {
        return start;
    }
    else if (start > end)
    {
        return -1;
    }
    else
    {
        return recursiveSequentialSearch(arr, start + 1, end, key);
    }
}

int binarySearchItreation(int arr[], int start, int end, int key)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int binarySearch(int arr[], int start, int end, int key)
{
    if (start > end)
    {
        return -1;
    }
    else
    {
        int mid = (start + end) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            binarySearch(arr, start, mid - 1, key);
        }
        else
        {
            binarySearch(arr, mid + 1, end, key);
        }
    }
}

int indexSequentialSearch(int arr[], int n, int key)
{
    int index[20];
    int blockSize = 4, x = 0, start, end;
    
    for (int i = 0; i < n; i = i + blockSize)
    {
        index[x++] = i;
    }

    if (key < arr[index[0]])
    {
        printf("  Not found......\n");
        exit(0);
    }
    else if (key > arr[index[x - 1]])
    {
        start = index[x - 1];
        end = n;
    }
    else
    {
        for (int j = 1; j <= x; j++)
        {
            if (key <= arr[index[j]])
            {
                start = index[j - 1];
                end = start + blockSize;
                break;
            }
        }
    }

    sequentialSearch(arr, start, end, key);
}

int main()
{
    int arr1[] = {1, 4, 2, 5, 44, 66, 34, 76, 55};
    int n1 = sizeof(arr1) / sizeof(arr1[0]); // size of array
    int searchkey;
    printf("Enter the element to search: ");
    scanf("%d", &searchkey);



    // sequentialSearch(arr1, 0, n1 - 1, searchkey);

    // int flag = recursiveSequentialSearch(arr1, 0, n1, searchkey);
    // if (flag == -1)
    // {
    //     printf("Not Found...\n");
    // }
    // else
    // {
    //     printf("Found at position %d......\n", flag + 1);
    // }



    // // Binary Search
    // int arr2[] = {1, 3, 4, 6, 8, 9, 11, 44, 66, 88, 96};
    // int n2 = sizeof(arr2) / sizeof(arr2[0]); // size of array
    // int flag = binarySearch(arr2, 0, n2 - 1, searchkey);

    // // int flag = binarySearchItreation(arr2, 0, n2-1, searchkey);
    // if (flag == -1)
    // {
    //     printf("Not Found...\n");
    // }
    // else
    // {
    //     printf("Found at position %d......\n", flag + 1);
    // }



    // Index Sequential Search
    int arr2[] = {1, 3, 4, 6, 8, 9, 11, 44, 66, 88, 96,100};
    int n2 = sizeof(arr2) / sizeof(arr2[0]); // size of array
    indexSequentialSearch(arr2,n2-1,searchkey);
}