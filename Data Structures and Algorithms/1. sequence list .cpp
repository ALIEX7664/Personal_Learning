#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50 //最大数据元素数量

//线性表结构体
typedef struct
{
    int data[MAXSIZE];
    int length;
} SqList;

//创建线性表
void CreateList(SqList *&L, int a[], int n)
{
    int i = 0;
    L = (SqList *)malloc(sizeof(SqList)); //分配线性表存储空间
    while (i < n)
    {
        L->data[i] = a[i]; //讲数据按i扫描a，存入线性表
        i++;
    }
    L->length = n; //记录长度
}

//初始化线性表
void InitList(SqList *&L)
{
    L = (SqList *)malloc(sizeof(SqList));
    L->length = 0; //初始化长度为0
}

//销毁线性表
void DestroyList(SqList *L)
{
    free(L);
}

//判断线性表是否为空表
bool ListEmpty(SqList *L)
{
    return (L->length == 0);
}

//求线性表长度
int ListLength(SqList *L)
{
    return L->length;
}

//输出线性表
void DispList(SqList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d", L->data[i]);
    }
    printf("\n");
}

//求线性表中某个数据元素值
bool GetElem(SqList *L, int i, int &e)
{
    //出错判断
    if (i < 1 || i > L->length)
    {
        return false;
    }
    //获取元素
    e = L->data[i - 1];
    return true;
}

//按元素值查找
int LocateElem(SqList *L, int &e)
{
    int i = 0;
    while (i < L->length && L->data[i] != e)
    {
        i++;
    }
    if (i >= L->length)
    {
        return 0;
    }
    else
    {
        return i + 1; //返回真是坐标，下标+1
    }
}

//插入数据元素
bool ListInsert(SqList *&L, int i, int e)
{
    int j;
    if (i < 1 || i > L->length + 1)
    {
        return false;
    }
    i--;
    for (j = L->length; j > i; j--)
    {
        //将插入位置及后方元素后移一位
        L->data[j] = L->data[j - 1];
    }

    //插入元素并增加长度
    L->data[i] = e;
    L->length++;
    return true;
}

//删除数据元素
bool ListDelete(SqList *&L, int i, int &e)
{
    int j;
    if (i < 1 || i > L->length + 1)
    {
        return false;
    }
    i--;
    //保存被删除的元素
    e = L->data[i];

    for (j = i; j < L->length - 1; j++)
    {
        L->data[j] = L->data[j + 1];
    }
    L->length--;
    return true;
}

int main(void)
{
    return 0;
}