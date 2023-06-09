# C++核心编程

本阶段主要针对C++**面向对象**编程技术做详细讲解，探讨C++中的核心和精髓。

## **4** 类和对象


C++面向对象的三大特性为：**封装、继承、多态**



C++认为**万事万物都皆为对象**，对象上有其属性和行为


**例如：**

​	人可以作为对象，属性有姓名、年龄、身高、体重...，行为有走、跑、跳、吃饭、唱歌...

​	车也可以作为对象，属性有轮胎、方向盘、车灯...,行为有载人、放音乐、放空调...

​	具有==相同性质的对象==，我们可以抽象称为==类==，人属于人类，车属于车类

### 4.2 对象的初始化和清理



*  生活中我们买的电子产品都基本会有出厂设置，在某一天我们不用时候也会删除一些自己信息数据保证安全
*  C++中的面向对象来源于生活，每个对象也都会有初始设置以及 对象销毁前的清理数据的设置。





#### 4.2.1 构造函数和析构函数

对象的**初始化和清理**也是两个非常重要的安全问题

​一个对象或者变量没有初始状态，对其使用后果是未知

​同样的使用完一个对象或变量，没有及时清理，也会造成一定的安全问题

c++利用了**构造函数**和**析构函数**解决上述问题，这两个函数将会被编译器自动调用，完成对象初始化和清理工作。

对象的初始化和清理工作是编译器强制要我们做的事情，因此如果**我们不提供构造和析构，编译器会提供**

**编译器提供的构造函数和析构函数是空实现。**



* 构造函数：主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无须手动调用。
* 析构函数：主要作用在于对象**销毁前**系统自动调用，执行一些清理工作。





**构造函数语法：**`类名(){}`

1. 构造函数，没有返回值也不写void
2. 函数名称与类名相同
3. 构造函数可以有参数，因此可以发生重载
4. 程序在调用对象时候会自动调用构造，无须手动调用,而且只会调用一次





**析构函数语法：** `~类名(){}`

1. 析构函数，没有返回值也不写void
2. 函数名称与类名相同,在名称前加上符号  ~
3. 析构函数不可以有参数，因此不可以发生重载
4. 程序在对象销毁前会自动调用析构，无须手动调用,而且只会调用一次





```C++
//*********構造函數與析构函数*********

#include<iostream>
using namespace std;

class Person
{
public:
	//1. 構造函數，進行初始化操作
    //沒有返回值，不用寫void
    //函數名與類名相同
    //構造函數可以有參數，可以發生重載
    //創建對象的時候，構造函數會自動調用，而且只會調用一次
	Person()
	{
		cout << "Person的构造函数调用" << endl;
	}

	//2. 析构函数，進行清理操作
    //沒有返回值，不用寫void
    //函數名與類名相同，但要在前面有`~`
    //析构函数可以不可以有參數，所以不可以發生重載
    //對象在銷毀前，會自動調用析构函数，而且只會調用一次
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}

};

//構造函數和析构函數都是必須有的，如果我們沒有去撰寫構造函數和析构函數
//編譯器會自動提供一個空的構造函數和析构函數
void test01()
{
	Person p;   //在棧上的數據，test01執行完畢後，會自動釋放這個對象
}

int main() {
	
	test01();

	system("pause");

	return 0;
}
```











#### 4.2.2 构造函数的分类及调用

**两种分类方式：**

* ​按参数分为： 有参构造和无参构造
* 按类型分为： 普通构造和拷贝构造

**三种调用方式：**
* ​括号法
* ​显示法
* 隐式转换法



**示例：**

