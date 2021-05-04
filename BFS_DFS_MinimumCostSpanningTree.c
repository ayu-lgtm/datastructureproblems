#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>
#define INT_MAX 10
int n,x;
int rear=-1,front=-1;
int top=-1;
void bfs(int v,int vis[n],int q[n],int a[n][n]);
void initial(int a[n][n]);
void edges(int a[n][n]);
void EDGE(int a[n][n]);
void Span(int a[n][n]);
void dfs(int v,int vis[],int q[],int a[n][n]);
int main()
{
    printf("\nEnter the number of Nodes: ");
    scanf("%d",&n);
    int a[n][n];
    int vis[n];
    int q[n];
    initial(a);
    edges(a);

    for(int k=0;k<n;k++)
    {
        vis[k]=0;
    }
    for(int k=0;k<n;k++)
    {
        q[k]=0;
    }
    int pos;
    printf("\n-------------------BREADTH-FIRST-SEARCH---------------------");
    printf("\n\n\nEnter the Starting position for BFS:");
    scanf("%d",&pos);
    printf("%d->",pos);
    bfs(pos,vis,q,a);
        for(int k=0;k<n;k++)
    {
        vis[k]=0;
    }
    for(int k=0;k<n;k++)
    {
        q[k]=0;
}
    printf("\n");
    printf("\n-------------------DEPTH-FIRST-SEARCH---------------------");
    int pos1;
    printf("\n\n\nEnter the Starting position for DFS:");
    scanf("%d",&pos1);
    printf("%d->",pos1);
    dfs(pos1,vis,q,a);
    printf("\n");
    printf("\n-------------------MINIMUM SPANNING TREEE---------------------");

    printf("\n-------------------undirected graph---------------------");
    EDGE(a);
    Span(a);
}
void initial(int a[n][n])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
}
void edges(int a[n][n])
{
    int i,j,l;
    printf("\nEnter the number of edges:");
    scanf("%d",&l);
    int c,b,m=1;
    while(m<=l)
    {       peak:
            printf("\nenter edge between(v1,v2):");
            scanf("%d %d",&c,&b);
            if(c<n && b<n)
            {
                printf("(%d---%d):%d",c,b,1);
                a[c][b]=1;
                if(b!=c)
                {
                   printf("(%d---%d):%d",b,c,1);
                   a[b][c]=1;
                   m=m+1;
                }
                else{
                    m++;
                }
            }
            else{
                printf("invalid !");
                goto peak;
            }
    }

    i=0;
    j=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                a[i][j]=0;
            }
        }
    }
    printf("\nAdjency Matrix of Graph(NOT CONSIDERING LOOP):\n");
    for(i=0;i<n;i++)
    {
        printf("[");
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("]");
        printf("\n");
    }
}
void bfs(int v,int vis[],int q[],int a[n][n])
{
        int u=v;
        int i;
        vis[v]=1;
        for(i=0;i<n;i++)
        {       if(a[u][i]==1)
                {
                        if(vis[i]==0)
                        {
                                rear++;
                                if(front==-1)
                                        front++;
                                q[rear]=i;
                                vis[i]=1;
                        }
                }
        }
        if(front==rear+1)
         {
                return;
         }
        else
         {
                x=q[front];
                front++;
                printf("%d->",x);
                bfs(x,vis,q,a);
         }
}
void dfs(int v,int vis[],int q[],int a[n][n])
{
        int u=v;
        int i;
        vis[v]=1;
        for(i=0;i<n;i++)
        {       if(a[u][i]==1)
                {
                        if(vis[i]==0)
                        {
                                top++;

                                q[top]=i;
                                printf("%d->",i);
                                vis[i]=1;
                                dfs(i,vis,q,a);
                        }
                }
        }
        if(top==-1)
         {
                return;
         }
        else
         {
                x=q[top];
                top--;

         }
}
void Span(int a[n][n])
{
    int parent[n];
    int key[n];
    bool Set[n];
    for (int i = 0; i < n; i++){
        key[i] = INT_MAX,Set[i] = false;}
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, Set);
        Set[u] = true;
        for (int v = 0; v < n; v++){
            if (a[u][v] && Set[v] == false && a[u][v] < key[v])
                parent[v] = u, key[v] = a[u][v];}
    }
    MST(parent,a);
}
int MST(int parent[], int a[n][n])
{
    int sum=0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++){
        printf("%d--%d \t%d \n", parent[i], i, a[i][parent[i]]);
         sum=sum+a[i][parent[i]];
    }
    printf("\nCOST OF MINIMUM SPANNING TREE:");
    printf("%d",sum);
}
int minKey(int key[], bool Set[])
{
    int min = INT_MAX, x;
    for (int v = 0; v < n; v++)
        if (Set[v] == false && key[v] < min)
            min = key[v],x = v;
    return x;
}
void EDGE(int a[n][n])
{
    int i,j,l,w;
    printf("\nEnter the number of edges:");
    scanf("%d",&l);
    int c,b,m=1;
    while(m<=l)
    {       peak:
            printf("\nenter edge between(v1,v2):");
            scanf("%d %d",&c,&b);
            if(c<n && b<n)
            {
                printf("(%d---%d):",c,b);
                scanf("%d",&w);
                a[c][b]=abs(w);
                if(b!=c)
                {
                   printf("(%d---%d):%d",b,c,w);
                   a[b][c]=abs(w);
                   m=m+1;
                }
                else{
                    m++;
                }
            }
            else{
                printf("invalid !");
                goto peak;
            }
    }

    i=0;
    j=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                a[i][j]=0;
            }
        }
    }
    printf("\nAdjency Matrix of Graph:\n");
    for(i=0;i<n;i++)
    {
        printf("[");
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("]");
        printf("\n");
    }
}
