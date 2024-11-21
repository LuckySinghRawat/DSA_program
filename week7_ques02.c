/*
Write an algorithm and a program to implement queue using linked list. The program should
implement following stack operations:
a) Create()
b) EnQueue()
c) DeQueue()
d) IsEmpty()
e) Size()
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} ln;

void createNode(ln **ptr1, ln **ptr2)
{
    *ptr1 = *ptr2 = NULL;
}

void EnQueue(ln **ptr, ln **ptr1)
{
    ln *temp = (ln *)malloc(sizeof(ln));
    printf("Enter data : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (*ptr1 == NULL)
    {
        *ptr = *ptr1 = temp;
    }
    else
    {
        ln *rear = *ptr1;
        rear->next = temp;
        *ptr1 = temp;
    }
    return;
}

ln *DeQueue(ln *ptr)
{
    if (ptr != NULL)
    {
        ptr = ptr->next;
        return ptr;
    }
}

void isEmpty(ln *ptr)
{
    if (ptr == NULL)
    {
        printf("Empty...");
        return;
    }
    printf("NOT Empty...");
}

void display(ln *ptr)
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

void size(ln *ptr)
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

int main()
{
    while (1)
    {
        ln *front, *rear;
        int choice;
        printf("\n1->Create 2->Enqueue 3->Dequeue 4->IsEmpty 5->Size 0->Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            createNode(&front, &rear);
            printf("Queue is created");
            break;
        case 2:
            EnQueue(&front, &rear);
            display(front);
            break;
        case 3:
            if (front != NULL)
            {
                front = DeQueue(front);
            }
            else
            {
                createNode(&front, &rear);
            }
            display(front);
            break;
        case 4:
            isEmpty(front);
            break;
        case 5:
            size(front);
            break;

        default:
            printf("Invalid Input");
            break;
        }
    }
}