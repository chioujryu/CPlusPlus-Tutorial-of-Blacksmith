//*********初始化列表*********
//作用：C++提供了初始化列表语法，用来初始化属性
//當然，你也可以用傳統方式來做初始化
//這只是另一種初始化的方式
//語法：构造函数()：属性1(值1),属性2（值2）... {}

#include<iostream>
using namespace std;

class Person {
public:

	////传统方式初始化
	//Person(int a, int b, int c) {
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}

	//初始化列表方式初始化
	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}
	void PrintPerson() {
		cout << "mA:" << m_A << endl;
		cout << "mB:" << m_B << endl;
		cout << "mC:" << m_C << endl;
	}
private:
	int m_A;
	int m_B;
	int m_C;
};

int main() {

	Person p(1, 2, 3);
	p.PrintPerson();

	system("pause");

	return 0;
}