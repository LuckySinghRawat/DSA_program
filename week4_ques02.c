/*
Design an algorithm and a program to implement two stacks by using only one array i.e. both the
stacks should use the same array for push and pop operation. Array should be divided in such a
manner that space should be efficiently used if one stack contains very large number of elements
and other one contains only few elements.
Input Format:
First line will take size of stack.
Second line will ask user whether it wants to push/pop in stack1 or stack2, then accordingly
perform operation.
Output Format:
Output will be the final contents of both stacks after performing all the operations.
Sample:
Input:
10
Press:
1 to push in stack 1
2 to pop from stack 1
3 to push in stack 2
4 to pop from stack 2
5 to exit
1
342
1
564
3
601
3
970
3
123
5
Output:
stack 1: 342 564
stack 2: 601 970 123
*/

#include <stdio.h>
#include <stdlib.h>

void push(int top, int *stack, int max)
{
    if (top == max - 1)
    {
        printf("Stack is Full......%d %d", top, max);
    }
    else
    {
        int x;
        scanf("%d", &x);
        stack[top] = x;
    }
}

int pop(int top, int *stack)
{
    if (top == -1)
    {
        printf("Stack is Empty.......");
    }
    else
    {
        top -= 2;
        return top;
    }
}

int main()
{
    int sz =0;
    printf("Enter size of stack : ");
    scanf("%d", &sz);
    int stack[sz];
    int top1 = -1, top2 = -1;
    printf(" 1 to push in stack 1\n 2 to pop from stack 1\n 3 to push in stack 2\n 4 to pop from stack 2\n 5 to exit\n");
    while (1)
    {
        char choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            top1 = (top1 >= 0 ? top1 + 2 : 0);
            push(top1, stack, sz);
            break;
        case 2:
            top1 = pop(top1, stack);
            break;
        case 3:
            top2 = (top2 > 0 ? top2 + 2 : 1);
            push(top2, stack, sz);
            break;
        case 4:
            top2 = pop(top2, stack);
            break;
        case 5:
            printf("Stack1 : ");
            for (int i = 0; i <= top1; i += 2)
            {
                printf("%d ", stack[i]);
            }
            printf("\nStack2 : ");
            for (int i = 1; i <= top2; i += 2)
            {
                printf("%d ", stack[i]);
            }
            exit(0);

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}