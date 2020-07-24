/*
*********************************************************************************************************
*											������
*********************************************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
} LinkNode;

//��ʼ��������
void InitList(LinkNode *&L)
{
	//ͷ�ڵ㴴��
	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = NULL;
}

//���ٵ�����
void DestroyList(LinkNode *&L)
{
	//��ȡͷ�ڵ���׽ڵ�
	LinkNode *pre = L, *p = L->next;

	while (p != NULL)
	{
		free(pre);	   //�ͷ�ǰ�ڵ�
		pre = p;	   //ǰ�ڵ�ָ��ָ���¸��ڵ�
		p = pre->next; //�½ڵ�ָ��ָ�����¸��ڵ�
	}
}

//�жϵ������Ƿ�Ϊ��
bool ListEmpty(LinkNode *L)
{
	//�鿴�Ƿ����׽ڵ�
	return (L->next == NULL);
}

//�鿴��������
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

//��ʾ��������������Ԫ��
void DispList(LinkNode *L)
{
	LinkNode *p = L->next; //ָ���׽ڵ�

	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}

//������Ż�ȡԪ��ֵ
bool GetElem(LinkNode *L, int i, int &e)
{
	//��malloc������ͷ�ڵ㲻Ϊ��
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

//����Ԫ��ֵ���ҽ��
int LocateElem(LinkNode *L, int &e)
{
	int i = 1;
	LinkNode *p = L->next;

	//���ݵ�ǰ�ڵ��Ƿ�Ϊ���Լ�������ж��Ƿ��������
	while (p != NULL && p->data != e)
	{
		i++;
		p = p->next;
	}

	//�����Ƿ���ڽ�㣬�������
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		return i;
	}
}

//����ڵ�
bool ListInsert(LinkNode *&L, int i, int e)
{
	int j = 0;
	LinkNode *p = L, *s;
	if (i <= 0)
	{
		return false;
	}

	//������ź���������i-1λ��
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}

	//�ڲ��ҵ�i-1�����г��ֿս�㣬��i̫��
	if (p == NULL)
	{
		return false;
	}
	else
	{
		//�����м������β������
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = e;
		p->next = s->next; //��p�ĺ��ָ���򸳸�s
		p->next = s;	   //��s�����������м�
		return true;
	}
}

//ɾ�����
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