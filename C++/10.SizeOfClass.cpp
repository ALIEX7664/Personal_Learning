#include <iostream>

using namespace std;


struct Student{
//private:
	
	char j;
	short i;
	char *p;
	
	/*char *m_name;
	int m_age;
	float m_score;*/
/*public:
	void setname(char *name);
	void setage(int age);
	void setscore(float score);
	void show()*/;
};
//void Student::setname(char *name){
//	m_name = name;
//}
//void Student::setage(int age){
//	m_age = age;
//}
//void Student::setscore(float score){
//	m_score = score;
//}
//void Student::show(){
//	cout << m_name << "��������" << m_age << "���ɼ���" << m_score << endl;
//}
int main(){
	//��ջ�ϴ�������
	Student stu;
	cout << sizeof(stu) << endl;
	//�ڶ��ϴ�������
	Student *pstu = new Student();
	cout << sizeof(*pstu) << endl;
	//��Ĵ�С
	cout << sizeof(Student) << endl;
	return 0;
}