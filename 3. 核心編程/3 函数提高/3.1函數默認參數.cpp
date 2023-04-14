//*********函數默認參數*********
//在C++中，函数的形参列表中的形参是可以有默认值的。
//语法：` 返回值类型  函数名 （参数= 默认值）{}`

#include<iostream>
using namespace std;

//如果我們自己傳入的話就用自己的數據，如果沒有傳入自己的數據就用默認值
//语法：` 返回值类型  函数名 （参数 = 默认值）{}`
int func(int a, int b = 10, int c = 10) {
	return a + b + c;
}

//注意事項
//1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
//2. 如果函数声明有默认值，函数实现的时候就不能有默认参数
//聲明和實現只能有一個有默認參數
int func2(int a = 10, int b = 10);
int func2(int a, int b) {
	return a + b;
}

int main() {

	cout << "result = " << func(20, 20) << endl;
	cout << "result = " << func(100) << endl;

	cout << "result = " << func2(20, 20) << endl;
	cout << "result = " << func2(100) << endl;

	system("pause");

	return 0;
}