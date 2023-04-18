//*********全局函數做友元*********

#include<iostream>
using namespace std;

//建築物類
class Building
{
	//告诉编译器 goodGay全局函数 是 Building类的好朋友，可以访问类中的私有内容
	friend void goodGay(Building * building);

public:

	Building()
	{
		this->m_SittingRoom = "客厅";
		this->m_BedRoom = "卧室";
	}


public:
	string m_SittingRoom; //客廳

private:
	string m_BedRoom; //卧室
};


void goodGay(Building * building)	//goodGay = 好基友
{
	cout << "好基友的全局函數正在访问building->m_SittingRoom： " << building->m_SittingRoom << endl;
	cout << "好基友的全局函數正在访问building->m_BedRoom： " << building->m_BedRoom << endl;
}


void test01()
{
	Building b;
	goodGay(&b);
}

int main(){

	test01();

	system("pause");
	return 0;
}