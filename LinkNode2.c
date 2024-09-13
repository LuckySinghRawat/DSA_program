// PROGRAM TO CREATE LINKLIST AND ITS MORE FUNCTIONS USING [typedef str]

#include <stdio.h>
#include <stdlib.h>
typedef struct linkNode
{
    int data;
    struct linkNode *next;
} lnk;

void display(lnk *s)
{
    lnk *temp;
    temp = s->next;
    while (temp != NULL)
    {
        printf("%d    ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtBeg(lnk *s, int x)
{
    lnk *temp;
    temp = (lnk *)malloc(sizeof(lnk));
    temp->data = x;
    temp->next = s->next;
    s->next = temp;
}

void insertAtEnd(lnk *s, int x)
{
    lnk *temp1, *temp2;
    temp1 = (lnk *)malloc(sizeof(lnk));
    temp2 = s->next;
    while ((temp1->next) != NULL)
        temp2 = temp2->next;
    temp1->data = x;
    temp1->next = NULL;
    temp2->next = temp1;
}

void insertAfter(lnk *s, int y, int x)
{
    lnk *temp1, *temp2;
    temp1 = (lnk *)malloc(sizeof(lnk));
    temp2 = s->next;
    while ((temp2->data) != x)
        temp2 = temp2->next;
    temp1->data = y;
    temp1->next = temp2->next;
    temp2->next = temp1;
}

int main()
{
    lnk *nn;
    nn = (lnk *)malloc(sizeof(lnk));
    int choice, value, after;
    while(1)
    {
        printf("Enter 1->insertingAtBegining : 2->insertingAtEnd : 3->insertAfter : 4->display : 5->exit\n\t:: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert at begining : ");
            scanf("%d", &value);
            insertAtBeg(nn, value);
            break;

        case 2:
            printf("Enter value to insert at end : ");
            scanf("%d", &value);
            insertAtEnd(nn, value);
            break;

        case 3:
            printf("Enter value to insert after : ");
            scanf("%d", &value);
            printf("Enter value for which insert after : ");
            scanf("%d", &after);
            insertAfter(nn, value, after);
            break;
            
        case 4:
            display(nn);
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("!!!...Enter valid choice...!!!");
            break;
        }
    }
}
