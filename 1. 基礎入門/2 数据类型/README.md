# C++基礎入門


## 2 數據類型

C++規定在創建一個變量或者常量時，必須要指定出相應的數據類型，否則無法給變量分配內存

### 2.1 整型

**作用**：整型變量表示的是**整數類型**的數據

C++中能夠表示整型的類型有以下幾種方式，**區別在於所佔內存空間不同**：

| **數據類型**        | **佔用空間**                                    | 取值範圍         |
| ------------------- | ----------------------------------------------- | ---------------- |
| short(短整型)       | 2字節                                           | (-2^15 ~ 2^15-1) |
| int(整型)           | 4字節                                           | (-2^31 ~ 2^31-1) |
| unsigned int(無符號整型)  | 4字節                                           | (0 ~ 2^31-1) |
| long(長整形)        | Windows為4字節，Linux為4字節(32位)，8字節(64位) | (-2^31 ~ 2^31-1) |
| long long(長長整形) | 8字節                                           | (-2^63 ~ 2^63-1) |






### 2.2 sizeof 關鍵字

**作用**：利用 sizeof 關鍵字可以**統計數據類型所佔內存大小**

**語法**： `sizeof( 數據類型 / 變量)`

**示例**：

```C++
#include <iostream>
using namespace std;

int main() {

	cout << "short 類型所佔內存空間為： " << sizeof(short) << endl;

	cout << "int 類型所佔內存空間為： " << sizeof(int) << endl;

	cout << "long 類型所佔內存空間為： " << sizeof(long) << endl;

	cout << "long long 類型所佔內存空間為： " << sizeof(long long) << endl;

	cout << "\n"<< endl;

	cout << "unsigned short 類型所佔內存空間為： " << sizeof(unsigned short) << endl;

	cout << "unsigned int 類型所佔內存空間為： " << sizeof(unsigned int) << endl;

	cout << "unsigned long 類型所佔內存空間為： " << sizeof(unsigned long) << endl;

	cout << "unsigned long long 類型所佔內存空間為： " << sizeof(unsigned long long) << endl;

	// 建議用下面方式來定義數據類型，因為這樣程式碼跨平臺會比較不會有Bug

	cout << "\n"<< endl;

	cout << "int8_t 類型所佔內存空間為： " << sizeof(int8_t) << endl;

	cout << "uint8_t 類型所佔內存空間為： " << sizeof(uint8_t) << endl;

	cout << "int16_t 類型所佔內存空間為： " << sizeof(int16_t) << endl;

	cout << "uint16_t 類型所佔內存空間為： " << sizeof(uint16_t) << endl;

	cout << "int32_t 類型所佔內存空間為： " << sizeof(int32_t) << endl;

	cout << "uint32_t 類型所佔內存空間為： " << sizeof(uint32_t) << endl;

	cout << "int64_t 類型所佔內存空間為： " << sizeof(int64_t) << endl;

	cout << "uint64_t 類型所佔內存空間為： " << sizeof(uint64_t) << endl;

	return 0;
}
```

```
short 類型所佔內存空間為： 2
int 類型所佔內存空間為： 4
long 類型所佔內存空間為： 4
long long 類型所佔內存空間為： 8


unsigned short 類型所佔內存空間為： 2
unsigned int 類型所佔內存空間為： 4
unsigned long 類型所佔內存空間為： 4
unsigned long long 類型所佔內存空間為： 8


int8_t 類型所佔內存空間為： 1
uint8_t 類型所佔內存空間為： 1
int16_t 類型所佔內存空間為： 2
uint16_t 類型所佔內存空間為： 2
int32_t 類型所佔內存空間為： 4
uint32_t 類型所佔內存空間為： 4
int64_t 類型所佔內存空間為： 8
uint64_t 類型所佔內存空間為： 8
```



> **整型結論**：**short < int <= long <= long long**















### 2.3 實型（浮點型）

**作用**：用於**表示小數**



浮點型變量分為兩種：

1. 單精度float 
2. 雙精度double

兩者的**區別**在於表示的有效數字範圍不同。

| **數據類型**  | **佔用空間** | **有效數字範圍** |
| ------------ | ------------ | ---------------- |
| float        | 4字節        | 7位有效數字      |
| double       | 8字節        | 15～16位有效數字 |


**示例**：

