// FOR ALL LINKLIST OPERATION

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; // TO STORE DATA
    struct node *next;
};
struct node *head = NULL; // WHICH POINTS FIRST_NODE

void display(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("List is underFlow...\n");
    }
    // CHECK THAT IS LINKLIST IS EMPTY OF NOT
    else
    {
        printf("\nLinked list is : ");
        while (ptr != NULL)
        {
            printf("%d  ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n\n");
    }
}

void insertAtBeg(struct node *ptr)
{
    struct node *temp;
    int x;
    temp = (struct node *)malloc(sizeof(struct node));
    // TEMP IS CREATING NEW_NODE TO STORE DATA IN IT

    printf("Enter data: ");
    scanf("%d", &x);
    temp->data = x; // TEMP STORING DATA
    temp->next = NULL;

    head = temp;
    temp->next = ptr;
    // FOR BEGINING TEMP BECAME HEAD AND POINTING TO PTR(pointer) FOR NEXT
    printf("NOde inserted succesfully...\n");
}
void insertAtEnd(struct node *ptr)
{
    struct node *temp;
    int x;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &x);
    temp->data = x;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    } // IF FOR ENDING THEIR IS NO LINKNODE IF FIRST THAN TEMP BECAME FIRST

    else
    {
        head = ptr;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        } // SEARCHING FOR PTR POINTING TO NULL

        ptr->next = temp;
        // AFTER FINDING NULL REPLACE IT WITH TEMP
    }
    printf("Node inserted successfully...\n");
}

void insertAfter(struct node *s, int x)
{
    struct node *temp1;
    int flag = -1, y;
    temp1 = (struct node *)malloc(sizeof(struct node));
    while (s != NULL)
    {
        if (s->data == x)
        {
            flag = 1;
            break;
        }
        s = s->next;
    } // LOOP IS FOR FINDING NULL,,,BUT IF S->DATA FINDS X THAN FLAG CHANGE [-1,1]

    if (flag == -1)
    {
        printf("%d does not exist\n", x);
        return;
    } // CHECKING FOR [after which] IS PRESENT OR NOT

    printf("Enter value to insert after : ");
    scanf("%d", &y);
    temp1->data = y;
    temp1->next = s->next;
    s->next = temp1;
}
int size(struct node *ptr)
{
    int count = 0;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (ptr != NULL)
        {
            ptr = ptr->next;
            count++;
        }
    }
    return count;
}
void middleNode(struct node *ptr)
{
    int count = size(head) / 2, match = 0;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        if (size(head) > 2)
        {
            while (ptr != NULL)
            {
                match++;
                if (match == count)
                {
                    break;
                }
                else
                {
                    ptr = ptr->next;
                }
            }
            if (size(head) % 2 == 0)
            {
                printf("The Middle Nodes are : %d\t%d\n", ptr->data, ptr->next->data);
            }
            else
            {
                printf("The Middle Node is : %d\n", ptr->next->data);
            }
        }else{
            printf("There is no MiddleElement....\n");
        }
    }
}
void searchNode(struct node *ptr, int x)
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (ptr != NULL)
        {
            if (ptr->data == x)
            {
                printf("Found successfully....\n");
                return;
            }
            ptr = ptr->next;
        }
        printf("Not found...\n");
    }
}
struct node *deleteNode(struct node *start, int x)
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        if (start->data == x)
        {
            struct node *temp = start;
            start = start->next;
            // free(temp);
            printf("Deleted successfully...\n");
            return start;
        }

        struct node *temp, *prv;
        temp = start->next;
        prv = start;
        while (temp->data != x)
        {
            temp = temp->next;
            prv = prv->next;
        }
        prv->next = temp->next;
    }
    printf(" Deleted successfully...\n");
    return start;
}

int main()
{
    int ch, value, after;
    while (1)
    {
        int num;
        printf("\nEnter 1->insertingAtBegining : 2->insertingAtEnd : 3->insertAfter : 4->display : 5->deleteNode : 6->size : 7->middleNode : 8->searchNode: 0->exit\n\t:: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertAtBeg(head);
            break;

        case 2:
            insertAtEnd(head);
            break;

        case 3:

            printf("After which : ");
            scanf("%d", &after);
            insertAfter(head, after);
            break;

        case 4:
            display(head);
            break;

        case 5:
            printf("Enter data to delete : ");
            scanf("%d", &num);
            head = deleteNode(head, num);
            break;

        case 6:
            printf("Size of Linklist is : %d", size(head));
            break;

        case 7:
            middleNode(head);
            break;

        case 8:
            printf("Enter data to search : ");
            scanf("%d", &num);
            searchNode(head, num);
            break;

        case 0:
            exit(0);

        default:
            printf("Enter Valid choise!!!\n\n");
            break;
        }
    }
}