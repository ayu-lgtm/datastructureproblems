#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
}*f=NULL,*r=NULL,*q;
int j;
void inqueue()
{
    int n;
    q=(struct node*)malloc(sizeof(struct node));
    printf("\n enter inqueue number: \n");
    scanf("%d",&n);
    q->info=n;
    q->link=NULL;
    if(r==NULL && f==NULL)
    {
        r=f=q;
        r->link=f;
    }
    else
    {
        r->link=q;
        r=q;
        q->link=f;
    }
}
void dequeue()
{
    if(f==NULL && r==NULL)
    {
        printf("\n underflow condition. \n");
    }
    else if(f==r){
        f=r=NULL;
    }
    else
    {
        f=f->link;
        r->link=f;
    }
}
void display()
{
    q=f;
    if(f==NULL && r==NULL)
    {
        printf("\n queue is empty. \n");
    }
    else
    {
        do
        {
            printf("%d ",q->info);
            q=q->link;
        }
        while(q!=f);
    }
}
int main()
{
    while(1)
    {
        int s;
        printf("\n welcome to circular queue program.\n");
        printf("\n 1.inqueue: \n 2.dequeue: \n 3.Display: \n 4.exit(): \n");
        printf("\n select your choice(1-4):\n");
        scanf("%d",&s);
        switch(s)
        {
        case 1:
            inqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\n wrong choice. \n");
        }
    }
    return 0;
}
