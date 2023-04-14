//*********封装的意义*********
//在设计类的时候，属性和行为写在一起，表现事物
//语法： class 类名{ 访问权限： 属性 / 行为 };

#include<iostream>
using namespace std;

//学生类
class Student {
//屬性
public:
	string m_name;
	int m_id;

//行為
public:
	void setName(string name) {
		m_name = name;
	}
	void setID(int id) {
		m_id = id;
	}
	void showStudent() {
		cout << "name:" << m_name << " ID:" << m_id << endl;
	}
};

int main() {
	//創建一個具體學生
	Student stu;
	//給stu對象，進行一個賦予值的操作
	stu.setName("德玛西亚");
	stu.setID(250);
	//顯示學生信息
	stu.showStudent();


	//創建一個具體學生
	Student stu2;
	//給stu對象，進行一個賦予值的操作
	stu.setName("李四");
	stu.setID(299);
	//顯示學生信息
	stu.showStudent();


	system("pause");

	return 0;
}
