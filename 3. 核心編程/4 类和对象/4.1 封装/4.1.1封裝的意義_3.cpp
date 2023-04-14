//*********封装的意义 - 三種權限*********

#include<iostream>
using namespace std;

//三种权限
//公共权限  public 类内可以访问，类外可以访问
//保护权限  protected 类内可以访问，类外不可以访问，兒子也可以訪問父親中的保護內容
//私有权限  private 類内可以访问，类外不可以访问，兒子不可以訪問父親中的私有內容

class Person
{
	//姓名  公共權限
public:
	string m_Name; //姓名

	//汽车  保护權限
protected:
	string m_Car;

	//银行卡密码  私有權限
private:
	int m_Password;

public:
	void func()
	{
		m_Name = "张三";
		m_Car = "拖拉机";
		m_Password = 123456;
	}
};

int main() {

	Person p;
	p.m_Name = "李四";	//公共權限的內容，類外可以訪問到
	//p.m_Car = "奔驰";  //保護權限的內容，類外訪問不到
	//p.m_Password = 123; //私有權限的內容，類外訪問不到
	cout<<p.m_Name<<endl;

	//可以藉由類內的行為，改變類內的屬性
	p.func();
	cout<<p.m_Name<<endl;

	system("pause");

	return 0;
}