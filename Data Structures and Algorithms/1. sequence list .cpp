#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50 //�������Ԫ������

//���Ա�ṹ��
typedef struct
{
    int data[MAXSIZE];
    int length;
} SqList;

//�������Ա�
void CreateList(SqList *&L, int a[], int n)
{
    int i = 0;
    L = (SqList *)malloc(sizeof(SqList)); //�������Ա�洢�ռ�
    while (i < n)
    {
        L->data[i] = a[i]; //�����ݰ�iɨ��a���������Ա�
        i++;
    }
    L->length = n; //��¼����
}

//��ʼ�����Ա�
void InitList(SqList *&L)
{
    L = (SqList *)malloc(sizeof(SqList));
    L->length = 0; //��ʼ������Ϊ0
}

//�������Ա�
void DestroyList(SqList *L)
{
    free(L);
}

//�ж����Ա��Ƿ�Ϊ�ձ�
bool ListEmpty(SqList *L)
{
    return (L->length == 0);
}

//�����Ա���
int ListLength(SqList *L)
{
    return L->length;
}

//������Ա�
void DispList(SqList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d", L->data[i]);
    }
    printf("\n");
}

//�����Ա���ĳ������Ԫ��ֵ
bool GetElem(SqList *L, int i, int &e)
{
    //�����ж�
    if (i < 1 || i > L->length)
    {
        return false;
    }
    //��ȡԪ��
    e = L->data[i - 1];
    return true;
}

//��Ԫ��ֵ����
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
        return i + 1; //�����������꣬�±�+1
    }
}

//��������Ԫ��
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
        //������λ�ü���Ԫ�غ���һλ
        L->data[j] = L->data[j - 1];
    }

    //����Ԫ�ز����ӳ���
    L->data[i] = e;
    L->length++;
    return true;
}

//ɾ������Ԫ��
bool ListDelete(SqList *&L, int i, int &e)
{
    int j;
    if (i < 1 || i > L->length + 1)
    {
        return false;
    }
    i--;
    //���汻ɾ����Ԫ��
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