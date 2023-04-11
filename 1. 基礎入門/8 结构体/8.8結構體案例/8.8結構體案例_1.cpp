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