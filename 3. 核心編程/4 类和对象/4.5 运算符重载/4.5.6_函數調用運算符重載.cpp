//**************函數調用運算符重載**************
//作用：重载关系运算符，可以让两个自定义类型对象进行对比操作

#include<iostream>
using namespace std;

//打印的類
class MyPrint
{
public:

	//重載()運算符
	void operator()(string text)
	{
		cout << text << endl;
	}

	int a =20;

};
void test01()
{
	MyPrint myFunc;

	//因為使用起來非常像是函數，所以也称为仿函数
	myFunc("hello world");	
}

//加法類
class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

void test02()
{
	MyAdd add;
	int ret = add(10, 10);
	cout << "ret = " << ret << endl;

	//匿名對象调用，調用完之後，會馬上釋放掉記憶體
	cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;
}

int main() {

	test01();
	test02();
	
	system("pause");

	return 0;
}