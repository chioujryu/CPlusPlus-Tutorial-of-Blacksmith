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