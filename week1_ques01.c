/*
Given an array of integers, write an algorithm and a program to left rotate the array by specific
number of elements.
Input format: 
The first line contains number of test cases, T.
For each test case, there will be three input lines.
First line contains n (the size of array).
Second line contains n space-separated integers describing array.
Third line will take number (k<=n) of times elements of array is rotated.
Output format: 
The output will have T number of lines. 
For each test case, output will be the new rotated array.

Sample Input:
3
5
2 4 -3 2 3
3
10
1 6 3 2 9 1 4 2 3 6 
4
15
-2 8 7 1 2 6 8 9 0 2 -6 2 9 7 1
6

Output:
2 3 2 4 -3
9 1 4 2 3 6 1 6 3 2
8 9 0 2 -6 2 9 7 1 -2 8 7 1 2 
*/

#include<stdio.h>
int main(){
    int arr[100],test_case,j = 0 ;
    printf("Enter test cases : ");
    scanf("%d",&test_case);
    while (j<test_case)
    {
        int num,rotate;
        printf("\nEnter Number of Element : ");
        scanf("%d",&num);
        for (int i = 0; i < num; i++)
        {
            scanf("%d",&arr[i]);
        }
        printf("Enter index number to rotate : ");
        scanf("%d",&rotate);
        for (int i = rotate; i < num; i++)
        {
            printf("%d  ",arr[i]);
        }
        for (int i = 0; i < rotate; i++)
        {
            printf("%d  ",arr[i]);
        }
        j++;
    }
    

}