# C++基础入门

## 8 结构体

### 8.1 结构体基本概念

结构体属于用户==自定义的数据类型==，允许用户存储不同的数据类型



### 8.2 结构体定义和使用

**语法：**`struct 结构体名 { 结构体成员列表 }；`

通过结构体创建变量的方式有三种：

* struct 结构体名 变量名
* struct 结构体名 变量名 = { 成员1值 ， 成员2值...}
* 定义结构体时顺便创建变量

**示例：**

```C++
#include<iostream>
using namespace std;

//結構體屬於用戶自定義的數據類型，允許用戶存儲不同的數據類型

//1. 創建學生的數據類型：學生包括(姓名，年齡，分數)
//自定義的數據類型，一些類型集合組成的一個類型
//語法：struct 結構體名稱{結構體成員列表}
struct student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
}stu3; //结构体变量创建方式3 

//2. 通過學生類型創建具體學生


int main(){
    //2.1 struct Student s1
    struct student stu1;
    //給s1屬性賦值
    stu1.name = "張三";
    stu1.age = 18;
    stu1.score = 100;
    cout << "姓名：" << stu1.name << " 年龄：" << stu1.age  << " 分数：" << stu1.score << endl;


    //2.2 struct Student s2 = {....}
    struct student stu2 = { "李四",19,60 };
    cout << "姓名：" << stu2.name << " 年龄：" << stu2.age  << " 分数：" << stu2.score << endl;


    //2.3 在定義結構體時順便創建結構體變量
    //這一種定義方法是最少用的，因為查看程式碼不容易看
    stu3.name = "王五";
    stu3.age = 16;
    stu3.score = 88;
    cout << "姓名：" << stu2.name << " 年龄：" << stu2.age  << " 分数：" << stu2.score << endl;


    //2.4 struct關鍵字可以省略
    student stu4;
    //給s1屬性賦值
    stu4.name = "張六";
    stu4.age = 21;
    stu4.score = 96;
    cout << "姓名：" << stu4.name << " 年龄：" << stu4.age  << " 分数：" << stu4.score << endl;


	//可以查看各個元素的地址
	cout<<"stu的地址為："<<(int)&stu4<<endl;  //stu的地址就是`stu.name`的地址，因為是string，所以是24byte
	cout<<"stu.name的地址為："<<(int)&stu4.name<<endl;  //stu.name的地址，因為是string，所以是24byte
	cout<<"stu.age的地址為："<<(int)&stu4.age<<endl;		//stu.name的地址，因為是int，所以是4byte	
	cout<<"stu.score的地址為："<<(int)&stu4.score<<endl;	//stu.score的地址，因為是int，所以是4byte
}
```



> 总结1：定义结构体时的关键字是struct，不可省略

> 总结2：创建结构体变量时，关键字struct可以省略

> 总结3：结构体变量利用操作符 ''.''  访问成员









### 8.3 结构体数组

**作用：**将自定义的结构体放入到数组中方便维护

**语法：**` struct  结构体名 数组名[元素个数] = {  {} , {} , ... {} }`

**示例：**

```C++
#include<iostream>
using namespace std;

//結構體數組
//作用：将自定义的结构体放入到数组中方便维护

//1. 定義結構體
struct student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};



int main(){

    //2.創建結構體數組
	//结构体数组
	struct student arr[3]=
	{
		{"张三",18,80 },
		{"李四",19,60 },
		{"王五",20,70 }
	};

    //3. 給結構體數組中的元素賦值
    arr[2].name = "邱之宇";
    arr[2].age = 30;
    arr[2].score = 99;

    //4. 遍歷結構體數組
	for (int i = 0; i < 3; i++)
	{
		cout << "姓名：" << arr[i].name 
            << " 年龄：" << arr[i].age 
            << " 分数：" << arr[i].score << endl;
	}

    system("pause");
	return 0;
}
```











### 8.4 结构体指针

**作用：**通过指针访问结构体中的成员



* 利用操作符 `-> `可以通过结构体指针访问结构体属性



**示例：**

