/*
*********************************************************************************************************
*                                           链栈
*********************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//链栈结构体
typedef struct linknode
{
    ElemType data;
    linknode *next;
} LiStack;

//初始化栈
void InitStack(LiStack *&s)
{
    s = (LiStack *)malloc(sizeof(LiStack));
    s->next = NULL;
}

//销毁栈
void DestroyStack(LiStack *&s)
{
    LiStack *pre = s, *p = s->next;
    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = pre -> next;
    }
    free(pre);
}

//栈空
bool StackEmpty(LiStack *s)
{
    return (s->next == NULL);
}

//入栈
void Push(LiStack *&s,ElemType e)
{
    LiStack *p = (LiStack*)malloc(sizeof(LiStack));
    p->data = e;
    p->next = s->next;
    s->next= p;
}

//出栈
bool Pop(LiStack *&s,ElemType &e)
{
    LiStack *p;
    if(s->next == NULL)
    {
        return false;
    }
    p = s->next;
    e = p->data;
    s->next = p->next;
    free(p);
    return true;
} 

//获取头节点元素
bool GetTop(LiStack *s,ElemType &e)
{
    if(s->next == NULL)
    {
        return false;
    }
    e = s->next->data;
    return true;
}

int main(void)
{
    return 0;
}