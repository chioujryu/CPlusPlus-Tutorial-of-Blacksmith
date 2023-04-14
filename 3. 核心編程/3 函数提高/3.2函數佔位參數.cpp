//*********函數佔位參數*********
//语法： `返回值类型 函数名 (数据类型){}`
//目前階段的佔位參數目前還用不到，後面課程會用到

#include<iostream>
using namespace std;

//函数占位参数 ，占位参数也可以有默认参数
//语法： `返回值类型 函数名 (数据类型){}`
void func(int a, int = 10) {
	cout << "this is func" << endl;
}
//目前階段的佔位參數目前還用不到，後面課程會用到

int main() {

	func(10,10); //占位参数必须填补

	system("pause");

	return 0;
}