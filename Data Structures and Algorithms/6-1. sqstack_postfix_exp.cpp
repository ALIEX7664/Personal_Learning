/*
*********************************************************************************************************
*                                       简单表达式
*********************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

//可拓展
#define MAXSIZE 20
typedef char ElemType;
typedef double ElemType1;

typedef struct
{
    ElemType data[MAXSIZE];
    int top; //栈顶指针
} SqStack;

typedef struct
{
    ElemType1 data[MAXSIZE];
    int top; //栈顶指针
} SqStack1;

//初始化栈
void InitStack(SqStack *&s)
{
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1; //无元素，初始化为-1
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
bool Push(SqStack *&s, ElemType e)
{
    //栈满检查
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
bool Pop(SqStack *&s, ElemType &e)
{
    //有无元素检查
    if (s->top == -1)
    {
        return false;
    }
    else
    {
        //取得栈顶元素后top--
        e = s->data[s->top--];
        return true;
    }
}

//取栈顶元素
bool GetTop(SqStack *s, ElemType &e)
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

//初始化栈
void InitStack1(SqStack1 *&s)
{
    s = (SqStack1 *)malloc(sizeof(SqStack1));
    s->top = -1; //无元素，初始化为-1
}

//销毁栈
void DestroyStack1(SqStack1 *&s)
{
    free(s);
}

//判断是否为空
bool StackEmpty1(SqStack1 *s)
{
    return (s->top == -1);
}

//进栈
bool Push1(SqStack1 *&s, ElemType1 e)
{
    //栈满检查
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
bool Pop1(SqStack1 *&s, ElemType1 &e)
{
    //有无元素检查
    if (s->top == -1)
    {
        return false;
    }
    else
    {
        //取得栈顶元素后top--
        e = s->data[s->top--];
        return true;
    }
}

//取栈顶元素
bool GetTop1(SqStack1 *s, ElemType1 &e)
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

void trans(char *exp, ElemType postexp[])
{
    //定义与初始化操作数栈
    ElemType e;
    SqStack *Optr;
    InitStack(Optr);
    int i = 0;

    //遍历表达式字符串
    while (*exp != '\0')
    {
        switch (*exp)
        {
        case '(':
            //左括号直接入栈
            Push(Optr, *exp);
            exp++;
            break;

        case ')':
            //右括号出栈操作符并存入表达式中
            Pop(Optr, e);

            //到达左括号时出栈并结束,左括号无需存入表达式
            while (e != '(')
            {
                postexp[i++] = e;
                Pop(Optr, e);
            }
            exp++;
            break;

     
        case '-':
        case '+':
            //判断栈是否为空
            while (!StackEmpty(Optr))
            {
                //获取头部元素
                GetTop(Optr, e);

                //出栈在当前操作符前的所有操作符，直到括号或栈空为指
                //因为：'+'和'-'的优先级是最低的，所以之前的操作符都可以加入表达式运算
                if (e != '(')
                {
                    Pop(Optr, e);
                    postexp[i++] = e;
                }
                else
                {
                    break;
                }
            }

            //入栈当前运算符
            Push(Optr, *exp);
            exp++;
            break;
        case '*':
        case '/':
            while (!StackEmpty(Optr))
            {
                //获取栈顶元素
                GetTop(Optr, e);

                //比起'+'和'-','*'和'/'的优先级更高，所以要将'*'和'/'的操作符先出栈
                //'+'和'-'不需要提前出栈，其在一个优先级括号内在最后才参与运算
                if (e != '(' && e != '+' && e != '-')
                {
                    Pop(Optr, e);
                    postexp[i++] = e;
                }
                else
                {
                    break;
                }
            }

            Push(Optr, *exp);
            exp++;
            break;
        default:
            //若为数字则直接加入到后缀表达式中
            while (*exp >= '0' && *exp <= '9')
            {
                postexp[i++] = *exp;
                exp++;
            }
            //使用'#'区分每个数字
            postexp[i++] = '#';
        }
        
    }

    //将余下的元素出栈
    while (!StackEmpty(Optr))
    {
        Pop(Optr, e);
        postexp[i++] = e;
    }
    //加上结束符
    postexp[i] = '\0';
    DestroyStack(Optr);
}

double compuvalue(ElemType *postexp)
{
    ElemType1 a, b, c, d, e;
    SqStack1 *Opnd;
    InitStack1(Opnd);

    while (*postexp != '\0')
    {
        switch (*postexp)
        {
        //进行运算并存入栈中
        case '+':
            Pop1(Opnd, a);
            Pop1(Opnd, b);
            Push1(Opnd, a + b);
            break;

        case '-':
            Pop1(Opnd, a);
            Pop1(Opnd, b);
            Push1(Opnd, b - a);
            break;

        case '*':
            Pop1(Opnd, a);
            Pop1(Opnd, b);
            Push1(Opnd, a * b);
            break;

        case '/':
            Pop1(Opnd, a);
            Pop1(Opnd, b);

            //判断分母是否为0
            if (a != '0')
            {
                Push1(Opnd, b / a);
                break;
            }
            else
            {
                printf("error");
                exit(-1);
            }
        default:
            d = 0; //用于计算其为几位数
            //单个数字运算
            while (*postexp >= '0' && *postexp <= '9')
            {
                d = 10 * d + *postexp - '0';
                postexp++;
            }
            Push1(Opnd, d);
            break;
        }
        postexp++;
    }

    //获取最终计算结果
    GetTop1(Opnd, e);
    DestroyStack1(Opnd);
    return e;
}

int main(int argc, char *argv[])
{
    char postexp[MAXSIZE];

    //转换为后缀表达式
    trans(argv[1],postexp);
    printf("infix exp: %s\n", argv[1]);
    printf("postfix exp:%s\n", postexp );
    printf("result:%lf\n",compuvalue(postexp));
     return 0;
}