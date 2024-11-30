/*
Design an algorithm and write a program to reverse a queue.
Input format: Queue elements are taken as an input.
Output Format: Output will be update reverse queue.
Sample:
Input:
Press:
1 to insert
2 to exit
1
924
1
380
1
206
2

Output:
Initial Queue : 924 380 206
Reverse Queue : 206 380 924
*/

#include <stdio.h>
#include <stdlib.h>
#define max 10
typedef struct Queue
{
    int data[max];
    int front;
    int rear;
} que;

que Enqueue(que q, int data)
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
        q.data[q.front++];
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
        for (int i = q.front; i <= q.rear; i++)
        {
            printf("%d  ", q.data[i]);
        }
    }
}

que Reverse(que q)
{
    int j = q.rear;
    for (int i = q.front; i < (q.rear - q.front + 1)/2; i++)
    {
        int temp1 = q.data[i];
        q.data[i] = q.data[j];
        q.data[j] = temp1;
        j--;
    }
    return q;
}

int main()
{
    que q;
    q.front = -1, q.rear = -1;
    int data;
    while (1)
    {
        int ch;
        printf("\nQueue Operations\n1->EnQueue 2->Exit : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            q = Enqueue(q, data);
            break;
        case 2:
            printf("Initial Queue  : ");
            Display(q);
            q = Reverse(q);
            printf("\nReversed Queue : ");
            Display(q);
            exit(0);
        }
    }
}