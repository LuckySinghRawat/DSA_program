#include <stdio.h>
#include <stdlib.h>

#define ele 10
int top = -1;

// TO CHECK IS EMPTY OR NOT
int isEmpty(int a[])
{
    if (top == -1)
    {
        return 1;
    }return 0;
    //  ALTRENATOR  return a[top]==-1;
}

// TO PUSH ELEMENT IN STACK
void push(int a[], int x)
{
    if (top == ele - 1)
    {
        printf("Stack is overFlow,you can't push\n");
        return;
    }
    a[++top] = x;
    printf("Pushed element is : %d\n", x);
}

// TO POP ELEMENT IS STACK
int pop(int a[])
{
    if (isEmpty(a))
    {
        printf("Stack is underFlow,You can't pop\n");
        return 0;
    }
    return a[top--];
}

// TO CHECK SIZE
int size()
{
    // YAHA HAMARA TOP PEHLE SE ++ HORA HAI TOH TOP HI SIZE HOGA
    return top + 1;
}

// TO DISPLAY STACK
void display(int s[])
{
    if (isEmpty(s))
    {
        printf("Stack empty\n");
        return;
    }
    printf("Stack Elements are : ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d  ", s[i]);
    }
    printf("\n");
}

int main()
{
    int stack[ele];
    printf("Enter 1 -> push | ");
    printf("Enter 2 -> pop | ");
    printf("Enter 3 -> size | ");
    printf("Enter 4 -> display | ");
    printf("Enter 5 -> exit \n ");

    int choice, value;
    while (1)
    {
        printf("Enter choise : \n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter any value to push :");
            scanf("%d",&value);
            push(stack, value);
            break;

        case 2:
            pop(stack);
            break;

        case 3:
            printf("Size of stack is : %d \n", size(stack));
            break;

        case 4:
            display(stack);
            break;
        case 5:
            exit(0);

        default:
            printf("Enter valid operator!...\n");
            break;
        }
    }
}