### 4.5 运算符重载



运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型



#### 4.5.1 加号运算符重载



**作用**：实现两个自定义数据类型相加的运算
重點整理：
* `operator+` 是編譯器內建的函數運算符
* 如果你把全部運算式寫成都寫成 `Person p3 = p2 + p1;` 這種格式，編譯器會不知道你是要調用成員函數還是全局函數
* 建議可以寫成`Person p6 = p4 + p5`這種格式


```C++
//**************加號運算符重載**************
//运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
//作用：实现两个自定义数据类型相加的运算

#include<iostream>
using namespace std;

class Person {
public:
	Person() {};	//默認無參構造函數
	Person(int a, int b)	//有參構造函數
	{
		this->m_A = a;
		this->m_B = b;
	}
	//成员函数实现 + 号运算符重载
	//operator+ 是編譯器內建的
	Person operator+(const Person& p) {
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}

public:
	int m_A;
	int m_B;
};

//全局函数实现 + 号运算符重载
Person operator+(const Person& p1, const Person& p2) {
	Person temp(0, 0);
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}

//运算符重载 可以发生函数重载 
Person operator+(const Person& p2, int val)  
{
	Person temp;
	temp.m_A = p2.m_A + val;
	temp.m_B = p2.m_B + val;
	return temp;
}

void test() {

	Person p1(10, 10);
	Person p2(20, 20);

	//成员函数重載方式調用
	Person p3 = p2 + p1;  //相当于 Person p3 = p2.operaor+(p1)
	cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;

	Person p4(10, 10);
	Person p5(20, 20);
	//全局函數重載調用
	Person p6 = operator+(p4,p5);	//也可以寫成 Person p6 = p4 + p5
	cout << "mA:" << p6.m_A << " mB:" << p6.m_B << endl;
	Person p7 = p6 + 10; //相当于 Person p7 = operator+(p6,10)
	cout << "mA:" << p7.m_A << " mB:" << p7.m_B << endl;

	//注意： 如果你全部都寫成 Person p3 = p2 + p1; 這種格式，編譯器會不知道你是要調用成員函數還是全局函數

}

int main() {

	test();

	system("pause");

	return 0;
}
```



> 总结1：对于内置的数据类型的表达式的的运算符是不可能改变的

> 总结2：不要滥用运算符重载







#### 4.5.2 左移运算符重载



**作用**：可以输出自定义数据类型
**例如**：你創建一個`class Person`，則`cout<<Person<<endl;` 可以輸出Person類裡面的所有屬性，就要使用`左移运算符重载`

**重點整理：**
* 製作左移運算符重載的函數，一定要在全局下新增
* 在 `vscode` 可以點擊 `cout` 並按下 `alt + F12`，即可查看 `cout` 的原碼


**input**
```C++ {.line-numbers}
//**************左移运算符重载**************
//作用：可以输出自定义数据类型

#include<iostream>
using namespace std;

class Person {
	//利用成員函數重載左移運算符
	//friend ostream& operator<<(ostream& out, Person& p);
	friend void operator<<(ostream & cout, Person & p);

public:

	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}

	//利用成員函數重載左移運算符 p.operator<<(cout) 簡化版本 p<<cout
	//不會利用成員函數重載左移運算符(<<)，因為無法實現 cout 在左側
	//void operator<<(cout){
	//}

private:
	int m_A;
	int m_B;
};

//只能利用全局函數實現左移運算符(<<)
//在 vscode 可以點擊 `cout` 並按下 `alt + F12`，即可查看 cout的原碼
//可以看到 `cout` 的是在 `ostream` 創建出來的對象。
//補充： `ostream`為輸出流，`istream`為輸入流
void operator<<(ostream & cout, Person & p)	//本質 operator<<(cout, p) 可簡化成 cout<<p
{
	cout<<"m_A = "<<p.m_A<<"\t\t"<<"m_B = "<<p.m_B<<endl;
}

void test() {

	Person p1(10, 20);
	cout<<p1;
}

int main() {

	test();

	system("pause");

	return 0;
}
```
另外，如果在 `42` 行加上 `endl;` 就會報錯，因為 `34` 行的全局函數返回的並不是 `cout`，所以修改代碼如下


