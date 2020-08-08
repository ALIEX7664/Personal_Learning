/*
*********************************************************************************************************
*                                          顺序队
*       以MAXSIZE-1作为队空判断，在队满条件为真时，可能还有若干空位置，造成假溢出
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
    int front,rear;
}SqQueue;

//初始化队
void InitQueue(SqQueue *&q)
{
    q = (SqQueue*)malloc(sizeof(SqQueue));
    q->front = q->rear = -1;
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
    if(q->rear ==MAXSIZE -1)
    {
        return false;
    }
    else
    {
        q->data[++(q->rear)] = e;
        return true;
    }
}

//出队
bool deQueue(SqQueue *&q,ElemType &e)
{
    //队空判断
    if(q->front == q->rear)
    {
        return false;
    }
    else
    {
        e = q->data[++(q->front)];
        return true;
    }
    
}

int main(void)
{

    return 0;

}