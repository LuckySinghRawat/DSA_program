#include <stdio.h>
#include <stdlib.h>

typedef struct doubly_linklist
{
    struct doubly_linklist *prev;
    int data;
    struct doubly_linklist *next;
} n;

n *create(n *start)
{
    n *temp, *ptr;
    temp = (n *)malloc(sizeof(n));
    printf("Enter your data : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
        temp->prev = start;
    }
    else
    {
        ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        temp->prev = ptr;
        ptr->next = temp;
    }
    temp->next = start;
    return start;
}

void display(n *start)
{
    if (start == NULL)
    {
        printf("Empty list .......!\n");
    }
    else
    {
        n *ptr = start;
        while (ptr->next != start)
        {
            printf("%d  ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d  ", ptr->data);
    }
}

int main()
{
    n *head = NULL;
    int ch;
    while (1)
    {
        printf("\n1->Previous : 2->Create : 3->Next : 4->Display : 0->Exit\n");
        printf("Enter your choise : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            exit(0);
            break;
        
        case 2:
            head = create(head);
            n *ptr = head;
            break;

        case 1:
            ptr = ptr->prev;
            printf("%d", ptr->data);
            break;
        case 3:
            printf("%d", ptr->data);
            ptr = ptr->next;
            break;
        case 4:
            display(head);
            break;

        default:
            printf("Enter valid choise");
            break;
        }
    }
}