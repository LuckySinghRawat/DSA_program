#include <stdio.h>
#include <stdlib.h>
typedef struct polyAddition
{
    int coffe;
    int pow;
    struct polyAddition *next;
} polyAdd;

polyAdd *enter(polyAdd *);
polyAdd *insert(polyAdd *, int, int);

polyAdd *poly_add(polyAdd *ptr1, polyAdd *ptr2) {
    polyAdd *head3, *ptr3, *tmp;
    head3 = NULL;

    if (ptr1 == NULL && ptr2 == NULL)
        return head3;

    while (ptr1 != NULL && ptr2 != NULL) {
        tmp = (polyAdd *)malloc(sizeof(polyAdd));
        tmp->next = NULL;  // Important to initialize this!

        if (head3 == NULL) {
            head3 = tmp;
            ptr3 = head3;
        } else {
            ptr3->next = tmp;
            ptr3 = ptr3->next;
        }

        if (ptr1->pow == ptr2->pow) {
            tmp->coffe = ptr1->coffe + ptr2->coffe;
            tmp->pow = ptr1->pow;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else if (ptr1->pow > ptr2->pow) {
            tmp->coffe = ptr1->coffe;
            tmp->pow = ptr1->pow;
            ptr1 = ptr1->next;
        } else {
            tmp->coffe = ptr2->coffe;
            tmp->pow = ptr2->pow;
            ptr2 = ptr2->next;
        }
    }

    // Append remaining nodes from ptr1 or ptr2
    while (ptr1 != NULL) {
        ptr3->next = ptr1;
        ptr3 = ptr3->next;
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL) {
        ptr3->next = ptr2;
        ptr3 = ptr3->next;
         ptr2 = ptr2->next;
    }

    ptr3->next = NULL;
    return head3;
}

//*enter se original jata hai

/*
|  Aspect             | PolyAdd enter(PolyAdd *)                    | PolyAdd *enter(PolyAdd *) |
|:--------------------|:--------------------------------------------|:--------------------------------|
| Return Type         | PolyAdd object                              | Pointer to PolyAdd object |
| Return Semantics    | Copy of object                              | Pointer to original object |
| Memory Allocation   | Stack allocation                            | Dynamic memory allocation |
| Object Modification | Modifications lost                          | Modifications affect original |
| Usage               | Return copy, no modification needed         | Return pointer, modification needed |

*/

void display(polyAdd *start)
{
    if (start == NULL)
        printf("NO ... variable inserted yet\n");
    else
    {
        while (start != NULL)
        {
            printf("%dx^%d ", start->coffe, start->pow);
            start = start->next;
            if (start != NULL)
            {
                printf(" + ");
            }
        }
        printf("\n");
    }
}
int main()
{
    polyAdd *head1, *head2, *head3;
    head1 = NULL;
    head2 = NULL;
    head3 = NULL;
    printf("Enter variable in polynomial 1 : ");
    head1 = enter(head1);
    display(head1);
    printf("Enter variable in polynomial 2 : ");
    head2 = enter(head2);
    display(head2);
    head3 = poly_add(head1,head2);
    printf("Sum of polynomial is : ");
    display(head3);

}

// JB DO YA DO SE JADA LINKLIST BANE TO : 

polyAdd *enter(polyAdd *start)
{
    int co, po, nv;

// TO GET NUMBER OF VARIABLE 
    scanf("%d",&nv);
    for (int i = 1; i <= nv; i++)
    {
        printf("Enter coffecient and power : ");
        scanf("%d %d", &co, &po);

// INSERT COFFECIENT AND POWER IN LINKLIST    
        start = insert(start, co, po);
    }
    return start;
    // ASSIGEN LINKLIST TO THEIR HEAD 
}

polyAdd *insert(polyAdd *start, int x, int y)
{
    polyAdd *temp, *ptr;
    temp = (polyAdd *)malloc(sizeof(polyAdd));
    temp->coffe = x;
    temp->pow = y;

    if (start == NULL || y > start->pow)
    //  AGR POWER JADA HO TOH WOH PEHLE AAJAYEGA ISSE 
    {
        temp->next = start;
        start = temp;

/*
+--------+    +--------+    +--------+
|  Node1 |-->|  Node2 |-->|  Node3 |
+--------+    +--------+    +--------+
^
|
Start


+--------+    +--------+    +--------+    +--------+
|  Temp  |-->|  Node1 |-->|  Node2 |-->|  Node3 |
+--------+    +--------+    +--------+    +--------+
^
|
Start

*/

    }
    // WRNA PICHE CHALA JAYEGA
    else
    {
        ptr = start;
        while (ptr->next != NULL )
        // && ptr->next->pow > y ??
        {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
    return start;
}
