/*
*********************************************************************************************************
*                               笛卡尔积运算
*       存在表A和B，表A的i列元素与表B的j列元素相等，那么作为条件创建C表，该表为结果的记录组
        e.g
            | 1 2 3 |      | 3 5 |                        | 1 2 3 3 5 |
        A = | 2 3 3 |  B = | 1 6 |      C = A *(i=j) B  = | 1 2 3 3 4 |
            | 1 1 1 |      | 3 4 |                        | 2 3 3 3 5 |
                                                          | 2 3 3 3 4 |
                                                          | 1 1 1 1 6 |
        其实就是用A的一行遍历B的每一行，把对应A行中i列和B每一行中j列的数相比较，相同则将A的行与B的对应行给
        合并到一行，不相同则跳过，最后组成C矩阵
*********************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxCol 10   //最大列数

//头节点，保存行和列
typedef struct NodeH
{
    int Col, Row;
    DList *next; //指向第一个行结点
} HList;

//行结点，保存一行的数据
typedef struct NodeD
{
    int data[MaxCol]; //列数
    struct NodeD *next;
} DList;

//交互式建表
void CreateTable(HList *&h)
{
    int i, j;
    DList *r, *s;

    //创建头节点
    h = (HList *)malloc(sizeof(HList));

    printf("input: col row:");
    scanf("%d %d", &h->Col, &h->Row);

    //遍历交互式创建数据
    for (int i = 0; i < h->Row; i++)
    {
        printf("input %d row's data:", i + 1);
        s = (DList *)malloc(sizeof(DList));

        for (int j = 0; j < h->Col; j++)
        {
            scanf("%d", &s->data);
        }

        if (h->next == NULL)
        {
            h->next = s; //只有头节点时
        }
        else
        {
            r->next = s; //有行节点存在时
        }

        //获取下一个节点
        r = s;
    }

    //在链表最后补上NULL
    r->next == NULL;
}

//销毁表
void DestroyTable(HList *&h)
{
    DList *pre = h->next, *p = pre->next;

    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }

    //销毁最后一个结点
    free(pre);
}

void DispTable(HList *h)
{
    int j;
    DList *p = h->next;
    while (!p == NULL)
    {
        //遍历一行的数据
        for (j = 0; j < h->Col; j++)
        {
            printf("%4d", p->data[j]);
        }
        printf("\n");
        p = p->next; //获取下一行的节点
    }
}

//连接运算
void LinkTable(HList *h1, HList *h2, HList *&h)
{
    int i, j, k;
    DList *p = h1->next, *q, *s, *r;

    //输入
    printf(" input connect: h1-co1 h2 -col:");
    scanf("%d %d", &i, &j);

    //初始化组合表C
    h = (HList *)malloc(sizeof(HList));
    h->Row = 0;
    h->Col = h1->Col + h2->Col;
    h->next = NULL;

    //遍历A表
    while (p != NULL)
    {
        //获取b表头节点
        q = h2->next;
        //遍历B表的每一行
        while (q != NULL)
        {
            //找到对应列的数值相同，则进行组合操作
            if (p->data[i - 1] == q->data[j])
            {
                //创建节点
                s = (DList *)malloc(sizeof(DList));

                //将A表的行首先装入
                for (k = 0; k < h1->Col; k++)
                {
                    s->data[k] = p->data[k];
                }

                //将B表的行后续装入
                for (k = 0; k < h2->Col; k++)
                {
                    s->data[k + h1->Col] = p->data[k];
                }

                //根据情况将节点放入组合表中
                if (h->next == NULL)
                {
                    h->next = s;
                }
                else
                {
                    r->next = s;
                }

                //获取组合表中最新的节点
                r = s;
                h->Row++;
            }
            //执行B表下一行
            q = q->next;
        }
        //指向A表下一行
        p = p->next;
    }
    r->next = NULL;
}

int main(void)
{
    return 0;
}