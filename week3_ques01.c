/*
Design an algorithm and a program to implement stack using array. The program should
implement following stack operations:
a) Create() - create an empty stack
b) Push(k) - push an element k into the stack
c) Pop() - pop an element from the stack snd return it
d) IsEmpty() - check if stack is empty or not
e) Size() - finds the size of the stack
f) Print() - prints the contents of stack
*/
#include <stdio.h>
#include <stdlib.h>
#define max 5
int stack[max];
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
void push()
{
    if (isFull())
    {
        printf("Stack is Full......");
    }
    else
    {
        int num;
        printf("Enter the number to push : ");
        scanf("%d", &num);
        top++;
        stack[top] = num;
        printf("%d pushed....", num);
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
        printf("Poped element %d", stack[top]);
        return stack[top--];
    }
}

void print()
{
    if (isEmpty())
    {
        printf("Stack is Empty....");
    }
    else
    {
        int i = 0;
        while (i <= top)
        {
            printf("%d\t", stack[i++]);
        }
    }
}

int main()
{
    while (1)
    {
        int choice;
        printf("\n Stack Operation \n 0->exit 1->push 2->pop 3->isEmpty 4->size 5->print : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            if (isEmpty())
            {
                printf("Stack is Empty......");
            }
            else
            {
                printf("NO not empty...");
            }
            break;
        case 4:
            printf("Size  = %d",(top>0?top+1:0));
            break;
        case 5:
            print();
            break;

        default:
            printf("Enter valid number......");
            break;
        }
    }
}