/*
*********************************************************************************************************
*                                       顺序栈
*********************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

//可拓展
#define MAXSIZE 5
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int top;    //栈顶指针
} SqStack;

//初始化栈
void InitStack(SqStack *&s)
{
    s = (SqStack*)malloc(sizeof(SqStack));
    s->top = -1;    //无元素，初始化为-1
}

//销毁栈
void DestroyStack(SqStack *&s)
{
    free(s);
}

//判断是否为空
bool StackEmpty(SqStack *s)
{
    return (s->top == -1);
}

//进栈
bool Push(SqStack *&s,ElemType e)
{
    //栈满检查
    if(s->top == MAXSIZE -1)
    {
        return false;
    }
    else
    {
        //top++后放入元素
        s->data[++(s->top)] = e;    
        return true;
    }
}

//出栈
bool Pop(SqStack *&s,ElemType &e)
{
    //有无元素检查
    if(s->top == -1)
    {
        return false;
    }
    else
    {
        //取得栈顶元素后top--
        e =s->data[s->top--];
        return true;
    }
}

//取栈顶元素
bool GetTop(SqStack *s,ElemType &e)
{
    if(s->top == -1)
    {
        return false;
    }
    else
    {
        e = s->data[s->top];
        return true;
    }
    
}

int main(void)
{
    return 0;
}