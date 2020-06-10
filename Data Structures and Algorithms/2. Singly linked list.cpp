#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct Link {

	char elem;
	struct Link *next; //ָ����һ�ڵ�

}link;

link* initLink()
{
	link *p = NULL; //ͷָ��
	link *temp = (link*)malloc(sizeof(link)); //��Ԫ�ڵ�
	temp->elem = 1;		//����ͷ�ڵ������
	temp->next = NULL;	//����ͷ�ڵ������
	p = temp; //ָ��ͷ�ڵ�
	for (int i = 2 ; i < SIZE ; i++)
	{
		link* a = (link*)malloc(sizeof(link));
		a->elem = i;
		a->next = NULL;
		temp->next = a;
		temp = temp->next;//ʹ�´�ѭ��tempΪa
	}
	
	return p;

}

/* ����ͷ�ڵ���� */
//void display(link* p) {
//	link* temp = p;//��tempָ������ָ��ͷ���
//	//ֻҪtempָ��ָ��Ľ���next����Null����ִ�������䡣
//	while (temp->next) {
//		temp = temp->next;
//		printf("%d", temp->elem);
//	}
//	printf("\n");
//}


void display(link* p)
{
	link* temp = p; //��������洢p����ֹp��;�����仯��������ֵ�������
	while (temp)
	{
	
			printf("%d", temp->elem);
			temp = temp->next;
			
	}
	printf("\n");
}

link* inserElem(link* p, int elem, int add) //p��ԭ����
{
	link *temp = p;
	for (int i = 1;i < add; i++)
	{
		temp = temp->next;  //ͨ��ѭ��ʹ֮�ҵ�������ϸ����
		if (temp == NULL) {
			printf("Insert invalid\n");
			return p;
		}
	}
	
	link* c = (link*)malloc(sizeof(link));
	c  -> elem = elem;
	c->next = temp->next; //ʹC�ĺ�ڵ�ָ��ǰ�ڵ�ĺ�ڵ㣬ʵ�ֲ���
	temp->next = c;	//ʹǰ�ڵ�ָ��C����������˳���ܵߵ�

	return p;

}

//pΪԭ����elem��ʾ������Ԫ�ء�
int selectElem(link* p, int elem) { 
	//�½�һ��ָ��t����ʼ��Ϊͷָ�� p
	link* t = p;
	int i = 1;
	//����ͷ�ڵ�Ĵ��ڣ����while�е��ж�Ϊt->next

	while (t) {		//����ͷ�ڵ��Ϊt->next
		if (t->elem == elem) {
			return i;	//���ؽڵ�λ��
		}
		t = t->next;
		i++;
	}
	//����ִ�����˴�����ʾ����ʧ��
	return -1;
}


//���º��������У�add ��ʾ���Ľ���������е�λ�ã�newElem Ϊ�µ��������ֵ
link* amendElem(link* p, int add, int newElem) {			//ֻ���޸�ֵ�������޸�nextָ��
	link* temp = p;	//ָ����Ԫ�ڵ�

	//temp = temp->next; //����ͷ�ڵ�Ҫ���ϴ˾�
	//�����������½��

	for (int i = 1; i < add; i++) {
		temp = temp->next;
	}
	temp->elem = newElem;
	return p;
}

int main()
{
	link* p = initLink();
	display(p);


	p = inserElem(p, 9, 3);
	display(p);

	p = inserElem(p, 3, 9);
	display(p);

	int i = selectElem(p, 9);
	printf("%d \n", i);

	p = amendElem(p, 3, 7);
	display(p);
	return 0;
}


