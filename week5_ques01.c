/*
Design an algorithm and a program to implement queue using array. The program should
implement following queue operations:
a) Create() - create a queue
b) EnQueue(k) - insert an element k into the queue
c) DeQueue() - delete an element from the queue
d) IsEmpty() - check if queue is empty or not
e) Size() - finds the size of the queue


data             
rear -1  0 1 2 3 4
front -1 0 1 2 3 4 5

front ek aage hoga rear se empty k liye
*/
#include <stdio.h>
#include <stdlib.h>
#define max 5
typedef struct Queue
{
    int data[max];
    int front;
    int rear;
} que;
que Enqueue(que q)
{
    if (q.rear == max - 1)
    {
        printf("Queue is full......");
    }
    else
    {
        if (q.front == -1)
        {
            q.front = 0;
        }
        int data;
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        q.data[++q.rear] = data;
    }
    return q;
}
que Dequeue(que q)
{
    if (q.front > q.rear)
    {
        printf("Queue is empty......");
    }
    else
    {
        printf("Deleted element is: %d\n", q.data[q.front++]);
    }
    return q;
}
void Display(que q)
{
    if (q.front == -1 || q.front > q.rear)
    {
        printf("Queue is empty......");
    }
    else
    {
        printf("Queue elements are: ");
        for (int i = q.front; i <= q.rear; i++)
        {
            printf("%d  ", q.data[i]);
        }
    }
}
void size(que q){
    if (q.front == -1 || q.front > q.rear){
        printf("Size = 0");
    }else{
        printf("Size = %d", q.rear - q.front + 1);
    }
}
int main()
{
    que q;
    q.front = -1, q.rear = -1;
    while (1)
    {
        int ch;
        printf("\nQueue Operations\n1->EnQueue 2->DeQueue 3->Display 4->Size 5->Exit : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            q = Enqueue(q);
            break;
        case 2:
            q = Dequeue(q);
            break;
        case 3:
            Display(q);
            break;
        case 4:
            size(q);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid input....");
            break;
        }
    }
}