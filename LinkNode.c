//PROGRAM TO CREATE LINKLIST AND ITS MORE FUNCTIONS

#include <stdio.h>
#include <stdlib.h>
struct linkNode
{
    int data;
    struct linkNode *next;
};

void display(struct linkNode *s){
struct linkNode *temp;
temp=s->next;
while(temp!=NULL)
{
    printf("%d    ",temp->data);
    temp=temp->next;
}
printf("\n");
}

void insertAtBeg(struct linkNode *s, int x)
{
    struct linkNode *temp;
    temp = (struct linkNode*)malloc(sizeof(struct linkNode));
    temp->data = x;
    temp->next = s->next;
    s->next = temp;
}

void insertAtEnd(struct linkNode *s,int x){
    struct linkNode *temp1,*temp2;
    temp1 = (struct linkNode*)malloc(sizeof(struct linkNode));
    temp2 = s->next;
    while ((temp1->next)!=NULL)temp2=temp2->next;
    temp1->data=x;
    temp1->next=NULL;
    temp2->next=temp1;
}

void insertAfter(struct linkNode *s,int x,int y){
    struct linkNode *temp1,*temp2;
    temp1 = (struct linkNode*)malloc(sizeof(struct linkNode));
    temp2 = s->next;
    while ((temp2->data)!=x)temp2=temp2->next;
    temp1->data=y;
    temp1->next=temp2->next;
    temp2->next=temp1;
}

int main()
{
    struct linkNode *nn;
    nn = (struct linkNode*)malloc(sizeof(struct linkNode));
    insertAtBeg(nn,5);
    display(nn);
    insertAtEnd(nn,45);
    display(nn);
    insertAfter(nn,5,35);
    display(nn);
}