```c++ {.line-numbers}
//**************左移运算符重载**************
//作用：可以输出自定义数据类型

#include<iostream>
using namespace std;

class Person {
	//利用成員函數重載左移運算符
	friend ostream & operator<<(ostream & cout, Person & p);

public:

	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}

private:
	int m_A;
	int m_B;
};

//只能利用全局函數實現左移運算符(<<)
//在 vscode 可以點擊 `cout` 並按下 `alt + F12`，即可查看 cout的原碼
//可以看到 `cout` 的是在 `ostream` 創建出來的對象。
//補充： `ostream`為輸出流，`istream`為輸入流
ostream & operator<<(ostream & cout, Person & p)	//本質 operator<<(cout, p) 可簡化成 cout<<p
{
	cout<<"m_A = "<<p.m_A<<"\t\t"<<"m_B = "<<p.m_B<<endl;
	return cout;
}

void test() {

	Person p1(10, 20);
	cout<<p1<<endl;
}

int main() {

	test();

	system("pause");

	return 0;
}
```


> 总结：重载左移运算符配合友元可以实现输出自定义数据类型













#### 4.5.3 递增运算符重载



作用： 通过重载递增运算符，实现自己的整型数据



```C++ {.line-numbers}
//**************遞增运算符重载**************
//作用：通过重载递增运算符，实现自己的整型数据

#include<iostream>
using namespace std;

class MyInteger {

	friend ostream & operator<<(ostream & out, MyInteger myint);

public:
	MyInteger() {
		m_Num = 0;
	}
	//重載前置++運算符	返回引用是為了對同一個數據做增加
	MyInteger & operator++() {
		//先進行++運算
		m_Num++;
		//再將自身做返回
		return *this;
	}

	//重載后置++運算符
	MyInteger operator++(int) {	//int代表佔位參數，可以區分前置以及後置遞增
		//先返回
		MyInteger temp = *this; //记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
		m_Num++;
		//再將自身做返回
		return temp;
	}

	//重載前置--運算符	返回引用是為了對同一個數據做遞減
	MyInteger & operator--() {
		//先進行++運算
		m_Num--;
		//再將自身做返回
		return *this;
	}

	//重載后置--運算符
	MyInteger operator--(int) {	//int代表佔位參數，可以區分前置以及後置遞增
		//先返回
		MyInteger temp = *this; //记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
		m_Num++;
		//再將自身做返回
		return temp;
	}

private:
	int m_Num;
};

//重載左移運算符
ostream & operator<<(ostream & out, MyInteger myint) {
	out << myint.m_Num;
	return out;
}

//前置++ 先++ 再返回
void test01() {
	MyInteger myInt;
	cout << ++myInt << endl;
	cout << myInt << endl;
}

//后置++ 先返回 再++
void test02() {

	MyInteger myInt;
	cout << myInt++ << endl;
	cout << myInt << endl;
}

//前置-- 先-- 再返回
void test03() {
	MyInteger myInt;
	cout << --myInt << endl;
	cout << myInt << endl;
}

//后置-- 先返回 再--
void test04() {

	MyInteger myInt;
	cout << myInt-- << endl;
	cout << myInt << endl;
}

int main() {

	//test01();
	//test02();
	//test03();
    //test04();

    return 0;

	system("pause");

	return 0;
}
```



> 总结： 前置递增返回引用，后置递增返回值













#### 4.5.4 赋值运算符重载



c++编译器至少给一个类添加4个函数

1. 默认构造函数(无参，函数体为空)
2. 默认析构函数(无参，函数体为空)
3. 默认拷贝构造函数，对属性进行值拷贝
4. 赋值运算符 operator=, 对属性进行值拷贝



