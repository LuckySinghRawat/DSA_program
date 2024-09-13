// THIS CODE IS OF STRUCTURED STACK

#include <stdio.h>
#include <stdlib.h>
#define CAP 10

typedef struct stack
{
    int top;
    int arr[CAP];
} stk;

void create(stk *s)
{
    s->top = -1;
}

int isEmpty(stk *s)
{
    return s->top == -1;
}

void push(stk *s, int k)
{
    s->arr[++s->top] = k;
}
void pop(stk *s)
{
    if (isEmpty(s))
    {
        printf("Stack is underFlow can't pop...\n");
        return;
    }
    printf("Poped Element is %d\n", s->arr[s->top--]);
}
void size(stk *s)
{
    printf("Size of stack is %d\n", s->top + 1);
}

void display(stk *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return;
    }
    int i = 0;
    printf("Elements in stack are : ");
    while (i != s->top + 1)
    {
        printf("%d\t", s->arr[i++]);
    }
    printf("\n");
}

int main()
{
    stk stack;
    create(&stack);
    while (1)
    {
        int choice, value;
        printf("Enter 1->push : 2->pop : 3->size : 4->display : 5->Exit\n\t:: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (stack.top == CAP - 1)
            {
                printf("Stack overFlow can't push ....\n");
                break;
            }
            printf("Enter value to push in stack :: ");
            scanf("%d", &value);
            push(&stack, value);
            break;
        case 2:
            pop(&stack);
            break;

        case 3:
            size(&stack);
            break;
        case 4:
            display(&stack);
            break;
        case 5:
            exit(0);
        default:
            printf("Enter valid choice...\n");
            break;
        }
    }
}
