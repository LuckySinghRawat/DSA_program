#include <stdio.h>
#include <stdlib.h>
typedef struct PolynomialRepresentation
{
    int pow;
    int coffe;
    struct PolynomialRepresentation *next;
} polyRep;
polyRep *head = NULL;

void create(polyRep *ptr)
{
    polyRep *temp;
    temp = (polyRep *)malloc(sizeof(polyRep));
    printf("Enter coffecient and power of variable : \n");
    scanf("%d%d", &temp->coffe, &temp->pow);
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void display(polyRep *ptr)
{
    if (ptr == NULL)
        printf("NO ... variable inserted yet\n");
    else
    {
        while (ptr->next != NULL)
        {
            printf("%dx^%d + ", ptr->coffe, ptr->pow);
            ptr = ptr->next;
        }
        printf("%dx^%d\n", ptr->coffe, ptr->pow);
    }
}

// void display(polyRep *ptr)
// {
//     if (ptr == NULL)
//         printf("NO ... variable inserted yet\n");
//     else
//     {
//         while (ptr != NULL)
//         {
//             printf("%dx^%d ", ptr->coffe, ptr->pow);
//             ptr = ptr->next;
//         if (ptr!=NULL)
//         {
//             printf(" + ");
//         }
//         }
//         printf("\n");
        
//     }
// }

int main()
{
    int ch;
    while (1)
    {
        printf("Enter 1->Create || 2->Display || 0->Exit : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create(head);
            break;
        case 2:
            display(head);
            break;
        case 0:
            exit(0);
        default:
            printf("Enter valid choice\n");
            break;
        }
    }
}