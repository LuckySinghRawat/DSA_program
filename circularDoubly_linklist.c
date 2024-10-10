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
    n *temp, *ptr, *ptr1;
    temp = (n *)malloc(sizeof(n));
    printf("Enter your data : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        ptr->prev = temp;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        temp->prev = ptr;
        ptr->next = temp;
    }
    // ptr1->prev = temp;
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
    int ch, x, y;
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

        case 3:
            if (ptr->data == y)
            {
                ptr = ptr->next->next;
                printf("%d", ptr->data);
                ptr = ptr->next;
                x = ptr->data;
                y = 0;
            }
            else
            {
                printf("%d", ptr->data);
                ptr = ptr->next;
                x = ptr->data;
                y = 0;
            }
            break;

        case 1:
            if (ptr->data == x)
            {
                ptr = ptr->prev->prev;
                printf("%d", ptr->data);
                ptr = ptr->prev;
                y = ptr->data;
                x = 0;
            }
            else
            {
                printf("%d", ptr->data);
                ptr = ptr->prev;
                y = ptr->data;
                x = 0;
            }
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