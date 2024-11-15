/*
Given a string of opening and closing paranthesis, design an algorithm and a program to find the
length of the longest valid paranthesis substring. Valid paranthesis substring is a string which
contains balanced paranthesis.
Input Format: 
The first line contains number of test cases, T.
For each test case, there will be  string of paranthesis.
Output Format: 
The output will have T number of lines. For each test case, output will be length of longest valid
paranthesis substring
*/


#include <stdio.h>
#define max 50
char stack[50];
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
void push(char a)
{
    if (isFull())
    {
        printf("Stack is Full......");
    }
    else
    {
        top++;
        stack[top] = a;
        printf("%c pushed....\n", a);
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
        printf("Poped element %c\n", stack[top]);
        return stack[top--];
    }
}

int logic(char *parenthese){
    int i = 0,count = 0;
    while (parenthese[i] != '\0')
    {
        if (parenthese[i] == '(' || parenthese[i] == '{' || parenthese[i] == '[')
        {
            push(parenthese[i]);
        }
        else
        {
            if (isEmpty() || parenthese[i] == ')' && stack[top] != '(' || parenthese[i] == '}' && stack[top] != '{' || parenthese[i] == ']' && stack[top] != '[')
            {
                return count;
            }
            else
            {
                pop();
                count += 2;
            }
        }
        i++;
    }
    return count;

}

int main()
{
    int test;
    printf("Enter number of test cases : ");
    scanf("%d",&test);
    int i = 0;
    while (i<test)
    {
    char parenthese[max];
    printf("\nEnter parenthese : ");
    scanf("%s",parenthese);
    int count = logic(parenthese);
    printf("%d \n",count);
    i++;
    }
    
}