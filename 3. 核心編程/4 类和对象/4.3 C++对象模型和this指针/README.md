# C++核心编程

本阶段主要针对C++==面向对象==编程技术做详细讲解，探讨C++中的核心和精髓。

## **4** 类和对象


C++面向对象的三大特性为：==封装、继承、多态==



C++认为==万事万物都皆为对象==，对象上有其属性和行为



**例如：**

​	人可以作为对象，属性有姓名、年龄、身高、体重...，行为有走、跑、跳、吃饭、唱歌...

​	车也可以作为对象，属性有轮胎、方向盘、车灯...,行为有载人、放音乐、放空调...

​	具有==相同性质的对象==，我们可以抽象称为==类==，人属于人类，车属于车类

### 4.3 C++对象模型和this指针



#### 4.3.1 成员变量和成员函数分开存储



在C++中，类内的成员变量和成员函数分开存储

只有非静态成员变量才属于类的对象上



```C++
//*********成员变量和成员函数分开存储*********
//在C++中，类内的成员变量和成员函数分开存储
//只有非静态成员变量才属于类的对象上

#include<iostream>
using namespace std;

class Person {
public:
	Person() {
		mA = 0;
	}
	//非静态成员变量占对象空间
	int mA;
	//静态成员变量不占对象空间
	static int mB; 
	//函数也不占对象空间，所有函数共享一个函数实例
	void func() {
		cout << "mA:" << this->mA << endl;
	}
	//静态成员函数也不占对象空间
	static void sfunc() {
	}
};

int Person::mB = 10;

class cat{
	
};

void test(){
	//空對象占用內存空間為1
	//c++編譯器會給每個空對象也分配一個字節的空間，是為了區分空對象占內存的位置
	//每個空對象，也應該有獨一無二的內存地址
	cat c1;
	cout<<"空對象c1的大小為多少：" <<sizeof(c1)<<endl;
};

int main() {

	test();

	Person p;
	cout << "Person類的大小為" <<sizeof(Person) << endl;		//因mA的大小有4byte，所以Person類的大小為4byte
	cout<<"p的地址為：" <<(int)&p<<endl;
	cout<<"p.mA的地址為："<<(int)&p.mA<<endl;
	cout<<"靜態變量`mB`的地址為："<<(int) & Person::mB<<endl;

	system("pause");

	return 0;
}
```







#### 4.3.2 this指针概念

通过4.3.1我们知道在C++中成员变量和成员函数是分开存储的

每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码

那么问题是：这一块代码是如何区分那个对象调用自己的呢？



c++通过提供特殊的对象指针，this指针，解决上述问题。**this指针指向被调用的成员函数所属的对象**

**注意**：這個章節很難，要多看多了解

this指针是隐含每一个非静态成员函数内的一种指针

this指针不需要定义，直接使用即可



this指针的用途：

*  当形参和成员变量同名时，可用this指针来区分
*  在类的非静态成员函数中返回对象本身，可使用return *this

```C++
//*********this指針概念*********
//這個章節很難，要多看多了解

#include<iostream>
using namespace std;

class Person
{
public:

	Person(int age)
	{
		//1、当形参和成员变量同名时，可用this指针来区分
		//this指針指向被調用的成員函數 所屬的對象
		//this === Person * p1
		this->age = age;
	}

	Person & PersonAddAge(Person p)
	{
		this->age += p.age;

		//this指向的是p2的指針，而*this指向的就是p2的本體 
		return *this;
	}

	int age;
};

//1. 解決名稱衝突
void test01()
{
	Person p1(10);
	cout << "p1.age = " << p1.age << endl;
}

//2. 返回对象本身*this
void test02()
{
	Person p1(10);
	cout << "p1.age = " << p1.age << endl;

	Person p2(10);
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);	//這是鏈式編程思想
	cout << "p2.age = " << p2.age << endl;
}


int main() {

	test01();
	//test02();

	system("pause");

	return 0;
}
```









#### 4.3.3 空指针访问成员函数



C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针



如果用到this指针，需要加以判断保证代码的健壮性



**示例：**

```C++
//*********空指針訪問成員函數*********

#include<iostream>
using namespace std;

//空指针访问成员函数
class Person {
public:

	void ShowClassName() {
		cout << "我是Person类!" << endl;
	}

	void ShowPerson() {
		cout << mAge << endl;
    //會報錯，因為你是用空指針，根本沒有對象去掉用mAge，因為在mAge的程式背後是this->mAge，甚至你可以直接將mAge改成this->mAge
	}

public:
	int mAge;	//前面的m代表是member，就是成員
};

void test01()
{
	Person * p = NULL;
	p->ShowClassName(); //空指针，可以调用成员函数
	p->ShowPerson();  //但是如果成员函数中用到了this指针，就不可以了
}

int main() {

	test01();

	system("pause");

	return 0;
}
```
OUTPUT報錯
```
我是Person类!
signal: illegal instruction (core dumped)
```

