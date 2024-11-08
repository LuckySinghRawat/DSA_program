#include<stdio.h>
#include<stdlib.h>
# define max 5
int queue[max];
int front = -1,rear = -1;

void enqueue(){
    if(rear == max-1){
        printf("overflow.....\n");
    }
    else{
        if(front == -1){
            front = 0;
        }
        int num;
        rear++;
        printf("Enter element to enter : ");
        scanf("%d",&num);
        queue[rear]= num;
    }
}
void dequeue(){
    if (front == -1 || front == rear + 1)
    {
        printf("Empty Queue.....\n");
    }
    else{
        int x = queue[front];
        printf("Deleted element is : %d\n",x);
        front++;
    }
    
}
void display(){
    if(front == -1 || front == rear + 1){
        printf("Empty Queue.......\n");
    }
    else{
        printf("Elements in queue are : ");
        for(int i = front ;i<=rear;i++){
            printf("%d\t",queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("Enter 1->enqueue 2->dequeue 3->display 0->exit : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:

            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            printf("Enter valid choice \n");
            break;
        }
    }
}