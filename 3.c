#include<stdio.h>
#include<stdlib.h>
#define MAXV 100
int visited[100];
typedef struct
{
    int edges[MAXV][MAXV];//�ڽӾ���ı�����
    int n,e;//������������
    char vexs[MAXV];
}MGraph;
void BulidGraph(MGraph *G)
{
    int i,j,k;
    char ch1,ch2;
    printf("�����붥�����ͱ���(�����ʽΪ:������,����):\n");
    scanf("%d,%d",&(G->n),&(G->e));

    //��������
    for(i=0;i<G->n;i++)
        for(j=0;j<G->n;j++)
            G->edges[i][j]=0;
    //�����
    printf("�����붥����Ϣ,ÿ���ڵ��Իس���Ϊ����:\n");
    for(i=0;i<G->n;i++)
    {
        getchar();
        scanf("%c",&(G->vexs[i]));
    }
    printf("������ÿ���߶�Ӧ����������(�����ʽΪ:i,j):\n");
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
    printf("������ȱ������: ���%c\n",G->vexs[i]);   //���ʶ���vi
    for(j=0;j<G->n;j++)           //��������vi�ڽӵ�
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
