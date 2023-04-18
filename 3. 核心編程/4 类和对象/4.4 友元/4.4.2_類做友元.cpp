//*********類做友元*********

#include<iostream>
using namespace std;

class Building;	//building類的宣告

class goodGay
{
public:

	goodGay();	//goodGay構造函數宣告，並在類外實現這個函數
	void visit();	//參觀函數，訪問building中的屬性

private:
	Building *building;
};


class Building	//buildng類的實現
{
	//告诉编译器 goodGay类是Building类的好朋友，可以访问到Building类中私有内容
	friend class goodGay;

public:
	Building();	//Building構造函數宣告，並在類外實現這個函數

public:
	string m_SittingRoom; //客厅
private:
	string m_BedRoom;//卧室
};

//類外寫成員函數
Building::Building()
{
	this->m_SittingRoom = "客厅";
	this->m_BedRoom = "卧室";
}

goodGay::goodGay()
{
	//創建一個建築物 指針對象
	building = new Building;
}

void goodGay::visit()
{
	cout << "好基友正在访问" << building->m_SittingRoom << endl;
	cout << "好基友正在访问" << building->m_BedRoom << endl;
}

void test01()
{
	goodGay gg;
	gg.visit();

}

int main(){

	test01();

	system("pause");
	return 0;
}