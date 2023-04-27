#include<iostream>
#include <string>
using namespace std;

//1、包含头文件
#include <fstream>	

class Person
{
public:
	char m_Name[64];	// 用c++的string會有問題，所以要用char
	int m_Age;
	char m_mood[64];
};

//二进制文件  写文件
void test01()
{
	
	//2、创建输出流对象
	ofstream ofs("person.txt", ios::out | ios::binary);	// ofstream 裡面有構造函數，可以直接設定初始值
	
	//3、打开文件
	//ofs.open("person.txt", ios::out | ios::binary);

	Person p = {"张三"  , 18, "happy"};

	cout<<p.m_mood<<endl;

	//4、写文件
	ofs.write((const char *)&p, sizeof(p));	//二進制寫入，會是亂碼是正常的，可以讀回來就好

	//5、关闭文件
	ofs.close();
}

int main() {

	test01();

	system("pause");

	return 0;
}