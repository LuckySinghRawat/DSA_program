/*
Given an eval1pression in the form of postfival1 representation, design an algorithm and a program to
find result of this eval1pression.
Input Format: The first line contains number of test cases, T.
For each test case, there will be eval1pression string.
Output Format: The output will have T number of lines. For each test case, output will be the
result of the evaluated eval1pression.
Sample:
Input:
3
2 3 1 * + 4 -
40 8 / 5 * 10 2 / -
40 8 / 5 2 * -
Output:
1
20
-5
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maval1 50
int stack[maval1];
int top = -1;

int isEmptval2()
{
    return top == -1;
}
int isFull()
{
    return top == maval1 - 1;
}
void push(int val1)
{
    if (isFull())
    {
        printf("Stack is Full......");
    }
    else
    {
        stack[++top] = val1;
        printf("Pushed element = %d\n", val1);
    }
}

int pop()
{
    if (isEmptval2())
    {
        printf("Stack is Emptval2.......");
    }
    else
    {
        int val1 = stack[top];
        printf("Poped element = %d\n", val1);
        return stack[top--];
    }
}

int operate(int val1, int val2, char z)
{
    switch (z)
    {
    case '+':
        return val1 + val2;
    case '-':
        return val1 - val2;
    case '/':
        return val2 != 0 ? val1 / val2 : 0;
    case '*':
        return val1 * val2;
    }
}

int evaluate(char *str)
{
    char *token = strtok(str," ");;
    int i = 0;
    int val1 = 0, val2 = 0, z = 0;
    while (token != NULL)
    {
    
            if (token[0] == '/' || token[0] == '*' || token[0] == '-' || token[0] == '+')
            {
                val1 = pop();
                val2 = pop();
                z = operate(val2, val1,token[0]);
                push(z);
            }
            else
            {
                push(atoi(token));
            }
        
            i++;
            token = strtok(NULL, " ");
    }
    return pop();
}

int main()
{
    int test, i = 0, ans;
    printf("Enter test case : ");
    scanf("%d", &test);
    getchar();
    while (i < test)
    {
        char str[50];
        printf("\nEnter string : ");
        gets(str);
        ans = evaluate(str);
        printf("Answer : %d", ans);
        i++;
    }
}