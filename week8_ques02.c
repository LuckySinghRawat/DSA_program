/*
Given a doubly linked list, design an algorithm and write a program to reverse this list without
using any extra space.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} ln;

ln *insertAtFront(ln *ptr)
{
    ln *temp = (ln *)malloc(sizeof(ln));
    ln *start = ptr;
    printf("Enter data : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if (ptr == NULL)
    {
        ptr = temp;
    }
    else
    {
        temp->next = ptr;
        ptr->prev = temp;
        ptr = temp;
    }
    return ptr;
}

void display(ln *start)
{
    ln *ptr = start;
    if (ptr == NULL)
    {
        printf("Empty Linked List...");
        return;
    }
    while (ptr->next != NULL)
    {
        printf("| %d |<==>", ptr->data);
        ptr = ptr->next;
    }
    printf("| %d |-->null", ptr->data);
}

ln *reverse(ln *start)
{
    ln *ptr1 = start,*ptr2 = start->next;
    ptr1->next = NULL;
    ptr1->prev = ptr2;
    while (ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr1->prev;
    }
    return ptr1;
}


int main()
{
    ln *head = NULL;
    while (1)
    {
        int choice;
        printf("1-> Insert at front 2-> Exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = insertAtFront(head);
            break;
        case 2:
            printf("Linked List is : ");
            display(head);
            printf("\nReversed Linked List is : ");
            head = reverse(head);
            display(head);
            exit(0);

        default:
            printf("Invalid Input");
            break;
        }
    }
}