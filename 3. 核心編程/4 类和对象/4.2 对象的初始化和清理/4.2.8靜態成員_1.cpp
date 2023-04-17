//*********靜態成員變量*********

#include<iostream>
using namespace std;

//人類
class Person
{
	
public:

	static int m_A; //静态成员变量

	//静态成员变量特点：
	//1 在编译之前就已經分配内存，並分配在全局區
	//2 类内声明，类外初始化
	//3 所有对象共享同一份数据

//静态成员变量也是有访问权限的
private:
	static int m_B; 
};

int Person::m_A = 10;
int Person::m_B = 10;

void test01()
{
	//静态成员变量两种访问方式

	//1、通过对象
	Person p1;
	p1.m_A = 100;
	cout << "p1.m_A = " << p1.m_A << endl;

	Person p2;
	p2.m_A = 200;
	cout << "p1.m_A = " << p1.m_A << endl; //共享同一份数据
	cout << "p2.m_A = " << p2.m_A << endl;

	//2、通过类名
	cout << "m_A = " << Person::m_A << endl;


	//cout << "m_B = " << Person::m_B << endl; //私有权限访问不到
}

void test02(){
	//靜態成員變亮不屬於某個對象上，所有對象都共享同一份數據
	//因此靜態成員變量有兩種訪問方式

	//1. 通過對象進行訪問
	Person p;
	cout<<p.m_A<<endl;

	//2. 通過類名進行訪問
	cout<<Person::m_A<<endl;

	//cout << "m_B = " << Person::m_B << endl; //私有权限访问不到

}

int main() {

	test02();

	system("pause");

	return 0;
}