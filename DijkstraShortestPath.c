#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
int n;
int main()
{
    printf("\nEnter the number of Nodes: ");
    scanf("%d",&n);
    int a[n][n];
    int vis[n];
    int q[n];
    initial(a);
    edges(a);
    int u;
    printf("\nEnter the starting node:");
    scanf("%d",&u);
    dijkstra(a,u);

  return 0;
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

void dijkstra(int G[n][n],int startnode)
{

  int cost[n][n],dis[n],pred[n];
  int visited[n],count,mind,next,i,j;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      if(G[i][j]==0)
        cost[i][j]=INFINITY;
      else
        cost[i][j]=G[i][j];

  for(i=0;i<n;i++)
  {
    dis[i]=cost[startnode][i];
    pred[i]=startnode;
    visited[i]=0;
  }

  dis[startnode]=0;
  visited[startnode]=1;
  count=1;

  while(count<n-1)
  {
    mind=INFINITY;

    for(i=0;i<n;i++)
      if(dis[i]<mind&&!visited[i])
      {
        mind=dis[i];
        next=i;
      }

      visited[next]=1;
      for(i=0;i<n;i++)
        if(!visited[i])
          if(mind+cost[next][i]<dis[i])
          {
            dis[i]=mind+cost[next][i];
            pred[i]=next;
          }
    count++;
  }

  for(i=0;i<n;i++)
    if(i!=startnode)
    {
      printf("\nShortest path between node(%d---%d)",i,startnode);
      printf("\nPath=%d",i);

      j=i;
      do
      {
        j=pred[j];
        printf("<-%d",j);
      }while(j!=startnode);
  }
}