```C++
#include <iostream>
using namespace std;

int main() {

	float f1 = 3.14f;
	double d1 = 3.14;

	cout << f1 << endl;
	cout << d1<< endl;

	cout << "float  sizeof = " << sizeof(f1) << endl;
	cout << "double sizeof = " << sizeof(d1) << endl;

	//科學計數法
	float f2 = 3e2; // 3 * 10 ^ 2 
	cout << "f2 = " << f2 << endl;

	float f3 = 3e-2;  // 3 * 0.1 ^ 2
	cout << "f3 = " << f3 << endl;

	return 0;
}
```

```
3.14
3.14
float  sizeof = 4
double sizeof = 8
f2 = 300
f3 = 0.03
```









### 2.4 字符型

**作用：**字符型變量用於顯示單個字符

**語法：**`char ch = 'a';`



> 注意1：在顯示字符型變量時，用單引號將字符括起來，不要用雙引號

> 注意2：單引號內只能有一個字符，不可以是字符串



- C和C++中字符型變量只佔用**1個字節**。
- 字符型變量並不是把字符本身放到內存中存儲，而是將對應的ASCII編碼放入到存儲單元



示例：

```C++
#include <iostream>
using namespace std;
#include <typeinfo>

int main() {
	
	char ch = 'a';
	cout << "ch = " << ch << endl;
	cout << "sizeof(char) = " <<sizeof(char) << endl;
	cout << "ch 的數據類型為 = " <<typeid(ch).name() << endl;  // 需要 #include <typeinfo>

	//ch = "abcde"; //錯誤，不可以用雙引號
	//ch = 'abcde'; //錯誤，單引號內只能引用一個字符

	cout << "'a'的 ASCII 碼 = " <<(int)ch << endl;  //查看字符a對應的ASCII碼
	ch = 97; //可以直接用ASCII給字符型變量賦值
	cout << "ch = 97時，ASCII碼為 " << ch << endl;

	return 0;
}
```

```
ch = a
sizeof(char) = 1
ch 的數據類型為 = c
'a'的 ASCII 碼 = 97
ch = 97時，ASCII碼為 a
```

ASCII碼錶格：

