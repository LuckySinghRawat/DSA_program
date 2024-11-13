/*
Given a boolean matrix (contains only 0 and 1) of size m X n where each row is sorted, write an
algorithm and a program to find which row  has  maximum number of 1's. (Linear time
complexity)
Input Format: 
First line contains m and n (the size of matrix).
For next m input lines, each line contains space-separated n integers describing each row of the
matrix.
Output Format: 
Output will be row number which has maximum number of 1's. If all the elements of matrix is 0
then print “Not Present”. 

Sample Input:
4 3
0 1 1 
0 0 1 
1 1 1
0 0 0

Output:
row - 3
*/

#include<stdio.h>
int main(){
    int num1,num2;
    printf("Enter nunmber : ");
    scanf("%d %d",&num1,&num2);
    int arr[num1][num2];
    for (int i = 0; i < num1; i++)
    {
        for (int j = 0; j < num2; j++)
        {
            scanf("%d",&arr[i][j]);
        }  
    }
    int i = 0,j = num2-1,key,count;
    printf("Enter key : ");
    scanf("%d",&key);
    while (i<num1 && j>=0)
    {
        if (arr[i][j] == 0)
        {
            i++;
        }
        else{
            j--;
            count = i;
        }
        
    }
    if (count > 0)
    {
        printf("row - %d.....\n",++count);
    }else{
        printf("Not Present.....\n");

    }
    
}