/*
Given an array of nonnegative integers, where all numbers occur even number of times except
one number which occurs odd number of times. Write an algorithm and a program to find this
number. (Time complexity = O(n))
Input format: 
The first line contains number of test cases, T.
For each test case, there will be two input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.
Output format: 
The output will have T number of lines. 
For each test case, output will be the element which occured odd number of times. If no such
element is present in the array, then print “No such element present”. 

Sample Input:
3
5
2 4 3 2 3
11
1 6 3 2 4 1 4 2 3 6 6
15
2 8 7 1 2 6 8 9 0 2 6 2 9 7 1

Output:
4
6
0
*/

#include<stdio.h>
int main()
{
    int arr[100], test_case, j = 0;
    printf("Enter test cases : ");
    scanf("%d", &test_case);
    while (j < test_case)
    {
        int num, c1 =0,flag =0;
        printf("\nEnter Number of Element : ");
        scanf("%d", &num);
        for (int i = 0; i < num; i++)
        {
            scanf("%d", &arr[i]);
        }
        // TIME COMPLEXITY O(N)
        int result = 0;
        for (int i = 0; i < num; i++)
        {
            result ^= arr[i];
        }
        if (result == 0)
        {
            printf("NO such number");
        }else{
            printf("%d",result);
        }
        

        // TIME COMPLEXITY O(N^2)
        /*
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num; j++)
            {
                if (arr[i]==arr[j])
                {
                    c1++;   
                }
                
            }
            if (c1%2!=0)
            {
                printf("%d",arr[i]);
                flag = 1;
                break;
            }else{
                flag=-1;
            }    
        }
        if (flag == -1)
            {
                printf("NO such number exist.....");
            }*/

        j++;
    }
}