| **ASCII**值 | **控制字符** | **ASCII**值 | **字符** | **ASCII**值 | **字符** | **ASCII**值 | **字符** |
| ----------- | ------------ | ----------- | -------- | ----------- | -------- | ----------- | -------- |
| 0           | NUT          | 32          | (space)  | 64          | @        | 96          | 、       |
| 1           | SOH          | 33          | !        | 65          | A        | 97          | a        |
| 2           | STX          | 34          | "        | 66          | B        | 98          | b        |
| 3           | ETX          | 35          | #        | 67          | C        | 99          | c        |
| 4           | EOT          | 36          | $        | 68          | D        | 100         | d        |
| 5           | ENQ          | 37          | %        | 69          | E        | 101         | e        |
| 6           | ACK          | 38          | &        | 70          | F        | 102         | f        |
| 7           | BEL          | 39          | ,        | 71          | G        | 103         | g        |
| 8           | BS           | 40          | (        | 72          | H        | 104         | h        |
| 9           | HT           | 41          | )        | 73          | I        | 105         | i        |
| 10          | LF           | 42          | *        | 74          | J        | 106         | j        |
| 11          | VT           | 43          | +        | 75          | K        | 107         | k        |
| 12          | FF           | 44          | ,        | 76          | L        | 108         | l        |
| 13          | CR           | 45          | -        | 77          | M        | 109         | m        |
| 14          | SO           | 46          | .        | 78          | N        | 110         | n        |
| 15          | SI           | 47          | /        | 79          | O        | 111         | o        |
| 16          | DLE          | 48          | 0        | 80          | P        | 112         | p        |
| 17          | DCI          | 49          | 1        | 81          | Q        | 113         | q        |
| 18          | DC2          | 50          | 2        | 82          | R        | 114         | r        |
| 19          | DC3          | 51          | 3        | 83          | S        | 115         | s        |
| 20          | DC4          | 52          | 4        | 84          | T        | 116         | t        |
| 21          | NAK          | 53          | 5        | 85          | U        | 117         | u        |
| 22          | SYN          | 54          | 6        | 86          | V        | 118         | v        |
| 23          | TB           | 55          | 7        | 87          | W        | 119         | w        |
| 24          | CAN          | 56          | 8        | 88          | X        | 120         | x        |
| 25          | EM           | 57          | 9        | 89          | Y        | 121         | y        |
| 26          | SUB          | 58          | :        | 90          | Z        | 122         | z        |
| 27          | ESC          | 59          | ;        | 91          | [        | 123         | {        |
| 28          | FS           | 60          | <        | 92          | /        | 124         | \|       |
| 29          | GS           | 61          | =        | 93          | ]        | 125         | }        |
| 30          | RS           | 62          | >        | 94          | ^        | 126         | `        |
| 31          | US           | 63          | ?        | 95          | _        | 127         | DEL      |

ASCII 碼大致由以下**兩部分組**成：

* ASCII 非打印控制字符： ASCII 表上的數字 **0-31** 分配給了控制字符，用於控制像打印機等一些外圍設備。
* ASCII 打印字符：數字 **32-126** 分配給了能在鍵盤上找到的字符，當查看或打印文檔時就會出現。













### 2.5 轉義字符

**作用：**用於表示一些**不能顯示出來的ASCII字符**

現階段我們常用的轉義字符有：` \n  \\  \t`

| **轉義字符** | **含義**                                | **ASCII**碼值（十進制） |
| ------------ | --------------------------------------- | ----------------------- |
| \a           | 警報                                    | 007                     |
| \b           | 退格(BS) ，將當前位置移到前一列         | 008                     |
| \f           | 換頁(FF)，將當前位置移到下頁開頭        | 012                     |
| **\n**       | **換行(LF) ，將當前位置移到下一行開頭** | **010**                 |
| \r           | 回車(CR) ，將當前位置移到本行開頭       | 013                     |
| **\t**       | **水平製表(HT)  （跳到下一個TAB位置）** | **009**                 |
| \v           | 垂直製表(VT)                            | 011                     |
| **\\\\**     | **代表一個反斜線字符"\"**               | **092**                 |
| \'           | 代表一個單引號（撇號）字符              | 039                     |
| \"           | 代表一個雙引號字符                      | 034                     |
| \?           | 代表一個問號                            | 063                     |
| \0           | 數字0                                   | 000                     |
| \ddd         | 8進制轉義字符，d範圍0~7                 | 3位8進制                |
| \xhh         | 16進制轉義字符，h範圍0~9，a~f，A~F      | 3位16進制               |

示例：

```C++
int main() {
	
	cout << "\\" << endl;
	cout << "\tHello" << endl;
	cout << "\n" << endl;

	return 0;
}
```








### 2.6 字符串型

**作用**：用於表示一串字符

**兩種風格**

1. **C風格字符串**： `char 變量名[] = "字符串值"`

   示例：

   ```C++
   int main() {

   	char str1[] = "hello world";
   	cout << str1 << endl;

   	return 0;
   }
   ```

> 注意：C風格的字符串要用雙引號括起來

1. **C++風格字符串**：  `string  變量名 = "字符串值"`

   示例：

   ```C++
   int main() {

   	string str = "hello world";
   	cout << str << endl;
   	
   	system("pause");

   	return 0;
   }
   ```

   ​

> 注意：C++風格字符串，需要加入頭文件 `#include\<string>`













### 2.7 布爾類型 bool

**作用**：布爾數據類型代表真或假的值 

bool類型只有兩個值：

* true  --- 真（本質是1）
* false --- 假（本質是0）

**bool類型佔**1個字節**大小**

示例：

```C++
#include <iostream>
using namespace std;
#include <typeinfo>

int main() {

	bool flag = true;
	cout << "true = " <<flag << endl; // 1

	flag = false;
	cout << "false = " << flag << endl; // 0

	cout << "size of bool = " << sizeof(bool) << endl; //1

    cout << "flag 的數據類型為 = " <<typeid(flag).name() << endl;  // 需要 #include <typeinfo>

	return 0;
}
```

```
true = 1
false = 0
size of bool = 1
flag 的數據類型為 = b
```














### 2.8 數據的輸入

**作用：用於從鍵盤獲取數據**

**關鍵字**：cin

**語法**： `cin >> 變量 `

示例：

