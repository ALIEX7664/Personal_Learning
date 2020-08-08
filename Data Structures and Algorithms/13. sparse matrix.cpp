/*
*********************************************************************************************************
*                                         稀疏矩阵
*       非零元素个数远小于零元素个数的矩阵，采用三元组的方式压缩矩阵（行，列，元素值)
*       若要将三元组还原为矩阵，需要将矩阵初始化为零矩阵，并将三元组的值填入到矩阵中
*********************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

#define M 5
#define N 5

#define MAXSIZE M *N / 2

typedef int Elemtype;

typedef struct
{
    int r;
    int c;
    Elemtype d;
} TupNode;

typedef struct
{
    int cols;
    int rows;
    int num;
    TupNode data[MAXSIZE];
} TSMartix;

//创建三元组
void CreateMat(TSMartix &t, Elemtype A[M][N])
{
    int i, j;
    t.rows = M;
    t.cols = N;
    t.num = 0;

    //找到非零元素，存入三元组中
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (A[i][j] != 0)
            {
                t.data[t.num].r = i;
                t.data[t.num].c = j;
                t.data[t.num].d = A[i][j];
                t.num++;
            }
        }
    }
}

//赋值三元组元素数据
bool Value(TSMartix &t, Elemtype x, int i, int j)
{
    int k = 0, k1;
    if (i >= t.rows || j >= t.cols)
    {
        return false;
    }

    //到达要赋值的数的行和列
    //但要保持在有效元素数量以内
    while (k < t.num && i > t.data[k].r)
    {
        k++;
    }
    while (k < t.num && i == t.data[k].r && j > t.data[k].c)
    {
        k++;
    }

    //判断是否在三元组中找到相应的元素
    if (t.data[k].r == i && t.data[k].c == j)
    {
        t.data[k].d = x;
    }
    else
    {
        //插入新元素节点到三元组相应位置中
        for (k1 = t.num - 1; k1 > k; k--)
        {
            t.data[k1 + 1].r = t.data[k].r;
            t.data[k1 + 1].c = t.data[k].c;
            t.data[k1 + 1].d = t.data[k].d;
        }
        t.data[k].r = i;
        t.data[k].c = j;
        t.data[k].d = x;
        t.num++;
    }
    return true;
}

//获取三元组内的元素
//由于三元组按行顺序存储非零值
//所以当找不到相应的行和列时即为零值
bool Assign(TSMartix t, Elemtype &x, int i, int j)
{
    int k = 0;
    if (i >= t.rows || j >= t.cols)
    {
        return false;
    }

    //在三元组找到对应的行和列
    while (k < t.num && i > t.data[k].r)
    {
        k++;
    }
    while (k < t.num && i > t.data[k].c)
    {
        k++;
    }

    //根据情况为x赋值
    if (t.data[k].r == i && t.data[k].c == j)
    {
        x = t.data[k].d;
    }
    else
    {
        x = 0;
    }

    return true;
}

//显示三元组数据
void DispMat(TSMartix t)
{
    int k ;

    //不存在非零值
    if(t.num <=0)
    {
        return;
    }
    else
    {
        //遍历三元组，显示所有数据
        printf("\t%d\t%d\t%d\n",t.rows,t.cols,t.num);
        printf("\t------------------------------\n");
        for(k = 0 ; k <t.num;k++)
        {
            printf("\t%d\t%d\t%d\n",t.data[k].r,t.data[k].c,t.data[k].d);
        }
    }
}

//矩阵转置(对三元组中的值转置)
void TranTat(TSMartix t, TSMartix &tb)
{
    int k,k1 = 0,v;
    tb.rows = t.cols;
    tb.cols = t.rows;
    tb.num = t.num;

    //判断是否存在非零值
    if(t.num != 0)
    {
        //遍历旧三元组，将转置结果存入到新元组中
        for(v = 0 ;v<t.num;v++)
        {
            for(k = 0 ;k<t.num;k++)
            {
                if(t.data[k].c == v)
                {
                    tb.data[k1].r = t.data[k].c;
                    tb.data[k1].c = t.data[k].r;
                    tb.data[k1].d = t.data[k].d;
                    k1++;               
                }
            }
        }
    }
}

int main()
{
    return 0;
}
