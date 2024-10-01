#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} n;

n *insert(n *start, int x)
{
    n *temp, *ptr;
    temp = (n *)malloc(sizeof(n));
    temp->data = x;
    if (start == NULL)
    {
        temp->next = start;
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
    return start;
}

void display(n *ptr)
{
    if (ptr == NULL)
    {
        printf("Empty node....");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

n *merge(n *node1, n *node2, n *node3){
    if(node1 == NULL)
        return node2;
    if(node2 == NULL)
        return node1;
    
    node3 = node1;
    n *ptr = node3;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = node2;
    return node3;
}

/*
n *merge(n *node1, n *node2, n *node3){
    node3 = NULL;
    if(node1 == NULL)
        return node2;
    if(node2 == NULL)
        return node1;
    
    if(node1->data < node2->data){
        node3 = node1;
        node3->next = merge(node1->next, node2, node3);
    } else {
        node3 = node2;
        node3->next = merge(node1, node2->next, node3);
    }
    return node3;
}
*/


n *sort(n *ptr)
{
    int swapped;
    n *ptr1;
    n *lptr = NULL;

    if (ptr == NULL)
        return ptr;

    do
    {
        swapped = 0;
        ptr1 = ptr;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);

    return ptr;
}


int main()
{
    n *head1, *head2 , *head3;
    head1 = NULL;
    head2 = NULL;
    head3 = NULL;
    int num = 0, info = 0;

    printf("Enter Number of inputs for HEAD1 : ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("Enter the value to be inserted : ");
        scanf("%d", &info);
        head1 = insert(head1, info);
    }

    printf("Enter Number of inputs for HEAD2 : ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("Enter the value to be inserted : ");
        scanf("%d", &info);
        head2 = insert(head2, info);
    }
    display(head1);
    display(head2);
    head3 = merge(head1,head2 ,head3);
    display(head3);
    head3 = sort(head3);
    display(head3);

}