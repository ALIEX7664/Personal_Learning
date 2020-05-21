///*
//在C++中，建议使用 new 和 delete 来管理内存，
//它们可以使用C++的一些新特性，
//最明显的是可以自动调用构造函数和析构函数
//*/
//
//
//#include <stdio.h>
//#include <iostream> //或#include<malloc.h>
//using namespace std;
//
//int main()
//{
//	int *a = (int*)malloc(sizeof(int) * 10);//分配10个
//	free(a);
//
//	int *b = new int[10]; //分配10个int空间
//
//	
//	cout << _msize(b) /sizeof(int) << endl; //_msize返回字节数
//
//	delete(b);
//
//
//	return 0;
//
//}