```C++
#include<iostream>
using namespace std;

//結構體指針

//定義學生結構體
struct student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};

int main() {

    //1. 創建學生結構體變量
	struct student stu = { "张三",18,100, };

    //2. 通過指針指向結構體變量
    struct student * p = &stu;  //記住，也可以省略struct

    //3. 通過指針訪問結構體變量中的數據
    //通過結構體指針，訪問結構體中的屬性，需要利用 "->"
	p->score = 80; //指针通过 -> 操作符可以访问成员
	cout << "姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score << endl;
	
	system("pause");

	return 0;
}
```



> 总结：结构体指针可以通过 -> 操作符 来访问结构体中的成员













### 8.5 结构体嵌套结构体

**作用：** 结构体中的成员可以是另一个结构体

**例如：**每个老师辅导一个学员，一个老师的结构体中，记录一个学生的结构体

**示例：**

```C++
#include<iostream>
using namespace std;

//作用： 结构体中的成员可以是另一个结构体
//例如：每个老师辅导一个学员，一个老师的结构体中，记录一个学生的结构体


//学生结构体定义
struct student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};

//教师结构体定义
struct teacher
{
    //成员列表
	int id; //职工编号
	string name;  //教师姓名
	int age;   //教师年龄
	struct student stu; //子结构体 学生
};


int main() {

	//結構體嵌套結構體

	//創建老師
	struct teacher t1; //補充，要省略掉`struct`也可以
	t1.id = 10000;
	t1.name = "老王";
	t1.age = 40;

	t1.stu.name = "张三";
	t1.stu.age = 18;
	t1.stu.score = 100;

	cout << "教师 职工编号： " << t1.id 
			<< " 姓名： " << t1.name 
			<< " 年龄： " << t1.age << endl;
	
	cout << "辅导学员 姓名： " << t1.stu.name 
			<< " 年龄：" << t1.stu.age 
			<< " 考试分数： " << t1.stu.score << endl;

	system("pause");

	return 0;

	//总结：在结构体中可以定义另一个结构体作为成员，用来解决实际问题
}
```



**总结**：在结构体中可以定义另一个结构体作为成员，用来解决实际问题









### 8.6 结构体做函数参数 

**作用：**将结构体作为参数向函数中传递

传递方式有两种：

* 值传递
* 地址传递

**示例：**

```C++
#include<iostream>
using namespace std;

//作用：将结构体作为参数向函数中传递

//传递方式有两种：
//1. 值传递
//2. 地址传递



//学生结构体定义
struct student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};

//打印學生信息的函數
//值传递
void printStudent(struct student stu)
{
	stu.age = 28;
	cout << "子函数中 姓名：" << stu.name << " 年龄： " << stu.age  << " 分数：" << stu.score << endl;
}

//地址传递
void printStudent2(struct student * stu)
{
	stu->age = 28;
	cout << "子函数中 姓名：" << stu->name << " 年龄： " << stu->age  << " 分数：" << stu->score << endl;
}

int main() {

	//結構體做函數參數
	//將學生傳入到一個參數中，打印學生身上的所有信息

	//創建結構體變量
	student stu = { "张三",18,100};  //已將struct省略掉
	//值传递
	printStudent(stu);
	cout << "主函数中 姓名：" << stu.name << " 年龄： " << stu.age << " 分数：" << stu.score << endl;

	cout << endl;

	//地址传递
	printStudent2(&stu);
	cout << "主函数中 姓名：" << stu.name << " 年龄： " << stu.age  << " 分数：" << stu.score << endl;


	//可以查看各個元素的地址
	cout<<"stu的地址為："<<(int)&stu<<endl;  //stu的地址就是`stu.name`的地址，因為是string，所以是24byte
	cout<<"stu.name的地址為："<<(int)&stu.name<<endl;  //stu.name的地址，因為是string，所以是24byte
	cout<<"stu.age的地址為："<<(int)&stu.age<<endl;		//stu.name的地址，因為是int，所以是4byte	
	cout<<"stu.score的地址為："<<(int)&stu.score<<endl;	//stu.score的地址，因為是int，所以是4byte	

	return 0;
}
```

> 总结：如果不想修改主函数中的数据，用值传递，反之用地址传递







### 8.7 结构体中 const使用场景

**作用：**用const来防止误操作

**示例：**

