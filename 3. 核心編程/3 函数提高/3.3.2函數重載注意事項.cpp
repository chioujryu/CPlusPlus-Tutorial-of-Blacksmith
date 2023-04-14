//*********函數重載注意事項*********
//在C++中，函数的形参列表中的形参是可以有默认值的。

#include<iostream>
using namespace std;

//函数重载注意事项
//1、引用作为重载条件
void func(int &a)	//int & a = 10; 10是在常數區裡面，所以是不合法的
{
	cout << "func (int &a) 调用 " << endl;
}

void func(const int &a)	// const int & a = 10; = int temp = 10; const int & a = temp;
{
	cout << "func (const int &a) 调用 " << endl;
}

//2、函数重载碰到函数默认参数
void func2(int a, int b = 10)
{
	cout << "func2(int a, int b = 10) 调用" << endl;
}

void func2(int a)
{
	cout << "func2(int a) 调用" << endl;
}

int main() {
	
	int a = 10;
	func(a); //调用无const
	func(10);//调用有const

	//func2(10); //碰到默认参数产生歧义，需要避免

	system("pause");

	return 0;
}