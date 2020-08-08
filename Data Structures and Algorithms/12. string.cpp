/*
*********************************************************************************************************
*                                           顺序串
*********************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

//串结构体
typedef struct 
{
    char data[MAXSIZE];
    int length;
}SqString;

//分配顺序串
void StrAssign(SqString &s,char str[])
{
    int i;
    for(i = 0 ; str[i] != '\0';i++)
    {
        s.data[i] = str[i];
    }
    s.length = i;
}

//销毁顺序串
void DestroyStr(SqString &s)
{
    return;
}

//复制字符串
void StrCopy(SqString &s,SqString t)
{
    int i;
    for(i = 0 ; i < t.length;i++)
    {
        s.data[i] = t.data[i];
    }
    s.length = t.length;
}

bool StrEqual(SqString s,SqString t)
{
    int i;

    //先比较是否相同
    if(s.length != t.length)
    {
        return false;
    }
    else
    {
        //遍历字符串，判断各自符是否相同
        for(int i = 0 ; i < s.length;i++)
        {
            if(s.data[i] != t.data[i])
            {
                return false;
            }
        }
    }
    return true;
}
int main(void)
{
    return 0;
}


