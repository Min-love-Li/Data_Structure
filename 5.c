#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#define maxs 10000000

typedef struct
{
    int key;
    char data;
}RecType;
void InserSort(RecType a[],int n);
void QuickSort(RecType a[],int s,int t);

int main()
{
    RecType *a;
    a = (RecType*)malloc(maxs*sizeof(RecType));
    int n=maxs,i,k;
    time_t start,end;
    k=0;


    srand((unsigned int)time(NULL));//设置当前时间为种子
    for(i=0;i<maxs;i++)
    {
        a[i].key=rand();
    }

    start =time(NULL);
    //InserSort(a,n);
    end =time(NULL);
    printf("time=%f\n",difftime(end,start));


    srand((unsigned int)time(NULL));//设置当前时间为种子
    for(i=0;i<maxs;i++)
    {
        a[i].key=rand()%maxs;
    }
    start =time(NULL);
    QuickSort(a,k,n);
    end =time(NULL);
    printf("time=%f\n",difftime(end,start));
    free(a);
    return 0;
}

void InserSort(RecType a[],int n)
{
    int i,j;
    RecType tmp;
    for(i=1;i<n;i++)
    {
        tmp=a[i];
        j=i-1;
        while(j>=0&&tmp.key<a[j].key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=tmp;
    }
}
void QuickSort(RecType a[],int s,int t)
{
    int i=s,j=t;
    RecType tmp;
    if(s<t)
    {
        tmp=a[s];
        while(i!=j)
        {

            while(j>i&&a[j].key>=tmp.key)
                j--;
            a[i]=a[j];
            while(i<j&&a[i].key<=tmp.key)
                i++;
            a[j]=a[i];
        }
        a[i]=tmp;
        QuickSort(a,s,i-1);
        QuickSort(a,i+1,t);
    }
}
