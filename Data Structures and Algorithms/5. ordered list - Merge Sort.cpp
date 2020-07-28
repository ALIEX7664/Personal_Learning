/*
*********************************************************************************************************
*                           顺序表的二路归并算法演示
*********************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 10

//顺序表
typedef struct
{
    int data[MAXNUM];
    int length;
} SqList;

//链表
typedef struct lnode
{
    int data;
    lnode *next;
} LinkNode;

//顺序表归并算法
void SqUnionList(SqList *LA, SqList *LB, SqList *&LC)
{
    int i,j,k;
    i = j = k = 0;
    LC = (SqList *)malloc(sizeof(SqList));

    //以长度较短的有序表作为条件,将LA和LB表的数据按顺序存入LC
    while (i < LA->length && j < LB->length)
    {
        if (LA->data[i] < LB->data[j])
        {
            LC->data[k++] = LA->data[i++];
        }
        else
        {
            LC->data[k++] = LB->data[j++];
        }

        //将较长的有序表剩余的数据放入LC中
        while (i < LA->length)
        {
            LC->data[k++] = LC->data[i++];
        }
        while (j < LB->length)
        {
            LC->data[k++] = LB->data[j++];
        }

        //保存长度
        LC->length = k;
    }
}

//链表归并算法
void LinkUnionList(LinkNode *LA, LinkNode *LB, LinkNode *&LC)
{
    LinkNode *pa = LA->next, *pb = LB->next, *r, *s;
    r = LC; //获取新的有序表算法

    //遍历有序表，根据条件存入数据
    while (pa != NULL && pb != NULL)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));

        if (pa->data < pb->data)
        {
            s->data = pa->data;
            pa = pa->next;
        }
        else
        {
            s->data = pb->data;
            pb = pb->next;
        }

        //保存节点
        r->next = s;
        r = s;
    }
    
    //将长度较长的有序表剩余的数据放入LC
    while(pa != NULL)
    {
        s = (LinkNode*)malloc(sizeof(LinkNode));
        s -> data = pa->data;
        r->next = s;
        r = s;
    }
      while(pb != NULL)
    {
        s = (LinkNode*)malloc(sizeof(LinkNode));
        s -> data = pb->data;
        r->next = s;
        r = s;
    }

    //使最后一个节点指向NULL
    r->next = NULL;

}


int main(void)
{
    return 0;
}
