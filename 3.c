#include<stdio.h>
#include<stdlib.h>
#define MAXV 100
int visited[100];
typedef struct
{
    int edges[MAXV][MAXV];//邻接矩阵的边数组
    int n,e;//顶点数，边数
    char vexs[MAXV];
}MGraph;
void BulidGraph(MGraph *G)
{
    int i,j,k;
    char ch1,ch2;
    printf("请输入顶点数和边数(输入格式为:顶点数,边数):\n");
    scanf("%d,%d",&(G->n),&(G->e));

    //矩阵清零
    for(i=0;i<G->n;i++)
        for(j=0;j<G->n;j++)
            G->edges[i][j]=0;
    //输入边
    printf("请输入顶点信息,每个节点以回车作为结束:\n");
    for(i=0;i<G->n;i++)
    {
        getchar();
        scanf("%c",&(G->vexs[i]));
    }
    printf("请输入每条边对应的两个顶点(输入格式为:i,j):\n");
    for(k=0;k<G->e;k++)
    {
        getchar();
        scanf("%c,%c",&ch1,&ch2);
        for(i=0;ch1!=G->vexs[i];i++);
        for(j=0;ch2!=G->vexs[j];j++);
        G->edges[i][j]=1;
    }
}
void DFSM(MGraph *G,int i)
{
    int j;
    visited[i]=1;
    printf("深度优先遍历结点: 结点%c\n",G->vexs[i]);   //访问顶点vi
    for(j=0;j<G->n;j++)           //依次搜索vi邻接点
        if(G->edges[i][j]==1 && !visited[j])
            DFSM(G,j);
}
void DFSTraverseM(MGraph *G)
{
    int i;
    for(i=0;i<G->n;i++)
        visited[i]=0;
    for(i=0;i<G->n;i++)
        if(!visited[i])
            DFSM(G,i);
}
int main()
{
    MGraph G;
    BulidGraph(&G);
    DFSTraverseM(&G);
    return 0;
}
