# C++核心编程

本阶段主要针对C++==面向对象==编程技术做详细讲解，探讨C++中的核心和精髓。

## 3 函数提高

### 3.1 函数默认参数



在C++中，函数的形参列表中的形参是可以有默认值的。
语法：` 返回值类型  函数名 （参数= 默认值）{}`

**注意事項：**
1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
2. 如果函数声明有默认值，函数实现的时候就不能有默认参数


**示例**：

```C++
//*********函數默認參數*********
//在C++中，函数的形参列表中的形参是可以有默认值的。
//语法：` 返回值类型  函数名 （参数= 默认值）{}`

#include<iostream>
using namespace std;

//如果我們自己傳入的話就用自己的數據，如果沒有傳入自己的數據就用默認值
//语法：` 返回值类型  函数名 （参数 = 默认值）{}`
int func(int a, int b = 10, int c = 10) {
	return a + b + c;
}

//注意事項
//1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
//2. 如果函数声明有默认值，函数实现的时候就不能有默认参数
//聲明和實現只能有一個有默認參數
int func2(int a = 10, int b = 10);
int func2(int a, int b) {
	return a + b;
}

int main() {

	cout << "result = " << func(20, 20) << endl;
	cout << "result = " << func(100) << endl;

	cout << "result = " << func2(20, 20) << endl;
	cout << "result = " << func2(100) << endl;

	system("pause");

	return 0;
}
```







### 3.2 函数占位参数



C++中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置


**重點：**
* **语法**： `返回值类型 函数名 (数据类型){}`
* 在现阶段函数的占位参数存在意义不大，但是后面的课程中会用到该技术
* 函数占位参数 ，占位参数也可以有默认参数



**示例**：

```C++
//*********函數佔位參數*********
//语法： `返回值类型 函数名 (数据类型){}`
//目前階段的佔位參數目前還用不到，後面課程會用到

#include<iostream>
using namespace std;

//函数占位参数 ，占位参数也可以有默认参数
//语法： `返回值类型 函数名 (数据类型){}`
void func(int a, int = 10) {
	cout << "this is func" << endl;
}
//目前階段的佔位參數目前還用不到，後面課程會用到

int main() {

	func(10,10); //占位参数必须填补

	system("pause");

	return 0;
}
```









### 3.3 函数重载

#### 3.3.1 函数重载概述



**作用**：函数名可以相同，提高复用性



**函数重载满足条件**：

* 同一个作用域下
* 函数名称相同
* 函数参数**类型不同**  或者 **个数不同** 或者 **顺序不同**



**注意**:  函数的返回值不可以作为函数重载的条件



**示例**：

```C++
//*********函數重載概述*********
//可以讓函數名稱相同，提高覆用性


#include<iostream>
using namespace std;

//函數重載的滿足條件

//1. 函数重载需要函数都在同一个作用域下

void func()
{
	cout << "func 的调用！" << endl;
}

//2. 函數名稱相同
void func(int a)
{
	cout << "func (int a) 的调用！" << endl;
}

//3. 函數參數類型不同，或者函數參數個數不同，或者函數參數順序不同
void func(double a)
{
	cout << "func (double a)的调用！" << endl;
}

void func(int a ,double b)
{
	cout << "func (int a ,double b) 的调用！" << endl;
}

void func(double a ,int b)
{
	cout << "func (double a ,int b)的调用！" << endl;
}

//函数返回值不可以作为函数重载条件
//int func(double a, int b)
//{
//	cout << "func (double a ,int b)的调用！" << endl;
//}


int main() {

	func();
	func(10);
	func(3.14);
	func(10,3.14);
	func(3.14 , 10);
	
	system("pause");

	return 0;
}
```













#### 3.3.2 函数重载注意事项



* 引用作为重载条件
* 函数重载碰到函数默认参数





**示例**：

```C++
//*********函數重載注意事項*********
//在C++中，函数的形参列表中的形参是可以有默认值的。

#include<iostream>
using namespace std;

//函数重载注意事项
//1、引用作为重载条件
void func(int &a)	//int & a = 10; 10是在常數區裡面，所以是不合法的
{
	cout << "func (int &a) 调用 " << endl;
}

void func(const int &a)	// const int & a = 10; = int temp = 10; const int & a = temp;
{
	cout << "func (const int &a) 调用 " << endl;
}

//2、函数重载碰到函数默认参数
void func2(int a, int b = 10)
{
	cout << "func2(int a, int b = 10) 调用" << endl;
}

void func2(int a)
{
	cout << "func2(int a) 调用" << endl;
}

int main() {
	
	int a = 10;
	func(a); //调用无const
	func(10);//调用有const

	//func2(10); //碰到默认参数产生歧义，需要避免

	system("pause");

	return 0;
}
```