```C++
//*********構造函數的分類與調用*********
//注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明，因為如果加括号，編譯器會以為你在做函數聲明


#include<iostream>
using namespace std;

//1、构造函数分类
// 按照参数分类分为 有参和无参构造   无参又称为默认构造函数
// 按照类型分类分为 普通构造和拷贝构造

class Person {
public:
	//无参（默认）构造函数
	Person() {
		cout << "无参构造函数!" << endl;
	}
	//有参构造函数
	Person(int a) {
		age = a;
		cout << "有参构造函数!" << endl;
	}
	//拷贝构造函数
	Person(const Person & p) {
		//將傳入的人身上的所有屬性，拷貝到我身上
		age = p.age;
		cout << "拷贝构造函数!" << endl;
	}
	//析构函数
	~Person() {
		cout << "析构函数!" << endl;
	}
public:
	int age;
};

//2、构造函数的调用
//调用无参构造函数
void test01() {
	//注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明，因為如果加括号，編譯器會以為你在做函數聲明
	//Person p();  //絕對不可以這樣寫，因為看起來在做函數聲明;
	Person p; //调用无参构造函数
}

//调用有参的构造函数
void test02() {

	//2.1  括号法，常用
	//注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明
	//Person p();  //絕對不可以這樣寫，因為看起來在做函數聲明;
	Person p;	//调用无参构造函数
	Person p1(10);	//调用有参构造函数
	Person p2(p1);	//調用拷貝構造函數
	cout<<p1.age<<endl;
	cout<<p2.age<<endl;


	//2.2 显式法
	Person p3 = Person(10); 	//有參構造
	Person p4 = Person(p3);		//無參構造
	//Person(10);		//单独写就是匿名对象  当前行结束之后，马上析构

	//注意2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明，Person (p4) === Person p4，
	//Person (p4);
	

	//2.3 隐式转换法
	Person p5 = 10; // Person p4 = Person(10); 
	Person p6 = p5; // Person p5 = Person(p4); 

	//注意2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明
	//Person p5(p4);
}

int main() {

	//test01();
	test02();

	system("pause");

	return 0;
}
```









#### 4.2.3 拷贝构造函数调用时机



C++中拷贝构造函数调用时机通常有三种情况

* 使用一个已经创建完毕的对象来初始化一个新对象
* 值传递的方式给函数参数传值
* 以值方式返回局部对象



**示例：**

```C++
//*********拷貝構造函數的調用時機*********


#include<iostream>
using namespace std;

class Person {
public:
	Person() {
		cout << "无参构造函数!" << endl;
		mAge = 0;
	}
	Person(int age) {
		cout << "有参构造函数!" << endl;
		mAge = age;
	}
	Person(const Person& p) {
		cout << "拷贝构造函数!" << endl;
		mAge = p.mAge;
	}
	//析构函数在释放内存之前调用
	~Person() {
		cout << "析构函数!" << endl;
	}
public:
	int mAge;
};

//1. 使用一个已经创建完毕的对象来初始化一个新对象
void test01() {

	Person man(100); //p对象已经创建完毕
	Person newman(man); //调用拷贝构造函数
	Person newman2 = man; //拷贝构造

	//Person newman3;
	//newman3 = man; //不是调用拷贝构造函数，赋值操作
}

//2. 值传递的方式给函数的参数传值
//相当于Person p1 = p;
void doWork(Person p1) {}	//值傳遞給形參等於是拷貝一個
void test02() {
	Person p; //无参构造函数
	doWork(p);
}

//3. 以值方式返回局部对象
Person doWork2()
{
	Person p1;
	cout << (int *)&p1 << endl;		//查看p1的地址
	return p1;
}

void test03()
{
	Person p = doWork2();
	cout << (int *)&p << endl;		//查看p的地址
}


int main() {

	//test01();
	//test02();
	test03();

	system("pause");

	return 0;
}
```





#### 4.2.4 构造函数调用规则

默认情况下，c++编译器至少给一个类添加3个函数

1．默认构造函数(无参，函数体为空)

2．默认析构函数(无参，函数体为空)

3．默认拷贝构造函数，对属性进行值拷贝



构造函数调用规则如下：

* 如果用户定义`有参构造函数`，c++不再提供默认`无参构造函數`，但是会提供`默认拷贝构造`


* 如果用户定义`拷贝构造函数`，c++不会再提供`其他默認构造函数`



示例：

