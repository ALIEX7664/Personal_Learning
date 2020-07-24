/*
*********************************************************************************************************
*											单链表
*********************************************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
} LinkNode;

//初始化单链表
void InitList(LinkNode *&L)
{
	//头节点创建
	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = NULL;
}

//销毁单链表
void DestroyList(LinkNode *&L)
{
	//获取头节点和首节点
	LinkNode *pre = L, *p = L->next;

	while (p != NULL)
	{
		free(pre);	   //释放前节点
		pre = p;	   //前节点指针指向下个节点
		p = pre->next; //下节点指针指向下下个节点
	}
}

//判断单链表是否为空
bool ListEmpty(LinkNode *L)
{
	//查看是否有首节点
	return (L->next == NULL);
}

//查看单链表长度
int ListLength(LinkNode *L)
{
	int n = 0;
	LinkNode *p = L;

	while (p->next != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}

//显示链表中所有数据元素
void DispList(LinkNode *L)
{
	LinkNode *p = L->next; //指向首节点

	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}

//根据序号获取元素值
bool GetElem(LinkNode *L, int i, int &e)
{
	//由malloc创建的头节点不为空
	LinkNode *p = L;
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
int LocateElem(LinkNode *L, int &e)
{
	int i = 1;
	LinkNode *p = L->next;

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
bool ListInsert(LinkNode *&L, int i, int e)
{
	int j = 0;
	LinkNode *p = L, *s;
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
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = e;
		p->next = s->next; //将p的后继指针域赋给s
		p->next = s;	   //将s插入在链表中间
		return true;
	}
}

//删除结点
bool ListDelete(LinkNode *&L, int i, int &e)
{
	int j = 0;
	LinkNode *p = L, *q;

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
		p->next = q->next;
		free(q);
		return true;
	}
}

int main(void)
{
	return 0;
}