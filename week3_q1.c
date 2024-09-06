#include <stdio.h>
#include <stdlib.h>
#define cap 10
typedef struct stack
{
    int top;
    int array[cap];
} stk;
void create(stk *stack)
{
    stack->top = -1;
}

int isEmpty(stk *stack)
{
    return stack->top == -1;
}
void push(stk *stack, int k)
{
    if (stack->top == cap - 1)
    {
        printf("Stack over flow");
        return;
    }
    stack->array[++stack->top] = k;
    printf("Pushed element is %d \n", k);
}

int pop(stk *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow!..cant push");
        return -1;
    }
    return stack->array[stack->top--];
}

int size(stk *stack)
{
    return stack->top + 1;
}

void Print(stk *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty");
        return;
    }
    printf("Stack's Elemets are :");
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d  ", stack->array[i]);
    }
    printf("\n");
}

int main()
{
    stk stack;
    create(&stack);
    int value, choice;
    while (1)
    {
        printf("Choose the number for operation\npush--> 1 || pop--> 2 || size--> 3 || print--> 4 || exit--> 5\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number to push:  ");
            scanf("%d", &value);
            push(&stack, value);
            break;
        case 2:
            value = pop(&stack);
            if (value != -1)
            {
                printf("Poped value is %d\n", value);
            }

            break;
        case 3:
            printf("Current size of stack: %d\n", size(&stack));
            break;
        case 4:
            Print(&stack);
            break;
        case 5:
            exit(0);

        default:
            printf("Invalid choice !!! try again\n");
            break;
        }
    }
}
