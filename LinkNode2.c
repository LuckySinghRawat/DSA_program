//PROGRAM TO CREATE LINKLIST AND ITS MORE FUNCTIONS USING [typedef str]

#include <stdio.h>
#include <stdlib.h>
typedef struct linkNode
{
    int data;
    struct linkNode *next;
}lnk;

void display(lnk *s){
lnk *temp;
temp=s->next;
while(temp!=NULL)
{
    printf("%d    ",temp->data);
    temp=temp->next;
}
printf("\n");
}

void insertAtBeg(lnk *s, int x)
{
    lnk *temp;
    temp = (lnk*)malloc(sizeof(lnk));
    temp->data = x;
    temp->next = s->next;
    s->next = temp;
}

void insertAtEnd(lnk *s,int x){
    lnk *temp1,*temp2;
    temp1 = (lnk*)malloc(sizeof(lnk));
    temp2 = s->next;
    while ((temp1->next)!=NULL)temp2=temp2->next;
    temp1->data=x;
    temp1->next=NULL;
    temp2->next=temp1;
}

void insertAfter(lnk *s,int x,int y){
    lnk *temp1,*temp2;
    temp1 = (lnk*)malloc(sizeof(lnk));
    temp2 = s->next;
    while ((temp2->data)!=x)temp2=temp2->next;
    temp1->data=y;
    temp1->next=temp2->next;
    temp2->next=temp1;
}

int main()
{
    lnk *nn;
    nn = (lnk*)malloc(sizeof(lnk));
    insertAtBeg(nn,5);
    display(nn);
    insertAtEnd(nn,45);
    display(nn);
    insertAfter(nn,5,35);
    display(nn);
}