```C++
//*********構造函數的調用規則*********

#include<iostream>
using namespace std;

//1. 只要創建一個類，c++編譯器會自動給每個類添加三個函數
//默認構造（空實現）
//析構函數（空實現）
//拷貝函數（值拷貝）

//2. 如果我們寫了有參構造函數，則編譯器則不會有默認無參構造函數
//如果我們提供了拷貝構造函數，則編譯器就不提供其他所有的默認函數

class Person {
public:
	//无参（默认）构造函数
	Person() {
		cout << "无参构造函数!" << endl;
	}
	//有参构造函数
	Person(int a) {
		age = a;
		cout << "有参构造函数!" << endl;
	}
	//拷贝构造函数
	Person(const Person& p) {
		age = p.age;
		cout << "拷贝构造函数!" << endl;
	}
	//析构函数
	~Person() {
		cout << "析构函数!" << endl;
	}
public:
	int age;
};

void test01()
{
	Person p1(18);
	//如果不写拷贝构造，编译器会自动添加拷贝构造，并且做浅拷贝操作
	Person p2(p1);

	cout << "p2的年龄为： " << p2.age << endl;
}

void test02()
{
	//如果用户提供有参构造，编译器不会提供默认构造，但依然会提供拷贝构造
	Person p1; //此时如果用户自己没有提供默认构造，会出错
	Person p2(10); //用户提供的有参
	Person p3(p2); //此时如果用户没有提供拷贝构造，编译器会提供

	//如果用户提供拷贝构造，编译器不会提供其他默認构造函数
	Person p4; //此时如果用户自己没有提供默认构造，会出错
	Person p5(10); //此时如果用户自己没有提供有参，会出错
	Person p6(p5); //用户自己提供拷贝构造
}

int main() {

	test01();

	system("pause");

	return 0;
}
```









#### 4.2.5 深拷贝与浅拷贝



深浅拷贝是面试经典问题，也是常见的一个坑



浅拷贝：简单的赋值拷贝操作



深拷贝：在堆区重新申请空间，进行拷贝操作



**示例：**

```C++
//*********深拷贝与浅拷贝*********
//总结：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题

#include<iostream>
using namespace std;

class Person {
public:
	//无参（默认）构造函数
	Person() {
		cout << "无参构造函数!" << endl;
	}
	//有参构造函数
	Person(int age ,int height) {
		
		cout << "有参构造函数!" << endl;

		m_age = age;
		m_height = new int(height);
		cout<<(int)&m_age<<endl;		//查看地址
		cout<<(int)m_height<<endl;		//查看堆區地址
	}
	//拷贝构造函数  
	Person(const Person& p) {
		cout << "拷贝构造函数!" << endl;
		//如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
		m_age = p.m_age;
		m_height = new int(*p.m_height);
		cout<<(int)&m_age<<endl;		//查看地址
		cout<<(int)m_height<<endl;		//查看堆區地址
	}

	//析构函数
	//將堆區開闢的數據做釋放操作
	~Person() {
		cout << "析构函数!" << endl;
		if (m_height != NULL)
		{
			delete m_height;
		}
	}
public:
	int m_age;
	int* m_height;
};

void test01()
{
	Person p1(18, 180);

	Person p2(p1);

	cout << "p1的年龄： " << p1.m_age << " 身高： " << *p1.m_height << endl;

	cout << "p2的年龄： " << p2.m_age << " 身高： " << *p2.m_height << endl;

}

int main() {

	test01();

	system("pause");

	return 0;
}
```

> 总结：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题









#### 4.2.6 初始化列表



**作用：**

C++提供了初始化列表语法，用来初始化属性

當然，你也可以用機構函數來做初始化，初始化列表只是另一種初始化的方式



**语法：**`构造函数()：属性1(值1),属性2（值2）... {}`



**示例：**

```C++
//*********初始化列表*********
//作用：C++提供了初始化列表语法，用来初始化属性
//當然，你也可以用傳統方式來做初始化
//這只是另一種初始化的方式
//語法：构造函数()：属性1(值1),属性2（值2）... {}

#include<iostream>
using namespace std;

class Person {
public:

	////传统方式初始化
	//Person(int a, int b, int c) {
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}

	//初始化列表方式初始化
	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}
	void PrintPerson() {
		cout << "mA:" << m_A << endl;
		cout << "mB:" << m_B << endl;
		cout << "mC:" << m_C << endl;
	}
private:
	int m_A;
	int m_B;
	int m_C;
};

int main() {

	Person p(1, 2, 3);
	p.PrintPerson();

	system("pause");

	return 0;
}
```





#### 4.2.7 类对象作为类成员



C++类中的成员可以是另一个类的对象，我们称该成员为 对象成员



例如：

```C++
class A {}
class B
{
    A a；
}
```



B类中有对象A作为成员，A为对象成员



那么当创建B对象时，A与B的构造和析构的顺序是谁先谁后？



**示例：**

