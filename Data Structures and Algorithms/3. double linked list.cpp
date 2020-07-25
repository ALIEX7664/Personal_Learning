/*
*********************************************************************************************************
*                                      双链表
*********************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct DNode{
    int data;
    DNode *prior;   //前驱结点
    DNode *next;    //后驱结点
}DLinkNode;

//初始化双链表
void InitList(DLinkNode *&L)
{
	//头节点创建
	L = (DLinkNode *)malloc(sizeof(DLinkNode));
	L->next = NULL;
    L->prior = NULL;
}

//销毁双链表
void DestroyList(DLinkNode *&L)
{
	//获取头节点和首节点
	DLinkNode *pre = L, *p = L->next;

	while (p != NULL)
	{
		free(pre);	   //释放前节点
		pre = p;	   //前节点指针指向下个节点
		p = pre->next; //下节点指针指向下下个节点
	}
}

//判断双链表是否为空
bool ListEmpty(DLinkNode *L)
{
	//查看是否有首节点
	return (L->next == NULL);
}


//查看双链表长度
int ListLength(DLinkNode *L)
{
	int n = 0;
	DLinkNode *p = L;

	while (p->next != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}

//显示链表中所有数据元素
void DispList(DLinkNode *L)
{
	DLinkNode *p = L->next; //指向首节点

	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}

//根据序号获取元素值
bool GetElem(DLinkNode *L, int i, int &e)
{
	//由malloc创建的头节点不为空
	DLinkNode *p = L;
	int j = 0;
	while (j < i && p != NULL)
	{
		j++;
		p = p->next;
	}

	if (p == NULL)
	{
		return false;
	}
	else
	{
		e = p->data;
		return true;
	}
}

//根据元素值查找结点
int LocateElem(DLinkNode *L, int &e)
{
	int i = 1;
	DLinkNode *p = L->next;

	//根据当前节点是否为空以及结果，判断是否继续遍历
	while (p != NULL && p->data != e)
	{
		i++;
		p = p->next;
	}

	//根据是否存在结点，返回序号
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		return i;
	}
}

//插入节点
bool ListInsert(DLinkNode *&L, int i, int e)
{
	int j = 0;
	DLinkNode *p = L, *s;
	if (i <= 0)
	{
		return false;
	}

	//根据序号和条件到达i-1位置
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}

	//在查找到i-1过程中出现空结点，即i太大
	if (p == NULL)
	{
		return false;
	}
	else
	{
		//考虑中间插入与尾部插入
		s = (DLinkNode *)malloc(sizeof(DLinkNode));
		s->data = e;
		p->next = s->next; //将p的后继指针域赋给s
        if(p->next != NULL)
        {
            p->next->prior = s; 
        }
        s->prior = p;       
		p->next = s;	   //将s插入在链表中间
		return true;
	}
}

bool ListDelete(DLinkNode *&L, int i, int &e)
{
	int j = 0;
	DLinkNode *p = L, *q;

	if (i <= 0)
	{
		return false;
	}

	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}

	if (p == NULL)
	{
		return false;
	}
	else
	{
		q = p->next;
		if (q == NULL)
		{
			return false;
		}
		e = q->data;
        q->next->prior = p; //将后结点前驱指针指向删除结点前结点
		p->next = q->next;  //获取删除结点后结点
		free(q);
		return true;
	}
}

int main(void)
{
    return 0;
}