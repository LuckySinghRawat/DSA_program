#include <stdio.h>
#include <stdlib.h>
#define max 5
int stack[max];
int top = -1;

void push()
{
    if (top == max - 1)
    {
        printf("Stack is Full......\n");
    }
    else
    {
        printf("Enter Number to push : ");
        int num;
        scanf("%d", &num);
        top++;
        stack[top] = num;
    }
}
int pop()
{
    if (top == -1)
    {
        printf("Stack empty.......\n");
    }
    else
    {
        printf("Poped element is : %d\n", stack[top]);
        // top--;
    }
    return stack[top--];
}

void display()
{
    int i=0;
    while (i <= max-1)
    {
        printf("%d  ", stack[i]);
        i++;
    }
    printf("\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("Enter 1->push 2->pop 3->display 0->exit : ");
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
            display();
            break;
        default:
            printf("Enter valid choice \n");
            break;
        }
    }
}