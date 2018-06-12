#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAXSIZE 110
#define NULLKEY -1
#define DELKEY -2

typedef struct
{
    int key;                            //标注节点状态
    char name[20];
    int counter;                        //探查次数
}HashTable[MAXSIZE];

void createtable(HashTable a,int *n);
void Inserttable(HashTable a,int k,int m,char name[20],int *n);
int Searchtable(HashTable a,int m,char name[20]);
void Deletetable(HashTable a,int loc,int *n);
void change(HashTable a,int *n);

int main(void)
{
    int n;                                          //n为总人数
    HashTable a;
    createtable(a,&n);
    change(a,&n);
    return 0;
}


void createtable(HashTable a,int *n)
{
    int i,j,k;
    int m=101;
    char name[20];
    printf("请输入一共多少人%(不超过100人%):");
    scanf("%d%*c",n);
    for (i=0;i<101;i++)
    {
        a[i].counter=0;
        a[i].key=NULLKEY;
    }
    for (i=0;i<*n;i++)
    {
        j=0;
        printf("请输入第%d个人的姓名：",i+1);
        do
        {
            scanf("%c",&name[j++]);
        }while(name[j-1]!='\n');
        name[j-1]='\0';
        k=name[0]-'a'+1;
        Inserttable(a,k,m,name,n);
    }
}
void Inserttable(HashTable a,int k,int m,char name[20],int *n)
{
    int i;
    int loc;
    loc=k%m;                           //位置
    if (a[loc].key==NULLKEY || a[loc].key==DELKEY)
    {
            strcpy(a[loc].name,name);
            a[loc].key=k;
            a[loc].counter=1;
    }
    else
    {
        i=1;
        do
        {
            loc=(loc + 1) % m;
            i++;
        }while(a[loc].key!=NULLKEY && a[loc].key!=DELKEY);
        strcpy(a[loc].name,name);
        a[loc].key=k;
        a[loc].counter=i;
    }
}

int Searchtable(HashTable a,int m,char name[20])
{
    int i,loc;
    int k;
    k=name[0]-'a'+1;
    loc=k%m;
    while(a[loc].key!=NULLKEY && strcmp(a[loc].name,name)!=0)
    {
        i++;
        loc=(loc + 1) % m;
    }
    if (strcmp(a[loc].name,name)==0 && a[loc].key!=DELKEY)
    {
        return loc;
    }
    else
    {
        return NULLKEY;
    }
}

void Deletetable(HashTable a,int loc,int *n)
{
    a[loc].key=DELKEY;
    n--;
}

void change(HashTable a,int *n)
{
    int i,j,p,k,loc;                                    //p为要查找人数
    char name[20];
    printf("请输入要查找的人数:");
    scanf("%d%*c",&p);
    for (i=0;i<p;i++)
    {
        printf("请输入要查找的人的姓名:");
        j=0;
        do
        {
            scanf("%c",&name[j++]);
        }while(name[j-1]!='\n');
        name[j-1]='\0';
        k=name[0]-'a'+1;
        loc=Searchtable(a,101,name);
        if (loc>=0)printf("在第%d存储\n",loc);
        else printf("不存在\n");
        if (loc<0) Inserttable(a,k,101,name,n);
        else Deletetable(a,loc,n);
    }
}
