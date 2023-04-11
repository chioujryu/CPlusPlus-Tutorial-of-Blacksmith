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