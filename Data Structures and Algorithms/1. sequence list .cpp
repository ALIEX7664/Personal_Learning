//#include <stdio.h>
//#include <stdlib.h>
//
//
//
//#define Size 5
//
//
//
//typedef struct Table{
//	int *head;
//	int length;
//	int size;
//}table;
//
//
//
//table initTable()  //初始化
//{
//	table t;
//	t.head = (int*)malloc(Size * sizeof(int));
//	if (!t.head)
//	{
//		perror("");
//		exit(0);
//	}
//
//	t.length = 0;
//	t.size = Size;
//	return t;
//}
//
//void displayTable(table t)  //显示所有元素
//{
//	for (int i = 0; i < t.length; i++)
//	{
//		printf("%d", t.head[i]);
//	}
//
//	printf("\n");
//}
//
//table addTable(table t, int elem, int add) //添加元素在指定地方
//{
//	if ( (add > t.length + 1) || (add < 1))
//	{
//		printf("error \n");
//		return t;
//	}
//	 
//	if (t.size == t.length)
//	{
//		t.head = (int*)realloc(t.head, (t.size + 1) * sizeof(int)); //增加新空间
//		if (!t.head)
//		{
//			printf("realloc error");
//			return t;
//		}
//
//		t.size++;
//	}
//
//	for (int i = t.length - 1; i >= add - 1; i--)
//	{
//		t.head[i + 1] = t.head[i];
//	}
//
//	t.head[add - 1] = elem;
//	t.length++;
//	return t;
//
//}
//
//table delTable(table t, int del)	//删除指定位置元素
//{
//	if (del > t.length || del < 1)
//	{
//		printf("error");
//		return t;
//	}
//	else
//	{
//		for (int i = del - 1; i < t.length - 1; i++)
//		{
//			t.head[i] = t.head[i + 1];
//		}
//
//		t.length--;
//	}
//
//	return t;
//}
//
//int selectTable(table t, int elem)	//查找元素位置
//{
//	for (int i = 0; i < t.length;i++)
//	{
//		if (t.head[i] == elem)
//		{
//			return i + 1;
//		}
//
//	}
//	return -1; //表示出错
//}
// 
//table amendTable(table t, int elem, int newElem)	//修改元素为新元素
//{
//	int add = selectTable(t, elem);
//	t.head[add - 1] = newElem;
//	return t;
//}
//
//int main()
//{
//	table t = initTable();
//	for (int i = 0;  i < Size; i++)
//	{
//		t.head[i] = i + 1;
//		t.length++;
//	}
//	displayTable(t);
//	t = addTable(t, 2, 1);
//	displayTable(t);
//
//	t = delTable(t, 1);
//	displayTable(t);
//
//	int add = selectTable(t, 2);
//	printf("%d\n", add);
//
//	t = amendTable(t, 2, 7);
//	displayTable(t);
//
//	return 0;
//}
//
