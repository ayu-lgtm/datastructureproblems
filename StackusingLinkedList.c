#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node*link;
}*top=NULL,*temp,*q;
void push(int data);
void pop();
void display();
int count=0;
void stack_count();
int main()
{
    int a,no;
    printf("\nwlecome to stack program ..\n");
    printf("\n1. push\n2. pop\n3. display\n4. exit\n5. stack_count\n");
    while(1)
    {
        printf("\nselect your choice\n:");
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            push(no);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        case 5:
            stack_count();
            break;
        default:
            printf("wrong choice");
            break;

        }
    }
    return 0;
}
void stack_count()
{
    printf("elements in stack: %d\n",count);
}
void push(int data)
{
    if(top==NULL)
    {
        top=(struct node*)malloc(sizeof(struct node));
        top->link=NULL;
        top->info=data;
    }
    else
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->link=top;
        temp->info=data;
        top=temp;
    }
    count++;
}
void pop()
{
    q=top;
    if(q==NULL)
    {
        printf("\n underflow condition.,\n");
        return;
    }
    else
        q=q->link;
        printf("popped value: %d\n",top->info);
        free(top);
        top=q;
        count--;
}
void display()
{
    q=top;
    if(q==NULL)
    {
        printf("empty stack..\n");
        return;
    }
    while(q!=NULL){
        printf("%d ",q->info);
        q=q->link;
    }
}
