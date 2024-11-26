/*
Given a sorted doubly linked list, design an algorithm and write a program to eliminate
duplicates from this list.
*/
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

void deleteDupllicate(ln *start)
{
    ln *ptr1 = start;
    while (ptr1 != NULL)
    {
        ln *ptr2 = ptr1->next; 
        while (ptr2 != NULL)
        {
            if (ptr1->data == ptr2->data)
            {
                ln *duplicate = ptr2;
                ptr2 = ptr2->next; 
                if (duplicate->next != NULL)
                {
                    duplicate->next->prev = duplicate->prev; 
                }
                if (duplicate->prev != NULL)
                {
                    duplicate->prev->next = duplicate->next; 
                }
                free(duplicate); 
            }
            else
            {
                ptr2 = ptr2->next; 
            }
        }
        ptr1 = ptr1->next; 
    }
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
            printf("\nAfter Deleted Duplicate node : ");
            deleteDuplicate(head);
            display(head);
            exit(0);

        default:
            printf("Invalid Input");
            break;
        }
    }
}