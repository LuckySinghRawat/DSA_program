/*
Write an algorithm and a program to implement stack using linked list. he program should
implement following queue operations:
a) Create()
b) Push()
c) Pop()
d) IsEmpty()
e) Size()
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} stk;

stk *push(stk *ptr)
{
    stk *temp;
    temp = (stk *)malloc(sizeof(stk));
    printf("Enter data : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (ptr == NULL)
    {
        ptr = temp;
    }
    else
    {
        temp->next = ptr;
        ptr = temp;
    }
    return ptr;
}

stk *pop(stk *ptr)
{
    if (ptr == NULL)
    {
        printf("empty stack...\n");
    }
    else
    {
        printf("Poped element is :%d \n", ptr->data);
        stk *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    return ptr;
}

void size(stk *ptr)
{
    if (ptr == NULL)
    {
        printf("Empty Linked List");
        return;
    }
    int count = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    printf("Size = %d", count);
}

void display(stk *ptr)
{
    if (ptr == NULL)
    {
        printf("Empty Linked List...");
        return;
    }
    while (ptr->next != NULL)
    {
        printf("| %d |-->", ptr->data);
        ptr = ptr->next;
    }
    printf("| %d |-->null", ptr->data);
}

void isEmpty(stk *ptr)
{
    if (ptr == NULL)
    {
        printf("Empty...");
        return;
    }
    printf("NOT Empty...");
}

int main()
{
    stk *top = NULL;
    int choice;
    while (1)
    {
        printf("\nEnter 1->push 2->pop 3->Size 4->isEmpty 0->exit : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:

            top = push(top);
            display(top);
            break;
        case 2:
            top = pop(top);
            display(top);
            break;
        case 3:
            size(top);
            break;
        case 4:
            isEmpty(top);
            break;
        default:
            printf("Enter valid choice \n");
            break;
        }
    }
}