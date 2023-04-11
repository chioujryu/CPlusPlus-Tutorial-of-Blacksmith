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