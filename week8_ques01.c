/*
Write  an algorithm and  a program  to implement doubly linked list.  The program  should
implement following operations:
a) Create(k) - create a linked list with single node of value k
b)InsertFront(k) - insert node of value k at the front of the linked list
c) InsertEnd(k) - insert a node of value k at the end of the linked list
d)InsertAnywhere(p) - insert a node at specific position p
e) DeleteFront() - delete a node from the front of the linked list
f) DeleteEnd() - delete a node from the end of the linked list
g)DeleteAnywhere(p) - delete a node from a specific position p
h)Size() - find the size of the linked list
i) IsEmpty() - checks if the linked list is empty or not
j) FindMiddle() - finds the middle element of the linked list
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} ln;

ln *createNode(ln *ptr)
{
    ln *temp = NULL;
    temp = (ln *)malloc(sizeof(ln));
    printf("Enter data : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    ptr = temp;
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
        printf("| %d | <==> ", ptr->data);
        ptr = ptr->next;
    }
    printf("| %d |-->null", ptr->data);
}

ln *insertAtFront(ln *ptr)
{
    ln *temp = (ln *)malloc(sizeof(ln));
    ln *start = ptr;
    printf("Enter data : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;

    temp->next = ptr;
    ptr->prev = temp;
    start = temp;
    return start;
}

ln *insertAtEnd(ln *ptr)
{
    ln *temp = (ln *)malloc(sizeof(ln));
    printf("Enter data : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;

    ln *last = ptr;
    while (last->next != NULL)
        last = last->next;
    last->next = temp;
    temp->prev = last;
    return ptr;
}

ln *insertAt(ln *ptr)
{
    int position;
    printf("Enter position : ");
    scanf("%d", &position);
    ln *temp = (ln *)malloc(sizeof(ln));
    printf("Enter data : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;

    ln *node = ptr;
    while (position > 2)
    {
        node = node->next;
        position--;
    }
    temp->next = node->next;
    temp->prev = node->prev;
    node->next = temp;
    return ptr;
}

void size(ln *ptr)
{
    int count = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    printf("Size of Linked List is %d\n", count);
}

void isEmpty(ln *ptr)
{
    if (ptr == NULL)
    {
        printf("Lniklist is Empty...");
    }
    else
    {
        printf("NOt Empty");
    }
}

void middleNode(ln *ptr)
{
    ln *slow = ptr, *fast = ptr;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    printf("| %d | is middle node\n", slow->data);
}

ln *deleteFront(ln *ptr)
{
    if (ptr != NULL)
    {
        ln *temp = ptr;
        ptr = ptr->next;
        if (ptr != NULL) // NULL prev does't exist
        {
            ptr->prev = NULL;
        }
        free(temp);
        printf("Deleted\n");
        return ptr;
    }
}

ln *deleteEnd(ln *ptr)
{
    if (ptr != NULL)
    {
        ln *temp = ptr, *ffree;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        ffree = temp;
        if (temp->prev != NULL) // to delete
        {
            temp->prev->next = NULL;
        }
        else // to protect from{if ptr->prev==NULL}[then change ptr to NULL]
        {
            ptr = NULL;
        }
        free(ffree);
        printf("Deleted\n");
        return ptr;
    }
}

ln *deleteNodeAt(ln *ptr)
{
    if (ptr != NULL)
    {

        ln *temp = ptr, *ffree;
        printf("Enter position : ");
        int posi;
        scanf("%d", &posi);
        if (posi == 1)
        {
            return deleteFront(ptr);
        }

        while (posi > 1)
        {
            temp = temp->next;
            posi--;
        }
        ffree = temp;
        if (temp->next != NULL)
        {
            temp->prev->next = temp->next;
        }
        else
        {
            return deleteEnd(ptr);
        }
        printf("Deleted\n");
        free(ffree);
        return ptr;
    }
}

int main()
{
    ln *head = NULL;
    while (1)
    {
        printf("\n0->Create 1->InsertAtFront 2->InsertAtEnd 3->InsertAt\n 4->DeleteFront 5->DeleteEnd 6->DeleteAt\n  7->Size 8->IsEmpty 9->FindMiddle\n   :: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            head = createNode(head);
            display(head);
            break;
        case 1:
            head = insertAtFront(head);
            display(head);
            break;
        case 2:
            head = insertAtEnd(head);
            display(head);
            break;
        case 3:
            head = insertAt(head);
            display(head);
            break;
        case 4:
            head = deleteFront(head);
            display(head);
            break;
        case 5:
            head = deleteEnd(head);
            display(head);
            break;
        case 6:
            head = deleteNodeAt(head);
            display(head);
            break;
        case 7:
            size(head);
            break;
        case 8:
            isEmpty(head);
            break;
        case 9:
            middleNode(head);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}