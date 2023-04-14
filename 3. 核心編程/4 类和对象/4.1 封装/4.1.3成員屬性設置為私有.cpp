//*********成員屬性設置為私有*********
//1. 可以控制讀寫權限
//2. 對於寫權限，我們可以檢測數據的有效性


#include<iostream>
using namespace std;

class Person {
public:

	//设置姓名 可寫不可讀
	void setName(string name) {
		m_Name = name;
	}

	//獲取姓名 只讀
	string getName()
	{
		return m_Name;
	}

	//获取年龄 只讀
	int getAge() {
		return m_Age;
	}
	//设置年龄 可寫不可讀
	void setAge(int age) {
		if (age < 0 || age > 150) {
			cout << "你个老妖精!" << endl;
			return;
		}
		m_Age = age;
	}

	//情人设置为只写
	void setLover(string lover) {
		m_Lover = lover;
	}

	//獲取情人为只讀
	string getLover() {
		return m_Lover;
	}

private:
	string m_Name; //可读可写  姓名
	int m_Age; //只读  年龄
	string m_Lover; //只写  情人
};


int main() {

	Person father;
	//姓名设置
	father.setName("张三");
	cout << "姓名： " << father.getName() << endl;

	//年龄设置
	father.setAge(1000);
	cout << "年龄： " << father.getAge() << endl;

	//情人设置
	father.setLover("青空光");	//將情人設置為"青空光"
	cout << "情人： " << father.getLover() << endl;
	//cout << "情人： " << p.m_Lover << endl;  //只写属性，不可以读取

	system("pause");

	return 0;
}