```C++
int main(){

	//整型輸入
	int a = 0;
	cout << "請輸入整型變量：" << endl;
	cin >> a;
	cout << a << endl;

	//浮點型輸入
	double d = 0;
	cout << "請輸入浮點型變量：" << endl;
	cin >> d;
	cout << d << endl;

	//字符型輸入
	char ch = 0;
	cout << "請輸入字符型變量：" << endl;
	cin >> ch;
	cout << ch << endl;

	//字符串型輸入
	string str;
	cout << "請輸入字符串型變量：" << endl;
	cin >> str;
	cout << str << endl;

	//布爾類型輸入
	bool flag = true;
	cout << "請輸入布爾型變量：" << endl;
	cin >> flag;
	cout << flag << endl;
	system("pause");
	return EXIT_SUCCESS;
}
```

### 2.9 typedef size_t

size_t的含義是size type，是一種計數類型。取值範圍與機器架構與操作系統相關。32 位機器一般是unsigned int，佔 4 字節；而 64 位機器一般是unsigned long，佔 8 字節。

size_t類型常被用作計數用途，例如：sizeof運算符得到對象所佔的字節數；字符串函數strlen返回字符串的長度等等，其返回值都為size_t類型。

size_t類型隱含著本機理論所能容納建立最大對象的字節數大小的含義，因此常被用於數組索引、內存管理函數中。

最初設計size_t類型初衷，是為了程序的跨平臺兼容性考慮。

在需要通過數組下標來訪問數組時，通常建議將下標定義size_t類型，因為一般來說在進行下標訪問時，下標都是正的。當然，也不是所有的下標訪問操作下標都是正的，比如以下代碼：

示例：
```c++
#include <iostream>
using namespace std;

#include <limits>

int main(void) {
    cout<< "size_t 的大小為 " <<sizeof(size_t)<<endl;
    cout << "size_t 數據類型最大值：" << (numeric_limits<size_t>::max)() << endl; 
    cout << "size_t 數據類型最大值：" << (numeric_limits<size_t>::min)() << endl;

    //size_t 的大小這邊如果是 4 byte，代表可能是編譯器調整成 32 bit 了

    int a[10]={1,2,3,4,5,6,7,8,9,10};

    int * ptr = &(a[4]);

    cout<<ptr[-2]<<endl;

}
```

