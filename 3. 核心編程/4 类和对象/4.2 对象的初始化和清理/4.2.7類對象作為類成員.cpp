//*********類對象作為類成員*********
//C++类中的成员可以是另一个类的对象，我们称该成员为 对象成员
//那么当创建B对象时，A与B的构造和析构的顺序是谁先谁后？

#include<iostream>
using namespace std;

//手機類
class Phone
{
public:
	Phone(string name)
	{
		m_PhoneName = name;
		cout << "Phone构造" << endl;
	}

	~Phone()
	{
		cout << "Phone析构" << endl;
	}

	//手機品牌名稱
	string m_PhoneName;

};

//人類
class Person
{
public:

	//初始化列表可以告诉编译器调用哪一个构造函数
	Person(string name, string pName) :m_Name(name), m_Phone(pName)		//Phone m_Phone = pName 隱式轉換法
	{
		cout << "Person构造" << endl;
	}

	~Person()
	{
		cout << "Person析构" << endl;
	}

	void playGame()
	{
		cout << m_Name << " 使用" << m_Phone.m_PhoneName << " 牌手机! " << endl;
	}

	string m_Name;
	Phone m_Phone;

};

void test01()
{
	//当类中成员是其他类对象时，我们称该成员为 对象成员
	//构造的顺序是 ：先调用对象成员的构造，再调用本类构造
	//析构顺序与构造相反
	Person p("张三" , "苹果X");
	p.playGame();

}

int main() {

	test01();

	system("pause");

	return 0;
}