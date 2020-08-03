/*
*********************************************************************************************************
*                                           链队
*********************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//节点结构体
typedef struct qnode
{
    ElemType data;
    qnode *next;
} DataNode;

//队列结构体
typedef struct
{
    DataNode *front;
    DataNode *rear;
} LinkQueue;

//初始化队列
void InitQueue(LinkQueue *&q)
{
    q = (LinkQueue *)malloc(sizeof(LinkQueue));
    q->front = q->rear = NULL;
}

//销毁队列
void DestroyQueue(LinkQueue *&q)
{
    DataNode *pre = q->front, *p;

    //若存在节点
    if (pre != NULL)
    {
        //获取首节点
        p = pre->next;

        //遍历节点
        while (p != NULL)
        {
            free(pre);   //释放当前节点前节点
            pre = p;     //存储当前节点
            p = p->next; //获取下个节点
        }
        free(pre); //释放尾节点
    }
    free(q); //释放队列
}

//判断队空
bool QueueEmpty(LinkQueue *q)
{
    //return (q->rear == NULL)
    return (q->front == NULL);
}

//入队
void enQueue(LinkQueue *&q, ElemType e)
{
    //申请节点
    DataNode *p = (DataNode *)malloc(sizeof(DataNode));
    p->data = e;
    p->next = NULL;

    //判断队列是否为空
    if (q->rear == NULL)
    {
        //首尾指针均指向p节点
        q->front = q->rear = p;
    }
    else
    {
        //尾节点的后继节点指针指向p节点
        q->rear->next = p;
        //再将尾节点指针指向p节点
        q->rear = p;
    }
}

//出队
bool deQueue(LinkQueue *&q, ElemType &e)
{
    DataNode *p;

    //不存在节点
    if (q->rear == NULL) //q->front == NULL
    {
        return false;
    }
    p = q->front;
    
    //判断节点个数
    if(q->front == q->rear)
    {
        //单节点则重置首尾指针为NULL
        q->front = q->rear =NULL;
    }
    else
    {
        //队首节点指针指向队首节点的下节点
        q->front = q->front->next;
    }

    //获取数据并释放资源
    e = p->data;
    free(p);
}

int main(void)
{
    return 0;
}