# C++核心編程

本階段主要針對C++==面向對象==編程技術做詳細講解，探討C++中的核心和精髓。

## 2 引用

### 2.1 引用的基本使用

**作用：** 給變量起別名

**語法：** `數據類型 &別名 = 原名`



**示例：**

```C++
#include<iostream>
using namespace std;

int main(){
	//引用基本語法
	//數據類型 &別名 = 原名

	int a = 10;
	//創建引用
	int &b = a;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	b = 100;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	system("pause");

	return 0;
}
```







### 2.2 引用注意事項

* 引用必須初始化
* 引用在初始化後，不可以改變

示例：

```C++
#include<iostream>
using namespace std;

//引用必須要初始化
//初始化後就不能變了

int main() {

	int a = 10;
	int b = 20;

	//1. 引用必須初始化
	//int &c; //錯誤，引用必須初始化
	int &c = a; //一旦初始化後，就不可以更改

	//2. 引用在初始化後，不可以改變
	c = b; //這是賦值操作，不是更改引用

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	system("pause");

	return 0;
}
```











### 2.3 引用做函數參數

**作用**：函數傳參時，可以利用引用的技術讓形參修飾實參

**優點**：可以簡化指針修改實參



**示例**：

```C++
//*********引用做函數參數**********
//作用：函數傳參時，可以利用引用的技術讓形參修飾實參
//優點：可以簡化指針修改實參

#include<iostream>
using namespace std;

//交換函數

//1. 值傳遞
void mySwap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;

}

//2. 地址傳遞
void mySwap02(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//3. 引用傳遞
void mySwap03(int & a, int & b) {	//引用其實就是起別名
	int temp = a;
	a = b;
	b = temp;
}

int main() {

	int a = 10;
	int b = 20;

	//1. 值傳遞
	//形參不會修飾實參
	mySwap01(a, b);
	cout << "a:" << a << " b:" << b << endl;

	//2. 地址傳遞
	mySwap02(&a, &b);
	cout << "a:" << a << " b:" << b << endl;

	//3. 引用傳遞
	mySwap03(a, b);
	cout << "a:" << a << " b:" << b << endl;

	system("pause");

	return 0;
}
```



> 總結：通過引用參數產生的效果同按地址傳遞是一樣的。引用的語法更清楚簡單













### 2.4 引用做函數返回值



作用：引用是可以作為函數的返回值存在的



注意：**不要返回局部變量引用**

用法：函數調用作為左值



**示例**：

```C++
//*********引用做函數返回值**********
//作用：引用是可以作為函數的返回值存在的
//注意：不要返回局部變量引用

#include<iostream>
using namespace std;

//返回局部變量引用
//1. 不要返回局部變量的引用
int & test01() {
	int a = 10; //局部變量
	return a;
}

//2. 可以返回靜態變量引用
int & test02() {
	static int a = 20;	//靜態變量存放在全局區，全局區上的數據在程序結束後系統釋放
	return a;
}

int main() {


	//不能返回局部變量的引用
	int& ref = test01();
	cout << "ref = " << ref << endl;	//第一次結果正確，是因為編譯器做了保留
	cout << "ref = " << ref << endl;	//第二次是錯誤的，因為a的內存已經釋放

	//如果函數做左值，那麼必須返回引用
	int & ref2 = test02();
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	//如果函數的返回值是引用，這個函數調用可以作為左值
	test02() = 1000;	// test02() = a
						// ref2 = a

	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	system("pause");

	return 0;
}
```





​	









### 2.5 引用的本質

* 本質：**引用的本質在c++內部實現是一個指針常量.**，所以引用才會初始化後，就無法改變。
* `int a = 10; int & ref = a;` = `int* const ref = &a`

講解示例：

```C++
//*********引用的本質**********
//本質：引用的本質在c++內部實現是一個`指針常量`

#include<iostream>
using namespace std;

//發現是引用，轉換為 int* const ref = &a;
void func(int & ref){
	ref = 100; // ref是引用，轉換為*ref = 100
}

int main(){
	int a = 10;
    
    //自動轉換為 int* const ref = &a; 指針常量是指針指向不可改，也說明為什麼引用不可更改
	int & ref = a; 
	ref = 20; //內部發現ref是引用，自動幫我們轉換為: *ref = 20;
    
	cout << "a:" << a << endl;
	cout << "ref:" << ref << endl;
    
	func(a);
	cout << "a:" << a << endl;
	cout << "ref:" << ref << endl;

	return 0;

	//結論：C++推薦用引用技術，因為語法方便，引用本質是指針常量，但是所有的指針操作編譯器都幫我們做了
}
```

結論：C++推薦用引用技術，因為語法方便，引用本質是指針常量，但是所有的指針操作編譯器都幫我們做了













### 2.6 常量引用



* **作用**：常量引用主要用來修飾形參，防止誤操作

* 在函數形參列表中，可以加==const修飾形參==，防止形參改變實參

* `const int & ref = 10;` = `int temp = 10; const int& ref = temp;`



**示例：**



```C++
//*********常量引用**********
//作用：引用使用的場景，通常用來修飾形參，防止誤操作

#include<iostream>
using namespace std;

//打印數據函數
void showValue(const int& v) {	
	//v += 10;	//因有形參有const所以v無法修改，就是為了誤操作
	cout << v << endl;
}

int main() {

	//int& ref = 10;  引用本身需要一個合法的內存空間，因此這行錯誤
	//加入const就可以了，編譯器優化代碼，int temp = 10; const int& ref = temp;
	const int & ref = 10;

	//ref = 100;  //加入const後不可以修改變量
	cout << ref << endl;

	//函數中利用常量引用防止誤操作修改實參
	int a = 10;
	showValue(a);
	cout << a << endl;

	system("pause");

	return 0;
}
```



