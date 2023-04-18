//**************左移运算符重载**************
//作用：可以输出自定义数据类型

#include<iostream>
using namespace std;

class Person {
	//利用成員函數重載左移運算符
	friend ostream & operator<<(ostream & cout, Person & p);

public:

	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}

	//利用成員函數重載左移運算符 p.operator<<(cout) 簡化版本 p<<cout
	//不會利用成員函數重載左移運算符(<<)，因為無法實現 cout 在左側
	//void operator<<(cout){
	//}

private:
	int m_A;
	int m_B;
};

//只能利用全局函數實現左移運算符(<<)
//在 `vscode` 可以點擊 `cout` 並按下 `alt + F12`，即可查看 `cout` 的原碼
//可以看到 `cout` 的是在 `ostream` 創建出來的對象。
//補充： `ostream`為輸出流，`istream`為輸入流
ostream & operator<<(ostream & cout, Person & p)	//本質 operator<<(cout, p) 可簡化成 cout<<p
{
	cout<<"m_A = "<<p.m_A<<"\t\t"<<"m_B = "<<p.m_B<<endl;
	return cout;
}


//全局函数实现左移重载
//ostream对象只能有一个
// ostream& operator<<(ostream& out, Person& p) {
// 	out << "a:" << p.m_A << " b:" << p.m_B;
// 	return out;
// }

void test() {

	Person p1(10, 20);
	cout<<p1<<endl;

	//cout << p1 << "hello world" << endl; //链式编程
}

int main() {

	test();

	system("pause");

	return 0;
}