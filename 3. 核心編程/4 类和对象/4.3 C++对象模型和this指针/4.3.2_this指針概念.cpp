//*********this指針概念*********
//這個章節很難，要多看多了解

#include<iostream>
using namespace std;

class Person
{
public:

	Person(int age)
	{
		//1、当形参和成员变量同名时，可用this指针来区分
		//this指針指向被調用的成員函數 所屬的對象
		//this === Person * p1
		this->age = age;
	}

	Person & PersonAddAge(Person p)
	{
		this->age += p.age;

		//this指向的是p2的指針，而*this指向的就是p2的本體 
		return *this;
	}

	int age;
};

//1. 解決名稱衝突
void test01()
{
	Person p1(10);
	cout << "p1.age = " << p1.age << endl;
}

//2. 返回对象本身*this
void test02()
{
	Person p1(10);
	cout << "p1.age = " << p1.age << endl;

	Person p2(10);
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);	//這是鏈式編程思想
	cout << "p2.age = " << p2.age << endl;
}


int main() {

	test01();

	system("pause");

	return 0;
}