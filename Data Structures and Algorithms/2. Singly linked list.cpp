#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct Link {

	char elem;
	struct Link *next; //指向下一节点

}link;

link* initLink()
{
	link *p = NULL; //头指针
	link *temp = (link*)malloc(sizeof(link)); //首元节点
	temp->elem = 1;		//若有头节点无需此
	temp->next = NULL;	//若有头节点无需此
	p = temp; //指向头节点
	for (int i = 2 ; i < SIZE ; i++)
	{
		link* a = (link*)malloc(sizeof(link));
		a->elem = i;
		a->next = NULL;
		temp->next = a;
		temp = temp->next;//使下次循环temp为a
	}
	
	return p;

}

/* 带有头节点情况 */
//void display(link* p) {
//	link* temp = p;//将temp指针重新指向头结点
//	//只要temp指针指向的结点的next不是Null，就执行输出语句。
//	while (temp->next) {
//		temp = temp->next;
//		printf("%d", temp->elem);
//	}
//	printf("\n");
//}


void display(link* p)
{
	link* temp = p; //定义链表存储p，防止p中途发生变化，导致数值输出错误
	while (temp)
	{
	
			printf("%d", temp->elem);
			temp = temp->next;
			
	}
	printf("\n");
}

link* inserElem(link* p, int elem, int add) //p是原链表
{
	link *temp = p;
	for (int i = 1;i < add; i++)
	{
		temp = temp->next;  //通过循环使之找到插入的上个结点
		if (temp == NULL) {
			printf("Insert invalid\n");
			return p;
		}
	}
	
	link* c = (link*)malloc(sizeof(link));
	c  -> elem = elem;
	c->next = temp->next; //使C的后节点指向前节点的后节点，实现插入
	temp->next = c;	//使前节点指向C，以上两句顺序不能颠倒

	return p;

}

//p为原链表，elem表示被查找元素、
int selectElem(link* p, int elem) { 
	//新建一个指针t，初始化为头指针 p
	link* t = p;
	int i = 1;
	//由于头节点的存在，因此while中的判断为t->next

	while (t) {		//若有头节点改为t->next
		if (t->elem == elem) {
			return i;	//返回节点位置
		}
		t = t->next;
		i++;
	}
	//程序执行至此处，表示查找失败
	return -1;
}


//更新函数，其中，add 表示更改结点在链表中的位置，newElem 为新的数据域的值
link* amendElem(link* p, int add, int newElem) {			//只需修改值，无需修改next指向
	link* temp = p;	//指向首元节点

	//temp = temp->next; //若有头节点要加上此句
	//遍历到待更新结点

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


