/* ��������������
*	�� "::"��������Student��������
*/

#include <iostream>

using namespace std;

class Student{
public:
	//��Ա����
	char *name;
	int age;
	float score;
	//��Ա����
	void say();  //��������
};
//��������
void Student::say(){
	cout << name << "��������" << age << "���ɼ���" << score << endl;
}

int main(){
	Student *pStu = new Student;
	pStu->name = "С��";
	pStu->age = 15;
	pStu->score = 92.5f;
	pStu->say();
	delete pStu;  //ɾ������
	return 0;
}