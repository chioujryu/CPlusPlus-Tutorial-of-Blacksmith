//**************遞增运算符重载**************
//作用：通过重载递增运算符，实现自己的整型数据

#include<iostream>
using namespace std;

class MyInteger {

	friend ostream & operator<<(ostream & out, MyInteger myint);

public:
	MyInteger() {
		m_Num = 0;
	}
	//重載前置++運算符	返回引用是為了對同一個數據做增加
	MyInteger & operator++() {
		//先進行++運算
		m_Num++;
		//再將自身做返回
		return *this;
	}

	//重載后置++運算符
	MyInteger operator++(int) {	//int代表佔位參數，可以區分前置以及後置遞增
		//先返回
		MyInteger temp = *this; //记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
		m_Num++;
		//再將自身做返回
		return temp;
	}

	//重載前置--運算符	返回引用是為了對同一個數據做遞減
	MyInteger & operator--() {
		//先進行++運算
		m_Num--;
		//再將自身做返回
		return *this;
	}

	//重載后置--運算符
	MyInteger operator--(int) {	//int代表佔位參數，可以區分前置以及後置遞增
		//先返回
		MyInteger temp = *this; //记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
		m_Num++;
		//再將自身做返回
		return temp;
	}

private:
	int m_Num;
};

//重載左移運算符
ostream & operator<<(ostream & out, MyInteger myint) {
	out << myint.m_Num;
	return out;
}

//前置++ 先++ 再返回
void test01() {
	MyInteger myInt;
	cout << ++myInt << endl;
	cout << myInt << endl;
}

//后置++ 先返回 再++
void test02() {

	MyInteger myInt;
	cout << myInt++ << endl;
	cout << myInt << endl;
}

//前置-- 先-- 再返回
void test03() {
	MyInteger myInt;
	cout << --myInt << endl;
	cout << myInt << endl;
}

//后置-- 先返回 再--
void test04() {

	MyInteger myInt;
	cout << myInt-- << endl;
	cout << myInt << endl;
}

int main() {

	//test01();
	//test02();
	//test03();
    //test04();

    return 0;

	system("pause");

	return 0;
}