//**************赋值运算符重载**************
//c++编译器至少给一个类添加4个函数
//1. 默认构造函数(无参，函数体为空)
//2. 默认析构函数(无参，函数体为空)
//3. 默认拷贝构造函数，对属性进行值拷贝
//4. 赋值运算符 operator=, 对属性进行值拷贝

#include<iostream>
using namespace std;

class Person
{
public:

	Person(int age)
	{
		//將年龄數據開闢到堆區
		m_Age = new int(age);
	}

	//重载赋值运算符 (=)
	Person & operator=(Person & p)
	{
		//编译器提供的代码是浅拷贝
		//m_Age = p.m_Age;


		//我們應該先判斷是否有屬性在堆區，如果有，先釋放乾淨，然後再深拷貝
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}

		//提供深拷贝 解决浅拷贝的问题
		m_Age = new int(*p.m_Age);

		//返回自身
		return *this;
	}

	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}

	//年龄的指针
	int *m_Age;

};

void test01()
{
	Person p1(18);

	Person p2(20);

	Person p3(30);

	p3 = p2 = p1; //赋值操作	//p2 = p1 相當於 p2.operator=(p1)

	cout << "p1的年龄为：" << *p1.m_Age << endl;

	cout << "p2的年龄为：" << *p2.m_Age << endl;

	cout << "p3的年龄为：" << *p3.m_Age << endl;
}

int main() {

	test01();

	//int a = 10;
	//int b = 20;
	//int c = 30;

	//我們想讓Person類值行這樣的賦值
	//c = b = a;
	//cout << "a = " << a << endl;
	//cout << "b = " << b << endl;
	//cout << "c = " << c << endl;

	system("pause");

	return 0;
}