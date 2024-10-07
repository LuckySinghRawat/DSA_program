#include <stdio.h>
#include <stdlib.h>
 typedef struct node
{
    int data;
    struct node *next;
}n;



n *create(n *start)
{
    n *temp,*ptr;
    temp = (n *)malloc(sizeof(n));
    printf("Enter data:");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    temp->next = start;
    return start;
}


void display(n *);

int main()
{
    n *head = NULL;
    int ch;
    n *ptr;
    while (1)
    {
        printf("\nPress 1:Create 2:Display 3:Next 0:Exit \n ");
        printf("enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = create(head);
            ptr = head;
            break;
        case 2:
            display(head);
            break;
        case 3:
            printf("%d", ptr->data);
            ptr = ptr->next;
            break;

        case 0:
            exit(0);
        default:
            printf("Wrong choice....use only above option ");
        }
    }
    return 0;
}



void display(n *start)
{
    if (start == NULL)
        printf("No Node in this circular Linked List...");
    else
    {
        n *ptr = start;

        printf("\ncircular Linked List is :\n");

        while (ptr->next != start)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d ", ptr->data);
    }
}
