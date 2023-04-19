# C++核心编程

本阶段主要针对C++==面向对象==编程技术做详细讲解，探讨C++中的核心和精髓。

## **4** 类和对象


C++面向对象的三大特性为：**封装、继承、多态**



C++认为**万事万物都皆为对象**，对象上有其属性和行为



**例如：**

​	人可以作为对象，属性有姓名、年龄、身高、体重...，行为有走、跑、跳、吃饭、唱歌...

​	车也可以作为对象，属性有轮胎、方向盘、车灯...,行为有载人、放音乐、放空调...

​	具有==相同性质的对象==，我们可以抽象称为**类**，人属于人类，车属于车类

### 4.4 友元



生活中你的家有客厅(Public)，有你的卧室(Private)

客厅所有来的客人都可以进去，但是你的卧室是私有的，也就是说只有你能进去

但是呢，你也可以允许你的好闺蜜好基友进去。



在程序里，有些私有属性 也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术



友元的目的就是让一个函数或者类 访问另一个类中私有成员



友元的关键字为  **friend**



友元的三种实现

* 全局函数做友元
* 类做友元
* 成员函数做友元





#### 4.4.1 全局函数做友元
**input**
```C++
//*********全局函數做友元*********

#include<iostream>
using namespace std;

//建築物類
class Building
{
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
```
**output**
報錯，因為在類外訪問私有屬性
```
./main.cpp:32:85: error: 'm_BedRoom' is a private member of 'Building'
        cout << "好基友的全局函數正在访问building->m_BedRoom： " << building->m_BedRoom << endl;
                                                                              ^
./main.cpp:25:9: note: declared private here
        string m_BedRoom; //卧室
```
**input**
將全局函數變成Building的好朋友，即可以訪問
```c++
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
```
**output**
```
好基友的全局函數正在访问building->m_SittingRoom： 客厅
好基友的全局函數正在访问building->m_BedRoom： 卧室
```




#### 4.4.2 类做友元

**input**
```C++
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
```
**output**
```
好基友正在访问客厅
好基友正在访问卧室
```




#### 4.4.3 成员函数做友元
**input**
```C++
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
```
**output**
```
好基友正在访问客厅
好基友正在访问卧室
```


