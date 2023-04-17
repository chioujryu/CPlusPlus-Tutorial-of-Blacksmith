//*********靜態成員函數*********

#include<iostream>
using namespace std;

class Person
{

public:

	//静态成员函数特点：
	//1 所有對象共享一个函数
	//2 静态成员函数只能访问静态成员变量
	
	static void func()
	{
		cout << "func调用" << endl;
		m_A = 100;	//靜態成員函數可以訪問靜態成員變量
		//m_B = 100; //错误，不可以访问非静态成员变量，無法缺分到底是哪個對象的m_B
	}

	static int m_A; //静态成员变量
	int m_B; // 
private:

	//静态成员函数也是有访问权限的
	static void func2()
	{
		cout << "func2调用" << endl;
	}
};
int Person::m_A = 10;


void test01()
{
	//静态成员变量两种访问方式

	//1、通过对象進行訪問
	Person p1;
	p1.func();

	//2、通过类名進行訪問
	Person::func();


	//Person::func2(); //類外訪問不到私有权限的靜態函數
}

int main() {

	test01();

	system("pause");

	return 0;
}