/*
Given a matrix of size n X n containing positive integers, write an algorithm and a program to
rotate the elements of matrix in clockwise direction.
Input Format:
First line contains n (the size of matrix).
For next n input lines, each line contains space-separated n integers describing each row of the
matrix.
Output Format:
Output will be rotated matrix.

Sample Input:
4
11 12 13 14
15 16 17 18
19 20 21 22
23 24 25 26

Output:
15 11 12 13
19 20 16 14
23 21 17 18
24 25 26 22
*/

#include <stdio.h>
int main()
{
    int n1 = 5;
    int arr[5][5] = {1, 2, 3, 4, 5 ,
                    6, 7, 8, 9, 10 ,
                    11, 12, 13, 14, 15,
                    16, 17, 18, 19, 20,
                    21, 22, 23, 24, 25};

    int row = 0, col = 0, last_row = n1-1, last_col = n1-1;
    int prev, curr;
    while (row < last_row && col < last_col)
    {
        prev = arr[row + 1][col];
        for (int i = col; i <= last_col; i++)
        {
            curr = arr[row][i];
            arr[row][i] = prev;
            prev = curr;
        }
        row++;
        for (int i = row; i <= last_row; i++)
        {
            curr = arr[i][last_col ];
            arr[i][last_col ] = prev;
            prev = curr;
        }
        last_col--;

        for (int i = last_col ; i >= col; i--)
        {
            curr = arr[last_row ][i];
            arr[last_row ][i] = prev;
            prev = curr;
        }
        last_row-- ;

        for (int i = last_row ; i >= row; i--)
        {
            curr = arr[i][col];
            arr[i][col] = prev;
            prev = curr;
        }
        col++;

        
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}