```C++
#include<iostream>
using namespace std;

//学生结构体定义
struct student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};

//const使用场景

//將函數中的形參改為指針，可以減少內存空間，而且不會覆至新的副本出來
void printStudent(const student *stu) //加const防止函数体中的误操作
{
	//stu->age = 100; //操作失败，因为加了const修饰
	cout << "姓名：" << stu->name << " 年龄：" << stu->age << " 分数：" << stu->score << endl;

}

int main() {

	//創建結構體變數
	struct student stu = { "张三",18,100 };

	//通過函數打印結構體變數信息
	printStudent(&stu);

	return 0;
}
```









### 8.8 结构体案例

#### 8.8.1 案例1

**案例描述：**

学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下

设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员

学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值

最终打印出老师数据以及老师所带的学生数据。



**示例：**

```C++
#include<iostream>
using namespace std;
#include <ctime> //為了產生亂數而用

//学生结构体定义
struct student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};

//老師結構體定義
struct teacher
{
	string name;
	struct student sArray[5];
};

//給老師和學生賦值的函數
void allocateSpace(struct teacher tArray[], int len)
{
	string tName = "教师";
	string sName = "学生";
	string nameSeed = "ABCDE";	
	for (int i = 0 ; i < len ; i++)
	{
		tArray[i].name = tName + nameSeed[i];

		//通過循環給每名老師所帶的學生賦值
		for (int j = 0 ; j < 5 ; j++)
		{
			tArray[i].sArray[j].name = 	sName + nameSeed[j];

			//隨機賦予學生分數
			int randomScore = rand() % 101; //產生0~100的隨機數字
			tArray[i].sArray[j].score = randomScore;
		}
	}
}


//打印所有信息的函數
void printTeachers(teacher tArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << tArray[i].name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t姓名：" << tArray[i].sArray[j].name 	//  \t可以讓整串字串往右移
					<< " 分数：" << tArray[i].sArray[j].score << endl;
		}
	}
}

int main() {

	//隨機數種子
	srand(time(NULL));  //這可以讓每次產生的亂數不同

	//1. 創建3名老師的數組
	struct teacher tArray[3];

	//2. 通過函數給3名老師的信息賦值，並給老師帶的學生信息賦值
	int len = sizeof(tArray) / sizeof(tArray)[0];
	allocateSpace(tArray, len);

	//3. 打印所有老師及所帶的學生信息
	printTeachers(tArray,len);

}
```









#### 8.8.2 案例2

**案例描述：**

设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。

通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。



五名英雄信息如下：

```C++
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},
```









**示例：**

```C++
//设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。
//通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。
//五名英雄信息如下：
//{"刘备",23,"男"},
//{"关羽",22,"男"},
//{"张飞",20,"男"},
//{"赵云",21,"男"},
//{"貂蝉",19,"女"},

#include<iostream>
using namespace std;

//1. 設計英雄結構體
struct hero
{
	string name;	 //姓名
	int age;	//年齡
	string sex;		//性別
};


//打印所有英雄數據
void printHeros(struct hero Heros[], int len)
{
	for (int i = 0 ; i < len ; i++)
	{
		cout << "姓名： " << Heros[i].name 
				<< " 性别： " << Heros[i].sex 
				<< " 年龄： " << Heros[i].age << endl;
	}
};

//冒泡排序，實現年齡升序排列
void bubbleSort(struct hero Heros[], int len)
{
	for (int i = 0 ; i < len-1 ; i++)
	{
		for (int j = 0 ; j < len-i-1 ; j++)
		{
			//如果j下標的元素年齡大於j+1下標的元素的年齡，交換兩個元素
			if(Heros[j].age>Heros[j+1].age)
			{
				int temp = Heros[j+1].age;
				Heros[j+1].age = Heros[j].age;
				Heros[j].age = temp;
			}
		}
	}
};



int main() {
	//2. 創建數組存放五名英雄
	struct hero heroArray[5] = 
	{
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},
	};

	//3. 取得heroArray的長度
	int len = sizeof(heroArray) / sizeof(heroArray[0]);

	//4. 打印所有英雄信息
	cout<<"打印所有英雄信息"<<endl;
	printHeros(heroArray,len);

	//5. 對數組進行排序，按照年齡進行升序排序
	bubbleSort(heroArray, len);

	//6. 打印排序後的英雄信息
	cout<<"打印排序後的所有英雄信息"<<endl;
	printHeros(heroArray,len);

	return 0;
}
```



# 