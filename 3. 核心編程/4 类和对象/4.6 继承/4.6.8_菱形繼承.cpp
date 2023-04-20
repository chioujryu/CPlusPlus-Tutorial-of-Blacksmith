#include<iostream>
using namespace std;

class Animal
{
public:
	int m_Age;
};

//利用需繼承可以解決菱形繼承的問題
//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类
//使用虛繼承後，同名的成員就變成同一個數據了
class Sheep : virtual public Animal {};
class Tuo   : virtual public Animal {};
class SheepTuo : public Sheep, public Tuo {};

void test01()
{
	SheepTuo st;
	//Sheep 作用域下的m_Age
	st.Sheep::m_Age = 18;
	//Tuo 作用域下的m_Age
	st.Tuo::m_Age = 20;

	//當菱形繼承，兩個父類有相同數據，所以要加上作用域來區分
	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age = " <<  st.Tuo::m_Age << endl;

	//那現在st.m_Age 到底是多少，所以要用到virtual
	cout << "st.m_Age = " << st.m_Age << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}