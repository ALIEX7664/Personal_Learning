///* 类指针
//	非指针用 "."
//	指针用 " -> "
//	在栈上创建出来的对象都有一个名字，比如 stu，使用指针指向它不是必须的。
//	但是通过 new 创建出来的对象就不一样了，它在堆上分配内存，没有名字，只能得到一个指向它的指针，
//	所以必须使用一个指针变量来接收这个指针，否则以后再也无法找到这个对象了，更没有办法使用它。
//	也就是说，使用 new 在堆上创建出来的对象是匿名的，没法直接使用，必须要用一个指针指向它，
//	再借助指针来访问它的成员变量或成员函数。
//
//	栈内存是程序自动管理的，不能使用 delete 删除在栈上创建的对象；堆内存由程序员管理，
//	对象使用完毕后可以通过 delete 删除。
//	在实际开发中，new 和 delete 往往成对出现，以保证及时删除不再使用的对象，防止无用内存堆积。
//*/
//
//
//#include <iostream>
//using namespace std;
//class Student{
//public:
//	char *name;
//	int age;
//	float score;
//	void say(){
//		cout << name << "的年龄是" << age << "，成绩是" << score << endl;
//	}
//};
//int main(){
//	Student *pStu = new Student;
//	pStu->name = "小明";
//	pStu->age = 15;
//	pStu->score = 92.5f;
//	pStu->say();
//	delete pStu;  //删除对象
//	return 0;
//}