```C++
//*********類對象作為類成員*********
//C++类中的成员可以是另一个类的对象，我们称该成员为 对象成员
//那么当创建B对象时，A与B的构造和析构的顺序是谁先谁后？

#include<iostream>
using namespace std;

//手機類
class Phone
{
public:
	Phone(string name)
	{
		m_PhoneName = name;
		cout << "Phone构造" << endl;
	}

	~Phone()
	{
		cout << "Phone析构" << endl;
	}

	//手機品牌名稱
	string m_PhoneName;

};

//人類
class Person
{
public:

	//初始化列表可以告诉编译器调用哪一个构造函数
	Person(string name, string pName) :m_Name(name), m_Phone(pName)		//Phone m_Phone = pName 隱式轉換法
	{
		cout << "Person构造" << endl;
	}

	~Person()
	{
		cout << "Person析构" << endl;
	}

	void playGame()
	{
		cout << m_Name << " 使用" << m_Phone.m_PhoneName << " 牌手机! " << endl;
	}

	string m_Name;
	Phone m_Phone;

};

void test01()
{
	//当类中成员是其他类对象时，我们称该成员为 对象成员
	//构造的顺序是 ：先调用对象成员的构造，再调用本类构造
	//析构顺序与构造相反
	Person p("张三" , "苹果X");
	p.playGame();

}

int main() {

	test01();

	system("pause");

	return 0;
}
```











#### 4.2.8 静态成员

静态成员就是在成员变量和成员函数前加上关键字static，称为静态成员

静态成员分为：



*  静态成员变量
   *  所有对象共享同一份数据
   *  在编译之前就已經分配内存，並分配在全局區
   *  类内声明，类外初始化
*  静态成员函数
   *  所有对象共享同一个函数
   *  静态成员函数只能访问静态成员变量







**示例1** ：静态成员变量

```C++
//*********靜態成員變量*********

#include<iostream>
using namespace std;

//人類
class Person
{
	
public:

	static int m_A; //静态成员变量

	//静态成员变量特点：
	//1 在编译之前就已經分配内存，並分配在全局區
	//2 类内声明，类外初始化
	//3 所有对象共享同一份数据

//静态成员变量也是有访问权限的
private:
	static int m_B; 
};

int Person::m_A = 10;
int Person::m_B = 10;

void test01()
{
	//静态成员变量两种访问方式

	//1、通过对象
	Person p1;
	p1.m_A = 100;
	cout << "p1.m_A = " << p1.m_A << endl;

	Person p2;
	p2.m_A = 200;
	cout << "p1.m_A = " << p1.m_A << endl; //共享同一份数据
	cout << "p2.m_A = " << p2.m_A << endl;

	//2、通过类名
	cout << "m_A = " << Person::m_A << endl;


	//cout << "m_B = " << Person::m_B << endl; //私有权限访问不到
}

void test02(){
	//靜態成員變亮不屬於某個對象上，所有對象都共享同一份數據
	//因此靜態成員變量有兩種訪問方式

	//1. 通過對象進行訪問
	Person p;
	cout<<p.m_A<<endl;

	//2. 通過類名進行訪問
	cout<<Person::m_A<<endl;

	//cout << "m_B = " << Person::m_B << endl; //私有权限访问不到

}

int main() {

	test02();

	system("pause");

	return 0;
}
```



**示例2**：静态成员函数

```C++
//*********靜態成員函數*********

#include<iostream>
using namespace std;

class Person
{

public:

	//静态成员函数特点：
	//1 所有對象共享一个函数
	//2 静态成员函数只能访问静态成员变量
	
	static void func()
	{
		cout << "func调用" << endl;
		m_A = 100;	//靜態成員函數可以訪問靜態成員變量
		//m_B = 100; //错误，不可以访问非静态成员变量，無法缺分到底是哪個對象的m_B
	}

	static int m_A; //静态成员变量
	int m_B; // 
private:

	//静态成员函数也是有访问权限的
	static void func2()
	{
		cout << "func2调用" << endl;
	}
};
int Person::m_A = 10;


void test01()
{
	//静态成员变量两种访问方式

	//1、通过对象進行訪問
	Person p1;
	p1.func();

	//2、通过类名進行訪問
	Person::func();


	//Person::func2(); //類外訪問不到私有权限的靜態函數
}

int main() {

	test01();

	system("pause");

	return 0;
}
```








