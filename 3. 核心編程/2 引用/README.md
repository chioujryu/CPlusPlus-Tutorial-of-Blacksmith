# C++核心编程

本阶段主要针对C++==面向对象==编程技术做详细讲解，探讨C++中的核心和精髓。

## 2 引用

### 2.1 引用的基本使用

**作用：** 给变量起别名

**语法：** `数据类型 &别名 = 原名`



**示例：**

```C++
#include<iostream>
using namespace std;

int main(){
	//引用基本語法
	//数据类型 &别名 = 原名

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







### 2.2 引用注意事项

* 引用必须初始化
* 引用在初始化后，不可以改变

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
	//int &c; //错误，引用必须初始化
	int &c = a; //一旦初始化后，就不可以更改

	//2. 引用在初始化後，不可以改變
	c = b; //这是赋值操作，不是更改引用

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	system("pause");

	return 0;
}
```











### 2.3 引用做函数参数

**作用**：函数传参时，可以利用引用的技术让形参修饰实参

**优点**：可以简化指针修改实参



**示例**：

```C++
//*********引用做函数参数**********
//作用：函数传参时，可以利用引用的技术让形参修饰实参
//优点：可以简化指针修改实参

#include<iostream>
using namespace std;

//交換函數

//1. 值传递
void mySwap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;

}

//2. 地址传递
void mySwap02(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//3. 引用传递
void mySwap03(int & a, int & b) {	//引用其實就是起別名
	int temp = a;
	a = b;
	b = temp;
}

int main() {

	int a = 10;
	int b = 20;

	//1. 值传递
	//形參不會修飾實參
	mySwap01(a, b);
	cout << "a:" << a << " b:" << b << endl;

	//2. 地址传递
	mySwap02(&a, &b);
	cout << "a:" << a << " b:" << b << endl;

	//3. 引用传递
	mySwap03(a, b);
	cout << "a:" << a << " b:" << b << endl;

	system("pause");

	return 0;
}
```



> 总结：通过引用参数产生的效果同按地址传递是一样的。引用的语法更清楚简单













### 2.4 引用做函数返回值



作用：引用是可以作为函数的返回值存在的



注意：**不要返回局部变量引用**

用法：函数调用作为左值



**示例**：

```C++
//*********引用做函數返回值**********
//作用：引用是可以作为函数的返回值存在的
//注意：不要返回局部变量引用

#include<iostream>
using namespace std;

//返回局部变量引用
//1. 不要返回局部變量的引用
int & test01() {
	int a = 10; //局部变量
	return a;
}

//2. 可以返回静态变量引用
int & test02() {
	static int a = 20;	//靜態變量存放在全局區，全局區上的數據在程序結束後系統釋放
	return a;
}

int main() {


	//不能返回局部变量的引用
	int& ref = test01();
	cout << "ref = " << ref << endl;	//第一次結果正確，是因為編譯器做了保留
	cout << "ref = " << ref << endl;	//第二次是錯誤的，因為a的內存已經釋放

	//如果函数做左值，那么必须返回引用
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









### 2.5 引用的本质

* 本质：**引用的本质在c++内部实现是一个指针常量.**，所以引用才會初始化後，就無法改變。
* `int a = 10; int & ref = a;` = `int* const ref = &a`

讲解示例：

```C++
//*********引用的本質**********
//本質：引用的本质在c++内部实现是一个`指针常量`

#include<iostream>
using namespace std;

//發現是引用，轉換為 int* const ref = &a;
void func(int & ref){
	ref = 100; // ref是引用，转换为*ref = 100
}

int main(){
	int a = 10;
    
    //自动转换为 int* const ref = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改
	int & ref = a; 
	ref = 20; //内部发现ref是引用，自动帮我们转换为: *ref = 20;
    
	cout << "a:" << a << endl;
	cout << "ref:" << ref << endl;
    
	func(a);
	cout << "a:" << a << endl;
	cout << "ref:" << ref << endl;

	return 0;

	//结论：C++推荐用引用技术，因为语法方便，引用本质是指针常量，但是所有的指针操作编译器都帮我们做了
}
```

结论：C++推荐用引用技术，因为语法方便，引用本质是指针常量，但是所有的指针操作编译器都帮我们做了













### 2.6 常量引用



* **作用**：常量引用主要用来修饰形参，防止误操作

* 在函数形参列表中，可以加==const修饰形参==，防止形参改变实参

* `const int & ref = 10;` = `int temp = 10; const int& ref = temp;`



**示例：**



```C++
//*********常量引用**********
//作用：引用使用的场景，通常用来修饰形参，防止誤操作

#include<iostream>
using namespace std;

//打印數據函數
void showValue(const int& v) {	
	//v += 10;	//因有形參有const所以v無法修改，就是為了誤操作
	cout << v << endl;
}

int main() {

	//int& ref = 10;  引用本身需要一个合法的内存空间，因此这行错误
	//加入const就可以了，编译器优化代码，int temp = 10; const int& ref = temp;
	const int & ref = 10;

	//ref = 100;  //加入const后不可以修改变量
	cout << ref << endl;

	//函数中利用常量引用防止误操作修改实参
	int a = 10;
	showValue(a);
	cout << a << endl;

	system("pause");

	return 0;
}
```



