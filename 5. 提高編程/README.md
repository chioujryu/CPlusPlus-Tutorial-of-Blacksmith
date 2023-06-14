# C++提高編程




* 本階段主要針對C++**泛型編程**和**STL**技術做詳細講解，探討C++更深層的使用

- [C++提高編程](#c提高編程)
	- [1 模板](#1-模板)
		- [1.1 模板的概念](#11-模板的概念)
		- [1.2 函數模板](#12-函數模板)
			- [1.2.1 函數模板語法](#121-函數模板語法)
			- [1.2.2 函數模板注意事項](#122-函數模板注意事項)
			- [1.2.3 函數模板案例](#123-函數模板案例)
			- [1.2.4 普通函數與函數模板的區別](#124-普通函數與函數模板的區別)
			- [1.2.5 普通函數與函數模板的調用規則](#125-普通函數與函數模板的調用規則)
			- [1.2.6 模板的侷限性](#126-模板的侷限性)
		- [1.3 類模板](#13-類模板)
			- [1.3.1 類模板語法](#131-類模板語法)
			- [1.3.2 類模板與函數模板區別](#132-類模板與函數模板區別)
			- [1.3.3 類模板中成員函數創建時機](#133-類模板中成員函數創建時機)
			- [1.3.4 類模板對象做函數參數](#134-類模板對象做函數參數)
			- [1.3.5 類模板與繼承](#135-類模板與繼承)
			- [1.3.6 類模板成員函數類外實現](#136-類模板成員函數類外實現)
			- [1.3.7 類模板分文件編寫](#137-類模板分文件編寫)
			- [1.3.8 類模板與友元](#138-類模板與友元)
			- [1.3.9 類模板案例](#139-類模板案例)
	- [2 STL初識](#2-stl初識)
		- [2.1 STL的誕生](#21-stl的誕生)
		- [2.2 STL基本概念](#22-stl基本概念)
		- [2.3 STL六大組件](#23-stl六大組件)
		- [2.4  STL中容器、算法、迭代器](#24--stl中容器算法迭代器)
		- [2.5 容器算法迭代器初識](#25-容器算法迭代器初識)
			- [2.5.1 vector存放內置數據類型](#251-vector存放內置數據類型)
			- [2.5.2 Vector存放自定義數據類型](#252-vector存放自定義數據類型)
			- [2.5.3 Vector容器嵌套容器](#253-vector容器嵌套容器)
	- [3 STL- 常用容器](#3-stl--常用容器)
		- [3.1 string容器](#31-string容器)
			- [3.1.1 string基本概念](#311-string基本概念)
			- [3.1.2 string構造函數](#312-string構造函數)
			- [3.1.3 string賦值操作](#313-string賦值操作)
			- [3.1.4 string字符串拼接](#314-string字符串拼接)
			- [3.1.5 string查找和替換](#315-string查找和替換)
			- [3.1.6 string字符串比較](#316-string字符串比較)
			- [3.1.7 string字符存取](#317-string字符存取)
			- [3.1.8 string插入和刪除](#318-string插入和刪除)
			- [3.1.9 string子串](#319-string子串)
		- [3.2 vector容器](#32-vector容器)
			- [3.2.1 vector基本概念](#321-vector基本概念)
			- [3.2.2 vector構造函數](#322-vector構造函數)
			- [3.2.3 vector賦值操作](#323-vector賦值操作)
			- [3.2.4  vector容量和大小](#324--vector容量和大小)
			- [3.2.5 vector插入和刪除](#325-vector插入和刪除)
			- [3.2.6 vector數據存取](#326-vector數據存取)
			- [3.2.7 vector互換容器](#327-vector互換容器)
			- [3.2.8 vector預留空間](#328-vector預留空間)
		- [3.3 deque容器](#33-deque容器)
			- [3.3.1 deque容器基本概念](#331-deque容器基本概念)
			- [3.3.2 deque構造函數](#332-deque構造函數)
			- [3.3.3 deque賦值操作](#333-deque賦值操作)
			- [3.3.4 deque大小操作](#334-deque大小操作)
			- [3.3.5 deque 插入和刪除](#335-deque-插入和刪除)
			- [3.3.6 deque 數據存取](#336-deque-數據存取)
			- [3.3.7  deque 排序](#337--deque-排序)
		- [3.4 案例-評委打分](#34-案例-評委打分)
			- [3.4.1 案例描述](#341-案例描述)
			- [3.4.2 實現步驟](#342-實現步驟)
		- [3.5 stack容器](#35-stack容器)
			- [3.5.1 stack 基本概念](#351-stack-基本概念)
			- [3.5.2 stack 常用接口](#352-stack-常用接口)
		- [3.6 queue 容器](#36-queue-容器)
			- [3.6.1 queue 基本概念](#361-queue-基本概念)
			- [3.6.2 queue 常用接口](#362-queue-常用接口)
		- [3.7 list容器](#37-list容器)
			- [3.7.1 list基本概念](#371-list基本概念)
			- [3.7.2  list構造函數](#372--list構造函數)
			- [3.7.3 list 賦值和交換](#373-list-賦值和交換)
			- [3.7.4 list 大小操作](#374-list-大小操作)
			- [3.7.5 list 插入和刪除](#375-list-插入和刪除)
			- [3.7.6 list 數據存取](#376-list-數據存取)
			- [3.7.7 list 反轉和排序](#377-list-反轉和排序)
			- [3.7.8 排序案例](#378-排序案例)
		- [3.8 set/ multiset 容器](#38-set-multiset-容器)
			- [3.8.1 set基本概念](#381-set基本概念)
			- [3.8.2 set構造和賦值](#382-set構造和賦值)
			- [3.8.3 set大小和交換](#383-set大小和交換)
			- [3.8.4 set插入和刪除](#384-set插入和刪除)
			- [3.8.5 set查找和統計](#385-set查找和統計)
			- [3.8.6 set和multiset區別](#386-set和multiset區別)
			- [3.8.7 pair對組創建](#387-pair對組創建)
			- [3.8.8 set容器排序](#388-set容器排序)
		- [3.9 map/ multimap容器](#39-map-multimap容器)
			- [3.9.1 map基本概念](#391-map基本概念)
			- [3.9.2  map構造和賦值](#392--map構造和賦值)
			- [3.9.3 map大小和交換](#393-map大小和交換)
			- [3.9.4 map插入和刪除](#394-map插入和刪除)
			- [3.9.5 map查找和統計](#395-map查找和統計)
			- [3.9.6 map容器排序](#396-map容器排序)
		- [3.10 案例-員工分組](#310-案例-員工分組)
			- [3.10.1 案例描述](#3101-案例描述)
			- [3.10.2 實現步驟](#3102-實現步驟)
	- [4 STL- 函數對象](#4-stl--函數對象)
		- [4.1 函數對象](#41-函數對象)
			- [4.1.1 函數對象概念](#411-函數對象概念)
			- [4.1.2  函數對象使用](#412--函數對象使用)
		- [4.2  謂詞](#42--謂詞)
			- [4.2.1 謂詞概念](#421-謂詞概念)
			- [4.2.2 一元謂詞](#422-一元謂詞)
			- [4.2.3 二元謂詞](#423-二元謂詞)
		- [4.3 內建函數對象](#43-內建函數對象)
			- [4.3.1 內建函數對象意義](#431-內建函數對象意義)
			- [4.3.2 算術仿函數](#432-算術仿函數)
			- [4.3.3 關係仿函數](#433-關係仿函數)
			- [4.3.4 邏輯仿函數](#434-邏輯仿函數)
	- [5 STL- 常用算法](#5-stl--常用算法)
		- [5.1 常用遍歷算法](#51-常用遍歷算法)
			- [5.1.1 for\_each](#511-for_each)
			- [5.1.2 transform](#512-transform)
		- [5.2 常用查找算法](#52-常用查找算法)
			- [5.2.1 find](#521-find)
			- [5.2.2 find\_if](#522-find_if)
			- [5.2.3 adjacent\_find](#523-adjacent_find)
			- [5.2.4 binary\_search](#524-binary_search)
			- [5.2.5 count](#525-count)
			- [5.2.6 count\_if](#526-count_if)
		- [5.3 常用排序算法](#53-常用排序算法)
			- [5.3.1 sort](#531-sort)
			- [5.3.2 random\_shuffle](#532-random_shuffle)
			- [5.3.3 merge](#533-merge)
			- [5.3.4 reverse](#534-reverse)
		- [5.4 常用拷貝和替換算法](#54-常用拷貝和替換算法)
			- [5.4.1 copy](#541-copy)
			- [5.4.2 replace](#542-replace)
			- [5.4.3 replace\_if](#543-replace_if)
			- [5.4.4 swap](#544-swap)
		- [5.5 常用算術生成算法](#55-常用算術生成算法)
			- [5.5.1 accumulate](#551-accumulate)
			- [5.5.2 fill](#552-fill)
		- [5.6 常用集合算法](#56-常用集合算法)
			- [5.6.1 set\_intersection](#561-set_intersection)
			- [5.6.2 set\_union](#562-set_union)
			- [5.6.3  set\_difference](#563--set_difference)

<small><i><a href='http://ecotrust-canada.github.io/markdown-toc/'>Table of contents generated with markdown-toc</a></i></small>



## 1 模板

### 1.1 模板的概念



模板就是建立**通用的模具**，大大**提高複用性**



例如生活中的模板



一寸照片模板：



![1547105026929](assets/1547105026929.png)



PPT模板：

![1547103297864](assets/1547103297864.png)



![1547103359158](assets/1547103359158.png)





模板的特點：

* 模板不可以直接使用，它只是一個框架
* 模板的通用並不是萬能的









### 1.2 函數模板



* C++另一種編程思想稱爲 **泛型編程** ，主要利用的技術就是模板


* C++提供兩種模板機制:**函數模板**和**類模板** 



#### 1.2.1 函數模板語法

函數模板作用：

建立一個通用函數，其函數返回值類型和形參類型可以不具體制定，用一個**虛擬的類型**來代表。



**語法：** 

```C++
template<typename T>
函數聲明或定義
```

**解釋：**

template  ---  聲明創建模板

typename  --- 表面其後面的符號是一種數據類型，可以用class代替

T    ---   通用的數據類型，名稱可以替換，通常爲大寫字母



**示例：**

```C++

# include <iostream>
using namespace std;

//交換兩個整數
void swapInt(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


//交換兩個浮點數
void swapDouble(double &a, double &b){
    double temp = a;
    a = b;
    b = temp;
}

//函數模板
template<typename T>
void mySwap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}


void test01(){
    
    //定義參數
    int a = 10;
    int b = 20;
    double c = 10;
    double d = 20;

    //整數交換
    swapInt(a,b);
    cout<<"a = "<<a<<"\t"<<"b = "<<b<<endl;

    //浮點數交換
    swapDouble(c,d);
    cout<<"c = "<<c<<"\t"<< "d = "<<d<<endl;

    //利用函數模板交換
    //兩種方式使用函數模板

    //1. 自動類型推倒
    mySwap(a,b);
    cout<<"a = "<<a<<"\t"<<"b = "<<b<<endl;

    //2. 顯示指定類型
    mySwap<int>(a,b);
    cout<<"a = "<<a<<"\t"<<"b = "<<b<<endl;
}

int main(){
    test01();
}
```

總結：

* 函數模板利用關鍵字 template
* 使用函數模板有兩種方式：自動類型推導、顯示指定類型
* 模板的目的是爲了提高複用性，將類型參數化









#### 1.2.2 函數模板注意事項

注意事項：

* 自動類型推導，必須推導出一致的數據類型T,纔可以使用


* 模板必須要確定出T的數據類型，纔可以使用



**示例：**

```C++
# include <iostream>
using namespace std;

// 函數模板注意事項
template<class T> // typename可以替換成class，可以用，都一樣
void mySwap(T&a, T&b){
    T temp = a;
    a = b;
    b = temp;
}


//1. 自動類型推導，必須推導出一致的數據類型T才可以使用
void test01(){
    int a = 10;
    int b = 20;
    char c = 'c';
    mySwap(a,b); // 正確！！
    //mySwap(a,c); // 錯誤！！ 推導不出一致的T類型

    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
}

//2. 模板必須要確定出T的數據類型，才可以使用
template<class T>
void func(){
    cout<<"func調用"<<endl;
}

void test02()
{
    func<int>();    //直接定義出template的數據類型
}


int main()
{
    test01();
    test02();

	system("pause");

	return 0;
}
```

總結：

* 使用模板時必須確定出通用數據類型T，並且能夠推導出一致的類型











#### 1.2.3 函數模板案例

案例描述：

* 利用函數模板封裝一個排序的函數，可以對**不同數據類型數組**進行排序
* 排序規則從大到小，排序算法爲**選擇排序**
* 分別利用**char數組**和**int數組**進行測試



示例：

```C++
//交換的函數模板
template<typename T>
void mySwap(T &a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}


template<class T> // 也可以替換成typename
//利用選擇排序，進行對數組從大到小的排序
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i; //最大數的下標
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i) //如果最大數的下標不是i，交換兩者
		{
			mySwap(arr[max], arr[i]);
		}
	}
}
template<typename T>
void printArray(T arr[], int len) {

	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void test01()
{
	//測試char數組
	char charArr[] = "bdcfeagh";
	int num = sizeof(charArr) / sizeof(char);
	mySort(charArr, num);
	printArray(charArr, num);
}

void test02()
{
	//測試int數組
	int intArr[] = { 7, 5, 8, 1, 3, 9, 2, 4, 6 };
	int num = sizeof(intArr) / sizeof(int);
	mySort(intArr, num);
	printArray(intArr, num);
}

int main() {

	test01();
	test02();

	system("pause");

	return 0;
}
```

總結：模板可以提高代碼複用，需要熟練掌握











#### 1.2.4 普通函數與函數模板的區別



**普通函數與函數模板區別：**

* 普通函數調用時可以發生自動類型轉換（隱式類型轉換）
* 函數模板調用時，如果利用自動類型推導，不會發生隱式類型轉換
* 如果利用顯示指定類型的方式，可以發生隱式類型轉換



**示例：**

```C++
# include <iostream>
using namespace std;

// 普通函數與函數模板區別

//1. 普通函數調用可以發生隱式類型轉換
//2. 函數模板 用自動類型推導，不可以發生隱式類型轉換
//3. 函數模板 用顯示指定類型，可以發生隱式類型轉換



//普通函數
int AddTwoNumber(int a, int b)
{
    return a + b;
}

//函數模板
template<class T>
T AddTwoNumberAnyType(T a, T b)
{
    return a + b;
}

void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c';

    //1. 普通函數調用可以發生隱式類型轉換
    cout<<AddTwoNumber(a,b)<<endl;
    cout<<AddTwoNumber(a,c)<<endl;  // 將字串轉乘ASCII碼, c = 99, a = 97

    cout << AddTwoNumberAnyType(a, b) << endl;

    // 2. 函數模板 用自動類型推導，不可以發生隱式類型轉換
    //cout << AddTwoNumberAnyType(a, c) << endl;    //報錯

    //3. 函數模板 用顯示指定類型，可以發生隱式類型轉換
    cout<<AddTwoNumberAnyType<int>(a,c)<<endl;
}

int main()
{
    test01();
}
```

**總結：建議使用顯示指定類型的方式，調用函數模板，因爲可以自己確定通用類型T**











#### 1.2.5 普通函數與函數模板的調用規則



調用規則如下：

1. 如果函數模板和普通函數都可以實現，優先調用普通函數
2. 可以通過空模板參數列表來強制調用函數模板
3. 函數模板也可以發生重載
4. 如果函數模板可以產生更好的匹配,優先調用函數模板





**示例：**

```C++
# include <iostream>
using namespace std;

// 普通函數與函數模板的調用規則

//1. 如果函數模板與普通函數都可以調用，優先調用普通函數
//2. 可以通過空模板參數列表，強制調用 函數模板
//3. 函數模板可以發生函數重載
//4. 如果函數模板可以產生更好的匹配，優先調用函數模板

void MyPrint(int a, int b)
{
    cout<<"調用的是普通函數"<<endl;
}

template<class T>
void MyPrint(T a, T b)
{
    cout<<"調用的是模板"<<endl;
}

template<class T>
void MyPrint(T a, T b, T c)
{
    cout<<"調用的是重載的模板"<<endl;
}

void test01()
{
    int a = 10;
    int b = 20;

    //1. 如果函數模板與普通函數都可以調用，優先調用普通函數
    MyPrint(a, b);

    //2. 可以通過空模板參數列表，強制調用 函數模板
    MyPrint<>(a, b);

    //3. 函數模板可以發生函數重載
    MyPrint<>(a, b, 100);

    //4. 如果函數模板可以產生更好的匹配，優先調用函數模板
    //先調用函數模板是因為，調用普通函數還必須要把字符串轉換成整數，所以系統優先調用函數模板
    const char c1[] = "a";
    const char c2[] = "b";
    MyPrint(c1, c2);  
}

int main()
{
    test01();
}
```

**總結：既然提供了函數模板，最好就不要提供普通函數，否則容易出現二義性**











#### 1.2.6 模板的侷限性

**侷限性：**

* 模板的通用性並不是萬能的



**例如：**

```C++
	template<class T>
	void f(T a, T b)
	{ 
    	a = b;
    }
```

在上述代碼中提供的賦值操作，如果傳入的a和b是一個數組，就無法實現了



再例如：

```C++
	template<class T>
	void f(T a, T b)
	{ 
    	if(a > b) { ... }
    }
```

在上述代碼中，如果T的數據類型傳入的是像Person這樣的自定義數據類型，也無法正常運行



因此C++爲了解決這種問題，提供模板的重載，可以爲這些**特定的類型**提供**具體化的模板**



**示例：**

```C++
#include<iostream>
using namespace std;

#include <string>

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

//普通函數模板
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//具體化，顯示具體化的原型和定意思以template<>開頭，並通過名稱來指出類型
//具體化優先於常規模板
template<> bool myCompare(Person &p1, Person &p2)
{
	if ( p1.m_Name  == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test01()
{
	int a = 10;
	int b = 20;
	//內置數據類型可以直接使用通用的函數模板
	bool ret = myCompare(a, b);
	if (ret)
	{
		cout << "a == b " << endl;
	}
	else
	{
		cout << "a != b " << endl;
	}
}

void test02()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	//自定義數據類型，不會調用普通的函數模板
	//可以創建具體化的Person數據類型的模板，用於特殊處理這個類型
	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2 " << endl;
	}
	else
	{
		cout << "p1 != p2 " << endl;
	}
}

int main() {

	test01();

	test02();

	system("pause");

	return 0;
}
```

**總結：**

* **利用具體化的模板，可以解決自定義類型的通用化**
* **學習模板並不是爲了寫模板，而是在STL能夠運用系統提供的模板**









### 1.3 類模板

#### 1.3.1 類模板語法

類模板作用：

* 建立一個通用類，類中的成員 數據類型可以不具體制定，用一個**虛擬的類型**來代表。



**語法：** 

```c++
template<typename T>
類
```

**解釋：**

template  ---  聲明創建模板

typename  --- 表面其後面的符號是一種數據類型，可以用class代替

T    ---   通用的數據類型，名稱可以替換，通常爲大寫字母



**示例：**

```C++
# include <iostream>
using namespace std;

//類模板
template <typename Nametype, typename AgeType>
class Person
{
public:
    Person(Nametype name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    void ShowPerson()
    {
        cout<<"name = "<<this->m_Name<<"\t"<<"age = "<<this->m_Age<<endl;
    }

    string m_Name;
    int m_Age;
};

void test01()
{
    // 指定NameType 爲string類型，AgeType 爲 int類型
    Person<string, int> p1("孫悟空", 999);
    p1.ShowPerson();
}

int main()
{
    test01();
}
```

總結：類模板和函數模板語法相似，在聲明模板template後面加類，此類稱爲類模板











#### 1.3.2 類模板與函數模板區別



類模板與函數模板區別主要有兩點：

1. 類模板沒有自動類型推導的使用方式
2. 類模板在模板參數列表中可以有默認參數




**示例：**

```C++
# include <iostream>
using namespace std;

//類模板與函數模板區別主要有兩點
//1. 類模板沒有自動類型推導的使用方式
//2. 類模板在模板參數列表中可以有默認參數

//類模板與函數模板的區別
template <typename NameType, typename AgeType = int>
class Person
{
public:
    Person (NameType name, AgeType age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    void ShowPerson()
    {
        cout<<"name = "<<this->m_name<<"\t"<<"age = "<<this->m_age<<endl;
    }

    string m_name;
    int m_age;
};


//1. 類模板沒有自動類型推導的使用方式
void test01()
{
    //Person p("孫悟空", 1000); // 錯誤，無法自動推導數據類型
    Person<string, int> p("孫悟空", 1000);  // 正確，只能用顯示指定類型
    p.ShowPerson();
}

//2. 類模板在模板參數列表中可以有默認參數
void test02()
{
    //只需指定 string 類型，因為 int 已經在 Person 類裡面是默認類型了
    Person<string> p("孫悟空", 1000);  // 正確
    p.ShowPerson();
}

int main()
{
    test01();
    test02();
}
```

總結：

* 類模板使用只能用顯示指定類型方式
* 類模板中的模板參數列表可以有默認參數











#### 1.3.3 類模板中成員函數創建時機



類模板中成員函數和普通類中成員函數創建時機是有區別的：

* 普通類中的成員函數一開始就可以創建
* 類模板中的成員函數在調用時才創建





**示例：**

```C++
# include <iostream>
using namespace std;

//類模板中成員函數創建時機


class Person01
{
public:
    void ShowPerson01()
    {
        cout<<"Person01 show"<<endl;
    }

};

class Person02
{
public:
    void ShowPerson02()
    {
        cout<<"Person02 show"<<endl;
    }
};

template<class T>
class MyClass
{
public:
    T obj; 


	//類模板中的成員函數，並不是一開始就創建的，而是在模板調用時再生成

    //類模板中的成員函數
    void function01()
    {
        obj.ShowPerson01();
    }   
    void function02()
    {
        obj.ShowPerson02();
    }
};

void test01()
{
    MyClass<Person01>m;
    m.function01(); 
    //m.function02();   // Person01 不可以調 function02
}

void test02()
{
    MyClass<Person02>m;
    //m.function01();   // Person02 不可以調 function01
    m.function02();
}

int main()
{
    test01();
    test02();
    
    system("pause");

	return 0;
}
```

總結：類模板中的成員函數並不是一開始就創建的，在調用時纔去創建









#### 1.3.4 類模板對象做函數參數

學習目標：

* 類模板實例化出的對象，向函數傳參的方式



一共有三種傳入方式：

1. 指定傳入的類型   --- 直接顯示對象的數據類型
2. 參數模板化           --- 將對象中的參數變爲模板進行傳遞
3. 整個類模板化       --- 將這個對象類型 模板化進行傳遞


**示例：**

```C++
# include <iostream>
using namespace std;
#include <typeinfo> 


//類模板對象做函數參數
template<class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson()
    {
        cout<<"姓名:"<<this->m_Name<<"年齡:"<<this->m_Age<<endl;
    }

    T1 m_Name;
    T2 m_Age;

};



//===============1. 指定傳入類型===============
//這是最常用的方式，建議都用這種用法
void PrintPerson01(Person<string, int> & p)
{
    p.showPerson();
}
void test01()
{
    Person<string, int> p("孫悟空", 100);
    PrintPerson01(p);
}

//===============2. 參數模板化===============
template<class T1, class T2>
void PrintPerson02(Person<T1, T2> & p)
{
    p.showPerson();
    cout<<"T1 的類型為:"<< typeid(T1).name()<<endl;
    cout<<"T2 的類型為:"<< typeid(T2).name()<<endl;
}
void test02()
{
    Person<string, int> p("豬八戒", 90);
    PrintPerson02(p);
}

//===============3. 整個類模板化===============
template<class T>
void PrintPerson03(T & p)
{
    p.showPerson();
    cout<<"T的數據類型為:"<<typeid(T).name()<<endl;
}
void test03()
{
    Person<string, int> p("唐僧", 30);
    PrintPerson03(p);
}


int main()
{
    test01();
    test02();
    test03();

	return 0;
}
```

**總結：**

* 通過類模板創建的對象，可以有三種方式向函數中進行傳參
* **使用比較廣泛是第一種：指定傳入的類型**



#### 1.3.5 類模板與繼承



當類模板碰到繼承時，需要注意一下幾點：

* 當子類繼承的父類是一個類模板時，子類在聲明的時候，要指定出父類中T的類型
* 如果不指定，編譯器無法給子類分配內存
* 如果想靈活指定出父類中T的類型，子類也需變爲類模板




**示例：**

```C++
# include <iostream>
using namespace std;
#include <typeinfo> 

//類模板與繼承

template<typename T>
class Base
{

    //成員
    T m;
};

//class Son: public Base  // 錯誤，必須要知道父類中T的類型，才能繼承給子類，因為子類要知道父類的記憶體大小
class Son01: public Base<int>
{

};

void test01()
{
    Son01 s1;
};

//如果想靈活指定父類中T類型，子類也需要變類模板
template <class T1, class T2>
class Son02: public Base<T2>
{
public:
    Son02()
    {
        cout <<"T1的類型為"<< typeid(T1).name() << endl;
		cout <<"T2的類型為"<< typeid(T2).name() << endl;
    }
    T1 obj;
};

void test02()
{
    Son02<int, char> S2;
};


int main()
{
    test02();

	return 0;
}
```

**總結：**
* 如果父類是類模板，子類需要指定出父類中T的數據類型
* 如果要靈活構建的話，那子類也要是類模板









#### 1.3.6 類模板成員函數類外實現



學習目標：能夠掌握類模板中的成員函數類外實現



**示例：**

```C++
# include <iostream>
using namespace std;
#include <typeinfo> 

//類模板與繼承

// ============類模板============
template<typename T1, typename T2>
class Person
{
public:
    Person(T1 name, T2 age);
    void showPerson();

    T1 m_name;
    T2 m_age;
};

// ============構造函數的類外實現============
template<typename T1, typename T2>
//Person::Person(T1 name, T2 age)   // 這是普通構造函數的類外實現，我們要類模板的普通構造函數類外實現
Person<T1,T2>::Person(T1 name, T2 age)
{
    this->m_name = name;
    this->m_age = age;
};

// ============成員函數的類外實現============
template<typename T1, typename T2>
void Person<T1, T2>::showPerson()
{
    cout<<"姓名:"<<this->m_name<<"\t"<<"年齡"<<this->m_age<<endl;
};

// ============類模板調用============
void test01()
{
    Person<string, int> p("孫悟空", 100);
    p.showPerson();
}

// ============main函數============
int main()
{
    test01();
	return 0;
}
```

總結：類模板中成員函數類外實現時，需要加上模板參數列表









#### 1.3.7 類模板分文件編寫

學習目標：

* 掌握類模板成員函數分文件編寫產生的問題以及解決方式



問題：

* 類模板中成員函數創建時機是在調用階段，導致分文件編寫時鏈接不到


解決：

* 解決方式1：直接包含.cpp源文件
* 解決方式2：將聲明和實現寫到同一個文件中，並更改後綴名爲.hpp，hpp是約定的名稱，並不是強制




**示例：**

person.hpp中代碼：

```C++
#pragma once
#include <iostream>
using namespace std;

// ============類模板============
template<typename T1, typename T2>
class Person
{
private:

public:
    Person(T1 name, T2 age);
    void showPerson();

    T1 m_name;
    T2 m_age;
};

// ============實現函數============
//構造函數 類外實現
template<typename T1, typename T2>
Person<T1,T2>::Person(T1 name, T2 age)
{
    this->m_name = name;
    this->m_age = age;
};

// ============實現函數============
//成員函數 類外實現
template<typename T1, typename T2>
void Person<T1, T2>::showPerson()
{
    cout<<"姓名:"<<m_name<<"\t"<<"年齡:"<<m_age<<endl;
};
```



類模板分文件編寫.cpp中代碼

```C++
// 類模板分文件編寫

# include <iostream>
#include <typeinfo> 
using namespace std;

// ============第一種解決方式============
// 解決方式:直接包含原文件
// 編譯方式: g++ -o main 1.3.7_類模板分文件編寫.cpp person.cpp
#include "person.cpp"


// ============第二種解決方式============
// 解決方式:將 .h 和 .cpp中的內容寫到一起，將後綴名改為 .hpp文件
// 編譯方式: g++ -o main 1.3.7_類模板分文件編寫.cpp
#include "person.hpp"


void test01()
{
    Person<string, int> p("李多惠", 24);
    p.showPerson();
}


// ============main函數============
int main()
{
    test01();
	return 0;
}
```

**總結：主流的解決方式是第二種，將類模板成員函數寫到一起，並將後綴名改爲.hpp**









#### 1.3.8 類模板與友元



學習目標：

* 掌握類模板配合友元函數的類內和類外實現



全局函數類內實現 - 直接在類內聲明友元即可

全局函數類外實現 - 需要提前讓編譯器知道全局函數的存在



**示例：**

```C++
# include <iostream>
using namespace std;
#include <typeinfo> 

//通過全局函數打印Person的信息

// 7. 提前讓編譯器知道Person的存在，因為在 步驟<6> 使用到了Person
// 全局函數配合友元  類外實現 - 先做函數模板聲明，下方在做函數模板定義，在做友元
template<class T1, class T2> 
class Person;

// 6. 全局函數 類外實現
// 如果聲明瞭函數模板，可以將實現寫到後面，否則需要將實現體寫到類的前面讓編譯器提前看到
template<typename T1, typename T2>
void PrintPerson02(Person<T1, T2> p)
{
    cout<<"類外實現------"<<"姓名:"<<p.m_name<<"\t"<<"年齡"<<p.m_age<<endl;
}

// 1. 定義類模板
template<typename T1, typename T2>
class Person
{
    // 2. 全局函數 類內實現
    friend void PrintPerson01(Person<T1, T2> p)
    {
        cout<<"姓名:"<<p.m_name<<"\t"<<"年齡"<<p.m_age<<endl;
    }

    // 3. 全局函數 類外實現 定義
    // friend void PrintPerson02(Person<T1, T2> p);  //這是普通函數的聲明
    // 加
    // 如果全局函數 是類外實現，需要讓編譯器提前知道這個函數的存在
    friend void PrintPerson02<>(Person<T1, T2> p);  //這是函數模板的聲明

public:
    // 4. 定義構造函數
    Person(T1 name, T2 age);

private:
    T1 m_name;
    T2 m_age;
};

// 5. 構造函數的類外實現
template<typename T1, typename T2>
//Person::Person(T1 name, T2 age)   // 這是普通構造函數的類外實現，我們要類模板的普通構造函數類外實現
Person<T1,T2>::Person(T1 name, T2 age)
{
    this->m_name = name;
    this->m_age = age;
};


// 8. 全局函數在類內實現
void test01()
{
    Person<string, int> p("孫悟空", 100);
    PrintPerson01(p);
}

// 9. 全局函數在類外實現
void test02()
{
    Person<string, int> p("孫悟空", 100);
    PrintPerson02(p);
}



// ============main函數============
int main()
{
    test01();
    test02();
	return 0;
}
```

**總結：建議全局函數做類內實現，用法簡單，而且編譯器可以直接識別**








#### 1.3.9 類模板案例

案例描述:  實現一個通用的數組類，要求如下：



* 可以對內置數據類型以及自定義數據類型的數據進行存儲
* 將數組中的數據存儲到堆區
* 構造函數中可以傳入數組的容量
* 提供對應的拷貝構造函數以及operator=防止淺拷貝問題
* 提供尾插法和尾刪法對數組中的數據進行增加和刪除
* 可以通過下標的方式訪問數組中的元素
* 可以獲取數組中當前元素個數和數組的容量





**示例：**

myArray.hpp中代碼
```C++
#pragma once
# include <iostream>
using namespace std;
#include <typeinfo> 

template<typename T>
class MyArray
{
public:
    // 有參構造函數 
    MyArray(int capacity) // 參數 容量
    {
        cout<<"MyArray的有參構造函數調用"<<endl;
        this->m_capacity = capacity;
        this->m_size = 0;
        this->p_address = new T[this->m_capacity];  // 開闢新的堆區
    };

    // 拷貝構造函數
    MyArray(const MyArray & arr)
    {
        cout<<"MyArray的拷貝構造函數調用"<<endl;
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;

        // 普通類型可以直接 = 但是指針類型需要深拷貝
        //this->p_address = arr.p_address; // 指針不能附值給指針

        // 深拷貝
        this->p_address = new T[arr.m_capacity];

        // 將arr中的數據都拷貝過來
        for (int i = 0 ; i < this->m_size ; i++)
        {
            //如果T爲對象，而且還包含指針，必須需要重載 = 操作符，因爲這個等號不是 構造 而是賦值
            this->p_address[i] = arr.p_address[i];
        }
    }

    // operator= 操作符 防止淺拷貝問題 
    MyArray & operator=(const MyArray & arr)
    {
        cout<<"MyArray的 operator= 調用"<<endl;
        // 先判斷原來堆區是否有數據，如果有，先釋放
        if(this->p_address != NULL)
        {
            delete[] this->p_address;
            this->p_address = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
        }

        // 深拷貝
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->p_address = new T[arr.m_capacity];
        for (int i = 0; i < this->m_size ; i++)
        {
            this->p_address[i] = arr.p_address[i];
        }
        return *this; // 因為這個函數是 MyArray 開頭，所以要返回自己
    }

    // 析構函數
    ~MyArray()
    {
        cout<<"MyArray的析構函數調用"<<endl;
        if (this->p_address != NULL)
        {
            delete[] this->p_address;
            this->p_address = NULL;
        }
    }

private:
    T * p_address;  // 指針指向堆區開闢的真實數組
    int m_capacity; // 數組容量
    int m_size; // 數組大小
};
```
main.cpp
```C++
# include <iostream>
using namespace std;
#include <typeinfo> 

#include "myarray.hpp"

void test01()
{
    MyArray<int>arr01(5);
    MyArray<int>arr02(arr01);

    MyArray<int>arr03(100);
    arr03 = arr01;
};


int main()
{
    test01();
}
```

輸出結果是：
```
MyArray的有參構造函數調用
MyArray的拷貝構造函數調用
MyArray的有參構造函數調用
MyArray的 operator= 調用
MyArray的析構函數調用
MyArray的析構函數調用
MyArray的析構函數調用
```


接著我們繼續修改裡面的代碼

myArray.hpp中代碼

```C++
#pragma once
# include <iostream>
using namespace std;
#include <typeinfo> 

// 1. 創建類模板
template<typename T>
class MyArray
{
private:
    T * p_address;  // 指針指向堆區開闢的真實數組
    int m_capacity; // 數組容量
    int m_size; // 數組大小
    
public:
    // 2. 有參構造函數 
    MyArray(int capacity) // 參數 容量
    {
        cout<<"MyArray的有參構造函數調用"<<endl;
        this->m_capacity = capacity;  // 總共的Array容量
        this->m_size = 0;  // Array 裡面現在佔滿幾個空間
        this->p_address = new T[this->m_capacity];  // 開闢新的堆區
    };

    // 3. 拷貝構造函數
    MyArray(const MyArray & arr)
    {
        cout<<"MyArray的拷貝構造函數調用"<<endl;
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;

        // 普通類型可以直接 = 但是指針類型需要深拷貝
        //this->p_address = arr.p_address; // 指針不能附值給指針

        // 深拷貝
        this->p_address = new T[arr.m_capacity];

        // 將arr中的數據都拷貝過來
        for (int i = 0 ; i < this->m_size ; i++)
        {
            //如果T爲對象，而且還包含指針，必須需要重載 = 操作符，因爲這個等號不是 構造 而是賦值
            this->p_address[i] = arr.p_address[i];
        }
    }

    // 4. operator= 操作符 防止淺拷貝問題 
    MyArray & operator=(const MyArray & arr)
    {
        cout<<"MyArray的 operator= 調用"<<endl;
        // 先判斷原來堆區是否有數據，如果有，先釋放
        if(this->p_address != NULL)
        {
            delete[] this->p_address;
            this->p_address = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
        }

        // 深拷貝
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->p_address = new T[arr.m_capacity];
        for (int i = 0; i < this->m_size ; i++)
        {
            this->p_address[i] = arr.p_address[i];
        }
        return *this; // 因為這個函數是 MyArray 開頭，所以要返回自己
    }

    // 5. 尾插法
    void PuahBack(const T & val) // 使用 const 是因為防止修改val
    {
        // 判斷容量是否等於大小
        if(this->m_capacity == this->m_size)
        {
            return;
        }
        this->p_address[this->m_size] = val; // 在數組的末尾插入數據
        this->m_size++; // 更新數組大小
    }

    // 6. 尾刪法
    void PopBack()
    {
        //讓用戶訪問不到最後一個元素，即為尾刪，邏輯刪除
        if (this->m_size == 0)
        {
            return;
        }
        this->m_size--;
    }

    // 7. 讓用戶通過下標的方式訪問數組中的元素 arr[0] = 100
    T & operator[] (int index)
    {
        return this->p_address[index];
    }

    // 8. 返回數組容量
    int GetCapacity()
    {
        return this->m_capacity;
    }

    // 9. 返回數組大小
    int GetSize()
    {
        return this->m_size;
    }

    // 10. 設計PrintArray函數
    void PrintArray()
    {
        for (int i = 0 ; i < this->m_size ; i++ )
        {
            cout<<this->p_address[i]<<endl;
        }
    }

    // 11. 析構函數
    ~MyArray()
    {
        cout<<"MyArray的析構函數調用"<<endl;
        if (this->p_address != NULL)
        {
            delete[] this->p_address;
            this->p_address = NULL;
        }
    }
};
```



類模板案例—數組類封裝.cpp中

```C++
# include <iostream>
using namespace std;
#include <typeinfo> 

#include "myarray.hpp"

void test01()
{
    int capacity = 5;

    // 1. 查看構造函數是否啟用
    MyArray<int>arr01(capacity);
    // 2. 查看拷貝構造函數是否啟用
    MyArray<int>arr02(arr01);
    // 3. 查看 operator= 是否啟用
    MyArray<int>arr03(100);
    arr03 = arr01;

    // 4. 利用尾插法向數組中插入數據
    for (int i = 0; i < capacity ; i++)
    {
        arr01.PuahBack(i);
    }
    
    arr01.PrintArray();
    cout<<"GetCapacity = "<<arr01.GetCapacity()<<endl;  
    cout<<"GetSize = "<<arr01.GetSize()<<endl;


    // 5. 利用尾刪法向數組中刪除數據
    arr01.PopBack();
    cout<<"尾刪後"<<endl; 
    cout<<"GetCapacity = "<<arr01.GetCapacity()<<endl;  
    cout<<"GetSize = "<<arr01.GetSize()<<endl;
};

// 6. 測試自訂數據類型
class Person
{
public:
    Person(){} // 默認構造
    Person(string name, int age) // 有參構造函數
    {
        this->m_age = age;
        this->m_name = name;
    }
    string m_name;
    int m_age;
};

// 7. 設計一個打印 Person 數據類型的函數
void PrintPersonArray(MyArray<Person> & person_array)
{
    for (int i = 0 ; i < person_array.GetSize() ; i++ )
    {
        cout << "姓名：" << person_array[i].m_name << " 年齡： " << person_array[i].m_age << endl;
    }
}

void test02()
{
    // 8. 創建一個 person 的 array
    MyArray<Person> person_arr(10);
    Person p1("孫悟空", 999);
    Person p2("韓信", 20);
    Person p3("流川風", 16);
    Person p4("李佳惠", 24);
    Person p5("趙雲", 30);

    // 9. 將數據插入到數組中
    person_arr.PuahBack(p1);
    person_arr.PuahBack(p2);
    person_arr.PuahBack(p3);
    person_arr.PuahBack(p4);
    person_arr.PuahBack(p5);

    // 10. 打印 Person 數據類型
    PrintPersonArray(person_arr);

	cout << "pArray的大小：" << person_arr.GetSize() << endl;
	cout << "pArray的容量：" << person_arr.GetCapacity() << endl;
}

int main()
{
    test01();
}
```
輸出為：
```
MyArray的拷貝構造函數調用
MyArray的有參構造函數調用
MyArray的 operator= 調用
0
1
GetCapacity = 5
GetSize = 5
尾刪後
GetCapacity = 5
GetSize = 4
MyArray的析構函數調用
MyArray的析構函數調用
MyArray的析構函數調用
```

**總結：**

能夠利用所學知識點實現通用的數組





## 2 STL初識

### 2.1 STL的誕生



* 長久以來，軟件界一直希望建立一種可重複利用的東西

* C++的**面向對象**和**泛型編程**思想，目的就是**複用性的提升**

* 大多情況下，數據結構和算法都未能有一套標準,導致被迫從事大量重複工作

* 爲了建立數據結構和算法的一套標準,誕生了**STL**

  ​


### 2.2 STL基本概念



* STL(Standard Template Library,**標準模板庫**)
* STL 從廣義上分爲: **容器(container) 算法(algorithm) 迭代器(iterator)**
* **容器**和**算法**之間通過**迭代器**進行無縫連接。
* STL 幾乎所有的代碼都採用了模板類或者模板函數





### 2.3 STL六大組件

STL大體分爲六大組件，分別是:**容器、算法、迭代器、仿函數、適配器（配接器）、空間配置器**



1. 容器：各種數據結構，如vector、list、deque、set、map等,用來存放數據。
2. 算法：各種常用的算法，如sort、find、copy、for_each等
3. 迭代器：扮演了容器與算法之間的膠合劑。
4. 仿函數：行爲類似函數，可作爲算法的某種策略。
5. 適配器：一種用來修飾容器或者仿函數或迭代器接口的東西。
6. 空間配置器：負責空間的配置與管理。





### 2.4  STL中容器、算法、迭代器



**容器：**置物之所也

STL**容器**就是將運用**最廣泛的一些數據結構**實現出來

常用的數據結構：數組, 鏈表,樹, 棧, 隊列, 集合, 映射表 等

這些容器分爲**序列式容器**和**關聯式容器**兩種:

​	**序列式容器**:強調值的排序，序列式容器中的每個元素均有固定的位置。
	**關聯式容器**:二叉樹結構，各元素之間沒有嚴格的物理上的順序關係



**算法：**問題之解法也

有限的步驟，解決邏輯或數學上的問題，這一門學科我們叫做算法(Algorithms)

算法分爲:**質變算法**和**非質變算法**。

質變算法：是指運算過程中會更改區間內的元素的內容。例如拷貝，替換，刪除等等

非質變算法：是指運算過程中不會更改區間內的元素內容，例如查找、計數、遍歷、尋找極值等等



**迭代器：**容器和算法之間粘合劑

提供一種方法，使之能夠依序尋訪某個容器所含的各個元素，而又無需暴露該容器的內部表示方式。

每個容器都有自己專屬的迭代器

迭代器使用非常類似於指針，初學階段我們可以先理解迭代器爲指針



迭代器種類：

| 種類           | 功能                                                     | 支持運算                                |
| -------------- | -------------------------------------------------------- | --------------------------------------- |
| 輸入迭代器     | 對數據的只讀訪問                                         | 只讀，支持++、==、！=                   |
| 輸出迭代器     | 對數據的只寫訪問                                         | 只寫，支持++                            |
| 前向迭代器     | 讀寫操作，並能向前推進迭代器                             | 讀寫，支持++、==、！=                   |
| 雙向迭代器     | 讀寫操作，並能向前和向後操作                             | 讀寫，支持++、--，                      |
| 隨機訪問迭代器 | 讀寫操作，可以以跳躍的方式訪問任意數據，功能最強的迭代器 | 讀寫，支持++、--、[n]、-n、<、<=、>、>= |

常用的容器中迭代器種類爲雙向迭代器，和隨機訪問迭代器







### 2.5 容器算法迭代器初識



瞭解STL中容器、算法、迭代器概念之後，我們利用代碼感受STL的魅力

STL中最常用的容器爲Vector，可以理解爲數組，下面我們將學習如何向這個容器中插入數據、並遍歷這個容器



#### 2.5.1 vector存放內置數據類型



容器：     `vector`

算法：     `for_each`

迭代器： `vector<int>::iterator`



**示例：**

```C++
#include <vector>
#include <algorithm>

void MyPrint(int val)
{
	cout << val << endl;
}

void test01() {

	//創建vector容器對象，並且通過模板參數指定容器中存放的數據的類型
	vector<int> v;
	//向容器中放數據
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//每一個容器都有自己的迭代器，迭代器是用來遍歷容器中的元素
	//v.begin()返回迭代器，這個迭代器指向容器中第一個數據
	//v.end()返回迭代器，這個迭代器指向容器元素的最後一個元素的下一個位置
	//vector<int>::iterator 拿到vector<int>這種容器的迭代器類型

	vector<int>::iterator pBegin = v.begin();
	vector<int>::iterator pEnd = v.end();

	//第一種遍歷方式：
	while (pBegin != pEnd) {
		cout << *pBegin << endl;
		pBegin++;
	}

	
	//第二種遍歷方式：
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
	cout << endl;

	//第三種遍歷方式：
	//使用STL提供標準遍歷算法  頭文件 algorithm
	for_each(v.begin(), v.end(), MyPrint);
}

int main() {

	test01();

	system("pause");

	return 0;
}
```



#### 2.5.2 Vector存放自定義數據類型



學習目標：vector中存放自定義數據類型，並打印輸出



**示例：**

```c++
#include <vector>
#include <string>

//自定義數據類型
class Person {
public:
	Person(string name, int age) {
		mName = name;
		mAge = age;
	}
public:
	string mName;
	int mAge;
};
//存放對象
void test01() {

	vector<Person> v;

	//創建數據
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "Name:" << (*it).mName << " Age:" << (*it).mAge << endl;

	}
}


//放對象指針
void test02() {

	vector<Person*> v;

	//創建數據
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++) {
		Person * p = (*it);
		cout << "Name:" << p->mName << " Age:" << (*it)->mAge << endl;
	}
}


int main() {

	test01();
    
	test02();

	system("pause");

	return 0;
}
```



#### 2.5.3 Vector容器嵌套容器



學習目標：容器中嵌套容器，我們將所有數據進行遍歷輸出



**示例：**

```C++
#include <vector>

//容器嵌套容器
void test01() {

	vector< vector<int> >  v;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	for (int i = 0; i < 4; i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}

	//將容器元素插入到vector v中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);


	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {

		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
			cout << *vit << " ";
		}
		cout << endl;
	}

}

int main() {

	test01();

	system("pause");

	return 0;
}
```





## 3 STL- 常用容器

### 3.1 string容器



#### 3.1.1 string基本概念

**本質：**

* string是C++風格的字符串，而string本質上是一個類



**string和char * 區別：**

* char * 是一個指針
* string是一個類，類內部封裝了char\*，管理這個字符串，是一個char*型的容器。



**特點：**

string 類內部封裝了很多成員方法

例如：查找find，拷貝copy，刪除delete 替換replace，插入insert

string管理char*所分配的內存，不用擔心複製越界和取值越界等，由類內部進行負責



#### 3.1.2 string構造函數

構造函數原型：

* `string();`          				//創建一個空的字符串 例如: string str;
	 `string(const char* s);`	        //使用字符串s初始化
* `string(const string& str);`    //使用一個string對象初始化另一個string對象
* `string(int n, char c);`           //使用n個字符c初始化 



**示例：**

```C++
#include <string>
//string構造
void test01()
{
	string s1; //創建空字符串，調用無參構造函數
	cout << "str1 = " << s1 << endl;

	const char* str = "hello world";
	string s2(str); //把c_string轉換成了string

	cout << "str2 = " << s2 << endl;

	string s3(s2); //調用拷貝構造函數
	cout << "str3 = " << s3 << endl;

	string s4(10, 'a');
	cout << "str3 = " << s3 << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：string的多種構造方式沒有可比性，靈活使用即可









#### 3.1.3 string賦值操作

功能描述：

* 給string字符串進行賦值



賦值的函數原型：

* `string& operator=(const char* s);`             //char*類型字符串 賦值給當前的字符串
* `string& operator=(const string &s);`         //把字符串s賦給當前的字符串
* `string& operator=(char c);`                          //字符賦值給當前的字符串
* `string& assign(const char *s);`                  //把字符串s賦給當前的字符串
* `string& assign(const char *s, int n);`     //把字符串s的前n個字符賦給當前的字符串
* `string& assign(const string &s);`              //把字符串s賦給當前字符串
* `string& assign(int n, char c);`                  //用n個字符c賦給當前字符串




**示例：**

```C++
//賦值
void test01()
{
	string str1;
	str1 = "hello world";
	cout << "str1 = " << str1 << endl;

	string str2;
	str2 = str1;
	cout << "str2 = " << str2 << endl;

	string str3;
	str3 = 'a';
	cout << "str3 = " << str3 << endl;

	string str4;
	str4.assign("hello c++");
	cout << "str4 = " << str4 << endl;

	string str5;
	str5.assign("hello c++",5);
	cout << "str5 = " << str5 << endl;


	string str6;
	str6.assign(str5);
	cout << "str6 = " << str6 << endl;

	string str7;
	str7.assign(5, 'x');
	cout << "str7 = " << str7 << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：

​	string的賦值方式很多，`operator=`  這種方式是比較實用的









#### 3.1.4 string字符串拼接

**功能描述：**

* 實現在字符串末尾拼接字符串



**函數原型：**

* `string& operator+=(const char* str);`                   //重載+=操作符
* `string& operator+=(const char c);`                         //重載+=操作符
* `string& operator+=(const string& str);`                //重載+=操作符
* `string& append(const char *s); `                               //把字符串s連接到當前字符串結尾
* `string& append(const char *s, int n);`                 //把字符串s的前n個字符連接到當前字符串結尾
* `string& append(const string &s);`                           //同operator+=(const string& str)
* `string& append(const string &s, int pos, int n);`//字符串s中從pos開始的n個字符連接到字符串結尾




**示例：**


```C++
//字符串拼接
void test01()
{
	string str1 = "我";

	str1 += "愛玩遊戲";

	cout << "str1 = " << str1 << endl;
	
	str1 += ':';

	cout << "str1 = " << str1 << endl;

	string str2 = "LOL DNF";

	str1 += str2;

	cout << "str1 = " << str1 << endl;

	string str3 = "I";
	str3.append(" love ");
	str3.append("game abcde", 4);
	//str3.append(str2);
	str3.append(str2, 4, 3); // 從下標4位置開始 ，截取3個字符，拼接到字符串末尾
	cout << "str3 = " << str3 << endl;
}
int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：字符串拼接的重載版本很多，初學階段記住幾種即可







#### 3.1.5 string查找和替換

**功能描述：**

* 查找：查找指定字符串是否存在
* 替換：在指定的位置替換字符串



**函數原型：**

* `int find(const string& str, int pos = 0) const;`              //查找str第一次出現位置,從pos開始查找
* `int find(const char* s, int pos = 0) const; `                     //查找s第一次出現位置,從pos開始查找
* `int find(const char* s, int pos, int n) const; `               //從pos位置查找s的前n個字符第一次位置
* `int find(const char c, int pos = 0) const; `                       //查找字符c第一次出現位置
* `int rfind(const string& str, int pos = npos) const;`      //查找str最後一次位置,從pos開始查找
* `int rfind(const char* s, int pos = npos) const;`              //查找s最後一次出現位置,從pos開始查找
* `int rfind(const char* s, int pos, int n) const;`              //從pos查找s的前n個字符最後一次位置
* `int rfind(const char c, int pos = 0) const;  `                      //查找字符c最後一次出現位置
* `string& replace(int pos, int n, const string& str); `       //替換從pos開始n個字符爲字符串str
* `string& replace(int pos, int n,const char* s); `                 //替換從pos開始的n個字符爲字符串s




**示例：**

```C++
//查找和替換
void test01()
{
	//查找
	string str1 = "abcdefgde";

	int pos = str1.find("de");

	if (pos == -1)
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "pos = " << pos << endl;
	}
	

	pos = str1.rfind("de");

	cout << "pos = " << pos << endl;

}

void test02()
{
	//替換
	string str1 = "abcdefgde";
	str1.replace(1, 3, "1111");

	cout << "str1 = " << str1 << endl;
}

int main() {

	//test01();
	//test02();

	system("pause");

	return 0;
}
```

總結：

* find查找是從左往後，rfind從右往左
* find找到字符串後返回查找的第一個字符位置，找不到返回-1
* replace在替換時，要指定從哪個位置起，多少個字符，替換成什麼樣的字符串
















####    3.1.6 string字符串比較

**功能描述：**

* 字符串之間的比較

**比較方式：**

* 字符串比較是按字符的ASCII碼進行對比

= 返回   0

\> 返回   1 

< 返回  -1



**函數原型：**

* `int compare(const string &s) const; `  //與字符串s比較
* `int compare(const char *s) const;`      //與字符串s比較





**示例：**

```C++
//字符串比較
void test01()
{

	string s1 = "hello";
	string s2 = "aello";

	int ret = s1.compare(s2);

	if (ret == 0) {
		cout << "s1 等於 s2" << endl;
	}
	else if (ret > 0)
	{
		cout << "s1 大於 s2" << endl;
	}
	else
	{
		cout << "s1 小於 s2" << endl;
	}

}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：字符串對比主要是用於比較兩個字符串是否相等，判斷誰大誰小的意義並不是很大





#### 3.1.7 string字符存取



string中單個字符存取方式有兩種



* `char& operator[](int n); `     //通過[]方式取字符
* `char& at(int n);   `                    //通過at方法獲取字符





**示例：**

```C++
void test01()
{
	string str = "hello world";

	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;


	//字符修改
	str[0] = 'x';
	str.at(1) = 'x';
	cout << str << endl;
	
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：string字符串中單個字符存取有兩種方式，利用 [ ] 或 at









#### 3.1.8 string插入和刪除

**功能描述：**

* 對string字符串進行插入和刪除字符操作

**函數原型：**

* `string& insert(int pos, const char* s);  `                //插入字符串
* `string& insert(int pos, const string& str); `        //插入字符串
* `string& insert(int pos, int n, char c);`                //在指定位置插入n個字符c
* `string& erase(int pos, int n = npos);`                    //刪除從Pos開始的n個字符 





**示例：**

```C++
//字符串插入和刪除
void test01()
{
	string str = "hello";
	str.insert(1, "111");
	cout << str << endl;

	str.erase(1, 3);  //從1號位置開始3個字符
	cout << str << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**總結：**插入和刪除的起始下標都是從0開始











#### 3.1.9 string子串

**功能描述：**

* 從字符串中獲取想要的子串



**函數原型：**

* `string substr(int pos = 0, int n = npos) const;`   //返回由pos開始的n個字符組成的字符串




**示例：**

```C++
//子串
void test01()
{

	string str = "abcdefg";
	string subStr = str.substr(1, 3);
	cout << "subStr = " << subStr << endl;

	string email = "hello@sina.com";
	int pos = email.find("@");
	string username = email.substr(0, pos);
	cout << "username: " << username << endl;

}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**總結：**靈活的運用求子串功能，可以在實際開發中獲取有效的信息







### 3.2 vector容器



#### 3.2.1 vector基本概念

**功能：**

* vector數據結構和**數組非常相似**，也稱爲**單端數組**



**vector與普通數組區別：**

* 不同之處在於數組是靜態空間，而vector可以**動態擴展**



**動態擴展：**

* 並不是在原空間之後續接新空間，而是找更大的內存空間，然後將原數據拷貝新空間，釋放原空間



![說明: 2015-11-10_151152](assets/clip_image002.jpg)



* vector容器的迭代器是支持隨機訪問的迭代器





#### 3.2.2 vector構造函數



**功能描述：**

* 創建vector容器



**函數原型：**

* `vector<T> v; `               		     //採用模板實現類實現，默認構造函數
* `vector(v.begin(), v.end());   `       //將v[begin(), end())區間中的元素拷貝給本身。
* `vector(n, elem);`                            //構造函數將n個elem拷貝給本身。
* `vector(const vector &vec);`         //拷貝構造函數。




**示例：**


```C++
#include <vector>

void printVector(vector<int>& v) {

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int> v1; //無參構造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int> v2(v1.begin(), v1.end());
	printVector(v2);

	vector<int> v3(10, 100);
	printVector(v3);
	
	vector<int> v4(v3);
	printVector(v4);
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**總結：**vector的多種構造方式沒有可比性，靈活使用即可









#### 3.2.3 vector賦值操作



**功能描述：**

* 給vector容器進行賦值



**函數原型：**

* `vector& operator=(const vector &vec);`//重載等號操作符


* `assign(beg, end);`       //將[beg, end)區間中的數據拷貝賦值給本身。
* `assign(n, elem);`        //將n個elem拷貝賦值給本身。





**示例：**

```C++
#include <vector>

void printVector(vector<int>& v) {

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//賦值操作
void test01()
{
	vector<int> v1; //無參構造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int>v2;
	v2 = v1;
	printVector(v2);

	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	printVector(v3);

	vector<int>v4;
	v4.assign(10, 100);
	printVector(v4);
}

int main() {

	test01();

	system("pause");

	return 0;
}

```

總結： vector賦值方式比較簡單，使用operator=，或者assign都可以







#### 3.2.4  vector容量和大小

**功能描述：**

* 對vector容器的容量和大小操作



**函數原型：**

* `empty(); `                            //判斷容器是否爲空

* `capacity();`                      //容器的容量

* `size();`                              //返回容器中元素的個數

* `resize(int num);`             //重新指定容器的長度爲num，若容器變長，則以默認值填充新位置。

  ​					      //如果容器變短，則末尾超出容器長度的元素被刪除。

* `resize(int num, elem);`  //重新指定容器的長度爲num，若容器變長，則以elem值填充新位置。

  ​				              //如果容器變短，則末尾超出容器長度的元素被刪除




**示例：**


```C++
#include <vector>

void printVector(vector<int>& v) {

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	if (v1.empty())
	{
		cout << "v1爲空" << endl;
	}
	else
	{
		cout << "v1不爲空" << endl;
		cout << "v1的容量 = " << v1.capacity() << endl;
		cout << "v1的大小 = " << v1.size() << endl;
	}

	//resize 重新指定大小 ，若指定的更大，默認用0填充新位置，可以利用重載版本替換默認填充
	v1.resize(15,10);
	printVector(v1);

	//resize 重新指定大小 ，若指定的更小，超出部分元素被刪除
	v1.resize(5);
	printVector(v1);
}

int main() {

	test01();

	system("pause");

	return 0;
}

```

總結：

* 判斷是否爲空  --- empty
* 返回元素個數  --- size
* 返回容器容量  --- capacity
* 重新指定大小  ---  resize













#### 3.2.5 vector插入和刪除

**功能描述：**

* 對vector容器進行插入、刪除操作



**函數原型：**

* `push_back(ele);`                                         //尾部插入元素ele
* `pop_back();`                                                //刪除最後一個元素
* `insert(const_iterator pos, ele);`        //迭代器指向位置pos插入元素ele
* `insert(const_iterator pos, int count,ele);`//迭代器指向位置pos插入count個元素ele
* `erase(const_iterator pos);`                     //刪除迭代器指向的元素
* `erase(const_iterator start, const_iterator end);`//刪除迭代器從start到end之間的元素
* `clear();`                                                        //刪除容器中所有元素





**示例：**

```C++

#include <vector>

void printVector(vector<int>& v) {

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//插入和刪除
void test01()
{
	vector<int> v1;
	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);
	//尾刪
	v1.pop_back();
	printVector(v1);
	//插入
	v1.insert(v1.begin(), 100);
	printVector(v1);

	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);

	//刪除
	v1.erase(v1.begin());
	printVector(v1);

	//清空
	v1.erase(v1.begin(), v1.end());
	v1.clear();
	printVector(v1);
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：

* 尾插  --- push_back
* 尾刪  --- pop_back
* 插入  --- insert    (位置迭代器)
* 刪除  --- erase  （位置迭代器）
* 清空  ---  clear  













#### 3.2.6 vector數據存取



**功能描述：**

* 對vector中的數據的存取操作



**函數原型：**

* `at(int idx); `     //返回索引idx所指的數據
* `operator[]; `       //返回索引idx所指的數據
* `front(); `            //返回容器中第一個數據元素
* `back();`              //返回容器中最後一個數據元素





**示例：**

```C++
#include <vector>

void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;

	cout << "v1的第一個元素爲： " << v1.front() << endl;
	cout << "v1的最後一個元素爲： " << v1.back() << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：

* 除了用迭代器獲取vector容器中元素，[ ]和at也可以
* front返回容器第一個元素
* back返回容器最後一個元素











#### 3.2.7 vector互換容器

**功能描述：**

* 實現兩個容器內元素進行互換



**函數原型：**

* `swap(vec);`  // 將vec與本身的元素互換





**示例：**

```C++
#include <vector>

void printVector(vector<int>& v) {

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int>v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);

	//互換容器
	cout << "互換後" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}

void test02()
{
	vector<int> v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}

	cout << "v的容量爲：" << v.capacity() << endl;
	cout << "v的大小爲：" << v.size() << endl;

	v.resize(3);

	cout << "v的容量爲：" << v.capacity() << endl;
	cout << "v的大小爲：" << v.size() << endl;

	//收縮內存
	vector<int>(v).swap(v); //匿名對象

	cout << "v的容量爲：" << v.capacity() << endl;
	cout << "v的大小爲：" << v.size() << endl;
}

int main() {

	test01();

	test02();

	system("pause");

	return 0;
}

```

總結：swap可以使兩個容器互換，可以達到實用的收縮內存效果









#### 3.2.8 vector預留空間

**功能描述：**

* 減少vector在動態擴展容量時的擴展次數



**函數原型：**

* `reserve(int len);`//容器預留len個元素長度，預留位置不初始化，元素不可訪問。

  ​

**示例：**

```C++
#include <vector>

void test01()
{
	vector<int> v;

	//預留空間
	v.reserve(100000);

	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}

	cout << "num:" << num << endl;
}

int main() {

	test01();
    
	system("pause");

	return 0;
}
```

總結：如果數據量較大，可以一開始利用reserve預留空間











### 3.3 deque容器

#### 3.3.1 deque容器基本概念



**功能：**

* 雙端數組，可以對頭端進行插入刪除操作



**deque與vector區別：**

* vector對於頭部的插入刪除效率低，數據量越大，效率越低
* deque相對而言，對頭部的插入刪除速度回比vector快
* vector訪問元素時的速度會比deque快,這和兩者內部實現有關

![說明: 2015-11-19_204101](assets/clip_image002-1547547642923.jpg)



deque內部工作原理:

deque內部有個**中控器**，維護每段緩衝區中的內容，緩衝區中存放真實數據

中控器維護的是每個緩衝區的地址，使得使用deque時像一片連續的內存空間

![clip_image002-1547547896341](assets/clip_image002-1547547896341.jpg)

* deque容器的迭代器也是支持隨機訪問的



#### 3.3.2 deque構造函數

**功能描述：**

* deque容器構造



**函數原型：**

* `deque<T>` deqT;                      //默認構造形式
* `deque(beg, end);`                  //構造函數將[beg, end)區間中的元素拷貝給本身。
* `deque(n, elem);`                    //構造函數將n個elem拷貝給本身。
* `deque(const deque &deq);`   //拷貝構造函數





**示例：**

```C++
#include <deque>

void printDeque(const deque<int>& d) 
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";

	}
	cout << endl;
}
//deque構造
void test01() {

	deque<int> d1; //無參構造函數
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	deque<int> d2(d1.begin(),d1.end());
	printDeque(d2);

	deque<int>d3(10,100);
	printDeque(d3);

	deque<int>d4 = d3;
	printDeque(d4);
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**總結：**deque容器和vector容器的構造方式幾乎一致，靈活使用即可









#### 3.3.3 deque賦值操作



**功能描述：**

* 給deque容器進行賦值



**函數原型：**

* `deque& operator=(const deque &deq); `         //重載等號操作符


* `assign(beg, end);`                                           //將[beg, end)區間中的數據拷貝賦值給本身。
* `assign(n, elem);`                                             //將n個elem拷貝賦值給本身。





**示例：**

```C++
#include <deque>

void printDeque(const deque<int>& d) 
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";

	}
	cout << endl;
}
//賦值操作
void test01()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int>d2;
	d2 = d1;
	printDeque(d2);

	deque<int>d3;
	d3.assign(d1.begin(), d1.end());
	printDeque(d3);

	deque<int>d4;
	d4.assign(10, 100);
	printDeque(d4);

}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：deque賦值操作也與vector相同，需熟練掌握







#### 3.3.4 deque大小操作

**功能描述：**

* 對deque容器的大小進行操作



**函數原型：**

* `deque.empty();`                       //判斷容器是否爲空

* `deque.size();`                         //返回容器中元素的個數

* `deque.resize(num);`                //重新指定容器的長度爲num,若容器變長，則以默認值填充新位置。

  ​			                             //如果容器變短，則末尾超出容器長度的元素被刪除。

* `deque.resize(num, elem);`     //重新指定容器的長度爲num,若容器變長，則以elem值填充新位置。

  ​                                                     //如果容器變短，則末尾超出容器長度的元素被刪除。

  ​



**示例：**

```C++
#include <deque>

void printDeque(const deque<int>& d) 
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";

	}
	cout << endl;
}

//大小操作
void test01()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	//判斷容器是否爲空
	if (d1.empty()) {
		cout << "d1爲空!" << endl;
	}
	else {
		cout << "d1不爲空!" << endl;
		//統計大小
		cout << "d1的大小爲：" << d1.size() << endl;
	}

	//重新指定大小
	d1.resize(15, 1);
	printDeque(d1);

	d1.resize(5);
	printDeque(d1);
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：

* deque沒有容量的概念
* 判斷是否爲空   --- empty
* 返回元素個數   --- size
* 重新指定個數   --- resize









#### 3.3.5 deque 插入和刪除

**功能描述：**

* 向deque容器中插入和刪除數據



**函數原型：**

兩端插入操作：

- `push_back(elem);`          //在容器尾部添加一個數據
- `push_front(elem);`        //在容器頭部插入一個數據
- `pop_back();`                   //刪除容器最後一個數據
- `pop_front();`                 //刪除容器第一個數據

指定位置操作：

* `insert(pos,elem);`         //在pos位置插入一個elem元素的拷貝，返回新數據的位置。

* `insert(pos,n,elem);`     //在pos位置插入n個elem數據，無返回值。

* `insert(pos,beg,end);`    //在pos位置插入[beg,end)區間的數據，無返回值。

* `clear();`                           //清空容器的所有數據

* `erase(beg,end);`             //刪除[beg,end)區間的數據，返回下一個數據的位置。

* `erase(pos);`                    //刪除pos位置的數據，返回下一個數據的位置。

  ​

  ​



**示例：**

```C++
#include <deque>

void printDeque(const deque<int>& d) 
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";

	}
	cout << endl;
}
//兩端操作
void test01()
{
	deque<int> d;
	//尾插
	d.push_back(10);
	d.push_back(20);
	//頭插
	d.push_front(100);
	d.push_front(200);

	printDeque(d);

	//尾刪
	d.pop_back();
	//頭刪
	d.pop_front();
	printDeque(d);
}

//插入
void test02()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);

	d.insert(d.begin(), 1000);
	printDeque(d);

	d.insert(d.begin(), 2,10000);
	printDeque(d);

	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d.insert(d.begin(), d2.begin(), d2.end());
	printDeque(d);

}

//刪除
void test03()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);

	d.erase(d.begin());
	printDeque(d);

	d.erase(d.begin(), d.end());
	d.clear();
	printDeque(d);
}

int main() {

	//test01();

	//test02();

    test03();
    
	system("pause");

	return 0;
}

```

總結：

* 插入和刪除提供的位置是迭代器！
* 尾插   ---  push_back
* 尾刪   ---  pop_back
* 頭插   ---  push_front
* 頭刪   ---  pop_front











#### 3.3.6 deque 數據存取



**功能描述：**

* 對deque 中的數據的存取操作



**函數原型：**

- `at(int idx); `     //返回索引idx所指的數據
- `operator[]; `      //返回索引idx所指的數據
- `front(); `            //返回容器中第一個數據元素
- `back();`              //返回容器中最後一個數據元素



**示例：**

```C++
#include <deque>

void printDeque(const deque<int>& d) 
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";

	}
	cout << endl;
}

//數據存取
void test01()
{

	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);

	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << " ";
	}
	cout << endl;


	for (int i = 0; i < d.size(); i++) {
		cout << d.at(i) << " ";
	}
	cout << endl;

	cout << "front:" << d.front() << endl;

	cout << "back:" << d.back() << endl;

}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：

- 除了用迭代器獲取deque容器中元素，[ ]和at也可以
- front返回容器第一個元素
- back返回容器最後一個元素













#### 3.3.7  deque 排序

**功能描述：**

* 利用算法實現對deque容器進行排序



**算法：**

* `sort(iterator beg, iterator end)`  //對beg和end區間內元素進行排序





**示例：**

```C++
#include <deque>
#include <algorithm>

void printDeque(const deque<int>& d) 
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";

	}
	cout << endl;
}

void test01()
{

	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);

	printDeque(d);
	sort(d.begin(), d.end());
	printDeque(d);

}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：sort算法非常實用，使用時包含頭文件 algorithm即可











### 3.4 案例-評委打分



#### 3.4.1 案例描述

有5名選手：選手ABCDE，10個評委分別對每一名選手打分，去除最高分，去除評委中最低分，取平均分。



#### 3.4.2 實現步驟

1. 創建五名選手，放到vector中
2. 遍歷vector容器，取出來每一個選手，執行for循環，可以把10個評分打分存到deque容器中
3. sort算法對deque容器中分數排序，去除最高和最低分
4. deque容器遍歷一遍，累加總分
5. 獲取平均分





**示例代碼：**

```C++
//選手類
class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name; //姓名
	int m_Score;  //平均分
};

void createPerson(vector<Person>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "選手";
		name += nameSeed[i];

		int score = 0;

		Person p(name, score);

		//將創建的person對象 放入到容器中
		v.push_back(p);
	}
}

//打分
void setScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//將評委的分數 放入到deque容器中
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;  // 60 ~ 100
			d.push_back(score);
		}

		//cout << "選手： " << it->m_Name << " 打分： " << endl;
		//for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		//{
		//	cout << *dit << " ";
		//}
		//cout << endl;

		//排序
		sort(d.begin(), d.end());

		//去除最高和最低分
		d.pop_back();
		d.pop_front();

		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit; //累加每個評委的分數
		}

		int avg = sum / d.size();

		//將平均分 賦值給選手身上
		it->m_Score = avg;
	}

}

void showScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名： " << it->m_Name << " 平均分： " << it->m_Score << endl;
	}
}

int main() {

	//隨機數種子
	srand((unsigned int)time(NULL));

	//1、創建5名選手
	vector<Person>v;  //存放選手容器
	createPerson(v);

	//測試
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "姓名： " << (*it).m_Name << " 分數： " << (*it).m_Score << endl;
	//}

	//2、給5名選手打分
	setScore(v);

	//3、顯示最後得分
	showScore(v);

	system("pause");

	return 0;
}
```

**總結：** 選取不同的容器操作數據，可以提升代碼的效率







### 3.5 stack容器

#### 3.5.1 stack 基本概念



**概念：**stack是一種**先進後出**(First In Last Out,FILO)的數據結構，它只有一個出口





![說明: 2015-11-15_195707](assets/clip_image002-1547604555425.jpg)

棧中只有頂端的元素纔可以被外界使用，因此棧不允許有遍歷行爲

棧中進入數據稱爲  --- **入棧**  `push`

棧中彈出數據稱爲  --- **出棧**  `pop`



生活中的棧：

![img](assets/clip_image002.png)





![img](assets/clip_image002-1547605111510.jpg)



#### 3.5.2 stack 常用接口

功能描述：棧容器常用的對外接口



構造函數：

* `stack<T> stk;`                                 //stack採用模板類實現， stack對象的默認構造形式
* `stack(const stack &stk);`            //拷貝構造函數

賦值操作：

* `stack& operator=(const stack &stk);`           //重載等號操作符

數據存取：

* `push(elem);`      //向棧頂添加元素
* `pop();`                //從棧頂移除第一個元素
* `top(); `                //返回棧頂元素

大小操作：

* `empty();`            //判斷堆棧是否爲空
* `size(); `              //返回棧的大小





**示例：**

```C++
#include <stack>

//棧容器常用接口
void test01()
{
	//創建棧容器 棧容器必須符合先進後出
	stack<int> s;

	//向棧中添加元素，叫做 壓棧 入棧
	s.push(10);
	s.push(20);
	s.push(30);

	while (!s.empty()) {
		//輸出棧頂元素
		cout << "棧頂元素爲： " << s.top() << endl;
		//彈出棧頂元素
		s.pop();
	}
	cout << "棧的大小爲：" << s.size() << endl;

}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：

* 入棧   --- push
* 出棧   --- pop
* 返回棧頂   --- top
* 判斷棧是否爲空   --- empty
* 返回棧大小   --- size











### 3.6 queue 容器

#### 3.6.1 queue 基本概念



**概念：**Queue是一種**先進先出**(First In First Out,FIFO)的數據結構，它有兩個出口







![說明: 2015-11-15_214429](assets/clip_image002-1547606475892.jpg)

隊列容器允許從一端新增元素，從另一端移除元素

隊列中只有隊頭和隊尾纔可以被外界使用，因此隊列不允許有遍歷行爲

隊列中進數據稱爲 --- **入隊**    `push`

隊列中出數據稱爲 --- **出隊**    `pop`



生活中的隊列：

![1547606785041](assets/1547606785041.png)







#### 3.6.2 queue 常用接口



功能描述：棧容器常用的對外接口



構造函數：

- `queue<T> que;`                                 //queue採用模板類實現，queue對象的默認構造形式
- `queue(const queue &que);`            //拷貝構造函數

賦值操作：

- `queue& operator=(const queue &que);`           //重載等號操作符

數據存取：

- `push(elem);`                             //往隊尾添加元素
- `pop();`                                      //從隊頭移除第一個元素
- `back();`                                    //返回最後一個元素
- `front(); `                                  //返回第一個元素

大小操作：

- `empty();`            //判斷堆棧是否爲空
- `size(); `              //返回棧的大小



**示例：**

```C++
#include <queue>
#include <string>
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void test01() {

	//創建隊列
	queue<Person> q;

	//準備數據
	Person p1("唐僧", 30);
	Person p2("孫悟空", 1000);
	Person p3("豬八戒", 900);
	Person p4("沙僧", 800);

	//向隊列中添加元素  入隊操作
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	//隊列不提供迭代器，更不支持隨機訪問	
	while (!q.empty()) {
		//輸出隊頭元素
		cout << "隊頭元素-- 姓名： " << q.front().m_Name 
              << " 年齡： "<< q.front().m_Age << endl;
        
		cout << "隊尾元素-- 姓名： " << q.back().m_Name  
              << " 年齡： " << q.back().m_Age << endl;
        
		cout << endl;
		//彈出隊頭元素
		q.pop();
	}

	cout << "隊列大小爲：" << q.size() << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：

- 入隊   --- push
- 出隊   --- pop
- 返回隊頭元素   --- front
- 返回隊尾元素   --- back
- 判斷隊是否爲空   --- empty
- 返回隊列大小   --- size















### 3.7 list容器

#### 3.7.1 list基本概念



**功能：**將數據進行鏈式存儲

**鏈表**（list）是一種物理存儲單元上非連續的存儲結構，數據元素的邏輯順序是通過鏈表中的指針鏈接實現的



鏈表的組成：鏈表由一系列**結點**組成



結點的組成：一個是存儲數據元素的**數據域**，另一個是存儲下一個結點地址的**指針域**



STL中的鏈表是一個雙向循環鏈表



![說明: 2015-11-15_225145](assets/clip_image002-1547608564071.jpg)

由於鏈表的存儲方式並不是連續的內存空間，因此鏈表list中的迭代器只支持前移和後移，屬於**雙向迭代器**



list的優點：

* 採用動態存儲分配，不會造成內存浪費和溢出
* 鏈表執行插入和刪除操作十分方便，修改指針即可，不需要移動大量元素

list的缺點：

* 鏈表靈活，但是空間(指針域) 和 時間（遍歷）額外耗費較大



List有一個重要的性質，插入操作和刪除操作都不會造成原有list迭代器的失效，這在vector是不成立的。



總結：STL中**List和vector是兩個最常被使用的容器**，各有優缺點





#### 3.7.2  list構造函數

**功能描述：**

* 創建list容器



**函數原型：**

* `list<T> lst;`                               //list採用採用模板類實現,對象的默認構造形式：
* `list(beg,end);`                           //構造函數將[beg, end)區間中的元素拷貝給本身。
* `list(n,elem);`                             //構造函數將n個elem拷貝給本身。
* `list(const list &lst);`            //拷貝構造函數。





**示例：**

```C++
#include <list>

void printList(const list<int>& L) {

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	printList(L1);

	list<int>L2(L1.begin(),L1.end());
	printList(L2);

	list<int>L3(L2);
	printList(L3);

	list<int>L4(10, 1000);
	printList(L4);
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：list構造方式同其他幾個STL常用容器，熟練掌握即可













#### 3.7.3 list 賦值和交換

**功能描述：**

* 給list容器進行賦值，以及交換list容器

**函數原型：**

* `assign(beg, end);`            //將[beg, end)區間中的數據拷貝賦值給本身。
* `assign(n, elem);`              //將n個elem拷貝賦值給本身。
* `list& operator=(const list &lst);`         //重載等號操作符
* `swap(lst);`                         //將lst與本身的元素互換。



**示例：**

```C++
#include <list>

void printList(const list<int>& L) {

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//賦值和交換
void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	//賦值
	list<int>L2;
	L2 = L1;
	printList(L2);

	list<int>L3;
	L3.assign(L2.begin(), L2.end());
	printList(L3);

	list<int>L4;
	L4.assign(10, 100);
	printList(L4);

}

//交換
void test02()
{

	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	list<int>L2;
	L2.assign(10, 100);

	cout << "交換前： " << endl;
	printList(L1);
	printList(L2);

	cout << endl;

	L1.swap(L2);

	cout << "交換後： " << endl;
	printList(L1);
	printList(L2);

}

int main() {

	//test01();

	test02();

	system("pause");

	return 0;
}
```

總結：list賦值和交換操作能夠靈活運用即可















#### 3.7.4 list 大小操作

**功能描述：**

* 對list容器的大小進行操作



**函數原型：**

* `size(); `                             //返回容器中元素的個數

* `empty(); `                           //判斷容器是否爲空

* `resize(num);`                   //重新指定容器的長度爲num，若容器變長，則以默認值填充新位置。

  ​					    //如果容器變短，則末尾超出容器長度的元素被刪除。

* `resize(num, elem); `       //重新指定容器的長度爲num，若容器變長，則以elem值填充新位置。

   			 	 	​					    //如果容器變短，則末尾超出容器長度的元素被刪除。



**示例：**

```C++
#include <list>

void printList(const list<int>& L) {

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//大小操作
void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	if (L1.empty())
	{
		cout << "L1爲空" << endl;
	}
	else
	{
		cout << "L1不爲空" << endl;
		cout << "L1的大小爲： " << L1.size() << endl;
	}

	//重新指定大小
	L1.resize(10);
	printList(L1);

	L1.resize(2);
	printList(L1);
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：

- 判斷是否爲空   --- empty
- 返回元素個數   --- size
- 重新指定個數   --- resize











#### 3.7.5 list 插入和刪除

**功能描述：**

* 對list容器進行數據的插入和刪除



**函數原型：**

* push_back(elem);//在容器尾部加入一個元素
* pop_back();//刪除容器中最後一個元素
* push_front(elem);//在容器開頭插入一個元素
* pop_front();//從容器開頭移除第一個元素
* insert(pos,elem);//在pos位置插elem元素的拷貝，返回新數據的位置。
* insert(pos,n,elem);//在pos位置插入n個elem數據，無返回值。
* insert(pos,beg,end);//在pos位置插入[beg,end)區間的數據，無返回值。
* clear();//移除容器的所有數據
* erase(beg,end);//刪除[beg,end)區間的數據，返回下一個數據的位置。
* erase(pos);//刪除pos位置的數據，返回下一個數據的位置。
* remove(elem);//刪除容器中所有與elem值匹配的元素。





**示例：**

```C++
#include <list>

void printList(const list<int>& L) {

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//插入和刪除
void test01()
{
	list<int> L;
	//尾插
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	//頭插
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);

	printList(L);

	//尾刪
	L.pop_back();
	printList(L);

	//頭刪
	L.pop_front();
	printList(L);

	//插入
	list<int>::iterator it = L.begin();
	L.insert(++it, 1000);
	printList(L);

	//刪除
	it = L.begin();
	L.erase(++it);
	printList(L);

	//移除
	L.push_back(10000);
	L.push_back(10000);
	L.push_back(10000);
	printList(L);
	L.remove(10000);
	printList(L);
    
    //清空
	L.clear();
	printList(L);
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：

* 尾插   --- push_back
* 尾刪   --- pop_back
* 頭插   --- push_front
* 頭刪   --- pop_front
* 插入   --- insert
* 刪除   --- erase
* 移除   --- remove
* 清空   --- clear

















#### 3.7.6 list 數據存取

**功能描述：**

* 對list容器中數據進行存取



**函數原型：**

* `front();`        //返回第一個元素。
* `back();`         //返回最後一個元素。





**示例：**

```C++
#include <list>

//數據存取
void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	
	//cout << L1.at(0) << endl;//錯誤 不支持at訪問數據
	//cout << L1[0] << endl; //錯誤  不支持[]方式訪問數據
	cout << "第一個元素爲： " << L1.front() << endl;
	cout << "最後一個元素爲： " << L1.back() << endl;

	//list容器的迭代器是雙向迭代器，不支持隨機訪問
	list<int>::iterator it = L1.begin();
	//it = it + 1;//錯誤，不可以跳躍訪問，即使是+1
}

int main() {

	test01();

	system("pause");

	return 0;
}

```

總結：

* list容器中不可以通過[]或者at方式訪問數據
* 返回第一個元素   --- front
* 返回最後一個元素   --- back











#### 3.7.7 list 反轉和排序

**功能描述：**

* 將容器中的元素反轉，以及將容器中的數據進行排序



**函數原型：**

* `reverse();`   //反轉鏈表
* `sort();`        //鏈表排序





**示例：**

```C++
void printList(const list<int>& L) {

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

bool myCompare(int val1 , int val2)
{
	return val1 > val2;
}

//反轉和排序
void test01()
{
	list<int> L;
	L.push_back(90);
	L.push_back(30);
	L.push_back(20);
	L.push_back(70);
	printList(L);

	//反轉容器的元素
	L.reverse();
	printList(L);

	//排序
	L.sort(); //默認的排序規則 從小到大
	printList(L);

	L.sort(myCompare); //指定規則，從大到小
	printList(L);
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：

* 反轉   --- reverse
* 排序   --- sort （成員函數）











#### 3.7.8 排序案例

案例描述：將Person自定義數據類型進行排序，Person中屬性有姓名、年齡、身高

排序規則：按照年齡進行升序，如果年齡相同按照身高進行降序



**示例：**

```C++
#include <list>
#include <string>
class Person {
public:
	Person(string name, int age , int height) {
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}

public:
	string m_Name;  //姓名
	int m_Age;      //年齡
	int m_Height;   //身高
};


bool ComparePerson(Person& p1, Person& p2) {

	if (p1.m_Age == p2.m_Age) {
		return p1.m_Height  > p2.m_Height;
	}
	else
	{
		return  p1.m_Age < p2.m_Age;
	}

}

void test01() {

	list<Person> L;

	Person p1("劉備", 35 , 175);
	Person p2("曹操", 45 , 180);
	Person p3("孫權", 40 , 170);
	Person p4("趙雲", 25 , 190);
	Person p5("張飛", 35 , 160);
	Person p6("關羽", 35 , 200);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	for (list<Person>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "姓名： " << it->m_Name << " 年齡： " << it->m_Age 
              << " 身高： " << it->m_Height << endl;
	}

	cout << "---------------------------------" << endl;
	L.sort(ComparePerson); //排序

	for (list<Person>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "姓名： " << it->m_Name << " 年齡： " << it->m_Age 
              << " 身高： " << it->m_Height << endl;
	}
}

int main() {

	test01();

	system("pause");

	return 0;
}
```



總結：

* 對於自定義數據類型，必須要指定排序規則，否則編譯器不知道如何進行排序


* 高級排序只是在排序規則上再進行一次邏輯規則制定，並不複雜



















### 3.8 set/ multiset 容器

#### 3.8.1 set基本概念

**簡介：**

* 所有元素都會在插入時自動被排序





**本質：**

* set/multiset屬於**關聯式容器**，底層結構是用**二叉樹**實現。





**set和multiset區別**：

* set不允許容器中有重複的元素
* multiset允許容器中有重複的元素





#### 3.8.2 set構造和賦值

功能描述：創建set容器以及賦值



構造：

* `set<T> st;`                        //默認構造函數：
* `set(const set &st);`       //拷貝構造函數

賦值：

* `set& operator=(const set &st);`    //重載等號操作符



**示例：**

```C++
#include <set>

void printSet(set<int> & s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//構造和賦值
void test01()
{
	set<int> s1;

	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);

	//拷貝構造
	set<int>s2(s1);
	printSet(s2);

	//賦值
	set<int>s3;
	s3 = s2;
	printSet(s3);
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：

* set容器插入數據時用insert
* set容器插入數據的數據會自動排序











#### 3.8.3 set大小和交換

**功能描述：**

* 統計set容器大小以及交換set容器



**函數原型：**

* `size();`          //返回容器中元素的數目
* `empty();`        //判斷容器是否爲空
* `swap(st);`      //交換兩個集合容器



**示例：**

```C++
#include <set>

void printSet(set<int> & s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//大小
void test01()
{

	set<int> s1;
	
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	if (s1.empty())
	{
		cout << "s1爲空" << endl;
	}
	else
	{
		cout << "s1不爲空" << endl;
		cout << "s1的大小爲： " << s1.size() << endl;
	}

}

//交換
void test02()
{
	set<int> s1;

	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	set<int> s2;

	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);

	cout << "交換前" << endl;
	printSet(s1);
	printSet(s2);
	cout << endl;

	cout << "交換後" << endl;
	s1.swap(s2);
	printSet(s1);
	printSet(s2);
}

int main() {

	//test01();

	test02();

	system("pause");

	return 0;
}
```

總結：

* 統計大小   --- size
* 判斷是否爲空   --- empty
* 交換容器   --- swap

















#### 3.8.4 set插入和刪除

**功能描述：**

* set容器進行插入數據和刪除數據





**函數原型：**

* `insert(elem);`           //在容器中插入元素。
* `clear();`                    //清除所有元素
* `erase(pos);`              //刪除pos迭代器所指的元素，返回下一個元素的迭代器。
* `erase(beg, end);`    //刪除區間[beg,end)的所有元素 ，返回下一個元素的迭代器。
* `erase(elem);`            //刪除容器中值爲elem的元素。





**示例：**

```C++
#include <set>

void printSet(set<int> & s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//插入和刪除
void test01()
{
	set<int> s1;
	//插入
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);

	//刪除
	s1.erase(s1.begin());
	printSet(s1);

	s1.erase(30);
	printSet(s1);

	//清空
	//s1.erase(s1.begin(), s1.end());
	s1.clear();
	printSet(s1);
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：

* 插入   --- insert
* 刪除   --- erase
* 清空   --- clear











#### 3.8.5 set查找和統計

**功能描述：**

* 對set容器進行查找數據以及統計數據



**函數原型：**

* `find(key);`                  //查找key是否存在,若存在，返回該鍵的元素的迭代器；若不存在，返回set.end();
* `count(key);`                //統計key的元素個數





**示例：**

```C++
#include <set>

//查找和統計
void test01()
{
	set<int> s1;
	//插入
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	
	//查找
	set<int>::iterator pos = s1.find(30);

	if (pos != s1.end())
	{
		cout << "找到了元素 ： " << *pos << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

	//統計
	int num = s1.count(30);
	cout << "num = " << num << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：

* 查找   ---  find    （返回的是迭代器）
* 統計   ---  count  （對於set，結果爲0或者1）

















#### 3.8.6 set和multiset區別

**學習目標：**

* 掌握set和multiset的區別



**區別：**

* set不可以插入重複數據，而multiset可以
* set插入數據的同時會返回插入結果，表示插入是否成功
* multiset不會檢測數據，因此可以插入重複數據





**示例：**

```C++
#include <set>

//set和multiset區別
void test01()
{
	set<int> s;
	pair<set<int>::iterator, bool>  ret = s.insert(10);
	if (ret.second) {
		cout << "第一次插入成功!" << endl;
	}
	else {
		cout << "第一次插入失敗!" << endl;
	}

	ret = s.insert(10);
	if (ret.second) {
		cout << "第二次插入成功!" << endl;
	}
	else {
		cout << "第二次插入失敗!" << endl;
	}
    
	//multiset
	multiset<int> ms;
	ms.insert(10);
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：

* 如果不允許插入重複數據可以利用set
* 如果需要插入重複數據利用multiset











#### 3.8.7 pair對組創建

**功能描述：**

* 成對出現的數據，利用對組可以返回兩個數據





**兩種創建方式：**

* `pair<type, type> p ( value1, value2 );`
* `pair<type, type> p = make_pair( value1, value2 );`





**示例：**

```C++
#include <string>

//對組創建
void test01()
{
	pair<string, int> p(string("Tom"), 20);
	cout << "姓名： " <<  p.first << " 年齡： " << p.second << endl;

	pair<string, int> p2 = make_pair("Jerry", 10);
	cout << "姓名： " << p2.first << " 年齡： " << p2.second << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：

兩種方式都可以創建對組，記住一種即可













#### 3.8.8 set容器排序

學習目標：

* set容器默認排序規則爲從小到大，掌握如何改變排序規則



主要技術點：

* 利用仿函數，可以改變排序規則





**示例一**   set存放內置數據類型

```C++
#include <set>

class MyCompare 
{
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};
void test01() 
{    
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(50);

	//默認從小到大
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//指定排序規則
	set<int,MyCompare> s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(30);
	s2.insert(50);

	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：利用仿函數可以指定set容器的排序規則



**示例二** set存放自定義數據類型

```C++
#include <set>
#include <string>

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;

};
class comparePerson
{
public:
	bool operator()(const Person& p1, const Person &p2)
	{
		//按照年齡進行排序  降序
		return p1.m_Age > p2.m_Age;
	}
};

void test01()
{
	set<Person, comparePerson> s;

	Person p1("劉備", 23);
	Person p2("關羽", 27);
	Person p3("張飛", 25);
	Person p4("趙雲", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名： " << it->m_Name << " 年齡： " << it->m_Age << endl;
	}
}
int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：

對於自定義數據類型，set必須指定排序規則纔可以插入數據











### 3.9 map/ multimap容器

#### 3.9.1 map基本概念

**簡介：**

* map中所有元素都是pair
* pair中第一個元素爲key（鍵值），起到索引作用，第二個元素爲value（實值）
* 所有元素都會根據元素的鍵值自動排序



**本質：**

* map/multimap屬於**關聯式容器**，底層結構是用二叉樹實現。



**優點：**

* 可以根據key值快速找到value值



map和multimap**區別**：

- map不允許容器中有重複key值元素
- multimap允許容器中有重複key值元素




#### 3.9.2  map構造和賦值

**功能描述：**

* 對map容器進行構造和賦值操作

**函數原型：**

**構造：**

* `map<T1, T2> mp;`                     //map默認構造函數: 
* `map(const map &mp);`             //拷貝構造函數



**賦值：**

* `map& operator=(const map &mp);`    //重載等號操作符



**示例：**

```C++
#include <map>

void printMap(map<int,int>&m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

void test01()
{
	map<int,int>m; //默認構造
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	printMap(m);

	map<int, int>m2(m); //拷貝構造
	printMap(m2);

	map<int, int>m3;
	m3 = m2; //賦值
	printMap(m3);
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：map中所有元素都是成對出現，插入數據時候要使用對組











#### 3.9.3 map大小和交換

**功能描述：**

* 統計map容器大小以及交換map容器





函數原型：

- `size();`          //返回容器中元素的數目
- `empty();`        //判斷容器是否爲空
- `swap(st);`      //交換兩個集合容器





**示例：**

```C++
#include <map>

void printMap(map<int,int>&m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

void test01()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	if (m.empty())
	{
		cout << "m爲空" << endl;
	}
	else
	{
		cout << "m不爲空" << endl;
		cout << "m的大小爲： " << m.size() << endl;
	}
}


//交換
void test02()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	map<int, int>m2;
	m2.insert(pair<int, int>(4, 100));
	m2.insert(pair<int, int>(5, 200));
	m2.insert(pair<int, int>(6, 300));

	cout << "交換前" << endl;
	printMap(m);
	printMap(m2);

	cout << "交換後" << endl;
	m.swap(m2);
	printMap(m);
	printMap(m2);
}

int main() {

	test01();

	test02();

	system("pause");

	return 0;
}
```

總結：

- 統計大小   --- size
- 判斷是否爲空   --- empty
- 交換容器   --- swap











#### 3.9.4 map插入和刪除

**功能描述：**

- map容器進行插入數據和刪除數據





**函數原型：**

- `insert(elem);`           //在容器中插入元素。
- `clear();`                    //清除所有元素
- `erase(pos);`              //刪除pos迭代器所指的元素，返回下一個元素的迭代器。
- `erase(beg, end);`    //刪除區間[beg,end)的所有元素 ，返回下一個元素的迭代器。
- `erase(key);`            //刪除容器中值爲key的元素。



**示例：**

```C++
#include <map>

void printMap(map<int,int>&m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

void test01()
{
	//插入
	map<int, int> m;
	//第一種插入方式
	m.insert(pair<int, int>(1, 10));
	//第二種插入方式
	m.insert(make_pair(2, 20));
	//第三種插入方式
	m.insert(map<int, int>::value_type(3, 30));
	//第四種插入方式
	m[4] = 40; 
	printMap(m);

	//刪除
	m.erase(m.begin());
	printMap(m);

	m.erase(3);
	printMap(m);

	//清空
	m.erase(m.begin(),m.end());
	m.clear();
	printMap(m);
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：

* map插入方式很多，記住其一即可

- 插入   --- insert 
- 刪除   --- erase
- 清空   --- clear













#### 3.9.5 map查找和統計

**功能描述：**

- 對map容器進行查找數據以及統計數據



**函數原型：**

- `find(key);`                  //查找key是否存在,若存在，返回該鍵的元素的迭代器；若不存在，返回set.end();
- `count(key);`                //統計key的元素個數



**示例：**

```C++
#include <map>

//查找和統計
void test01()
{
	map<int, int>m; 
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	//查找
	map<int, int>::iterator pos = m.find(3);

	if (pos != m.end())
	{
		cout << "找到了元素 key = " << (*pos).first << " value = " << (*pos).second << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

	//統計
	int num = m.count(3);
	cout << "num = " << num << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：

- 查找   ---  find    （返回的是迭代器）
- 統計   ---  count  （對於map，結果爲0或者1）















#### 3.9.6 map容器排序

**學習目標：**

- map容器默認排序規則爲 按照key值進行 從小到大排序，掌握如何改變排序規則





**主要技術點:**

- 利用仿函數，可以改變排序規則





**示例：**

```C++
#include <map>

class MyCompare {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};

void test01() 
{
	//默認從小到大排序
	//利用仿函數實現從大到小排序
	map<int, int, MyCompare> m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));

	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
}
int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：

* 利用仿函數可以指定map容器的排序規則
* 對於自定義數據類型，map必須要指定排序規則,同set容器













### 3.10 案例-員工分組

#### 3.10.1 案例描述

* 公司今天招聘了10個員工（ABCDEFGHIJ），10名員工進入公司之後，需要指派員工在那個部門工作
* 員工信息有: 姓名  工資組成；部門分爲：策劃、美術、研發
* 隨機給10名員工分配部門和工資
* 通過multimap進行信息的插入  key(部門編號) value(員工)
* 分部門顯示員工信息





#### 3.10.2 實現步驟

1. 創建10名員工，放到vector中
2. 遍歷vector容器，取出每個員工，進行隨機分組
3. 分組後，將員工部門編號作爲key，具體員工作爲value，放入到multimap容器中
4. 分部門顯示員工信息





**案例代碼：**

```C++
#include<iostream>
using namespace std;
#include <vector>
#include <string>
#include <map>
#include <ctime>

/*
- 公司今天招聘了10個員工（ABCDEFGHIJ），10名員工進入公司之後，需要指派員工在那個部門工作
- 員工信息有: 姓名  工資組成；部門分爲：策劃、美術、研發
- 隨機給10名員工分配部門和工資
- 通過multimap進行信息的插入  key(部門編號) value(員工)
- 分部門顯示員工信息
*/

#define CEHUA  0
#define MEISHU 1
#define YANFA  2

class Worker
{
public:
	string m_Name;
	int m_Salary;
};

void createWorker(vector<Worker>&v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "員工";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000; // 10000 ~ 19999
		//將員工放入到容器中
		v.push_back(worker);
	}
}

//員工分組
void setGroup(vector<Worker>&v,multimap<int,Worker>&m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//產生隨機部門編號
		int deptId = rand() % 3; // 0 1 2 

		//將員工插入到分組中
		//key部門編號，value具體員工
		m.insert(make_pair(deptId, *it));
	}
}

void showWorkerByGourp(multimap<int,Worker>&m)
{
	// 0  A  B  C   1  D  E   2  F G ...
	cout << "策劃部門：" << endl;

	multimap<int,Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA); // 統計具體人數
	int index = 0;
	for (; pos != m.end() && index < count; pos++ , index++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工資： " << pos->second.m_Salary << endl;
	}

	cout << "----------------------" << endl;
	cout << "美術部門： " << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU); // 統計具體人數
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工資： " << pos->second.m_Salary << endl;
	}

	cout << "----------------------" << endl;
	cout << "研發部門： " << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA); // 統計具體人數
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工資： " << pos->second.m_Salary << endl;
	}

}

int main() {

	srand((unsigned int)time(NULL));

	//1、創建員工
	vector<Worker>vWorker;
	createWorker(vWorker);

	//2、員工分組
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);


	//3、分組顯示員工
	showWorkerByGourp(mWorker);

	////測試
	//for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	//{
	//	cout << "姓名： " << it->m_Name << " 工資： " << it->m_Salary << endl;
	//}

	system("pause");

	return 0;
}
```

總結：

* 當數據以鍵值對形式存在，可以考慮用map 或 multimap







## 4 STL- 函數對象

### 4.1 函數對象

#### 4.1.1 函數對象概念

**概念：**

* 重載**函數調用操作符**的類，其對象常稱爲**函數對象**
* **函數對象**使用重載的()時，行爲類似函數調用，也叫**仿函數**



**本質：**

函數對象(仿函數)是一個**類**，不是一個函數



#### 4.1.2  函數對象使用

**特點：**

* 函數對象在使用時，可以像普通函數那樣調用, 可以有參數，可以有返回值
* 函數對象超出普通函數的概念，函數對象可以有自己的狀態
* 函數對象可以作爲參數傳遞





**示例:**

```C++
#include <string>

//1、函數對象在使用時，可以像普通函數那樣調用, 可以有參數，可以有返回值
class MyAdd
{
public :
	int operator()(int v1,int v2)
	{
		return v1 + v2;
	}
};

void test01()
{
	MyAdd myAdd;
	cout << myAdd(10, 10) << endl;
}

//2、函數對象可以有自己的狀態
class MyPrint
{
public:
	MyPrint()
	{
		count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		count++; //統計使用次數
	}

	int count; //內部自己的狀態
};
void test02()
{
	MyPrint myPrint;
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	cout << "myPrint調用次數爲： " << myPrint.count << endl;
}

//3、函數對象可以作爲參數傳遞
void doPrint(MyPrint &mp , string test)
{
	mp(test);
}

void test03()
{
	MyPrint myPrint;
	doPrint(myPrint, "Hello C++");
}

int main() {

	//test01();
	//test02();
	test03();

	system("pause");

	return 0;
}
```

總結：

* 仿函數寫法非常靈活，可以作爲參數進行傳遞。













### 4.2  謂詞

#### 4.2.1 謂詞概念



**概念：**

* 返回bool類型的仿函數稱爲**謂詞**
* 如果operator()接受一個參數，那麼叫做一元謂詞
* 如果operator()接受兩個參數，那麼叫做二元謂詞





#### 4.2.2 一元謂詞

**示例：**

```C++
#include <vector>
#include <algorithm>

//1.一元謂詞
struct GreaterFive{
	bool operator()(int val) {
		return val > 5;
	}
};

void test01() {

	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end()) {
		cout << "沒找到!" << endl;
	}
	else {
		cout << "找到:" << *it << endl;
	}

}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：參數只有一個的謂詞，稱爲一元謂詞











#### 4.2.3 二元謂詞

**示例：**

```C++
#include <vector>
#include <algorithm>
//二元謂詞
class MyCompare
{
public:
	bool operator()(int num1, int num2)
	{
		return num1 > num2;
	}
};

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);

	//默認從小到大
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "----------------------------" << endl;

	//使用函數對象改變算法策略，排序從大到小
	sort(v.begin(), v.end(), MyCompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：參數只有兩個的謂詞，稱爲二元謂詞

















### 4.3 內建函數對象

#### 4.3.1 內建函數對象意義

**概念：**

* STL內建了一些函數對象



**分類:**

* 算術仿函數

* 關係仿函數

* 邏輯仿函數

**用法：**

* 這些仿函數所產生的對象，用法和一般函數完全相同
* 使用內建函數對象，需要引入頭文件 `#include<functional>`







#### 4.3.2 算術仿函數

**功能描述：**

* 實現四則運算
* 其中negate是一元運算，其他都是二元運算



**仿函數原型：**

* `template<class T> T plus<T>`                //加法仿函數
* `template<class T> T minus<T>`              //減法仿函數
* `template<class T> T multiplies<T>`    //乘法仿函數
* `template<class T> T divides<T>`         //除法仿函數
* `template<class T> T modulus<T>`         //取模仿函數
* `template<class T> T negate<T>`           //取反仿函數



**示例：**

```C++
#include <functional>
//negate
void test01()
{
	negate<int> n;
	cout << n(50) << endl;
}

//plus
void test02()
{
	plus<int> p;
	cout << p(10, 20) << endl;
}

int main() {

	test01();
	test02();

	system("pause");

	return 0;
}
```

總結：使用內建函數對象時，需要引入頭文件 `#include <functional>`









#### 4.3.3 關係仿函數

**功能描述：**

- 實現關係對比



**仿函數原型：**

* `template<class T> bool equal_to<T>`                    //等於
* `template<class T> bool not_equal_to<T>`            //不等於
* `template<class T> bool greater<T>`                      //大於
* `template<class T> bool greater_equal<T>`          //大於等於
* `template<class T> bool less<T>`                           //小於
* `template<class T> bool less_equal<T>`               //小於等於



**示例：**

```C++
#include <functional>
#include <vector>
#include <algorithm>

class MyCompare
{
public:
	bool operator()(int v1,int v2)
	{
		return v1 > v2;
	}
};
void test01()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//自己實現仿函數
	//sort(v.begin(), v.end(), MyCompare());
	//STL內建仿函數  大於仿函數
	sort(v.begin(), v.end(), greater<int>());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：關係仿函數中最常用的就是greater<>大於











#### 4.3.4 邏輯仿函數

**功能描述：**

- 實現邏輯運算



**函數原型：**

* `template<class T> bool logical_and<T>`              //邏輯與
* `template<class T> bool logical_or<T>`                //邏輯或
* `template<class T> bool logical_not<T>`              //邏輯非



**示例：**

```C++
#include <vector>
#include <functional>
#include <algorithm>
void test01()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin();it!= v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//邏輯非  將v容器搬運到v2中，並執行邏輯非運算
	vector<bool> v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(),  v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：邏輯仿函數實際應用較少，瞭解即可







## 5 STL- 常用算法



**概述**:

* 算法主要是由頭文件`<algorithm>` `<functional>` `<numeric>`組成。



* `<algorithm>`是所有STL頭文件中最大的一個，範圍涉及到比較、 交換、查找、遍歷操作、複製、修改等等
* `<numeric>`體積很小，只包括幾個在序列上面進行簡單數學運算的模板函數
* `<functional>`定義了一些模板類,用以聲明函數對象。





### 5.1 常用遍歷算法

**學習目標：**

* 掌握常用的遍歷算法



**算法簡介：**

* `for_each`     //遍歷容器
* `transform`   //搬運容器到另一個容器中





#### 5.1.1 for_each

**功能描述：**

* 實現遍歷容器

**函數原型：**

* `for_each(iterator beg, iterator end, _func);  `

  // 遍歷算法 遍歷容器元素

  // beg 開始迭代器

  // end 結束迭代器

  // _func 函數或者函數對象



**示例：**

```C++
#include <algorithm>
#include <vector>

//普通函數
void print01(int val) 
{
	cout << val << " ";
}
//函數對象
class print02 
{
 public:
	void operator()(int val) 
	{
		cout << val << " ";
	}
};

//for_each算法基本用法
void test01() {

	vector<int> v;
	for (int i = 0; i < 10; i++) 
	{
		v.push_back(i);
	}

	//遍歷算法
	for_each(v.begin(), v.end(), print01);
	cout << endl;

	for_each(v.begin(), v.end(), print02());
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**總結：**for_each在實際開發中是最常用遍歷算法，需要熟練掌握









#### 5.1.2 transform

**功能描述：**

* 搬運容器到另一個容器中

**函數原型：**

* `transform(iterator beg1, iterator end1, iterator beg2, _func);`

//beg1 源容器開始迭代器

//end1 源容器結束迭代器

//beg2 目標容器開始迭代器

//_func 函數或者函數對象



**示例：**

```C++
#include<vector>
#include<algorithm>

//常用遍歷算法  搬運 transform

class TransForm
{
public:
	int operator()(int val)
	{
		return val;
	}

};

class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>vTarget; //目標容器

	vTarget.resize(v.size()); // 目標容器需要提前開闢空間

	transform(v.begin(), v.end(), vTarget.begin(), TransForm());

	for_each(vTarget.begin(), vTarget.end(), MyPrint());
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**總結：** 搬運的目標容器必須要提前開闢空間，否則無法正常搬運







### 5.2 常用查找算法

學習目標：

- 掌握常用的查找算法





**算法簡介：**

- `find`                     //查找元素
- `find_if`               //按條件查找元素
- `adjacent_find`    //查找相鄰重複元素
- `binary_search`    //二分查找法
- `count`                   //統計元素個數
- `count_if`             //按條件統計元素個數




#### 5.2.1 find

**功能描述：**

* 查找指定元素，找到返回指定元素的迭代器，找不到返回結束迭代器end()



**函數原型：**

- `find(iterator beg, iterator end, value);  `

  // 按值查找元素，找到返回指定位置迭代器，找不到返回結束迭代器位置

  // beg 開始迭代器

  // end 結束迭代器

  // value 查找的元素





**示例：**

```C++
#include <algorithm>
#include <vector>
#include <string>
void test01() {

	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i + 1);
	}
	//查找容器中是否有 5 這個元素
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end()) 
	{
		cout << "沒有找到!" << endl;
	}
	else 
	{
		cout << "找到:" << *it << endl;
	}
}

class Person {
public:
	Person(string name, int age) 
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	//重載==
	bool operator==(const Person& p) 
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) 
		{
			return true;
		}
		return false;
	}

public:
	string m_Name;
	int m_Age;
};

void test02() {

	vector<Person> v;

	//創建數據
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator it = find(v.begin(), v.end(), p2);
	if (it == v.end()) 
	{
		cout << "沒有找到!" << endl;
	}
	else 
	{
		cout << "找到姓名:" << it->m_Name << " 年齡: " << it->m_Age << endl;
	}
}
```

總結： 利用find可以在容器中找指定的元素，返回值是**迭代器**













#### 5.2.2 find_if

**功能描述：**

* 按條件查找元素

**函數原型：**

- `find_if(iterator beg, iterator end, _Pred);  `

  // 按值查找元素，找到返回指定位置迭代器，找不到返回結束迭代器位置

  // beg 開始迭代器

  // end 結束迭代器

  // _Pred 函數或者謂詞（返回bool類型的仿函數）



**示例：**

```C++
#include <algorithm>
#include <vector>
#include <string>

//內置數據類型
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test01() {

	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i + 1);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end()) {
		cout << "沒有找到!" << endl;
	}
	else {
		cout << "找到大於5的數字:" << *it << endl;
	}
}

//自定義數據類型
class Person {
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};

class Greater20
{
public:
	bool operator()(Person &p)
	{
		return p.m_Age > 20;
	}

};

void test02() {

	vector<Person> v;

	//創建數據
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20());
	if (it == v.end())
	{
		cout << "沒有找到!" << endl;
	}
	else
	{
		cout << "找到姓名:" << it->m_Name << " 年齡: " << it->m_Age << endl;
	}
}

int main() {

	//test01();

	test02();

	system("pause");

	return 0;
}
```

總結：find_if按條件查找使查找更加靈活，提供的仿函數可以改變不同的策略















#### 5.2.3 adjacent_find

**功能描述：**

* 查找相鄰重複元素



**函數原型：**

- `adjacent_find(iterator beg, iterator end);  `

  // 查找相鄰重複元素,返回相鄰元素的第一個位置的迭代器

  // beg 開始迭代器

  // end 結束迭代器

  ​



**示例：**

```C++
#include <algorithm>
#include <vector>

void test01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);

	//查找相鄰重複元素
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end()) {
		cout << "找不到!" << endl;
	}
	else {
		cout << "找到相鄰重複元素爲:" << *it << endl;
	}
}
```

總結：面試題中如果出現查找相鄰重複元素，記得用STL中的adjacent_find算法









#### 5.2.4 binary_search

**功能描述：**

* 查找指定元素是否存在



**函數原型：**

- `bool binary_search(iterator beg, iterator end, value);  `

  // 查找指定的元素，查到 返回true  否則false

  // 注意: 在**無序序列中不可用**

  // beg 開始迭代器

  // end 結束迭代器

  // value 查找的元素





**示例：**

```C++
#include <algorithm>
#include <vector>

void test01()
{
	vector<int>v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//二分查找
	bool ret = binary_search(v.begin(), v.end(),2);
	if (ret)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**總結：**二分查找法查找效率很高，值得注意的是查找的容器中元素必須的有序序列









#### 5.2.5 count

**功能描述：**

* 統計元素個數



**函數原型：**

- `count(iterator beg, iterator end, value);  `

  // 統計元素出現次數

  // beg 開始迭代器

  // end 結束迭代器

  // value 統計的元素





**示例：**

```C++
#include <algorithm>
#include <vector>

//內置數據類型
void test01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);

	int num = count(v.begin(), v.end(), 4);

	cout << "4的個數爲： " << num << endl;
}

//自定義數據類型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	bool operator==(const Person & p)
	{
		if (this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string m_Name;
	int m_Age;
};

void test02()
{
	vector<Person> v;

	Person p1("劉備", 35);
	Person p2("關羽", 35);
	Person p3("張飛", 35);
	Person p4("趙雲", 30);
	Person p5("曹操", 25);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
    
    Person p("諸葛亮",35);

	int num = count(v.begin(), v.end(), p);
	cout << "num = " << num << endl;
}
int main() {

	//test01();

	test02();

	system("pause");

	return 0;
}
```

**總結：** 統計自定義數據類型時候，需要配合重載 `operator==`

















#### 5.2.6 count_if

**功能描述：**

* 按條件統計元素個數

**函數原型：**

- `count_if(iterator beg, iterator end, _Pred);  `

  // 按條件統計元素出現次數

  // beg 開始迭代器

  // end 結束迭代器

  // _Pred 謂詞

  ​

**示例：**

```C++
#include <algorithm>
#include <vector>

class Greater4
{
public:
	bool operator()(int val)
	{
		return val >= 4;
	}
};

//內置數據類型
void test01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);

	int num = count_if(v.begin(), v.end(), Greater4());

	cout << "大於4的個數爲： " << num << endl;
}

//自定義數據類型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

class AgeLess35
{
public:
	bool operator()(const Person &p)
	{
		return p.m_Age < 35;
	}
};
void test02()
{
	vector<Person> v;

	Person p1("劉備", 35);
	Person p2("關羽", 35);
	Person p3("張飛", 35);
	Person p4("趙雲", 30);
	Person p5("曹操", 25);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	int num = count_if(v.begin(), v.end(), AgeLess35());
	cout << "小於35歲的個數：" << num << endl;
}


int main() {

	//test01();

	test02();

	system("pause");

	return 0;
}
```

**總結：**按值統計用count，按條件統計用count_if













### 5.3 常用排序算法

**學習目標：**

- 掌握常用的排序算法

**算法簡介：**

- `sort`             //對容器內元素進行排序
- `random_shuffle`   //洗牌   指定範圍內的元素隨機調整次序
- `merge `           // 容器元素合併，並存儲到另一容器中
- `reverse`       // 反轉指定範圍的元素





#### 5.3.1 sort

**功能描述：**

* 對容器內元素進行排序





**函數原型：**

- `sort(iterator beg, iterator end, _Pred);  `

  // 按值查找元素，找到返回指定位置迭代器，找不到返回結束迭代器位置

  //  beg    開始迭代器

  //  end    結束迭代器

  // _Pred  謂詞





**示例：**

```c++
#include <algorithm>
#include <vector>

void myPrint(int val)
{
	cout << val << " ";
}

void test01() {
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	//sort默認從小到大排序
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	//從大到小排序
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**總結：**sort屬於開發中最常用的算法之一，需熟練掌握













#### 5.3.2 random_shuffle

**功能描述：**

* 洗牌   指定範圍內的元素隨機調整次序



**函數原型：**

- `random_shuffle(iterator beg, iterator end);  `

  // 指定範圍內的元素隨機調整次序

  // beg 開始迭代器

  // end 結束迭代器

  ​

**示例：**

```c++
#include <algorithm>
#include <vector>
#include <ctime>

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	srand((unsigned int)time(NULL));
	vector<int> v;
	for(int i = 0 ; i < 10;i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;

	//打亂順序
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**總結：**random_shuffle洗牌算法比較實用，使用時記得加隨機數種子















#### 5.3.3 merge

**功能描述：**

* 兩個容器元素合併，並存儲到另一容器中



**函數原型：**

- `merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  `

  // 容器元素合併，並存儲到另一容器中

  // 注意: 兩個容器必須是**有序的**

  // beg1   容器1開始迭代器
  // end1   容器1結束迭代器
  // beg2   容器2開始迭代器
  // end2   容器2結束迭代器
  // dest    目標容器開始迭代器

  ​

**示例：**

```c++
#include <algorithm>
#include <vector>

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10 ; i++) 
    {
		v1.push_back(i);
		v2.push_back(i + 1);
	}

	vector<int> vtarget;
	//目標容器需要提前開闢空間
	vtarget.resize(v1.size() + v2.size());
	//合併  需要兩個有序序列
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
	for_each(vtarget.begin(), vtarget.end(), myPrint());
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**總結：**merge合併的兩個容器必須的有序序列











#### 5.3.4 reverse

**功能描述：**

* 將容器內元素進行反轉



**函數原型：**

- `reverse(iterator beg, iterator end);  `

  // 反轉指定範圍的元素

  // beg 開始迭代器

  // end 結束迭代器

  ​

**示例：**

```c++
#include <algorithm>
#include <vector>

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	cout << "反轉前： " << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;

	cout << "反轉後： " << endl;

	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**總結：**reverse反轉區間內元素，面試題可能涉及到









### 5.4 常用拷貝和替換算法

**學習目標：**

- 掌握常用的拷貝和替換算法

**算法簡介：**

- `copy`                      // 容器內指定範圍的元素拷貝到另一容器中
- `replace`                // 將容器內指定範圍的舊元素修改爲新元素
- `replace_if `          // 容器內指定範圍滿足條件的元素替換爲新元素
- `swap`                     // 互換兩個容器的元素




#### 5.4.1 copy

**功能描述：**

* 容器內指定範圍的元素拷貝到另一容器中



**函數原型：**

- `copy(iterator beg, iterator end, iterator dest);  `

  // 按值查找元素，找到返回指定位置迭代器，找不到返回結束迭代器位置

  // beg  開始迭代器

  // end  結束迭代器

  // dest 目標起始迭代器



**示例：**

```c++
#include <algorithm>
#include <vector>

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i + 1);
	}
	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());

	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**總結：**利用copy算法在拷貝時，目標容器記得提前開闢空間















#### 5.4.2 replace

**功能描述：**

* 將容器內指定範圍的舊元素修改爲新元素



**函數原型：**

- `replace(iterator beg, iterator end, oldvalue, newvalue);  `

  // 將區間內舊元素 替換成 新元素

  // beg 開始迭代器

  // end 結束迭代器

  // oldvalue 舊元素

  // newvalue 新元素



**示例：**

```c++
#include <algorithm>
#include <vector>

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);

	cout << "替換前：" << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;

	//將容器中的20 替換成 2000
	cout << "替換後：" << endl;
	replace(v.begin(), v.end(), 20,2000);
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**總結：**replace會替換區間內滿足條件的元素













#### 5.4.3 replace_if

**功能描述:**  

* 將區間內滿足條件的元素，替換成指定元素



**函數原型：**

- `replace_if(iterator beg, iterator end, _pred, newvalue);  `

  // 按條件替換元素，滿足條件的替換成指定元素

  // beg 開始迭代器

  // end 結束迭代器

  // _pred 謂詞

  // newvalue 替換的新元素



**示例：**

```c++
#include <algorithm>
#include <vector>

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

class ReplaceGreater30
{
public:
	bool operator()(int val)
	{
		return val >= 30;
	}

};

void test01()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);

	cout << "替換前：" << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;

	//將容器中大於等於的30 替換成 3000
	cout << "替換後：" << endl;
	replace_if(v.begin(), v.end(), ReplaceGreater30(), 3000);
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**總結：**replace_if按條件查找，可以利用仿函數靈活篩選滿足的條件







#### 5.4.4 swap

**功能描述：**

* 互換兩個容器的元素



**函數原型：**

- `swap(container c1, container c2);  `

  // 互換兩個容器的元素

  // c1容器1

  // c2容器2

  ​

**示例：**

```c++
#include <algorithm>
#include <vector>

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+100);
	}

	cout << "交換前： " << endl;
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;

	cout << "交換後： " << endl;
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**總結：**swap交換容器時，注意交換的容器要同種類型













### 5.5 常用算術生成算法

**學習目標：**

- 掌握常用的算術生成算法



**注意：**

* 算術生成算法屬於小型算法，使用時包含的頭文件爲 `#include <numeric>`



**算法簡介：**

- `accumulate`      // 計算容器元素累計總和

- `fill`                 // 向容器中添加元素

  ​

#### 5.5.1 accumulate

**功能描述：**

*  計算區間內 容器元素累計總和



**函數原型：**

- `accumulate(iterator beg, iterator end, value);  `

  // 計算容器元素累計總和

  // beg 開始迭代器

  // end 結束迭代器

  // value 起始值



**示例：**

```c++
#include <numeric>
#include <vector>
void test01()
{
	vector<int> v;
	for (int i = 0; i <= 100; i++) {
		v.push_back(i);
	}

	int total = accumulate(v.begin(), v.end(), 0);

	cout << "total = " << total << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**總結：**accumulate使用時頭文件注意是 numeric，這個算法很實用



#### 5.5.2 fill

**功能描述：**

* 向容器中填充指定的元素



**函數原型：**

- `fill(iterator beg, iterator end, value);  `

  // 向容器中填充元素

  // beg 開始迭代器

  // end 結束迭代器

  // value 填充的值



**示例：**

```c++
#include <numeric>
#include <vector>
#include <algorithm>

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{

	vector<int> v;
	v.resize(10);
	//填充
	fill(v.begin(), v.end(), 100);

	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**總結：**利用fill可以將容器區間內元素填充爲 指定的值





### 5.6 常用集合算法

**學習目標：**

- 掌握常用的集合算法



**算法簡介：**

- `set_intersection`          // 求兩個容器的交集

- `set_union`                       // 求兩個容器的並集

- `set_difference `              // 求兩個容器的差集

  ​



#### 5.6.1 set_intersection

**功能描述：**

* 求兩個容器的交集



**函數原型：**

- `set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  `

  // 求兩個集合的交集

  // **注意:兩個集合必須是有序序列**

  // beg1 容器1開始迭代器
  // end1 容器1結束迭代器
  // beg2 容器2開始迭代器
  // end2 容器2結束迭代器
  // dest 目標容器開始迭代器



**示例：**

```C++
#include <vector>
#include <algorithm>

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
    {
		v1.push_back(i);
		v2.push_back(i+5);
	}

	vector<int> vTarget;
	//取兩個裏面較小的值給目標容器開闢空間
	vTarget.resize(min(v1.size(), v2.size()));

	//返回目標容器的最後一個元素的迭代器地址
	vector<int>::iterator itEnd = 
        set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**總結：** 

* 求交集的兩個集合必須的有序序列
* 目標容器開闢空間需要從**兩個容器中取小值**
* set_intersection返回值既是交集中最後一個元素的位置













#### 5.6.2 set_union

**功能描述：**

* 求兩個集合的並集



**函數原型：**

- `set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  `

  // 求兩個集合的並集

  // **注意:兩個集合必須是有序序列**

  // beg1 容器1開始迭代器
  // end1 容器1結束迭代器
  // beg2 容器2開始迭代器
  // end2 容器2結束迭代器
  // dest 目標容器開始迭代器

  ​

**示例：**

```C++
#include <vector>
#include <algorithm>

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+5);
	}

	vector<int> vTarget;
	//取兩個容器的和給目標容器開闢空間
	vTarget.resize(v1.size() + v2.size());

	//返回目標容器的最後一個元素的迭代器地址
	vector<int>::iterator itEnd = 
        set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**總結：** 

- 求並集的兩個集合必須的有序序列
- 目標容器開闢空間需要**兩個容器相加**
- set_union返回值既是並集中最後一個元素的位置








#### 5.6.3  set_difference

**功能描述：**

* 求兩個集合的差集



**函數原型：**

- `set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  `

  // 求兩個集合的差集

  // **注意:兩個集合必須是有序序列**

  // beg1 容器1開始迭代器
  // end1 容器1結束迭代器
  // beg2 容器2開始迭代器
  // end2 容器2結束迭代器
  // dest 目標容器開始迭代器

  ​

**示例：**

```C++
#include <vector>
#include <algorithm>

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+5);
	}

	vector<int> vTarget;
	//取兩個裏面較大的值給目標容器開闢空間
	vTarget.resize( max(v1.size() , v2.size()));

	//返回目標容器的最後一個元素的迭代器地址
	cout << "v1與v2的差集爲： " << endl;
	vector<int>::iterator itEnd = 
        set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;


	cout << "v2與v1的差集爲： " << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**總結：** 

- 求差集的兩個集合必須的有序序列
- 目標容器開闢空間需要從**兩個容器取較大值**
- set_difference返回值既是差集中最後一個元素的位置