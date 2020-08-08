/*
**********************************************************************************************************
*                                      迷宫问题-最短路径-顺序队
*       从起点开始，按一定的时钟方向，逐个查看旁边的节点，并将这些节点置为-1，表示已经被查看过，而前节点作为
*   父节点，从子节点开始并重复上述过程。
*       当到达出口时停止该过程，再从出口节点出发，通过父节点回头查找得到的路径，即为最短路径，也是算法该到达
*   节点时的最短时间复杂度路径。
*       e.g                            （1,1）
*                                         |             1.出栈父节点，找到出栈节点附近没有被置-1的附近节点         
*                                         |             2.将这些子节点置-1并入栈
*                                  (2,1)—— ——(1,2)      3.将子节点出栈，并查找所有子节点附近节点，重复过程
*       
*       注意：由于循环队列可能会覆盖节点，所以采用顺序队，所以队列空间要足够大，最好是可走节点数的数值，或者为
*       迷宫 —— 长*宽 的大小的数值
*
**********************************************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>



#define M 8
#define N 8
#define MAXSIZE M *N //设定队大小为迷宫大小

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

typedef struct
{
    int x;   //x坐标
    int y;   //y坐标
    int pre; //前节点下标
} Box;

//队列结构体
typedef struct
{
    Box data[MAXSIZE];
    //front队首指向元素前一个位置
    //rear队尾指向最后一个元素
    int front, rear;
} SqQueue;

typedef Box ElemType;

//初始化队
void InitQueue(SqQueue *&q)
{
    q = (SqQueue *)malloc(sizeof(SqQueue));
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
    if (q->rear == MAXSIZE - 1)
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
bool deQueue(SqQueue *&q, ElemType &e)
{
    //队空判断
    if (q->front == q->rear)
    {
        return false;
    }
    else
    {
        e = q->data[++(q->front)];
        return true;
    }
}

//路径输出
void print(SqQueue *q, int front)
{
    //获取出口节点的坐标，此时队列首节点为出口节点
    int k = front, j, ns = 0;
    printf("\n");

    //从出口遍历到入口，找到路径所有节点
    do
    {
        j = k;
        k = q->data[k].pre;

        //将节点的前节点下标置-1，作为标记
        q->data[j].pre = -1;
    } while (k != 0);

    printf("Path:\n");

    //遍历队列数组，前节点为-1的坐标，得到路径
    while(k<MAXSIZE)
    {
        if(q->data[k].pre == -1)
        {
            ns++;
            printf("\t(%d,%d)",q->data[k].x,q->data[k].y);
            if(ns%5 == 0)
            {
                printf("\n");
            }
        }
        k++;
    }
    printf("\n");

}

//路径求解
bool mgpath(int xi, int yi, int xe, int ye)
{
    Box e;
    int i, j, dir, i1, j1;
    SqQueue *qu;

    //初始化栈
    InitQueue(qu);
    e.x = xi;
    e.y = yi;
    e.pre = -1;
      
    //入栈入口节点  p
    enQueue(qu, e);
    mg[xi][yi] = -1;

    //通过出队元素进行操作，判断路径
    while (!QueueEmpty(qu))
    {
        //出队，但实际上是把头指针往后移，所以元素还在队/数组中
        deQueue(qu, e);
        i = e.x;
        j = e.y;

        //到达出口节点时，输出路径
        if (i == xe && j == ye)
        {
            print(qu,qu ->front);
            DestroyQueue(qu);
            return true;
        }

        //将节点四个方向的坐标一一进行判断
        for (dir = 0; dir < 4; dir++)
        {
            switch (dir)
            {
            case 0:
                i1 = i - 1;
                j1 = j;
                break;
            case 1:
                i1 = i;
                j1 = j + 1;
                break;
            case 2:
                i1 = i + 1;
                j1 = j;
                break;
            case 3:
                i1 = i;
                j1 = j - 1;
                break;
            }
            //可走节点的操作
            if (mg[i1][j1] == 0)
            {
               
                //将节点入队
                e.x = i1;
                e.y = j1;
                e.pre = qu->front;
                enQueue(qu, e);
                  
                //将路径置为已查找
                mg[i1][j1] = -1;
               
            }
        }
    }

    //找不到到达终点的路径
    DestroyQueue(qu);
    return false;
}




int main(void)
{
    if(!mgpath(1,1,M,N))
    {
        printf("error");
        return -1;
    }
    return 1;
}