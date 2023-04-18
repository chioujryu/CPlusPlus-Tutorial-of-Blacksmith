//**************類做友元**************

#include<iostream>
using namespace std;

//**************類的宣告**************
class Building;

class goodGay
{
public:

	goodGay();	//構造函數宣告
	void visit(); //讓visit函數可以訪問Building中的私有成員
	void visit2(); 	//讓visit2函數不可以訪問Building中的私有成員

private:
	Building *building;
};


class Building
{
	//告诉编译器  goodGay类中的visit成员函数 是Building好朋友，可以访问私有内容
	friend void goodGay::visit();

public:
	Building();//構造函數宣告

public:
	string m_SittingRoom; //客厅
private:
	string m_BedRoom;//卧室
};

//**************類外實現成員函數**************
Building::Building()	//構造函數實現
{
	this->m_SittingRoom = "客厅";
	this->m_BedRoom = "卧室";
}

goodGay::goodGay()	//構造函數實現
{
	building = new Building;
}

void goodGay::visit()
{
	cout << "好基友正在访问" << building->m_SittingRoom << endl;
	cout << "好基友正在访问" << building->m_BedRoom << endl;
}

void goodGay::visit2()
{
	cout << "好基友正在访问" << building->m_SittingRoom << endl;
	//cout << "好基友正在访问" << building->m_BedRoom << endl;	//因visit2()不是building的好朋友，所以不能訪問building的私有屬性
}

//**************全局函數**************
void test01()
{
	goodGay  gg;
	gg.visit();

}

//**************main 函數**************
int main(){
    
	test01();

	system("pause");
	return 0;
}