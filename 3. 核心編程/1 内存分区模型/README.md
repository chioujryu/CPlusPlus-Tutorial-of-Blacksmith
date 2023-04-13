# C++核心编程

本阶段主要针对C++==面向对象==编程技术做详细讲解，探讨C++中的核心和精髓。



## 1 内存分区模型

C++程序在执行时，将内存大方向划分为**4个区域**

- **代码区**：存放函数体的二进制代码，由操作系统进行管理的
- **全局区**：存放全局变量和静态变量以及常量
- **栈区**：由编译器自动分配释放, 存放函数的参数值,局部变量等
- **堆区**：由程序员分配和释放,若程序员不释放,程序结束时由操作系统回收







**内存四区意义：**

不同区域存放的数据，赋予不同的生命周期, 给我们更大的灵活编程





### 1.1 程序运行前

​	在程序编译后，生成了exe可执行程序，**未执行该程序前**分为两个区域

​	**代码区：**

​		存放 CPU 执行的机器指令

​		代码区是**共享**的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可

​		代码区是**只读**的，使其只读的原因是防止程序意外地修改了它的指令

​	**全局区：**

​		全局变量和静态变量存放在此.

​		全局区还包含了常量区, 字符串常量和其他常量也存放在此.

​		==该区域的数据在程序结束后由操作系统释放==.













**示例：**

```c++
#include<iostream>
using namespace std;

//全局變數
int g_a = 10;
int g_b = 10;

//const修飾的全局變數 = 全局常數
const int c_g_a = 10;
const int c_g_b = 10;


int main(){

	//創建普通局部變數
	int a = 10;
	int b = 10;

	//打印地址
	cout << "局部變數a地址为： " << (int)&a << endl;
	cout << "局部變數b地址为： " << (int)&b << endl;

	cout << "全局變數g_a地址为： " <<  (int)&g_a << endl;
	cout << "全局變數g_b地址为： " <<  (int)&g_b << endl;

	//靜態變量，在普通便量前面加static，就屬於靜態變量
	static int s_a = 10;
	static int s_b = 10;
	cout << "静态變數s_a地址为： " << (int)&s_a << endl;
	cout << "静态變數s_b地址为： " << (int)&s_b << endl;

	//常數
	//字符串常數
	cout << "字符串常數地址为： " << (int)&"hello world" << endl;
	cout << "字符串常數地址为： " << (int)&"hello world1" << endl;

	//const修飾的變數、
	//const修飾的全局變數
	cout << "全局常數c_g_a地址为： " << (int)&c_g_a << endl;
	cout << "全局常數c_g_b地址为： " << (int)&c_g_b << endl;

	//const修飾的局部變數
	//c-const   g-global    l-local
	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "局部常數c_l_a地址为： " << (int)&c_l_a << endl;
	cout << "局部常數c_l_b地址为： " << (int)&c_l_b << endl;

	system("pause");

	return 0;
}
```

打印结果：

![1545017602518](assets/1545017602518.png)



总结：

* C++中在程序运行前分为全局区和代码区
* 代码区特点是共享和只读
* 全局区中存放全局变量、静态变量、常量
* 常量区中存放 const修饰的全局常量  和 字符串常量






### 1.2 程序运行后



​	**栈区：**

​		由编译器自动分配释放, 存放函数的参数值,局部变量等

​		**注意事项**：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放



**示例：**

```c++
#include<iostream>
using namespace std;

//棧區數據的注意事項 -- 不要返回局部變量的地址
//棧區的數據由編譯器管理開闢與釋放

int * func(int b) //型參數據也會放在棧區
{
	b = 100;
	int a = 10;	//局部變量，存放在棧區，棧區的數據在函數執行完後自動釋放
	return &a;	//返回局部變量的地址
}

int main(){

	int * p = func(1);	//第一次可以打印正確的數字，是因為編譯器做了保留
	cout<<*p<<endl;		//第二次這個數據就不再保留了
	return 0;
}
```







​	**堆区：**

​		由程序员分配释放,若程序员不释放,程序结束时由操作系统回收

​		在C++中主要利用`new`在堆区开辟内存

**示例：**

```c++
#include<iostream>
using namespace std;

int * func() //型參數據也會放在棧區
{
	//利用new關鍵字，可以將數據開闢到堆區
	//指針本質也是局部變量，放在棧上，則指針保存的數據是放在堆區
	int * p = new int(10);
	return p;
}

int main(){

	//開闢數據內存
	int * p = func();
	cout<<*p<<endl;		
	
	system("pause");
	return 0;
}
```



**总结：**

堆区数据由程序员管理开辟和释放

堆区数据利用new关键字进行开辟内存









### 1.3 new操作符



​	C++中利用==new==操作符在堆区开辟数据

​	堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符 ==delete==

​	语法：` new 数据类型`

​	利用new创建的数据，会返回该数据对应的类型的指针



**示例1： 基本语法**

```c++
#include<iostream>
using namespace std;


//1. new的基本語法
int * func()
{
	//在堆區創建整形數據
	//new返回是 該數據類型的指針
	int * p = new int(10);
	return p;
}

int test01() 
{
	int * p = func();
	cout<<*p<<endl;

	//堆區的數據由程序員管理開闢，程序員管理釋放
	//如果想釋放堆區的數據，利用關鍵字delete
	delete p;

	cout<<*p<<endl;	//內存已經被釋放，再訪問一次就會報錯
}

int main(){
	test01();
}
```



**示例2：开辟数组**

```c++
#include<iostream>
using namespace std;


//1. new的基本語法
int * func()
{
	//在堆區創建整形數據
	//new返回是 該數據類型的指針
	int * p = new int(10);
	return p;
}

int test01() 
{
	int * p = func();
	cout<<*p<<endl;

	//堆區的數據由程序員管理開闢，程序員管理釋放
	//如果想釋放堆區的數據，利用關鍵字delete
	delete p;

	cout<<*p<<endl;	//內存已經被釋放，再訪問一次就會報錯或是亂碼
}

//2. 在堆區利用new開闢數組
void test02()
{
	//創建10個整型數據的數組，在堆區
	int * arr = new int[10];	//10代表數組有10個元素

	for (int i = 0 ; i < 10 ; i++)
	{
		arr[i] = i + 100;	//給10個元素賦予數值  100~109
	}

	//打印數組
	for (int i = 0 ; i < 10 ; i++)
	{
		cout<<arr[i]<<endl;
	}

	//釋放堆區數組
	//釋放數組的時候要加上[]才可以
	delete[] arr;

}

int main(){
	test01();
	test02();
}

```