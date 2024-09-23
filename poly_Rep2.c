#include <stdio.h>
#include <stdlib.h>

typedef struct polyRepresentation
{
    int coffe;
    int pow;
    struct polyRepresentation *next;
} polyRep;

polyRep *insert(polyRep *start, int x, int y)
{
    polyRep *temp, *ptr;
    temp = (polyRep *)malloc(sizeof(polyRep));
    temp->next = NULL;
    temp->coffe = x;
    temp->pow = y;
    if (start == NULL || y > start->pow)
    {
        temp->next = start;
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL && ptr->next->pow > y)
        {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
    return start;
}

polyRep *add(polyRep *ptr1, polyRep *ptr2)
{
    polyRep *ptr3 = NULL, *temp = NULL;
    polyRep *head3 = NULL;
    if (ptr1 == NULL && ptr2 == NULL)
        return head3;
    else
    {
        while (ptr1 != NULL && ptr2 != NULL)
        {
            //     we are allocating memory multiple times
            temp = (polyRep *)malloc(sizeof(polyRep));
            temp->next = NULL;
            if (head3 == NULL)
            {
                head3 = temp;
                ptr3 = head3;
            }
            else
            {
                ptr3->next = temp;
                ptr3 = ptr3->next;
            }

            if (ptr1->pow == ptr2->pow)
            {
                temp->coffe = ptr1->coffe + ptr2->coffe;
                temp->pow = ptr1->pow;
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            else if (ptr1->pow > ptr2->pow)
            {
                temp->coffe = ptr1->coffe;
                temp->pow = ptr1->pow;
                ptr1 = ptr1->next;
            }
            else
            {
                temp->pow = ptr2->pow;
                temp->coffe = ptr2->coffe;
                ptr2 = ptr2->next;
            }
        }
       
        while (ptr1 != NULL)
        {
            ptr3->next = ptr1;
            ptr3 = ptr3->next;
            ptr1 = ptr1->next;
        }
        while (ptr2 != NULL)
        {
            ptr3->next = ptr2;
            ptr3 = ptr3->next;
            ptr2 = ptr2->next;
        }

        ptr3->next = NULL;
        return head3;
    }
}

void display(polyRep *ptr)
{
    if (ptr == NULL)
    {
        printf("Empty node....");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%dx^%d", ptr->coffe, ptr->pow);
            ptr = ptr->next;
            if (ptr != NULL)
            {
                printf(" + ");
            }
        }
        printf("\n");
    }
}

int main()
{
    polyRep *head1, *head2, *head3;
    head1 = NULL;
    head2 = NULL;
    head3 = NULL;
    int nv, co = 0, po = 0;
    printf("Enter no of variable in polynomial 1 : ");
    scanf("%d", &nv);
    for (int i = 1; i <= nv; i++)
    {
        printf("Enter coffeciennt and power for %d variable : ", i);
        scanf("%d %d", &co, &po);
        head1 = insert(head1, co, po);
    }
    printf("Enter no of variable in polynomial 2 : ");
    scanf("%d", &nv);
    for (int i = 1; i <= nv; i++)
    {
        printf("Enter coffeciennt and power for %d variable : ", i);
        scanf("%d %d", &co, &po);
        head2 = insert(head2, co, po);
    }
    printf("Our polynomials are :\n");
    display(head1);
    display(head2);
    head3 = add(head1, head2);
    printf("After adding polynomials  :\n");
    display(head3);
}

/* ------------------------------------------------------------------------------
INCORRECT CODE 
while (ptr1 != NULL)
        {
            temp->coffe = ptr1->coffe;
            temp->pow = ptr1->pow;
            ptr1 = ptr1->next;
        }
        while (ptr2 != NULL)
        {
            temp->coffe = ptr2->coffe;
            temp->pow = ptr2->pow;
            ptr2 = ptr2->next;
        }

In both while loops, you're overwriting the contents of temp with the values from the current nodes in ptr1 and ptr2. This means that only the last node from each list will be stored in temp, and all previous nodes will be lost.*/

/*
CORRECT CODE WILL BE LIKE :-  

 while (ptr1 != NULL)
        {
            temp = (polyRep *)malloc(sizeof(polyRep));
            temp->next = NULL;
            temp->coffe = ptr1->coffe;
            temp->pow = ptr1->pow;
            if (head3 == NULL)
            {
                head3 = temp;
            }
            else
            {
                ptr3->next = temp;
            }
            ptr3 = temp;
            ptr1 = ptr1->next;
        }
        while (ptr2 != NULL)
        {
            temp->next = NULL;
            temp = (polyRep *)malloc(sizeof(polyRep));
            temp->coffe = ptr2->coffe;
            temp->pow = ptr2->pow;
            if (head3 == NULL)
            {
                head3 = temp;
            }
            else
            {
                ptr3->next = temp;
            }
            ptr3 = temp;
            ptr2 = ptr2->next;
        }
*/