如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题



**示例：**

```C++ {.line-numbers}
//**************赋值运算符重载**************
//c++编译器至少给一个类添加4个函数
//1. 默认构造函数(无参，函数体为空)
//2. 默认析构函数(无参，函数体为空)
//3. 默认拷贝构造函数，对属性进行值拷贝
//4. 赋值运算符 operator=, 对属性进行值拷贝

#include<iostream>
using namespace std;

class Person
{
public:

	Person(int age)
	{
		//將年龄數據開闢到堆區
		m_Age = new int(age);
	}

	//重载赋值运算符 (=)
	Person & operator=(Person & p)
	{
		//编译器提供的代码是浅拷贝
		//m_Age = p.m_Age;


		//我們應該先判斷是否有屬性在堆區，如果有，先釋放乾淨，然後再深拷貝
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}

		//提供深拷贝 解决浅拷贝的问题
		m_Age = new int(*p.m_Age);

		//返回自身
		return *this;
	}

	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}

	//年龄的指针
	int *m_Age;

};

void test01()
{
	Person p1(18);

	Person p2(20);

	Person p3(30);

	p3 = p2 = p1; //赋值操作	//p2 = p1 相當於 p2.operator=(p1)

	cout << "p1的年龄为：" << *p1.m_Age << endl;

	cout << "p2的年龄为：" << *p2.m_Age << endl;

	cout << "p3的年龄为：" << *p3.m_Age << endl;
}

int main() {

	test01();

	//int a = 10;
	//int b = 20;
	//int c = 30;

	//我們想讓Person類值行這樣的賦值
	//c = b = a;
	//cout << "a = " << a << endl;
	//cout << "b = " << b << endl;
	//cout << "c = " << c << endl;

	system("pause");

	return 0;
}
```





#### 4.5.5 关系运算符重载



**作用**：重载关系运算符，可以让两个自定义类型对象进行对比操作



**示例：**

```C++ {.line-numbers}
//**************关系运算符重载**************
//作用：重载关系运算符，可以让两个自定义类型对象进行对比操作

#include<iostream>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	};

	bool operator==(Person & p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(Person & p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	string m_Name;
	int m_Age;
};

void test01()
{
	//int a = 0;
	//int b = 0;

	Person a("孙悟空", 18);
	Person b("孙悟空", 18);

	if (a == b)
	{
		cout << "a和b相等" << endl;
	}
	else
	{
		cout << "a和b不相等" << endl;
	}

	if (a != b)
	{
		cout << "a和b不相等" << endl;
	}
	else
	{
		cout << "a和b相等" << endl;
	}
}


int main() {

	test01();

	system("pause");

	return 0;
}
```





#### 4.5.6 函数调用运算符重载



* `函数调用运算符 ()`  也可以重载
* 由于重载后使用的方式非常像`函数`的调用，因此称为`仿函数`
* `仿函数`没有固定写法，非常灵活

**動點整理：**
1. 有用到`匿名對象`
2. 有用到 `函数调用运算符 ()`




**示例：**

```C++ {.line-numbers}
//**************函數調用運算符重載**************
//作用：重载关系运算符，可以让两个自定义类型对象进行对比操作

#include<iostream>
using namespace std;

//打印的類
class MyPrint
{
public:

	//重載()運算符
	void operator()(string text)
	{
		cout << text << endl;
	}

	int a =20;

};
void test01()
{
	MyPrint myFunc;

	//因為使用起來非常像是函數，所以也称为仿函数
	myFunc("hello world");	
}

//加法類
class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

void test02()
{
	MyAdd add;
	int ret = add(10, 10);
	cout << "ret = " << ret << endl;

	//匿名對象调用，調用完之後，會馬上釋放掉記憶體
	cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;
}

int main() {

	test01();
	test02();
	
	system("pause");

	return 0;
}
```








