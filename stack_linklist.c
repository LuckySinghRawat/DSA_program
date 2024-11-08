#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} stk;

stk *push(stk *ptr)
{
    stk *temp;
    temp = (stk *)malloc(sizeof(stk));
    printf("Enter data : ");
    scanf("%d",&temp->data);
    temp->next = NULL;
    if (ptr == NULL)
    {
        ptr = temp;
    }
    else
    {
        temp->next = ptr;
        ptr = temp;
    }
    return ptr;
}



stk *pop(stk *ptr){
    if(ptr == NULL){
        printf("empty stack...\n");
    }
    else{
        printf("Poped element is :%d \n",ptr->data);
        stk *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    return ptr;
}

void display(stk *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    stk *top = NULL;
    int choice;
    while (1)
    {
        printf("Enter 1->push 2->pop 3->display 0->exit : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:

            top = push(top);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            display(top);
            break;
        default:
            printf("Enter valid choice \n");
            break;
        }
    }
}