### 2.10 所有數據類型統整
```c++
#include <iostream>
using namespace std;

#include <limits>

#include <iomanip>

#include <typeinfo>


int main(void) {

	//強制使用小數,防止使用科學計數法
    //cout << fixed;

    //控制顯示的精度，控制小數點後面的位數。而整數太大時也會使用科學計數法，要輸出完整的整數時就可以將下面改成setprecision(0)
    // cout << setprecision(0);

    cout << " *************** 浮點數 *************** "<< endl;
	cout << "float 類型所佔內存空間為： " << sizeof(float) << endl;
    cout << "float 數據類型最大值：" << (numeric_limits<float>::max)() << endl; 
    cout << "float 數據類型最小值：" << (numeric_limits<float>::min)() << endl;

    cout << "" << endl;

	cout << "double 類型所佔內存空間為： " << sizeof(double) << endl;
    cout << "double 數據類型最大值：" << (numeric_limits<double>::max)() << endl; 
    cout << "double 數據類型最小值：" << (numeric_limits<double>::min)() << endl;

    cout << "" << endl;

	cout << "long double 類型所佔內存空間為： " << sizeof(long double) << endl;
    cout << "long double 數據類型最大值：" << (numeric_limits<long double>::max)() << endl; 
    cout << "long double 數據類型最小值：" << (numeric_limits<long double>::min)() << endl;

	cout << "" << endl;

    cout << " *************** 整數 *************** "<< endl;
	cout << "short 類型所佔內存空間為： " << sizeof(short) << endl;
    cout << "short 數據類型最大值：" << (numeric_limits<short>::max)() << endl; 
    cout << "short 數據類型最小值：" << (numeric_limits<short>::min)() << endl;

	cout << "" << endl;

	cout << "unsigned short 類型所佔內存空間為： " << sizeof(unsigned short) << endl;
    cout << "unsigned short 數據類型最大值：" << (numeric_limits<unsigned short>::max)() << endl; 
    cout << "unsigned short 數據類型最小值：" << (numeric_limits<unsigned short>::min)() << endl;

    cout << "" << endl;

	cout << "int 類型所佔內存空間為： " << sizeof(int) << endl;
    cout << "int 數據類型最大值：" << (numeric_limits<int>::max)() << endl; 
    cout << "int 數據類型最小值：" << (numeric_limits<int>::min)() << endl;

    cout << "" << endl;

	cout << "unsigned int 類型所佔內存空間為： " << sizeof(unsigned int) << endl;
    cout << "unsigned int 數據類型最大值：" << (numeric_limits<unsigned int>::max)() << endl; 
    cout << "unsigned int 數據類型最小值：" << (numeric_limits<unsigned int>::min)() << endl;

	cout << "" << endl;

	cout << "long 類型所佔內存空間為： " << sizeof(long) << endl;
    cout << "long 數據類型最大值：" << (numeric_limits<long>::max)() << endl; 
    cout << "long 數據類型最小值：" << (numeric_limits<long>::min)() << endl;

	cout << "" << endl;

	cout << "unsigned long 類型所佔內存空間為： " << sizeof(unsigned long) << endl;
    cout << "unsigned long 數據類型最大值：" << (numeric_limits<unsigned long>::max)() << endl; 
    cout << "unsigned long 數據類型最小值：" << (numeric_limits<unsigned long>::min)() << endl;

	cout << "" << endl;

	cout << "long long 類型所佔內存空間為： " << sizeof(long long) << endl;
    cout << "long long 數據類型最大值：" << (numeric_limits<long long>::max)() << endl; 
    cout << "long long 數據類型最小值：" << (numeric_limits<long long>::min)() << endl;

	cout << "" << endl;

	cout << "unsigned long long 類型所佔內存空間為： " << sizeof(unsigned long long) << endl;
    cout << "unsigned long long 數據類型最大值：" << (numeric_limits<unsigned long long>::max)() << endl; 
    cout << "unsigned long long 數據類型最小值：" << (numeric_limits<unsigned long long>::min)() << endl;

	cout << "\n"<< endl;

	cout << " *************** typedef  *************** "<< endl;
	// 建議用下面方式來定義數據類型，因為這樣程式碼跨平臺會比較不會有Bug
	
	cout << "int8_t 類型所佔內存空間為： " << sizeof(int8_t) << endl;
	cout << "int8_t 的型別為： " << typeid(int8_t).name() << endl;

	cout << "" << endl;

	cout << "uint8_t 類型所佔內存空間為： " << sizeof(uint8_t) << endl;
	cout << "uint8_t 的型別為： " << typeid(uint8_t).name() << endl;

	cout << "" << endl;

	cout << "int16_t 類型所佔內存空間為： " << sizeof(int16_t) << endl;
    cout << "int16_t 數據類型最大值：" << (numeric_limits<int16_t>::max)() << endl; 
    cout << "int16_t 數據類型最小值：" << (numeric_limits<int16_t>::min)() << endl;

	cout << "" << endl;

	cout << "uint16_t 類型所佔內存空間為： " << sizeof(uint16_t) << endl;
    cout << "uint16_t 數據類型最大值：" << (numeric_limits<uint16_t>::max)() << endl; 
    cout << "uint16_t 數據類型最小值：" << (numeric_limits<uint16_t>::min)() << endl;

	cout << "" << endl;

	cout << "size_t 類型所佔內存空間為： " << sizeof(size_t) << endl;
    cout << "size_t 數據類型最大值：" << (numeric_limits<size_t>::max)() << endl; 
    cout << "size_t 數據類型最小值：" << (numeric_limits<size_t>::min)() << endl;

	cout << "" << endl;

	cout << "int32_t 類型所佔內存空間為： " << sizeof(int32_t) << endl;
    cout << "int32_t 數據類型最大值：" << (numeric_limits<int32_t>::max)() << endl; 
    cout << "int32_t 數據類型最小值：" << (numeric_limits<int32_t>::min)() << endl;

	cout << "" << endl;

	cout << "uint32_t 類型所佔內存空間為： " << sizeof(uint32_t) << endl;
    cout << "uint32_t 數據類型最大值：" << (numeric_limits<uint32_t>::max)() << endl; 
    cout << "uint32_t 數據類型最小值：" << (numeric_limits<uint32_t>::min)() << endl;

	cout << "" << endl;

	cout << "int64_t 類型所佔內存空間為： " << sizeof(int64_t) << endl;
    cout << "int64_t 數據類型最大值：" << (numeric_limits<int64_t>::max)() << endl; 
    cout << "int64_t 數據類型最小值：" << (numeric_limits<int64_t>::min)() << endl;

	cout << "" << endl;

	cout << "uint64_t 類型所佔內存空間為： " << sizeof(uint64_t) << endl;
    cout << "uint64_t 數據類型最大值：" << (numeric_limits<uint64_t>::max)() << endl; 
    cout << "uint64_t 數據類型最小值：" << (numeric_limits<uint64_t>::min)() << endl;

	cout << "" << endl;

	cout << " *************** char  *************** "<< endl;

	cout << "char 類型所佔內存空間為： " << sizeof(char) << endl;
	cout << "string 類型所佔內存空間為： " << sizeof(string) << endl;

	cout << "" << endl;

	cout << " *************** bool  *************** "<< endl;
    cout<< "bool 類型所佔內存空間為： " <<sizeof(bool)<<endl;
    cout << "bool 數據類型最大值：" << (numeric_limits<bool>::max)() << endl; 
    cout << "bool 數據類型最小值：" << (numeric_limits<bool>::min)() << endl;

	cout << " *************** pointer  *************** "<< endl;
    cout<< "pointer 類型所佔內存空間為： " <<sizeof(void *)<<endl;


}
```
```
 *************** 浮點數 *************** 
float 類型所佔內存空間為： 4
float 數據類型最大值：3.40282e+038
float 數據類型最小值：1.17549e-038

double 類型所佔內存空間為： 8
double 數據類型最大值：1.79769e+308
double 數據類型最小值：2.22507e-308

long double 類型所佔內存空間為： 12
long double 數據類型最大值：1.18973e+4932
long double 數據類型最小值：3.3621e-4932

 *************** 整數 *************** 
short 類型所佔內存空間為： 2
short 數據類型最大值：32767
short 數據類型最小值：-32768

unsigned short 類型所佔內存空間為： 2
unsigned short 數據類型最大值：65535
unsigned short 數據類型最小值：0

int 類型所佔內存空間為： 4
int 數據類型最大值：2147483647
int 數據類型最小值：-2147483648

unsigned int 類型所佔內存空間為： 4
unsigned int 數據類型最大值：4294967295
unsigned int 數據類型最小值：0

long 類型所佔內存空間為： 4
long 數據類型最大值：2147483647
long 數據類型最小值：-2147483648

unsigned long 類型所佔內存空間為： 4
unsigned long 數據類型最大值：4294967295
unsigned long 數據類型最小值：0

long long 類型所佔內存空間為： 8
long long 數據類型最大值：9223372036854775807
long long 數據類型最小值：-9223372036854775808

unsigned long long 類型所佔內存空間為： 8
unsigned long long 數據類型最大值：18446744073709551615
unsigned long long 數據類型最小值：0


 *************** typedef  *************** 
int8_t 類型所佔內存空間為： 1
int8_t 的型別為： a

uint8_t 類型所佔內存空間為： 1
uint8_t 的型別為： h

int16_t 類型所佔內存空間為： 2
int16_t 數據類型最大值：32767
int16_t 數據類型最小值：-32768

uint16_t 類型所佔內存空間為： 2
uint16_t 數據類型最大值：65535
uint16_t 數據類型最小值：0

size_t 類型所佔內存空間為： 4
size_t 數據類型最大值：4294967295
size_t 數據類型最小值：0

int32_t 類型所佔內存空間為： 4
int32_t 數據類型最大值：2147483647
int32_t 數據類型最小值：-2147483648

uint32_t 類型所佔內存空間為： 4
uint32_t 數據類型最大值：4294967295
uint32_t 數據類型最小值：0

int64_t 類型所佔內存空間為： 8
int64_t 數據類型最大值：9223372036854775807
int64_t 數據類型最小值：-9223372036854775808

uint64_t 類型所佔內存空間為： 8
uint64_t 數據類型最大值：18446744073709551615
uint64_t 數據類型最小值：0

 *************** char  *************** 
char 類型所佔內存空間為： 1
string 類型所佔內存空間為： 24

 *************** bool  *************** 
bool 類型所佔內存空間為： 1
bool 數據類型最大值：1
bool 數據類型最小值：0
 *************** pointer  *************** 
pointer 類型所佔內存空間為： 4
```