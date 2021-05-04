#include <stdio.h>
#include <stdlib.h>
struct queue{
    int front,rear;
    int item[5];
};
void inqueue(struct queue*q)
{
    int x;
    printf("enter number to be inserted:\n");
    scanf("%d",&x);
    if(q->rear==4 && q->front==0 || q->front==q->rear+1)
    {
        printf("\n queue is overflow.\n");
    }
    if(q->front==-1)
    {
        q->front=0;
        q->rear=0;
    }
    else if(q->rear==4 && q->front!=0)
    {
        q->rear=0;
    }
    else
    {
        q->rear=q->rear+1;
    }
    q->item[q->rear]=x;
}
int dequeue(struct queue*q)
{
    if(q->front==-1 && q->rear==-1)
    {
        printf("\n queue is underflow.\n");
        exit(0);
    }
    if(q->front==q->rear)
    {
        q->front=q->rear=-1;
    }
    else if(q->front==4)
    {
        q->front=0;
    }
    else
    {
        return(q->item[(q->front)++]);
    }
}
void display(struct queue*q)
{
    int i;
    if(q->rear<q->front)
    {
        printf("empty queue.\n");
    }
    else{
        printf("elements of queue:\n");
        for(i=q->front;i<=q->rear;i++)
        {
            printf("%d ",q->item[i]);
        }
    }
}
int main()
{
    struct queue q;
    q.front=-1;
    q.rear=-1;
    while(1)
    {
        int n;
        printf("\n welcome in queue program.\n");
        printf("\n 1. inqueue:\n 2. dequeue:\n 3. display:\n 4. exit:\n");
        printf("select your choice (1-4)-------\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            inqueue(&q);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}