這樣寫就不會報錯了
```C++
//*********空指針訪問成員函數*********

#include<iostream>
using namespace std;

//空指针访问成员函数
class Person {
public:

	void ShowClassName() {
		cout << "我是Person类!" << endl;
	}

	void ShowPerson() {
		if (this == NULL) {
			return;
		}
		cout << mAge << endl;
	}

public:
	int mAge;	//前面的m代表是member，就是成員
};

void test01()
{
	Person * p = NULL;
	p->ShowClassName(); //空指针，可以调用成员函数
	p->ShowPerson();  //但是如果成员函数中用到了this指针，就不可以了
}

int main() {

	test01();

	system("pause");

	return 0;
}
```












#### 4.3.4 const修饰成员函数



**常函数：**

* 成员函数后加const后我们称为这个函数为**常函数**
* 常函数内不可以修改成员属性
* 成员属性声明时加关键字mutable后，在常函数中依然可以修改



**常对象：**

* 声明对象前加const称该对象为常对象
* 常对象只能调用常函数







**示例：**

```C++
//*********const修飾成員函數*********

#include<iostream>
using namespace std;

class Person {
public:
	Person() {
		m_A = 0;
		m_B = 0;
	}

	//常量函數
	//this指针的本质是一个指针常量，指针的指向不可修改
	//如果想让指针指向的值也不可以修改，需要声明常函数
	//在成員函數後面加上const，修飾的是this指向，讓指針指向的值都不可以修改
	void ShowPerson() const {
		//const Person * const this; 這代表指針的指向跟裡面的值都不能修改
		//this = NULL; //不能修改指针的指向 Person* const this;
		//this->mA = 100; //但是this指针指向的对象的数据是可以修改的
		

		//const修饰成员函数，表示指针指向的内存空间的数据不能修改，除了mutable修饰的变量
		this->m_B = 100;
	}

	void MyFunc() {		
		//m_A = 10000;
		cout<<"我調用了MyFunc"<<endl;
	}

public:
	int m_A;
	mutable int m_B; //特殊關鍵字mutable，加上這個關鍵字，即使在常量函數中，也可以修改這個值
};

//const修饰对象  常量对象
void test01() {

	const Person person; //常量对象  
	cout << person.m_A << endl;
	//person.mA = 100; //常量对象 不能修改成员变量的值,但是可以访问
	person.m_B = 100; //m_B因為有加上mutable關鍵字，所以可以修改他

	//常量对象 只能調用常量函數
	person.MyFunc();
}

int main() {

	test01();

	system("pause");

	return 0;
}
```
OUTPUT
報錯，因為常量對象不能調用一般函數，常量對象只能調用常量函數
```
tempCodeRunnerFile.cpp: In function 'void test01()':
tempCodeRunnerFile.cpp:46:16: error: passing 'const Person' as 'this' argument discards qualifiers [-fpermissive]
  person.MyFunc();
                ^
tempCodeRunnerFile.cpp:27:7: note:   in call to 'void Person::MyFunc()'
  void MyFunc() {
       ^~~~~~
```
這樣寫就成功編譯了
```C++
//*********const修飾成員函數*********

#include<iostream>
using namespace std;

class Person {
public:
	Person() {
		m_A = 0;
		m_B = 0;
	}

	//常量函數
	//this指针的本质是一个指针常量，指针的指向不可修改
	//如果想让指针指向的值也不可以修改，需要声明常函数
	//在成員函數後面加上const，修飾的是this指向，讓指針指向的值都不可以修改
	void ShowPerson() const {
		//const Person * const this; 這代表指針的指向跟裡面的值都不能修改
		//this = NULL; //不能修改指针的指向 Person* const this;
		//this->mA = 100; //但是this指针指向的对象的数据是可以修改的
		

		//const修饰成员函数，表示指针指向的内存空间的数据不能修改，除了mutable修饰的变量
		this->m_B = 100;
	}

	void MyFunc() const{		
		//m_A = 10000;
		cout<<"我調用了MyFunc"<<endl;
	}

public:
	int m_A;
	mutable int m_B; //特殊關鍵字mutable，加上這個關鍵字，即使在常量函數中，也可以修改這個值
};

//const修饰对象  常量对象
void test01() {

	const Person person; //常量对象  
	cout << person.m_A << endl;
	//person.mA = 100; //常量对象 不能修改成员变量的值,但是可以访问
	person.m_B = 100; //m_B因為有加上mutable關鍵字，所以可以修改他

	//常量对象 只能調用常量函數
	person.MyFunc();
}

int main() {

	test01();

	system("pause");

	return 0;
}
```
OUTPUT
```
0
我調用了MyFunc
```







