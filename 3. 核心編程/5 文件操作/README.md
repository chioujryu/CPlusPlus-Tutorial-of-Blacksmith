# C++核心編程



## 5 文件操作



程序運行時產生的數據都屬於臨時數據，程序一旦運行結束都會被釋放
ㄟ
通過**文件可以將數據持久化**

C++中對文件操作需要包含頭文件 **&lt; fstream &gt;**



文件類型分為兩種：

1. **文本文件**     -  文件以文本的**ASCII碼**形式存儲在計算機中
2. **二進制文件** -  文件以文本的**二進制**形式存儲在計算機中，用戶一般不能直接讀懂它們



操作文件的三大類:

1. ofstream：寫操作
2. ifstream： 讀操作
3. fstream ： 讀寫操作



### 5.1文本文件

#### 5.1.1寫文件

   寫文件步驟如下：

1. 包含頭文件   

     \#include <fstream\>

2. 創建流對象  

   ofstream ofs;	
	// ofstream = open file stream

3. 打開文件

   ofs.open("文件路徑",打開方式);

4. 寫數據

   ofs << "寫入的數據";

5. 關閉文件

   ofs.close();

   ​

文件打開方式：

| 打開方式    | 解釋                       |
| ----------- | -------------------------- |
| ios::in     | 為讀文件而打開文件         |
| ios::out    | 為寫文件而打開文件         |
| ios::ate    | 初始位置：文件尾           |
| ios::app    | 追加方式寫文件             |
| ios::trunc  | 如果文件存在先刪除，再創建 |
| ios::binary | 二進制方式                 |

文件判斷式
| 判斷方式     | 解釋                       |
| ----------- | -------------------------- |
| ifs.is_open() | 判斷是否有打開文件         |
| ifs.eof()   | 判斷文件裡有無數據，如果為ture代表為空 |


**注意：** 文件打開方式可以配合使用，利用|操作符

**例如：**用二進制方式寫文件 `ios::binary |  ios:: out`





**示例：**

```C++
#include<iostream>
using namespace std;
#include<fstream>

//文本文件 寫文件
void test(){
    ofstream ofs;
    ofs.open("test.txt",ios::out);

	ofs << "姓名：張三" << endl;
	ofs << "性別：男" << endl;
	ofs << "年齡：18" << endl;

	ofs.close();

};

int main(){

    test();

};
```

總結：

* 文件操作必須包含頭文件 fstream
* 讀文件可以利用 ofstream  ，或者fstream類
* 打開文件時候需要指定操作文件的路徑，以及打開方式
* 利用<<可以向文件中寫數據
* 操作完畢，要關閉文件

















#### 5.1.2讀文件



讀文件與寫文件步驟相似，但是讀取方式相對於比較多



讀文件步驟如下：

1. 包含頭文件   

     \#include <fstream\>

2. 創建流對象  

   ifstream ifs;

3. 打開文件並判斷文件是否打開成功

   ifs.open("文件路徑",打開方式);

4. 讀數據

   四種方式讀取

5. 關閉文件

   ifs.close();



**示例：**

```C++
#include<iostream>
using namespace std;
#include<fstream>	//1. 包含頭文件

void print(char (&buffer)[1024]);

//文本文件 讀文件
void test(){

	//2. 創建輸入流對象
    ifstream ifs;

	//3. 打開文件
	ifs.open("test.txt",ios::in);

	//4. 判斷是否打開成功
	if (!ifs.is_open())
	{
		cout<<"文件打開失敗"<<endl;
		return;
	}
	else if (ifs.is_open())
	{
		cout<<"文件打開成功"<<endl;
	}

	//5.讀數據
	//第一種方式
	char buffer[1024] = { 0 };	// 這個陣列裡面的數值都是 0
	print(buffer);	// 印出陣列
	while (ifs >> buffer)
	{
		cout << buffer << endl;
	}

	//第二種方式
	//char buffer[1024] = { 0 };
	// while (ifs.getline(buffer,sizeof(buffer)))
	// {
	// 	cout << buffer << endl;
	// }

	//第三種方式
	// string buffer;
	// while (getline(ifs, buffer))
	// {
	// 	cout << buffer << endl;
	// }
	
	//第四種方式
	// char c;
	// while ((c = ifs.get()) != EOF)	//EOF = End of File
	// {
	// 	cout << c;
	// }

	//6.關閉文件
	ifs.close();
};

void print(char (&buffer)[1024]){	//用引用接收，才不會讓數組傳指標近來
	int len = sizeof(buffer) / sizeof(buffer[0]);
	cout<<len<<endl;
	for(int i=0; i < len; i++)
	{
		cout<<buffer[i]<<endl;	//ASCII 的 0 為 NULL，所以打印出來會沒有東西
	};
};

int main(){
	
    test();

};
```

總結：

- 讀文件可以利用 ifstream  ，或者fstream類
- 利用is_open函數可以判斷文件是否打開成功
- close 關閉文件 















### 5.2 二進制文件

以二進制的方式對文件進行讀寫操作

打開方式要指定為 `ios::binary`



#### 5.2.1 寫文件

二進制方式寫文件主要利用流對象調用成員函數write

函數原型 ：`ostream& write(const char * buffer,int len);`

參數解釋：字符指針buffer指向內存中一段存儲空間。len是讀寫的字節數



**示例：**

```C++
#include<iostream>
#include <string>
using namespace std;

//1、包含頭文件
#include <fstream>	

class Person
{
public:
	char m_Name[64];	// 用c++的string會有問題，所以要用char
	int m_Age;
};

//二進制文件  寫文件
void test01()
{
	
	//2、創建輸出流對象
	ofstream ofs("person.txt", ios::out | ios::binary);	// ofstream 裡面有構造函數，可以直接設定初始值
	
	//3、打開文件
	//ofs.open("person.txt", ios::out | ios::binary);

	Person p = {"張三"  , 18};

	//4、寫文件
	ofs.write((const char *)&p, sizeof(p));	//二進制寫入，會是亂碼是正常的，可以讀回來就好

	//5、關閉文件
	ofs.close();
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

總結：

* 文件輸出流對象 可以通過write函數，以二進制方式寫數據











#### 5.2.2 讀文件

二進制方式讀文件主要利用流對象調用成員函數read

函數原型：`istream& read(char *buffer,int len);`

參數解釋：字符指針buffer指向內存中一段存儲空間。len是讀寫的字節數

示例：

```C++
#include<iostream>
#include <string>
using namespace std;

#include <fstream>

class Person
{
public:
	char m_Name[64];
	int m_Age;
	char m_mood[64];
};

void test01()
{
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打開失敗" << endl;
	}

	Person p;
	ifs.read((char *)&p, sizeof(p));

	cout << "姓名： " << p.m_Name << " 年齡： " << p.m_Age << " 心情： " <<p.m_mood<<endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```



- 文件輸入流對象 可以通過read函數，以二進制方式讀數據

