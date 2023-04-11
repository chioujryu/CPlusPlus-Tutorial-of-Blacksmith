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