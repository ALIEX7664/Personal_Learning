/*
*********************************************************************************************************
*                                          迷宫问题-顺序栈（非最优）
*********************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50
#define M 8
#define N 8

//迷宫
int mg[M + 2][N + 2] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

//迷宫格结构体
typedef struct
{
    int x;   //x坐标
    int y;   //y坐标
    int dir; //方向
} Box;

//路径栈
typedef struct
{
    Box data[MAXSIZE];
    int top; //栈顶指针
} SqStack;

//初始化栈
void InitStack(SqStack *&s)
{
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1; //无元素，初始化为-1
}

//入栈
bool Push(SqStack *&s, Box e)
{
    if (s->top == MAXSIZE - 1)
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
bool Pop(SqStack *&s, Box &e)
{
    if (s->top == -1)
    {
        return false;
    }
    else
    {
        e = s->data[(s->top)--];
        return true;
    }
}

bool StackEmpty(SqStack *s)
{
    return (s->top == -1);
}

//获取栈顶元素
bool GetTop(SqStack *s, Box &e)
{
    if (s->top == -1)
    {
        return false;
    }
    else
    {
        e = s->data[s->top];
        return true;
    }
}

//销毁栈
void DestroyStack(SqStack *&s)
{
    free(s);
}

//路径查找
bool mgpath(int xi, int yi, int xe, int ye)
{
    //path用于找到路径存放栈元素，形成正向路径
    Box path[MAXSIZE], e;
    int i, j, dir, i1, j1, k;
    bool find;   //寻找标志位
    SqStack *st; //路径栈

    //相关初始化
    InitStack(st);
    e.x = xi;
    e.y = yi;
    e.dir = -1;

    //入栈入口元素
    Push(st, e);
    //将入口置-1表示为路径元素之一
    mg[xi][yi] = -1;

    while (!StackEmpty(st))
    {
        //获取栈顶元素
        GetTop(st, e);

        //将栈顶信息存放至临时变量
        i = e.x;
        j = e.y;
        dir = e.dir;
        find = false;

        //到达出口
        if (i == xe && j == ye)
        {
            k = 0;
            printf("Find Path:\n");

            //存放栈元素用于输出
            while (!StackEmpty(st))
            {
                Pop(st, e);
                path[k++] = e;
            }

            //输出栈元素
            while (k >= 1)
            {
                k--;
                printf(" (%d,%d)", path[k].x, path[k].y);
                if ((k + 2) % 5 == 0)
                {
                    //每5个换行一次
                    printf("\n");
                }
            }
            printf("\n");
            DestroyStack(st);
            return true;
        }

        //寻找路径方向
        while (dir < 4 && !find)
        {
            dir++;
            switch (dir)
            {
            //上
            case 0:
                i1 = i - 1;
                j1 = j;
                break;
            //右
            case 1:
                i1 = i;
                j1 = j + 1;
                break;
            //下
            case 2:
                i1 = i + 1;
                j1 = j;
                break;
            //左
            case 3:
                i1 = i;
                j1 = j - 1;
                break;
            }

            //找到合法路径
            if (mg[i1][j1] == 0)
                find = true;
        }

        //找到合法路径执行的操作
        if (find)
        {
            //将上一个节点的方向变量设置为对应的方向
            st->data[st->top].dir = dir;
            //获取新元素方向并入栈
            e.x = i1;
            e.y = j1;
            e.dir = -1;
            Push(st, e);

            //将对应占用元素置-1表示被占用
            mg[i1][j1] = -1;
        }
        else
        {
            //将栈顶元素出栈，退回上一个元素，从出栈元素的方向开始逆时针寻找
            Pop(st, e);

            //还原为未占用路径
            mg[e.x][e.y] = 0;
        }
    }

    DestroyStack(st);
    //失败返回
    return false;
}

//显示迷宫
void Dismg()
{
    printf("map:\n");
    for (int i = 0; i < M + 2; i++)
    {
        for (int j = 0; j < N + 2; j++)
        {
            switch (mg[i][j])
            {
            case 1: 
                printf("X ");
                break;
            case 0:
                printf("* ");
                break;
            case -1:
                printf("o ");
                break;
            }
        }
        printf("\n");
    }
}

int main(void)
{
    if (!mgpath(1, 1, M, N))
    {
        printf("error");
    }
    else
    {
        Dismg();
        return 1;
    }

    return 0;
}