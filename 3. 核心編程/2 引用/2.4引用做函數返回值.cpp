//*********引用做函數返回值**********
//作用：引用是可以作为函数的返回值存在的
//注意：不要返回局部变量引用

#include<iostream>
using namespace std;

//返回局部变量引用
//1. 不要返回局部變量的引用
int & test01() {
	int a = 10; //局部变量
	return a;
}

//2. 可以返回静态变量引用
int & test02() {
	static int a = 20;	//靜態變量存放在全局區，全局區上的數據在程序結束後系統釋放
	return a;
}

int main() {


	//不能返回局部变量的引用
	int& ref = test01();
	cout << "ref = " << ref << endl;	//第一次結果正確，是因為編譯器做了保留
	cout << "ref = " << ref << endl;	//第二次是錯誤的，因為a的內存已經釋放

	//如果函数做左值，那么必须返回引用
	int & ref2 = test02();
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	//如果函數的返回值是引用，這個函數調用可以作為左值
	test02() = 1000;	// test02() = a
						// ref2 = a

	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	system("pause");

	return 0;
}