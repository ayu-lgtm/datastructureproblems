#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1;
 

void enq(int data);
void deq();
void display();
void create();
 
int count = 0;
 
void main()
{
    int no, ch, e;
 
    printf("\n 1 - Insert");
    printf("\n 2 - Delete");
    printf("\n 3 - Exit");
    printf("\n 4 - Display");
    
    create();
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            enq(no);
            break;
        case 2:
            deq();
            break; 
        case 3:
            exit(0);
        case 4:
            display();
            break;
       
        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}
 
/* Create an empty queue */
void create()
{
    front = rear = NULL;
}
/* Enqueing the queue */
void enq(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
 
        rear = temp;
    }
    count++;
}
 
/* Displaying the queue elements */
void display()
{
    front1 = front;
 
    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d", front1->info);
}
 
/* Dequeing the queue */
void deq()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("\n Deleted Value : %d", front->info);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n Deleted value  : %d", front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}
