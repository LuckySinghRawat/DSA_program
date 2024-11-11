/*
Given an unsorted array of integers and two numbers a and b. Design an algorithm and write a
program to find minimum distance between a and b in this array. Minimum distance between any
two numbers a and b present in array is the minimum difference between their indices.
Input format:
The first line contains number of test cases, T.
For each test case, there will be three input lines.
First line contains n (the size of array).
Second line contains n space-separated integers describing array.
Third line will take two numbers a and b.
Output format:
The output will have T number of lines.
For each test case, output will be the minimum distance between a and b.

Sample Input:
3
5
2 4 -3 2 3
4 2
10
1 6 3 2 9 1 4 3 6 2
3 2
15
-2 8 7 1 2 6 8 9 0 2 -6 12 9 7 1
7 2

Output:
1
1
2
*/

#include <stdio.h>
int main()
{
    int arr[100], test_case, j = 0;
    printf("Enter test cases : ");
    scanf("%d", &test_case);
    while (j < test_case)
    {
        int num, num1, num2, sum, c1 =0, c2=0;
        printf("\nEnter Number of Element : ");
        scanf("%d", &num);
        for (int i = 0; i < num; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("Enter two  number  : ");
        scanf("%d %d", &num1, &num2);
        for (int i = 0; i < num; i++)
        {
            if (arr[i] == num1)
            {
                if (c1 == 0)
                {
                    num1 = i;
                    c1++;
                }
            }
            if (arr[i] == num2)
            {
                if (c2 == 0)
                {
                    num2 = i;
                    c2++;
                }
            }
        }
        sum = num1-num2;
        sum = (sum>0?sum:-sum);
        printf("\n%d",sum);
        j++;
    }
}
