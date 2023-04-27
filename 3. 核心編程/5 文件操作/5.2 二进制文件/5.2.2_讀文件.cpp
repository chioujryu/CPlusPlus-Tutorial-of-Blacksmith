#include<iostream>
#include <string>
using namespace std;

#include <fstream>

class Person
{
public:
	char m_Name[64];
	int m_Age;
	char m_mood[64];
};

void test01()
{
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
	}

	Person p;
	ifs.read((char *)&p, sizeof(p));

	cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << " 心情： " <<p.m_mood<<endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}