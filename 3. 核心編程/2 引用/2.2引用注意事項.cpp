#include<iostream>
using namespace std;

//引用必須要初始化
//初始化後就不能變了

int main() {

	int a = 10;
	int b = 20;

	//1. 引用必須初始化
	//int &c; //错误，引用必须初始化
	int &c = a; //一旦初始化后，就不可以更改

	//2. 引用在初始化後，不可以改變
	c = b; //这是赋值操作，不是更改引用

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	system("pause");

	return 0;
}