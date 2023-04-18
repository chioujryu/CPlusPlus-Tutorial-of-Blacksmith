//**************加號運算符重載**************
//运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
//作用：实现两个自定义数据类型相加的运算

#include<iostream>
using namespace std;

class Person {
public:
	Person() {};	//默認無參構造函數
	Person(int a, int b)	//有參構造函數
	{
		this->m_A = a;
		this->m_B = b;
	}
	//成员函数实现 + 号运算符重载
	//operator+ 是編譯器內建的
	Person operator+(const Person& p) {
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}

public:
	int m_A;
	int m_B;
};

//全局函数实现 + 号运算符重载
Person operator+(const Person& p1, const Person& p2) {
	Person temp(0, 0);
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}

//运算符重载 可以发生函数重载 
Person operator+(const Person& p2, int val)  
{
	Person temp;
	temp.m_A = p2.m_A + val;
	temp.m_B = p2.m_B + val;
	return temp;
}

void test() {

	Person p1(10, 10);
	Person p2(20, 20);

	//成员函数重載方式調用
	Person p3 = p2 + p1;  //相当于 Person p3 = p2.operaor+(p1)
	cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;

	Person p4(10, 10);
	Person p5(20, 20);
	//全局函數重載調用
	Person p6 = operator+(p4,p5);	//也可以寫成 Person p6 = p4 + p5
	cout << "mA:" << p6.m_A << " mB:" << p6.m_B << endl;
	Person p7 = p6 + 10; //相当于 Person p7 = operator+(p6,10)
	cout << "mA:" << p7.m_A << " mB:" << p7.m_B << endl;

	//注意： 如果你全部都寫成 Person p3 = p2 + p1; 這種格式，編譯器會不知道你是要調用成員函數還是全局函數

}

int main() {

	test();

	system("pause");

	return 0;
}