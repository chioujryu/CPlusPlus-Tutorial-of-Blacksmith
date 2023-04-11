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