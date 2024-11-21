/*
Design an algorithm and write a program to implement circular queue. Circular queue is a queue
in which last position of queue is connected with first position of queue to make a circle. The
program should implement following operations:
a) Create() - create a queue of specific size
b)EnQueue(k) - insert an element k into the queue
c) DeQueue() - delete an element from the queue
d)IsEmpty() - check if queue is empty or not
e) Front() - return front item from queue
f) Rear() - return rear item from queue
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

que create(que q)
{
    q.front = -1;
    q.rear = -1;
    return q;
}

que Enqueue(que q)
{
    if ((q.rear + 1) % max == q.front)
    {
        printf("Queue is full......");
    }
    else
    {
        q.rear = (q.rear + 1) % max;
        if (q.front == -1)
        {
            q.front = 0;
        }
        int data;
        printf("Enter Data : ");
        scanf("%d", &data);
        q.data[q.rear] = data;
    }
    return q;
}

que Dequeue(que q)
{
    if (q.front == -1)
    {
        printf("Queue is empty......");
    }
    else
    {
        if (q.rear == q.front)
        {
            q.rear = q.front = -1;
        }
        else
        {
            q.front = (q.front + 1) % max;
        }
    }
    return q;
}

void IsEmpty(que q)
{
    if (q.front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Queue is not empty");
    }
}

void Front(que q)
{
    printf("Front = %d", q.data[q.front]);
}
void Rear(que q)
{
    printf("Front = %d", q.data[q.rear]);
}

void Display(que q)
{
    if (q.front == -1)
    {
        printf("Queue is empty......");
    }
    else
    {
        int i;
        printf("\nQueue is : ");
        for (i = q.front; i != q.rear; i = (i + 1) % max)
        {
            printf("%d  ", q.data[i]);
        }
        printf("%d  ", q.data[i]);
    }
}

int main()
{
    while (1)
    {
        que q;
        printf("\n0->Exit 1->Create 2->Enqueue 3->Dequeue 4->IsEmpty 5->Front 6->Rear\n:: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            q = create(q);
            break;
        case 2:
            q = Enqueue(q);
            Display(q);
            break;
        case 3:
            q = Dequeue(q);
            Display(q);
            break;
        case 4:
            IsEmpty(q);
            break;
        case 5:
            Front(q);
            break;
        case 6:
            Rear(q);
            break;
        default:
            printf("Invalid input");
            break;
        }
    }
}