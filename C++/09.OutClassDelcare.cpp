/* 类体外声明函数
*	加 "::"表明是类Student的作用域
*/

#include <iostream>

using namespace std;

class Student{
public:
	//成员变量
	char *name;
	int age;
	float score;
	//成员函数
	void say();  //函数声明
};
//函数定义
void Student::say(){
	cout << name << "的年龄是" << age << "，成绩是" << score << endl;
}

int main(){
	Student *pStu = new Student;
	pStu->name = "小明";
	pStu->age = 15;
	pStu->score = 92.5f;
	pStu->say();
	delete pStu;  //删除对象
	return 0;
}