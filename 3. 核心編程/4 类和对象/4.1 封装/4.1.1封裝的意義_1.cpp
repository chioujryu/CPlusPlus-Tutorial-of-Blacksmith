//*********封装的意义*********
//在设计类的时候，属性和行为写在一起，表现事物
//语法： class 类名{ 访问权限： 属性 / 行为 };

#include<iostream>
using namespace std;

//設計一個圓類，求圓的周長
//圓求周長的公式：2*PI*半徑

//圆周率
const double PI = 3.14;

//1、封装的意义
//将属性和行为作为一个整体，用来表现生活中的事物

//封装一个圆类，求圆的周长
//class代表設計一個類，後面跟著是類名稱
class Circle
{
public:  //訪問權限 - 公共的權限

	//屬性
	int m_r;//半徑

	//行為
	//獲取到圓的周長
	double calculateZC()
	{
		//2 * pi  * r
		//获取圆的周长
		return  2 * PI * m_r;
	}
};

int main() {

	// 通过圆类，创建圆的对象
	// 實例化，通過一個類，創建一個對象的過程
	Circle c1;
	c1.m_r = 10; //给圆对象的半径 进行赋值操作

	//2 * pi * 10 = = 62.8
	cout << "圆的周长为： " << c1.calculateZC() << endl;

	system("pause");

	return 0;
}