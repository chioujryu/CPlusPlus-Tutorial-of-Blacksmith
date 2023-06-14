# C++核心編程

本階段主要針對C++==面向對象==編程技術做詳細講解，探討C++中的核心和精髓。

## 3 函數提高

### 3.1 函數默認參數



在C++中，函數的形參列表中的形參是可以有默認值的。
語法：` 返回值類型  函數名 （參數= 默認值）{}`

**注意事項：**
1. 如果某個位置參數有默認值，那麼從這個位置往後，從左向右，必須都要有默認值
2. 如果函數聲明有默認值，函數實現的時候就不能有默認參數


**示例**：

```C++
//*********函數默認參數*********
//在C++中，函數的形參列表中的形參是可以有默認值的。
//語法：` 返回值類型  函數名 （參數= 默認值）{}`

#include<iostream>
using namespace std;

//如果我們自己傳入的話就用自己的數據，如果沒有傳入自己的數據就用默認值
//語法：` 返回值類型  函數名 （參數 = 默認值）{}`
int func(int a, int b = 10, int c = 10) {
	return a + b + c;
}

//注意事項
//1. 如果某個位置參數有默認值，那麼從這個位置往後，從左向右，必須都要有默認值
//2. 如果函數聲明有默認值，函數實現的時候就不能有默認參數
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







### 3.2 函數佔位參數



C++中函數的形參列表裡可以有佔位參數，用來做佔位，調用函數時必須填補該位置


**重點：**
* **語法**： `返回值類型 函數名 (數據類型){}`
* 在現階段函數的佔位參數存在意義不大，但是後面的課程中會用到該技術
* 函數佔位參數 ，佔位參數也可以有默認參數



**示例**：

```C++
//*********函數佔位參數*********
//語法： `返回值類型 函數名 (數據類型){}`
//目前階段的佔位參數目前還用不到，後面課程會用到

#include<iostream>
using namespace std;

//函數佔位參數 ，佔位參數也可以有默認參數
//語法： `返回值類型 函數名 (數據類型){}`
void func(int a, int = 10) {
	cout << "this is func" << endl;
}
//目前階段的佔位參數目前還用不到，後面課程會用到

int main() {

	func(10,10); //佔位參數必須填補

	system("pause");

	return 0;
}
```









### 3.3 函數重載

#### 3.3.1 函數重載概述



**作用**：函數名可以相同，提高複用性



**函數重載滿足條件**：

* 同一個作用域下
* 函數名稱相同
* 函數參數**類型不同**  或者 **個數不同** 或者 **順序不同**



**注意**:  函數的返回值不可以作為函數重載的條件



**示例**：

```C++
//*********函數重載概述*********
//可以讓函數名稱相同，提高覆用性


#include<iostream>
using namespace std;

//函數重載的滿足條件

//1. 函數重載需要函數都在同一個作用域下

void func()
{
	cout << "func 的調用！" << endl;
}

//2. 函數名稱相同
void func(int a)
{
	cout << "func (int a) 的調用！" << endl;
}

//3. 函數參數類型不同，或者函數參數個數不同，或者函數參數順序不同
void func(double a)
{
	cout << "func (double a)的調用！" << endl;
}

void func(int a ,double b)
{
	cout << "func (int a ,double b) 的調用！" << endl;
}

void func(double a ,int b)
{
	cout << "func (double a ,int b)的調用！" << endl;
}

//函數返回值不可以作為函數重載條件
//int func(double a, int b)
//{
//	cout << "func (double a ,int b)的調用！" << endl;
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













#### 3.3.2 函數重載注意事項



* 引用作為重載條件
* 函數重載碰到函數默認參數





**示例**：

```C++
//*********函數重載注意事項*********
//在C++中，函數的形參列表中的形參是可以有默認值的。

#include<iostream>
using namespace std;

//函數重載注意事項
//1、引用作為重載條件
void func(int &a)	//int & a = 10; 10是在常數區裡面，所以是不合法的
{
	cout << "func (int &a) 調用 " << endl;
}

void func(const int &a)	// const int & a = 10; = int temp = 10; const int & a = temp;
{
	cout << "func (const int &a) 調用 " << endl;
}

//2、函數重載碰到函數默認參數
void func2(int a, int b = 10)
{
	cout << "func2(int a, int b = 10) 調用" << endl;
}

void func2(int a)
{
	cout << "func2(int a) 調用" << endl;
}

int main() {
	
	int a = 10;
	func(a); //調用無const
	func(10);//調用有const

	//func2(10); //碰到默認參數產生歧義，需要避免

	system("pause");

	return 0;
}
```







