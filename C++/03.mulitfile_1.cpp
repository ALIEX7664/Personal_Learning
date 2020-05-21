///*
// c++全局变量和const变量的作用域是相同的，但可见程度不同，全局变量的作用域可以是其他文件，可以被其他文件识别
// 但const会导致当前变量作用域此时只在文件中
// 我们可以通过把const变量添加到头文件来进行调用
//
// */
//
//#include <stdio.h>
//
//int n = 10; //若修改为const  int 则会报错 
//void func();
//
//int main()
//{
//	func();
//	printf("%d\n", n);
//	return 0;
//}