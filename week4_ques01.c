/*
Given an empty stack, design an algorithm and a program to reverse a string using this stack
(with and without recursion).
Input Format: 
The first line contains number of test cases, T.
For each test case, there will be  string of characters.
Output Format: 
The output will have T number of lines. For each test case, output will be new reversed string.
Sample:
Input:
3
qwerty
computerscience
graphicerauniversity

Output:
ytrewq
ecneicsretupmoc
ytisrevinuarecihparg
*/

#include<stdio.h>
#define max 50
char stack[max];
int top = -1;

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
int isFull()
{
    if (top == max - 1)
    {
        return 1;
    }
    return 0;
}
void push(char x)
{
    if (isFull())
    {
        printf("Stack is Full......");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack is Empty.......");
    }
    else
    {
        return stack[top--];
    }
}

char reverse(char *str){
    int i = 0;
    while (str[i]!='\0')
    {
        push(str[i]);
        i++;
    }
    printf("Reversed string : ");
    while (top!=-1)
    {
        printf("%c",pop());
    }
    return 0;
}

int main(){
    int test,i = 0 ;
    printf("Enter test case : ");
    scanf("%d",&test);
    while (i<test)
    {
        char str[50];
        printf("\nEnter string : ");
        scanf("%s",str);
        reverse(str);
        i++;
    }
    
}