/*
*********************************************************************************************************
*                                          循环队列/环形队列
*       解决顺序队列假溢出情况，但只能有MAXSIZE - 1个元素存在
*********************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

#define MAXSIZE 10

//队列结构体
typedef struct
{
    ElemType data[MAXSIZE];
    //front队首指向元素前一个位置
    //rear队尾指向最后一个元素
    int front, rear;
} SqQueue;

//初始化队
void InitQueue(SqQueue *&q)
{
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = 0; //初始化为0
}

//销毁队列
void DestroyQueue(SqQueue *&q)
{
    free(q);
}

//队空判断
bool QueueEmpty(SqQueue *q)
{
    //由于front和rear会随着元素进出和不断变化，不能用q->rear来判断是否为空
    return (q->front == q->rear);
}

//入队
bool enQueue(SqQueue *&q, ElemType e)
{
    //堆满判断，通过加1判断是否到达front下标来判断是否对队满
    if ((q->rear + 1) % MAXSIZE == q->front)
    {
        return false;
    }
    else
    {
        //循环自增后放入e
        q->data[(++(q->rear)) % MAXSIZE] = e;  
        return true;
    }
}

//出队
bool deQueue(SqQueue *&q, ElemType &e)
{
    //队空判断
    if (q->front == q->rear)
    {
        return false;
    }
    else
    {
        //获取e后循环自增
        e = q->data[(q->front++) % MAXSIZE];
        return true;
    }
}

int main(void)
{
    return 0;
}