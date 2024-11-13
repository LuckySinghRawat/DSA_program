/*
Given a matrix of size n X n, where every row and every column is sorted in increasing order.
Write an algorithm and a program to find whether the given key element is present in the matrix
or not. (Linear time complexity)
Input Format: 
First line contains n (the size of matrix).
For next n input lines, each line contains space-separated n integers describing each row of the
matrix.
Last line of input will contain key integer to be searched
Output Format: 
Output will be “Present” if the key element is found in the array, otherwise print “Not Present”. 
Sample Input:
4
10 20 30 40
15 25 34 41
27 29 35 45
32 33 38 49
33
Output: Present
*/

#include<stdio.h>
int main(){
    int num;
    printf("Enter nunmber : ");
    scanf("%d",&num);
    int arr[num][num];
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            scanf("%d",&arr[i][j]);
        }  
    }
    int key;
    printf("Enter key : ");
    scanf("%d",&key);
    int i = 0 ,j = num - 1,flag = -1;
    while (i<num && j>=0)
    {
        if (arr[i][j] == key)
        {
            flag = 1;
            break;
        }
        else if(arr[i][j]>key){
            j--;
        }
        else{
            i++;
        }
        
    }
    if (flag != -1)
    {
        printf("Present.....\n");
    }else{
        printf("Not Present.....\n");

    }
    
    
    

}