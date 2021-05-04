#include <stdio.h>
#include <stdlib.h>

struct stack{
    int top;
    int item[10];
};
void insert(struct stack *q)
{
    int k;
    printf("enter the number which u want to add:\n");
    scanf("%d",&k);
    if(q->top==10)
    {
        printf("\n stack is overflow.\n");
    }
    else{
        q->item[++(q->top)]=k;
    }
}
int deletion(struct stack *q)
{
    if(q->top==-1)
    {
        printf("stack is underflow.\n");
    }
    else
        return(q->item[(q->top)--]);
}
void display(struct stack *q)
{
    int i;
    if(q->top==-1)
    {
        printf("\n stack is empty.");
    }
    else
    {
        printf("stack : ");
        for(i=q->top;i>=0;i--)
        {
            printf("%d ",q->item[i]);
        }
    }
}
int main()
{
    struct stack s;
    s.top=-1;
    while(1)
    {
        printf("\n welcome in stack program \n");
        printf("\n 1. insert: \n 2. deletion: \n 3.display: \n 4. exit(): \n");
        printf("select your choice:\n");
        int l;
        scanf("%d",&l);
        switch(l)
        {
        case 1:
            insert(&s);
            break;
        case 2:
            deletion(&s);
            break;
        case 3:
            display(&s);
            break;
        case 4:
            exit(0);
        default:
            printf("\n wrong choice! \n");
        }
    }
    return 0;
}
