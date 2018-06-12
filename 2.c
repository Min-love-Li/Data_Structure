#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 1000
typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
}BTNode;
BTNode *CreatBTNode()//创建以链表为存储结构的二叉树
{
    BTNode *b;
    char ch;
    scanf("%c",&ch);
    if(ch=='/')
        b=NULL;
    else
    {
        b=(BTNode *)malloc(sizeof(BTNode));
        b->data=ch;
        //递归
        b->lchild=CreatBTNode();
        b->rchild=CreatBTNode();
    }
    return b;
}
void InOrder(BTNode *b)//递归中序遍历
{
    if(b!=NULL)
    {
        InOrder(b->lchild);
        printf("%c",b->data);
        InOrder(b->rchild);
    }
}
void InOrder1(BTNode *b)//非递归中序遍历
{
    BTNode *a[maxsize],*p;
    int top=-1;
    if(b!=NULL)
    {
        p=b;
        while(top>-1||p!=NULL)
        {
            while(p!=NULL)
            {
                top++;
                a[top]=p;
                p=p->lchild;
            }
            if(top>-1)
            {
                p=a[top];
                top--;
                printf("%c",p->data);
                p=p->rchild;
            }
        }
        printf("\n");
    }
}
int main()
{
    BTNode *b;
    b=CreatBTNode();
    printf("递归中序遍历：\n");
    InOrder(b);
    printf("\n非递归中序遍历：\n");
    InOrder1(b);
}
